#include "03/code_021b7efc.h"
#include "03/code_021b7bb4.h"
#include "03/code_021b94b8.h"

void func_ov003_021b7efc(s32 a, s8 *b, s32 c, const s8 *d, s32 e) {
    s32 f = c / 2;
    s32 g = a % e;
    s32 i;
    for (i = 0; i < f; i++) {
        b[i] = i;
        b[i] ^= d[g++];
        if (g >= e) {
            g = 0;
        }
    }
}

s32 func_ov003_021b7f48(u8 *a, s32 b, const s8 *c, s32 d) {
    s8 *e;
    u8 *f;
    s32 i;
    e = func_ov003_021ba178(b / 2);
    if (e == NULL) {
        return -1;
    }
    f = func_ov003_021ba178(b);
    if (f == NULL) {
        func_ov003_021ba164(e);
        return -1;
    }
    for (i = 0; i < 2; i++) {
        func_ov003_021b7efc(i, e, b, c, d);
        func_ov003_021b7ed0(e, a, b);
        func_ov003_021b7e94(a, b, f);
    }
    func_ov003_021ba164(e);
    func_ov003_021ba164(f);
    return 0;
}

void func_ov003_021b7fd4(s32 a, u32 *b) {
    u32 c;
    s32 i;
    s32 j;
    for (i = 0; i < 0x100; i++) {
        c = i;
        for (j = 0; j < 8; j++) {
            if (c & 1) {
                c = (c >> 1) ^ 0xedb88320;
            } else {
                c = c >> 1;
            }
        }
        *b++ = c;
    }
}

u32 func_ov003_021b8010(u32 a, const u8 *b, s32 c, s32 d, u32 *e) {
    s32 i;
    if (d == 0) {
        func_ov003_021b7fd4(d, e);
    }
    for (i = 0; i < c; i++) {
        a = (a >> 8) ^ e[(a ^ b[i]) & 0xff];
    }
    return a;
}
