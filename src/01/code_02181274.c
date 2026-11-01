#include "01/code_02181274.h"
#include "01/code_02181b54.h"
#include "01/code_02188950.h"
#include "01/code_02188e88.h"
#include "01/unk_021a9000.h"
#include "01/code_02181000.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_0214d000.h"

void func_ov001_021815d0(s32 p0) {
    s32 i;

    for (i = 0; i < p0; i++) {
        if (++data_ov001_021a9b90->mUnk_08 > func_ov001_0218180c()) {
            data_ov001_021a9b90->mUnk_08 = func_ov001_0218180c();
            return;
        }
        if (data_ov001_021a9b90->mUnk_0e == 0) {
            data_ov001_021a9b90->mUnk_0e = data_ov001_021a9b90->mUnk_10;
        } else {
            data_ov001_021a9b90->mUnk_0e += data_ov001_021a9b90->mUnk_14;
            if (data_ov001_021a9b90->mUnk_0e > data_ov001_021a9b90->mUnk_12) {
                data_ov001_021a9b90->mUnk_0e = data_ov001_021a9b90->mUnk_12;
            }
        }
    }
}

void func_ov001_0218155c(s32 p0) {
    s32 i;

    if ((u32) p0 >= data_ov001_021a9b90->mUnk_06) {
        p0 = data_ov001_021a9b90->mUnk_06;
    }
    for (i = 0; i < p0; i++) {
        data_ov001_021a9b90->mUnk_06--;
        if (++data_ov001_021a9b90->mUnk_08 > func_ov001_0218180c()) {
            data_ov001_021a9b90->mUnk_08 = func_ov001_0218180c();
            return;
        }
        if (data_ov001_021a9b90->mUnk_0e == 0) {
            data_ov001_021a9b90->mUnk_0e = data_ov001_021a9b90->mUnk_10;
        } else {
            data_ov001_021a9b90->mUnk_0e += data_ov001_021a9b90->mUnk_16;
            if (data_ov001_021a9b90->mUnk_0e > data_ov001_021a9b90->mUnk_12) {
                data_ov001_021a9b90->mUnk_0e = data_ov001_021a9b90->mUnk_12;
            }
        }
    }
}

s32 func_ov001_02181528(void) {
    Unk02188950 *p;

    if (data_021759c0->mUnk_08 == 4) {
        p = func_ov001_02181b68(data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0);
    } else {
        p = 0;
    }
    return p->mUnk_168;
}

#pragma thumb off

s32 func_ov001_02181510(void) {
    return func_020c0c2c(&data_ov001_021a9b8c, 0x68);
}

void func_ov001_021814fc(void) {
    func_020c0b84(&data_ov001_021a9b8c);
}

void func_ov001_02181410(void) {
    s32 i;
    s32 count;
    Unk0217b498_00 *e;
    Vec3 *pos;
    u32 v;

    count = 0;
    v = func_020c0db0();
    for (i = 0; i < data_ov001_021a9b8c->mUnk_08; i++) {
        e = data_ov001_021a9b8c->mUnk_00[i];
        if ((e->mUnk_02 & 1) == 0) {
            pos = &e->mUnk_04;
            if (func_020b5ae8(pos, &data_ov001_021a9b8c->mUnk_10[count].mUnk_00, v, 1, 1)) {
                data_ov001_021a9b8c->mUnk_10[count].mUnk_08 = func_020b83dc(0x58);
                data_ov001_021a9b8c->mUnk_10[count].mUnk_0c = func_020b4e70(pos) != 0 ? 2 : 3;
                count++;
            }
        }
    }
    data_ov001_021a9b8c->mUnk_04 = count;
}

void func_ov001_021813f4(void *p0) {
    func_020c092c(p0, data_ov001_021a9b8c, 0);
}

#pragma thumb on

void func_ov001_02181274(s32 p0, s32 p1, s32 p2) {
    s32 j;
    s32 i;
    void *heap;

    heap = func_020364e0(func_020364e8());
    data_ov001_021a9b88 = (Unk021a9b88 *) func_02036b74(heap, 0x30, 0x20);
    data_ov001_021a9b88->mUnk_00 = p0;
    data_ov001_021a9b88->mUnk_04 = p1;
    data_ov001_021a9b88->mUnk_08 = p2;
    heap = func_020364e0(func_020364e8());
    data_ov001_021a9b88->mUnk_18 = (u16 *) func_02036b74(heap, data_ov001_021a9b88->mUnk_08 * 2, 0x20);
    heap = func_020364e0(func_020364e8());
    data_ov001_021a9b88->mUnk_1c =
        (u8 *) func_02036b74(heap, data_ov001_021a9b88->mUnk_04 / 8 * (data_ov001_021a9b88->mUnk_04 / 8), 0x20);
    func_0214d168(data_ov001_021a9b88->mUnk_1c, data_ov001_021a9b88->mUnk_00 / 8 * data_ov001_021a9b88->mUnk_00 / 8,
                  data_ov001_021a9b88->mUnk_04 / 8 * (data_ov001_021a9b88->mUnk_04 / 8));
    for (i = 0; i < data_ov001_021a9b88->mUnk_00 / 8; i++) {
        for (j = 0; j < data_ov001_021a9b88->mUnk_00 / 8; j++) {
            data_ov001_021a9b88->mUnk_1c[i * data_ov001_021a9b88->mUnk_04 / 8 + j] =
                j + i * data_ov001_021a9b88->mUnk_00 / 8;
        }
    }
    heap = func_020364e0(func_020364e8());
    data_ov001_021a9b88->mUnk_20 =
        (u8 *) func_02036b74(heap, data_ov001_021a9b88->mUnk_00 * data_ov001_021a9b88->mUnk_00 + 0x40, 0x20);
    heap = func_020364e0(func_020364e8());
    data_ov001_021a9b88->mUnk_24 =
        (u8 *) func_02036b74(heap, data_ov001_021a9b88->mUnk_00 * data_ov001_021a9b88->mUnk_00 + 0x40, 0x20);
    heap = func_020364e0(func_020364e8());
    data_ov001_021a9b88->mUnk_28 =
        (u8 *) func_02036b74(heap, data_ov001_021a9b88->mUnk_00 * data_ov001_021a9b88->mUnk_00, 0x20);
    heap = func_020364e0(func_020364e8());
    data_ov001_021a9b88->mUnk_2c =
        (u8 *) func_02036b74(heap, data_ov001_021a9b88->mUnk_00 * data_ov001_021a9b88->mUnk_00 * 2, 0x20);
}
