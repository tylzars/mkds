#include "Main/Unknown/code_0203e74c.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203f2b4.h"
#include "Main/Unknown/code_0203f280.h"
#include "Main/Unknown/code_0203f320.h"
#include "Main/Unknown/code_0203f334.h"
#include "Main/Unknown/code_0204a904.h"
#include "Main/Unknown/code_0204a928.h"
#include "Main/Unknown/code_020401ac.h"
#include "Main/Unknown/code_0205a92c.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020c70ec.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_0219b580.h"
#include "code_02147cd8.h"

void func_0203e74c(u16 param_1) {
    if (data_021759c0->mUnk_08 != 4) {
        return;
    }
    func_0203e788(param_1, 0);
}

void func_0203e788(s32 a, s32 b) {
    Unk0206bcb0 *q;
    Unk0217aa1c_144_00 t;
    s32 s;
    BOOL f;
    Unk0217561c_14 *e;
    e = (Unk0217561c_14 *) ((u8 *) &data_0217561c->mUnk_14[0] + a * 0x8c);
    s = e->mUnk_00;
    f = FALSE;
    switch (s) {
        case 1:
        case 2:
        case 3:
            f = TRUE;
            break;
    }
    if (f != FALSE) {
        return;
    }
    if ((e->mUnk_30 & 0x10) != 0) {
        return;
    }
    if ((e->mUnk_30 & 0x20) != 0) {
        return;
    }
    q = func_0207a974(a);
    e = (Unk0217561c_14 *) ((u8 *) &data_0217561c->mUnk_14[0] + a * 0x8c);
    data_0217561c->mUnk_000[0].mUnk_04 = 0;
    func_0203f5f0(&t.mUnk_02, &t.mUnk_03, &t.mUnk_00, 0, data_0217561c->mUnk_000[0].mUnk_00);
    e->mUnk_0c[5] = t;
    if ((e->mUnk_30 & 1) != 0) {
        data_0217561c->mUnk_4e0 = b;
        q->mUnk_7c |= 0x20000000;
        q->mUnk_48 &= ~0x2000000;
        if (b == 0) {
            e->mUnk_30 |= 0x10;
            data_0217561c->mUnk_4fa = 0;
            if (data_021759c0->mUnk_08 == 4) {
                func_020a12b8();
            }
        } else {
            e->mUnk_30 |= 0x20;
            data_0217561c->mUnk_4fc = 0;
            if (data_021759c0->mUnk_08 == 4) {
                ((void (*)(s32)) func_020a16d0)(a);
            }
        }
    }
    func_0203e9a0(e, b == 0);
    if (func_0203ef58() == 0) {
        return;
    }
    switch (data_021759c0->mUnk_08) {
        case 2:
            func_020a12b8();
            return;
        case 4:
            func_0203eb38();
            return;
        case 5:
            func_0203ecf0();
            return;
        default:
            func_0203ee28();
            return;
        case 1:
            return;
    }
}

void func_0203e9a0(Unk0217561c_14 *a, s32 b) {
    Unk0217aa1c_144_00 *t;
    s32 c;
    s32 m;
    s16 d;
    c = data_021759c0->mUnk_68[(u32) (a->mUnk_3c << 24) >> 28].mUnk_08.mUnk_0c;
    if (b != 0) {
        a->mUnk_00 = 1;
    } else {
        a->mUnk_00 = 3;
    }
    switch (data_02175628[c].mSourceKind) {
        case 2:
            func_0204a928(&data_02175628[c].mUnk_28);
            break;
        case 1:
            func_0204a904(&data_02175628[c].mUnk_28);
            break;
    }
    a->mUnk_30 |= 8;
    if ((a->mUnk_30 & 1) != 0 && (a->mUnk_30 & 0x10) == 0) {
        func_020c7164();
    }
    t = &a->mUnk_0c[5];
    if (b != 0) {
        a->mUnk_2c = (t->mUnk_02 * 0x3c + t->mUnk_03) * 1000 + t->mUnk_00;
    } else if (data_021759c0->mUnk_08 != 5) {
        a->mUnk_2c = 0x5b8d80;
    }
    m = data_021759c0->mUnk_08;
    if (m == 0 || m == 4) {
        if ((a->mUnk_30 & 1) != 0) {
            a->mUnk_3e = func_020408f0((u32) (a->mUnk_3c << 24) >> 28);
            d = a->mUnk_3e;
            if (data_021759c0->mUnk_08 == 4) {
                data_0217aa1c->mUnk_140 = d;
            } else {
                data_0217aa1c->mUnk_140 += d;
            }
        }
    }
    data_0217561c->mUnk_000[0].mUnk_0e++;
}

