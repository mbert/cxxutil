/* -*-gnu-*- */
/*
 * CxxUtil C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated, this software is provided under the terms of the
 * GNU LESSER PUBLIC LICENSE. The text of this license agreement accompanies
 * this library's source distribution.
 */

/* --------------------------------------------------------------------
 * Utility function implementations
 *
 * $Date: 2006-03-27 13:40:22 $
 * $Revision: 1.5 $
 * -------------------------------------------------------------------- */


#if defined __GNUC__ && defined __GLIBC__
# ifdef __USE_MISC
# undef __USE_MISC
# endif
# define __USE_MISC 1
# ifdef __USE_BSD
# undef __USE_BSD
# endif
# define __USE_BSD  1
#endif

#include "cxxutil/utils.h"
#include "cxxutil/cdefines.h"

#ifdef OUTLINE
#include "cxxutil/utils.ih"
#endif

#ifdef WIN32
# include <io.h>
# define _open open
#else
# include <unistd.h>
#endif
#include <fcntl.h>

#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <cassert>
#include <stdexcept>

#if defined __GNUC__ && __GNUC__ == 2 || __GNUC__ == 3 && __GNUC_MINOR__ == 0
 /* this is a workaround for g++ 2.95 and g++ 3.0 */
int setenv (const char *, const char *, int);
#endif

int
CxxUtil::tempFileName (char *templ, const char *extension)
{
  static char letters[]
    = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

  int templen = strlen (templ);
  int letterlen = strlen (letters);
  int extenlen = strlen (extension);

  if(templen < 6)
    {
      return -1;
    }

  char *p = templ + templen - 6;

  if (strcmp (p, "XXXXXX") != 0)
    {
      return -1;
    }

  srand ((unsigned)time (NULL));
  int fd;
  char *fname = NEW (char [templen + extenlen + 1]);
  strcpy (fname, templ);
  strcat (fname, extension);
  p = fname + templen - 6;

  for (int run = 0; run < 512; run++)
    {
      for (int i = 0; i < 6; i++)
        {
          p[i] = letters[rand () % letterlen];
        }

      if ((fd = open (fname, O_CREAT | O_EXCL)) > 0)
        {
          break;
        }
    }

  if (fd < 0)
    {
      DELETE( fname);
      return -1;
    }

  close (fd);
  (void)remove (fname);
  strncpy (templ, fname, templen);
  DELETE( fname);

  return 0;
}

FILE *
CxxUtil::tempFile (char *templ)
{
  if (CxxUtil::tempFileName (templ) < 0)
    {
      return NULL;
    }
  return fopen (templ, "wb");
}

int
CxxUtil::putEnvironment (char *name, char *value)
{
#ifdef IRIX
  // On IRIX we are somewhat less flexible...
  static char var[256];
  snprintf (var, sizeof var, "%s=%s", name, value);
  return putenv (var);
#elif defined WIN32
  static char var[256];
  sprintf (var, "%s=%s", name, value);
  return _putenv (var);
#else
  // Linux
  return setenv (name, value, 1);
#endif
}

unsigned char*
CxxUtil::htond (double dat)
{
  static unsigned char res[8];
  int s;
  int e;
  CxxUtil::i64 m;
  double md;
  double temp;

  /// @todo: is this correct?
  if (fabs (dat) <= DBL_EPSILON)
    {
      int i;
      for (i = 0; i < 8; i++)
        {
          res[i] = 0;
        }
      return res;
    }

  s = (dat >=0 ) ? 0 : 1;

  if (s)
    {
      dat *= -1;
    }

  e = 0;
  temp = dat;
  while (temp >= 2.0)
    {
      temp /= 2;
      e++;
    }

  if (temp >= DBL_EPSILON)
    {
      while(temp < 1.0)
        {
          temp *=2;
          e--;
        }
    }
  else
    {
      e = 0;
    }

  dat /= pow ((double)2, e);

  e += 1023;

  res[0]  = (s << 7);
  res[0] |= (e >> 4) & 0x7f;
  res[1]  = (e << 4) & 0xf0;

  md =  (dat * (4294967296.0 * 1048576.0));
  m = (CxxUtil::i64)md;

  res[1] |= (unsigned char)((m >> 48) & 0x0f);
  res[2]  = (unsigned char)((m >> 40) & 0xff);
  res[3]  = (unsigned char)((m >> 32) & 0xff);
  res[4]  = (unsigned char)((m >> 24) & 0xff);
  res[5]  = (unsigned char)((m >> 16) & 0xff);
  res[6]  = (unsigned char)((m >>  8) & 0xff);
  res[7]  = (unsigned char)((m)       & 0xff);

  return res;
}

double
CxxUtil::ntohd (unsigned char *dat)
{
  double res;
  int s;
  int e;
  CxxUtil::i64 m;

  if (*((CxxUtil::i64*)dat) == 0)
    {
      return 0.0;
    }

  s  = dat[0] >> 7 & 1;
  e  = (dat[0] & 0x7f) << 4;
  e |= (dat[1] & 0xf0) >> 4;
  e -= 1023;
  m  = ((CxxUtil::i64)dat[1] & 0x0f) << 48;
  m += ((CxxUtil::i64)dat[2] & 0xff) << 40;
  m += ((CxxUtil::i64)dat[3] & 0xff) << 32;
  m += ((CxxUtil::i64)dat[4] & 0xff) << 24;
  m += ((CxxUtil::i64)dat[5] & 0xff) << 16;
  m += ((CxxUtil::i64)dat[6] & 0xff) << 8;
  m += ((CxxUtil::i64)dat[7] & 0xff);

  res = (1.0 - (2.0 * (double)s)) * pow (2.0 ,(double)e) *
        (1.0 + ((double)m / (4294967296.0 * 1048576.0)));

  return res;
}

char *
CxxUtil::strdup(const std::string &str)
{
	return strdup(str.c_str());
}

char *
CxxUtil::strdup (const char *str)
{
  const char *s = str;
  if (str == NULL)
    {
      s = "";
    }
  int len = strlen (s);
  char *ret = new char [len + 1];
  ret[len] = '\0';
  strcpy (ret, s);
  assert (ret[len] == '\0');
  return ret;
}


std::string
CxxUtil::itoa (long num)
{
  char ctemp[256];
  snprintf(ctemp, sizeof ctemp, "%ld", num);
  return std::string(ctemp);
}

std::string
CxxUtil::utoa (unsigned long num)
{
  char ctemp[256];
  snprintf(ctemp, sizeof ctemp, "%lu", num);
  return std::string(ctemp);
}

long
CxxUtil::atoi(const std::string &str, int base)
{
  char *error = NULL;
  long ret = (int)strtol(str.c_str(), &error, base);
  if (*error != '\0')
    {
      throw std::invalid_argument(std::string("Invalid number format at: ") + error);
    }
  return ret;
}

unsigned long
CxxUtil::atou(const std::string &str, int base)
{
  char *error = NULL;
  unsigned long ret = (int)strtoul(str.c_str(), &error, base);
  if (*error != '\0')
    {
      throw std::invalid_argument(std::string("Invalid number format at: ") + error);
    }
  return ret;
}
