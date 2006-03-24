/* ********************************************************************
//  Class: MTuple
//  Implementation of class MTuple
//  -------------------------------------------------------------------
//  Project: Repairing and texturing of VR models
//  (C) Copyright Fachhochschule Wedel, Germany 2003
//  -------------------------------------------------------------------
//  $Revision: 1.1 $
//  $Date: 2006-03-24 15:36:45 $
// ******************************************************************** */

#ifndef MTUPLE_CPP
#define MTUPLE_CPP

// class specific includes
#include "MTuple.hh"
#include "mmessages.h"
#include "cutil.h"

#include <stdexcept>

// include "outlined" INLINE functions
#ifdef OUTLINE
#include "MTuple.ih"
#endif

template < class Scalar > 
HmdUtils::AbstractTuple < Scalar >::AbstractTuple (int dim)
{
  init (dim);
}

template < class Scalar >
HmdUtils::AbstractTuple < Scalar >::AbstractTuple (const AbstractTuple < Scalar > &t)
{
  init (t.m_dim);

  for (int i = 0; i < m_dim; i++)
    {
      m_coord[i] = t.m_coord[i];
    }
}

template < class Scalar >
HmdUtils::AbstractTuple < Scalar >::AbstractTuple (const int dim, const Scalar s)
{
  init (dim);

  for (int i = 0; i < dim; i++)
    {
      m_coord[i] = s;
    }
}

template < class Scalar > 
HmtUtils::AbstractTuple < Scalar >::~AbstractTuple (void)
{
  DELETE (m_coord);
}

// Constructor from two tuples
template < class Scalar > 
HmtUtils::AbstractTuple < Scalar >::AbstractTuple (const AbstractTuple < Scalar > &t1,
						   char op,
						   const AbstractTuple < Scalar > &t2)
{
  init (t1.m_dim);

  for (int i = 0; i < m_dim; i++)
    {
      m_coord[i] = t1.m_coord[i];
    }
  switch (op)
    {
    case '+': 
      for (int i = 0; i < m_dim; i++)
        {
          m_coord[i] = m_coord[i] + t2.m_coord[i];
        }
      break;
    case '-': 
      for (int i = 0; i < m_dim; i++)
        {
          m_coord[i] = m_coord[i] - t2.m_coord[i];
        }
      break;
    case '*': 
      for (int i = 0; i < m_dim; i++)
        {
          m_coord[i] = m_coord[i] * t2.m_coord[i];
        }
      break;
    case '/': 
      for (int i = 0; i < m_dim; i++)
        {
          m_coord[i] = m_coord[i] / t2.m_coord[i];
        }
      break;
    }
}

// Constructor from a tuple and a scalar
template < class Scalar > 
HmdUtils::AbstractTuple < Scalar >::AbstractTuple (const AbstractTuple < Scalar > &t1,
						   char op, Scalar s)
{
  init (t1.m_dim);

  for (int i = 0; i < m_dim; i++)
    {
      m_coord[i] = t1.m_coord[i];
    }
  switch (op)
    {
    case '+': 
      for (int i = 0; i < m_dim; i++)
        {
          m_coord[i] = m_coord[i] + s;
        }
      break;
    case '-': 
      for (int i = 0; i < m_dim; i++)
        {
          m_coord[i] = m_coord[i] - s;
        }
      break;
    case '*': 
      for (int i = 0; i < m_dim; i++)
        {
          m_coord[i] = m_coord[i] * s;
        }
      break;
    case '/': 
      for (int i = 0; i < m_dim; i++)
        {
          m_coord[i] = m_coord[i] / s;
        }
      break;
    }
}

////////////////////////////////////////////////////////////////////////
// COMPARISON
////////////////////////////////////////////////////////////////////////
template < class Scalar > bool
HmdUtils::AbstractTuple < Scalar >::operator== (const AbstractTuple<Scalar> &t) const
{
  for (int i = 0; i < m_dim; i++)
    {
      if (fabs (m_coord[i] - t.m_coord[i]) > epsilon)
        {
          return false;
        }
    }

  return true;
}

template < class Scalar > bool
HmdUtils::AbstractTuple < Scalar >::operator!= (const AbstractTuple<Scalar> &t) const
{
  return !(*this == t);
}


////////////////////////////////////////////////////////////////////////
// COORD ACCESS
////////////////////////////////////////////////////////////////////////

// Returns the reference to the i-th components of the tuple
// Note: Here the content can be changed
template < class Scalar > Scalar & 
HmdUtils::AbstractTuple < Scalar >::operator[](int i)
{
  if (i >= m_dim)
    {
      throw std::invalid_argument ("AbstractTuple::operator[]: "  
                                   MSG_ERROR_BOUNDS_CHECK);
    }
  return m_coord[i];
}

// Returns the reference to the i-th components of the tuple
// Note: Here the content can not be changed
template < class Scalar > const Scalar & 
HmdUtils::AbstractTuple < Scalar >::operator[] (int i) const
{
  if (i >= m_dim)
    {
      throw std::invalid_argument ("AbstractTuple::operator[]: "
                                   MSG_ERROR_BOUNDS_CHECK);
    }
  return m_coord[i];
}

////////////////////////////////////////////////////////////////////////
// UNARY ASSIGNMENT OPERATOR
////////////////////////////////////////////////////////////////////////

// Assignment to another tuple
template < class Scalar > AbstractTuple < Scalar > &
HmdUtils::AbstractTuple < Scalar >::assignTo (const AbstractTuple < Scalar > &t)
{
  if (t.m_dim != this->m_dim)
    {
      DELETE (m_coord);
      init (t.m_dim);
    }

  if (&t != this)
    {
      for (int i = 0; i < m_dim; i++)
        {
          m_coord[i] = t.m_coord[i];
        }
    }

  return *this;
}

