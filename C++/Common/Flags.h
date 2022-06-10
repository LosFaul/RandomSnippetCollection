#include "Defines.h"

union Flags8 {
	u8 data;
	struct {
		u8
			bit1 : 1, bit2 : 1, bit3 : 1, bit4 : 1, bit5 : 1, bit6 : 1, bit7 : 1, bit8 : 1;
	};
};


union Flags16 {
	u16 data;
	struct {
		u16
			bit1 : 1, bit2 : 1, bit3 : 1, bit4 : 1, bit5 : 1, bit6 : 1, bit7 : 1, bit8 : 1,
			bit9 : 1, bit10 : 1, bit11 : 1, bit12 : 1, bit13 : 1, bit14 : 1, bit15 : 1, bit16 : 1;
	};
};


union Flags32 {
	u32 data;
	struct {
		u32
			bit1 : 1, bit2 : 1, bit3 : 1, bit4 : 1, bit5 : 1, bit6 : 1, bit7 : 1, bit8 : 1,
			bit9 : 1, bit10 : 1, bit11 : 1, bit12 : 1, bit13 : 1, bit14 : 1, bit15 : 1, bit16 : 1,
			bit17 : 1, bit18 : 1, bit19 : 1, bit20 : 1, bit21 : 1, bit22 : 1, bit23 : 1, bit24 : 1,
			bit25 : 1, bit26 : 1, bit27 : 1, bit28 : 1, bit29 : 1, bit30 : 1, bit31 : 1, bit32 : 1;
	};
};


union Flags64 {
	u64 data;
	struct {
		u64
			bit1 : 1, bit2 : 1, bit3 : 1, bit4 : 1, bit5 : 1, bit6 : 1, bit7 : 1, bit8 : 1,
			bit9 : 1, bit10 : 1, bit11 : 1, bit12 : 1, bit13 : 1, bit14 : 1, bit15 : 1, bit16 : 1,
			bit17 : 1, bit18 : 1, bit19 : 1, bit20 : 1, bit21 : 1, bit22 : 1, bit23 : 1, bit24 : 1,
			bit25 : 1, bit26 : 1, bit27 : 1, bit28 : 1, bit29 : 1, bit30 : 1, bit31 : 1, bit32 : 1,
			bit33 : 1, bit34 : 1, bit35 : 1, bit36 : 1, bit37 : 1, bit38 : 1, bit39 : 1, bit40 : 1,
			bit41 : 1, bit42 : 1, bit43 : 1, bit44 : 1, bit45 : 1, bit46 : 1, bit47 : 1, bit48 : 1,
			bit49 : 1, bit50 : 1, bit51 : 1, bit52 : 1, bit53 : 1, bit54 : 1, bit55 : 1, bit56 : 1,
			bit57 : 1, bit58 : 1, bit59 : 1, bit60 : 1, bit61 : 1, bit62 : 1, bit63 : 1, bit64 : 1;
	};
};
