/* Dynamic index functions.
   Copyright (C) 2007 Free Software Foundation, Inc.
   Contributed by David Coroama (david.coroama.dev@gmail.com)

This file contains the function declarations for manipulating, 
creating, and safely destroying the dynamic index structure.

The dynamic index structure is used for creating a growable array 
of 'size_t' indexes. It works similarly to a list, being able to 
allocate enough memory dynamically for new elements added.

The array operates on the LILO (Last In, Last Out) 
principle, meaning that the last index pushed in is 
also the last one to be removed. */

#pragma once
#ifndef _COROAMALIB_DYNAMIC_INDEX_H_
#define _COROAMALIB_DYNAMIC_INDEX_H_

#include <coroama/ext/util.h>

#define _DISABLE_TYPE_MACROS
#include <coroama/types.h>

#ifdef __cplusplus
extern "C" {
#endif//__cplusplus

_T(struct) dynamic_index {
    /* The next size to be allocated if the index exceeds the current size. */
    size_t  next_size;
    /* The rate at which the size increases. */
    size_t  grow_rate;
    /* The current memory size, calculated as 'sizeof(size_t)' times the growth rate. */
    size_t  size;
    /* Points to the last filled slot. */
    size_t  index;
    /* The block of memory where all the indexes are stored. */
    size_t* block;
} dynidx_t;

dynidx_t dynidx_null();
bool     is_dynidx_null(dynidx_t*);

dynidx_t dynidx_new();
dynidx_t dynidx_new_ex(size_t, size_t);
void     dynidx_free(dynidx_t*);

bool     dynidx_push(dynidx_t*, size_t);
void     dynidx_pop(dynidx_t*, size_t*);
size_t   dynidx_last(dynidx_t*);

static bool _dynidx_reserve(dynidx_t*);

#include <stdlib.h>

#ifdef __cplusplus
}
#endif//__cplusplus

#include <coroama/ext/cleanup.h>

#endif //_COROAMALIB_DYNAMIC_INDEX_H_