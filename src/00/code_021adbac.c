#include "00/code_021adbac.h"
#include "00/code_021a9228.h"
#include "00/code_021ae01c.h"
#include "00/code_021aefa8.h"
#include "00/code_021af550.h"
#include "code_0200db4c.h"
#include "code_0200f5ac.h"
#include "code_0200fc8c.h"
#include "code_02134d30.h"
#include "Main/Unknown/unk_0216f000.h"

s32 func_ov000_021adbac(void) {
    Unk021a998c *s;
    s32 r;

    s = *(Unk021a998c **) data_0216ff5c.mUnk_04->mUnk_a4;
    if (s != NULL) {
        if (s->mUnk_09 != 0) {
            r = func_ov000_021a9358(s);
        } else {
            r = s->mReceiveBufferLength;
        }
        if (r == 0 && s->mState != 4 && (u8) (s->mState + 0xf6) > 1) {
            return -1;
        }
        return r;
    }
    return 0;
}

s32 func_ov000_021adbf4(const u8 *a, s32 b) {
    Unk021a998c *s;
    s32 r;

    s = *(Unk021a998c **) data_0216ff5c.mUnk_04->mUnk_a4;
    if (s != NULL) {
        if (s->mUnk_60 != 0) {
            r = func_ov000_021adc64(s->mUnk_5c, s->mUnk_60, a, b);
            if (r < s->mUnk_60) {
                memmove(s->mUnk_5c, s->mUnk_5c + r, s->mUnk_60 - r);
                s->mUnk_60 -= r;
                return 0;
            }
            r -= s->mUnk_60;
            s->mUnk_60 = 0;
            return r;
        }
        return func_ov000_021adc64(a, b, NULL, 0);
    }
    return 0;
}

s32 func_ov000_021adc64(const u8 *a, s32 b, const u8 *c, s32 d) {
    Unk021a998c *s;
    u8 t;
    s32 r;

    s = *(Unk021a998c **) data_0216ff5c.mUnk_04->mUnk_a4;
    if (s != NULL) {
        t = s->mState;
        if (t == 0xa) {
            if (b != 0) {
                func_ov000_021af70c((u8 *) a, b, s);
            }
            if (d != 0) {
                func_ov000_021af70c((u8 *) c, d, s);
            }
            r = b + d;
        } else if (t == 0xb) {
            if (b != 0) {
                func_ov000_021af7e4((u8 *) a, b, s);
            }
            if (d != 0) {
                func_ov000_021af7e4((u8 *) c, d, s);
            }
            r = b + d;
        } else if (s->mUnk_09 != 0) {
            r = func_ov000_021a9280((u8 *) a, b, (u8 *) c, d, s);
        } else {
            r = func_ov000_021adcec(a, b, c, d, s);
        }
        if (data_ov000_021b6364 == 0) {
            return r;
        }
    }
    return 0;
}

s32 func_ov000_021adcec(const u8 *a, u32 b, const u8 *c, s32 d, void *e) {
    Unk021a998c *s;
    s32 f;
    BOOL g;
    s32 h;
    u32 j;
    s32 i;
    u32 k;

    s = e;
    f = 0;
    s->mUnk_34 = 0;
    g = FALSE;
    j = func_0200f5ac() >> 16;
    while (data_ov000_021b6388() != 0 && b != 0 && s->mState == 4 && (s32) ((u32) (func_0200f5ac() >> 16) - j) < 0x9f) {
        h = s->mUnk_28;
        func_ov000_021ade40(a, b, c, d, s, g);
        k = func_0200f5ac() >> 16;
        do {
            func_ov000_021b04d4();
        } while (data_ov000_021b6388() != 0 && s->mState == 4 && s->mUnk_28 != s->mUnk_30 &&
                 (s32) ((u32) (func_0200f5ac() >> 16) - k) < 0xf && (g == FALSE || s->mUnk_2c == 0));
        i = s->mUnk_30 - h;
        f += i;
        if (i != 0) {
            j = func_0200f5ac() >> 16;
        }
        s->mUnk_28 = s->mUnk_30;
        if (s->mState == 4 && s->mUnk_2c == 0 && i == 0) {
            if (g == FALSE) {
                k = func_0200f5ac() >> 16;
                while (data_ov000_021b6388() != 0 && (s32) ((u32) (func_0200f5ac() >> 16) - k) < 0xf) {
                    func_ov000_021b04d4();
                    if (s->mUnk_2c != 0) {
                        break;
                    }
                }
                if (s->mUnk_2c == 0) {
                    g = TRUE;
                }
            }
        } else {
            g = FALSE;
        }
        if (i >= b) {
            i -= b;
            a = c + i;
            b = d - i;
            c = NULL;
            d = 0;
        } else {
            a += i;
            b -= i;
        }
    }
    return f;
}

