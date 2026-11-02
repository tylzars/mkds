#include "Main/Unknown/code_02102674.h"

#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_02102000.h"
#include "Main/Unknown/code_021031f4.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02102eb8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f8e3c.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_02074854.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"

// non-matching: registers only. In the two pairs of accumulations (0x148/0x14c, 0x180/0x184.x) the factor is in r3
// now as in the original, but 0x148 / 0x180 is loaded after the target and kept in r6 / r5 (the original loads it
// first into r2), so the rest of each pair has other registers; the umull block after the first pair also has other
// registers.
void func_0210298c(Unk02102674 *p) {
    Unk0206bcb0 *q;
    Unk020748a8 *s;
    s32 a2;
    s32 i;
    s32 b;
    Unk0206bcb0 *r;
    s32 v;
    Vec3 w;
    s32 m;
    s32 n;

    q = p->mUnk_12c;
    s = func_020748a8();
    a2 = p->mUnk_000.mUnk_11c;
    if (a2 == 0x3f) {
        func_021031f4(p);
    }
    if (a2 == 0x8f) {
        b = data_021759c0->mUnk_3d0;
        for (i = 0; i < b; i++) {
            if (p->mUnk_130[i] == 0) {
                continue;
            }
            r = func_0207a974(i);
            if (r->mUnk_7c & 0x402020) {
                continue;
            }
            if (r->mUnk_4c & 0x10000840) {
                continue;
            }
            if (r->mUnk_48 & 0x10000) {
                continue;
            }
            func_0206924c(r, p->mUnk_130[i]);
            func_020f8e3c((u32) r, 0xf0);
        }
    }
    if (p->mUnk_160 != 0) {
        if (a2 <= data_0217c634) {
            return;
        }
        func_020f0f70(data_027e00cc + p->mUnk_000.mUnk_44, &p->mUnk_000);
        return;
    }
    if (p->mUnk_138 >= 4 && p->mUnk_138 < 0xd) {
        if ((q->mUnk_7c & 0x402020) || (q->mUnk_4c & 0x10000840) || (q->mUnk_48 & 0x10000)) {
            p->mUnk_138 = 0xd;
            func_0210300c(p);
            if (p->mUnk_198 != 0) {
                func_020f8e3c((u32) q, 0xf3);
            }
        }
    }
    if (q->mUnk_4c & 0x800) {
        p->mUnk_160 = 1;
        p->mUnk_198 = 0;
    }
    v = p->mUnk_148;
    if (p->mUnk_000.mUnk_d8 < 0x1f && p->mUnk_194 == 0 && p->mUnk_198 != 0) {
        p->mUnk_000.mUnk_d8 = (s16) (p->mUnk_000.mUnk_d8 + 7);
        if (p->mUnk_000.mUnk_d8 > 0x1f) {
            p->mUnk_000.mUnk_d8 = 0x1f;
        }
    }
    p->mUnk_16c = p->mUnk_16c - 1;
    if (p->mUnk_16c > 0) {
        m = p->mUnk_154 - p->mUnk_148;
        n = p->mUnk_158 - p->mUnk_14c;
        m = (s32) (((s64) p->mUnk_164 * m) >> 12);
        n = (s32) (((s64) p->mUnk_164 * n) >> 12);
        p->mUnk_148 += m;
        p->mUnk_14c += n;
    } else {
        s32 f;

        f = p->mUnk_168;
        p->mUnk_148 = (s32) (((s64) p->mUnk_148 * f) >> 12);
        p->mUnk_14c = (s32) (((s64) p->mUnk_14c * f) >> 12);
        if (p->mUnk_194 != 0) {
            p->mUnk_000.mUnk_d8 = (s16) (p->mUnk_000.mUnk_d8 - p->mUnk_170);
            if (p->mUnk_000.mUnk_d8 >= 1) {
                p->mUnk_16c = 0;
            } else {
                p->mUnk_16c = -1 - p->mUnk_170;
                p->mUnk_198 = 0;
                p->mUnk_000.mUnk_d8 = 1;
            }
        }
        if (p->mUnk_16c < -p->mUnk_170) {
            if (func_0210300c(p) != 0) {
                p->mUnk_160 = 1;
                p->mUnk_198 = 0;
                return;
            }
        }
    }
    v = (s32) (((s64) v * 0xccd) >> 12);
    p->mUnk_13c.x += p->mUnk_148;
    p->mUnk_13c.y += p->mUnk_14c;
    v = (s32) (((s64) (p->mUnk_148 - v) * 0x19a) >> 12);
    if (v > 0x19a) {
        v = 0x19a;
    } else if (v < -0x19a) {
        v = -0x19a;
    }
    p->mUnk_19c += v;
    p->mUnk_19c = (s32) (((s64) p->mUnk_19c * 0xeb8) >> 12);
    if (p->mUnk_19c > 0x266) {
        p->mUnk_19c = 0x266;
    } else if (p->mUnk_19c < -0x266) {
        p->mUnk_19c = -0x266;
    }
    m = p->mUnk_174 - p->mUnk_180;
    n = p->mUnk_178 - p->mUnk_184.x;
    m = (s32) (((s64) p->mUnk_184.z * m) >> 12);
    n = (s32) (((s64) p->mUnk_184.z * n) >> 12);
    p->mUnk_180 += m;
    p->mUnk_184.x += n;
    w = p->mUnk_13c;
    v = (s32) (((s64) p->mUnk_19c * 0x800) >> 12);
    w.x -= (s32) (((s64) v * w.x) >> 12);
    p->mUnk_000.mUnk_50.x = (s32) (((s64) s->mUnk_0c.x * -w.x) >> 12);
    p->mUnk_000.mUnk_50.y = (s32) (((s64) s->mUnk_0c.y * -w.x) >> 12);
    p->mUnk_000.mUnk_50.z = (s32) (((s64) s->mUnk_0c.z * -w.x) >> 12);
    func_02147fd8(w.y, &s->mUnk_00, &p->mUnk_000.mUnk_50, &p->mUnk_000.mUnk_50);
    func_02147fd8(-w.z, &s->mUnk_15c, &p->mUnk_000.mUnk_50, &p->mUnk_000.mUnk_50);
    func_02148504(&s->mUnk_24, &p->mUnk_000.mUnk_50, &p->mUnk_000.mUnk_50);
}

