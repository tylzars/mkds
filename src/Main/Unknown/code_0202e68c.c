#include "Main/Unknown/code_0202e68c.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0202ecac.h"
#include "Main/Unknown/code_0202ecd4.h"
#include "Main/Unknown/code_0202edfc.h"
#include "Main/Unknown/code_0202ee3c.h"
#include "Main/Unknown/code_0202ee68.h"
#include "Main/Unknown/code_0202f0a8.h"
#include "code_0214d018.h"

#pragma optimize_for_size on

u16 func_0202ec98(Unk02175628 *a, u32 b) {
    return a->mUnk_02 & b;
}

u16 func_0202ec7c(u32 a, u32 b) {
    return func_0202ec98(&data_02175628[a], b);
}

#pragma thumb on

void func_0202e9f0(void) {
    u32 a = func_020435bc();
    s32 f;
    if (data_02174e48->mUnk_660 == 0) {
        return;
    }
    data_02174e48->mUnk_048 = data_02174e48->mUnk_04c > 2 ? 5 : 0xf;
    if (func_0202ecd4(a, 1) != 0) {
        data_02174e48->mUnk_670 = 5;
        data_02174e48->mUnk_024 = data_02174e48->mUnk_044;
        data_02174e48->mUnk_008[data_02174e48->mUnk_02c].mUnk_00 = 0;
        data_02174e48->mUnk_038 = 10;
        data_02174e48->mUnk_054 = 0;
        data_02174e48->mUnk_050 = data_02174e48->mUnk_054;
        data_02174e48->mUnk_04c = 0;
        func_0202edd0();
        func_0202f120(0, -1, -1, -1);
        return;
    }
    if (data_02174e48->mUnk_018 <= data_02174e48->mUnk_020 && data_02174e48->mUnk_020 < data_02174e48->mUnk_018 + 5 &&
        data_02174e48->mUnk_020 - data_02174e48->mUnk_018 < data_02174e48->mUnk_034) {
        data_02174e48->mUnk_670 = 5;
        data_02174e48->mUnk_024 = data_02174e48->mUnk_020 - data_02174e48->mUnk_018;
        f = data_02174e48->mUnk_024 != data_02174e48->mUnk_044;
        data_02174e48->mUnk_008[data_02174e48->mUnk_02c].mUnk_00 = f;
        data_02174e48->mUnk_038 = 10;
        data_02174e48->mUnk_054 = 0;
        data_02174e48->mUnk_050 = data_02174e48->mUnk_054;
        data_02174e48->mUnk_04c = 0;
        data_02174e48->mUnk_040 = data_02174e48->mUnk_040 + (data_02174e48->mUnk_024 - data_02174e48->mUnk_044);
        data_02174e48->mUnk_044 = data_02174e48->mUnk_024;
        func_0202edd0();
        func_0202f120(0, -1, -1, f != 0 ? func_0202edfc() : -1);
        return;
    }
    if ((func_0202ecd4(a, 0x40) != 0 || data_02174e48->mUnk_020 == data_02174e48->mUnk_010 ||
         data_02174e48->mUnk_050 > data_02174e48->mUnk_048) &&
        data_02174e48->mUnk_040 > 0) {
        if (data_02174e48->mUnk_044 == 0) {
            data_02174e48->mUnk_038 = data_02174e48->mUnk_048;
            data_02174e48->mUnk_008[data_02174e48->mUnk_02c].mUnk_00 = 0;
            data_02174e48->mUnk_670 = 3;
            func_0202ee3c(data_02174e48->mUnk_03c, 1);
            func_0202f120(0, -1, -1, -1);
            func_0202f120(2, data_02174e48->mUnk_03c, data_02174e48->mUnk_040 - data_02174e48->mUnk_044 - 1, -1);
        } else {
            data_02174e48->mUnk_670 = 1;
        }
        data_02174e48->mUnk_050 = 0;
        data_02174e48->mUnk_04c = data_02174e48->mUnk_04c + 1;
        if (data_02174e48->mUnk_01c == data_02174e48->mUnk_010) {
            func_0202ed50(1);
        }
        func_0202ecac(3);
        return;
    }
    if ((func_0202ecd4(a, 0x80) != 0 || data_02174e48->mUnk_020 == data_02174e48->mUnk_014 ||
         data_02174e48->mUnk_054 > data_02174e48->mUnk_048) &&
        data_02174e48->mUnk_040 < data_02174e48->mUnk_034 - 1) {
        if (data_02174e48->mUnk_044 == 4) {
            data_02174e48->mUnk_038 = data_02174e48->mUnk_048;
            data_02174e48->mUnk_008[data_02174e48->mUnk_02c].mUnk_00 = 0;
            data_02174e48->mUnk_670 = 4;
            func_0202ee3c(func_0202ee68(), 1);
            func_0202f120(0, -1, -1, -1);
            {
                Unk02174e48 *q = data_02174e48;
                func_0202f120(2, func_0202ee68(), q->mUnk_040 - q->mUnk_044 + 5, -1);
            }
        } else {
            data_02174e48->mUnk_670 = 2;
        }
        data_02174e48->mUnk_054 = 0;
        data_02174e48->mUnk_04c = data_02174e48->mUnk_04c + 1;
        if (data_02174e48->mUnk_01c == data_02174e48->mUnk_014) {
            func_0202ed50(2);
        }
        func_0202ecac(3);
        return;
    }
    if (func_0202ec7c(a, 0xc0) == 0 && data_02174e48->mUnk_01c != data_02174e48->mUnk_010 &&
        data_02174e48->mUnk_01c != data_02174e48->mUnk_014) {
        data_02174e48->mUnk_04c = 0;
    }
}

