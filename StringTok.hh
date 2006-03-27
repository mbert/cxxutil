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

#ifndef STRING_TOK_H
#define STRING_TOK_H

/* --------------------------------------------------------------------
 * String Tokenizer class definition
 *
 * $Date: 2006-03-27 11:08:15 $
 * $Revision: 1.3 $
 * -------------------------------------------------------------------- */

/**
 * @class StringTok
 * @short String tokenizer class for use with C++ std::string or whatever.
 */
namespace CxxUtils
{
  template<class T>
  class StringTok
  {
  public:
    StringTok (const T& seq, typename T::size_type pos = 0)
      : m_seq (seq), m_pos (pos) { }

    T operator() (const T& delim);

  private:
    const T&           m_seq;
    typename T::size_type m_pos;
  };
}

#include "cxxutils/StringTok.cc"

#endif // STRING_TOK_H
