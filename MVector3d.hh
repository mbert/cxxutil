#ifndef MVECTOR3D_HPP
#define MVECTOR3D_HPP

/** @addtogroup math */
// *********************************************************************
/*! @class MVector3d
//
//  @short 3D vector class
//
//  This class defines 3-dim vectors. Since it is derived from
//  MVector, all public methods from this base class are avialable in
//  this class with the introduction of the constructor
//  MVector3D (MVector<..>). This constructor is absolutely neccessary.
//
//  @ingroup math
//  @author  Andreas Kolb <akolb@fh-wedel.de>, Martin Dietze <di@fh-wedel.de>
//  @version 0.1
*/
/*  --------------------------------------------------------------------
//  Project: Repairing and texturing of VR models
//  (C) Copyright Fachhochschule Wedel, Germany 2002
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
#include "cdefines.h"
#include "MVector.hh"


// forward declarations

namespace HmdUtils 
{

  template < class Scalar > class MVector3D:public MVector < Scalar >
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
    MVector3D (const MTuple < Scalar > &p);

    /** Destructor */
    virtual ~ MVector3D (void);

    // -------------------------------------------------------------------
    // GEOMETRIC OPERATIONS
    // -------------------------------------------------------------------

    /** Computation of the cross product
	@param v vector to build the cross-product with
    */
    MVector3D < Scalar > operator^ (const MVector3D & v) const;
  };

  typedef MVector3D < double >MV3D;

  // include INLINES if required
#include "MVector3d.cc"
#ifndef OUTLINE
#include "MVector3d.ih"
#endif
}

#endif // MVECTOR3D_HPP
