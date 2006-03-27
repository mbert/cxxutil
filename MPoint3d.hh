#ifndef MPOINT3D_HPP
#define MPOINT3D_HPP

/** @addtogroup math */
// *********************************************************************
/*! @class MPoint3d
//
//  @short 3D point class
//
//  This class defines 3-dim points. Since it is derived from
//  MPoint, all public methods from this base class are avialable in
//  this class with the introduction of the constructor
//  MPoint3D (MPoint<..>). This constructor is absolutely neccessary.
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

  template<class Scalar> class MPoint3D:public MPoint<Scalar>
  {
  public:
    // -------------------------------------------------------------------
    // CONSTRUCTORS
    // -------------------------------------------------------------------
    /** Default constructor */
    MPoint3D (void);

    /** Constructor given two Scalar's */
    MPoint3D (const Scalar & u, const Scalar & v, const Scalar & w);

    /** Constructor from base class
	@param p general point as src for this 3D point
    */
    MPoint3D (const MTuple<Scalar> &p);

    /** Destructor */
    virtual ~ MPoint3D (void);
  };

  typedef MPoint3D<double>MP3D;
}

  // include INLINES if required
#include "cxxutils/MPoint3d.cc"
#ifndef OUTLINE
#include "cxxutils/MPoint3d.ih"
#endif

#endif // MPOINT3D_HPP
