/* -*-gnu-*- */
/*
 * CxxUtils C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated, this software is provided under the terms of the
 * GNU LESSER PUBLIC LICENSE. The text of this license agreement accompanies
 * this library's source distribution.
 */

#ifndef MPOINT4D_CC
#define MPOINT4D_CC

/* --------------------------------------------------------------------
 * 4D point class implementation
 *
 * $Date: 2006-03-27 11:08:15 $
 * $Revision: 1.1 $
 * -------------------------------------------------------------------- */

// system specific includes

// class specific includes
#include "cxxutils/MPoint4D.hh"

// include "outlined" INLINE functions
#ifdef OUTLINE
#include "cxxutils/MPoint4D.ih"
#endif

// Description:
// Default constructor using MPoint instantiation
template<class Scalar> 
CxxUtils::MPoint4D<Scalar>::MPoint4D (void)
  : MPoint<Scalar> (4)
{
}



// Description:
// Build an instance given two doubles
template<class Scalar>
CxxUtils::MPoint4D<Scalar>::MPoint4D (const Scalar & u, const Scalar & v,
					 const Scalar & w, const Scalar & x)
  : MPoint<Scalar> (4)
{
  this->m_coord[0] = u;
  this->m_coord[1] = v;
  this->m_coord[2] = w;
  this->m_coord[3] = x;
}


// Description:
// Upward copy constructor 
// This constructor is the base for inheriting the MPoint-functionality
template<class Scalar>
CxxUtils::MPoint4D<Scalar>::MPoint4D (const MTuple<Scalar> &p)
  : MPoint<Scalar> (p)
{
  assert (p.getDim () == 4);
}


// Description:
// Virtual destructor (just for completeness)
template<class Scalar> 
CxxUtils::MPoint4D<Scalar>::~MPoint4D (void)
{
}

template<class Scalar> CxxUtils::MPoint3D<Scalar>
CxxUtils::MPoint4D<Scalar>::projectTo3D (void) const
{
  MPoint3D<Scalar> res ((*this)[0] / (*this)[3],
                           (*this)[1] / (*this)[3], (*this)[2] / (*this)[3]);
  //std::cout << res << endl;
  return res;
}

#endif // MPOINT4D_CC
