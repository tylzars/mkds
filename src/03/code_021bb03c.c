#include "03/code_021bb03c.h"

#include "03/code_021bcadc.h"
#include "03/code_021bcedc.h"
#include "03/code_021be264.h"
#include "03/code_021be3b8.h"
#include "03/code_021be418.h"
#include "code_0200db4c.h"
#include "code_0214d018.h"
#include "03/code_021bbc94.h"
#include "03/unk_021d8000.h"
#include "code_0200f5ac.h"
#include "code_021329f8.h"
#include "code_02134d30.h"

void func_ov003_021bb408(u8 *output, const u32 *input, u32 size) {
    u32 i;
    for (i = 0; i < size; i += 4) {
        output[i] = *input;
        output[i + 1] = *input >> 8;
        output[i + 2] = *input >> 16;
        output[i + 3] = *input >> 24;
        input++;
    }
}

void func_ov003_021bb3d8(u32 *output, const u8 *input, u32 size) {
    u32 i;
    for (i = 0; i < size; i += 4) {
        *output++ = ((u32) input[i + 3] << 24) | ((input[i + 2] << 16) | (input[i] | (input[i + 1] << 8)));
    }
}

void func_ov003_021bb3bc(void *a, const void *b, u32 c) {
    u8 *d = a;
    const u8 *e = b;
    u32 i;
    for (i = 0; i < c; i++) {
        d[i] = e[i];
    }
}

void func_ov003_021bb3a4(void *buffer, s32 value, u32 count) {
    s8 *p = buffer;
    u32 i = 0;
    for (i = 0; i < count; i++) {
        *p++ = value;
    }
}

void func_ov003_021bb378(u8 *a, const u8 *b, u32 c) {
    Unk021bbd70 d;
    func_ov003_021bbd70(&d);
    func_ov003_021bbcf0(&d, b, c);
    func_ov003_021bbc94(a, &d);
}

u32 func_ov003_021bb354(void) {
    return _ll_udiv(func_0200f5ac() << 6, 0x82ea);
}

void *func_ov003_021bb328(s32 a, s32 b) {
    s32 c = a * b;
    void *d = (void *) data_ov003_021d8bd4(c);
    if (d != NULL) {
        memset(d, 0, c);
    }
    return d;
}

void func_ov003_021bb314(void *p0) {
    u32 v2 = ((u32) (&data_ov003_021d8bdc));
    u32 v3 = ((u32) * (u32 *) ((v2) + (0)));
    u32 v4 = ((u32(*)(void *))(v3))(p0);
}

s32 func_ov003_021bb2d8(u8 *a, s8 b) {
    u8 *c = a;
    u8 w = b;
    s32 i;
    s32 d;
    s32 e;
    d = (w & 0xf0) >> 4;
    i = 0;
    e = w & 0xf;
    for (; i < 2; i++) {
        if (d <= 9) {
            *c++ = d + 0x30;
        } else {
            *c++ = d + 0x37;
        }
        d = e;
    }
    *c = 0;
    return c - a;
}

s32 func_ov003_021bb29c(u8 *a, const s8 *b) {
    u8 *c = a;
    s32 i;
    for (i = 0; i < 6; i++) {
        c += func_ov003_021bb2d8(c, *b++);
        if (i < 5) {
            *c++ = ':';
        }
    }
    *c = 0;
    return c - a;
}

s32 func_ov003_021bb168(u32 a, s32 b, UnkFunc *c, UnkWordFunc *d, UnkFunc *e, u32 f) {
    s32 g;
    if (data_ov003_021d8c08 >= 1 && data_ov003_021d8c08 <= 5) {
        return -10;
    }
    data_ov003_021d68bc = b;
    data_ov003_021d8c08 = 7;
    data_ov003_021d8c4c = c;
    data_ov003_021d8bd4 = d;
    data_ov003_021d8bdc = e;
    data_ov003_021d68b4 = f;
    g = func_ov003_021be418(b);
    data_ov003_021d8c44 = 1;
    if (g < 0) {
        data_ov003_021d8c48 = g;
        return g;
    }
    data_ov003_021d8c00 = (void *) data_ov003_021d8bd4(data_ov003_021d68b4);
    if (data_ov003_021d8c00 == NULL) {
        data_ov003_021d8c48 = -1;
        return -1;
    }
    if (ThreadSystemIsInit() != 1) {
        data_ov003_021d8c48 = -9;
        return -9;
    }
    ThreadInit(&data_ov003_021d8d08, (void (*)(void *)) func_ov003_021bcedc, NULL,
               (u8 *) data_ov003_021d8c00 + (data_ov003_021d68b4 & ~7), data_ov003_021d68b4, a);
    data_ov003_021d8c08 = 1;
    data_ov003_021d68b8 = func_ov003_021bb354() + 60000;
    data_ov003_021d8be0 = 0;
    __clear(&data_ov003_021d8dc8, 0xe8);
    func_ov003_021bb03c();
    ThreadSetRunnable(&data_ov003_021d8d08);
    data_ov003_021d8c34 = 1;
    return 1;
}

s32 func_ov003_021bb0b0(void) {
    s32 a;
    if (data_ov003_021d8c34 != 0) {
        a = data_ov003_021d8c08;
        data_ov003_021d8be0 = 1;
        while (data_ov003_021d8c08 >= 1 && data_ov003_021d8c08 <= 5) {
            func_0200dc3c(100);
        }
        func_0200dc3c(500);
        if (ThreadHasEnded(&data_ov003_021d8d08) == 0) {
            do {
                ThreadSetRunnable(&data_ov003_021d8d08);
                ThreadWaitForEnd(&data_ov003_021d8d08);
            } while (ThreadHasEnded(&data_ov003_021d8d08) == 0);
        }
        if (data_ov003_021d8c00 != NULL) {
            data_ov003_021d8bdc(data_ov003_021d8c00);
            data_ov003_021d8c00 = NULL;
        }
        data_ov003_021d8c34 = 0;
        if (a != data_ov003_021d8c08) {
            func_ov003_021bb03c();
        }
    }
    if (data_ov003_021d8c44 > 0) {
        s32 b = func_ov003_021be3b8();
        data_ov003_021d8c44 = 0;
        return b;
    }
    return -10;
}

u32 func_ov003_021bb070(u32 *a) {
    int v1;
    *a = *(u32 *) &data_ov003_021d8c08;
    if ((*(s32 *) &data_ov003_021d68b8) == -1) {
        a[1] = 0xffffffff;
    } else {
        v1 = func_ov003_021bb354();
        a[1] = (*(s32 *) &data_ov003_021d68b8) - v1;
    }
    a[2] = *(u32 *) &data_ov003_021d8c48;
    return 1;
}

u32 func_ov003_021bb058(Unk021d8dc8 *a) {
    memcpy((u32 *) ((u32 *) (u32) (a)), (const void *) &data_ov003_021d8dc8, 0xe8);
    return 1;
}

void func_ov003_021bb03c(void) {
    u8 v1[8];
    func_ov003_021bb070((u32 *) ((u32 *) (void *) (v1)));
    (*(UnkFunc *) (u32) data_ov003_021d8c4c)(v1);
    return;
}
