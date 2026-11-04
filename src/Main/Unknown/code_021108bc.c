#include "Main/Unknown/code_020c70ec.h"
#include "Main/Unknown/code_02108e38.h"
#include "Main/Unknown/code_0210d590.h"
#include "Main/Unknown/code_021108bc.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02108000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020c7000.h"
#include "Main/Unknown/code_0210d000.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_021059e0.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"

void func_02111024(void) {
    s32 a;
    s32 b;
    s32 t;
    u32 c;
    u32 *q;
    if (data_0217d324 == 0) {
        return;
    }
    if (data_0217d070.mUnk_0c != NULL) {
        return;
    }
    a = func_02110e58();
    t = (a == 2) ? 0x91 : 0x82;
    b = data_0217d320 + 1;
    data_0217d320 = b;
    if (b <= t) {
        return;
    }
    if (data_0217d328 == 0) {
        return;
    }
    q = data_0217d32c.mUnk_08;
    c = 0xff;
    switch (a) {
        case 0:
        case 1:
            c = q[3];
            break;
        case 2:
            c = q[4];
            break;
    }
    func_0210d614(&data_0217d070, c, NULL);
    data_0217d328 = 0;
    data_0217d324 = 0;
    data_0217d320 = 0;
}

s32 func_02110fb8(s32 a) {
    s32 b;
    b = 0xb;
    if (a == 1) {
        b = 9;
    } else {
        switch (data_021759c0->mKartCount) {
            case 4:
            case 5:
                if (a < 3) {
                    b = 0xa;
                }
                break;
            case 6:
            case 7:
            case 8:
                if (a < 4) {
                    b = 0xa;
                }
                break;
        }
    }
    return b;
}

s32 func_02110e58(void) {
    s32 a;
    s32 b;
    Unk021759c0 *p;
    a = -1;
    p = data_021759c0;
    switch (p->mUnk_08) {
        case 0:
        case 5:
            switch (data_0217d32c.mUnk_0c) {
                case 0:
                    if (func_0203c8dc((u16) p->mEntryIndex) - 1 == 0) {
                        b = 0;
                    } else {
                        b = 1;
                    }
                    break;
                case 1:
                case 2:
                    b = 2;
                    break;
            }
            a = b;
            break;
        case 3:
            if (p->mUnk_1c == 1) {
                a = (data_0217d32c.mUnk_0c == 0) ? 0 : 2;
            } else {
                switch (data_0217d32c.mUnk_0c) {
                    case 0:
                        if (func_0203c8dc((u16) p->mEntryIndex) - 1 == 0) {
                            b = 0;
                        } else {
                            b = 1;
                        }
                        break;
                    case 1:
                    case 2:
                        b = 2;
                        break;
                }
                a = b;
            }
            break;
        case 4:
            a = (data_0217d32c.mUnk_0c == 0) ? 0 : 2;
            break;
        case 2:
            a = (data_0217d32c.mUnk_0c == 0) ? 0 : 2;
            break;
        case 1:
            a = (data_0217d32c.mUnk_0c == 0) ? 1 : 2;
            if (a == func_020c7108()) {
                a = 0;
            }
            break;
    }
    return a;
}

void func_02110cc8(s32 d) {
    s32 a;
    s32 b;
    u32 c;
    u32 *q;
    a = -1;
    c = data_021759c0->mUnk_00c;
    if (c != 2 && c != 0) {
        return;
    }
    if (data_0217d084.mUnk_04 != 2) {
        return;
    }
    func_02106c64();
    b = func_02110e58();
    q = data_0217d32c.mUnk_08;
    c = 0xff;
    switch (b) {
        case 0:
            c = q[0];
            break;
        case 1:
            c = q[1];
            break;
        case 2:
            c = q[2];
            break;
    }
    func_0210d614(&data_0217d070, c, NULL);
    data_0217d324 = 1;
    data_0217d328 = 1;
    switch (data_021759c0->mCourseId) {
        case 0x22:
            switch (b) {
                case 0:
                case 1:
                    a = 0x1bd;
                    break;
                default:
                    a = 0x1be;
                    break;
            }
            break;
        case 0x14:
            switch (b) {
                case 0:
                case 1:
                    a = 0x105;
                    break;
                default:
                    a = 0x106;
                    break;
            }
            break;
        case 0x19:
            switch (b) {
                case 0:
                case 1:
                    a = 0x19d;
                    break;
                default:
                    a = 0x19e;
                    break;
            }
            break;
    }
    if (a <= -1) {
        return;
    }
    func_02108e38();
    func_0212ecc0(&data_0217d068, 0, (u16) a);
}

