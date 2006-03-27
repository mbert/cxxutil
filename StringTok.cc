/* -*-gnu-*- */
/*
 * CxxUtils C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated, this software is provided under the terms of the
 * GNU LESSER PUBLIC LICENSE. The text of this license agreement accompanies
 * this library's source distribution.
 *
 * This source file is based on code published in C/C++ Users' Journal, issue
 * 10/2001. The exact license terms are unknown, BSD-like license is assumed.
 */

#ifndef STRING_TOK_CC
#define STRING_TOK_CC

/* --------------------------------------------------------------------
 * String Tokenizer class implementation
 *
 * $Date: 2006-03-27 11:08:15 $
 * $Revision: 1.3 $
 * -------------------------------------------------------------------- */

#include "cxxutils/StringTok.hh"

template<class T> T
CxxUtils::StringTok<T>::operator() (const T& delim)
{
  T token;

  if (m_pos != T::npos)
    {
      /* start of found token */
      typename T::size_type first = m_seq.find_first_not_of (delim.c_str(), m_pos);
      if (first != T::npos)
	{
	  /* length of found token */
	  typename T::size_type num
	    = m_seq.find_first_of (delim.c_str (), first) - first;

	  /* do all the work off to the side */
	  token = m_seq.substr (first, num);

	  /* done; now commit using
	   * nonthrowing operations only */
	  m_pos = first + num;
	  if (m_pos != T::npos)
	    {
	      ++m_pos;
	    }
	  if (m_pos >= m_seq.size ())
	    {
	      m_pos = T::npos;
	    }
	}
    }

  return token;
}

#endif // STRING_TOK_CC
