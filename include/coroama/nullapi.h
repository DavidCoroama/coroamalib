/* Null functions for different parts of the `coroamalib` library.
   Copyright (C) 2007 Free Software Foundation, Inc.
   Contributed by David Coroama (david.coroama.dev@gmail.com) */

#pragma once
#ifndef _COROAMALIB_NULL_API_H_
#define _COROAMALIB_NULL_API_H_

#define Null(x) __ ## x ## _NULL_API

#define NULL_DECL_API_(n)  _NULL_API_DECL_  ## n
#define NULL_CHECK_API_(n) _NULL_API_CHECK_ ## n

#ifdef _COROAMALIB_DYNAMIC_INDEX_H_
    #define _NULL_API_DECL_dynidx  dynidx_t dynidx_null
    #define _NULL_API_CHECK_dynidx bool is_dynidx_null
    
    #define __dynidx_NULL_API   dynidx_null()
    #define __DYNIDX_NULL_API   dynidx_null()
    #define __dynidx_t_NULL_API dynidx_null()
    #define __DYNIDX_T_NULL_API dynidx_null()
#endif//_COROAMALIB_DYNAMIC_INDEX_H_

#endif//_COROAMALIB_NULL_API_H_