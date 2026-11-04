#include "code_02148538.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_02161000.h"

// Returns a u16 from the signs of a and b and which magnitude is larger. Equal magnitudes and zero inputs return
// 0x2000, 0x6000, 0xa000, 0xe000, 0x4000, 0xc000, 0 or 0x8000. Otherwise the result is a base (0, 0x4000, 0x8000,
// -0x4000, -0x8000) plus or minus the s16 at index (DivFixed12(n, d) >> 5) of data_021615b8, where n and d are
// the smaller and larger magnitude. Returns 0 when d is 0.
u16 AngleFromPair(s32 a, s32 b) {
    s32 n;
    s32 d;
    s32 base;
    s32 f;

    if (a > 0) {
        if (b > 0) {
            if (b > a) {
                n = a;
                d = b;
                base = 0;
                f = 1;
            } else if (b < a) {
                n = b;
                d = a;
                base = 0x4000;
                f = 0;
            } else {
                return 0x2000;
            }
        } else if (b < 0) {
            b = -b;
            if (b < a) {
                n = b;
                d = a;
                base = 0x4000;
                f = 1;
            } else if (b > a) {
                n = a;
                d = b;
                base = 0x8000;
                f = 0;
            } else {
                return 0x6000;
            }
        } else {
            return 0x4000;
        }
    } else if (a < 0) {
        a = -a;
        if (b < 0) {
            b = -b;
            if (b > a) {
                n = a;
                d = b;
                base = -0x8000;
                f = 1;
            } else if (b < a) {
                n = b;
                d = a;
                base = -0x4000;
                f = 0;
            } else {
                return 0xa000;
            }
        } else if (b > 0) {
            if (b < a) {
                n = b;
                d = a;
                base = -0x4000;
                f = 1;
            } else if (b > a) {
                base = 0;
                n = a;
                d = b;
                f = base;
            } else {
                return 0xe000;
            }
        } else {
            return 0xc000;
        }
    } else {
        if (b >= 0) {
            return 0;
        }
        return 0x8000;
    }
    if (d == 0) {
        return 0;
    }
    if (f != 0) {
        return base + data_021615b8[DivFixed12(n, d) >> 5];
    }
    return base - data_021615b8[DivFixed12(n, d) >> 5];
}

// Same shape as AngleFromPair with the bases 0, 0x1922, 0x3244, -0x1922 and -0x3244, the constants 0xc91, 0x25b3,
// -0xc91, -0x25b3, 0x1922, -0x1922, 0 and 0x3244 for equal magnitudes and zero inputs, the table data_021614b4 and an
// s16 result.
s16 func_02148538(s32 a, s32 b) {
    s32 n;
    s32 d;
    s32 base;
    s32 f;

    if (a > 0) {
        if (b > 0) {
            if (b > a) {
                n = a;
                d = b;
                base = 0;
                f = 1;
            } else if (b < a) {
                n = b;
                d = a;
                base = 0x1922;
                f = 0;
            } else {
                return 0xc91;
            }
        } else if (b < 0) {
            b = -b;
            if (b < a) {
                n = b;
                d = a;
                base = 0x1922;
                f = 1;
            } else if (b > a) {
                n = a;
                d = b;
                base = 0x3244;
                f = 0;
            } else {
                return 0x25b3;
            }
        } else {
            return 0x1922;
        }
    } else if (a < 0) {
        a = -a;
        if (b < 0) {
            b = -b;
            if (b > a) {
                n = a;
                d = b;
                base = -0x3244;
                f = 1;
            } else if (b < a) {
                n = b;
                d = a;
                base = -0x1922;
                f = 0;
            } else {
                return -0x25b3;
            }
        } else if (b > 0) {
            if (b < a) {
                n = b;
                d = a;
                base = -0x1922;
                f = 1;
            } else if (b > a) {
                base = 0;
                n = a;
                d = b;
                f = base;
            } else {
                return -0xc91;
            }
        } else {
            return -0x1922;
        }
    } else {
        if (b >= 0) {
            return 0;
        }
        return 0x3244;
    }
    if (d == 0) {
        return 0;
    }
    if (f != 0) {
        return base + data_021614b4[DivFixed12(n, d) >> 5];
    }
    return base - data_021614b4[DivFixed12(n, d) >> 5];
}
