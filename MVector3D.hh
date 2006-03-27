/* -*-gnu-*- */
/*
 * CxxUtil C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated in the source file, this code is provided under 
 * the terms of the GNU LESSER PUBLIC LICENSE. The text of this license 
 * agreement accompanies this library's source distribution.
 */

#ifndef MVECTOR3D_H
#define MVECTOR3D_H

/* --------------------------------------------------------------------
 * 3D vector class definition
 *
 * $Date: 2006-03-27 13:00:00 $
 * $Revision: 1.3 $
 * -------------------------------------------------------------------- */

/**
 * @class MVector3D
 *
 * @short 3D vector class
 *
 * This class defines 3-dim vectors. Since it is derived from
 * MVector, all public methods from this base class are avialable in
 * this class with the introduction of the constructor
 * MVector3D (MVector<..>). This constructor is absolutely neccessary.
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
#include "cxxutil/cdefines.h"
#include "cxxutil/MVector.hh"


// forward declarations

namespace CxxUtil 
{

  template<class Scalar> class MVector3D:public MVector<Scalar>
  {
  public:
    // -------------------------------------------------------------------
    // CONSTRUCTORS
    // -------------------------------------------------------------------
    /** Default constructor */
    MVector3D (void);

    /** Constructor given two Scalar's */
    MVector3D (const Scalar & u, const Scalar & v, const Scalar & w);

    /** Constructor from base class
	@param p general vector as src for this 3D vector
    */
    MVector3D (const MTuple<Scalar> &p);

    /** Destructor */
    virtual ~ MVector3D (void);

    // -------------------------------------------------------------------
    // GEOMETRIC OPERATIONS
    // -------------------------------------------------------------------

    /** Computation of the cross product
	@param v vector to build the cross-product with
    */
    MVector3D<Scalar> operator^ (const MVector3D & v) const;
  };

  typedef MVector3D<double>MV3D;
}

  // include INLINES if required
#include "cxxutil/MVector3D.cc"
#ifndef OUTLINE
#include "cxxutil/MVector3D.ih"
#endif

#endif // MVECTOR3D_H
