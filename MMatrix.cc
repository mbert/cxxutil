/* -*-gnu-*- */
/*
 * CxxUtil C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated, this software is provided under the terms of the
 * GNU LESSER PUBLIC LICENSE. The text of this license agreement accompanies
 * this library's source distribution.
 */

#ifndef MMATRIX_CC
#define MMATRIX_CC

/* --------------------------------------------------------------------
 * Generic matrix class implementation
 *
 * $Date: 2008-04-16 15:41:21 $
 * $Revision: 1.6 $
 * -------------------------------------------------------------------- */

// class specific includes
#include "cxxutil/MMatrix.hh"

// system specific includes
#include <iostream>
#include <cstdarg>
#include <cassert>

/* ========================= main class MMatrix ======================= */

template<class Scalar>
CxxUtil::MMatrix<Scalar>::MMatrix (int rows, int cols, Scalar value)
{
  m_rows = rows;
  m_cols = cols;
  init ();
  updateRowsArray ();
  fill (value);
}

template<class Scalar>
CxxUtil::MMatrix<Scalar>::MMatrix (const MMatrix<Scalar> &matrix)
{
  copy (matrix);
}

template<class Scalar> void
CxxUtil::MMatrix<Scalar>::copy (const MMatrix<Scalar> &matrix)
{
  m_rows = matrix.m_rows;
  m_cols = matrix.m_cols;
  m_values = NEW (MTuple<Scalar> (*matrix.m_values));
  m_rowOffsets = NULL;
  updateRowsArray ();
}

template<class Scalar> 
CxxUtil::MMatrix<Scalar>::~MMatrix (void)
{
  destroy ();
}

template<class Scalar> void
CxxUtil::MMatrix<Scalar>::init (void)
{
  m_values = NEW (MTuple<Scalar> (m_rows * m_cols));
  m_rowOffsets = NULL;
}

template<class Scalar> void
CxxUtil::MMatrix<Scalar>::fill (Scalar value)
{
  for (int i = m_rows * m_cols - 1; i > -1; i--)
    {
      m_values->at (i) = value;
      assert (m_values->at (i) == value);
    }
}

template<class Scalar> void 
CxxUtil::MMatrix<Scalar>::updateRowsArray (void)
{
  DELETENOTNULL (m_rowOffsets);
  m_rowOffsets = NEW (int [m_rows]);
  for (int i = 0; i < m_rows; i++)
    {
      m_rowOffsets[i] = m_cols * i;
    }
}

template<class Scalar> void
CxxUtil::MMatrix<Scalar>::destroy (void)
{
  DELETE (m_values);
  DELETEAR (m_rowOffsets);
}

template<class Scalar> std::ostream &
CxxUtil::operator<< (std::ostream & os, MMatrix<Scalar> m)
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
#include "cxxutil/MMatrix.ih"
#endif

#endif // MMATRIX_CC
