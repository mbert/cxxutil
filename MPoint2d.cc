#ifndef MPOINT2D_CPP
#define MPOINT2D_CPP

/* ********************************************************************
//  Class: MPoint2D
//  Implementation of class MPoint2D
//  -------------------------------------------------------------------
//  Project: Repairing and texturing of VR models
//  (C) Copyright Fachhochschule Wedel, Germany 2002
// ******************************************************************** */

// system specific includes
#include <assert.h>

// class specific includes
#include "cxxutils/MPoint2d.hh"

// include "outlined" INLINE functions
#ifdef OUTLINE
#include "cxxutils/MPoint2d.ih"
#endif

// Description:
// Default constructor using MPoint instantiation
template<class Scalar> 
CxxUtils::MPoint2D<Scalar>::MPoint2D (void)
  : MPoint<Scalar> (2)
{
}



// Description:
// Build an instance given two doubles
template<class Scalar>
CxxUtils::MPoint2D<Scalar>::MPoint2D (const Scalar & u, const Scalar & v)
  : MPoint<Scalar> (2)
{
  this->m_coord[0] = u;
  this->m_coord[1] = v;
}


// Description:
// Upward copy constructor 
// This constructor is the base for inheriting the MPoint-functionality
template<class Scalar>
CxxUtils::MPoint2D<Scalar>::MPoint2D (const MTuple<Scalar> &p)
  : MPoint<Scalar> (p)
{
  assert (p.getDim () == 2);
}


// Description:
// Virtual destructor (just for completeness)
template<class Scalar> 
CxxUtils::MPoint2D<Scalar>::~MPoint2D (void)
{
}

#endif // MPOINT2D_CPP
