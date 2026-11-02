#include "Main/Unknown/code_02116174.h"

#include "Main/Unknown/code_0211621c.h"
#include "Main/Unknown/code_02116244.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02114000.h"
#include "Main/Unknown/code_02116844.h"
#include "Main/Unknown/code_02116870.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_0212426c.h"
#include "00/code_02182fdc.h"
#include "code_02016468.h"
#include "Main/Unknown/code_02116888.h"

#pragma thumb on

void func_02116888(void) {
    int *v1;
    u32 v2;
    int v3;
    int v4;
    int v5;
    int v6[2];
    v4 = 0;
    v5 = 0;
    v6[0] = 0;
    v2 = ((int) func_0204799c((const char *) data_0216d20c));
    func_020b49bc((Unk020b4934 **) data_0217d350, (void *) v2);
    v2 = ((int) func_0204799c((const char *) data_0216d200));
    func_020b48b4(&data_0217d350->mUnk_04, (void *) v2);
    v2 = ((int) func_0204799c((const char *) data_0216d1f4));
    data_0217d350->mUnk_08 = (Unk0201ea30 *) v2;
    v2 = ((int) func_0204799c((const char *) data_0216d22c));
    data_0217d350->mUnk_0c = (void *) v2;
    v2 = ((int) func_0204799c((const char *) data_0216d238));
    data_0217d350->mUnk_18 = (Unk0201ea30 *) v2;
    v2 = ((int) func_0204799c((const char *) data_0216d1fc));
    data_0217d350->mUnk_1c = (void *) v2;
    v2 = ((int) func_0204799c((const char *) data_0216d208));
    func_020b49bc(&data_0217d350->mUnk_28, (void *) v2);
    v2 = ((int) func_0204799c((const char *) data_0216d210));
    func_020b48b4(&data_0217d350->mUnk_2c, (void *) v2);
    v2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d3f0))));
    data_0217d350->mUnk_30 = (Unk0201ea30 *) v2;
    v2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d3fc))));
    data_0217d350->mUnk_34 = (void *) v2;
    v2 = ((int) func_0204799c((const char *) ((*(u32 *) &data_0216d3f8))));
    v1 = (&(*(int *) &data_0217d350));
    data_0217d350->mUnk_38 = (void *) v2;
    v2 = ((u32) func_02036bec((void *) (*(u32 *) (*v1 + 0x50)), (u32) (((u32) 0x00000800u))));
    data_0217d350->mUnk_4c = v2;
    v2 = ((int) func_0204799c((const char *) data_0216d3f4));
    func_020b4934((Unk020b4934 **) (&v4), (void *) v2);
    v2 = ((int) func_0204799c((const char *) data_0216d400));
    func_020b47d8((Unk020b47d8 **) v6, (void *) v2);
    v2 = ((int) func_0204799c((const char *) data_0216d404));
    func_020b4a44((Unk020b4a44 **) (&v5), (void *) v2);
    v2 = ((int) func_0204799c((const char *) data_0216d228));
    func_020b47d8((Unk020b47d8 **) ((int *) (u32) ((int) data_0217d350 + 0x10)), (void *) v2);
    v2 = ((int) func_0204799c((const char *) data_0216d214));
    func_020b47d8((Unk020b47d8 **) ((int *) (u32) ((int) data_0217d350 + 0x20)), (void *) v2);
    v3 = ((u32) func_02077f00());
    func_02016468((u32) 0x17, (u32) 0, (void *) (*(u32 *) (v4 + 0x14)), (u32) (*(u32 *) (v4 + 0x10)));
    func_02016468((u32) 0x1b, (u32) 0, (void *) (v6[0] + 0xc), (u32) (*(u32 *) (v6[0] + 8)));
    func_02016468((u32) 0x1b, (u32) (((u32) 0x00000800u)), (void *) data_0217d350->mUnk_4c,
                  (u32) (((u32) 0x00000800u)));
    func_02016468((u32) 0x1f, (u32) 0, (void *) (*(u32 *) (v5 + 0xc)), (u32) 0x40);
    func_02016468((u32) 0xe, (u32) 0x40, (void *) (*(u32 *) (v3 + 0xc)), (u32) 0x20);
}

#pragma thumb off

#pragma thumb on

u16 func_02116870(void) {
    return data_0217d350->mUnk_76 * 5;
}

#pragma thumb off

#pragma thumb on

