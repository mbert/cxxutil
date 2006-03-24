/* ********************************************************************
//  Class: MVector
//  Implementation of class MVector
//  -------------------------------------------------------------------
//  Project: Repairing and texturing of VR models
//  (C) Copyright Fachhochschule Wedel, Germany 2003
//  -------------------------------------------------------------------
//  $Revision: 1.1 $
//  $Date: 2006-03-24 15:36:45 $
// ******************************************************************** */

#ifndef MVECTOR_CPP
#define MVECTOR_CPP

// class specific includes
#include "MVector.hh"

template < class Scalar > 
HmdUtils::MVector < Scalar >::MVector (int dim) : AbstractTuple < Scalar > (dim)
{
}

template < class Scalar >
HmdUtils::MVector < Scalar >::MVector (const MVector < Scalar > &t)
  : AbstractTuple < Scalar > (t)
{
}

template < class Scalar >
HmdUtils::MVector < Scalar >::MVector (const AbstractTuple < Scalar > &t)
  : AbstractTuple < Scalar > (t)
{
}

template < class Scalar >
HmdUtils::MVector < Scalar >::MVector (const int dim, const Scalar s)
  : AbstractTuple < Scalar > (dim, s)
{
}

template < class Scalar > 
HmdUtils::MVector < Scalar >::~MVector (void)
{
}

template < class Scalar > Scalar 
HmdUtils::MVector < Scalar >::operator| (const MVector < Scalar > &v) const
{
  return (*this * v).getSum ();
}

template < class Scalar > MPoint < Scalar > 
HmdUtils::MVector < Scalar >::toPoint (void) const
{
  return MPoint < Scalar > (*this);
}

// return a normalized version of *this
template < class Scalar > MVector < Scalar > 
HmdUtils::MVector < Scalar >::getNormalized (void) const
{
  return ((*this) / getNorm ());
}

// normalized this
template < class Scalar > Scalar 
HmdUtils::MVector < Scalar >::normalize (void)
{
  Scalar norm = getNorm ();
  (*this) /= norm;
  return norm;
}

// include "outlined" INLINE functions
#ifdef OUTLINE
#include "MVector.ih"
#endif


#endif // MVECTOR_CPP