void func_0203eb38(void) {
    u16 i;
    Unk0217561c_14 *p;
    Unk0206cdd4_B *q;
    s32 s;
    BOOL f;
    u32 g;
    u8 *r;
    Unk0217aa1c_144_00 *t;
    u32 h;
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        s = ((Unk0217561c_000 *) ((u8 *) data_0217561c + i * 0x8c))->mUnk_14;
        f = FALSE;
        switch (s) {
            case 1:
            case 2:
            case 3:
                f = TRUE;
                break;
        }
        if (f == FALSE) {
            p = (Unk0217561c_14 *) ((u8 *) &data_0217561c->mUnk_14[0] + i * 0x8c);
            t = &p->mUnk_0c[5];
            h = data_0217561c->mUnk_000[0].mUnk_00;
            if (data_021759c0->mUnk_08 == 0) {
                if (p->mUnk_44 > 0) {
                    h = (u32) (h * ReciprocalFixed12(p->mUnk_44)) >> 12;
                    if (h > 0x57e40) {
                        h = 0x57e40;
                    }
                } else {
                    h = 0x57e40;
                }
            }
            func_0203f5f0(&t->mUnk_02, &t->mUnk_03, &t->mUnk_00, 0, h);
            g = 1;
            r = (u8 *) &data_021759c0->mUnk_028;
            q = func_0207a6b0();
            switch (r[7]) {
                case 4:
                    if (r[0xf] > (u32) q->mUnk_04) {
                        g = 0;
                    }
                    break;
                case 6:
                    if (((u32) (p->mUnk_3c << 28) >> 28) != 1) {
                        g = 0;
                    }
                    break;
            }
            if (g != 0) {
                u32 k = (u32) (p->mUnk_3c << 24) >> 28;
                if (data_021759c0->mUnk_08 == 4) {
                    func_0203e788(k, 0);
                }
            } else {
                func_0203e788((u32) (p->mUnk_3c << 24) >> 28, 4);
            }
        }
    }
    data_0217561c->mUnk_000[0].mUnk_0e = data_021759c0->mKartCount;
}

void func_0203ecf0(void) {
    u16 i;
    Unk0217561c_14 *p;
    s32 s;
    BOOL f;
    BOOL u;
    BOOL v;
    Unk0217aa1c_144_00 *t;
    u32 h;
    u = FALSE;
    v = FALSE;
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        s = ((Unk0217561c_000 *) ((u8 *) data_0217561c + i * 0x8c))->mUnk_14;
        f = FALSE;
        switch (s) {
            case 1:
            case 2:
            case 3:
                f = TRUE;
                break;
        }
        if (f == FALSE && s != 4) {
            p = (Unk0217561c_14 *) ((u8 *) &data_0217561c->mUnk_14[0] + i * 0x8c);
            t = &p->mUnk_0c[5];
            h = data_0217561c->mUnk_000[0].mUnk_00;
            if (data_021759c0->mUnk_08 == 0) {
                if (p->mUnk_44 > 0) {
                    h = (u32) (h * ReciprocalFixed12(p->mUnk_44)) >> 12;
                    if (h > 0x57e40) {
                        h = 0x57e40;
                    }
                } else {
                    h = 0x57e40;
                }
            }
            func_0203f5f0(&t->mUnk_02, &t->mUnk_03, &t->mUnk_00, u, h);
            func_0205ae8c(i);
            func_0203e9a0(p, v);
        }
    }
    data_0217561c->mUnk_000[0].mUnk_0e = data_021759c0->mKartCount;
}

