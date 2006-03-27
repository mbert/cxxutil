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

#ifndef MMATRIX4X4_H
#define MMATRIX4X4_H

/* --------------------------------------------------------------------
 * 4D Matrix class definition
 *
 * $Date: 2006-03-27 11:08:15 $
 * $Revision: 1.3 $
 * -------------------------------------------------------------------- */

/**
 * @class MMatrix4x4
 *
 * @short A 4x4 matrix. This specialized version is only necessary to 
 * provide support for the 4x4 array structure needed by RxHelper.
 */

// INLINE declaration
#ifndef INLINE
#ifdef OUTLINE
#define INLINE
#else
#define INLINE inline
#endif
#endif

#include "cxxutils/MMatrix.hh"

namespace CxxUtils 
{

  template<class Scalar> class MMatrix4x4:public MMatrix<Scalar>
  {
  public:
    /** default constutor that initializes all elements
     * @param value the initial value for all elements */
    MMatrix4x4 (Scalar value = 0);
    /** copy constructor
     * @param matrix the source matrix */
    MMatrix4x4 (const MMatrix4x4<Scalar> &matrix);
    /** destructor */
    ~MMatrix4x4 (void);
    /** read the matrix contents from a 4x4-array
     *  @param a an array containing data as a[col][row] */
    INLINE void fromA (Scalar (&a)[4][4]);
  };

  /** this is needed by RxHelper in Redux */
  typedef MMatrix4x4<float>MFloatMatrix4x4;
}

  // include INLINES if required
#include "cxxutils/MMatrix4x4.cc"
#ifndef OUTLINE
#include "cxxutils/MMatrix4x4.ih"
#endif


#endif // MMATRIX4X4_H
