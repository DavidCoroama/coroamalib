/* Different shorthands for commonly used functions.
   Copyright (C) 2007 Free Software Foundation, Inc.
   Contributed by David Coroama (david.coroama.dev@gmail.com)

This file includes shorthand macros for various standard 
library features and functions, as well as commonly used 
syntax in the C language. Shorthands can be switched off
by defining certain macro names. */

#pragma once
#ifndef _COROAMALIB_SHORTHANDS_H_
#define _COROAMALIB_SHORTHANDS_H_

#ifndef _DISABLE_MALLOC_SHORTHANDS
    #define MALLOC(T, size) (T*)malloc(sizeof(T) * (size))
    #define VARMALLOC(var, T, size) T* var = MALLOC(T, size)
#endif//_DISABLE_MALLOC_SHORTHANDS

#ifndef _DISABLE_CALLOC_SHORTHANDS
    #define CALLOC(T, size) (T*)calloc(size, sizeof(T))
    #define VARCALLOC(var, T, size) T* var = CALLOC(T, size)
#endif//_DISABLE_CALLOC_SHORTHANDS

#ifndef _DISABLE_REALLOC_SHORTHANDS
    #define REALLOC(block, T, size) (T*)realloc(block, sizeof(T) * (size))
    #define VARREALLOC(var, block, T, size) T* var = REALLOC(block, T, size)
#endif//_DISABLE_REALLOC_SHORTHANDS

#ifndef _DISABLE_MAIN_FUNCTION_SHORTHANDS
    #define MAIN(Arg1Name, Arg2Name) int main(int Arg1Name, char* Arg2Name[])
    #define EMPTY_MAIN(exitcode) int main(void) {return exitcode;}
    #define DEFAULT_MAIN MAIN(argc, argv)
#endif//_DISABLE_MAIN_FUNCTION_SHORTHANDS

#endif //_COROAMALIB_SHORTHANDS_H_