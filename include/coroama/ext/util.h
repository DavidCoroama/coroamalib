/* Utility functions used by `coroamalib`.
   Copyright (C) 2007 Free Software Foundation, Inc.
   Contributed by David Coroama (david.coroama.dev@gmail.com)

Anything delcared here is not intended to be 
used outside of the `coroamalib` library. */

#pragma once
#ifndef _COROAMALIB_EXT_UTIL_H_
#define _COROAMALIB_EXT_UTIL_H_

#define _R(x) (x)
#define _A(x) __attribute__((x))
#define _T(x) typedef x

#ifdef _COROAMALIB_TYPES_H_
   #define L long
   #define S signed
   #define U unsigned
#endif//_COROAMALIB_TYPES_H_

#endif //_COROAMALIB_EXT_UTIL_H_