void func_0202e9ac(void) {
    data_02174e48->mUnk_044 = data_02174e48->mUnk_044 - 1;
    data_02174e48->mUnk_040 = data_02174e48->mUnk_040 - 1;
    func_0202edd0();
    func_0202f120(0, -1, -1, func_0202edfc());
    data_02174e48->mUnk_670 = 0;
}

void func_0202e968(void) {
    data_02174e48->mUnk_044 = data_02174e48->mUnk_044 + 1;
    data_02174e48->mUnk_040 = data_02174e48->mUnk_040 + 1;
    func_0202edd0();
    func_0202f120(0, -1, -1, func_0202edfc());
    data_02174e48->mUnk_670 = 0;
}

void func_0202e84c(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 a;
    Unk02124b1c *p;
    s32 z = 0;
    s32 t = func_0202ee68();
    data_02174e48->mUnk_038 = data_02174e48->mUnk_038 - 1;
    for (i = 0; i < data_02174e48->mUnk_000; i++) {
        for (j = z; j < 7; j++) {
            k = data_02174e48->mUnk_004[i];
            a = func_0202ee20(j + k, (j + 1) % 7 + k);
            p = &data_02174e48->mUnk_008[j + k];
            if (j == t) {
                p->mUnk_06 = a;
            } else {
                p->mUnk_06 = func_020ae4c0(1, (s16) a, z, data_02174e48->mUnk_038, data_02174e48->mUnk_048);
            }
        }
    }
    if (data_02174e48->mUnk_038 == 0) {
        for (i = 0; i < data_02174e48->mUnk_000; i++) {
            for (j = z; j < 7; j++) {
                p = &data_02174e48->mUnk_008[j + data_02174e48->mUnk_004[i]];
                p->mUnk_0e = p->mUnk_0e + p->mUnk_06;
                p->mUnk_06 = 0;
            }
        }
        data_02174e48->mUnk_008[data_02174e48->mUnk_02c].mUnk_00 = 1;
        data_02174e48->mUnk_040 = data_02174e48->mUnk_040 - 1;
        data_02174e48->mUnk_03c = t;
        func_0202f120(1, data_02174e48->mUnk_03c, data_02174e48->mUnk_040 - 1, -1);
        {
            Unk02174e48 *q = data_02174e48;
            func_0202f120(0, q->mUnk_03c, q->mUnk_040 - 1, func_0202edfc());
        }
        data_02174e48->mUnk_670 = 0;
        func_0202ee3c(data_02174e48->mUnk_03c, 0);
    }
}

void func_0202e72c(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 a;
    Unk02124b1c *p;
    s32 z = 0;
    data_02174e48->mUnk_038 = data_02174e48->mUnk_038 - 1;
    for (i = 0; i < data_02174e48->mUnk_000; i++) {
        for (j = z; j < 7; j++) {
            k = data_02174e48->mUnk_004[i];
            a = func_0202ee20(j + k, (j + 6) % 7 + k);
            p = &data_02174e48->mUnk_008[j + k];
            if (j == data_02174e48->mUnk_03c) {
                p->mUnk_06 = a;
            } else {
                p->mUnk_06 = func_020ae4c0(1, (s16) a, z, data_02174e48->mUnk_038, data_02174e48->mUnk_048);
            }
        }
    }
    if (data_02174e48->mUnk_038 == 0) {
        for (i = 0; i < data_02174e48->mUnk_000; i++) {
            for (j = z; j < 7; j++) {
                p = &data_02174e48->mUnk_008[j + data_02174e48->mUnk_004[i]];
                p->mUnk_0e = p->mUnk_0e + p->mUnk_06;
                p->mUnk_06 = 0;
            }
        }
        data_02174e48->mUnk_008[data_02174e48->mUnk_02c].mUnk_00 = 1;
        data_02174e48->mUnk_040 = data_02174e48->mUnk_040 + 1;
        func_0202f120(1, data_02174e48->mUnk_03c, data_02174e48->mUnk_040 + 1, -1);
        {
            Unk02174e48 *q = data_02174e48;
            q->mUnk_03c = (q->mUnk_03c + 1) % 7;
        }
        {
            Unk02174e48 *q = data_02174e48;
            func_0202f120(0, q->mUnk_03c, q->mUnk_040 - 1, func_0202edfc());
        }
        data_02174e48->mUnk_670 = 0;
        func_0202ee3c(func_0202ee68(), 0);
    }
}

void func_0202e6c4(void) {
    if (data_02174e48->mUnk_038 == 10) {
        data_02174e48->mUnk_668 = 1;
    }
    data_02174e48->mUnk_038 = data_02174e48->mUnk_038 - 1;
    if (data_02174e48->mUnk_038 == 0) {
        func_0202f120(0, -1, -1, func_0202edfc());
        data_02174e48->mUnk_008[data_02174e48->mUnk_02c].mUnk_00 = 1;
        data_02174e48->mUnk_670 = 0;
        data_02174e48->mUnk_664 = 1;
    }
}

#pragma thumb off

void func_0202e6a0(void *a, u32 b, u32 c) {
    volatile u32 v = b;
    func_0214d05c(v, a, c);
}

void func_0202e68c(void *a, u32 b) {
    func_0202e6a0(a, 0, b);
}
