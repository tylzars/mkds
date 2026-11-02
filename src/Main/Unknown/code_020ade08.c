#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020aa81c.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/code_020ad8e0.h"
#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/code_020ae0ac.h"
#include "Main/Unknown/code_020ae0c8.h"
#include "Main/Unknown/code_020ae0e4.h"
#include "Main/Unknown/code_020ae0f8.h"
#include "Main/Unknown/code_020ae114.h"
#include "Main/Unknown/code_020ae178.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_0212b090.h"
#include "Main/Unknown/code_0212b09c.h"
#include "Main/Unknown/unk_02168000.h"
#include "code_0213c9f8.h"
#include "code_0213ecf8.h"

#pragma optimize_for_size on

#pragma thumb on

void func_020adff0(u32 a, u16 *b, u32 c) {
    u16 v[2];
    u16 w[10];
    u16 x[12];
    u16 i;
    u32 n;
    u16 *p;

    for (i = 0; i < 11; i++) {
        b[i] = 0;
    }
    if (func_020ae114(a) != 0) {
        p = (u16 *) func_020ae0f8(a);
        if (p == NULL) {
            return;
        }
        if (c != 0) {
            n = 10;
        } else {
            n = func_020adc7c(p, &x[1]);
        }
    } else {
        if (func_020ae0e4() == 0 || func_020ae0e4() == 4) {
            p = (u16 *) func_020ae178(func_020ae0c8(a), c);
            n = 20;
        } else {
            wcsncpy(w, GetBmgEntry(func_020b47cc(data_02168100), 0x72), 9);
            swprintf(v, 2, data_0216810c, func_020ae0ac(a));
            wcsncat(w, v, 1);
            p = w;
            n = 10;
        }
    }
    if (p != NULL) {
        wcsncpy(b, p, n);
    }
}

#pragma thumb off

void func_020adfd8(Unk02180728 *a, void *b, void *c, s32 d, s32 e) {
    a->mUnk_00 = b;
    a->mUnk_04 = c;
    a->mUnk_08 = d;
    a->mUnk_0c = e;
}

void func_020adfb0(Unk02180728 *a, s32 b, s32 c, u32 d, u32 e, void *f) {
    func_02024340(a, b, c, d, e, f);
}

#pragma thumb on

void func_020adf00(u32 a) {
    Unk02023374 o;
    Unk02180728 q;
    u16 r[22];
    void *t;
    u16 *s;
    s32 i;
    s32 j;

    t = func_020b403c(0);
    s = func_0212b090();
    func_0212b09c();
    for (i = 0; i < 0x100; i++) {
        s[i] = 0;
    }
    func_02023408(&o, s, 8, 2, 4);
    func_020adfd8(&q, &o, t, 2, 0);
    func_020adff0(a, r, 0);
    for (j = -1; j < 2; j++) {
        for (i = -1; i < 2; i++) {
            func_020adfb0(&q, j + 0x20, i + 8, 2, 0x412, r);
        }
    }
    func_020adfb0(&q, 0x20, 8, 1, 0x412, r);
    func_0200ee74(func_0212b090(), 0x200);
}

void func_020adec0(u16 *a, s32 b, s32 c, s32 d) {
    u16 t;
    s32 o;
    s32 s;

    o = (b + c * 64) / 8 * 2;
    t = a[(b + c * 64) / 8];
    s = b % 8 * 2;
    t &= ~(3 << s);
    a[(b + c * 64) / 8] = t | (d << s);
}

void func_020ade08(const u16 *a, u16 *b, s32 c, s32 d, Unk020ade08_f *e) {
    s32 i;
    s32 j;
    s32 k;
    s32 p;
    s32 q;
    s32 u;
    s32 w;
    u16 v;

    for (i = 0; i < 16; i++) {
        p = i / 8;
        q = i % 8;
        for (j = 0; j < 16; j++) {
            u = j / 2;
            w = j % 2;
            v = a[i * 16 + j];
            for (k = 0; k < 4; k++) {
                switch ((u8) ((v >> (k * 4)) % 16)) {
                    case 0:
                        break;
                    case 1:
                        e(b, q * 8 + w * 4 + k, p * 8 + u, c);
                        break;
                    case 2:
                        e(b, q * 8 + w * 4 + k, p * 8 + u, d);
                        break;
                }
            }
        }
    }
}

#pragma thumb off
