#ifndef MVECTOR2D_HPP
#define MVECTOR2D_HPP

/** @addtogroup math */
// *********************************************************************
/*! @class MVector2d
//
//  @short 2D vector class
//
//  This class defines 2-dim vectors. Since it is derived from
//  MVector, all public methods from this base class are avialable in
//  this class with the introduction of the constructor
//  MVector2D (MVector<..>). This constructor is absolutely neccessary.
//
//  @ingroup math
//  @author  Andreas Kolb<akolb@fh-wedel.de>, Martin Dietze<di@fh-wedel.de>
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
#include "cxxutils/cdefines.h"
#include "cxxutils/MVector.hh"


// forward declarations

namespace CxxUtils 
{

  template<class Scalar> class MVector2D:public MVector<Scalar>
  {
  public:
    // -------------------------------------------------------------------
    // CONSTRUCTORS
    // -------------------------------------------------------------------
    /** Default constructor */
    MVector2D (void);

    /** Constructor given two Scalar's */
    MVector2D (const Scalar & u, const Scalar & v);

    /** Constructor from base class
	@param p general vector as src for this 2D vector
    */
    MVector2D (const MTuple<Scalar> &p);

    /** Destructor */
    virtual ~ MVector2D (void);

    // -------------------------------------------------------------------
    // GEOMETRIC OPERATIONS
    // -------------------------------------------------------------------

    /** Computation of the vector normal to this
	The normal is computed such that {this, normal} build a right hand CS
    */
    MVector2D<Scalar> getOrthogonal (void) const;

  };

  typedef MVector2D<double>MV2D;
}

  // include INLINES if required
#include "cxxutils/MVector2d.cc"
#ifndef OUTLINE
#include "cxxutils/MVector2d.ih"
#endif

#endif // MVECTOR2D_HPP
