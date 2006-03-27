#ifndef MPOINT_CPP
#define MPOINT_CPP

/* ********************************************************************
//  Class: MPoint
//  Implementation of class MPoint
//  -------------------------------------------------------------------
//  Project: Repairing and texturing of VR models
//  (C) Copyright Fachhochschule Wedel, Germany 2003
//  -------------------------------------------------------------------
//  $Revision: 1.2 $
//  $Date: 2006-03-27 09:02:55 $
// ******************************************************************** */

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


#endif // MPOINT_CPP
