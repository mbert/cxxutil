/* -*-gnu-*- */
/*
 * CxxUtil C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated, this software is provided under the terms of the
 * GNU LESSER PUBLIC LICENSE. The text of this license agreement accompanies
 * this library's source distribution.
 */

#ifndef UTILS_H
#define UTILS_H

/* --------------------------------------------------------------------
 * Utility function declarations
 *
 * $Date: 2007-08-02 12:54:35 $
 * $Revision: 1.7 $
 * -------------------------------------------------------------------- */

/**
 * @short General utility functions
 */

#include <cstdio>
#include <cstdlib>
#include <string>

#ifndef INLINE
#ifdef OUTLINE
#define INLINE
#else
#define INLINE inline
#endif
#endif

namespace CxxUtil 
{

  /** Compute a simple hash value on a string
   * @param str the string
   * @param key the key
   * @param base the base
   * @return the hash */
  INLINE int simplehash (const char str[], int key = 997, int base = 128);

  /** Return the name for a temporary file
   * @param templ
   * the address of a writable char-array (<= 255 chars) for the file name 
   * @param extension
   * a string containing anything after the template string (e.g. ".jpg")
   * return 0 if the operation was successful, -1 if not */
  int tempFileName (char *templ, const char *extension = "");

  /** Return an open temporary file
   * @param templ
   * the address of a writable char-array (<= 255 chars) for the file name
   * @return the file handle, NULL on error */
  FILE *tempFile (char *templ);

  /** Set an environment variable
   * Note! On some platforms this function can only be used for one variable.
   * A new variable will overwrite the old one.
   * @param name the variable name
   * @param value the variable value
   * @return zero on success, -1 if error */
  int putEnvironment (char *name, char *value);

  unsigned char* htond (double dat);
  double ntohd (unsigned char *dat);

  /**
   * @brief Copies a C-string into a new one allocating necessary memory.
   * 
   * @param str the source string
   * @return the newly allocated result string 
   */
  char *strdup (const char *str);
  
  /**
   * Returns a new C-String from a std::string
   * @param str the input std::string
   * @return a new C-string
   */
  char *strdup(const std::string &str);

  /**
   * @brief Converts an integer into a string
   *
   * A pointer to a new string containing the result is returned. 
   *
   * @param num the number
   * @return a string object with the result
   */
  std::string itoa (long num);

  /**
   * @brief Converts an unsigned long integer into a string
   *
   * A pointer to a new string containing the result is returned. 
   *
   * @param num the number
   * @return a string object with the result
   */
  std::string utoa (unsigned long num);
  /**
   * Convert a string to a double
   * @param str the string to process
   * @return a double representing the number
   * @exception std::invalid_argument if the string could not be converted
   */
  double atod(const std::string &str);
  /**
   * Convert a string to a long int using any base
   * @param str the string to process
   * @param base the numbering base 
   * @return an int representing the number
   * @exception std::invalid_argument if the string could not be converted
   */
  long atoi(const std::string &str, int base = 10);
  /**
   * Convert a string to a unsigned long int using any base
   * @param str the string to process
   * @param base the numbering base 
   * @return an int representing the number
   * @exception std::invalid_argument if the string could not be converted
   */
  unsigned long atou(const std::string &str, int base = 10);

#define CXXU_NTOHD(x) ntohd(x)
#define CXXU_HTOND(x) htond(x)

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
}

#ifndef OUTLINE
#include "cxxutil/utils.ih"
#endif

#endif
