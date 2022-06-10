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
        std::iota(pool, &pool[poolSize], 0);
    }


    inline u32 getFreeIdCount() {
        return poolSize - pointer;
    }                    

                                  
    inline u32 getFreeIdCount() {
        return poolSize - pointer;
    }        
                                  
                                  
    inline u32 acquire() {
        return pool[pointer++];
    }
                                  
                                  
    inline void release(u32 id) {
        pool[--pointer] = id;
    }
                                                                   
}
    
   
