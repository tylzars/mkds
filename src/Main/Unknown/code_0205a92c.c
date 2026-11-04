#include "Main/Unknown/code_0205a92c.h"
#include "Main/Unknown/code_0205a548.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_0219b580.h"
#include "code_0214d018.h"

void func_0205ae8c(u32 a) {
    u8 j;
    u8 n;
    u8 f;
    u8 m;
    s32 s;
    s32 t;
    Unk0217aa18 *g;
    Unk0217aa14 *p;

    g = data_0217aa18;
    p = data_0217aa14;
    s = g->mUnk_00[(u8) a];
    n = p->mUnk_104[s].mUnk_86_1;
    if (s < 0) {
        return;
    }
    j = 0;
    for (j = 0; j < (s32) data_021759c0->mKartCount; j++) {
        if (j != a) {
            t = g->mUnk_00[j];
            m = p->mUnk_104[t].mUnk_86_1;
            if (t >= 0 && m < n) {
                f = 0;
                if ((p->mUnk_0fc & (1 << (u8) t)) != 0 && (p->mUnk_749 & (1 << (u8) t)) == 0) {
                    f = 1;
                }
                if (f != 0) {
                    n = n - 1;
                }
            }
        }
    }
    p->mUnk_104[s].mUnk_86_1 = n;
}

void func_0205ad88(void) {
    s32 i;
    s32 j;
    Unk0217aa14_324 *e;

    for (i = 0; i < 16; i++) {
        for (j = 0; j < 4; j++) {
            e = &data_0217aa14->mUnk_3e4[i][j];
            e->mUnk_08 = 0;
            e->mUnk_00 = 0;
            e->mUnk_09 = 15;
            e->mUnk_0a = 0;
            e->mUnk_0b = 0;
            MemFill(e->mUnk_04, 0, 20);
            data_0217aa14->mUnk_6e4[i][j] = 0;
        }
        e = &data_0217aa14->mUnk_324[i];
        e->mUnk_08 = 0;
        e->mUnk_00 = 0;
        e->mUnk_09 = 15;
        e->mUnk_0a = 0;
        e->mUnk_0b = 0;
        MemFill(e->mUnk_04, 0, 20);
    }
    data_0217aa14->mUnk_724 = 0x30;
}

BOOL func_0205ad44(void) {
    u16 i;

    for (i = 0; i < 16; i++) {
        if (data_0217aa14->mUnk_324[i].mUnk_08 == 0) {
            return TRUE;
        }
    }
    return FALSE;
}

void func_0205ac38(void) {
    u16 i;
    u8 *a;
    u8 *b;
    u16 v;
    Unk0217aa14_324 *e;
    Unk0217aa14_754_04 *q;
    u8 c;

    v = 0;
    q = (void *) &data_0217aa14->mUnk_754->mUnk_04;
    a = q->mUnk_28;
    b = a + 16;
    for (i = 0; i < 16; i++) {
        e = &data_0217aa14->mUnk_324[i];
        if (e->mUnk_08 == 0 || e->mUnk_08 == 2 || e->mUnk_09 == 15) {
            c = 15;
        } else {
            c = (e->mUnk_09 & 0x1f) | ((e->mUnk_0a << 5) & 0xe0);
        }
        *a++ = c;
        switch (e->mUnk_08) {
            case 0:
                break;
            case 1:
                if (e->mUnk_0b != 0 && 0x30 - (v + e->mUnk_0b) >= 0) {
                    MemCopy(e->mUnk_04, b, e->mUnk_0b);
                    v = v + e->mUnk_0b;
                    b += e->mUnk_0b;
                }
                break;
            case 2:
                break;
        }
    }
    data_0217aa14->mUnk_724 = 0x30 - v;
}

void func_0205ab78(void) {
    u16 i;
    Unk0217aa14_324 *e;

    for (i = 0; i < 16; i++) {
        e = &data_0217aa14->mUnk_324[i];
        if (e->mUnk_09 == 15) {
            continue;
        }
        switch (e->mUnk_08) {
            case 0:
                break;
            case 2:
                if ((u32) e->mUnk_00 + 30 < (u32) data_0217aa14->mUnk_728) {
                    e->mUnk_08 = 0;
                    e->mUnk_00 = 0;
                    e->mUnk_09 = 15;
                    e->mUnk_0a = 0;
                    e->mUnk_0b = 0;
                    MemFill(e->mUnk_04, 0, 20);
                }
                break;
            case 1:
                if ((u32) e->mUnk_00 < (u32) data_0217aa14->mUnk_728) {
                    e->mUnk_08 = 2;
                }
                break;
        }
    }
}

void func_0205aa60(void) {
    u8 i;
    u16 j;
    u8 *s;
    u8 *d;
    Unk0217aa14_324 *e;
    u8 c;

    for (i = 0; i < 4; i++) {
        if (i != func_ov000_0219bb50() && (data_0217aa14->mUnk_749 & (1 << i)) != 0 &&
            data_0217aa14->mUnk_104[i].mUnk_86_0 != 0) {
            s = (u8 *) &data_0217aa14->mUnk_104[i] + 0x28;
            d = s + 16;
            for (j = 0; j < 16; j++) {
                c = *s++;
                e = &data_0217aa14->mUnk_3e4[j][i];
                e->mUnk_09 = c & 0x1f;
                e->mUnk_0a = (c & 0xe0) >> 5;
                if (e->mUnk_09 == 15) {
                    e->mUnk_0b = 0;
                } else {
                    e->mUnk_0b = func_020fa0e8(e->mUnk_09, e->mUnk_0a);
                }
                if (e->mUnk_0b != 0) {
                    MemCopy(d, e->mUnk_04, e->mUnk_0b);
                    d += e->mUnk_0b;
                }
            }
        }
    }
}

void func_0205a92c(void) {
    u8 i;
    u16 j;
    Unk0217aa14 *p;
    Unk0217aa14_324 *e;
    u8 *f;
    u8 *v;

    for (i = 0; i < 4; i++) {
        if (i != func_ov000_0219bb50() && (data_0217aa14->mUnk_749 & (1 << i)) != 0 &&
            data_0217aa14->mUnk_104[i].mUnk_86_0 != 0) {
            for (j = 0; j < 16; j++) {
                p = data_0217aa14;
                e = &p->mUnk_3e4[j][i];
                f = &p->mUnk_6e4[j][i];
                if (e->mUnk_09 == 15) {
                    *f = 0;
                } else if (*f == 0) {
                    v = NULL;
                    func_0205b954(i);
                    if (e->mUnk_0b != 0) {
                        v = e->mUnk_04;
                    }
                    if (e->mUnk_0a <= 1) {
                        func_0205a630(i);
                    }
                    func_020fe5b8(e->mUnk_09, e->mUnk_0a, v, data_0217aa18->mUnk_06[i]);
                    *f = 1;
                }
            }
        }
    }
}
