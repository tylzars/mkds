#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c53c4.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b19f8.h"
#include "Main/Unknown/code_020b1cf4.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "code_020222ec.h"

void func_020c5940(void) {
    u32 b;
    s32 a;
    u16 i;
    s32 n;
    u16 x;
    s32 *q;
    Unk0217aa1c_00 *p;

    n = data_0217b3f0->mUnk_04;
    x = func_020b4d9c();
    if (data_0217561c->mUnk_000[x].mUnk_14 == 1 || data_0217561c->mUnk_4cc != 0) {
        data_0217b3f0->mUnk_00 = 0;
    }
    if (func_020b1d0c() == 0) {
        return;
    }
    if (data_021759c0->mUnk_08 == 4) {
        if ((func_0203c880((u16) data_021759c0->mUnk_62) != 0 ? data_0217561c->mUnk_4e0 : 6) != 0 &&
            func_0207a218() == 0 && n == 0) {
            return;
        }
    }
    q = &data_0217b3f0->mUnk_04;
    if (*q < 0x7fffffff) {
        *q = *q + 1;
    }
    switch (data_021759c0->mUnk_08) {
        case 0:
            data_0217b3f0->mUnk_08 = func_0203c8dc(func_020b4d9c()) - 1;
            b = func_0205dc7c(func_020b4d9c());
            a = func_0205db28();
            p = &data_0217aa1c->mUnk_000[a][func_0205dc7c(b)];
            a = p->mUnk_00;
            data_0217b3f0->mUnk_0c = a - func_0205d3f0(func_020b4d9c());
            if (n > 0x14) {
                data_0217b3f0->mUnk_00 = 1;
            }
            break;
        case 1:
            if (n > 0x14) {
                data_0217b3f0->mUnk_00 = 1;
            }
            break;
        case 3:
        case 5:
            data_0217b3f0->mUnk_08 = func_0203c8dc(func_020b4d9c()) - 1;
            for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
                if (func_0203c8dc(i) == 1) {
                    break;
                }
            }
            data_0217b3f0->mUnk_10 = i;
            if (n > 0x14) {
                data_0217b3f0->mUnk_00 = 1;
            }
            break;
        case 4:
            if (func_0203c880((u16) data_021759c0->mUnk_62) != 0 ? data_0217561c->mUnk_4e0 : 6) {
                data_0217b3f0->mUnk_18 = 9;
            } else {
                data_0217b3f0->mUnk_18 = func_0205d140();
            }
            if ((func_0203c880((u16) data_021759c0->mUnk_62) != 0 ? data_0217561c->mUnk_4e0 : 6) == 0) {
                if (n == 1) {
                    switch (data_0217b3f0->mUnk_18) {
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                            break;
                        case 5:
                            func_0212ecc0(&data_0217d068, 0, 0x1b);
                            break;
                        case 6:
                            func_0212ecc0(&data_0217d068, 0, 0x1c);
                            break;
                        case 7:
                            func_0212ecc0(&data_0217d068, 0, 0x1d);
                            break;
                    }
                } else if (n > 0x1e) {
                    data_0217b3f0->mUnk_00 = 1;
                }
            } else if (n > 0x4b) {
                data_0217b3f0->mUnk_00 = 1;
            }
            break;
        default:
            data_0217b3f0->mUnk_00 = 1;
            break;
    }
}

void func_020c5804(Unk020c06c4 *a) {
    s32 y;
    s32 k;
    s32 e[2];
    void *c;

    if (data_021759c0->mUnk_00c != 0) {
        return;
    }
    if (func_020b1d0c() == 0) {
        return;
    }
    switch (data_021759c0->mUnk_08) {
        case 0:
            func_020c55b0(a);
            break;
        case 3:
        case 5:
            y = func_020ae4c0(1, 0x40, 0, data_0217b3f0->mUnk_04, 0x14);
            c = GetRaceGoalMNcerEntry(data_0217b3f0->mUnk_08);
            e[0] = 0x18000;
            e[1] = (y + 0xa8) << 12;
            k = a->mUnk_400;
            a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, c, NULL, e, 0, 1);
            break;
        case 4:
            func_020c541c(a);
            break;
    }
}

void func_020c55b0(Unk020c06c4 *a) {
    s32 y;
    s32 k;
    s32 e0[2];
    s32 e1[2];
    s32 e2[2];
    s32 e3[2];
    s32 e4[2];
    s32 z;
    void *c;

    y = func_020ae4c0(1, 0x40, 0, data_0217b3f0->mUnk_04, 0x14);
    c = GetRaceGoalMNcerEntry(data_0217b3f0->mUnk_08);
    e0[0] = 0x18000;
    e0[1] = (y + 0xa8) << 12;
    k = a->mUnk_400;
    a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, c, NULL, e0, 0, 1);

    c = GetRaceGoalMNcerEntry(data_0217b3f0->mUnk_0c + 8);
    e1[0] = 0x48000;
    e1[1] = (y + 0xb0) << 12;
    k = a->mUnk_400;
    a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, c, NULL, e1, 0, 1);

    c = GetRaceGoalMNcerEntry(func_020b4b98(data_0217b3f0->mUnk_0c) != 0 ? 0x13 : 0x14);
    e2[0] = 0x48000;
    e2[1] = (y + 0xb0) << 12;
    k = a->mUnk_400;
    a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, c, NULL, e2, 0, 1);

    c = GetRaceGoalMNcerEntry(0x40);
    e3[0] = 0xda000;
    e3[1] = (y + 0xa6) << 12;
    k = a->mUnk_400;
    a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, c, NULL, e3, 0, 1);

    c = GetRaceGoalMNcerEntry(0x41);
    e4[0] = 0xda000;
    e4[1] = (y + 0xa6) << 12;
    k = a->mUnk_400;
    a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, c, NULL, e4, 0, 1);
}

void func_020c541c(Unk020c06c4 *a) {
    s32 n;
    s32 y;
    s32 k;
    s32 v;
    s32 t;
    s32 e[2];
    void *c;

    n = data_0217b3f0->mUnk_04;
    y = func_020ae4c0(1, -0x80, 0, n, 0x14);
    if (data_0217b3f0->mUnk_14 != 9 && data_0217b3f0->mUnk_18 > data_0217b3f0->mUnk_14 && n >= 0x1e) {
        t = n - 10;
        if (t < 0x54) {
            n = t % 12;
            if (n >= 8) {
                return;
            }
        }
    }
    switch (data_0217b3f0->mUnk_18) {
        case 0:
            v = 7;
            break;
        case 1:
            v = 6;
            break;
        case 2:
            v = 5;
            break;
        case 3:
            v = 4;
            break;
        case 4:
            v = 3;
            break;
        case 5:
            v = 2;
            break;
        case 6:
            v = 1;
            break;
        case 7:
            v = 0;
            break;
    }
    if (data_0217b3f0->mUnk_18 >= 8) {
        return;
    }
    c = GetRaceGoalMrMNcerEntry(v);
    e[0] = (y + 0x80) << 12;
    e[1] = 0x60000;
    k = a->mUnk_400;
    a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, c, NULL, e, 0, 1);
}

void func_020c53c4(void) {
    data_0217b3ec = HeapAlloc(GetHeap(func_020364e8()), 0x14);
    data_0217b3ec->mUnk_00 = 0;
    data_0217b3ec->mUnk_04 = 0;
    data_0217b3ec->mUnk_08 = 0;
    data_0217b3ec->mUnk_0c = 0;
    data_0217b3ec->mUnk_10 = 0;
}
