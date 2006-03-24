// --------------------------------------------------------------------
/*! @file utils.h
 * @short General utility functions
 */
// --------------------------------------------------------------------
#ifndef UTILS_H
#define UTILS_H

#include "Wave.hh"
#include "math/MMatrix.h"
#include "common/cdefines.h"

#include <stdio.h>
//#include <stdlib.h>
#include <cstdlib>

#ifndef INLINE
#ifdef OUTLINE
#define INLINE
#else
#define INLINE inline
#endif
#endif

namespace HmdUtils 
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

  /** Compute the inner product between a matrix and the underlying area of
   * an image. Placing the matrix outside the image boundaries is legal. In 
   * such cases the image boundaries will be used as mirror axises to map 
   * all locations back into the image.
   * @param mat the matrix
   * @param img the image
   * @param ypos the uppermost row in the image to start with
   * @param xpos the leftmost col in the image to start with */
  double innerProduct (MMatrix < double > &mat, Image &img, 
			     int ypos, int xpos);

  unsigned char* htond (double dat);
  double ntohd (unsigned char *dat);

#define BMBF_NTOHD(x) ntohd(x)
#define BMBF_HTOND(x) htond(x)

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#ifndef OUTLINE
#include "utils/utils.ih"
#endif
}


#endif
