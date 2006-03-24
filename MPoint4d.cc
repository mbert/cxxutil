#ifndef MPOINT4D_CPP
#define MPOINT4D_CPP

/* ********************************************************************
//  Class: MPoint4D
//  Implementation of class MPoint4D
//  -------------------------------------------------------------------
//  Project: Repairing and texturing of VR models
//  (C) Copyright Fachhochschule Wedel, Germany 2002
// ******************************************************************** */

// system specific includes

// class specific includes
#include "MPoint4d.hh"

// include "outlined" INLINE functions
#ifdef OUTLINE
#include "MPoint4d.ih"
#endif

// Description:
// Default constructor using MPoint instantiation
template < class Scalar > 
HmdUtils::MPoint4D < Scalar >::MPoint4D (void)
  : MPoint < Scalar > (4)
{
}



// Description:
// Build an instance given two doubles
template < class Scalar >
HmdUtils::MPoint4D < Scalar >::MPoint4D (const Scalar & u, const Scalar & v,
					 const Scalar & w, const Scalar & x)
  : MPoint < Scalar > (4)
{
  this->m_coord[0] = u;
  this->m_coord[1] = v;
  this->m_coord[2] = w;
  this->m_coord[3] = x;
}


// Description:
// Upward copy constructor 
// This constructor is the base for inheriting the MPoint-functionality
template < class Scalar >
HmdUtils::MPoint4D < Scalar >::MPoint4D (const MTuple < Scalar > &p)
  : MPoint < Scalar > (p)
{
  assert (p.getDim () == 4);
}


// Description:
// Virtual destructor (just for completeness)
template < class Scalar > 
HmdUtils::MPoint4D < Scalar >::~MPoint4D (void)
{
}

template < class Scalar > MPoint3D < Scalar >
HmdUtils::MPoint4D < Scalar >::projectTo3D (void) const
{
  MPoint3D < Scalar > res ((*this)[0] / (*this)[3],
                           (*this)[1] / (*this)[3], (*this)[2] / (*this)[3]);
  //std::cout << res << endl;
  return res;
}

#endif // MPOINT4D_CPP
