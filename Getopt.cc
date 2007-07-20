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
 * Getopt wrapper class implementation
 *
 * Author: Michael Lipka, minor stuff by Martin Dietze
 *
 * $Date: 2007-07-20 15:07:14 $
 * $Revision: 1.8 $
 * -------------------------------------------------------------------- */

#include "cxxutil/Getopt.hh"

#include <stdexcept>
#include <iostream>
#include <cstdio>
#include <cassert>

#include "cxxutil/utils.h"
#include "cxxutil/cdefines.h"

extern "C" {
#include "cxxutil/getopt/getopt_wrapper.h"
}

extern int my_optopt;
extern int my_optind;
extern int my_optopt;
extern char *my_optarg;

using namespace std;

// ----------------------- Globals and Helpers --------------------------------

static struct option lastEntry = { NULL, 0, NULL, 0 };

static struct option *
structOption_grow(struct option *opts, const int &currentSize)
{
  unsigned newSize = (unsigned) currentSize + 10;
  struct my_option *ret = NEW (struct my_option[newSize]);
  int i = 0;
  ret[i] = lastEntry;
  for (i = 0; i < currentSize; i++)
    {
      ret[i] = opts[i];
    }
  DELETE( opts);
  return ret;
}

static struct option *
structOption_add(struct option *opts, int &currentSize,
		 const struct option &entry)
{
  struct option *ret = opts;
  if (currentSize == 0)
    {
      ret = structOption_grow(ret, currentSize);
    }
  int i = 0;
  for (i = 0; i < currentSize && opts->name != NULL; i++)
    {
    }
  if (i >= currentSize - 1)
    {
      ret = structOption_grow(ret, currentSize);
    }
  ret[i + 1] = lastEntry;
  ret[i] = entry;
  ++currentSize;
  return ret;
}


// ----------------------------- Public ---------------------------------------

CxxUtil::Getopt::Getopt (bool useSystemWarning)
  : m_longOpts(NULL), m_longOptsSize(0), m_lastOptNdx(1), m_error(false)
{
  m_convstr[0] = '\0';
  if (!useSystemWarning)
    {
      my_opterr = 0;
    }
}

CxxUtil::Getopt::~Getopt (void)
{
  if (m_longOpts != NULL && m_longOptsSize > 0)
    {
      for (int i = 0; i < m_longOptsSize; i++)
	{
	  /*lint -save -e605 */
	  DELETE (m_longOpts[i].name);
	  /*lint -restore */
	}
      DELETE (m_longOpts);
    }
}

void
CxxUtil::Getopt::addOption (const char shortOpt, const bool takesArg,
			    const std::string & description,
			    const std::string & longOpt)
{
  OptionDescription tmp;
  char so[3];
  sprintf (so, "-%c", shortOpt);
  tmp.leftSide = string(so);

  m_optionString += &so[1];
  if (takesArg)
    {
      m_optionString += ":";
    }

  if (longOpt.size() > 0)
    {
      tmp.leftSide += "|--" + longOpt;
      struct option tmp2;
      tmp2.name = CxxUtil::strdup (longOpt);
      tmp2.has_arg = (int) takesArg;
      tmp2.flag = 0;
      tmp2.val = (int) shortOpt;
      m_longOpts = structOption_add (m_longOpts, m_longOptsSize, tmp2);
    }

  if (takesArg)
    {
      tmp.leftSide += "<arg>";
    }
  tmp.rightSide = description;
  m_optDescriptions.push_back(tmp);
}

void
CxxUtil::Getopt::process(const int argc, char* const argv[])
{
  int o;
  optind = 0;
  m_error = false;
  m_options.clear();
  int optionindex = 0;

  while ((o = getopt_long(argc, argv, m_optionString.c_str(),
			  m_longOpts, &optionindex)) != -1)
    {
      if (o == '?')
	{
	  m_error = true;
	  //cout << "error: " << (char)optopt << endl;
	  m_lastError = "- ";
	  m_lastError[1] = (char)optopt;
	}
      if (optarg != NULL)
	{
	  m_options.push_back(ProgOption(ucar2str(o), optarg));
	}
      else
	{
	  m_options.push_back(ProgOption(ucar2str(o)));
	}
    }
  m_lastOptNdx = optind;
}

const CxxUtil::Getopt::ProgOption &
CxxUtil::Getopt::opt (const std::string &opti) const
{
  for (OptionIterator o = m_options.begin(); o != m_options.end(); ++o)
    {
      if (o->getName() == opti)
	{
	  return *o;
	}
    }
  throw std::invalid_argument("Option " + opti + " not found");
}


bool
CxxUtil::Getopt::given (const std::string &option) const
{
  for (OptionIterator o = m_options.begin(); o != m_options.end(); ++o)
    {
      if (o->getName() == option)
	{
	  return true;
	}
    }
  return false;
}

void
CxxUtil::Getopt::showHelp(void)
{
  unsigned longest = 0;
  std::list<OptionDescription>::iterator it;
  for (it = m_optDescriptions.begin();
       it != m_optDescriptions.end(); ++it)
    {
      if (it->leftSide.size() > longest)
	{
	  longest = (int)it->leftSide.size();
	}
    }
  std::string outLine;
  for (it = m_optDescriptions.begin();
       it != m_optDescriptions.end(); ++it)
    {
      outLine = it->leftSide;
      outLine.append(longest - outLine.size(), ' ');
      outLine += " : " + it->rightSide;
      cout << " " << outLine << endl;
    }
}

// ----------------------- Private / Protected --------------------------------

std::string
CxxUtil::Getopt::ucar2str(const int chr)
{
  sprintf(m_convstr,"%c", chr);
  return m_convstr;
}

const std::string
CxxUtil::Getopt::ProgOption::getValue(void) const
{
  if (!m_valueSet)
    {
      throw std::invalid_argument("No value in option");
    }
  return m_value;
}