u32 func_02116844(int a) {
    int v1;
    int v2;
    v1 = func_02116870();
    v2 = func_021143b4();
    if (v2 > v1 + a) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void func_02116624(void) {
    s32 i;
    s32 n;
    s32 v;

    n = data_0217d350->mUnk_30->mUnk_06;
    v = func_02116870();
    for (i = 0; i < 5; i++) {
        data_0217d350->mUnk_3c[data_0215c4e8[i]].mUnk_00 = 0;
        data_0217d350->mUnk_3c[data_0215c4f4[i]].mUnk_00 = 0;
        data_0217d350->mUnk_3c[data_0215c500[i]].mUnk_00 = 0;
        data_0217d350->mUnk_3c[data_0215c50c[i]].mUnk_00 = 0;
        data_0217d350->mUnk_3c[data_0215c518[i]].mUnk_00 = 0;
        data_0217d350->mUnk_3c[data_0215c524[i]].mUnk_00 = 0;
        data_0217d350->mUnk_3c[n + data_0215c4b8[i]].mUnk_00 = 0;
    }
    for (i = 0; i < 5; i++) {
        if (func_02116844((s16) i)) {
            if (data_0217d350->mUnk_74 == i) {
                if (func_02114398(v)) {
                    data_0217d350->mUnk_3c[data_0215c50c[i]].mUnk_00 = 1;
                    func_02124100(data_0215c4b8[i], 0xe, data_0217d350->mUnk_38, data_0217d350->mUnk_3c,
                                  data_0217d350->mUnk_30);
                } else {
                    data_0217d350->mUnk_3c[data_0215c4f4[i]].mUnk_00 = 1;
                    func_02124100(data_0215c4b8[i], 0xe, data_0217d350->mUnk_38, data_0217d350->mUnk_3c,
                                  data_0217d350->mUnk_30);
                }
            } else {
                if (func_02114398(v)) {
                    data_0217d350->mUnk_3c[data_0215c500[i]].mUnk_00 = 1;
                    func_02124100(data_0215c4b8[i], 0xe, data_0217d350->mUnk_38, data_0217d350->mUnk_3c,
                                  data_0217d350->mUnk_30);
                } else {
                    data_0217d350->mUnk_3c[data_0215c4e8[i]].mUnk_00 = 1;
                    func_02124100(data_0215c4b8[i], 0xf, data_0217d350->mUnk_38, data_0217d350->mUnk_3c,
                                  data_0217d350->mUnk_30);
                }
            }
            data_0217d350->mUnk_3c[data_0215c518[i]].mUnk_00 = func_02114398(v) ? 0 : 1;
            data_0217d350->mUnk_3c[data_0215c524[i]].mUnk_00 = func_02114398(v);
            data_0217d350->mUnk_3c[n + data_0215c4b8[i]].mUnk_00 = 1;
        }
        v++;
    }
}

void func_021162cc(void) {
    s32 v;
    s32 i;
    s32 j;
    s32 z;
    u16 buf[0x10];
    u32 t[3][3] = {0};
    u8 buf3[0x14];
    Unk02116a4c a;

    v = func_02116870();
    if (func_02114158(v + data_0217d350->mUnk_80, buf3)) {
        data_0217d350->mUnk_40 = 1;
        func_02016468(9, 0, &data_0217d350->mUnk_20->mUnk_0c, data_0217d350->mUnk_20->mUnk_08);
    } else {
        data_0217d350->mUnk_40 = 0;
        func_02016468(9, 0, &data_0217d350->mUnk_10->mUnk_0c, data_0217d350->mUnk_10->mUnk_08);
    }
    switch (data_0217d350->mUnk_40) {
        case 0:
            func_02114298(v + data_0217d350->mUnk_80, buf, 0x20);
            func_0212426c(0, 0, data_0217d350->mUnk_0c, buf, data_0217d350->mUnk_08, data_0217d350->mUnk_14);
            t[1][0] = func_0211437c(v + data_0217d350->mUnk_80);
            t[1][1] = func_02114360(v + data_0217d350->mUnk_80);
            t[1][2] = func_02114344(v + data_0217d350->mUnk_80);
            t[2][0] = func_02114328(v + data_0217d350->mUnk_80);
            t[2][1] = func_0211430c(v + data_0217d350->mUnk_80);
            t[2][2] = func_021142f0(v + data_0217d350->mUnk_80);
            for (i = 1; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (t[i][j] > 0x270f) {
                        t[i][j] = 0x270f;
                    }
                }
            }
            func_02124fac(t[1][0], buf);
            func_02124248(0, data_0215c530[1][0], data_0217d350->mUnk_0c, buf, data_0217d350->mUnk_08,
                          data_0217d350->mUnk_14, 6);
            func_02124fac(t[1][1], buf);
            func_02124248(0, data_0215c530[1][1], data_0217d350->mUnk_0c, buf, data_0217d350->mUnk_08,
                          data_0217d350->mUnk_14, 6);
            func_02124fac(t[1][2], buf);
            func_02124248(0, data_0215c530[1][2], data_0217d350->mUnk_0c, buf, data_0217d350->mUnk_08,
                          data_0217d350->mUnk_14, 6);
            func_02124fac(t[2][0], buf);
            func_02124248(0, data_0215c530[2][0], data_0217d350->mUnk_0c, buf, data_0217d350->mUnk_08,
                          data_0217d350->mUnk_14, 6);
            func_02124fac(t[2][1], buf);
            func_02124248(0, data_0215c530[2][1], data_0217d350->mUnk_0c, buf, data_0217d350->mUnk_08,
                          data_0217d350->mUnk_14, 6);
            func_02124fac(t[2][2], buf);
            func_02124248(0, data_0215c530[2][2], data_0217d350->mUnk_0c, buf, data_0217d350->mUnk_08,
                          data_0217d350->mUnk_14, 6);
            func_021142d4(v + data_0217d350->mUnk_80, &a);
            func_02116a4c(&a, buf);
            func_02124224(0, 0xc, data_0217d350->mUnk_0c, buf, data_0217d350->mUnk_08, data_0217d350->mUnk_14, 6);
            func_021141c8(v + data_0217d350->mUnk_80, data_0217d350->mUnk_88, data_0217d350->mUnk_8c);
            func_02016468(0x13, func_0212497c(3, data_0217d350->mUnk_04, data_0217d350->mUnk_08) << 5,
                          data_0217d350->mUnk_8c, 0x200);
            break;
        case 1:
            func_02114298(v + data_0217d350->mUnk_80, buf, 0x20);
            func_0212426c(0, 0, data_0217d350->mUnk_1c, buf, data_0217d350->mUnk_18, data_0217d350->mUnk_24);
            z = 0;
            for (i = 0; i < 12; i++) {
                func_02124fac(buf3[i] - 0x30, buf);
                func_0212426c(z, data_0215c584[i], data_0217d350->mUnk_1c, buf, data_0217d350->mUnk_18,
                              data_0217d350->mUnk_24);
            }
            func_021141c8(v + data_0217d350->mUnk_80, data_0217d350->mUnk_88, data_0217d350->mUnk_8c);
            func_02016468(0x13, func_0212497c(1, data_0217d350->mUnk_04, data_0217d350->mUnk_18) << 5,
                          data_0217d350->mUnk_8c, 0x200);
            break;
    }
}

