#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02016468.h"
#include "code_0214cfe4.h"

#pragma thumb on

Unk0215c5b4 data_0215c5b4 = {
    0, -2, -4, -5, -4, -2, 0, 0, -1, -2, -2, -2, -1, 0,
};

u16 data_0215c5d0[4] = {0, 1, 2, 0};

void func_02116d24(void) {
    u8 *q;
    Unk0217d354 *p;

    data_0217d354->mUnk_28++;
    if (data_0217d354->mUnk_28 >= 4) {
        data_0217d354->mUnk_24++;
        if (data_0217d354->mUnk_24 >= 3) {
            data_0217d354->mUnk_24 = 0;
        }
        data_0217d354->mUnk_28 = 0;
        func_02124748(data_0215c5d0[data_0217d354->mUnk_24], data_0217d354->mUnk_00, data_0217d354->mUnk_04,
                      data_0217d354->mUnk_0c, data_0217d354->mUnk_20, data_0217d354->mUnk_18, data_0217d354->mUnk_10,
                      data_0217d354->mUnk_14);
        p = data_0217d354;
        q = p->mUnk_08->mUnk_0c;
        switch (p->mUnk_20) {
            case 0:
                func_02016468(0xe, p->mUnk_1c << 5, q + 0x1c0, 0x20);
                break;
            case 1:
                func_02016468(0x1e, p->mUnk_1c << 5, q + 0x1c0, 0x20);
                break;
        }
    }
}

s16 func_02116d10(s32 a, s32 b) {
    return data_0215c5b4[b][a];
}

void func_02116ce8(s32 a, u16 *b, s32 c) {
    switch (c) {
        case 0:
            func_02124fac(a, b);
            break;
        case 1:
            func_02124f4c(a, b);
            break;
    }
}

void func_02116ccc(u16 *a, s32 b) {
    switch (b) {
        case 0:
            *a = 0x3a;
            break;
        case 1:
            *a = 0xff1a;
            break;
    }
}

void func_02116cb0(u16 *a, s32 b) {
    switch (b) {
        case 0:
            *a = 0x30;
            break;
        case 1:
            *a = 0xff10;
            break;
    }
}

void func_02116b98(Unk02116b98 *a, u16 *b, s32 c) {
    u16 i;
    u16 buf[0x12];

    i = 0;
    func_02116ce8(a->mUnk_02, b, c);
    i++;
    if (a->mUnk_02 >= 10) {
        i++;
    }
    func_02116ccc(b + i, c);
    func_02116ce8(a->mUnk_03, buf, c);
    if (a->mUnk_03 >= 10) {
        MemCopyHalfwords(buf, b + (u16) (i + 1), 4);
        i += 3;
    } else {
        func_02116cb0(b + (u16) (i + 1), c);
        MemCopyHalfwords(buf, b + (u16) (i + 2), 2);
        i += 3;
    }
    func_02116ccc(b + i, c);
    func_02116ce8(a->mUnk_00, buf, c);
    if (a->mUnk_00 >= 100) {
        MemCopyHalfwords(buf, b + (u16) (i + 1), 6);
        i += 4;
    } else if (a->mUnk_00 >= 10) {
        func_02116cb0(b + (u16) (i + 1), c);
        MemCopyHalfwords(buf, b + (u16) (i + 2), 4);
        i += 4;
    } else {
        func_02116cb0(b + (u16) (i + 1), c);
        func_02116cb0(b + (u16) (i + 2), c);
        MemCopyHalfwords(buf, b + (u16) (i + 3), 2);
        i += 4;
    }
    b[i] = 0;
}

void func_02116b8c(void *a, u16 *b) {
    func_02116b98(a, b, 0);
}

void func_02116b80(void *in, void *out) {
    func_02116b98(in, out, 1);
}

void func_02116b50(u32 a, u16 *b) {
    if (a >= 10) {
        func_02124fac(a, b);
    } else {
        func_02124fac(0, b);
        func_02124fac(a, b + 1);
    }
}

void func_02116a4c(Unk02116a4c *a, u16 *b) {
    switch (data_021759d0->mUnk_00) {
        case 0:
            func_02116b50(0x14, b);
            func_02116b50(a->mUnk_00, b + 2);
            b[4] = 0x2f;
            func_02116b50(a->mUnk_01, b + 5);
            b[7] = 0x2f;
            func_02116b50(a->mUnk_02, b + 8);
            b[10] = 0;
            break;
        case 1:
            func_02116b50(a->mUnk_01, b);
            b[2] = 0x2f;
            func_02116b50(a->mUnk_02, b + 3);
            b[5] = 0x2f;
            func_02116b50(0x14, b + 6);
            func_02116b50(a->mUnk_00, b + 8);
            b[10] = 0;
            break;
        case 2:
            if (data_021759d0->mUnk_04 == 3) {
                func_02116b50(a->mUnk_02, b);
                b[2] = 0x2e;
                func_02116b50(a->mUnk_01, b + 3);
                b[5] = 0x2e;
                func_02116b50(0x14, b + 6);
                func_02116b50(a->mUnk_00, b + 8);
                b[10] = 0;
            } else {
                func_02116b50(a->mUnk_02, b);
                b[2] = 0x2f;
                func_02116b50(a->mUnk_01, b + 3);
                b[5] = 0x2f;
                func_02116b50(0x14, b + 6);
                func_02116b50(a->mUnk_00, b + 8);
                b[10] = 0;
            }
    }
}

#pragma thumb off
