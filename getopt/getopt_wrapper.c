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

/* --------------------------------------------------------------------
 * Wrapper for BSD-getopt implementation
 *
 * $Date: 2006-03-27 11:08:15 $
 * $Revision: 1.2 $
 * -------------------------------------------------------------------- */

/* 
 * force including this one once so that we've got the proper getopt_long defs
 * in the included sources
 */
#include "getopt/getopt_wrapper.h"

/* include the first source file */
#include "getopt/getopt.c"

/* cleanup stuff it has defined */
#ifdef BADARG
#undef BADARG
#endif

#ifdef WIN32
#ifndef _WIN32
#define _WIN32
#endif
#else
#include <err.h>
#endif

/* include the second source file */
#include "getopt_long.c"

/* we're done. */
