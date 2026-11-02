#include "Main/Unknown/code_02121e84.h"
#include "00/code_0219b000.h"
#include "00/code_021a2000.h"
#include "00/code_021a3000.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_0214d000.h"

#pragma opt_arithtransformation off

void func_02122728(void) {
    func_02122684();
}

void func_02122684(void) {
    u8 i;
    s8 a = 0;
    u8 t;
    for (i = 0; i < 4; i++) {
        if (i < data_0217d384->mUnk_1f53) {
            if ((data_0217d384->mUnk_1f55 & (1 << i)) == 0) {
                data_0217d384->mUnk_1f4e[i] = -1;
            } else {
                t = data_0217d384->mUnk_1f4e[i];
                data_0217d384->mUnk_1f4e[i] = a;
                a++;
                func_0205d0e8(t, data_0217d384->mUnk_1f4e[i]);
            }
        } else {
            data_0217d384->mUnk_1f4e[i] = -1;
        }
    }
}

BOOL func_021225ac(u32 a) {
    s32 n;
    s32 s;
    n = data_0217d384->mUnk_1980;
    data_0217d384->mUnk_1980 = n + 1;
    if (n > a) {
        data_0217d384->mUnk_1980 = 0;
        s = data_0217d384->mUnk_1950;
        if (s == 0 || s == 1 || s == 2) {
            data_0217d384->mUnk_194e = 1;
            func_ov000_021a2ccc();
            func_ov000_0219bbfc();
            data_0217d384->mUnk_1950 = 11;
        } else {
            if (s == 9 || s == 10) {
                return TRUE;
            }
            data_0217d384->mUnk_19ad = 1;
            func_ov000_021a2ccc();
            func_ov000_0219bbfc();
            data_0217d384->mUnk_1950 = 11;
        }
        return TRUE;
    }
    return FALSE;
}