void func_ov000_021ade40(const u8 *a, s32 b, const u8 *c, s32 d, Unk021a998c *e, s32 f) {
    if (func_ov000_021ade6c(a, b, e, f) != 0 && d != 0) {
        func_ov000_021ade6c(c, d, e, 0);
    }
}

s32 func_ov000_021ade6c(const u8 *a, s32 b, Unk021a998c *c, s32 d) {
    u32 e;
    u32 f;
    s32 g;
    s32 h;
    s32 i;

    if (d != 0) {
        e = 1;
    } else {
        e = c->mUnk_2c;
    }
    g = c->mUnk_34;
    h = g * 2 + 4;
    while (b != 0 && c->mState == 4) {
        f = c->mUnk_2e;
        if (f >= e) {
            f = e;
        }
        if (data_ov000_021b6370 < f) {
            f = data_ov000_021b6370;
        }
        if (d == 0) {
            f &= ~1;
        }
        if (b < f) {
            f = b;
        }
        i = h + (c->mUnk_34 - g);
        g = c->mUnk_34;
        h = i - 1;
        if (i == 0) {
            f = 0;
        }
        if (f == 0) {
            break;
        }
        e -= f;
        func_ov000_021af550((u8 *) a, f, c, 0x18, 0);
        func_0200dd94();
        a += f;
        b -= f;
    }
    return f;
}

void func_ov000_021adf00(u32 a) {
    Unk021a998c *s;

    s = *(Unk021a998c **) data_0216ff5c.mUnk_04->mUnk_a4;
    if (s != NULL) {
        if (s->mUnk_09 != 0) {
            func_ov000_021a9394(a, s);
        } else {
            func_ov000_021adf30(a, s);
        }
    }
}

void func_ov000_021adf30(u32 a, Unk021a998c *b) {
    u32 c;
    u32 d;
    u8 *e;
    u8 *f;

    c = IrqDisable();
    d = b->mReceiveBufferLength;
    if (a >= d) {
        b->mReceiveBufferLength = 0;
    } else {
        e = b->mReceiveBuffer;
        f = e;
        f += a;
        b->mReceiveBufferLength = (d -= a);
        memmove(e, &(*f), d);
    }
    IrqRestore(c);
    if (b->mState != 0xa && b->mState != 0xb && b->mReceiveBufferLength == 0) {
        func_ov000_021aefb4(b, 0x1b);
    }
}

u8 *func_ov000_021adf78(u32 *a) {
    Unk021a998c *s;

    s = *(Unk021a998c **) data_0216ff5c.mUnk_04->mUnk_a4;
    if (s != NULL) {
        if ((u8) (s->mState + 0xf6) <= 1) {
            return func_ov000_021ae01c(a, s);
        }
        if (s->mUnk_09 != 0) {
            return func_ov000_021a93e0((s32 *) a, s);
        }
        return func_ov000_021adfc8(a, s);
    }
    *a = 0;
    return NULL;
}

u8 *func_ov000_021adfc8(u32 *a, Unk021a998c *b) {
    if (b->mReceiveBufferLength == 0 && b->mState == 4) {
        while (b->mReceiveBufferLength == 0 && b->mState == 4) {
            b->mUnk_04 = 2;
            func_0200e01c(NULL);
        }
    } else {
        func_0200dd94();
    }
    *a = b->mReceiveBufferLength;
    if (*a != 0) {
        return b->mReceiveBuffer;
    }
    return NULL;
}
