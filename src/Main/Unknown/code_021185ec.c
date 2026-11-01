#include "Main/Unknown/code_021185ec.h"

#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020d0000.h"
#include "Main/Unknown/code_02029520.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_0211de00.h"
#include "Main/Unknown/code_0211de40.h"
#include "Main/Unknown/code_0211f240.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"

#pragma thumb on
// non-matching: registers only, 13 words differ (first at +0x10): ours keep the u16 loaded from the +4 member of the
// first object in r7, the first loop's counter in r6, its zero copy in r3 and the table pointers in r5/r4, and make the
// zero copy before the pointer loads; the original has r6, r5, r7 and r4/r3 with the copy after the loads (second loop:
// outer counter r3 / row pointer r7 in ours, r7 / r3 in the original)
void func_021188dc(void) {
    s32 j;
    s32 k;
    s32 i;
    u16 v;
    u16 *q;
    Unk0217d360 *p;

    if (*(vu16 *) 0x027ffc40 != 2) {
        v = data_0217d360->mUnk_04->mUnk_06;
        i = 0;
        for (j = 0; j < 4; j++) {
            data_0217d360->mUnk_18[data_0215c7d0[j]].mUnk_00 = i;
            data_0217d360->mUnk_18[v + data_0215c7d8[j]].mUnk_00 = 1;
        }
        for (; i < 8; i++) {
            for (k = 0, q = data_0215c9bc[i]; k < 6; k++) {
                data_0217d360->mUnk_1c[q[k]].mUnk_00 = 0;
            }
        }
        data_0217d360->mUnk_18[0x14].mUnk_00 = 1;
        data_0217d360->mUnk_18[0x13].mUnk_00 = 1;
        data_0217d360->mUnk_1c[2].mUnk_00 = 1;
        data_0217d360->mUnk_1c[3].mUnk_00 = 1;
        for (i = 0; i < 8; i++) {
            data_0217d360->mUnk_1c[data_0215c9bc[i][0]].mUnk_00 = 1;
        }
        for (i = 0; i < 8; i++) {
            p = data_0217d360;
            func_0211ded0(i, p->mUnk_0c, p->mUnk_10, data_0215c9bc[i][4],
                          func_02124a68(data_0215c9bc[i][4], p->mUnk_0c, p->mUnk_10), 1);
        }
    }
}

void func_02118814(void) {
    s32 i;
    s32 z;

    if (*(vu16 *) 0x027ffc40 != 2) {
        z = 0;
        for (i = 0; i < 8; i++) {
            u16 *q = data_0215c9bc[i];
            data_0217d360->mUnk_1c[q[1]].mUnk_00 = 0;
            data_0217d360->mUnk_1c[q[2]].mUnk_00 = 0;
            data_0217d360->mUnk_1c[q[3]].mUnk_00 = 0;
            data_0217d360->mUnk_1c[q[4]].mUnk_00 = 0;
            data_0217d360->mUnk_1c[q[5]].mUnk_00 = 0;
            if (data_0217d360->mUnk_48[i] == 0) {
                data_0217d360->mUnk_1c[q[3]].mUnk_00 = 1;
                data_0217d360->mUnk_1c[q[5]].mUnk_00 = 1;
            } else {
                if (data_0217d360->mUnk_44 == i && data_0217d360->mUnk_68 != 0) {
                    data_0217d360->mUnk_1c[q[2]].mUnk_00 = 1;
                } else {
                    data_0217d360->mUnk_1c[q[1]].mUnk_00 = 1;
                }
                data_0217d360->mUnk_1c[q[4]].mUnk_00 = 1;
            }
            if (data_0217d360->mUnk_3c == 3) {
                data_0217d360->mUnk_1c[q[5]].mUnk_00 = z;
            }
        }
    }
}

void func_021187d4(void) {
    if (*(vu16 *) 0x027ffc40 != 2) {
        func_020d0efc(data_0215ca1c[data_0217d360->mUnk_44][data_0217d360->mUnk_78]);
        data_0217d360->mUnk_7c = 1;
    }
}

void func_02118624(void) {
    u32 a;
    s32 b;
    s32 c;
    s32 i;
    u16 *q;
    s32 j;
    Unk0217d360 *p;
    u32 v;

    a = 0;
    if (*(vu16 *) 0x027ffc40 == 2) {
        return;
    }
    func_0211de00(data_0217d360->mUnk_44, data_0217d360->mUnk_00, data_0217d360->mUnk_04, 0x13, a);
    j = 0;
    for (i = 0; i < 4; i++) {
        p = data_0217d360;
        func_0212426c(j, data_0215c7d8[i], data_0217d360->mUnk_08,
                      func_020b3f7c(p->mUnk_24, data_0215c91c[p->mUnk_44][i]), p->mUnk_04, p->mUnk_18);
    }
    for (j = 0, q = data_0215c83c; j < 8; q++, j++) {
        data_0217d360->mUnk_18[*q].mUnk_00 = 0;
    }
    for (i = 0; i < 4; i++) {
        data_0217d360->mUnk_18[data_0215c7c8[i]].mUnk_00 = 0;
    }
    if (data_0217d360->mUnk_3c == 0) {
        if (func_0202967c() != 0) {
            v = 3;
        } else {
            v = data_0215c7f0[func_0202969c()];
        }
        b = data_0215c81c[v];
        if (func_02060440(data_0215c85c[data_0217d360->mUnk_44], b) != 0) {
            c = func_02060364(data_0215c85c[data_0217d360->mUnk_44], b);
            data_0217d360->mUnk_18[data_0215c83c[data_0215c87c[c]]].mUnk_00 = 1;
            switch (c) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                    a = data_0215c7c8[0];
                    break;
                case 5:
                    a = data_0215c7c8[1];
                    break;
                case 6:
                    a = data_0215c7c8[2];
                    break;
                case 7:
                    a = data_0215c7c8[3];
                    break;
            }
            data_0217d360->mUnk_18[a].mUnk_00 = 1;
            c = func_020603bc(data_0215c85c[data_0217d360->mUnk_44], b);
            p = data_0217d360;
            func_0211f244(data_0215c85c[p->mUnk_44], c, p->mUnk_00, p->mUnk_04, a, 4, 0);
        }
    }
    func_021187d4();
}

void func_021185ec(void) {
    func_02029590(data_0215c85c[data_0217d360->mUnk_44]);
    func_02029580(data_0215c89c[data_0217d360->mUnk_44]);
}
#pragma thumb off
