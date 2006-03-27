#ifndef MPOINT2D_HPP
#define MPOINT2D_HPP

/** @addtogroup math */
// *********************************************************************
/*! @class MPoint2d
//
//  @short 2D point class
//
//  This class defines 2-dim points. Since it is derived from
//  MPoint, all public methods from this base class are avialable in
//  this class with the introduction of the constructor
//  MPoint2D (MPoint<..>). This constructor is absolutely neccessary.
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
#include "cxxutils/MPoint.hh"


// forward declarations

namespace CxxUtils 
{

  template<class Scalar> class MPoint2D:public MPoint<Scalar>
  {
  public:
    // -------------------------------------------------------------------
    // CONSTRUCTORS
    // -------------------------------------------------------------------
    /** Default constructor */
    MPoint2D (void);

    /** Constructor given two Scalar's */
    MPoint2D (const Scalar & u, const Scalar & v);

    /** Constructor from base class
	@param p general point as src for this 2D point
    */
    MPoint2D (const MTuple<Scalar> &p);

    /** Destructor */
    virtual ~ MPoint2D (void);
  };

  typedef MPoint2D<double>MP2D;
}

  // include INLINES if required
#include "cxxutils/MPoint2d.cc"
#ifndef OUTLINE
#include "cxxutils/MPoint2d.ih"
#endif

#endif // MPOINT2D_HPP
