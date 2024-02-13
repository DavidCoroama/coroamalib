/* Cleanup procedures for removing helper macros.
   Copyright (C) 2007 Free Software Foundation, Inc.
   Contributed by David Coroama (david.coroama.dev@gmail.com)

This file is designed to undefine any macros not 
intended to be used outside of the `coroamalib` library. */

#pragma once
#ifndef _COROAMALIB_EXT_CLEANUP_H_
#define _COROAMALIB_EXT_CLEANUP_H_

#ifdef _COROAMALIB_EXT_UTIL_H_
    #undef _R
    #undef _A
    #undef _T
#endif//_COROAMALIB_EXT_UTIL_H_

#ifdef _COROAMALIB_TYPES_H_
    #undef L
    #undef S
    #undef U
#endif//_COROAMALIB_TYPES_H_

#ifdef _DISABLE_TYPE_MACROS
    #undef _DISABLE_TYPE_MACROS
#endif//_DISABLE_TYPE_MACROS

#endif //_COROAMALIB_EXT_CLEANUP_H_