// Assigns all components to s
template < class Scalar > AbstractTuple < Scalar > &
HmdUtils::AbstractTuple < Scalar >::assignTo (const Scalar s)
{
  for (int i = 0; i < m_dim; i++)
    {
      m_coord[i] = s;
    }
  return *this;
}


// Assignment to the same tuple plus tuple t
template < class Scalar > AbstractTuple < Scalar > &
HmdUtils::AbstractTuple < Scalar >::addToMe (const AbstractTuple < Scalar > &t)
{
  for (int i = 0; i < m_dim; i++)
    {
      m_coord[i] += t.m_coord[i];
    }

  return *this;
}

// Assignment to the same point plus point consisting of Scalars s
template < class Scalar > AbstractTuple < Scalar > &
HmdUtils::AbstractTuple < Scalar >::addToMe (const Scalar s)
{
  for (int i = 0; i < m_dim; i++)
    {
      m_coord[i] += s;
    }

  return *this;
}

// Assignment to the same tuple minus tuple t
template < class Scalar > AbstractTuple < Scalar > &
HmdUtils::AbstractTuple < Scalar >::subFromMe (const AbstractTuple < Scalar > &t)
{
  for (int i = 0; i < m_dim; i++)
    {
      m_coord[i] -= t.m_coord[i];
    }

  return *this;
}

// Assignment to the same point minus point consisting of Scalars s
template < class Scalar > AbstractTuple < Scalar > &
HmdUtils::AbstractTuple < Scalar >::subFromMe (const Scalar s)
{
  for (int i = 0; i < m_dim; i++)
    {
      m_coord[i] -= s;
    }

  return *this;
}

// Assignment to the same tuple multiplied by a Scalar s componentwise
template < class Scalar > AbstractTuple < Scalar > &
HmdUtils::AbstractTuple < Scalar >::multMeBy (const Scalar s)
{
  for (int i = 0; i < m_dim; i++)
    {
      m_coord[i] *= s;
    }

  return *this;
}

// Assignment to the same tuple divided by Scalar s
// NOTE: s MUST be != zero!!
template < class Scalar > AbstractTuple < Scalar > &
HmdUtils::AbstractTuple < Scalar >::divMeBy (const Scalar s)
{
  for (int i = 0; i < m_dim; i++)
    {
      m_coord[i] /= s;
    }

  return *this;
}

// Assignment to the same point divided by point t componentwise
// NOTE: The components of t MUST be != zero!!
template < class Scalar > AbstractTuple < Scalar > &
HmdUtils::AbstractTuple < Scalar >::divMeBy (const AbstractTuple < Scalar > &t)
{
  for (int i = 0; i < m_dim; i++)
    {
      m_coord[i] /= t.m_coord[i];
    }

  return *this;
}

////////////////////////////////////////////////////////////////////////
// Compute norm & sum
////////////////////////////////////////////////////////////////////////

template < class Scalar > Scalar 
HmdUtils::AbstractTuple < Scalar >::getNormQuad (void) const
{
  Scalar normQ = 0;
  for (int i = 0; i < m_dim; i++)
    {
      normQ += m_coord[i] * m_coord[i];
    }
  return normQ;
}

template < class Scalar > Scalar 
HmdUtils::AbstractTuple < Scalar >::getSum (void) const
{
  Scalar sum = 0;
  for (int i = 0; i < m_dim; i++)
    {
      sum += m_coord[i];
    }

  return sum;
}

////////////////////////////////////////////////////////////////////////
// Epsilon handling
////////////////////////////////////////////////////////////////////////
template < class Scalar > void 
HmdUtils::AbstractTuple < Scalar >::setEpsilon (Scalar s)
{
  epsilon = s;
}

template < class Scalar > Scalar 
HmdUtils::AbstractTuple < Scalar >::getEpsilon () const
{
  return epsilon;
}

////////////////////////////////////////////////////////////////////////
// Getting the dimension
////////////////////////////////////////////////////////////////////////
template < class Scalar > int 
HmdUtils::AbstractTuple < Scalar >::getDim (void) const
{
  return m_dim;
}

template < class Scalar > void 
HmdUtils::AbstractTuple < Scalar >::init (int dim)
{
  m_dim = dim;
  m_coord = NEW (Scalar[m_dim]);
  for (int i = 0; i < m_dim; i++)
    {
      m_coord[i] = (Scalar) 0;
    }
}

template < class Scalar > std::ostream &
operator<< (std::ostream & os, const AbstractTuple < Scalar > p)
{
  os << "( ";
  for (int i = 0; i < p.getDim (); i++)
    {
      if (i != 0)
        {
          os << ", ";
        }
      os << p[i];
    }
  os << " )";
  return os;
}

template < class Scalar > std::istream &
operator>> (std::istream & is, AbstractTuple < Scalar > p)
{
  char
    c;
  is >> c;
  for (int i = 0; i < p.getDim (); i++)
    {
      if (i != 0)
        {
          is >> c;
        }
      is >> p[i];
    }
  is >> c;
  return is;
}

/* ===================== helper class MTuple ========================== */

template < class Scalar >
HmdUtils::MTuple < Scalar > :: MTuple (int dim) 
  : AbstractTuple < Scalar > (dim)
{
}

template < class Scalar > 
HmdUtils::MTuple < Scalar > :: MTuple (const MTuple < Scalar > &values) 
  : AbstractTuple < Scalar > (values)
{
}

template < class Scalar > 
HmdUtils::MTuple < Scalar > :: MTuple (const AbstractTuple < Scalar > &tuple)
  : AbstractTuple < Scalar > (tuple)
{
}

template < class Scalar > 
HmdUtils::MTuple < Scalar > ::~MTuple (void)
{
}

#endif // MTUPLE_CPP
