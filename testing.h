#ifndef TESTING_H
#define TESTING_H

/** @addtogroup common */
// *********************************************************************
//  @short Testing macros
//
//  @ingroup common 
//  @author  Martin Dietze <herbert@spamcop.net>
//  @version 0.1
//
/*  --------------------------------------------------------------------
//  Project: Repairing and texturing of VR models
//  (C) Copyright Fachhochschule Wedel, Germany 2003
//  --------------------------------------------------------------------
//  $Revision: 1.1 $
//  $Date: 2006-03-24 15:36:45 $
// ********************************************************************** */

#include <assert.h>
#include <math.h>
#include <float.h>
#include <string.h>
#include <stdexcept>

/** The code cmd must throw an exception */
#define TEST_EXCEPTION(cmd) \
  { try { { cmd; } assert (0); } catch (const std::exception &error) { \
      std::cout << " *** Expected exception caught: " << error.what () << \
      std::endl; } }

/** The code cmd must not throw an exception */
#define TEST_NO_EXCEPTION(cmd) \
  { try { { cmd; } } catch (const std::exception &error) { \
      std::cout << " *** Exception caught: " << error.what () << \
      std::endl; assert (0); } }

/** The double values d1 and d2 must differ */
#define TEST_DBL_DIFFERS(d1,d2) \
  (assert (fabs ((double)((d1) - (d2))) >= DBL_EPSILON))
/** The double values d1 and d2 must be equal */
#define TEST_DBL_EQUALS(d1,d2)  \
  (assert (fabs ((double)((d1) - (d2))) < DBL_EPSILON))
/** The double value d1 must be greater than d2 */
#define TEST_DBL_GREATER(d1,d2) (assert ((d1) > (d2)))
/** The double value d1 must be less than d2 */
#define TEST_DBL_LESS(d1,d2)    (assert ((d1) < (d2)))

/** The float values d1 and d2 must differ */
#define TEST_FLT_DIFFERS(d1,d2) \
  (assert (fabs ((float)((d1) - (d2))) >= FLT_EPSILON))
/** The float values d1 and d2 must be equal */
#define TEST_FLT_EQUALS(d1,d2)  \
  (assert (fabs ((float)((d1) - (d2))) < FLT_EPSILON))
/** The float value d1 must be greater than d2 */
#define TEST_FLT_GREATER(d1,d2) (assert ((d1) > (d2)))
/** The float value d1 must be less than d2 */
#define TEST_FLT_LESS(d1,d2)    (assert ((d1) < (d2)))

/** The strings s1 and s2 must differ */
#define TEST_STR_DIFFERS(s1,s2) (assert (strcmp (s1, s2) != 0))
/** The strings s1 and s2 must be equal */
#define TEST_STR_EQUALS(s1,s2)  (assert (strcmp (s1, s2) == 0))
/** The strings s1 must be greater than s2 */
#define TEST_STR_GREATER(s1,s2) (assert (strcmp (s1, s2) > 0))
/** The strings s1 must be less than s2 */
#define TEST_STR_LESS(s1,s2)    (assert (strcmp (s1, s2) < 0))

/** The generic values g1 and g2 must differ */
#define TEST_GEN_DIFFERS(g1,g2) (assert ((g1) != (g2)))
/** The generic values g1 and g2 must be equal */
#define TEST_GEN_EQUALS(g1,g2)  (assert ((g1) == (g2)))
/** The generic value g1 must be greater than g2 */
#define TEST_GEN_GREATER(g1,g2) (assert ((g1) > (g2)))
/** The generic value g1 must be less than g2 */
#define TEST_GEN_LESS(g1,g2)    (assert ((g1) < (g2)))

/** the expression expr must be true */
#define TEST_ASSERT(expr)       (assert (expr))
/** the expression expr must be false */
#define TEST_NOT(expr)          (assert (!(expr)))

#endif // TESTING_H
