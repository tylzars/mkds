#include "Main/Unknown/code_020b41e8.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "00/code_02182fdc.h"
#include "code_0214cfe4.h"
#include "code_02022aa8.h"

void func_020b478c(void *a, void *b) {
    if (b != 0) {
        func_02022d88((Unk02022aa8 *) a, (Unk02021f9c *) b);
    }
}

void func_020b46d0(void *a, s32 b, s32 c, s32 d, s32 e, void *f, s32 g, s32 h) {
    s32 i;
    s32 j;

    for (i = 0; i < d; i++) {
        for (j = 0; j < e; j++) {
            func_0214cffc((u8 *) a + (b + i) * 32 + (c + j) * 1024, (u8 *) f + (g + i) * 32 + (h + j) * 1024, 0x20);
        }
    }
}

void func_020b45b0(u16 *a, s32 b, s32 c, s32 d, s32 e, u16 *f, s32 g, s32 h) {
    s32 i;
    s32 j;
    s32 k;
    s32 l;

    for (i = 0; i < d; i++) {
        for (j = 0; j < e; j++) {
            for (k = 0; k < 8; k++) {
                for (l = 0; l < 2; l++) {
                    (f + (g + i) * 16 + (h + (e - j - 1)) * 512)[(7 - k) * 2 + l] =
                        (a + (b + i) * 16 + (c + j) * 512)[k * 2 + l];
                }
            }
        }
    }
}

void func_020b4520(u16 *a, s32 b, s32 c, s32 d, s32 e, u16 *f, s32 g, s32 h) {
    u16 *p;
    s32 j;
    s32 i;

    p = f;
    for (i = 0; i < e; i++) {
        for (j = 0; j < d; j++) {
            p[(g + j) + (h + i) * 32] = a[(b + j) + (c + i) * 32];
        }
    }
}

void func_020b44a4(u16 *a, s32 b, s32 c, s32 d, s32 e, u16 f) {
    s32 i;
    s32 j;

    for (i = c; i < c + e; i++) {
        for (j = b; j < b + d; j++) {
            a[i * 32 + j] = (f << 12) | (u16) (a[i * 32 + j] & 0xfff);
        }
    }
}

void func_020b4428(u16 *a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 i;
    s32 j;

    for (i = c; i < c + e; i++) {
        for (j = b; j < b + d; j++) {
            a[i * 32 + j] = f | (u16) (a[i * 32 + j] & 0xfc00);
        }
    }
}

// non-matching: same size, 14 words: in the first of the 16-iteration loops the sum d + e * 32 is added to j % 4 as
// (add r1, r5, r1), ours (add r1, r1, r5); in the third loop the original keeps the counter in r7, the row term in r5,
// the pointer o2->mUnk_14 in r8 and the running index in r6 (ours r5, r7, r6 and r8).
void func_020b41e8(s32 a, s32 b, s32 c, s32 d, s32 e) {
    Unk021759c0 *p = data_021759c0;
    Unk020b4a44 *o1;
    Unk020b4934 *o2;
    u16 *s3;
    u16 *s;
    u16 *k;
    s32 n;
    s32 m;
    s32 y;
    s32 j;
    s32 x;
    u16 i;

    i = p->mUnk_00c == 1 ? p->mUnk_063 : p->mUnk_62;
    n = p->mUnk_68[i].mUnk_00;
    if (n == 12) {
        o1 = (Unk020b4a44 *) func_020b4024(1);
    } else {
        o1 = func_020b4030(1);
    }
    o2 = func_020b4018(1);
    k = o1->mUnk_0c;
    if (n == 12) {
        m = data_0217b488
                ->mUnk_10c[(u16) (data_021759c0->mUnk_00c == 1 ? data_021759c0->mUnk_063 : data_021759c0->mUnk_62)];
    } else {
        m = n;
    }
    for (x = 0; x < 16; x++) {
        ((u16 *) a)[b * 16 + x] = k[m * 16 + x];
    }
    s = o2->mUnk_14;
    for (j = 0; j < 16; j++) {
        func_0214cffc(s + (n * 25 + j) * 16, (u16 *) c + (j % 4 + (d + e * 32)) * 16 + j / 4 * 512, 0x20);
    }
    s3 = o2->mUnk_14;
    for (y = 0; y < 4; y++) {
        func_0214cffc(s3 + (n * 25 + 16 + y) * 16, (u16 *) c + (d + 4 + e * 32) * 16 + y * 512, 0x20);
    }
    s = o2->mUnk_14;
    for (j = 0; j < 4; j++) {
        func_0214cffc(s + (n * 25 + 20 + j) * 16, (u16 *) c + (d + (e + 4) * 32 + j % 4) * 16 + j / 4 * 512, 0x20);
    }
    func_0214cffc(o2->mUnk_14 + (n * 25 + 24) * 16, (u16 *) c + (d + 4 + (e + 4) * 32) * 16, 0x20);
}