void func_0203ee28(void) {
    u16 i;
    Unk0217561c_14 *p;
    s32 s;
    BOOL f;
    BOOL u;
    BOOL v;
    Unk0217aa1c_144_00 *t;
    u32 h;
    u = FALSE;
    v = FALSE;
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        s = ((Unk0217561c_000 *) ((u8 *) data_0217561c + i * 0x8c))->mUnk_14;
        f = FALSE;
        switch (s) {
            case 1:
            case 2:
            case 3:
                f = TRUE;
                break;
        }
        if (f == FALSE && s != 4) {
            p = (Unk0217561c_14 *) ((u8 *) &data_0217561c->mUnk_14[0] + i * 0x8c);
            t = &p->mUnk_0c[5];
            h = data_0217561c->mUnk_000[0].mUnk_00;
            if (data_021759c0->mUnk_08 == 0) {
                if (p->mUnk_44 > 0) {
                    h = (u32) (h * ReciprocalFixed12(p->mUnk_44)) >> 12;
                    if (h > 0x57e40) {
                        h = 0x57e40;
                    }
                } else {
                    h = 0x57e40;
                }
            }
            func_0203f5f0(&t->mUnk_02, &t->mUnk_03, &t->mUnk_00, u, h);
            func_0203e9a0(p, v);
        }
    }
    data_0217561c->mUnk_000[0].mUnk_0e = data_021759c0->mKartCount;
}

s32 func_0203ef58(void) {
    BOOL r;
    u16 i;
    s32 s;
    s32 f;
    s32 v;
    s32 n;
    s32 m;
    Unk021759c0 *o;
    Unk0217561c *q;
    o = data_021759c0;
    switch (o->mUnk_08) {
        case 0:
            r = TRUE;
            for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
                f = 0;
                s = o->mUnk_68[i].mUnk_08.mUnk_00;
                if ((u32) s <= 3 && ((1 << s) & 0xd) != 0) {
                    f = 1;
                }
                if (f != 0) {
                    s = data_0217561c->mUnk_000[i].mUnk_14;
                    f = 0;
                    switch (s) {
                        case 1:
                        case 2:
                        case 3:
                            f = 1;
                            break;
                    }
                    if (f == 0) {
                        r = FALSE;
                        break;
                    }
                }
            }
            break;
        case 3:
            r = TRUE;
            q = data_0217561c;
            if (q->mUnk_000[0].mUnk_0e < (s32) func_0203f320() - (q->mUnk_000[0].mUnk_10 + 1)) {
                for (i = 0; i < func_0203f320(); i++) {
                    if (func_0203f2dc(i) != 0 && func_0203c880(i) == 0) {
                        if (func_0203f2b4(i) == 0) {
                            r = FALSE;
                            break;
                        }
                    }
                }
            }
            if (r == FALSE && func_0203f2a0() == 1) {
                if (func_0203c880(func_0203f280()) != 0) {
                    r = TRUE;
                }
            }
            break;
        case 5:
            v = data_0217aa18->mUnk_06[func_ov000_0219bb50()];
            if (v < 0) {
                r = FALSE;
            } else {
                n = data_021759c0->mKartCount;
                q = data_0217561c;
                m = q->mUnk_000[0].mUnk_10;
                if (n - m <= 1) {
                    r = FALSE;
                } else {
                    s = q->mUnk_000[(u16) v].mUnk_14;
                    f = 0;
                    switch (s) {
                        case 1:
                        case 2:
                        case 3:
                            f = 1;
                            break;
                    }
                    if (f == 0) {
                        r = q->mUnk_000[0].mUnk_0e + m >= n - 1;
                    } else {
                        r = q->mUnk_000[0].mUnk_0e + m >= n;
                    }
                }
            }
            break;
        case 1:
            r = FALSE;
            switch (data_0217561c->mUnk_000[0].mUnk_14) {
                case 1:
                case 2:
                case 3:
                    r = TRUE;
                    break;
            }
            break;
        case 2:
            r = TRUE;
            for (i = 0; i < (u32) o->mKartCount; i++) {
                f = 0;
                s = o->mUnk_68[i].mUnk_08.mUnk_00;
                if ((u32) s <= 3 && ((1 << s) & 0xd) != 0) {
                    f = 1;
                }
                if (f != 0) {
                    if (func_020a1084(i) == 0) {
                        r = FALSE;
                        break;
                    }
                }
                o = data_021759c0;
            }
            break;
        case 4:
            r = FALSE;
            if (o->mUnk_2f == 6 && data_0217561c->mUnk_000[0].mUnk_0e != 0) {
                r = TRUE;
            }
            break;
        default:
            r = FALSE;
            break;
    }
    return r;
}
