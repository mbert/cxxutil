/* -*-gnu-*- */
/*
 * CxxUtil C++ utility library
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
 * $Date: 2006-03-27 13:00:00 $
 * $Revision: 1.4 $
 * -------------------------------------------------------------------- */

// class specific includes
#include "cxxutil/MPoint.hh"

template<class Scalar> 
CxxUtil::MPoint<Scalar>::MPoint (int dim)
  : AbstractTuple<Scalar> (dim)
{
}

template<class Scalar>
CxxUtil::MPoint<Scalar>::MPoint (const CxxUtil::MPoint<Scalar> &t)
  : AbstractTuple<Scalar> (t)
{
}

template<class Scalar>
CxxUtil::MPoint<Scalar>::MPoint (const CxxUtil::AbstractTuple<Scalar> &t)
  : AbstractTuple<Scalar> (t)
{
}

template<class Scalar>
CxxUtil::MPoint<Scalar>::MPoint (const int dim, const Scalar s)
  : AbstractTuple<Scalar> (dim, s)
{
}

template<class Scalar> 
CxxUtil::MPoint<Scalar>::~MPoint (void)
{
}

template<class Scalar> CxxUtil::MVector<Scalar>
CxxUtil::MPoint<Scalar>::toVector (void) const
{
  return MVector<Scalar> (*this);
}

// distance computaion
template<class Scalar> Scalar
CxxUtil::MPoint<Scalar>::dist (const CxxUtil::MPoint<Scalar> &q) const
{
  return (*this - q).getNorm ();
}

// include "outlined" INLINE functions
#ifdef OUTLINE
#include "cxxutil/MPoint.ih"
#endif


#endif // MPOINT_CC
