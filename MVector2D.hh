/* -*-gnu-*- */
/*
 * CxxUtil C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated in the source file, this code is provided under 
 * the terms of the GNU LESSER PUBLIC LICENSE. The text of this license 
 * agreement accompanies this library's source distribution.
 */

#ifndef MVECTOR2D_H
#define MVECTOR2D_H

/* --------------------------------------------------------------------
 * 3D vector class definition
 *
 * $Date: 2006-03-27 13:00:00 $
 * $Revision: 1.3 $
 * -------------------------------------------------------------------- */

/**
 * @class MVector2D
 *
 * @short 2D vector class
 *
 * This class defines 2-dim vectors. Since it is derived from
 * MVector, all public methods from this base class are avialable in
 * this class with the introduction of the constructor
 * MVector2D (MVector<..>). This constructor is absolutely neccessary.
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
#include "cxxutil/MVector2D.cc"
#ifndef OUTLINE
#include "cxxutil/MVector2D.ih"
#endif

#endif // MVECTOR2D_H
