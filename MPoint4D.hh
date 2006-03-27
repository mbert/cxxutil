/* -*-gnu-*- */
/*
 * CxxUtils C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated in the source file, this code is provided under 
 * the terms of the GNU LESSER PUBLIC LICENSE. The text of this license 
 * agreement accompanies this library's source distribution.
 */

#ifndef MPOINT4D_H
#define MPOINT4D_H

/* --------------------------------------------------------------------
 * 4D point class definition
 *
 * $Date: 2006-03-27 12:32:44 $
 * $Revision: 1.2 $
 * -------------------------------------------------------------------- */

/**
 * @class MPoint4D
 *
 * @short 4D point class
 *
 * This class defines 4-dim points. Since it is derived from
 * MPoint, all public methods from this base class are avialable in
 * this class with the introduction of the constructor
 * MPoint4D (MPoint<..>). This constructor is absolutely neccessary.
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
#include "cxxutils/MPoint3D.hh"


// forward declarations

namespace CxxUtils 
{

  template<class Scalar> class MPoint4D:public MPoint<Scalar>
  {
  public:
    // -------------------------------------------------------------------
    // CONSTRUCTORS
    // -------------------------------------------------------------------
    /** Default constructor */
    MPoint4D (void);

    /** Constructor given two Scalar's */
    MPoint4D (const Scalar & u, const Scalar & v,
	      const Scalar & w, const Scalar & x);

    /** Constructor from base class
	@param p general point as src for this 4D point
    */
    MPoint4D (const MTuple<Scalar> &p);

    /** Destructor */
    virtual ~ MPoint4D (void);

    /** Project this point into 3D space */
    MPoint3D<Scalar> projectTo3D (void) const;
  };

  typedef MPoint4D<double>MP4D;
}

  // include INLINES if required
#include "cxxutils/MPoint4D.cc"
#ifndef OUTLINE
#include "cxxutils/MPoint4D.ih"
#endif

#endif // MPOINT4D_H
