#ifndef MVECTOR2D_CPP
#define MVECTOR2D_CPP

/* ********************************************************************
//  Class: MVector2D
//  Implementation of class MVector2D
//  -------------------------------------------------------------------
//  Project: Repairing and texturing of VR models
//  (C) Copyright Fachhochschule Wedel, Germany 2002
// ******************************************************************** */

// system specific includes
#include <assert.h>

// class specific includes
#include "MVector2d.hh"

// include "outlined" INLINE functions
#ifdef OUTLINE
#include "MVector2d.ih"
#endif

// Description:
// Default constructor using MVector instantiation
template < class Scalar > 
HmdUtils::MVector2D < Scalar >::MVector2D (void)
  : MVector < Scalar > (2)
{
}



// Description:
// Build an instance given two doubles
template < class Scalar >
HmdUtils::MVector2D < Scalar >::MVector2D (const Scalar & u, const Scalar & v)
  : MVector < Scalar > (2)
{
  this->m_coord[0] = u;
  this->m_coord[1] = v;
}


// Description:
// Upward copy constructor 
// This constructor is the base for inheriting the MVector-functionality
template < class Scalar >
HmdUtils::MVector2D < Scalar >::MVector2D (const MTuple < Scalar > &p)
  : MVector < Scalar > (p)
{
  assert (p.getDim () == 2);
}


// Description:
// Virtual destructor (just for completeness)
template < class Scalar > 
HmdUtils::MVector2D < Scalar >::~MVector2D (void)
{
}

template < class Scalar > MVector2D < Scalar >
HmdUtils::MVector2D < Scalar >::getOrthogonal (void) const
{
  return MVector2D (-this->m_coord[1], this->m_coord[0]);
}

#endif // MVECTOR2D_CPP
