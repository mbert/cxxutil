#ifndef MPOINT_HPP
#define MPOINT_HPP

/** @addtogroup math */
// *********************************************************************
/*! @class MPoint
//
//  @short A point.
//
//  @ingroup math
//  @author  Andreas Kolb<ko@fh-wedel.de>, Martin Dietze<herbert@spamcop.net>
//  @version 0.1
*/
/*  --------------------------------------------------------------------
//  Project: Repairing and texturing of VR models
//  (C) Copyright Fachhochschule Wedel, Germany 2003
//  --------------------------------------------------------------------
//  $Revision: 1.2 $
//  $Date: 2006-03-27 09:02:55 $
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
#include "cxxutils/MTuple.hh"
#include "cxxutils/mmessages.h"
// this is necessary for VC++ compatibility!
#include "cxxutils/MVector.hh"

// system specific includes
#include <iostream>
#include <stdexcept>
#include <math.h>

namespace CxxUtils 
{
  // forward declaration
  template<class Scalar> class MVector;

  template<class Scalar> class MPoint:public AbstractTuple<Scalar>
  {
  public:
    // CONSTRUCTORS
    MPoint (int dim = 1);
    MPoint (const MPoint<Scalar> &v);
    MPoint (const AbstractTuple<Scalar> &v);
    MPoint (const int dim, const Scalar s);

    // DESTRUCTORS
    virtual ~ MPoint<Scalar> (void);

    // Assigns all components to s
    virtual MPoint<Scalar> &operator= (const Scalar s);

    // Assignment from a different point
    MPoint<Scalar> &operator= (const MPoint<Scalar> &v);

    // Assignment to the same point plus point t
    virtual MPoint<Scalar> &operator+= (const MVector<Scalar> &t);

    // Assignment to the same point minus point t
    virtual MPoint<Scalar> &operator-= (const MVector<Scalar> &t);

    // Assignment to the same point plus point consisting of Scalars s
    virtual MPoint<Scalar> &operator+= (const Scalar s);

    // Assignment to the same point minus point consisting of Scalars s
    virtual MPoint<Scalar> &operator-= (const Scalar s);

    // Returns the sum of *this and point t
    virtual MPoint<Scalar> operator+ (const MVector<Scalar> &t) const;

    // Returns the difference of *this and point t
    virtual MPoint<Scalar> operator- (const MVector<Scalar> &t) const;

    // Returns the difference of *this and point t
    virtual MVector<Scalar> operator- (const MPoint<Scalar> &t) const;

    // distance computaion
    Scalar dist (const MPoint<Scalar> &q) const;

    // CONVERSION
    MVector<Scalar> toVector (void) const;

    ////////////////////////////////////////////////////////////////////////
    // Friend functions 
    ////////////////////////////////////////////////////////////////////////

    /** affine combiantion
     */
    friend MPoint<Scalar> affineComb2 (Scalar a, const MPoint<Scalar> &p1,
					  const MPoint<Scalar> &p2)
    {
      //cout << p1 << "*(1-" << a << ") " << p1*(1-a) << endl;
      //cout << p2 << "*" << a << " " << p2*a << endl; 
      return MPoint<Scalar> (p1 * (1 - a) + p2 * a);
    }

    /** affine combiantion
     */
    friend MPoint<Scalar>
    affineComb3 (Scalar a1, const MPoint<Scalar> &p1,
                 Scalar a2, const MPoint<Scalar> &p2,
                 Scalar a3, const MPoint<Scalar> &p3)
    {
      //MPoint<Scalar> res;
      if (fabs (1 - a1 - a2 - a3) > p1.getEpsilon ())
	{
	  throw std::invalid_argument ("affineComb3: " MSG_ERROR_WEIGHTS_TO_ONE);
	}
      return MPoint<Scalar> (p1 * a1 + p2 * a2 + p3 * a3);
    }

  protected:

    // multiplication
    MPoint<Scalar> operator* (const MPoint<Scalar> &v) const;
    MPoint<Scalar> operator* (const Scalar s) const;
  };
}

  // include INLINES if required
#include "cxxutils/MPoint.cc"
#ifndef OUTLINE
#include "cxxutils/MPoint.ih"
#endif


#endif // MPOINT_HPP
