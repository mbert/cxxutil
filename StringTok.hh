/**
 * String tokenizer class for use with C++ std::string or whatever.
 * Code based on Conversations article in C/C++ Users' Journal, issue 10/2001 
 */

namespace HmdUtils
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

