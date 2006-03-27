/* -*-gnu-*- */
/*
 * CxxUtil C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated, this software is provided under the terms of the
 * GNU LESSER PUBLIC LICENSE. The text of this license agreement accompanies
 * this library's source distribution.
 */

#ifndef MMATRIX4X4_CC
#define MMATRIX4X4_CC

/* --------------------------------------------------------------------
 * 4x4 Matrix class implementation
 *
 * $Date: 2006-03-27 13:00:00 $
 * $Revision: 1.4 $
 * -------------------------------------------------------------------- */

// class specific includes
#include "cxxutil/MMatrix4x4.hh"

// system specific includes

template<class Scalar> 
CxxUtil::MMatrix4x4<Scalar>::MMatrix4x4 (Scalar value)
  :MMatrix<Scalar> (4, 4, value)
{
}

template<class Scalar> 
CxxUtil::MMatrix4x4<Scalar>::MMatrix4x4 (const MMatrix4x4<Scalar> &matrix)
  : MMatrix<Scalar> (matrix)
{
}

template<class Scalar> 
CxxUtil::MMatrix4x4<Scalar>::~MMatrix4x4 (void)
{
}

#endif // MMATRIX4X4_CC
