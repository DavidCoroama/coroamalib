/* Null functions for different parts of the `coroamalib` library.
   Copyright (C) 2007 Free Software Foundation, Inc.
   Contributed by David Coroama (david.coroama.dev@gmail.com) */

#ifndef _COROAMALIB_NULL_API_H_
#define _COROAMALIB_NULL_API_H_

#include <stdbool.h>

#define Null(x) __ ## x ## _NULL_API

#ifdef __cplusplus
extern "C" {
#endif//__cplusplus

#ifdef _COROAMALIB_DYNAMIC_INDEX_H_
    #define __dynidx_NULL_API   dynidx_null()
    #define __DYNIDX_NULL_API   dynidx_null()
    #define __dynidx_t_NULL_API dynidx_null()
    #define __DYNIDX_T_NULL_API dynidx_null()

    dynidx_t dynidx_null() {
        dynidx_t __o = {
            .next_size = 0,
            .grow_rate = 0,
            .size = 0,
            .index = 0,
            .block = (size_t*)NULL
        };

        return __o;
    }

    bool is_dynidx_null(dynidx_t* _Ptr) {
        return _Ptr->block == (size_t*)NULL;
    }
#endif//_COROAMALIB_DYNAMIC_INDEX_H_

#ifdef __cplusplus
}
#endif//__cplusplus

#endif//_COROAMALIB_NULL_API_H_