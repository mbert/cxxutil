/* -*-configsys-*- */
/* ---------------------------------------------------------------------------
/// @file
/// @brief Wrapper for compiling the NetBSD implementation of getopt.
/// @author Martin Dietze
// --------------------------------------------------------------------------- */

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