void func_02116244(void) {
    s32 v;
    s32 i;
    u8 buf[0x20];

    v = func_02116870();
    for (i = 0; i < 5; i++) {
        if (func_021143b4() > v + i) {
            func_02114298(v + i, buf, 0x20);
            func_0212426c(1, data_0215c4b8[i], data_0217d350->mUnk_38, buf, data_0217d350->mUnk_30,
                          data_0217d350->mUnk_3c);
        }
    }
    if (func_021143b4() <= v + data_0217d350->mUnk_74) {
        data_0217d350->mUnk_74 = func_021143b4() % 5 - 1;
        data_0217d350->mUnk_80 = data_0217d350->mUnk_74;
    }
    func_021162cc();
}

#pragma thumb off

#pragma thumb on
u32 func_02116230(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217d350;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 118u;
    value0 = (u32) * (const s16 *) ((value1) + (value0));
    value0 = (value0) + (1u);
    value1 = (value1) + 118u;
    *(u16 *) ((value1) + 0u) = (u16) value0;
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 func_0211621c(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217d350;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 118u;
    value0 = (u32) * (const s16 *) ((value1) + (value0));
    value0 = (value0) - (1u);
    value1 = (value1) + 118u;
    *(u16 *) ((value1) + 0u) = (u16) value0;
    return value0;
}
#pragma thumb off

#pragma thumb on

void func_021161d0(void) {
    int v1;
    int v2;
    v2 = (data_0217d350->mUnk_74 + 1) * 0x10000 >> 0x10;
    v1 = func_02116844(v2);
    if ((v1 == 0) || (5 <= v2)) {
        v2 = 0;
    }
    if (data_0217d350->mUnk_74 != v2) {
        func_0212ecc0((const void *) (((u32) ((u8 *) &data_0217d068))), (u32) 0, (u32) 0);
    }
    data_0217d350->mUnk_74 = (short) v2;
}

void func_02116174(void) {
    int v1;
    u32 v2;
    int v3;
    int v4;
    v4 = (data_0217d350->mUnk_74 + -1) * 0x10000 >> 0x10;
    if (v4 < 0) {
        v4 = 4;
        v1 = func_02116844(4);
        if (v1 == 0) {
            v2 = func_021143b4();
            v3 = (int) (v2) % 5;
            v4 = (v3 + -1) * 0x10000 >> 0x10;
        }
    }
    if (data_0217d350->mUnk_74 != v4) {
        func_0212ecc0((const void *) &data_0217d068, (u32) 0, (u32) 0);
    }
    data_0217d350->mUnk_74 = (short) v4;
}

#pragma thumb off
