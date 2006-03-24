#ifndef UTIL_MATH_H
#define UTIL_MATH_H

/** @addtogroup math */
// *********************************************************************
//  @short Math utilities
//
//  Defines some small math utility functions.
//
//  @ingroup math 
//  @author  Andreas Kolb <ko@fh-wedel.de>, Martin Dietze <herbert@spamcop.net>
//  @version 0.1
//
/*  --------------------------------------------------------------------
//  Project: Repairing and texturing of VR models
//  (C) Copyright Fachhochschule Wedel, Germany 2003
//  --------------------------------------------------------------------
//  $Revision: 1.1 $
//  $Date: 2006-03-24 15:36:45 $
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
#include "cdefines.h"

namespace HmdUtils 
{

  INLINE double Cub (double a);
  INLINE float Cub (float a);
  INLINE double Sqr (double a);
  INLINE float Sqr (float a);
  INLINE int Abs (int a);
  INLINE void Swap (double &a, double &b);
  INLINE void Swap (float &a, float &b);
  INLINE void Swap (int &a, int &b);
  INLINE double Sign (double a, double b);
  INLINE float Sign (float a, float b);
  INLINE int Sign (int a, int b);
  INLINE double Min (double a, double b);
  INLINE double Max (double a, double b);
  INLINE float Min (float a, float b);
  INLINE float Max (float a, float b);
  INLINE int Min (int a, int b);
  INLINE int Max (int a, int b);
  INLINE int toInt (double a);
  INLINE int toInt (float a);
  INLINE bool isZero (double d);
  INLINE bool isZero (float f);

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

  // include INLINES if required
#ifndef OUTLINE
#include "mutil.ih"
#endif
}

#endif // UTIL_MATH_H
