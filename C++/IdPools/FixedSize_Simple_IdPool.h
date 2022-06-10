#pragma once

#include "Common/Defines.h"

// includes STL
#include <numeric>


class FixedSize_Simple_IdPool {
    static constexpr u32 poolSize{ 0xFF'FFFF };

    u32 pointer{ 0 };
    u32 pool[poolSize];

public:
    
    inline void init() {
        std::iota(id_pool, &id_pool[pool_size], 0);
        std::fill_n(id_data, pool_size, 0);
    }


    inline u32 getFreeIdCount() {
        return poolSize - pointer;
    }                    

                                  
    inline u32 getFreeIdCount() {
        return poolSize - pointer;
    }        
                                  
                                  
    inline u32 acquire() {
        return id_pool[pointer++];
    }
                                  
                                  
    inline void release(u32 id) {
        id_pool[--pointer] = id;
    }
                                                                   
}
    
   