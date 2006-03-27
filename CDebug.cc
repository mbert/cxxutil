/* -*-gnu-*- */
/*
 * CxxUtils C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated, this software is provided under the terms of the
 * GNU LESSER PUBLIC LICENSE. The text of this license agreement accompanies
 * this library's source distribution.
 */

/* --------------------------------------------------------------------
 * Debugging utils class implementation
 *
 * $Date: 2006-03-27 11:08:15 $
 * $Revision: 1.3 $
 * -------------------------------------------------------------------- */

#include "cxxutils/CDebug.hh"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>


#if !(defined __WATCOMC__ && __WATCOMC__ < 1230)
using namespace std;
#endif

// Definition and initialisation of static class data
ofstream CxxUtils::CDebug::ostr;
string CxxUtils::CDebug::errorcodeFilename;
int CxxUtils::CDebug::level;


//! Default constructor
/** Constructor for the static CDebug-class */
CxxUtils::CDebug::CDebug (void)
{
  level = CDebug::Info | CDebug::Error;
}

//! destructor
CxxUtils::CDebug::~CDebug (void)
{
  if (ostr.is_open ())
    {
      ostr.flush ();
      ostr.close ();
    }

  writeErrorCode (0);

  cout.flush ();
}

void
CxxUtils::CDebug::writeErrorCode (int errorcode)
{
  if (errorcodeFilename.length ())
    {
      ofstream errstream;
      errstream.open (errorcodeFilename.c_str ());
      if (errstream.is_open ())
        {
          errstream << errorcode << std::endl;
          errstream.close ();
        }
    }
  else
    {
      std::cout << errorcode << std::endl;
    }
}

//! Setting out-stream to a file
bool 
CxxUtils::CDebug::open (const char *fileName)
{
  if (ostr.is_open ())
    {
      ostr.flush ();
      ostr.close ();
    }

  if (fileName && strlen (fileName) > 0)
    {
      ostr.open (fileName);
      if (!ostr)
        {
          cerr << "Could not open debug-trace file `" << fileName << "'\n";
          return false;
        }
    }
  return true;
}


//! OStream-Operator
/** This method is used to put a given message to stdout or the specified
    file*/
ostream & 
CxxUtils::CDebug::getOStr (void)
{
  if (ostr.is_open ())
    {
      return (ostr);
    }
  else
    {
      return (cout);
    }
}


void
CxxUtils::CDebug::setLevel (const char *str)
{
  int len = strlen (str);
  int curr = 0;

  level = None;
  while (curr < len)
    {
      if (!strncmp (&(str[curr]), "Error", strlen ("Error")))
        {
          level |= Error;
          curr += strlen ("Error");
        }
      else if (!strncmp (&(str[curr]), "Info", strlen ("Info")))
        {
          level |= Info;
          curr += strlen ("Info");
        }
      else if (!strncmp (&(str[curr]), "Debug", strlen ("Debug")))
        {
          level |= Debug;
          curr += strlen ("Debug");
        }
      else if (!strncmp (&(str[curr]), "None", strlen ("None")))
        {
          level |= None;
          curr += strlen ("None");
        }
      else
        {
          std::cout << "CDebug::setLevel: Malformed level-definition "
            << &(str[curr]) << endl;
          break;
        }

      if (curr < len && str[curr] != '|')
        {
          std::cout << "CDebug::setLevel: Malformed level-definition "
            << str << endl;
          break;
        }
      else
        {
          curr++;                 // ueberspringe '|'
        }
    }
  return;
}

#if !defined (NDEBUG) && !defined (DPRINTF)
int 
CxxUtils::debug_printf (const char *tmpl, ...)
{
  va_list ap;
  int result;

  va_start (ap, tmpl);
  result = vfprintf (stderr, tmpl, ap);
  va_end (ap);
  return result;
}
#endif
