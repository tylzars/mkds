#include "Main/Unknown/code_0200c0d8.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0214d018.h"

#pragma thumb on

u8 *func_0200c0d8(Unk0200c0d8 *a, u8 *b) {
    u8 *v1;
    a->mUnk_00 = *b++;
    switch (a->mUnk_00) {
        case 4:
            a->mUnk_02 = b[0];
            a->mUnk_02 |= b[1] << 8;
            a->mUnk_04 = b[2];
            v1 = b + 3;
            b += 4;
            a->mUnk_04 |= *v1 << 8;
            break;
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
            break;
        default:
            return NULL;
    }
    return b;
}

u8 func_0200c12c(void *a, void *b) {
    data_0216fdf0 = (data_0216fdf0 + 1) % data_0216fdf8.mUnk_04;
    MemCopy((u8 *) b + data_0216fdf0 * data_0216fdf8.mUnk_00, a, data_0216fdf8.mUnk_00);
    return data_0216fdf0;
}

u8 *func_0200c16c(Unk0200c16c *a, u8 *b) {
    u8 *v1;
    v1 = b;
    *v1++ = a->mUnk_00;
    switch (a->mUnk_00) {
        case 7:
            *v1++ = *(u8 *) &a->mUnk_02;
            if (*(u8 *) &a->mUnk_02 > data_0216fdf8.mUnk_04) {
                return NULL;
            }
            MemCopy((u8 *) a + 3, v1, data_0216fdf8.mUnk_00);
            v1 += data_0216fdf8.mUnk_00;
            break;
        case 9:
            *v1++ = a->mUnk_02;
            *v1++ = (a->mUnk_02 & 0xff00) >> 8;
            MemCopy(a->mUnk_04, v1, data_0216fdf8.mUnk_00);
            v1 += data_0216fdf8.mUnk_00;
            break;
        case 8:
        case 10:
        case 11:
            break;
        default:
            return NULL;
    }
    return v1;
}

u32 func_0200c20c(u32 a) {
    u16 i;
    s32 v1;
    u32 v2;
    i = 0;
    v1 = data_0216fdf8.mUnk_04;
    if (v1 > 0) {
        v2 = data_0216fdf4->mUnk_1e0[a - 1];
        do {
            if (((1 << i) & v2) == 0) {
                return 0;
            }
            i++;
        } while (i < v1);
    }
    return 1;
}

u8 *func_0200c25c(Unk0200c16c *a, u32 b) {
    Unk0216fdf4 *v1;
    u8 v2;
    u32 v3;
    u32 v4;
    v1 = data_0216fdf4;
    if (v1 == NULL) {
        return NULL;
    }
    v2 = *(u8 *) &a->mUnk_02;
    if (v2 > data_0216fdf8.mUnk_04) {
        return NULL;
    }
    v4 = b - 1;
    v3 = v4 << 5;
    MemCopy((u8 *) a + 3, (u8 *) v1 + v3 + v2 * data_0216fdf8.mUnk_00, data_0216fdf8.mUnk_00);
    data_0216fdf4->mUnk_1e0[v4] |= 1 << v2;
    if (func_0200c20c(b) != 0) {
        return (u8 *) data_0216fdf4 + v3;
    }
    return NULL;
}

u8 *func_0200c2e0(u8 *a, Unk0200c16c *b, u32 c) {
    u8 *v1;
    b->mUnk_00 = a[0];
    switch (b->mUnk_00) {
        case 7:
            if (func_0200c20c(c) != 0) {
                return (u8 *) data_0216fdf4 + (c - 1) * 0x20;
            }
            *(u8 *) &b->mUnk_02 = a[1];
            if (*(u8 *) &b->mUnk_02 > data_0216fdf8.mUnk_04) {
                return NULL;
            }
            MemCopy(a + 2, (u8 *) b + 3, data_0216fdf8.mUnk_00);
            v1 = func_0200c25c(b, c);
            break;
        case 8:
            b->mUnk_02 = a[1] & 0xff;
            v1 = a + 3;
            b->mUnk_02 |= (a[2] << 8) & 0xff00;
            break;
        case 9:
            b->mUnk_02 = a[1] & 0xff;
            v1 = a + 3;
            b->mUnk_02 |= (a[2] << 8) & 0xff00;
            MemCopy(v1, b->mUnk_04, data_0216fdf8.mUnk_00);
            v1 += data_0216fdf8.mUnk_00;
            break;
        default:
            return NULL;
    }
    return v1;
}

u8 *func_0200c3a4(u8 *param_1, u8 *param_2) {
    Unk0200c0d8 *v1;
    u8 *v2;
    v1 = (Unk0200c0d8 *) param_1;
    v2 = param_2;
    *v2++ = v1->mUnk_00;
    switch (v1->mUnk_00) {
        case 4:
            *v2++ = v1->mUnk_02;
            *v2++ = (v1->mUnk_02 & 0xff00) >> 8;
            *v2++ = v1->mUnk_04;
            *v2++ = (v1->mUnk_04 & 0xff00) >> 8;
            break;
        case 1:
        case 2:
        case 3:
        case 5:
        case 6:
            break;
        default:
            return NULL;
    }
    return v2;
}

#pragma thumb off