void func_021027ac(Unk02102674 *p, s32 param_2, Unk020e6488 *t) {
    Vec3 w;
    Unk02012f58 s;
    s32 k;
    s32 d;

    if (p->mUnk_12c == 0) {
        return;
    }
    if (p->mUnk_198 == 0) {
        return;
    }
    s = *func_020e6cf8(&p->mUnk_000.mUnk_50);
    d = p->mUnk_19c;
    if (d <= 0) {
        d = -d;
    }
    d = 0x1000 - (s32) (((s64) d * 0xa4) >> 12);
    s.mUnk_0c.x = (s32) (((s64) s.mUnk_0c.x * d) >> 12);
    s.mUnk_0c.y = (s32) (((s64) s.mUnk_0c.y * d) >> 12);
    s.mUnk_0c.z = (s32) (((s64) s.mUnk_0c.z * d) >> 12);
    func_02147fd8(p->mUnk_19c, &s.mUnk_00, &s.mUnk_0c, &s.mUnk_0c);
    w.x = (s32) (((s64) p->mUnk_180 * p->mUnk_000.mUnk_68.x) >> 12);
    w.y = (s32) (((s64) p->mUnk_184.x * p->mUnk_000.mUnk_68.y) >> 12);
    w.z = p->mUnk_000.mUnk_68.z;
    k = func_0203c5e4() != 0 ? 0xccd : 0x119a;
    w.x = (s32) (((s64) w.x * k) >> 12);
    w.y = (s32) (((s64) w.y * k) >> 12);
    d = p->mUnk_000.mUnk_d8;
    if (d != 0x1f) {
        t->mUnk_14 = t->mUnk_14 & ~0x1f0000;
        t->mUnk_14 = t->mUnk_14 | ((u32) (u16) d << 16);
    }
    func_020e6a18(t);
    func_020e67c4(t, &s, &w, 0, 0x1f);
    if (p->mUnk_000.mUnk_d8 == 0x1f) {
        return;
    }
    t->mUnk_14 = t->mUnk_14 & ~0x1f0000;
    t->mUnk_14 = t->mUnk_14 | 0x1f0000;
}

void func_02102764(void *param_1, Unk02102674 *param_2, void *param_3) {
    func_020fecdc(param_1, param_2, param_3);
    if (param_2 == 0) {
        return;
    }
    if (param_3 == 0) {
        return;
    }
    func_020fe8ac(param_2->mUnk_000.mUnk_44);
}

void func_02102744(Unk02102674 *p) {
    func_020f8e78(p);
    func_02102eb8((u32) p, 1);
}

#pragma thumb on
void func_02102718(void) {
    s32 i;
    Unk0215a3b0 *p;

    data_0217c634 = 0xf;
    for (i = 0, p = data_0215a3b0; i < 0x11; i++) {
        data_0217c634 += p->mUnk_08 + p->mUnk_0a;
        p++;
    }
}
#pragma thumb off

void func_02102674(void) {
    s32 i;

    data_0217c630 = func_02036bec(func_020364e0(func_020364e8()), 0x52);
    for (i = 0; i <= 0x28; i++) {
        data_0217c630[i] = (u16) (((0x28 - i) << 12) / (0x29 - i));
    }
    for (i -= 5; i <= 0x28; i++) {
        data_0217c630[i] = (u16) ((data_0217c630[i] + data_0217c630[i - 1]) >> 1);
    }
}
