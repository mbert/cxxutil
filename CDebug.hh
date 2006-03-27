#ifndef DEBUG_INCL
#define DEBUG_INCL
/* --------------------------------------------------------------------
// KLASSE:  CDebug
// AUFGABE: Definition einer einfachen Debug-Klasse/Funktionalitaet
// BESCHR.: 
//          
// ----------------------------------------------------------------- */

// $Id: CDebug.hh,v 1.2 2006-03-27 09:02:55 herbert Exp $

// debug inline functions?
#ifndef INLINE
#ifdef OUTLINE
#define INLINE
#else
#define INLINE inline
#endif
#endif

// system includes
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

// other includes
#include "cxxutils/cdefines.h"

namespace CxxUtils 
{

#if !defined (NDEBUG) && !defined (DPRINTF)

  int debug_printf (const char *tmpl, ...);

#define STRR(X) #X
#define STR(X) STRR(X)
#define DPRINTF(X) \
  (debug_printf("DEBUG %s [%s]: ", __FILE__, STR(__LINE__)), debug_printf X)

#else /* NDEBUG */

#ifdef DPRINTF
#undef DPRINTF
#endif
#define DPRINTF(x)
#endif

  /// Klasse zur Steuerung der Debugausgaben
  /** Entsprechende Ausgaben koennen ueber die Makros I_OUT, E_OUT und D_OUT
   *  initiiert werden. Die Ausgaben haben folgendes Format:
   *  
   *  X_OUT("myMethod", "any text and any" << variable << " can be streamed");
   */
  class CDebug
  {

  public:

    //! Aufzaehlungstyp fuer Debug-Level 
    /*! Debug-Levels koennen einzeln gesetzt werden (NONE setzt alles zurueck:)
      INFO = I_OUT Ausgabe; ERROR = E_OUT Ausgabe; DEBUG = D_OUT Ausgabe */
    enum DebugLevel
      { None = 0, Info = 1, Error = 2, Debug = 4, All = 7 };

    //! Konstruktor
    CDebug (void);

    //! Destruktor
    ~CDebug (void);

    //! Oeffnen einer Ausgabedatei (default: Stdout)
    static bool open (const char *fileName);

    //! Zugriff auf den aktuell verwendeten Stream
    static std::ostream & getOStr (void);

    //! Setzen des debug-level: Bit-Code
    static void setLevel (int l)
    {
      level = l;
    }
    //! Setzen des debug-level: Namen
    /** @param level textuelle Form einer OR-verknuepften Kombination
	verschiedenener Debuglevel (ohne whitespace!!); Bsp.: Debug|Error
    */
    static void setLevel (const char *level);
    //! Holen des debug-level
    static int getLevel (void)
    {
      return level;
    }
    //! Festlegen einer Fehlerdatei
    static void setErrStrFilename (const std::string & filename)
    {
      errorcodeFilename = filename;
    }
    //! Schreibt einen Fehlercode 
    static void writeErrorCode (int errorcode);

    //! Exit-Routine zum flushen der gepufferten Ausgaben
    static void exit (int errorcode)
    {
      if (ostr.is_open ())
	{
	  ostr.flush ();
	  ostr.close ();
	}

      writeErrorCode (errorcode);

      std::cout.flush ();
      ::exit (errorcode);
    }

  protected:

  private:

    //! Ausgabestream
    static std::ofstream ostr;
    //! Name des Errorcodefile 
    static std::string errorcodeFilename;
    //! aktueller Error-Level
    static int level;
  };



#define I_OUT(method,a) \
  {if ( CDebug::getLevel() & CDebug::Info ) {              \
     CDebug::getOStr()<<std::setiosflags(std::ios::left)   \
                      <<std::setfill(' ')<<std::setw(30)   \
                      <<__FILE__"::"method": "             \
                      <<std::resetiosflags(std::ios::left) \
                      << a <<std::endl;}}
#define D_OUT(method,a) \
  {if ( CDebug::getLevel() & CDebug::Debug ) {             \
     CDebug::getOStr()<<std::setiosflags(std::ios::left)   \
                      <<std::setfill(' ')<<std::setw(30)   \
                      <<__FILE__"::"method": "             \
                      <<std::resetiosflags(std::ios::left) \
                      <<std::setfill('0')<<"-("<<std::setw( 5)<<__LINE__\
                      <<"): " << a <<std::endl;}}


#endif
}

