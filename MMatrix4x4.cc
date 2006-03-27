#ifndef MMATRIX4X4_CPP
#define MMATRIX4X4_CPP

/* ********************************************************************
//  Class: MMatrix4x4
//  Implementation of class MMatrix4x4
//  -------------------------------------------------------------------
//  Project: Repairing and texturing of VR models
//  (C) Copyright Fachhochschule Wedel, Germany 2003
//  -------------------------------------------------------------------
//  $Revision: 1.2 $
//  $Date: 2006-03-27 09:02:55 $
// ******************************************************************** */

// class specific includes
#include "cxxutils/MMatrix4x4.hh"

// system specific includes

/* ====================== main class MMatrix4x4 ======================= */

template<class Scalar> 
CxxUtils::MMatrix4x4<Scalar>::MMatrix4x4 (Scalar value)
  :MMatrix<Scalar> (4, 4, value)
{
}

template<class Scalar> 
CxxUtils::MMatrix4x4<Scalar>::MMatrix4x4 (const MMatrix4x4<Scalar> &matrix)
  : MMatrix<Scalar> (matrix)
{
}

template<class Scalar> 
CxxUtils::MMatrix4x4<Scalar>::~MMatrix4x4 (void)
{
}

#endif // MMATRIX4X4_CPP
