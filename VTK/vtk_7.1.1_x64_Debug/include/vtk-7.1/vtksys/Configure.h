/*============================================================================
  KWSys - Kitware System Library
  Copyright 2000-2009 Kitware, Inc., Insight Software Consortium

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#ifndef vtksys_Configure_h
#define vtksys_Configure_h

/* If we are building a kwsys .c or .cxx file, let it use the kwsys
   namespace.  When not building a kwsys source file these macros are
   temporarily defined inside the headers that use them.  */
#if defined(KWSYS_NAMESPACE)
# define kwsys_ns(x) vtksys##x
# define kwsysEXPORT vtksys_EXPORT
#endif

/* Disable some warnings inside kwsys source files.  */
#if defined(KWSYS_NAMESPACE)
# if defined(__BORLANDC__)
#  pragma warn -8027 /* function not inlined.  */
# endif
# if defined(__INTEL_COMPILER)
#  pragma warning (disable: 1572) /* floating-point equality test */
# endif
# if defined(__sgi) && !defined(__GNUC__)
#  pragma set woff 3970 /* pointer to int conversion */
#  pragma set woff 3968 /* 64 bit conversion */
# endif
#endif

/* Whether kwsys namespace is "kwsys".  */
#define vtksys_NAME_IS_KWSYS 0

/* Whether Large File Support is requested.  */
#define vtksys_LFS_REQUESTED 1

/* Whether Large File Support is available.  */
#if vtksys_LFS_REQUESTED
# define vtksys_LFS_AVAILABLE 0
#endif

/* Setup Large File Support if requested.  */
#if vtksys_LFS_REQUESTED
  /* Since LFS is requested this header must be included before system
     headers whether or not LFS is available. */
# if 0 && (defined(_SYS_TYPES_H) || defined(_SYS_TYPES_INCLUDED))
#  error "vtksys/Configure.h must be included before sys/types.h"
# endif
  /* Enable the large file API if it is available.  */
# if vtksys_LFS_AVAILABLE && \
     !defined(vtksys_LFS_NO_DEFINES)
#  if !defined(_LARGEFILE_SOURCE) && \
      !defined(vtksys_LFS_NO_DEFINE_LARGEFILE_SOURCE)
#   define _LARGEFILE_SOURCE
#  endif
#  if !defined(_LARGEFILE64_SOURCE) && \
      !defined(vtksys_LFS_NO_DEFINE_LARGEFILE64_SOURCE)
#   define _LARGEFILE64_SOURCE
#  endif
#  if !defined(_LARGE_FILES) && \
      !defined(vtksys_LFS_NO_DEFINE_LARGE_FILES)
#   define _LARGE_FILES
#  endif
#  if !defined(_FILE_OFFSET_BITS) && \
      !defined(vtksys_LFS_NO_DEFINE_FILE_OFFSET_BITS)
#   define _FILE_OFFSET_BITS 64
#  endif
#  if 0 && (defined(_FILE_OFFSET_BITS) && _FILE_OFFSET_BITS < 64)
#   error "_FILE_OFFSET_BITS must be defined to at least 64"
#  endif
# endif
#endif

/* Setup the export macro.  */
#if 1
# if defined(_WIN32) || defined(__CYGWIN__)
#  if defined(vtksys_EXPORTS)
#   define vtksys_EXPORT __declspec(dllexport)
#  else
#   define vtksys_EXPORT __declspec(dllimport)
#  endif
# elif __GNUC__ >= 4
#  define vtksys_EXPORT __attribute__ ((visibility("default")))
# else
#  define vtksys_EXPORT
# endif
#else
# define vtksys_EXPORT
#endif

/* Enable warnings that are off by default but are useful.  */
#if !defined(vtksys_NO_WARNING_ENABLE)
# if defined(_MSC_VER)
#  pragma warning ( default : 4263 ) /* no override, call convention differs */
# endif
#endif

/* Disable warnings that are on by default but occur in valid code.  */
#if !defined(vtksys_NO_WARNING_DISABLE)
# if defined(_MSC_VER)
#  pragma warning (disable: 4097) /* typedef is synonym for class */
#  pragma warning (disable: 4127) /* conditional expression is constant */
#  pragma warning (disable: 4244) /* possible loss in conversion */
#  pragma warning (disable: 4251) /* missing DLL-interface */
#  pragma warning (disable: 4305) /* truncation from type1 to type2 */
#  pragma warning (disable: 4309) /* truncation of constant value */
#  pragma warning (disable: 4514) /* unreferenced inline function */
#  pragma warning (disable: 4706) /* assignment in conditional expression */
#  pragma warning (disable: 4710) /* function not inlined */
#  pragma warning (disable: 4786) /* identifier truncated in debug info */
# endif
# if defined(__BORLANDC__) && !defined(__cplusplus)
   /* Code has no effect; raised by winnt.h in C (not C++) when ignoring an
      unused parameter using "(param)" syntax (i.e. no cast to void).  */
#  pragma warn -8019
# endif
#endif

/* MSVC 6.0 in release mode will warn about code it produces with its
   optimizer.  Disable the warnings specifically for this
   configuration.  Real warnings will be revealed by a debug build or
   by other compilers.  */
#if !defined(vtksys_NO_WARNING_DISABLE_BOGUS)
# if defined(_MSC_VER) && (_MSC_VER < 1300) && defined(NDEBUG)
#  pragma warning ( disable : 4701 ) /* Variable may be used uninitialized.  */
#  pragma warning ( disable : 4702 ) /* Unreachable code.  */
# endif
#endif

#endif
