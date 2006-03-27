#ifndef MMATRIX4X4_H
#define MMATRIX4X4_H

/** @addtogroup math */
// *********************************************************************
/*! @class MMatrix4x4
//
//  @short A 4x4 matrix. This specialized version is only necessary to 
//  provide support for the 4x4 array structure needed by RxHelper.
//
//  @ingroup math
//  @author Andreas Kolb<ko@fh-wedel.de>, Martin Dietze<herbert@spamcop.net>
//  @version 0.1
*/
/*  --------------------------------------------------------------------
//  Project: Repairing and texturing of VR models
//  (C) Copyright Fachhochschule Wedel, Germany 2003
//  --------------------------------------------------------------------
//  $Revision: 1.2 $
//  $Date: 2006-03-27 09:02:55 $
// ********************************************************************** */

// INLINE declaration
#ifndef INLINE
#ifdef OUTLINE
#define INLINE
#else
#define INLINE inline
#endif
#endif

#include "cxxutils/MMatrix.hh"

namespace CxxUtils 
{

  template<class Scalar> class MMatrix4x4:public MMatrix<Scalar>
  {
  public:
    /** default constutor that initializes all elements
     * @param value the initial value for all elements */
    MMatrix4x4 (Scalar value = 0);
    /** copy constructor
     * @param matrix the source matrix */
    MMatrix4x4 (const MMatrix4x4<Scalar> &matrix);
    /** destructor */
    ~MMatrix4x4 (void);
    /** read the matrix contents from a 4x4-array
     *  @param a an array containing data as a[col][row] */
    INLINE void fromA (Scalar (&a)[4][4]);
  };

  /** this is needed by RxHelper in Redux */
  typedef MMatrix4x4<float>MFloatMatrix4x4;
}

  // include INLINES if required
#include "cxxutils/MMatrix4x4.cc"
#ifndef OUTLINE
#include "cxxutils/MMatrix4x4.ih"
#endif


#endif // MMATRIX4X4_H
