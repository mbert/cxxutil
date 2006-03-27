/* -*-gnu-*- */
/*
 * CxxUtil C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated, this software is provided under the terms of the
 * GNU LESSER PUBLIC LICENSE. The text of this license agreement accompanies
 * this library's source distribution.
 */

#ifndef MVECTOR3D_CC
#define MVECTOR3D_CC

/* --------------------------------------------------------------------
 * 3D vector class implementation
 *
 * $Date: 2006-03-27 13:00:00 $
 * $Revision: 1.2 $
 * -------------------------------------------------------------------- */

// system specific includes
#include <assert.h>

// class specific includes
#include "cxxutil/MVector3D.hh"

// include "outlined" INLINE functions
#ifdef OUTLINE
#include "cxxutil/MVector3D.ih"
#endif

// Description:
// Default constructor using MVector instantiation
template<class Scalar> 
CxxUtil::MVector3D<Scalar>::MVector3D (void)
  : MVector<Scalar> (3)
{
}



// Description:
// Build an instance given two doubles
template<class Scalar>
CxxUtil::MVector3D<Scalar>::MVector3D (const Scalar & u, const Scalar & v,
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
CxxUtil::MVector3D<Scalar>::MVector3D (const MTuple<Scalar> &p)
  : MVector<Scalar> (p)
{
  assert (p.getDim () == 3);
}


// Description:
// Virtual destructor (just for completeness)
template<class Scalar> 
CxxUtil::MVector3D<Scalar>::~MVector3D (void)
{
}

template<class Scalar> CxxUtil::MVector3D<Scalar>
CxxUtil::MVector3D<Scalar>::operator^ (const MVector3D & v) const
{
  MVector3D ret;

  ret[0] = this->m_coord[1] * v[2] - this->m_coord[2] * v[1];
  ret[1] = this->m_coord[2] * v[0] - this->m_coord[0] * v[2];
  ret[2] = this->m_coord[0] * v[1] - this->m_coord[1] * v[0];

  return ret;
}


#endif // MVECTOR3D_CC
