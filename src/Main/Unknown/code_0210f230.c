#include "Main/Unknown/code_0210f230.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02108e38.h"

#include "Main/Unknown/code_02108000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_0210f208.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"

u32 data_0216cb4c = 0xffff;
Unk0216cb50 data_0216cb50[5] = {
    {{0x01b1, 0x01b2, 0x01b3, 0x01b4, 0x01b5, 0xffff, 0xffff, 0xffff}},
    {{0x1000, 0x1001, 0x1002, 0x1003, 0x0198, 0x0197, 0xffff, 0xffff}},
    {{0x1000, 0x1001, 0x1002, 0x1003, 0x01ab, 0xffff, 0xffff, 0xffff}},
    {{0x01cc, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff}},
    {{0x01c2, 0x01c3, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff}},
};

void func_0210f5d4(u32 a) {
    u32 v;
    s32 j;
    s32 i;
    u32 t;
    u32 w;

    v = 0xffff;
    switch (a) {
        case 0x1d:
            v = 0;
            break;
        case 0x1c:
            v = 1;
            break;
        case 0x20:
            v = 2;
            break;
        case 0x21:
            v = 3;
            break;
        case 0x22:
            v = 4;
            break;
    }
    data_0216cb4c = v;
    if (v != 0xffff) {
        j = 0;
        func_0210f208((Unk0217d1c0 *) data_0217d1c0, 3, j);
        func_0210f208((Unk0217d1c0 *) data_0217d1d0, 3, j);
        for (; j < 2; j++) {
            w = (j == 0 ? 0x1000 : 0x2000);
            for (i = 0; i < 8; i++) {
                if (data_0216cb50[v].mUnk_00[i] == w) {
                    func_0210f208(&((Unk0217d1c0 *) data_0217d1c0)[j], 0, i);
                    break;
                }
            }
        }
    }
    t = 0;
    if (v == 1 && data_021759c0->mMode != MODE_MISSION_RUN) {
        t = 3;
    }
    ((Unk0217d1c0 *) data_0217d1c0)[0].mUnk_04 = t;
    ((Unk0217d1c0 *) data_0217d1c0)[0].mUnk_00 = t;
}

void func_0210f458(s32 a) {
    u16 v;
    u16 w;
    u16 n;
    Unk0212c400 **p;

    v = data_0216cb50[data_0216cb4c].mUnk_00[a];
    w = v & 0xfff;
    switch (data_0216cb4c) {
        case 3:
            if (v == 0x1cc) {
                p = (Unk0212c400 **) func_02108e88();
                if (*p != NULL) {
                    func_0212c6f0(p, 0);
                }
                p = func_02108e6c(7);
                if (*p != NULL) {
                    func_0212c6f0(p, 0);
                }
            };
            break;
        case 4:
            func_02108e38();
            break;
    }
    if (v < 0xfff) {
        p = func_02108e6c(a < 5 ? a + 7 : a + 2);
        if ((data_0217c780 & 1) == 0) {
            return;
        }
        if (data_0217d084.mUnk_0c == 0) {
            return;
        }
        if (*p != NULL) {
            func_0212c6f0(p, 0);
        }
        if (*p != NULL) {
            func_0212c6f0(p, 0);
        }
        func_0212ecc0(p, 0, v);
        return;
    }
    if (w >= 4) {
        return;
    }
    n = (u16) (((v & 0xf000) >> 12) - 1);
    a = a - ((Unk0217d1c8 *) data_0217d1c8)[n].mUnk_00;
    ((Unk0217d1c4 *) data_0217d1c4)[n].mUnk_00 = ((Unk0217d1c0 *) data_0217d1c0)[n].mUnk_00;
    ((Unk0217d1c0 *) data_0217d1c0)[n].mUnk_00 = a;
}

u32 func_0210f35c(s32 a, u32 b) {
    Unk0212c400 **p;
    u32 v;
    u8 c;
    u32 ok;

    if (a == 0) {
        p = func_02108e6c(0xa);
    } else {
        p = func_02108e6c(0xb);
    }
    v = ((Unk0217d1c0 *) data_0217d1c0)[a].mUnk_00;
    if (v == 0) {
        c = 0;
        ok = 0;
    } else {
        c = ((Unk0217d1cc *) data_0217d1cc)[a].mUnk_00[v - 1];
        ok = 1;
    }
    if (ok != 0) {
        if ((data_0217c780 & 1) != 0) {
            if (data_0217d084.mUnk_0c != 0) {
                if (*p != NULL) {
                    func_0212c6f0(p, 0);
                }
                if (*p != NULL) {
                    func_0212c6f0(p, 0);
                }
                func_0212ecc0(p, 0, b);
            }
        }
        if (*p != NULL) {
            func_02105b28(p, c);
        }
    }
    return ok;
}

u32 func_0210f230(u32 a, u32 b) {
    Unk0212c400 **p;
    u32 v;
    u8 c;
    u32 ok;

    if (a == 0) {
        p = func_02108e6c(0xa);
    } else {
        p = func_02108e6c(0xb);
    }
    v = ((Unk0217d1c0 *) data_0217d1c0)[a].mUnk_00;
    if (v == 0) {
        c = 0;
        ok = 0;
    } else {
        c = ((Unk0217d1cc *) data_0217d1cc)[a].mUnk_00[v - 1];
        ok = 1;
    }
    if (ok != 0) {
        if (*p == NULL) {
            if ((data_0217c780 & 1) != 0) {
                if (data_0217d084.mUnk_0c != 0) {
                    if (*p != NULL) {
                        func_0212c6f0(p, 0);
                    }
                    if (*p != NULL) {
                        func_0212c6f0(p, 0);
                    }
                    func_0212ecc0(p, 0, b);
                }
            }
            func_02105b28(p, c);
        } else if (*p != NULL && ((Unk0217d1c4 *) data_0217d1c4)[a].mUnk_00 != v) {
            func_02105b28(p, c);
        }
    } else {
        func_0212c6f0(p, 0xa);
    }
    return ok;
}
