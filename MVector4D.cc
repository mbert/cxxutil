/* -*-gnu-*- */
/*
 * CxxUtil C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated, this software is provided under the terms of the
 * GNU LESSER PUBLIC LICENSE. The text of this license agreement accompanies
 * this library's source distribution.
 */

#ifndef MVECTOR4D_CC
#define MVECTOR4D_CC

/* --------------------------------------------------------------------
 * 4D vector class implementation
 *
 * $Date: 2006-03-27 13:40:22 $
 * $Revision: 1.3 $
 * -------------------------------------------------------------------- */

// system specific includes
#include <cassert>

// class specific includes
#include "cxxutil/MVector4D.hh"

// include "outlined" INLINE functions
#ifdef OUTLINE
#include "cxxutil/MVector4D.ih"
#endif

// Description:
// Default constructor using MVector instantiation
template<class Scalar> 
CxxUtil::MVector4D<Scalar>::MVector4D (void)
  : MVector<Scalar> (4)
{
}



// Description:
// Build an instance given two doubles
template<class Scalar>
CxxUtil::MVector4D<Scalar>::MVector4D (const Scalar & u, const Scalar & v,
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
CxxUtil::MVector4D<Scalar>::MVector4D (const MTuple<Scalar> &p)
  : MVector<Scalar> (p)
{
  assert (p.getDim () == 4);
}


// Description:
// Virtual destructor (just for completeness)
template<class Scalar> 
CxxUtil::MVector4D<Scalar>::~MVector4D (void)
{
}

#endif // MVECTOR4D_CC
