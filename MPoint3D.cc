/* -*-gnu-*- */
/*
 * CxxUtils C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated, this software is provided under the terms of the
 * GNU LESSER PUBLIC LICENSE. The text of this license agreement accompanies
 * this library's source distribution.
 */

#ifndef MPOINT3D_CC
#define MPOINT3D_CC

/* --------------------------------------------------------------------
 * 3D point class implementation
 *
 * $Date: 2006-03-27 11:08:15 $
 * $Revision: 1.1 $
 * -------------------------------------------------------------------- */

// system specific includes
#include <assert.h>

// class specific includes
#include "cxxutils/MPoint3D.hh"

// include "outlined" INLINE functions
#ifdef OUTLINE
#include "cxxutils/MPoint3D.ih"
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

#endif // MPOINT3D_CC
