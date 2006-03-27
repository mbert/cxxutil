/* -*-gnu-*- */
/*
 * CxxUtils C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated, this software is provided under the terms of the
 * GNU LESSER PUBLIC LICENSE. The text of this license agreement accompanies
 * this library's source distribution.
 */

#ifndef MVECTOR2D_CC
#define MVECTOR2D_CC

/* --------------------------------------------------------------------
 * 2D vector class implementation
 *
 * $Date: 2006-03-27 11:08:15 $
 * $Revision: 1.1 $
 * -------------------------------------------------------------------- */

// system specific includes
#include <assert.h>

// class specific includes
#include "cxxutils/MVector2D.hh"

// include "outlined" INLINE functions
#ifdef OUTLINE
#include "cxxutils/MVector2D.ih"
#endif

// Description:
// Default constructor using MVector instantiation
template<class Scalar> 
CxxUtils::MVector2D<Scalar>::MVector2D (void)
  : MVector<Scalar> (2)
{
}



// Description:
// Build an instance given two doubles
template<class Scalar>
CxxUtils::MVector2D<Scalar>::MVector2D (const Scalar & u, const Scalar & v)
  : MVector<Scalar> (2)
{
  this->m_coord[0] = u;
  this->m_coord[1] = v;
}


// Description:
// Upward copy constructor 
// This constructor is the base for inheriting the MVector-functionality
template<class Scalar>
CxxUtils::MVector2D<Scalar>::MVector2D (const MTuple<Scalar> &p)
  : MVector<Scalar> (p)
{
  assert (p.getDim () == 2);
}


// Description:
// Virtual destructor (just for completeness)
template<class Scalar> 
CxxUtils::MVector2D<Scalar>::~MVector2D (void)
{
}

template<class Scalar> CxxUtils::MVector2D<Scalar>
CxxUtils::MVector2D<Scalar>::getOrthogonal (void) const
{
  return MVector2D (-this->m_coord[1], this->m_coord[0]);
}

#endif // MVECTOR2D_CC
