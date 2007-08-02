/* -*-gnu-*- */
/*
 * CxxUtil C++ utility library
 * Copyright (c) 2003, 2006 Andreas Kolb, Martin Dietze and Contributors
 *
 * Unless otherwise stated, this software is provided under the terms of the
 * GNU LESSER PUBLIC LICENSE. The text of this license agreement accompanies
 * this library's source distribution.
 */
#ifndef DEFINES_INCL
#define DEFINES_INCL

/* --------------------------------------------------------------------
 * Common definitions
 *
 * $Date: 2007-08-02 12:54:35 $
 * $Revision: 1.8 $
 * -------------------------------------------------------------------- */

#include <climits>
#include <cfloat>
#include <stdint.h>

#ifndef EPSILON
//#define EPSILON 1.e-8
#define EPSILON FLT_EPSILON
#endif

#if defined _MSC_VER || defined __WATCOMC__
/** Moronize code for M\$ idiots. Since you can't compile any line of
 * code using the standard scope for loop variables (variables only  
 * visible inside the loop body) with VC++ this circumvention is   
 * necessary. */
#define for if(0);else for
#endif

namespace CxxUtil 
{

// --------------------------------------------------------------------
// GNU/Linux on a 32-bit PC platform, glibc
// --------------------------------------------------------------------
#if defined (__GNUC__) && defined (__i386__) && (__GNUC__ >= 2)

#ifndef LINUX
#define LINUX
#endif
/** Unsigned 8-bit integer */
typedef unsigned char u8;
/** Unsigned 16-bit integer */
typedef unsigned short u16;
/** Unsigned 32-bit integer */
typedef unsigned long u32;
/** Signed 64-bit integer */
typedef uint64_t u64;
#define CXXUU16_MAX USHRT_MAX
#define CXXUU32_MAX ULONG_MAX

/** Signed 8-bit integer */
typedef signed char i8;
/** Signed 16-bit integer */
typedef signed short i16;
/** Signed 32-bit integer */
typedef long int i32;
/** Signed 64-bit integer */
typedef int64_t i64;

#define CXXU_BYTE_SWAP 1

// --------------------------------------------------------------------
// GNU/Linux on a 64-bit PC platform, glibc
// --------------------------------------------------------------------
#elif defined (__GNUC__) && defined (__x86_64__) && (__GNUC__ >= 2)

#ifndef LINUX
#define LINUX
#endif
/** Unsigned 8-bit integer */
typedef unsigned char u8;
/** Unsigned 16-bit integer */
typedef unsigned short u16;
/** Unsigned 32-bit integer */
typedef unsigned int u32;
/** Signed 64-bit integer */
typedef unsigned long u64;
#define CXXUU16_MAX USHRT_MAX
#define CXXUU32_MAX ULONG_MAX

/** Signed 8-bit integer */
typedef signed char i8;
/** Signed 16-bit integer */
typedef signed short i16;
/** Signed 32-bit integer */
typedef int i32;
/** Signed 64-bit integer */
typedef long int i64;

#define CXXU_BYTE_SWAP 1

// --------------------------------------------------------------------
// GNU/Linux on MTX-1 platform, no glibc
// --------------------------------------------------------------------
#elif defined (__GNUC__) && defined (__MIPSEL__) && (__GNUC__ >= 2)
#ifndef LINUX
#define LINUX
#endif
/** Unsigned 8-bit integer */
typedef unsigned char u8;
/** Unsigned 16-bit integer */
typedef unsigned short u16;
/** Unsigned 32-bit integer */
typedef unsigned long u32;
/** Signed 64-bit integer */
typedef uint64_t u64;
#define CXXUU16_MAX USHRT_MAX
#define CXXUU32_MAX ULONG_MAX

/** Signed 8-bit integer */
typedef signed char i8;
/** Signed 16-bit integer */
typedef signed short i16;
/** Signed 32-bit integer */
typedef long int i32;
/** Signed 64-bit integer */
typedef int64_t i64;

#define CXXU_BYTE_SWAP 1

// --------------------------------------------------------------------
// Intel Compiler (experimental)
// --------------------------------------------------------------------
#elif defined (__INTEL_COMPILER) && (__INTEL_COMPILER >= 60)

#ifndef LINUX
#define LINUX
#endif
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef signed char i8;
typedef signed short i16;
typedef long int i32;
typedef __int64_t i64;

#define CXXUU16_MAX USHRT_MAX
#define CXXUU32_MAX ULONG_MAX

#define CXXU_BYTE_SWAP 1

// --------------------------------------------------------------------
// GCC on SUNOS, Sparc platform
// --------------------------------------------------------------------
#elif defined (__GNUC__) && defined (__sparc__) && (__GNUC__ >= 2) \
  && !(defined (__sparcv9) || defined (__sparc_v9__))

#ifndef SUNOS
#define SUNOS
#endif
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef signed char i8;
typedef signed short i16;
typedef long int i32;
typedef __int64 i64;

#define CXXUU16_MAX USHRT_MAX
#define CXXUU32_MAX ULONG_MAX

#define CXXU_BYTE_SWAP 0

// --------------------------------------------------------------------
// SGI CC on IRIX, 64-bit MIPS platform
// --------------------------------------------------------------------
#elif defined (__sgi) && defined (__host_mips) && defined (_MIPSEB) \
  && defined (_MIPS_SZLONG) && _MIPS_SZLONG == 32

#ifndef IRIX
#define IRIX
#endif
typedef unsigned short u16;
typedef unsigned long u32;
typedef __uint64_t u64;

typedef signed char i8;
typedef signed short i16;
typedef long int i32;
typedef __int64_t i64;

#define CXXUU16_MAX USHRT_MAX
#define CXXUU32_MAX ULONG_MAX

#define CXXU_BYTE_SWAP 0

// --------------------------------------------------------------------
// MSC on Windows
// --------------------------------------------------------------------
#elif defined (_MSC_VER)

/** Moronize code for M\$ idiots. Since you can't compile any line of
 * code using the standard scope for loop variables (variables only  
 * visible inside the loop body) with VC++ this circumvention is   
 * necessary. */
#define for if(0);else for

#ifndef WIN32
#define WIN32
#endif
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned __int64 u64;

typedef signed char i8;
typedef signed short i16;
typedef long int i32;
typedef __int64 i64;

#define CXXUU16_MAX USHRT_MAX
#define CXXUU32_MAX ULONG_MAX

#define CXXU_BYTE_SWAP 1

#else
#error "I don't know your system, configure me!"
#endif

#if CXXU_BYTE_SWAP

#define CXXU_BSWAP16(x) ((u16) (                      \
        (((u16)(x) & (u16) 0x00ffU) << 8) |       \
        (((u16)(x) & (u16) 0xff00U) >> 8) ))

