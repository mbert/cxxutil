/* -*-gnu-*- */
/*
 * CxxUtils C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated in the source file, this code is provided under 
 * the terms of the GNU LESSER PUBLIC LICENSE. The text of this license 
 * agreement accompanies this library's source distribution.
 *
 * This source file is based on code published in C/C++ Users' Journal, issue
 * 10/2001. The exact license terms are unknown, BSD-like license is assumed.
 */

#ifndef GETOPT_H
#define GETOPT_H

/* --------------------------------------------------------------------
 * Getopt wrapper class definition
 *
 * $Date: 2006-03-27 11:08:15 $
 * $Revision: 1.3 $
 * -------------------------------------------------------------------- */

#include <list>
#include <string>

#ifndef INLINE
#ifdef OUTLINE
#define INLINE
#else
#define INLINE inline
#endif
#endif

struct my_option;

namespace CxxUtils 
{
  extern int my_opterr;

  /**
   * @class Getopt
   * This wraps the Unix-/GNU-style getopt function for use in C++ code.
   * It uses its own (BSD-licensed) getopt implementation and is thus 
   * OS-independent
   */
  class Getopt {
  public:

    class ProgOption {
    public:
      ProgOption (const std::string option, const std::string value)
	: m_option(option), m_value(value), m_valueSet(true) {}
      ProgOption (const std::string option)
	: m_option(option), m_valueSet(false) {}
      INLINE const std::string getName(void) const {return m_option;}
      const std::string getValue(void) const; 
    private:
      const std::string m_option;
      const std::string m_value;
      const bool m_valueSet;
    };

	
    Getopt (bool useSystemWarning = true);
    ~Getopt (void);
    void addOption (const char shortOpt, const bool takesArg, 
		    const std::string description, const std::string longOpt = "");
    void process(const int argc, char* const argv[]);
    const Getopt::ProgOption& opt (const std::string option) const;
    bool given (const std::string option) const;
    int firstnonop(void) const {return m_lastoptndx;}
    INLINE bool error(void) const {return m_error;}
    INLINE void disableWarnings(void) { my_opterr = 0;}
    INLINE void enableWarnings(void) { my_opterr = 1;}
    INLINE std::string lastInvalid(void) const { return m_lastError; }
    void showHelp(void);

  private:
    std::string ucar2str(const int chr);

    typedef std::list<ProgOption> OptionList;
    typedef OptionList::const_iterator OptionIterator;

    typedef struct {
      std::string leftSide;
      std::string rightSide;
    } OptionDescription;

    std::list<OptionDescription> m_optDescriptions;

    std::string m_optionString; 
    struct my_option *m_longOpts;
    std::string m_lastError;
    int m_longOptsSize;
    int m_lastoptndx;
    OptionList m_options;
    char m_convstr[2];
    bool m_error;
  };
 
}

#endif //GETOPT_H
