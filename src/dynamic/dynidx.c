#include <coroama/dynamic/dynidx.h>
#include <coroama/shorthands.h>
#include <coroama/nullapi.h>

#include <stdlib.h>

dynidx_t dynidx_new() {
    return dynidx_new_ex(4, 4);
}

dynidx_t dynidx_new_ex(size_t _BaseSize, size_t _GrowRate) {
    dynidx_t __o = {
        .next_size = _BaseSize + _GrowRate,
        .grow_rate = _GrowRate,
        .size = _BaseSize,
        .index = 0,
        .block = MALLOC(size_t, _GrowRate)
    };

    if(is_dynidx_null(&__o)) {
        return Null(dynidx);
    }

    return __o;
}

void dynidx_free(dynidx_t* _Ptr) {
    if(!is_dynidx_null(_Ptr)) {
        free(_Ptr->block);
        _Ptr->block = (size_t*)NULL;
    }
}

bool dynidx_push(dynidx_t* _Ptr, size_t _Value) {
    if(!_dynidx_reserve(_Ptr)) {
        return false;
    }

    _Ptr->index++;
    _Ptr->block[_Ptr->index] = _Value;

    return true;
}

void dynidx_pop(dynidx_t* _Ptr, size_t* _Out) {
    if(!_dynidx_reserve(_Ptr)) {
        _Out = (size_t*)NULL;
        return;
    }

    if(_Out != (size_t*)NULL) {
        *_Out = _Ptr->block[_Ptr->index];
    }

    *(_Ptr->block + _Ptr->index) = 0;
    _Ptr->index--;
}

size_t dynidx_last(dynidx_t* _Ptr) {
    if(_Ptr->index == 0) {
        return 0;
    }

    return _Ptr->block[_Ptr->index];
}

static bool _dynidx_reserve(dynidx_t* _Ptr) {
    if(is_dynidx_null(_Ptr)) {
        return false;
    }

    if(_Ptr->index + 1 > _Ptr->size) {
        VARREALLOC(block, _Ptr->block, size_t, _Ptr->next_size);

        if(block == (size_t*)NULL) {
            return false;
        }

        _Ptr->block = block;
        _Ptr->size = _Ptr->next_size;
        _Ptr->next_size += _Ptr->grow_rate;
    }

    return true;
}