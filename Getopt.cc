#include "cxxutils/Getopt.hh"

#include <stdexcept>
#include <iostream>
#include <cstdio>
#include <cassert>

#include "cxxutils/utils.h"
#include "cxxutils/cdefines.h"

extern "C" {
#include "cxxutils/getopt/getopt_wrapper.h"
}

extern int my_optopt;
extern int my_optind;
extern char *my_optarg;

using namespace std;

// ----------------------- Globals and Helpers --------------------------------

static struct option lastEntry = { NULL, 0, NULL, 0 };

static struct option *
structOption_grow(struct option *opts, int &currentSize)
{
	int newSize = currentSize + 10;
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
structOption_add(struct option *opts, int &currentSize, struct option entry)
{
	struct option *ret = opts;
	if (currentSize == 0) 
	{
		ret = structOption_grow(ret, currentSize);
	}
	int i = 0;
	for (i = 0; i<currentSize && opts->name != NULL; i++)
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

CxxUtils::Getopt::Getopt (bool useSystemWarning)
	: m_longOpts(NULL), m_longOptsSize(0), m_lastoptndx(1), m_error(false)
{
	if (!useSystemWarning)
	{
		my_opterr = 0;
	}
}

CxxUtils::Getopt::~Getopt (void)
{
	if (m_longOptsSize > 0)
	{
		for (int i = 0; i < m_longOptsSize; i++)
		{
			DELETE (m_longOpts[i].name);
		}
		DELETE (m_longOpts);
	}
}

void 
CxxUtils::Getopt::addOption (const char shortOpt, const bool takesArg, 
		const std::string description, const std::string longOpt)
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
		struct option tmp;
		tmp.name = strdup(longOpt);
		tmp.has_arg = (int)takesArg;
		tmp.flag = 0;
		tmp.val = (int)shortOpt;
		m_longOpts = structOption_add(m_longOpts, m_longOptsSize, tmp);
	}

	tmp.leftSide += (takesArg? "<arg>": "      ");
	tmp.rightSide = description;
	m_optDescriptions.push_back(tmp);
}

void 
CxxUtils::Getopt::process(const int argc, char* const argv[])
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
			m_lastError = "-" + (char)optopt;
		}
		ProgOption *popt;
		popt = !optarg? NEW (ProgOption(ucar2str(o)))
			: NEW (ProgOption(ucar2str(o), optarg));

		m_options.push_back(*popt);
		if (m_lastoptndx < optind)
		{
			m_lastoptndx = optind;
		}
	}
}

const CxxUtils::Getopt::ProgOption &
CxxUtils::Getopt::opt (const std::string option) const
{
	for (OptionIterator o = m_options.begin(); o != m_options.end(); ++o)
	{
		if (o->getName() == option)
		{
			return *o;
		}
	}
	throw std::invalid_argument("Option " + option + " not found");
}


bool 
CxxUtils::Getopt::given (const std::string option) const
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
CxxUtils::Getopt::showHelp(void)
{
	int longest = 0;
	for (std::list<OptionDescription>::iterator it = m_optDescriptions.begin();
			 it != m_optDescriptions.end(); ++it)
	{
		if ((int)it->leftSide.size() > longest)
		{
			longest = (int)it->leftSide.size();
		}
	}
	std::string outLine;
	for (std::list<OptionDescription>::iterator it = m_optDescriptions.begin();
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
CxxUtils::Getopt::ucar2str(const int chr)
{
	sprintf(m_convstr,"%c", chr);
	return m_convstr;
}

const std::string 
CxxUtils::Getopt::ProgOption::getValue() const 
{
	if (!m_valueSet)
	{
		throw std::invalid_argument("No value in option");
	}
	return m_value;
}

