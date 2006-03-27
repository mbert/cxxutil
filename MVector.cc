/* -*-gnu-*- */
/*
 * CxxUtil C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated, this software is provided under the terms of the
 * GNU LESSER PUBLIC LICENSE. The text of this license agreement accompanies
 * this library's source distribution.
 */

#ifndef MVECTOR_CC
#define MVECTOR_CC

/* --------------------------------------------------------------------
 * Generic vector class implementation
 *
 * $Date: 2006-03-27 13:00:00 $
 * $Revision: 1.4 $
 * -------------------------------------------------------------------- */

// class specific includes
#include "cxxutil/MVector.hh"

template<class Scalar> 
CxxUtil::MVector<Scalar>::MVector (int dim) : AbstractTuple<Scalar> (dim)
{
}

template<class Scalar>
CxxUtil::MVector<Scalar>::MVector (const MVector<Scalar> &t)
  : AbstractTuple<Scalar> (t)
{
}

template<class Scalar>
CxxUtil::MVector<Scalar>::MVector (const AbstractTuple<Scalar> &t)
  : AbstractTuple<Scalar> (t)
{
}

template<class Scalar>
CxxUtil::MVector<Scalar>::MVector (const int dim, const Scalar s)
  : AbstractTuple<Scalar> (dim, s)
{
}

template<class Scalar> 
CxxUtil::MVector<Scalar>::~MVector (void)
{
}

template<class Scalar> Scalar 
CxxUtil::MVector<Scalar>::operator| (const MVector<Scalar> &v) const
{
  return (*this * v).getSum ();
}

template<class Scalar> CxxUtil::MPoint<Scalar> 
CxxUtil::MVector<Scalar>::toPoint (void) const
{
  return MPoint<Scalar> (*this);
}

// return a normalized version of *this
template<class Scalar> CxxUtil::MVector<Scalar> 
CxxUtil::MVector<Scalar>::getNormalized (void) const
{
  return ((*this) / getNorm ());
}

// normalized this
template<class Scalar> Scalar 
CxxUtil::MVector<Scalar>::normalize (void)
{
  Scalar norm = getNorm ();
  (*this) /= norm;
  return norm;
}

// include "outlined" INLINE functions
#ifdef OUTLINE
#include "cxxutil/MVector.ih"
#endif


#endif // MVECTOR_CC
