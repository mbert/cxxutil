#ifndef MPOINT_CPP
#define MPOINT_CPP

/* ********************************************************************
//  Class: MPoint
//  Implementation of class MPoint
//  -------------------------------------------------------------------
//  Project: Repairing and texturing of VR models
//  (C) Copyright Fachhochschule Wedel, Germany 2003
//  -------------------------------------------------------------------
//  $Revision: 1.1 $
//  $Date: 2006-03-24 15:36:45 $
// ******************************************************************** */

// class specific includes
#include "MPoint.hh"

template < class Scalar > 
HmdUtils::MPoint < Scalar >::MPoint (int dim)
  : AbstractTuple < Scalar > (dim)
{
}

template < class Scalar >
HmdUtils::MPoint < Scalar >::MPoint (const MPoint < Scalar > &t)
  : AbstractTuple < Scalar > (t)
{
}

template < class Scalar >
HmdUtils::MPoint < Scalar >::MPoint (const AbstractTuple < Scalar > &t)
  : AbstractTuple < Scalar > (t)
{
}

template < class Scalar >
HmdUtils::MPoint < Scalar >::MPoint (const int dim, const Scalar s)
  : AbstractTuple < Scalar > (dim, s)
{
}

template < class Scalar > 
HmdUtils::MPoint < Scalar >::~MPoint (void)
{
}

template < class Scalar > MVector < Scalar >
HmdUtils::MPoint < Scalar >::toVector (void) const
{
  return MVector < Scalar > (*this);
}

// distance computaion
template < class Scalar > Scalar
HmdUtils::MPoint < Scalar >::dist (const MPoint < Scalar > &q) const
{
  return (*this - q).getNorm ();
}

// include "outlined" INLINE functions
#ifdef OUTLINE
#include "MPoint.ih"
#endif


#endif // MPOINT_CPP
