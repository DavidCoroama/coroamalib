#include <coroama/nullapi.h>

#ifdef _COROAMALIB_DYNAMIC_INDEX_H_
    NULL_DECL_API_(dynidx) () {
        dynidx_t __o = {
            .next_size = 0,
            .grow_rate = 0,
            .index = 0,
            .size = 0,
            .block = (size_t*)NULL
        };

        return __o;
    }

    NULL_CHECK_API_(dynidx) (dynidx_t* _Ptr) {
        return _Ptr->block == (size_t*)NULL;
    }
#endif//_COROAMALIB_DYNAMIC_INDEX_H_