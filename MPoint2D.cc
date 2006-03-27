/* -*-gnu-*- */
/*
 * CxxUtil C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated, this software is provided under the terms of the
 * GNU LESSER PUBLIC LICENSE. The text of this license agreement accompanies
 * this library's source distribution.
 */

#ifndef MPOINT2D_CC
#define MPOINT2D_CC

/* --------------------------------------------------------------------
 * 2D point class implementation
 *
 * $Date: 2006-03-27 13:40:22 $
 * $Revision: 1.3 $
 * -------------------------------------------------------------------- */

// system specific includes
#include <cassert>

// class specific includes
#include "cxxutil/MPoint2D.hh"

// include "outlined" INLINE functions
#ifdef OUTLINE
#include "cxxutil/MPoint2D.ih"
#endif

// Description:
// Default constructor using MPoint instantiation
template<class Scalar> 
CxxUtil::MPoint2D<Scalar>::MPoint2D (void)
  : MPoint<Scalar> (2)
{
}



// Description:
// Build an instance given two doubles
template<class Scalar>
CxxUtil::MPoint2D<Scalar>::MPoint2D (const Scalar & u, const Scalar & v)
  : MPoint<Scalar> (2)
{
  this->m_coord[0] = u;
  this->m_coord[1] = v;
}


// Description:
// Upward copy constructor 
// This constructor is the base for inheriting the MPoint-functionality
template<class Scalar>
CxxUtil::MPoint2D<Scalar>::MPoint2D (const MTuple<Scalar> &p)
  : MPoint<Scalar> (p)
{
  assert (p.getDim () == 2);
}


// Description:
// Virtual destructor (just for completeness)
template<class Scalar> 
CxxUtil::MPoint2D<Scalar>::~MPoint2D (void)
{
}

#endif // MPOINT2D_CC
