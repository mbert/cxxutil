#ifndef MVECTOR3D_CPP
#define MVECTOR3D_CPP

/* ********************************************************************
//  Class: MVector3D
//  Implementation of class MVector3D
//  -------------------------------------------------------------------
//  Project: Repairing and texturing of VR models
//  (C) Copyright Fachhochschule Wedel, Germany 2002
// ******************************************************************** */

// system specific includes
#include <assert.h>

// class specific includes
#include "cxxutils/MVector3d.hh"

// include "outlined" INLINE functions
#ifdef OUTLINE
#include "cxxutils/MVector3d.ih"
#endif

// Description:
// Default constructor using MVector instantiation
template<class Scalar> 
CxxUtils::MVector3D<Scalar>::MVector3D (void)
  : MVector<Scalar> (3)
{
}



// Description:
// Build an instance given two doubles
template<class Scalar>
CxxUtils::MVector3D<Scalar>::MVector3D (const Scalar & u, const Scalar & v,
                                   const Scalar & w): MVector<Scalar> (3)
{
  this->m_coord[0] = u;
  this->m_coord[1] = v;
  this->m_coord[2] = w;
}


// Description:
// Upward copy constructor 
// This constructor is the base for inheriting the MVector-functionality
template<class Scalar>
CxxUtils::MVector3D<Scalar>::MVector3D (const MTuple<Scalar> &p)
  : MVector<Scalar> (p)
{
  assert (p.getDim () == 3);
}


// Description:
// Virtual destructor (just for completeness)
template<class Scalar> 
CxxUtils::MVector3D<Scalar>::~MVector3D (void)
{
}

template<class Scalar> CxxUtils::MVector3D<Scalar>
CxxUtils::MVector3D<Scalar>::operator^ (const MVector3D & v) const
{
  MVector3D ret;

  ret[0] = this->m_coord[1] * v[2] - this->m_coord[2] * v[1];
  ret[1] = this->m_coord[2] * v[0] - this->m_coord[0] * v[2];
  ret[2] = this->m_coord[0] * v[1] - this->m_coord[1] * v[0];

  return ret;
}


#endif // MVECTOR3D_CPP
