/* Internal Type Shorthands Declaration File.
   Copyright (C) 2007 Free Software Foundation, Inc.
   Contributed by David Coroama (david.coroama.dev@gmail.com)

This file simplifies the naming of integer types, making them 
shorter and more user-friendly. This specific type file is 
meant to be used within the 'coroamalib' library. Its purpose 
is to prevent the type file from being unintentionally imported 
from other feature files.

It has the same types as the standard 'types.h' file, except 
they are all defined as macros. This enables them to be undefined 
at the end of the file that imports it. */

#pragma once
#ifndef _COROAMALIB_EXT_TYPES_H_
#define _COROAMALIB_EXT_TYPES_H_

#define i8   signed char
#define i16  signed short
#define i32  signed int
#define i64  signed long long

#define u8   unsigned char
#define u16  unsigned short
#define u32  unsigned int
#define u64  unsigned long long

#define f32  float
#define f64  double
#define f128 long double

#define size_t  u64
#define ssize_t i64

#endif//_COROAMALIB_EXT_TYPES_H_