static inline BOOL func_02121f4c_inline(const Unk0217d384_1d00 *p, u32 a, u32 c, u8 n) {
    if (p->mUnk_00 < 10) {
        if (p->mUnk_04 == c) {
            if (p->mUnk_08 == a) {
                if (p->mUnk_09 == n) {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

void func_02121f4c(u32 a, void *b, u32 c) {
    Unk0217d384_1d00 *p;
    u8 n;
    p = b;
    if (data_0217d384->mUnk_1950 >= 5 && (data_0217d384->mUnk_1f55 & (1 << a)) == 0) {
        return;
    }
    data_0217d384->mUnk_1984[a] = 0;
    n = func_ov000_0219bb50();
    if (func_02121f4c_inline(p, a, c, n) == FALSE) {
        return;
    }
    if (func_021217e8(p->mUnk_00) == 0) {
        return;
    }
    switch (p->mUnk_00) {
        case 0:
            data_0217d384->mUnk_19aa |= 1 << a;
            break;
        case 1:
            data_0217d384->mUnk_19ab |= 1 << a;
            func_ov000_021a3264(a, &data_0217d384->mUnk_1d00[a], 0x44);
            break;
        case 2:
            if (data_0217d384->mUnk_1950 == 1) {
                data_0217d384->mUnk_19ab |= 1 << a;
            }
            break;
        case 8:
            if (data_0217d384->mUnk_1950 != 3) {
                return;
            }
            if (p->mUnk_40 == 0) {
                return;
            }
            func_0214d1fc(&data_0217d384->mUnk_1d00[a], &data_0217d384->mUnk_1e10[a], 0x44);
            data_0217d384->mUnk_19ab |= 1 << a;
            break;
        case 9:
            if (data_0217d384->mUnk_1950 == 3) {
                func_0214d1fc(&data_0217d384->mUnk_1d00[a], &data_0217d384->mUnk_1e10[a], 0x44);
                data_0217d384->mUnk_19ab |= 1 << a;
            } else if (data_0217d384->mUnk_1950 == 4) {
                func_0214d1fc(&data_0217d384->mUnk_1d00[a], &data_0217d384->mUnk_1e10[a], 0x44);
                data_0217d384->mUnk_19ab |= 1 << a;
            }
            break;
        case 3:
            if (data_0217d384->mUnk_1950 == 1) {
                func_0214d1fc(&data_0217d384->mUnk_1d00[a], &data_0217d384->mUnk_1e10[a], 0x44);
                data_0217d384->mUnk_19ab = 0xff;
            } else if (data_0217d384->mUnk_1950 == 5) {
                func_0214d1fc(&data_0217d384->mUnk_1d00[a], &data_0217d384->mUnk_1e10[a], 0x44);
                if (p->mUnk_30 == -1) {
                    return;
                }
                if (p->mUnk_34 == -1) {
                    return;
                }
                data_0217d384->mUnk_19ab |= 1 << a;
            } else if (data_0217d384->mUnk_1950 == 4) {
                func_0214d1fc(&data_0217d384->mUnk_1d00[a], &data_0217d384->mUnk_1e10[a], 0x44);
                data_0217d384->mUnk_19ab = 0xff;
            }
            break;
        case 4:
            if (data_0217d384->mUnk_1950 == 5) {
                func_0214d1fc(&data_0217d384->mUnk_1d00[a], &data_0217d384->mUnk_1e10[a], 0x44);
                data_0217d384->mUnk_19ab |= 1 << a;
            } else if (data_0217d384->mUnk_1950 == 6) {
                func_0214d1fc(&data_0217d384->mUnk_1d00[a], &data_0217d384->mUnk_1e10[a], 0x44);
                data_0217d384->mUnk_19ab |= 1 << a;
            }
            break;
        case 5:
            if (data_0217d384->mUnk_1950 == 6) {
                func_0214d1fc(&data_0217d384->mUnk_1d00[a], &data_0217d384->mUnk_1e10[a], 0x44);
                data_0217d384->mUnk_19ab = 0xff;
            } else if (data_0217d384->mUnk_1950 == 7) {
                if (p->mUnk_38 == 0) {
                    return;
                }
                func_0214d1fc(&data_0217d384->mUnk_1d00[a], &data_0217d384->mUnk_1e10[a], 0x44);
                data_0217d384->mUnk_19ab |= 1 << a;
            }
            break;
        case 6:
            if (data_0217d384->mUnk_1950 == 7) {
                func_0214d1fc(&data_0217d384->mUnk_1d00[a], &data_0217d384->mUnk_1e10[a], 0x44);
                data_0217d384->mUnk_19ab |= 1 << a;
            } else if (data_0217d384->mUnk_1950 == 8) {
                func_0214d1fc(&data_0217d384->mUnk_1d00[a], &data_0217d384->mUnk_1e10[a], 0x44);
                data_0217d384->mUnk_19ab |= 1 << a;
            }
            break;
        case 7:
            if (data_0217d384->mUnk_1950 == 8) {
                func_0214d1fc(&data_0217d384->mUnk_1d00[a], &data_0217d384->mUnk_1e10[a], 0x44);
                data_0217d384->mUnk_19ab |= 1 << a;
            } else if (data_0217d384->mUnk_1950 == 9) {
                func_0214d1fc(&data_0217d384->mUnk_1d00[a], &data_0217d384->mUnk_1e10[a], 0x44);
                func_0212145c(a);
                data_0217d384->mUnk_19ab |= 1 << a;
            }
            break;
    }
}

void func_02121f1c(s32 a) {
    data_0217d384->mUnk_1e10[func_ov000_0219bb50()].mUnk_30 = a;
}

void func_02121ee4(void) {
    data_0217d384->mUnk_1e10[func_ov000_0219bb50()].mUnk_30 = -1;
}

void func_02121eb4(s32 a) {
    data_0217d384->mUnk_1e10[func_ov000_0219bb50()].mUnk_34 = a;
}

void func_02121e84(s32 a) {
    data_0217d384->mUnk_1e10[func_ov000_0219bb50()].mUnk_38 = a;
}
