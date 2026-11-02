#include "Main/Unknown/code_020caba4.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ca984.h"
#include "Main/Unknown/code_020ca9dc.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
s32 func_020cadac(s32 a) {
    s32 v;
    s32 n;

    v = gEmblemChoises->mUnk_20;
    if (gEmblemChoises->mUnk_00 != 0) {
        n = gEmblemChoises->mUnk_28;
        if (a != 0) {
            gEmblemChoises->mUnk_24 = 0;
            func_02105ac0(0);
        }
        gEmblemChoises->mUnk_20 = (v + a + n) % n;
    }
    return v;
}

s32 func_020cacc0(void) {
    s32 v;
    s32 n;
    s32 z;
    s32 i;
    s32 j;
    Unk020ae244 r[6];

    v = 0;
    if (gEmblemChoises->mUnk_00 != 0) {
        func_020cadac(v);
        n = gEmblemChoises->mUnk_28;
        for (i = 0; i < n; i++) {
            s32 y;

            y = (12 - n * 2 + i * 4) * 8 + 6;
            r[i].mUnk_00 = 8;
            r[i].mUnk_04 = 0xf8;
            r[i].mUnk_02 = y;
            r[i].mUnk_06 = y + 0x16;
        }
        z = 0;
        for (j = 0; j < n; j++) {
            if (func_020ae244(func_020ca9dc(), r[j])) {
                if (gEmblemChoises->mUnk_20 != j) {
                    gEmblemChoises->mUnk_20 = j;
                    func_020cadac(z);
                } else {
                    gEmblemChoises->mUnk_10 = 1;
                }
                switch (gEmblemChoises->mUnk_20) {
                    case 0:
                        func_020ca984(0x10);
                        break;
                    case 1:
                        func_020ca984(0xb);
                        break;
                    case 2:
                        func_020ca984(5);
                        break;
                }
                v = 1;
            }
        }
    }
    return v;
}

void func_020cac9c(void) {
    gEmblemChoises->mUnk_1c = -1;
    gEmblemChoises->mUnk_20 = 0;
    gEmblemChoises->mUnk_24 = 0;
    gEmblemChoises->mUnk_10 = 0;
    gEmblemChoises->mUnk_14 = 0;
    gEmblemChoises->mUnk_18 = 0;
}

void func_020cac68(u16 *a, s32 b, s32 c) {
    func_020b4428(a, b, c, 1, 1, 4);
    func_020b4428(a, b, c + 1, 1, 1, 0x24);
}

void func_020cac18(void) {
    s32 n;
    u16 *v;
    s32 i;

    n = gEmblemChoises->mUnk_28;
    v = gEmblemChoises->mUnk_68->mUnk_0c;
    if (v != 0) {
        for (i = 0; i < n; i++) {
            func_020cac68(v, 2, 13 - n * 2 + i * 4);
        }
        func_020b44a4(v, 0, 0, 0x20, 0x18, 0xf);
    }
}

void func_020caba4(s32 a) {
    Unk0217b438 *p;
    s32 n;
    u16 *v;
    s32 c;

    p = gEmblemChoises;
    n = p->mUnk_28;
    v = p->mUnk_68->mUnk_0c;
    if (v != 0) {
        if (p->mUnk_10 == 0 || p->mUnk_14 >= 5) {
            c = 13 - n * 2 + a * 4;
            if (p->mUnk_24 < 0x1e) {
                func_020b4428(v, 2, c, 1, 1, 0x21);
                func_020b4428(v, 2, c + 1, 1, 1, 0x41);
            }
            func_020b44a4(v, 0, c - 1, 0x20, 4, 0xe);
        }
    }
}
#pragma thumb off
