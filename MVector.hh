/* -*-gnu-*- */
/*
 * CxxUtil C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated in the source file, this code is provided under 
 * the terms of the GNU LESSER PUBLIC LICENSE. The text of this license 
 * agreement accompanies this library's source distribution.
 */

#ifndef MVECTOR_H
#define MVECTOR_H

/* --------------------------------------------------------------------
 * 3D vector class definition
 *
 * $Date: 2006-03-27 13:40:22 $
 * $Revision: 1.6 $
 * -------------------------------------------------------------------- */

/**
 * @class MVector
 *
 * @short A vector.
 */

// INLINE declaration
#ifndef INLINE
#ifdef OUTLINE
#define INLINE
#else
#define INLINE inline
#endif
#endif

// class specific includes
#include "cxxutil/MTuple.hh"
// this is necessary for VC++ compatibility!
#include "cxxutil/MPoint.hh"

// system specific includes
#include <iostream>
#include <cmath>

namespace CxxUtil 
{
  // forward declaration
  template<class Scalar> class MPoint;

  template<class Scalar> class MVector:public AbstractTuple<Scalar>
  {
  public:
    // CONSTRUCTORS
    MVector (int dim = 1);
    MVector (const MVector<Scalar> &v);
    MVector (const AbstractTuple<Scalar> &v);
    MVector (const int dim, const Scalar s);

    // DESTRUCTORS
    virtual ~ MVector<Scalar> (void);

    // ASSIGNMENT OPERATORS
    // unary
    INLINE MVector<Scalar> &operator= (const MVector<Scalar> &v);
    INLINE MVector<Scalar> &operator+= (const MVector<Scalar> &v);
    INLINE MVector<Scalar> &operator-= (const MVector<Scalar> &v);
    INLINE MVector<Scalar> &operator*= (const Scalar s);
    INLINE MVector<Scalar> &operator/= (const Scalar s);

    // binary
    // NOTE: operators of type `Scalar operator vector` are not
    // implemented due to template constraints
    INLINE MVector<Scalar> operator+ (const MVector<Scalar> &v) const;
    INLINE MVector<Scalar> operator- (const MVector<Scalar> &v) const;
    INLINE MVector<Scalar> operator* (const Scalar s) const;
    INLINE MVector<Scalar> operator/ (const Scalar s) const;

    // COMPARISON OPERATORS
    //bool operator== (const MVector<Scalar> & v) const;
    //bool operator!= (const MVector<Scalar> & v) const;

    // Inner product
    Scalar operator| (const MVector<Scalar> &v) const;

    // NORM OPERATORS
    // compute vector norm
    INLINE Scalar getNorm (void) const;
    // return a normalized version of *this
    MVector<Scalar> getNormalized (void) const;
    // normalized this
    Scalar normalize (void);

    // CONVERSION
    MPoint<Scalar> toPoint (void) const;

    ////////////////////////////////////////////////////////////////////////
  protected:
    // multiplication
    MVector<Scalar> operator* (const MVector<Scalar> &v) const;
  };
}

  // include INLINES if required
#include "cxxutil/MVector.cc"
#ifndef OUTLINE
#include "cxxutil/MVector.ih"
#endif

#endif // MVECTOR_H
