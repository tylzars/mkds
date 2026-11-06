#include "code_02148538.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_02161000.h"

// Angle of the point (x, y) as a 16-bit angle index, using the arctangent table. Returns 0 when both are 0.
u16 FX_Atan2Idx(s32 y, s32 x) {
    s32 small;
    s32 large;
    s32 base;
    s32 add;

    if (y > 0) {
        if (x > 0) {
            if (x > y) {
                small = y;
                large = x;
                base = 0;
                add = 1;
            } else if (x < y) {
                small = x;
                large = y;
                base = 0x4000;
                add = 0;
            } else {
                return 0x2000;
            }
        } else if (x < 0) {
            x = -x;
            if (x < y) {
                small = x;
                large = y;
                base = 0x4000;
                add = 1;
            } else if (x > y) {
                small = y;
                large = x;
                base = 0x8000;
                add = 0;
            } else {
                return 0x6000;
            }
        } else {
            return 0x4000;
        }
    } else if (y < 0) {
        y = -y;
        if (x < 0) {
            x = -x;
            if (x > y) {
                small = y;
                large = x;
                base = -0x8000;
                add = 1;
            } else if (x < y) {
                small = x;
                large = y;
                base = -0x4000;
                add = 0;
            } else {
                return 0xa000;
            }
        } else if (x > 0) {
            if (x < y) {
                small = x;
                large = y;
                base = -0x4000;
                add = 1;
            } else if (x > y) {
                base = 0;
                small = y;
                large = x;
                add = base;
            } else {
                return 0xe000;
            }
        } else {
            return 0xc000;
        }
    } else {
        if (x >= 0) {
            return 0;
        }
        return 0x8000;
    }
    if (large == 0) {
        return 0;
    }
    if (add != 0) {
        return base + data_021615b8[FX_Div(small, large) >> 5];
    }
    return base - data_021615b8[FX_Div(small, large) >> 5];
}

// Angle of the point (x, y) in radians with 12 fractional bits, using the arctangent table. Returns 0 when both are 0.
s16 FX_Atan2(s32 y, s32 x) {
    s32 small;
    s32 large;
    s32 base;
    s32 add;

    if (y > 0) {
        if (x > 0) {
            if (x > y) {
                small = y;
                large = x;
                base = 0;
                add = 1;
            } else if (x < y) {
                small = x;
                large = y;
                base = 0x1922;
                add = 0;
            } else {
                return 0xc91;
            }
        } else if (x < 0) {
            x = -x;
            if (x < y) {
                small = x;
                large = y;
                base = 0x1922;
                add = 1;
            } else if (x > y) {
                small = y;
                large = x;
                base = 0x3244;
                add = 0;
            } else {
                return 0x25b3;
            }
        } else {
            return 0x1922;
        }
    } else if (y < 0) {
        y = -y;
        if (x < 0) {
            x = -x;
            if (x > y) {
                small = y;
                large = x;
                base = -0x3244;
                add = 1;
            } else if (x < y) {
                small = x;
                large = y;
                base = -0x1922;
                add = 0;
            } else {
                return -0x25b3;
            }
        } else if (x > 0) {
            if (x < y) {
                small = x;
                large = y;
                base = -0x1922;
                add = 1;
            } else if (x > y) {
                base = 0;
                small = y;
                large = x;
                add = base;
            } else {
                return -0xc91;
            }
        } else {
            return -0x1922;
        }
    } else {
        if (x >= 0) {
            return 0;
        }
        return 0x3244;
    }
    if (large == 0) {
        return 0;
    }
    if (add != 0) {
        return base + data_021614b4[FX_Div(small, large) >> 5];
    }
    return base - data_021614b4[FX_Div(small, large) >> 5];
}