s32 func_02110c40(void) {
    s32 a;
    s32 b;
    b = func_02110e58();
    a = -1;
    switch (data_021759c0->mCourseId) {
        case 0x14:
            switch (b) {
                case 0:
                case 1:
                    a = 0x104;
                    break;
                default:
                    a = 0x107;
                    break;
            }
            break;
        case 0x19:
            switch (b) {
                case 0:
                case 1:
                    a = 0x19c;
                    break;
                default:
                    a = 0x19f;
                    break;
            }
            break;
    }
    return a;
}

// Releases the object when it holds nothing other than the given value, otherwise sets it up with that value.
static inline void func_02110aac_inline(Unk0212c400 **p, u32 v) {
    Unk0212c400 *q;
    u32 r;
    if (v != 0xffff) {
        q = *p;
        if (q != NULL && q->mUnk_3a == v && q->mUnk_38 == 0) {
            r = 1;
        } else {
            r = 0;
        }
        if (r == 0) {
            func_0212c6f0(p, 0);
            if (*p != NULL) {
                func_0212c6f0(p, 0);
            }
            func_0212ecc0(p, 0, v);
        }
    } else if (*p != NULL) {
        func_0212c6f0(p, 0);
    }
}

void func_02110aac(s32 a, s32 b) {
    Unk0212c400 **p;
    u32 x;
    u32 y;
    p = func_02108e6c(1);
    if (a == 0) {
        x = 0x1ff;
    } else if (a == 1) {
        x = 0x200;
    } else {
        x = 0xffff;
    }
    func_02110aac_inline(p, x);
    p = func_02108e6c(2);
    y = (b != 0) ? 0x201 : 0xffff;
    if (x != 0xffff) {
        y = 0xffff;
    }
    func_02110aac_inline(p, y);
}

void func_02110a60(void) {
    data_0217d204 = 0;
    data_0217d1e0 = 0;
    data_0217d1e4 = 0;
    data_0217d1f4 = 7;
}

void func_021108bc(s32 a) {
    s32 b;
    s32 c;
    u8 m;
    u32 n;
    Unk0212c400 **p;
    if (a <= 2) {
        b = 0x1f7;
    } else if (a <= 5) {
        b = 0x1f8;
    } else {
        b = -1;
    }
    m = data_0217d1e4 + 1;
    n = data_0217d204 + 1;
    data_0217d1e4 = m;
    data_0217d204 = n;
    if (b == -1) {
        return;
    }
    if (n < 2) {
        return;
    }
    p = func_02108e6c((data_0217d1e0 & 1) ? 2 : 3);
    if (data_0217d204 >= 0x14) {
        data_0217d1e4 = 0;
    }
    if (*p != NULL) {
        func_0212c6f0(p, 0);
    }
    func_0212ecc0(p, 0, (u16) b);
    data_0217d1e0 = data_0217d1e0 + 1;
    if (p != NULL) {
        switch (data_0217d1e4 % 3) {
            case 0:
                c = 0;
                break;
            case 1:
                c = (a <= 2) ? 0x40 : -0x40;
                break;
            case 2:
                c = (a <= 2) ? 0x80 : -0x80;
                break;
        }
        if (a == 1 || a == 4) {
            c -= 0x100;
        } else if (a == 2 || a == 5) {
            c -= 0x200;
        }
        func_02105b0c(p, c);
    }
    data_0217d204 = 0;
}
