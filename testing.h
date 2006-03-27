/* -*-gnu-*- */
/*
 * CxxUtil C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated, this software is provided under the terms of the
 * GNU LESSER PUBLIC LICENSE. The text of this license agreement accompanies
 * this library's source distribution.
 */

#ifndef TESTING_H
#define TESTING_H

/* --------------------------------------------------------------------
 * Testing macros
 *
 * $Date: 2006-03-27 13:40:22 $
 * $Revision: 1.5 $
 * -------------------------------------------------------------------- */

/**
 * @short Testing macros
 */

#include <cassert>
#include <cmath>
#include <cfloat>
#include <cstring>
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
