/*
 * CxxUtil C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated, this software is provided under the terms of the
 * GNU LESSER PUBLIC LICENSE. The text of this license agreement accompanies
 * this library's source distribution.
 */

#ifndef MMATRIX_H
#define MMATRIX_H

/* --------------------------------------------------------------------
 * MMatrix class definition
 *
 * $Date: 2006-03-27 13:00:00 $
 * $Revision: 1.4 $
 * -------------------------------------------------------------------- */

/**
 * @class MMatrix
 *
 *  @short A generic NM matrix.
 *
 *  @ingroup math
 *  @author Andreas Kolb<ko@fh-wedel.de>, Martin Dietze<herbert@spamcop.net>
 *  @version 0.1
 */

// INLINE declaration
#ifndef INLINE
#ifdef OUTLINE
#define INLINE
#else
#define INLINE inline
#endif
#endif

#include "cxxutil/MVector.hh"

#include <iostream>

/** internal helper macro to automatically throw an exception if two 
 * matrices' dimensions do not match. */
#define MATRIX_DIMENSIONS(m1,m2,method) { \
    if (m1.m_rows != m2.m_rows || m1.m_cols != m2.m_cols) { \
        throw std::invalid_argument (method ": " MSG_ERROR_DIMENSIONS); } }

namespace CxxUtil 
{