#define CXXU_BSWAP32(x) ((u32)(                       \
        (((u32)(x) & (u32)0x000000ffUL) << 24) |  \
        (((u32)(x) & (u32)0x0000ff00UL) <<  8) |  \
        (((u32)(x) & (u32)0x00ff0000UL) >>  8) |  \
        (((u32)(x) & (u32)0xff000000UL) >> 24) ))

#define _htof32(x)  CXXU_BSWAP32 (x)
#define _ftoh32(x)  CXXU_BSWAP32 (x)
#define _htof16(x)  CXXU_BSWAP32 (x)
#define _ftoh16(x)  CXXU_BSWAP32 (x)

#else

#define _htof32(x)  (x)
#define _ftoh32(x)  (x)
#define _htof16(x)  (x)
#define _ftoh16(x)  (x)

#endif /* CXXU_BYTE_SWAP */

#define SIZE_CHECK(type,size,name) \
  typedef type name[(sizeof (type) == size)*2-1]

SIZE_CHECK (u8,  1, test_if_u8_is_8);
SIZE_CHECK (u16, 2, test_if_u16_is_16);
SIZE_CHECK (u32, 4, test_if_u32_is_32);
SIZE_CHECK (u64, 8, test_if_u64_is_64);

SIZE_CHECK (i8,  1, test_if_i8_is_8);
SIZE_CHECK (i16, 2, test_if_i16_is_16);
SIZE_CHECK (i32, 4, test_if_i32_is_32);
SIZE_CHECK (i64, 8, test_if_i64_is_64);

#undef SIZE_CHECK

#ifndef INLINE
#ifdef OUTLINE
#define INLINE
#else
#define INLINE inline
#endif
#endif

#ifndef NEW
#define NEW(a)       new a
#endif
#ifndef DELETE
#define DELETE(a)    delete (a), (a) = NULL
#endif
#ifndef DELETEAR
#define DELETEAR(a)  delete [] (a), (a) = NULL
#endif
#ifndef DELETENOTNULL
#define DELETENOTNULL(a) if (a) { delete (a); (a) = NULL; } else {}
#endif
#ifndef DELETENOTNULLAR
#define DELETENOTNULLAR(a) if (a) { delete [] (a); (a) = NULL; } else {}
#endif
}

#endif
