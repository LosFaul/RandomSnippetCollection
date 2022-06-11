#pragma once
#include "Common/Defines.h"

// includes STL
#include <numeric>
#include <algorithm>


class IdPool {
	// 0x0100'0000 | 194 MegaBytes | 16.7 Million IDs
	// 0x0200'0000 | 388 MegaBytes | 33.5 Million IDs 
	// 0x0300'0000 | 582 MegaBytes | 50.3 Million IDs
	// 0x0400'0000 | 776 MegaBytes | 67.1 Million IDs
	static constexpr u32 pool_size{ 0x0100'0000 };

	static constexpr u8 bit_mask[] = {
		0b0000'0001, // 0x01 |   1
		0b0000'0010, // 0x02 |   2
		0b0000'0100, // 0x04 |   4
		0b0000'1000, // 0x08 |   8
		0b0001'0000, // 0x10 |  16
		0b0010'0000, // 0x20 |  32
		0b0100'0000, // 0x40 |  64
		0b1000'0000, // 0x80 | 128
	};


	u32 pool_pointer{ 0 };
	u32 id_pool[pool_size];
	u8 id_used[pool_size / 8 + 1];

	// Userdata for ID
	u64 id_userdata[pool_size];


public:

	static constexpr u32 invalid = -1;


	inline void init() {
		std::iota(id_pool, &id_pool[pool_size], 0);
		std::fill_n(id_used, sizeof(id_used), 0);
		std::fill_n(id_userdata, pool_size, 0);
	}


	inline u32 getFreeCount() {
		return pool_size - pool_pointer;
	}


	// if failed to acquire ID returns IdPool::invalid
	inline u32 acquire() {
		if (pool_pointer < pool_size) {
			u32 id = id_pool[pool_pointer++];
			u32 used_index = id / 8;
			u32 bit_index = id % 8;
			id_used[used_index] += bit_mask[bit_index]; // acquire set
			return id;
		}
		return invalid;
	}


	inline void release(u32 id) {
		if (pool_pointer && isUsed(id)) {
			id_pool[--pool_pointer] = id;
			u32 used_index = id / 8;
			u32 bit_index = id % 8;
			id_used[used_index] -= bit_mask[bit_index]; // release set

			id_userdata[id] = 0;
		}
	}


	inline bool isUsed(u32 id) {
		u32 used_index = id / 8;
		u32 bit_index = id % 8;
		return id_used[used_index] & bit_mask[bit_index];
	}


	inline void setUserdata(u32 id, u64 data) {
		id_userdata[id] = data;
	}


	inline u64 getUserdata(u32 id) {
		return id_userdata[id];
	}


	/* Optimization Experiments */
	/*
		----------------------------------------------------------------
		// Get used_index
		u32 used_index = id / 8;
		VS
		u32 used_index = id >> 3;
		----------------------------------------------------------------
		// Get bit_index
		u32 bit_index = id % 8;
		VS
		u32 bit_index = id & 0b111; // or '& 7'
		----------------------------------------------------------------
		// Get bit_index value
		static constexpr u8 bit_mask[] = {
			0b0000'0001, // 0x01 |   1
			0b0000'0010, // 0x02 |   2
			0b0000'0100, // 0x04 |   4
			0b0000'1000, // 0x08 |   8
			0b0001'0000, // 0x10 |  16
			0b0010'0000, // 0x20 |  32
			0b0100'0000, // 0x40 |  64
			0b1000'0000, // 0x80 | 128
		};
		u8 bit_value = bit_mask[bitIndex];
		VS
		u8 bit_value = u8(1 << bitIndex);
		----------------------------------------------------------------
		// Acquire set Bit
		id_used[used_index] |= bitValue;
		VS
		id_used[used_index] += bitValue;
		----------------------------------------------------------------
		// Release set Bit
		id_used[used_index] -= bitValue;
		VS
		no alternative yet
		----------------------------------------------------------------
	*/
};
