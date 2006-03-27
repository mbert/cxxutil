/* -*-gnu-*- */
/*
 * CxxUtil C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated in the source file, this code is provided under 
 * the terms of the GNU LESSER PUBLIC LICENSE. The text of this license 
 * agreement accompanies this library's source distribution.
 */

#ifndef MPOINT3D_H
#define MPOINT3D_H

/* --------------------------------------------------------------------
 * 3D point class definition
 *
 * $Date: 2006-03-27 13:00:00 $
 * $Revision: 1.3 $
 * -------------------------------------------------------------------- */

/**
 * @class MPoint3D
 *
 * @short 3D point class
 *
 * This class defines 3-dim points. Since it is derived from
 * MPoint, all public methods from this base class are avialable in
 * this class with the introduction of the constructor
 * MPoint3D (MPoint<..>). This constructor is absolutely neccessary.
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
#include "cxxutil/MPoint.hh"


// forward declarations

namespace CxxUtil 
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
#include "cxxutil/MPoint3D.cc"
#ifndef OUTLINE
#include "cxxutil/MPoint3D.ih"
#endif

#endif // MPOINT3D_H
