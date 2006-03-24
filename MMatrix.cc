#ifndef MMATRIX_CPP
#define MMATRIX_CPP

/* ********************************************************************
//  Class: MMatrix
//  Implementation of class MMatrix
//  -------------------------------------------------------------------
//  Project: Repairing and texturing of VR models
//  (C) Copyright Fachhochschule Wedel, Germany 2003
//  -------------------------------------------------------------------
//  $Revision: 1.1 $
//  $Date: 2006-03-24 15:36:45 $
// ******************************************************************** */

// class specific includes
#include "MMatrix.hh"

// system specific includes
#include <iostream>
#include <stdarg.h>
#include <assert.h>

/* ========================= main class MMatrix ======================= */

template < class Scalar >
HmdUtils::MMatrix < Scalar >::MMatrix (int rows, int cols, Scalar value)
{
  m_rows = rows;
  m_cols = cols;
  init ();
  updateRowsArray ();
  fill (value);
}

template < class Scalar >
HmdUtils::MMatrix < Scalar >::MMatrix (const MMatrix < Scalar > &matrix)
{
  copy (matrix);
}

template < class Scalar > void
HmdUtils::MMatrix < Scalar >::copy (const MMatrix < Scalar > &matrix)
{
  m_rows = matrix.m_rows;
  m_cols = matrix.m_cols;
  m_values = NEW (MTuple < Scalar > (*matrix.m_values));
  m_rowOffsets = NULL;
  updateRowsArray ();
}

template < class Scalar > 
HmdUtils::MMatrix < Scalar >::~MMatrix (void)
{
  destroy ();
}

template < class Scalar > void
HmdUtils::MMatrix < Scalar >::init (void)
{
  m_values = NEW (MTuple < Scalar > (m_rows * m_cols));
  m_rowOffsets = NULL;
}

template < class Scalar > void
HmdUtils::MMatrix < Scalar >::fill (Scalar value)
{
  for (int i = m_rows * m_cols - 1; i > -1; i--)
    {
      m_values->at (i) = value;
      assert (m_values->at (i) == value);
    }
}

template < class Scalar > void 
HmdUtils::MMatrix < Scalar >::updateRowsArray (void)
{
  DELETENOTNULL (m_rowOffsets);
  m_rowOffsets = NEW (int [m_rows]);
  for (int i = 0; i < m_rows; i++)
    {
      m_rowOffsets[i] = m_cols * i;
    }
}

template < class Scalar > void
HmdUtils::MMatrix < Scalar >::destroy (void)
{
  DELETE (m_values);
  DELETE (m_rowOffsets);
}

template < class Scalar > std::ostream &
HmdUtils::operator<< (std::ostream & os, MMatrix < Scalar > m)
{
  os << "( ";
  for (int row = 0; row < m.rows (); row++)
    {
      for (int col = 0; col < m.cols (); col++)
        {
          if (col == 0)
            {
              os << "(";
            }
          if (col != 0)
            {
              os << ", ";
            }
          os << m (row, col);
          if (col == m.cols () - 1)
            {
              os << ")";
            }
        }
      if (row != m.rows () - 1)
        {
          os << ", ";
        }
    }
  os << " )";
  return os;
}

// include "outlined" INLINE functions
#ifdef OUTLINE
#include "MMatrix.ih"
#endif

#endif // MMATRIX_CPP
