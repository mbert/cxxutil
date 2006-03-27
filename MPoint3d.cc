#ifndef MPOINT3D_CPP
#define MPOINT3D_CPP

/* ********************************************************************
//  Class: MPoint3D
//  Implementation of class MPoint3D
//  -------------------------------------------------------------------
//  Project: Repairing and texturing of VR models
//  (C) Copyright Fachhochschule Wedel, Germany 2002
// ******************************************************************** */

// system specific includes
#include <assert.h>

// class specific includes
#include "cxxutils/MPoint3d.hh"

// include "outlined" INLINE functions
#ifdef OUTLINE
#include "cxxutils/MPoint3d.ih"
#endif

// Description:
// Default constructor using MPoint instantiation
template<class Scalar> 
CxxUtils::MPoint3D<Scalar>::MPoint3D (void)
  : MPoint<Scalar> (3)
{
}



// Description:
// Build an instance given two doubles
template<class Scalar>
CxxUtils::MPoint3D<Scalar>::MPoint3D (const Scalar & u, const Scalar & v,
					 const Scalar & w)
  : MPoint<Scalar> (3)
{
  this->m_coord[0] = u;
  this->m_coord[1] = v;
  this->m_coord[2] = w;
}


// Description:
// Upward copy constructor 
// This constructor is the base for inheriting the MPoint-functionality
template<class Scalar>
CxxUtils::MPoint3D<Scalar>::MPoint3D (const MTuple<Scalar> &p)
  : MPoint<Scalar> (p)
{
  assert (p.getDim () == 3);
}


// Description:
// Virtual destructor (just for completeness)
template<class Scalar> 
CxxUtils::MPoint3D<Scalar>::~MPoint3D (void)
{
}

#endif // MPOINT3D_CPP
