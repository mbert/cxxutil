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

#ifndef MVECTOR4D_H
#define MVECTOR4D_H

/* --------------------------------------------------------------------
 * 4D vector class definition
 *
 * $Date: 2006-03-27 11:08:15 $
 * $Revision: 1.1 $
 * -------------------------------------------------------------------- */

/**
 * @class MVector4D
 *
 * @short 4D vector class
 *
 * This class defines 4-dim vectors. Since it is derived from
 * MVector, all public methods from this base class are avialable in
 * this class with the introduction of the constructor
 * MVector4D (MVector<..>). This constructor is absolutely neccessary.
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
#include "cxxutils/MVector4D.cc"
#ifndef OUTLINE
#include "cxxutils/MVector4D.ih"
#endif

#endif // MVECTOR4D_H
