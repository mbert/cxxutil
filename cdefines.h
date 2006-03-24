#ifndef DEFINES_INCL
#define DEFINES_INCL

/* --------------------------------------------------------------------
// FILE:    defines.h
// AUFGABE: Globale Makro- und Typ-Definitionen
// BESCHR.: 
//          
// $Date: 2006-03-24 15:36:45 $
// $Revision: 1.1 $
//
// ----------------------------------------------------------------- */

#include <limits.h>
#include <float.h>

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


#if defined (__GNUC__) && defined (__i386__) && (__GNUC__ >= 2)

#ifndef LINUX
#define LINUX
#endif
typedef unsigned short bmbfu16;
typedef unsigned long bmbfu32;
#define BMBFU16_MAX USHRT_MAX
#define BMBFU32_MAX ULONG_MAX

#define BMBF_BYTE_SWAP 1

#elif defined (__INTEL_COMPILER) && (__INTEL_COMPILER >= 60)

#error "this is not tested"

typedef unsigned short bmbfu16;
typedef unsigned long bmbfu32;
#define BMBFU16_MAX USHRT_MAX
#define BMBFU32_MAX ULONG_MAX

#define BMBF_BYTE_SWAP 1

#elif defined (__GNUC__) && defined (__sparc__) && (__GNUC__ >= 2) \
  && !(defined (__sparcv9) || defined (__sparc_v9__))

#ifndef SUNOS
#define SUNOS
#endif
typedef unsigned short bmbfu16;
typedef unsigned long bmbfu32;
#define BMBFU16_MAX USHRT_MAX
#define BMBFU32_MAX ULONG_MAX

#define BMBF_BYTE_SWAP 0

#elif defined (__mips) || defined (__MIPS_ISA)

#ifndef IRIX
#define IRIX
#endif
typedef unsigned short bmbfu16;
typedef unsigned long bmbfu32;
#define BMBFU16_MAX USHRT_MAX
#define BMBFU32_MAX ULONG_MAX

#define BMBF_BYTE_SWAP 0

#elif defined (__LCLINT__)

typedef unsigned short bmbfu16;
typedef unsigned long bmbfu32;
#define BMBFU16_MAX USHRT_MAX
#define BMBFU32_MAX ULONG_MAX

#elif defined (_MSC_VER)
#ifndef WIN32
#define WIN32
#endif
typedef unsigned short bmbfu16;
typedef unsigned long bmbfu32;
#define BMBFU16_MAX USHRT_MAX
#define BMBFU32_MAX ULONG_MAX

#define BMBF_BYTE_SWAP 1

#elif defined (__WATCOMC__)
#ifndef WIN32
#define WIN32
#endif
typedef unsigned short bmbfu16;
typedef unsigned long bmbfu32;
#define BMBFU16_MAX USHRT_MAX
#define BMBFU32_MAX ULONG_MAX

#define BMBF_BYTE_SWAP 1

#else
#error "I don't know your system, configure me!"
#endif

#if BMBF_BYTE_SWAP

#define BMBF_BSWAP16(x) ((bmbfu16) (                      \
        (((bmbfu16)(x) & (bmbfu16) 0x00ffU) << 8) |       \
        (((bmbfu16)(x) & (bmbfu16) 0xff00U) >> 8) ))

#define BMBF_BSWAP32(x) ((bmbfu32)(                       \
        (((bmbfu32)(x) & (bmbfu32)0x000000ffUL) << 24) |  \
        (((bmbfu32)(x) & (bmbfu32)0x0000ff00UL) <<  8) |  \
        (((bmbfu32)(x) & (bmbfu32)0x00ff0000UL) >>  8) |  \
        (((bmbfu32)(x) & (bmbfu32)0xff000000UL) >> 24) ))

#define bmbf_htof32(x)  BMBF_BSWAP32 (x)
#define bmbf_ftoh32(x)  BMBF_BSWAP32 (x)
#define bmbf_htof16(x)  BMBF_BSWAP32 (x)
#define bmbf_ftoh16(x)  BMBF_BSWAP32 (x)

#else

#define bmbf_htof32(x)  (x)
#define bmbf_ftoh32(x)  (x)
#define bmbf_htof16(x)  (x)
#define bmbf_ftoh16(x)  (x)

#endif /* BMBF_BYTE_SWAP */

#define SIZE_CHECK(type,size,name) \
  typedef type name[(sizeof (type) == size)*2-1]

SIZE_CHECK (bmbfu16, 2, test_if_16_is_16);
SIZE_CHECK (bmbfu32, 4, test_if_32_is_32);

#undef SIZE_CHECK

#endif
