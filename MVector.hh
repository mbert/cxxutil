#ifndef MVECTOR_HPP
#define MVECTOR_HPP

/** @addtogroup math */
// *********************************************************************
/*! @class MVector
//
//  @short A vector.
//
//  @ingroup math
//  @author  Andreas Kolb <ko@fh-wedel.de>, Martin Dietze <herbert@spamcop.net>
//  @version 0.1
*/
/*  --------------------------------------------------------------------
//  Project: Repairing and texturing of VR models
//  (C) Copyright Fachhochschule Wedel, Germany 2003
//  --------------------------------------------------------------------
//  $Revision: 1.1 $
//  $Date: 2006-03-24 15:36:45 $
// ********************************************************************** */

// INLINE declaration
#ifndef INLINE
#ifdef OUTLINE
#define INLINE
#else
#define INLINE inline
#endif
#endif

// class specific includes
#include "MTuple.hh"
// this is necessary for VC++ compatibility!
#include "MPoint.hh"

// system specific includes
#include <iostream>
#include <math.h>

namespace HmdUtils 
{
  // forward declaration
  template < class Scalar > class MPoint;

  template < class Scalar > class MVector:public AbstractTuple < Scalar >
  {
  public:
    // CONSTRUCTORS
    MVector (int dim = 1);
    MVector (const MVector < Scalar > &v);
    MVector (const AbstractTuple < Scalar > &v);
    MVector (const int dim, const Scalar s);

    // DESTRUCTORS
    virtual ~ MVector < Scalar > (void);

    // ASSIGNMENT OPERATORS
    // unary
    INLINE MVector < Scalar > &operator= (const MVector < Scalar > &v);
    INLINE MVector < Scalar > &operator+= (const MVector < Scalar > &v);
    INLINE MVector < Scalar > &operator-= (const MVector < Scalar > &v);
    INLINE MVector < Scalar > &operator*= (const Scalar s);
    INLINE MVector < Scalar > &operator/= (const Scalar s);

    // binary
    // NOTE: operators of type `Scalar operator vector` are not
    // implemented due to template constraints
    INLINE MVector < Scalar > operator+ (const MVector < Scalar > &v) const;
    INLINE MVector < Scalar > operator- (const MVector < Scalar > &v) const;
    INLINE MVector < Scalar > operator* (const Scalar s) const;
    INLINE MVector < Scalar > operator/ (const Scalar s) const;

    // COMPARISON OPERATORS
    //bool operator== (const MVector < Scalar > & v) const;
    //bool operator!= (const MVector < Scalar > & v) const;

    // Inner product
    Scalar operator| (const MVector < Scalar > &v) const;

    // NORM OPERATORS
    // compute vector norm
    INLINE Scalar getNorm (void) const;
    // return a normalized version of *this
    MVector < Scalar > getNormalized (void) const;
    // normalized this
    Scalar normalize (void);

    // CONVERSION
    MPoint < Scalar > toPoint (void) const;

    ////////////////////////////////////////////////////////////////////////
  protected:
    // multiplication
    MVector < Scalar > operator* (const MVector < Scalar > &v) const;
  };

  // include INLINES if required
#include "MVector.cc"
#ifndef OUTLINE
#include "MVector.ih"
#endif
}

#endif // MVECTOR_HPP