  template<class Scalar> class MMatrix
  {
  public:
    /** constructor setting rows, cols and initializing all values
     * @param rows the number of rows
     * @param cols the number of cols
     * @param value the initial value */
    MMatrix (int rows, int cols, Scalar value = 0);

    /** copy constructor
     * @param matrix the source matrix */
    MMatrix (const MMatrix<Scalar> &matrix);

    /** destructor */
    ~MMatrix (void);

    /** returns the number of cols
     * @return the number of cols */
    INLINE int cols (void) const;

    /** returns the number of rows
     * @return the number of rows */
    INLINE int rows (void) const;

    /** initialize all matrix values 
     * @param value the value to initialize with */
    void fill (Scalar value);

    /** equality operator
     * @param matrix the other matrix
     * @return true if both matrices have the same dimensions and values */
    INLINE bool operator== (const MMatrix<Scalar> &matrix);

    /** non-equality operator
     * @param matrix the other matrix
     * @return true if both matrices have differing dimensions or values */
    INLINE bool operator!= (const MMatrix<Scalar> &matrix);

    /** member access, returning a reference to a matrix'es value a_ik
     * @param row the row
     * @param col the column
     * @return the value at position (row, column) */
    INLINE Scalar & operator () (int row, int col);

    /** assignment operator
     * @param m the other matrix
     * @return a reference to *this */
    INLINE MMatrix<Scalar> &operator= (const MMatrix<Scalar> &m);

    /** multiplication of a matrix with a vector
     * @exception invalid_argument if the dimensions do not match
     * @param MMatrix the matrix
     * @param MVector the vector
     * @return the result vector */
    friend MVector<Scalar> operator* (const MMatrix<Scalar> &MMatrix,
					 const MVector<Scalar> &MVector)
    {
      if (MMatrix.cols () != MVector.getDim ())
	{
	  throw std::invalid_argument ("operator*: " MSG_ERROR_DIMENSIONS);
	}
      CxxUtil::MVector<Scalar> result (MMatrix.m_rows, 0);
      for (int row = 0; row < result.getDim (); row++)
	{
	  for (int col = 0; col < MMatrix.m_cols; col++)
	    {
	      result[row] +=
		MMatrix.m_values->at (row * MMatrix.m_cols +
				      col) * MVector[col];
	    }
	}
      return CxxUtil::MVector<Scalar> (result);
    }

    /** multiplication of a matrix with a matrix
     * @exception invalid_argument if the dimensions do not match
     * @param m1 the first matrix
     * @param m2 the second matrix
     * @return the result matrix */
    friend MMatrix<Scalar> operator* (const MMatrix<Scalar> &m1,
					 const MMatrix<Scalar> &m2)
    {
      if (m1.cols () != m2.rows ())
	{
	  throw std::invalid_argument ("operator*: " MSG_ERROR_DIMENSIONS);
	}
      MMatrix<Scalar> result (m1.m_rows, m2.m_cols, 0);
      for (int row = 0; row < result.m_rows; row++)
	{
	  for (int col = 0; col < result.m_cols; col++)
	    {
	      for (int i = 0; i < m1.cols (); i++)
		{
		  result (row, col) += ((MMatrix<Scalar> &)m1) (row, i)
		    * ((MMatrix<Scalar> &)m2) (i, col);
		}
	    }
	}
      return MMatrix<Scalar> (result);
    }

    /** inner product between two matrices
     * @exception invalid_argument if the dimensions do not match
     * @param m1 the first matrix
     * @param m2 the other matrix
     * @return the scalar product */
    friend Scalar operator| (const MMatrix<Scalar> &m1,
			     const MMatrix<Scalar> &m2)
    {
      MATRIX_DIMENSIONS (m1, m2, "operator|");
      return (m1.m_values->mul (*m2.m_values)).getSum ();
    }

    /** matrix addition
     * @exception invalid_argument if the dimensions do not match
     * @param m1 the first matrix
     * @param m2 the other matrix
     * @return the addition result */
    friend MMatrix<Scalar> operator+ (const MMatrix<Scalar> &m1,
					 const MMatrix<Scalar> &m2)
    {
      MATRIX_DIMENSIONS (m1, m2, "operator+");
      MMatrix<Scalar> result (m1);
      *result.m_values += *m2.m_values;
      return result;
    }

    /** matrix subtraction
     * @exception invalid_argument if the dimensions do not match
     * @param m1 the first matrix
     * @param m2 the other matrix
     * @return the subtraction result */
    friend MMatrix<Scalar> operator- (const MMatrix<Scalar> &m1,
					 const MMatrix<Scalar> &m2)
    {
      MATRIX_DIMENSIONS (m1, m2, "operator-");
      MMatrix<Scalar> result (m1);
      *result.m_values -= *m2.m_values;
      return result;
    }

    /** multiplication by a scalar
     * @param matrix the matrix
     * @param val the scalar
     * @return the multiplication result */
    friend MMatrix<Scalar> operator* (const MMatrix<Scalar> &matrix,
					 const Scalar val)
    {
      MMatrix<Scalar> result (matrix);
      *result.m_values *= val;
      return result;
    }

    /** division by a scalar
     * @param matrix the matrix
     * @param val the scalar
     * @return the division result */
    friend MMatrix<Scalar> operator/ (const MMatrix<Scalar> &matrix,
					 const Scalar val)
    {
      MMatrix<Scalar> result (matrix);
      *result.m_values /= val;
      return result;
    }

  protected:
    /** an internal helper function to build an empty matrix with dimensions
     * m_cols * m_rows */
    void init (void);

    /** an internal helper function to release all memory */
    void destroy (void);

    /** an internal helper function to copy from another matrix */
    void copy (const MMatrix<Scalar> &matrix);

    /** update the `m_rowOffsets' array */
    void updateRowsArray (void);

    /** x dimensions */
    int m_cols;
    /** y dimensions */
    int m_rows;

    /** the matrix data (all rows serialized in one tuple) */
    MTuple<Scalar> *m_values;

    /** array holding all row offsets */
    int *m_rowOffsets;
  };

  /** output operator for std::ostream's */
  template<class Scalar> std::ostream &
  operator<< (std::ostream & os, MMatrix<Scalar> m);

}
  // include INLINES if required
#include "cxxutil/MMatrix.cc"
#ifndef OUTLINE
#include "cxxutil/MMatrix.ih"
#endif

#endif // MMATRIX_H
