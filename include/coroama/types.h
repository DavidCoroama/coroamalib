/* Type shorthands declaration file.
   Copyright (C) 2007 Free Software Foundation, Inc.
   Contributed by David Coroama (david.coroama.dev@gmail.com)

This file simplifies the naming of integer types, making them 
shorter and more user-friendly. Additionally, you have the option 
to define each type behind a macro. This allows you to employ 
preprocessing conditional logic to check if a specific type is defined.

Also provides 128-bit integer types, if your machine is 64-bit, 
for the signed integer, unsigned integer, and float. 

If you don't want each type to be defined as a macro you can
define '_DISABLE_TYPE_MACROS' before you import this file. */

#pragma once
#ifndef _COROAMALIB_TYPES_H_
#define _COROAMALIB_TYPES_H_

#include <coroama/ext/util.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif//__cplusplus

_T(S char)   i8;
_T(S short)  i16;
_T(S int)    i32;
_T(S L L)    i64;

_T(U char)   u8;
_T(U short)  u16;
_T(U int)    u32;
_T(U L L)    u64;

_T(float)    f32;
_T(double)   f64;
_T(L double) f128;

#ifndef _DISABLE_TYPE_MACROS
    #define i8   i8
    #define i16  i16
    #define i32  i32
    #define i64  i64

    #define u8   u8
    #define u16  u16
    #define u32  u32
    #define u64  u64

    #define f32  f32
    #define f64  f64
    #define f128 f128
#endif//_DISABLE_TYPE_MACROS

#ifdef __x86_64__
    _T(S int) i128 _A(mode(TI));
    _T(U int) u128 _A(mode(TI));

    #ifndef _DISABLE_TYPE_MACROS
        #define i128 i128
        #define u128 u128
    #endif//_DISABLE_TYPE_MACROS
#endif

#ifdef __cplusplus
}
#endif//__cplusplus

#include <coroama/ext/cleanup.h>

#endif //_COROAMALIB_TYPES_H_