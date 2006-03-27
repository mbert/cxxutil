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

#ifndef GETOPT_WRAPPER_H
#define GETOPT_WRAPPER_H

/* --------------------------------------------------------------------
 * Wrapper for BSD-getopt implementation
 *
 * $Date: 2006-03-27 11:08:15 $
 * $Revision: 1.2 $
 * -------------------------------------------------------------------- */

/* macros used in getopt/getopt.h (make sure this does not cause problems) */
#ifndef __P
#define __P(args)      args
#endif
#ifndef GETOPT_API
#ifdef WIN32
#define GETOPT_API __declspec(dllexport)
#else
#define GETOPT_API 
#ifndef __BEGIN_DECLS
#define __BEGIN_DECLS
#endif
#ifndef __END_DECLS
#define __END_DECLS
#endif
#endif
#endif

#define getopt my_getopt
#define getopt_long my_getopt_long
#define opterr my_opterr
#define optind my_optind 
#define optopt my_optopt
#define optreset my_optreset
#define optarg my_optarg
#define option my_option

/* make sure we get to see struct option */
#ifdef _POSIX_SOURCE
#define POSIX_SOURCE_DEFINED
#undef _POSIX_SOURCE
#endif
#ifdef _XOPEN_SOURCE
#define XOPEN_SOURCE_DEFINED
#undef _XOPEN_SOURCE
#endif

/* 
 * force including this one once so that we've got the proper getopt_long defs
 * in the included sources
 */
#include "getopt/getopt.h"

/* cleanup to avoid side effects */
#ifdef POSIX_SOURCE_DEFINED
#undef POSIX_SOURCE_DEFINED
#define _POSIX_SOURCE 1
#endif
#ifdef XOPEN_SOURCE_DEFINED
#undef XOPEN_SOURCE_DEFINED
#define _XOPEN_SOURCE 1
#endif

#endif // GETOPT_WRAPPER_H
