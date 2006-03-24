#ifndef MTUPLE_HPP
#define MTUPLE_HPP
/** @addtogroup math */
// *********************************************************************
/*! @class MTuple
//
//  @short An n-tuple.
//
//  This is an template class for the basic tuple classes. It is 
//  used for the construction of vector-classes, point-classes etc. The
//  fundamental funtionality for tuple-calculations is offered by this
//  template class, so classes build upon this class can use them
//  quite simply.
//
//  Though not abstract, this class should not be used directly but rather
//  be subclassed, see MVector and MPoint.
//
//  @ingroup math
//  @author  Andreas Kolb <ko@fh-wedel.de>, Martin Dietze <herbert@spamcop.net>
//  @version 0.1
*/
/*  --------------------------------------------------------------------
//  Project: Repairing and texturing of VR models
//  (C) Copyright Fachhochschule Wedel, Germany 2003
//  --------------------------------------------------------------------
//  $Revision: 1.1 $
//  $Date: 2006-03-24 15:36:45 $
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
#include "cdebug.hh"
#include "cdefines.h"
#include "mutil.h"

// system specific includes
#include <iostream>
#include <math.h>

namespace HmdUtils 
{
  template < class Scalar > class AbstractTuple
  {
  public:

    // -------------------------------------------------------------------
    // CONSTRUCTORS
    // -------------------------------------------------------------------
    AbstractTuple < Scalar > (int dim);
    AbstractTuple < Scalar > (const AbstractTuple < Scalar > &t);
    AbstractTuple < Scalar > (const int dim, const Scalar s);

    // DESTRUCTORS
    virtual ~AbstractTuple < Scalar > (void);

    ////////////////////////////////////////////////////////////////////////
    // COMPARISON
    ////////////////////////////////////////////////////////////////////////
    bool operator== (const AbstractTuple < Scalar > &t) const;

    bool operator!= (const AbstractTuple < Scalar > &t) const;

    ////////////////////////////////////////////////////////////////////////
    // COORD ACCESS
    ////////////////////////////////////////////////////////////////////////

    // Returns the reference to the i-th components of the tuple
    // Note: Here the content can be changed
    Scalar & operator[](int i);

    // Returns the reference to the i-th components of the tuple
    // Note: Here the content can not be changed
    const Scalar & operator[] (int i) const;

    ////////////////////////////////////////////////////////////////////////
    // Friend functions 
    ////////////////////////////////////////////////////////////////////////

    // Returns the negative tuple
    friend AbstractTuple < Scalar > operator- (const AbstractTuple < Scalar > &t)
    {
      AbstractTuple < Scalar > ret (t);
      ret.multMeBy (-1);
      return ret;
    }

    // Returns the componentwise product of Scalar s and *this
    friend AbstractTuple < Scalar > operator* (const Scalar s, 
					       AbstractTuple < Scalar > &p)
    {
      AbstractTuple < Scalar > ret (p.m_dim);
      for (int i = 0; i < p.m_dim; i++)
	{
	  ret.m_coord[i] = p.m_coord[i] * s;
	}

      return ret;
    }

    ////////////////////////////////////////////////////////////////////////
    // Epsilon handling
    ////////////////////////////////////////////////////////////////////////
    void setEpsilon (Scalar s);

    Scalar getEpsilon () const;

    ////////////////////////////////////////////////////////////////////////
    // Getting the dimension
    ////////////////////////////////////////////////////////////////////////
    int getDim (void) const;

    ////////////////////////////////////////////////////////////////////////
    // Getting the sum
    ////////////////////////////////////////////////////////////////////////
    Scalar getSum (void) const;

    ////////////////////////////////////////////////////////////////////////
    // Compute norm & sum
    ////////////////////////////////////////////////////////////////////////
    Scalar getNormQuad (void) const;

  protected:

    // Constructor from two tuples
    AbstractTuple < Scalar > (const AbstractTuple < Scalar > &t1, char op, 
			      const AbstractTuple < Scalar > &t2);

    // Constructor from a tuple and a scalar
    AbstractTuple < Scalar > (const AbstractTuple < Scalar > &t1, char op, 
			      Scalar s);

    ////////////////////////////////////////////////////////////////////////
    // UNARY ASSIGNMENT OPERATOR
    ////////////////////////////////////////////////////////////////////////

    // Assignment to another tuple
    AbstractTuple < Scalar > &assignTo (const AbstractTuple < Scalar > &t);

    // Assigns all components to s
    AbstractTuple < Scalar > &assignTo (const Scalar s);

    // Assignment to the same tuple plus tuple t
    AbstractTuple < Scalar > &addToMe (const AbstractTuple < Scalar > &t);

    // Assignment to the same tuple multiplied by a Scalar s componentwise
    AbstractTuple < Scalar > &addToMe (const Scalar s);

    // Assignment to the same tuple minus tuple t
    AbstractTuple < Scalar > &subFromMe (const AbstractTuple < Scalar > &t);

    // Assignment to the same tuple divided by Scalar s
    // NOTE: s MUST be != zero!!
    AbstractTuple < Scalar > &subFromMe (const Scalar s);

    // Assignment to the same tuple multiplied by a Scalar s componentwise
    AbstractTuple < Scalar > &multMeBy (const AbstractTuple < Scalar > &t);

    // Assignment to the same tuple multiplied by a Scalar s componentwise
    AbstractTuple < Scalar > &multMeBy (const Scalar s);

    // Assignment to the same tuple divided by tuple t componentwise
    // NOTE: The components of t MUST be != zero!!
    AbstractTuple < Scalar > &divMeBy (const AbstractTuple < Scalar > &t);

    // Assignment to the same tuple divided by Scalar s
    // NOTE: s MUST be != zero!!
    AbstractTuple < Scalar > &divMeBy (const Scalar s);

    ////////////////////////////////////////////////////////////////////////
    // BINARY ASSIGNMENT OPERATORS
    // NOTE: operators of type `Scalar operator Tuple` are not
    // implemented due to template constraints
    ////////////////////////////////////////////////////////////////////////

    // Returns the sum of *this and tuple t
    INLINE AbstractTuple < Scalar > 
    add (const AbstractTuple < Scalar > &t) const;

    // Returns the sum of *this and s
    INLINE AbstractTuple < Scalar > add (const Scalar s) const;

    // Returns the difference of *this and tuple t
    INLINE AbstractTuple < Scalar > 
    subtract (const AbstractTuple < Scalar > &t) const;

    // Returns the difference of *this and s
    INLINE AbstractTuple < Scalar > subtract (const Scalar s) const;

    // Returns the componentwise product of *this and tuple t
    INLINE AbstractTuple < Scalar > 
    multiply (const AbstractTuple < Scalar > &t) const;

    // Returns the componentwise product of *this and Scalar s
    INLINE AbstractTuple < Scalar > multiply (const Scalar s) const;

    // Returns the componentwise division of *this by tuple t
    // NOTE: s MUST be != zero!
    INLINE AbstractTuple < Scalar > 
    divide (const AbstractTuple < Scalar > &t) const;

    // Returns the componentwise division of *this by s
    // NOTE: s MUST be != zero!
    INLINE AbstractTuple < Scalar > divide (const Scalar s) const;


    void init (int dim);

    // DATA
    // epsilon: used for comparison etc.
    static Scalar epsilon;

    // dimensions
    int m_dim;

    // coordinates
    Scalar *m_coord;
  };

  template < class Scalar > class MTuple : public AbstractTuple < Scalar >
  {
  public:
    /** constructor
     * @param dim the number of dimensions (should be rows*cols) */
    MTuple (int dim);
    /** copy constructor 
     * @param values the copy source */
    MTuple (const MTuple < Scalar > &values);
    /** upcast constructor 
     * @param tuple the copy source */
    MTuple (const AbstractTuple < Scalar > &tuple);
    /** destructor */
    ~MTuple (void);
    /** returns a reference to the value at a given position 
     * @param pos the position */
    INLINE Scalar & at (int pos);
    /** Returns the componentwise sum of *this and another object
     * @param v the other MTuple object */
    INLINE MTuple < Scalar > &operator+= (MTuple < Scalar > & v);
    /** Returns the componentwise difference of *this and another object
     * @param v the other MTuple object */
    INLINE MTuple < Scalar > &operator-= (MTuple < Scalar > & v);
    /** Returns the product of *this and a scalar
     * @param s the scalar
     * @return *this */
    INLINE MTuple < Scalar > &operator*= (const Scalar s);
    /** Returns the quotient of *this and a scalar
     * @param s the scalar
     * @return *this */
    INLINE MTuple < Scalar > &operator/= (const Scalar s);
    /** Returns the componentwise product of *this and another object
     * @param v the other MTuple object */
    INLINE MTuple < Scalar > mul (const MTuple < Scalar > &v)const;
  };


  ////////////////////////////////////////////////////////////////////////
  // Static variable instantiation
  ////////////////////////////////////////////////////////////////////////
  template < class Scalar > Scalar AbstractTuple < Scalar >::epsilon = EPSILON;

  ////////////////////////////////////////////////////////////////////////
  // Stream operations
  ////////////////////////////////////////////////////////////////////////
  template < class Scalar > std::ostream &
  operator<< (std::ostream & os, const AbstractTuple < Scalar > p);

  template < class Scalar > std::istream &
  operator>> (std::istream & is, AbstractTuple < Scalar > p);

  // include INLINES if required
#include "MTuple.cc"
#ifndef OUTLINE
#include "MTuple.ih"
#endif
}

#endif // MTUPLE_HPP
