/* -*-gnu-*- */
/*
 * CxxUtil C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated in the source file, this code is provided under 
 * the terms of the GNU LESSER PUBLIC LICENSE. The text of this license 
 * agreement accompanies this library's source distribution.
 */

#ifndef MVECTOR4D_H
#define MVECTOR4D_H

/* --------------------------------------------------------------------
 * 4D vector class definition
 *
 * $Date: 2006-03-27 13:00:00 $
 * $Revision: 1.3 $
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
#include "cxxutil/cdefines.h"
#include "cxxutil/MVector.hh"


// forward declarations

namespace CxxUtil 
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
#include "cxxutil/MVector4D.cc"
#ifndef OUTLINE
#include "cxxutil/MVector4D.ih"
#endif

#endif // MVECTOR4D_H
