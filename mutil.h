#ifndef UTIL_MATH_H
#define UTIL_MATH_H

/** @addtogroup math */
// *********************************************************************
//  @short Math utilities
//
//  Defines some small math utility functions.
//
//  @ingroup math 
//  @author  Andreas Kolb<ko@fh-wedel.de>, Martin Dietze<herbert@spamcop.net>
//  @version 0.1
//
/*  --------------------------------------------------------------------
//  Project: Repairing and texturing of VR models
//  (C) Copyright Fachhochschule Wedel, Germany 2003
//  --------------------------------------------------------------------
//  $Revision: 1.2 $
//  $Date: 2006-03-27 09:02:56 $
// ********************************************************************** */

// INLINE declaration
#ifndef INLINE
#ifdef OUTLINE
#define INLINE
#else
#define INLINE inline
#endif
#endif

// project specific includes
#include "cxxutils/cdefines.h"

namespace CxxUtils 
{

  INLINE double cub (double a);
  INLINE float cub (float a);
  INLINE double sqr (double a);
  INLINE float sqr (float a);
  INLINE int abs (int a);
  INLINE void swap (double &a, double &b);
  INLINE void swap (float &a, float &b);
  INLINE void swap (int &a, int &b);
  INLINE double sign (double a, double b);
  INLINE float sign (float a, float b);
  INLINE int sign (int a, int b);
  INLINE double min (double a, double b);
  INLINE double max (double a, double b);
  INLINE float min (float a, float b);
  INLINE float max (float a, float b);
  INLINE int min (int a, int b);
  INLINE int max (int a, int b);
  INLINE int toInt (double a);
  INLINE int toInt (float a);
  INLINE bool isZero (double d);
  INLINE bool isZero (float f);

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
}

  // include INLINES if required
#ifndef OUTLINE
#include "cxxutils/mutil.ih"
#endif

#endif // UTIL_MATH_H
