#ifndef MVECTOR4D_CPP
#define MVECTOR4D_CPP

/* ********************************************************************
//  Class: MVector4D
//  Implementation of class MVector4D
//  -------------------------------------------------------------------
//  Project: Repairing and texturing of VR models
//  (C) Copyright Fachhochschule Wedel, Germany 2002
// ******************************************************************** */

// system specific includes
#include <assert.h>

// class specific includes
#include "cxxutils/MVector4d.hh"

// include "outlined" INLINE functions
#ifdef OUTLINE
#include "cxxutils/MVector4d.ih"
#endif

// Description:
// Default constructor using MVector instantiation
template<class Scalar> 
CxxUtils::MVector4D<Scalar>::MVector4D (void)
  : MVector<Scalar> (4)
{
}



// Description:
// Build an instance given two doubles
template<class Scalar>
CxxUtils::MVector4D<Scalar>::MVector4D (const Scalar & u, const Scalar & v,
					   const Scalar & w, const Scalar & x)
  : MVector<Scalar> (4)
{
  this->m_coord[0] = u;
  this->m_coord[1] = v;
  this->m_coord[2] = w;
  this->m_coord[3] = x;
}


// Description:
// Upward copy constructor 
// This constructor is the base for inheriting the MVector-functionality
template<class Scalar>
CxxUtils::MVector4D<Scalar>::MVector4D (const MTuple<Scalar> &p)
  : MVector<Scalar> (p)
{
  assert (p.getDim () == 4);
}


// Description:
// Virtual destructor (just for completeness)
template<class Scalar> 
CxxUtils::MVector4D<Scalar>::~MVector4D (void)
{
}

#endif // MVECTOR4D_CPP
