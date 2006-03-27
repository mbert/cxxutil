/* -*-gnu-*- */
/*
 * CxxUtils C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated in the source file, this code is provided under 
 * the terms of the GNU LESSER PUBLIC LICENSE. The text of this license 
 * agreement accompanies this library's source distribution.
 *
 * This source file is based on code published in C/C++ Users' Journal, issue
 * 10/2001. The exact license terms are unknown, BSD-like license is assumed.
 */

#ifndef MPOINT2D_H
#define MPOINT2D_H

/* --------------------------------------------------------------------
 * 2D Point class definition
 *
 * $Date: 2006-03-27 11:08:15 $
 * $Revision: 1.1 $
 * -------------------------------------------------------------------- */

/**
 * @class MPoint2d
 *
 * @short 2D point class
 *
 * This class defines 2-dim points. Since it is derived from
 * MPoint, all public methods from this base class are avialable in
 * this class with the introduction of the constructor
 * MPoint2D (MPoint<..>). This constructor is absolutely neccessary.
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
#include "cxxutils/MPoint2D.cc"
#ifndef OUTLINE
#include "cxxutils/MPoint2D.ih"
#endif

#endif // MPOINT2D_H
