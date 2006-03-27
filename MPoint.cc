/* -*-gnu-*- */
/*
 * CxxUtils C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated, this software is provided under the terms of the
 * GNU LESSER PUBLIC LICENSE. The text of this license agreement accompanies
 * this library's source distribution.
 */

#ifndef MPOINT_CC
#define MPOINT_CC

/* --------------------------------------------------------------------
 * Generic point class implementation
 *
 * $Date: 2006-03-27 11:08:15 $
 * $Revision: 1.3 $
 * -------------------------------------------------------------------- */

// class specific includes
#include "cxxutils/MPoint.hh"

template<class Scalar> 
CxxUtils::MPoint<Scalar>::MPoint (int dim)
  : AbstractTuple<Scalar> (dim)
{
}

template<class Scalar>
CxxUtils::MPoint<Scalar>::MPoint (const CxxUtils::MPoint<Scalar> &t)
  : AbstractTuple<Scalar> (t)
{
}

template<class Scalar>
CxxUtils::MPoint<Scalar>::MPoint (const CxxUtils::AbstractTuple<Scalar> &t)
  : AbstractTuple<Scalar> (t)
{
}

template<class Scalar>
CxxUtils::MPoint<Scalar>::MPoint (const int dim, const Scalar s)
  : AbstractTuple<Scalar> (dim, s)
{
}

template<class Scalar> 
CxxUtils::MPoint<Scalar>::~MPoint (void)
{
}

template<class Scalar> CxxUtils::MVector<Scalar>
CxxUtils::MPoint<Scalar>::toVector (void) const
{
  return MVector<Scalar> (*this);
}

// distance computaion
template<class Scalar> Scalar
CxxUtils::MPoint<Scalar>::dist (const CxxUtils::MPoint<Scalar> &q) const
{
  return (*this - q).getNorm ();
}

// include "outlined" INLINE functions
#ifdef OUTLINE
#include "cxxutils/MPoint.ih"
#endif


#endif // MPOINT_CC
