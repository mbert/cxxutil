#ifndef MVECTOR4D_HPP
#define MVECTOR4D_HPP

/** @addtogroup math */
// *********************************************************************
/*! @class MVector4d
//
//  @short 4D vector class
//
//  This class defines 4-dim vectors. Since it is derived from
//  MVector, all public methods from this base class are avialable in
//  this class with the introduction of the constructor
//  MVector4D (MVector<..>). This constructor is absolutely neccessary.
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

  template<class Scalar> class MVector4D:public MVector<Scalar>
  {
  public:
    // -------------------------------------------------------------------
    // CONSTRUCTORS
    // -------------------------------------------------------------------
    /** Default constructor */
    MVector4D (void);

    /** Constructor given two Scalar's */
    MVector4D (const Scalar & u, const Scalar & v,
	       const Scalar & w, const Scalar & x);

    /** Constructor from base class
	@param p general vector as src for this 4D vector
    */
    MVector4D (const MTuple<Scalar> &p);

    /** Destructor */
    virtual ~ MVector4D (void);

    // -------------------------------------------------------------------
    // GEOMETRIC OPERATIONS
    // -------------------------------------------------------------------


  };

  typedef MVector4D<double>MV4D;
}

  // include INLINES if required
#include "cxxutils/MVector4d.cc"
#ifndef OUTLINE
#include "cxxutils/MVector4d.ih"
#endif

#endif // MVECTOR4D_HPP
