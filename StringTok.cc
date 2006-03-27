/**
 * String tokenizer class for use with C++ std::string or whatever.
 * Code based on Conversations article in C/C++ Users' Journal, issue 10/2001 
 */

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
