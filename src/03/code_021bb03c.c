#include "03/code_021bb03c.h"

#include "03/code_021bcedc.h"
#include "03/code_021be3b8.h"
#include "03/code_021be418.h"
#include "code_0200db4c.h"
#include "code_0214d018.h"
#include "03/unk_021d8000.h"
#include "code_0200f5ac.h"
#include "code_021329f8.h"
#include "string.h"
#include "code_02134398.h"
#include "03/unk_021d3000.h"
#include "03/code_021b7000.h"
#include "Main/Unknown/code_02133000.h"
#include "03/code_021b7bb4.h"
#include "03/code_021bb000.h"
#include "03/code_021bd000.h"
#include "03/code_021be000.h"
#include "00/code_021a8aa8.h"
#include "code_02139f70.h"
#include "03/unk_021d6000.h"
#include "code_0200fc8c.h"
#include "03/code_021be610.h"
#include "00/code_021a6fa8.h"
#include "00/code_021a86bc.h"
#include "code_0200f790.h"
#include "00/unk_021b6000.h"

u32 func_ov003_021be604(void) {
    return data_ov003_021d8bfc;
}

u32 func_ov003_021be5cc(u32 a, s32 b) {
    u32 result;
    if (b > 0) {
        ThreadLockWait(data_ov003_021d8c8c);
        result = data_ov003_021d8bd4(b);
        ThreadLockUnlock(data_ov003_021d8c8c);
        return result;
    }
    return 0;
}

void func_ov003_021be59c(u32 a, s32 b, s32 c) {
    if (b != 0 && c > 0) {
        ThreadLockWait(data_ov003_021d8c8c);
        data_ov003_021d8bdc(b);
        ThreadLockUnlock(data_ov003_021d8c8c);
    }
}

void func_ov003_021be568(void) {
    u32 a = IrqDisable();
    s32 i;

    data_ov003_021d8c38 = 0;
    data_ov003_021d8c3c = 0;
    for (i = 0; i < 4; i++) {
        data_ov003_021d8c6c[i] = 0;
    }
    IrqRestore(a);
}

u32 func_ov003_021be528(void) {
    u32 a = IrqDisable();
    s32 b = data_ov003_021d8c3c;
    u32 c;

    if (data_ov003_021d8c38 == b) {
        c = 0;
    } else {
        c = data_ov003_021d8c6c[b];
        b++;
        data_ov003_021d8c3c = b;
        if (b >= 4) {
            data_ov003_021d8c3c = 0;
        }
    }
    IrqRestore(a);
    return c;
}

void func_ov003_021be4ec(u32 v1, u32 v2) {
    s32 a = data_ov003_021d8c3c;
    s32 b = data_ov003_021d8c38;
    s32 c = b + 1;

    if (c == a) {
        return;
    }
    if (b == a + 3) {
        return;
    }
    data_ov003_021d8c6c[b] = v1;
    data_ov003_021d8c38 = c;
    if (c >= 4) {
        data_ov003_021d8c38 = 0;
    }
}

void func_ov003_021be4e0(u32 value) {
    func_ov003_021be4ec(value, 0);
}

s32 func_ov003_021be418(u32 param_0) {
    u32 a = 1;
    s32 b;
    u32 c;
    u32 d;
    u32 e;
    u32 f;
    enum { K0 } g;
    u32 h;

    data_ov003_021d8c40 = param_0;
    func_ov003_021be568();
    e = param_0 * 0xd0;
    data_ov003_021d8c24 = (void *) data_ov003_021d8bd4(e + 0x24d0 + param_0 * 0xc0);
    if (data_ov003_021d8c24 == NULL) {
        return -1;
    }
    g = 0x1f;
    d = ((u32) data_ov003_021d8c24 + g) & ~0x1f;
    data_ov003_021d8c10 = (void *) d;
    f = e + 0x2490;
    h = d + f;
    data_ov003_021d8c2c = (Unk021d8c2c *) ((h + g) & ~0x1f);
    if (func_ov003_021be610(func_ov003_021be4ec, (void *) d, f) == 0) {
        return -2;
    }
    do {
        func_0200dc3c(10);
        while ((c = func_ov003_021be528()) != 0) {
            if (c == 4 || c == 5) {
            } else if (c == 6) {
                a = 0;
                b = 1;
            } else {
                a = 0;
                b = -2;
            }
        }
    } while (a != 0);
    return b;
}

u32 func_ov003_021be3b8(void) {
    u32 a = 1;
    u32 b;

    if (func_ov003_021be7b8() != 0) {
        do {
            func_0200dc3c(10);
            while ((b = func_ov003_021be528()) != 0) {
                switch (b) {
                    case 4:
                    case 5:
                        break;
                    case 20:
                        a = 0;
                        break;
                    default:
                        a = 0;
                        break;
                }
            }
        } while (a != 0);
    }
    if (data_ov003_021d8c24 != NULL) {
        data_ov003_021d8bdc(data_ov003_021d8c24);
        data_ov003_021d8c24 = NULL;
    }
    return 1;
}

s32 func_ov003_021be264(void) {
    Unk0200fb08 v1;
    Unk021d8c2c *p0;
    s32 a = 1;
    s32 b = -2;
    BOOL c;
    s32 d;

    p0 = data_ov003_021d8c2c + data_ov003_021d8be8;
    if (p0 == NULL) {
        return 0;
    }
    if (func_ov003_021be708(p0, NULL, 0x30000) == 0) {
        return -2;
    }
    func_0200fb08(&v1);
    func_0200f950(&v1, 0x3fec42, (void (*)(void *)) func_ov003_021be4e0, (void *) 0x12);
    c = FALSE;
    do {
        if (func_ov003_021bb354() >= data_ov003_021d68b8) {
            b = -3;
            break;
        }
        if (data_ov003_021d8be0 != 0) {
            b = -8;
            break;
        }
        func_0200dc3c(10);
        while ((d = func_ov003_021be528()) != 0) {
            switch (d) {
                case 12:
                    a = c;
                    b = 1;
                    break;
                case 13:
                    if (data_ov003_021d8be0 != 0) {
                        a = c;
                        b = -8;
                    } else if (func_ov003_021be708(p0, NULL, 0x30000) == 0) {
                        return b;
                    }
                    break;
                case 4:
                case 5:
                case 18:
                case 19:
                    break;
                default:
                    a = c;
                    break;
            }
        }
    } while (a != 0);
    func_0200f8b8(&v1);
    while (func_ov003_021be528() != 0) {
    }
    if (b > 0) {
        data_ov003_021d8bf0 = 1;
        if ((s32) func_ov000_021a8c94(data_ov003_021d691c) < 0) {
            b = -2;
        } else {
            data_ov003_021d8bf4 = 1;
        }
    }
    return b;
}

void func_ov003_021be1fc(void) {
    BOOL a;
    u32 b;
    a = TRUE;
    if (data_ov003_021d8bf0 != 0) {
        if (func_ov003_021be820() != 0) {
            do {
                func_0200dc3c(10);
                while ((b = func_ov003_021be528()) != 0) {
                    switch (b) {
                        case 4:
                        case 5:
                            break;
                        case 0xe:
                            a = FALSE;
                            break;
                        default:
                            a = FALSE;
                            break;
                    }
                }
            } while (a != FALSE);
        }
        data_ov003_021d8bf0 = 0;
    }
    if (data_ov003_021d8bf4 != 0) {
        data_ov003_021d8bf4 = 0;
        func_ov000_021a8c8c();
    }
}

s32 func_ov003_021be028(Unk021bdd3c *a, Unk021bdd3c *b, u32 *c) {
    BOOL e;
    BOOL d;
    BOOL f;
    BOOL g;
    Unk021bdd3c_Entry *h;
    Unk021bdd3c_Entry *i;
    u32 l;
    u32 j;
    u32 k;
    u32 m;
    e = FALSE;
    d = FALSE;
    h = a->mUnk_04;
    i = b->mUnk_04;
    j = 0;
    for (; j < a->mUnk_00; j++) {
        char n[0x22] = {0};
        memcpy(n, h->mUnk_04, 0x20);
        n[h->mUnk_00] = 0;
        k = 0;
        l = b->mUnk_00;
        if (k < l) {
            m = h->mUnk_00;
            do {
                if (m == 0 || m > 0x20) {
                    break;
                }
                if (m == 1 && (h->mUnk_04[0] == 0 || h->mUnk_04[0] == 0x20)) {
                    break;
                }
                if (memcmp(n, i->mUnk_04, strlen(n)) == 0 && memcmp(h->mUnk_28.mUnk_00, i->mUnk_28.mUnk_00, 4) == 0 &&
                    h->mUnk_2e != i->mUnk_2e && h->mUnk_2e == 0) {
                    e = TRUE;
                    break;
                }
                i++;
                k++;
            } while (k < l);
        }
        if (e != FALSE) {
            break;
        }
        h++;
        i = b->mUnk_04;
    }
    if (e == FALSE) {
        char o[0x22] = {0};
        f = FALSE;
        g = FALSE;
        h = a->mUnk_04;
        i = b->mUnk_04;
        k = 0;
        for (; k < b->mUnk_00; k++) {
            memcpy(o, i->mUnk_04, 0x20);
            o[i->mUnk_00] = 0;
            if (memcmp(o, data_ov003_021d68c0, strlen(data_ov003_021d68c0)) == 0 && i->mUnk_2e == 0) {
                g = TRUE;
                break;
            }
            i++;
        }
        j = 0;
        for (; j < a->mUnk_00; j++) {
            memcpy(o, h->mUnk_04, 0x20);
            o[h->mUnk_00] = 0;
            if (strlen(o) == strlen(data_ov003_021d68c0) &&
                memcmp(o, data_ov003_021d68c0, strlen(data_ov003_021d68c0)) == 0 && h->mUnk_2e == 0) {
                f = TRUE;
                break;
            }
            h++;
        }
        if (f != FALSE && g == FALSE) {
            e = TRUE;
        }
    }
    if (e != FALSE) {
        *c = j;
        d = TRUE;
    }
    return d;
}

s32 func_ov003_021bdd3c(void) {
    s32 a;
    s32 b;
    s32 h;
    s32 g;
    BOOL c;
    s32 d;
    u32 e;
    u32 f;
    Unk021bdd3c *j;
    Unk021bdd3c *k;
    Unk021d8c2c *l;
    Unk021bdd3c_Entry *m;
    u8 *s;
    u8 *t;
    u32 i;
    u8 o[0x20];
    Unk0200fb08 n;
    a = 0;
    j = NULL;
    a = -1;
    k = NULL;
    i = 0;
    e = data_ov003_021d8c40 * 0x30 + 0x34;
    j = func_ov003_021bb328(1, e);
    if (j == NULL) {
        goto end;
    }
    k = func_ov003_021bb328(1, e);
    if (k == NULL) {
        goto end;
    }
    b = 0;
    while (b < 30 && data_ov003_021d8be0 == 0) {
        if (func_ov003_021bb354() >= data_ov003_021d68b8) {
            break;
        }
        if (func_ov003_021be860(NULL, NULL, 0, 0x30bffe) == 0) {
            a = -2;
            goto end;
        }
        func_0200fb08(&n);
        func_0200f950(&n, 0xffb10, (void (*)(void *)) func_ov003_021be4e0, (void *) 0x13);
        c = TRUE;
        a = 0;
        do {
            func_0200dc3c(10);
            if (func_ov003_021bb354() >= data_ov003_021d68b8 || data_ov003_021d8be0 != 0) {
                break;
            }
            while ((f = func_ov003_021be528()) != 0) {
                switch (f) {
                    case 19:
                        c = FALSE;
                        break;
                    case 5:
                        d = func_ov003_021be96c((u8 *) data_ov003_021d8c2c, data_ov003_021d8c40);
                        if (d > a) {
                            a = d;
                            func_0200f8b8(&n);
                            func_0200f950(&n, 0xffb10, (void (*)(void *)) func_ov003_021be4e0, (void *) 0x13);
                        }
                        break;
                    case 10:
                        c = FALSE;
                        break;
                    case 4:
                    case 8:
                    case 18:
                        break;
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                    case 6:
                    case 7:
                    case 9:
                    case 11:
                    case 12:
                    case 13:
                    case 14:
                    case 15:
                    case 16:
                    case 17:
                    default:
                        c = FALSE;
                        break;
                }
            }
        } while (c != FALSE);
        func_0200f8b8(&n);
        while (func_ov003_021be528() != 0) {
        }
        if (data_ov003_021d8be0 != 0) {
            break;
        }
        g = 0;
        if (a >= data_ov003_021d8c40) {
            a = -6;
            goto end;
        }
        h = 0;
        l = data_ov003_021d8c2c;
        if (a > 0) {
            do {
                memcpy(j->mUnk_04[g].mUnk_04, l->mUnk_0c, 0x20);
                j->mUnk_04[g].mUnk_00 = l->mUnk_0a;
                j->mUnk_04[g].mUnk_04[l->mUnk_0a] = 0;
                j->mUnk_04[g].mUnk_2e = (l->mUnk_2c & 0x10) ? 1 : 0;
                s = (u8 *) &l->mUnk_04;
                t = (u8 *) &j->mUnk_04[g].mUnk_28;
                t[0] = s[0];
                t[1] = s[1];
                t[2] = s[2];
                t[3] = s[3];
                t[4] = s[4];
                t[5] = s[5];
                g++;
                h++;
                l++;
            } while (h < a);
        }
        j->mUnk_00 = a;
        if (data_ov003_021d8c08 != 1) {
            g = func_ov003_021be028(j, k, &i);
            if (g != 0) {
                m = &j->mUnk_04[i];
                data_ov003_021d8be8 = i;
                strcpy(data_ov003_021d8ce4, m->mUnk_04);
                t = (u8 *) &data_ov003_021d8c5c;
                s = (u8 *) &m->mUnk_28;
                t[0] = s[0];
                t[1] = s[1];
                t[2] = s[2];
                t[3] = s[3];
                t[4] = s[4];
                t[5] = s[5];
                func_ov003_021bb29c(o, (const s8 *) &data_ov003_021d8c5c);
                break;
            }
        }
        memcpy(k, j, e);
        data_ov003_021d8c08 = 2;
        func_ov003_021bb03c();
        b++;
    }
    if (b >= 30 || func_ov003_021bb354() > data_ov003_021d68b8) {
        a = -3;
    } else if (data_ov003_021d8be0 != 0) {
        a = -8;
    } else {
        a = 1;
    }
end:
    if (j != NULL) {
        func_ov003_021bb314(j);
    }
    if (k != NULL) {
        func_ov003_021bb314(k);
    }
    return a;
}

s32 func_ov003_021bdd1c(s32 v1, const Unk021bdcd8 *v2, const u8 *param_2, const void *v3, u32 v4) {
    s32 a;
    a = func_ov000_021a9018(v1, v3, v4, 0, v2);
    if (a < 0) {
        a = -4;
    }
    return a;
}

s32 func_ov003_021bdcd8(s32 v1, const void *v2, u32 v3) {
    Unk021bdcd8 a;
    u8 b[4];
    a.mUnk_00 = 8;
    a.mUnk_01 = 2;
    a.mUnk_04 = -1;
    a.mUnk_02 = 0x1e6;
    func_ov000_021a8bb0(func_ov000_021a8830(), b);
    return func_ov003_021bdd1c(v1, &a, b, v2, v3);
}

s32 func_ov003_021bdccc(s32 descriptor, const void *unused, const void *data, u32 size) {
    return func_ov003_021bdcd8(descriptor, data, size);
}

u8 *func_ov003_021bdc5c(const u8 *p, u32 *a, s32 *b) {
    u32 c;
    const u8 *d;
    const u8 *e;
    c = 0;
    *a = func_ov003_021b7c44_inline(*(u16 *) p);
    *b = func_ov003_021b7c44_inline(*(u16 *) (p + 2));
    d = p + 6 + *b;
    for (e = p; e < d; e++) {
        c += *e;
    }
    if ((u16) c != func_ov003_021b7c44_inline(*(u16 *) d)) {
        return NULL;
    }
    return (u8 *) p + 6;
}

u8 *func_ov003_021bdc08(u8 **p, u8 *a, u32 *b, s32 *c) {
    u8 *d;
    d = *p;
    if (d >= a) {
        return NULL;
    }
    *b = func_ov003_021b7c44_inline(*(u16 *) d);
    *c = func_ov003_021b7c44_inline(*(u16 *) (d + 2));
    d += 4;
    *p = d + (((*c + 0xb) & ~7) - 4);
    return d;
}

u8 *func_ov003_021bdbd0(const u8 *p, u32 *a, s32 *b) {
    u8 *c;
    c = (u8 *) p + 8;
    return func_ov003_021bdc08(&c, c + func_ov003_021b7c44_inline(*(u16 *) p), a, b);
}

s32 func_ov003_021bdb0c(u8 *p, u32 a, u8 *b, u32 c, const void *d) {
    u8 *e;
    u8 *f;
    u32 g;
    e = p;
    g = 0;
    b[0] = 0;
    b[1] = 0;
    b[2] = 0;
    b[3] = 0;
    b[4] = 0;
    b[5] = 0;
    b[6] = 0;
    b[7] = 0;
    *(u16 *) b = func_ov003_021b7c44_inline(c - 8);
    if (d != NULL) {
        func_ov003_021bccd0(p + 6, b, c, d, 0x10);
        c += 8;
    } else {
        memcpy(p + 6, b, c);
    }
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    *(u16 *) p = func_ov003_021b7c44_inline(a);
    *(u16 *) (p + 2) = func_ov003_021b7c44_inline(c);
    e += 6;
    e += c;
    for (f = p; f < e; f++) {
        g += *f;
    }
    *(u16 *) e = func_ov003_021b7c44_inline(g);
    return e + 2 - p;
}

u8 *func_ov003_021bdaa4(u8 *p, u32 a, const void *b, u32 c) {
    u32 d;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    *(u16 *) p = func_ov003_021b7c44_inline(a);
    d = ((c + 0xb) & ~7) - 4;
    *(u16 *) (p + 2) = func_ov003_021b7c44_inline(c);
    p = (u8 *) p + 4;
    memset(p, 0, d);
    memcpy(p, b, c);
    return p + d;
}

s32 func_ov003_021bda78(u8 *p, u32 a, const void *b, u32 c) {
    s32 d;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    d = func_ov003_021bdaa4(p + 8, a, b, c) - p;
    *(u16 *) p = d - 8;
    return d;
}

typedef struct Unk021bd894_buf {
    /* 0 */ u16 mUnk_00;
    /* 2 */ Unk021d68c8 mUnk_02;
} Unk021bd894_buf;

BOOL func_ov003_021bd998(const u8 *p, s32 *a) {
    u32 b;
    u32 g;
    s32 h;
    u32 i;
    s32 j;
    u32 c;
    s32 k;
    u8 *f;
    u8 *d;
    u8 *e;
    f = func_ov003_021bdc5c(p, &i, &j);
    b = 0;
    g = 0;
    h = 0;
    if (f == NULL) {
        return FALSE;
    }
    if (i != 1) {
        return FALSE;
    }
    d = f + j;
    f += 8;
    e = func_ov003_021bdc08(&f, d, &c, &k);
    if (e != NULL) {
        do {
            switch (c) {
                case 1:
                    b = func_ov003_021b7c44_inline(*(u16 *) e);
                    break;
                case 2:
                    g = func_ov003_021b7c44_inline(*(u16 *) e);
                    break;
                case 5:
                    h = func_ov003_021b7c44_inline(*(u16 *) e);
                    break;
            }
            e = func_ov003_021bdc08(&f, d, &c, &k);
        } while (e != NULL);
    }
    if (b != 1 || g != 1) {
        return FALSE;
    }
    if (h >= 1) {
        *a = 1;
    } else {
        *a = 0;
    }
    return TRUE;
}

s32 func_ov003_021bd938(const u8 *p, u32 a, u8 *b, const void *c) {
    u32 d;
    s32 e;
    u8 *f;
    f = func_ov003_021bdc5c(p, &d, &e);
    if (f == NULL) {
        return 0;
    }
    if (d != a) {
        return 0;
    }
    if (c != NULL) {
        func_ov003_021bcadc(b, f, e, c, 0x10);
        e -= 8;
    } else {
        memcpy(b, f, e);
    }
    return e;
}

s32 func_ov003_021bd894(u8 *p) {
    Unk021bd894_buf a;
    u8 *b;
    a.mUnk_00 = 0x100;
    a.mUnk_02 = data_ov003_021d68c8;
    b = func_ov003_021bdaa4(data_ov003_021d68ac, 1, &a, 2);
    b = func_ov003_021bdaa4(b, 2, &a, 2);
    if (data_ov003_021d8c20 != 0) {
        b = func_ov003_021bdaa4(b, 5, &a, 2);
    }
    b = func_ov003_021bdaa4(b, 3, &a.mUnk_02, 7);
    if (data_ov003_021d8c20 != 0) {
        b = func_ov003_021bdaa4(b, 4, &data_ov003_021d8c54, 6);
    }
    return func_ov003_021bdb0c(p, 2, data_ov003_021d9104, b - data_ov003_021d68ac + 8, NULL);
}

u32 func_ov003_021bd884(void *p) {
    func_0200fe58(p);
    return 0x1u;
}

s32 func_ov003_021bd768(u8 *a, void *b) {
    u8 c[6];
    u8 d[6];
    u8 e[0x20];
    u8 f[0x20];
    __memcpy(a + 0xc, &data_ov003_021d6974, sizeof(Unk021d6974));
    __memcpy(c, &data_ov003_021d8c5c, sizeof(Unk021d8c54));
    c[0] &= 0xfd;
    func_ov003_021bd884(d);
    __memcpy(&data_ov003_021d8c54, d, sizeof(Unk021d8c54));
    if (memcmp(c, d, 6) <= 0) {
        __memcpy(a, d, sizeof(Unk021d8c54));
        __memcpy(a + 6, c, sizeof(Unk021d8c54));
    } else {
        __memcpy(a, c, sizeof(Unk021d8c54));
        __memcpy(a + 6, d, sizeof(Unk021d8c54));
    }
    if (data_ov003_021d68b0 != 0) {
        func_ov003_021bb29c(e, (const s8 *) d);
        func_ov003_021bb29c(f, (const s8 *) c);
    }
    return 1;
}

s32 func_ov003_021bd59c(u8 *p) {
    u8 *c;
    BOOL b;
    u8 *a;
    u32 d;
    s32 e;
    u8 *f;
    u8 *l;
    a = p + 8;
    b = FALSE;
    c = a + func_ov003_021b7c44_inline(*(u16 *) p);
    f = func_ov003_021bdc08(&a, c, &d, &e);
    while (f != NULL) {
        switch (d) {
            case 0x201:
                __clear(&data_ov003_021d8fb0, 0x20);
                memcpy(&data_ov003_021d8fb0, f, e);
                b = TRUE;
                break;
            case 0x202:
                data_ov003_021d8fb0.mUnk_2c = func_ov003_021b7c44_inline(*(u16 *) f);
                break;
            case 0x203: {
                s32 g;
                s32 h;
                u8 *i;
                g = func_ov003_021b7c44_inline(*(u16 *) f);
                h = 0;
                i = (u8 *) data_ov003_021d8eb0;
                for (; h < 4; h++) {
                    *(u32 *) (i + 0x15c) = g;
                    i += 0x28;
                }
                break;
            }
            case 0x204: {
                u32 g;
                s32 h;
                g = func_ov003_021b7c44_inline(*(u16 *) f);
                h = 0;
                l = (u8 *) data_ov003_021d8eb0;
                for (; h < 4; h++) {
                    *(u32 *) (l + 0x160) = g;
                    l += 0x28;
                }
                break;
            }
            case 0x205:
                data_ov003_021d8fb0.mUnk_30 = func_ov003_021b7c44_inline(*(u16 *) f);
                break;
            case 0x206:
            case 0x207:
            case 0x208:
            case 0x209:
                memset(data_ov003_021d9014 + (d - 0x206) * 0x28, 0, 0x20);
                if (data_ov003_021d8fb0.mUnk_5c == 1) {
                    u8 *k;
                    s32 j;
                    k = data_ov003_021d9014 + (d - 0x206) * 0x28;
                    for (j = 0; j < e; j++) {
                        k += func_ov003_021bb2d8(k, *f++);
                    }
                } else {
                    memcpy(data_ov003_021d9014 + (d - 0x206) * 0x28, f, e);
                }
                break;
            case 0x20a:
                __clear(&data_ov003_021d90ac, 0x48);
                memcpy(&data_ov003_021d90ac, f, e);
                break;
        }
        f = func_ov003_021bdc08(&a, c, &d, &e);
    }
    return b;
}

BOOL func_ov003_021bd4cc(u8 *a, const s8 *b, s32 c) {
    u32 d;
    s32 e;
    d = 0;
    e = 0;
    for (; e < c; e++) {
        switch (b[e]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                d += b[e] - '0';
                break;
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
                d += b[e] - 'W';
                break;
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
                d += b[e] - '7';
                break;
            default:
                return FALSE;
        }
        if (e % 2 == 0) {
            d <<= 4;
        } else {
            a[e / 2] = d;
            d = 0;
        }
    }
    return TRUE;
}

s32 func_ov003_021bd338(void) {
    s32 a;
    s32 b;
    char c[0x21];
    char *d;
    u8 *e;
    u8 *f;
    a = 1;
    strcpy(data_ov003_021d8dc8.mUnk_00, data_ov003_021d8fb0.mUnk_00);
    switch (data_ov003_021d8fb0.mUnk_2c) {
        case 0:
            data_ov003_021d8dc8.mUnk_20 = 0;
            break;
        case 1:
            if (data_ov003_021d8fb0.mUnk_30 == 0) {
                a = -7;
                break;
            }
            data_ov003_021d8dc8.mUnk_24 = data_ov003_021d8fb0.mUnk_30;
            b = 0;
            d = c;
            e = data_ov003_021d9014;
            f = data_ov003_021d8dc8.mUnk_28[0];
            for (; b < 4; b++) {
                memcpy(d, e, 0x20);
                c[0x20] = 0;
                switch (strlen(d)) {
                    case 0:
                        break;
                    case 5:
                        data_ov003_021d8dc8.mUnk_20 = 1;
                        *(Unk021bd338_5 *) f = *(Unk021bd338_5 *) d;
                        break;
                    case 10:
                        data_ov003_021d8dc8.mUnk_20 = 1;
                        func_ov003_021bd4cc(f, (s8 *) d, 10);
                        break;
                    case 13:
                        data_ov003_021d8dc8.mUnk_20 = 2;
                        *(Unk021bd338_13 *) f = *(Unk021bd338_13 *) d;
                        break;
                    case 26:
                        data_ov003_021d8dc8.mUnk_20 = 2;
                        func_ov003_021bd4cc(f, (s8 *) d, 26);
                        break;
                    case 16:
                        data_ov003_021d8dc8.mUnk_20 = 3;
                        *(Unk021bd338_16 *) f = *(Unk021bd338_16 *) d;
                        break;
                    case 32:
                        data_ov003_021d8dc8.mUnk_20 = 3;
                        func_ov003_021bd4cc(f, (s8 *) d, 32);
                        break;
                    default:
                        a = -7;
                        break;
                }
                e += 0x28;
                f += 0x20;
            }
            break;
        case 2:
            data_ov003_021d8dc8.mUnk_20 = 4;
            __memcpy(&data_ov003_021d8dc8.mUnk_a8, &data_ov003_021d90ac.mUnk_00, sizeof(data_ov003_021d8dc8.mUnk_a8));
            break;
        case 3:
            data_ov003_021d8dc8.mUnk_20 = 5;
            __memcpy(&data_ov003_021d8dc8.mUnk_a8, &data_ov003_021d90ac.mUnk_00, sizeof(data_ov003_021d8dc8.mUnk_a8));
            break;
        default:
            a = -7;
            break;
    }
    return a;
}

s32 func_ov003_021bcf1c(void) {
    u32 m;
    s32 b;
    s32 a;
    s32 e;
    BOOL c;
    u8 *g;
    Unk021bdcd8 k;
    Unk021bdcd8 l;
    u32 h;
    s32 i;
    u32 j;
    b = 0;
    a = -5;
    m = 0;
    e = 0;
    c = FALSE;
    data_ov003_021d8bec = 1;
    while (c == FALSE && data_ov003_021d8be0 == 0) {
        func_0200dc3c(500);
        switch (data_ov003_021d8bec) {
            case 1:
                a = func_ov003_021bdd3c();
                if (a != 1) {
                    c = TRUE;
                } else {
                    data_ov003_021d8c08 = 3;
                    func_ov003_021bb03c();
                    data_ov003_021d8bec = 2;
                }
                break;
            case 2:
                a = func_ov003_021be264();
                if (a != 1) {
                    c = TRUE;
                } else {
                    data_ov003_021d8bec = 3;
                }
                break;
            case 3:
                b = func_ov000_021a918c(2, 2, 0);
                if (b < 0) {
                    a = -2;
                    c = TRUE;
                    break;
                }
                __clear(&k, 8);
                k.mUnk_00 = 8;
                k.mUnk_01 = 2;
                k.mUnk_02 = 0x1e6;
                k.mUnk_04 = 0;
                a = func_ov000_021a916c(b, &k);
                if (a < 0) {
                    a = -2;
                    c = TRUE;
                } else {
                    data_ov003_021d8bec = 4;
                }
                break;
            case 4:
                if (func_ov003_021bb354() >= data_ov003_021d68b8) {
                    func_ov000_021a9008(b);
                    a = -3;
                    c = TRUE;
                    break;
                }
                l.mUnk_00 = 8;
                func_ov003_021bd768(data_ov003_021d8c7c, &l);
                if (func_ov000_021a90a0(b, data_ov003_021d9904, 0x800, 4, &l) > 0) {
                    if (func_ov003_021bd998(data_ov003_021d9904, (s32 *) &data_ov003_021d8c20) != FALSE) {
                        data_ov003_021d68b8 = func_ov003_021bb354() + 30000;
                        data_ov003_021d8bec = 5;
                        data_ov003_021d8c08 = 4;
                        func_ov003_021bb03c();
                    }
                }
                break;
            case 5:
                data_ov003_021d8be4 = func_ov003_021bd894(data_ov003_021d9904);
                func_ov003_021bdccc(b, &l, data_ov003_021d9904, data_ov003_021d8be4);
                m = func_ov003_021bb354();
                data_ov003_021d8bec = 6;
                break;
            case 6:
                if (func_ov003_021bb354() >= data_ov003_021d68b8) {
                    func_ov000_021a9008(b);
                    a = -4;
                    c = TRUE;
                    break;
                }
                if (func_ov000_021a90a0(b, data_ov003_021d9904, 0x800, 4, &l) > 0 &&
                    func_ov003_021bd938(data_ov003_021d9904, 3, data_ov003_021d9104, data_ov003_021d8c7c) != 0) {
                    g = func_ov003_021bdbd0(data_ov003_021d9104, &h, &i);
                    if (h == 0x101) {
                        j = func_ov003_021bb354();
                        *(Unk021d8ca4 *) data_ov003_021d8ca4 = *(Unk021d8ca4 *) g;
                        func_ov003_021bb378(data_ov003_021d8cac, (const u8 *) &j, 4);
                        e = 0;
                        data_ov003_021d8bec = 7;
                        data_ov003_021d8c08 = 5;
                        data_ov003_021d68b8 = -1;
                        func_ov003_021bb03c();
                    }
                } else if (func_ov003_021bb354() >= m + 1000) {
                    data_ov003_021d8bec = 5;
                }
                break;
            case 7:
                data_ov003_021d8c04 = func_ov003_021bda78(data_ov003_021d9104, 0x102, data_ov003_021d8cac, 8);
                data_ov003_021d8be4 = func_ov003_021bdb0c(data_ov003_021d9904, 4, data_ov003_021d9104,
                                                          data_ov003_021d8c04, data_ov003_021d8c7c);
                func_ov003_021bdccc(b, &l, data_ov003_021d9904, data_ov003_021d8be4);
                m = func_ov003_021bb354();
                __clear(data_ov003_021d8eb0, 0x254);
                data_ov003_021d8bec = 8;
                break;
            case 8:
                if (func_ov000_021a90a0(b, data_ov003_021d9904, 0x800, 4, &l) > 0) {
                    data_ov003_021d8c04 =
                        func_ov003_021bd938(data_ov003_021d9904, 5, data_ov003_021d9104, data_ov003_021d8ca4);
                    if (data_ov003_021d8c04 != 0 && func_ov003_021bd59c(data_ov003_021d9104) != 0) {
                        if (*(s8 *) data_ov003_021d8fb0.mUnk_00 != 0) {
                            data_ov003_021d8bd0 = 1;
                        } else {
                            data_ov003_021d8bd0 = 0;
                        }
                        e = 0;
                        data_ov003_021d8bec = 9;
                        break;
                    }
                }
                if (func_ov003_021bb354() >= m + 1000) {
                    e++;
                    if (e >= 10) {
                        func_ov000_021a9008(b);
                        a = -2;
                        c = TRUE;
                    } else {
                        data_ov003_021d8bec = 7;
                    }
                }
                break;
            case 9:
                data_ov003_021d8c04 = func_ov003_021bda78(data_ov003_021d9104, 0x301, &data_ov003_021d8bd0, 1);
                data_ov003_021d8be4 = func_ov003_021bdb0c(data_ov003_021d9904, 6, data_ov003_021d9104,
                                                          data_ov003_021d8c04, data_ov003_021d8ca4);
                if (func_ov003_021be604() != 7) {
                    m = func_ov003_021bb354() + 1000;
                    e = 10;
                    data_ov003_021d8bec = 10;
                } else {
                    func_ov003_021bdccc(b, &l, data_ov003_021d9904, data_ov003_021d8be4);
                    m = func_ov003_021bb354();
                    data_ov003_021d8bec = 10;
                }
                break;
            case 10:
                if (func_ov003_021bb354() >= m + 1000) {
                    e++;
                    if (e >= 10) {
                        c = TRUE;
                        a = func_ov003_021bd338();
                    } else {
                        data_ov003_021d8bec = 9;
                    }
                }
                break;
        }
    }
    if (b != 0) {
        func_ov000_021a9008(b);
    }
    if (data_ov003_021d8be0 != 0) {
        a = -8;
    }
    return a;
}

void func_ov003_021bcedc(void) {
    int a;

    a = func_ov003_021bcf1c();
    *(s32 *) &data_ov003_021d8c48 = a;
    func_ov003_021be1fc();
    if (a == 1) {
        *(s32 *) &data_ov003_021d8c08 = 6;
    } else {
        *(s32 *) &data_ov003_021d8c08 = 7;
    }
    *(s32 *) &data_ov003_021d68b8 = -1;
    func_ov003_021bb03c();
}

typedef struct Unk021bccd0_block {
    /* 0 */ u8 mUnk_00[8];
} Unk021bccd0_block;

BOOL func_ov003_021bccd0(u8 *param_1, u8 *param_2, u32 param_3, u8 *param_4, int param_5) {
    u8 a[16];
    u64 b;
    u32 c[80];
    u32 d[2];
    int i;
    int h;
    int f;
    int g;
    s64 t;
    u8 *p;
    u8 *q;
    enum { K0 } k;

    d[0] = 0xa6a6a6a6;
    d[1] = 0xa6a6a6a6;
    if ((param_3 & 7) != 0 || (param_5 & 7) != 0) {
        return FALSE;
    }
    f = param_3 >> 3;
    if (f < 2) {
        return FALSE;
    }
    g = func_ov003_021bc7a8(c, param_4, param_5 << 3);
    memcpy(param_1 + 8, param_2, param_3);
    p = a;
    q = (u8 *) d;
    k = 8;
    do {
        *p++ = *q++;
    } while (--k != 0);
    for (h = 0; h < 6; h++) {
        for (i = 1; i <= f; i++) {
            p = param_1 + (u32) i * 8;
            *(Unk021bccd0_block *) (a + 8) = *(Unk021bccd0_block *) p;
            func_ov003_021bc1c4(c, g, a, a);
            t = (s64) f * (s32) h + (s32) i;
            b = ((((u64) t & 0x00000000000000ffULL) << 56) | (((u64) t & 0x000000000000ff00ULL) << 40) |
                 (((u64) t & 0x0000000000ff0000ULL) << 24) | (((u64) t & 0x00000000ff000000ULL) << 8) |
                 (((u64) t & 0x000000ff00000000ULL) >> 8) | (((u64) t & 0x0000ff0000000000ULL) >> 24) |
                 (((u64) t & 0x00ff000000000000ULL) >> 40) | (((u64) t & 0xff00000000000000ULL) >> 56));
            func_ov003_021bca90(a, (u8 *) &b, a);
            *(Unk021bccd0_block *) p = *(Unk021bccd0_block *) (a + 8);
        }
    }
    *(Unk021bccd0_block *) param_1 = *(Unk021bccd0_block *) a;
    return TRUE;
}

BOOL func_ov003_021bcadc(u8 *param_1, u8 *param_2, u32 param_3, u8 *param_4, int param_5) {
    u8 a[16];
    u64 b;
    u32 c[80];
    u32 d[2];
    int i;
    int h;
    int f;
    int g;
    BOOL e;
    s64 t;
    u8 *p;
    u8 *q;
    enum { K0 } k;

    e = TRUE;
    d[0] = 0xa6a6a6a6;
    d[1] = 0xa6a6a6a6;
    if ((param_3 & 7) != 0 || (param_5 & 7) != 0) {
        return FALSE;
    }
    f = (param_3 - 1) >> 3;
    if (f < 2) {
        return FALSE;
    }
    g = func_ov003_021bc5e4(c, param_4, param_5 << 3);
    p = a;
    q = param_2;
    k = 8;
    do {
        *p++ = *q++;
    } while (--k != 0);
    memcpy(param_1, param_2 + 8, param_3 - 1);
    for (h = 5; h >= 0; h--) {
        for (i = f; i > 0; i--) {
            t = (s64) f * (s32) h + (s32) i;
            b = ((((u64) t & 0x00000000000000ffULL) << 56) | (((u64) t & 0x000000000000ff00ULL) << 40) |
                 (((u64) t & 0x0000000000ff0000ULL) << 24) | (((u64) t & 0x00000000ff000000ULL) << 8) |
                 (((u64) t & 0x000000ff00000000ULL) >> 8) | (((u64) t & 0x0000ff0000000000ULL) >> 24) |
                 (((u64) t & 0x00ff000000000000ULL) >> 40) | (((u64) t & 0xff00000000000000ULL) >> 56));
            func_ov003_021bca90(a, (u8 *) &b, a);
            p = param_1 + (i - 1) * 8;
            {
                u8 *r = p;
                q = a + 8;
                k = 8;
                do {
                    *q++ = *r++;
                } while (--k != 0);
            }
            func_ov003_021bbd9c(c, g, a, a);
            {
                u8 *r = a + 8;
                k = 8;
                do {
                    *p++ = *r++;
                } while (--k != 0);
            }
        }
    }
    if (memcmp((u8 *) d, a, 8) != 0) {
        e = FALSE;
    }
    return e;
}

void func_ov003_021bca90(u8 *a, u8 *b, u8 *c) {
    *c = *a ^ *b;
    c[1] = a[1] ^ b[1];
    c[2] = a[2] ^ b[2];
    c[3] = a[3] ^ b[3];
    c[4] = a[4] ^ b[4];
    c[5] = a[5] ^ b[5];
    c[6] = a[6] ^ b[6];
    c[7] = a[7] ^ b[7];
    return;
}

int func_ov003_021bc7a8(u32 *a, u8 *b, int c) {
    int i = 0;
    u32 v1;

    a[0] = ((u32) b[0] << 24) ^ ((u32) b[1] << 16) ^ ((u32) b[2] << 8) ^ (u32) b[3];
    a[1] = ((u32) b[4] << 24) ^ ((u32) b[5] << 16) ^ ((u32) b[6] << 8) ^ (u32) b[7];
    a[2] = ((u32) b[8] << 24) ^ ((u32) b[9] << 16) ^ ((u32) b[10] << 8) ^ (u32) b[11];
    a[3] = ((u32) b[12] << 24) ^ ((u32) b[13] << 16) ^ ((u32) b[14] << 8) ^ (u32) b[15];
    if (c == 128) {
        for (;;) {
            v1 = a[3];
            a[4] = a[0] ^ (data_ov003_021d52bc[(v1 >> 16) & 0xff] & 0xff000000) ^
                   (data_ov003_021d52bc[(v1 >> 8) & 0xff] & 0x00ff0000) ^
                   (data_ov003_021d52bc[v1 & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[v1 >> 24] & 0x000000ff) ^
                   data_ov003_021d3694[i];
            a[5] = a[1] ^ a[4];
            a[6] = a[2] ^ a[5];
            a[7] = a[3] ^ a[6];
            if (++i == 10) {
                return 10;
            }
            a += 4;
        }
    }
    a[4] = ((u32) b[16] << 24) ^ ((u32) b[17] << 16) ^ ((u32) b[18] << 8) ^ (u32) b[19];
    a[5] = ((u32) b[20] << 24) ^ ((u32) b[21] << 16) ^ ((u32) b[22] << 8) ^ (u32) b[23];
    if (c == 192) {
        for (;;) {
            v1 = a[5];
            a[6] = a[0] ^ (data_ov003_021d52bc[(v1 >> 16) & 0xff] & 0xff000000) ^
                   (data_ov003_021d52bc[(v1 >> 8) & 0xff] & 0x00ff0000) ^
                   (data_ov003_021d52bc[v1 & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[v1 >> 24] & 0x000000ff) ^
                   data_ov003_021d3694[i];
            a[7] = a[1] ^ a[6];
            a[8] = a[2] ^ a[7];
            a[9] = a[3] ^ a[8];
            if (++i == 8) {
                return 12;
            }
            a[10] = a[4] ^ a[9];
            a[11] = a[5] ^ a[10];
            a += 6;
        }
    }
    a[6] = ((u32) b[24] << 24) ^ ((u32) b[25] << 16) ^ ((u32) b[26] << 8) ^ (u32) b[27];
    a[7] = ((u32) b[28] << 24) ^ ((u32) b[29] << 16) ^ ((u32) b[30] << 8) ^ (u32) b[31];
    if (c == 256) {
        for (;;) {
            v1 = a[7];
            a[8] = a[0] ^ (data_ov003_021d52bc[(v1 >> 16) & 0xff] & 0xff000000) ^
                   (data_ov003_021d52bc[(v1 >> 8) & 0xff] & 0x00ff0000) ^
                   (data_ov003_021d52bc[v1 & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[v1 >> 24] & 0x000000ff) ^
                   data_ov003_021d3694[i];
            a[9] = a[1] ^ a[8];
            a[10] = a[2] ^ a[9];
            a[11] = a[3] ^ a[10];
            if (++i == 7) {
                return 14;
            }
            v1 = a[11];
            a[12] = a[4] ^ (data_ov003_021d52bc[v1 >> 24] & 0xff000000) ^
                    (data_ov003_021d52bc[(v1 >> 16) & 0xff] & 0x00ff0000) ^
                    (data_ov003_021d52bc[(v1 >> 8) & 0xff] & 0x0000ff00) ^
                    (data_ov003_021d52bc[v1 & 0xff] & 0x000000ff);
            a[13] = a[5] ^ a[12];
            a[14] = a[6] ^ a[13];
            a[15] = a[7] ^ a[14];
            a += 8;
        }
    }
    return i;
}

int func_ov003_021bc5e4(u32 *a, u8 *b, int c) {
    int i, j, r;
    u32 v1;

    r = func_ov003_021bc7a8(a, b, c);
    for (i = 0, j = 4 * r; i < j; i += 4, j -= 4) {
        v1 = a[i];
        a[i] = a[j];
        a[j] = v1;
        v1 = a[i + 1];
        a[i + 1] = a[j + 1];
        a[j + 1] = v1;
        v1 = a[i + 2];
        a[i + 2] = a[j + 2];
        a[j + 2] = v1;
        v1 = a[i + 3];
        a[i + 3] = a[j + 3];
        a[j + 3] = v1;
    }
    for (i = 1; i < r; i++) {
        a += 4;
        a[0] = data_ov003_021d56bc[data_ov003_021d52bc[a[0] >> 24] & 0xff] ^
               data_ov003_021d5abc[data_ov003_021d52bc[(a[0] >> 16) & 0xff] & 0xff] ^
               data_ov003_021d36bc[data_ov003_021d52bc[(a[0] >> 8) & 0xff] & 0xff] ^
               data_ov003_021d3abc[data_ov003_021d52bc[a[0] & 0xff] & 0xff];
        a[1] = data_ov003_021d56bc[data_ov003_021d52bc[a[1] >> 24] & 0xff] ^
               data_ov003_021d5abc[data_ov003_021d52bc[(a[1] >> 16) & 0xff] & 0xff] ^
               data_ov003_021d36bc[data_ov003_021d52bc[(a[1] >> 8) & 0xff] & 0xff] ^
               data_ov003_021d3abc[data_ov003_021d52bc[a[1] & 0xff] & 0xff];
        a[2] = data_ov003_021d56bc[data_ov003_021d52bc[a[2] >> 24] & 0xff] ^
               data_ov003_021d5abc[data_ov003_021d52bc[(a[2] >> 16) & 0xff] & 0xff] ^
               data_ov003_021d36bc[data_ov003_021d52bc[(a[2] >> 8) & 0xff] & 0xff] ^
               data_ov003_021d3abc[data_ov003_021d52bc[a[2] & 0xff] & 0xff];
        a[3] = data_ov003_021d56bc[data_ov003_021d52bc[a[3] >> 24] & 0xff] ^
               data_ov003_021d5abc[data_ov003_021d52bc[(a[3] >> 16) & 0xff] & 0xff] ^
               data_ov003_021d36bc[data_ov003_021d52bc[(a[3] >> 8) & 0xff] & 0xff] ^
               data_ov003_021d3abc[data_ov003_021d52bc[a[3] & 0xff] & 0xff];
    }
    return r;
}

void func_ov003_021bc1c4(u32 *a, int b, u8 *c, u8 *d) {
    u32 s0, s1, s2, s3, t0, t1, t2, t3;
    int r;

    s0 = (((u32) c[0] << 24) ^ ((u32) c[1] << 16) ^ ((u32) c[2] << 8) ^ (u32) c[3]) ^ a[0];
    s1 = (((u32) c[4] << 24) ^ ((u32) c[5] << 16) ^ ((u32) c[6] << 8) ^ (u32) c[7]) ^ a[1];
    s2 = (((u32) c[8] << 24) ^ ((u32) c[9] << 16) ^ ((u32) c[10] << 8) ^ (u32) c[11]) ^ a[2];
    s3 = (((u32) c[12] << 24) ^ ((u32) c[13] << 16) ^ ((u32) c[14] << 8) ^ (u32) c[15]) ^ a[3];
    r = b >> 1;
    for (;;) {
        t0 = data_ov003_021d42bc[s0 >> 24] ^ data_ov003_021d46bc[(s1 >> 16) & 0xff] ^
             data_ov003_021d4abc[(s2 >> 8) & 0xff] ^ data_ov003_021d4ebc[s3 & 0xff] ^ a[4];
        t1 = data_ov003_021d42bc[s1 >> 24] ^ data_ov003_021d46bc[(s2 >> 16) & 0xff] ^
             data_ov003_021d4abc[(s3 >> 8) & 0xff] ^ data_ov003_021d4ebc[s0 & 0xff] ^ a[5];
        t2 = data_ov003_021d42bc[s2 >> 24] ^ data_ov003_021d46bc[(s3 >> 16) & 0xff] ^
             data_ov003_021d4abc[(s0 >> 8) & 0xff] ^ data_ov003_021d4ebc[s1 & 0xff] ^ a[6];
        t3 = data_ov003_021d42bc[s3 >> 24] ^ data_ov003_021d46bc[(s0 >> 16) & 0xff] ^
             data_ov003_021d4abc[(s1 >> 8) & 0xff] ^ data_ov003_021d4ebc[s2 & 0xff] ^ a[7];
        a += 8;
        if (--r == 0) {
            break;
        }
        s0 = data_ov003_021d42bc[t0 >> 24] ^ data_ov003_021d46bc[(t1 >> 16) & 0xff] ^
             data_ov003_021d4abc[(t2 >> 8) & 0xff] ^ data_ov003_021d4ebc[t3 & 0xff] ^ a[0];
        s1 = data_ov003_021d42bc[t1 >> 24] ^ data_ov003_021d46bc[(t2 >> 16) & 0xff] ^
             data_ov003_021d4abc[(t3 >> 8) & 0xff] ^ data_ov003_021d4ebc[t0 & 0xff] ^ a[1];
        s2 = data_ov003_021d42bc[t2 >> 24] ^ data_ov003_021d46bc[(t3 >> 16) & 0xff] ^
             data_ov003_021d4abc[(t0 >> 8) & 0xff] ^ data_ov003_021d4ebc[t1 & 0xff] ^ a[2];
        s3 = data_ov003_021d42bc[t3 >> 24] ^ data_ov003_021d46bc[(t0 >> 16) & 0xff] ^
             data_ov003_021d4abc[(t1 >> 8) & 0xff] ^ data_ov003_021d4ebc[t2 & 0xff] ^ a[3];
    }
    s0 = (data_ov003_021d52bc[t0 >> 24] & 0xff000000) ^ (data_ov003_021d52bc[(t1 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d52bc[(t2 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[t3 & 0xff] & 0x000000ff) ^ a[0];
    d[0] = s0 >> 24;
    d[1] = s0 >> 16;
    d[2] = s0 >> 8;
    d[3] = s0;
    s1 = (data_ov003_021d52bc[t1 >> 24] & 0xff000000) ^ (data_ov003_021d52bc[(t2 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d52bc[(t3 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[t0 & 0xff] & 0x000000ff) ^ a[1];
    d[4] = s1 >> 24;
    d[5] = s1 >> 16;
    d[6] = s1 >> 8;
    d[7] = s1;
    s2 = (data_ov003_021d52bc[t2 >> 24] & 0xff000000) ^ (data_ov003_021d52bc[(t3 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d52bc[(t0 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[t1 & 0xff] & 0x000000ff) ^ a[2];
    d[8] = s2 >> 24;
    d[9] = s2 >> 16;
    d[10] = s2 >> 8;
    d[11] = s2;
    s3 = (data_ov003_021d52bc[t3 >> 24] & 0xff000000) ^ (data_ov003_021d52bc[(t0 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d52bc[(t1 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d52bc[t2 & 0xff] & 0x000000ff) ^ a[3];
    d[12] = s3 >> 24;
    d[13] = s3 >> 16;
    d[14] = s3 >> 8;
    d[15] = s3;
}

void func_ov003_021bbd9c(u32 *a, int b, u8 *c, u8 *d) {
    u32 s0, s1, s2, s3, t0, t1, t2, t3;
    int r;

    s0 = (((u32) c[0] << 24) ^ ((u32) c[1] << 16) ^ ((u32) c[2] << 8) ^ (u32) c[3]) ^ a[0];
    s1 = (((u32) c[4] << 24) ^ ((u32) c[5] << 16) ^ ((u32) c[6] << 8) ^ (u32) c[7]) ^ a[1];
    s2 = (((u32) c[8] << 24) ^ ((u32) c[9] << 16) ^ ((u32) c[10] << 8) ^ (u32) c[11]) ^ a[2];
    s3 = (((u32) c[12] << 24) ^ ((u32) c[13] << 16) ^ ((u32) c[14] << 8) ^ (u32) c[15]) ^ a[3];
    r = b >> 1;
    for (;;) {
        t0 = data_ov003_021d56bc[s0 >> 24] ^ data_ov003_021d5abc[(s3 >> 16) & 0xff] ^
             data_ov003_021d36bc[(s2 >> 8) & 0xff] ^ data_ov003_021d3abc[s1 & 0xff] ^ a[4];
        t1 = data_ov003_021d56bc[s1 >> 24] ^ data_ov003_021d5abc[(s0 >> 16) & 0xff] ^
             data_ov003_021d36bc[(s3 >> 8) & 0xff] ^ data_ov003_021d3abc[s2 & 0xff] ^ a[5];
        t2 = data_ov003_021d56bc[s2 >> 24] ^ data_ov003_021d5abc[(s1 >> 16) & 0xff] ^
             data_ov003_021d36bc[(s0 >> 8) & 0xff] ^ data_ov003_021d3abc[s3 & 0xff] ^ a[6];
        t3 = data_ov003_021d56bc[s3 >> 24] ^ data_ov003_021d5abc[(s2 >> 16) & 0xff] ^
             data_ov003_021d36bc[(s1 >> 8) & 0xff] ^ data_ov003_021d3abc[s0 & 0xff] ^ a[7];
        a += 8;
        if (--r == 0) {
            break;
        }
        s0 = data_ov003_021d56bc[t0 >> 24] ^ data_ov003_021d5abc[(t3 >> 16) & 0xff] ^
             data_ov003_021d36bc[(t2 >> 8) & 0xff] ^ data_ov003_021d3abc[t1 & 0xff] ^ a[0];
        s1 = data_ov003_021d56bc[t1 >> 24] ^ data_ov003_021d5abc[(t0 >> 16) & 0xff] ^
             data_ov003_021d36bc[(t3 >> 8) & 0xff] ^ data_ov003_021d3abc[t2 & 0xff] ^ a[1];
        s2 = data_ov003_021d56bc[t2 >> 24] ^ data_ov003_021d5abc[(t1 >> 16) & 0xff] ^
             data_ov003_021d36bc[(t0 >> 8) & 0xff] ^ data_ov003_021d3abc[t3 & 0xff] ^ a[2];
        s3 = data_ov003_021d56bc[t3 >> 24] ^ data_ov003_021d5abc[(t2 >> 16) & 0xff] ^
             data_ov003_021d36bc[(t1 >> 8) & 0xff] ^ data_ov003_021d3abc[t0 & 0xff] ^ a[3];
    }
    s0 = (data_ov003_021d3ebc[t0 >> 24] & 0xff000000) ^ (data_ov003_021d3ebc[(t3 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d3ebc[(t2 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d3ebc[t1 & 0xff] & 0x000000ff) ^ a[0];
    d[0] = s0 >> 24;
    d[1] = s0 >> 16;
    d[2] = s0 >> 8;
    d[3] = s0;
    s1 = (data_ov003_021d3ebc[t1 >> 24] & 0xff000000) ^ (data_ov003_021d3ebc[(t0 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d3ebc[(t3 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d3ebc[t2 & 0xff] & 0x000000ff) ^ a[1];
    d[4] = s1 >> 24;
    d[5] = s1 >> 16;
    d[6] = s1 >> 8;
    d[7] = s1;
    s2 = (data_ov003_021d3ebc[t2 >> 24] & 0xff000000) ^ (data_ov003_021d3ebc[(t1 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d3ebc[(t0 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d3ebc[t3 & 0xff] & 0x000000ff) ^ a[2];
    d[8] = s2 >> 24;
    d[9] = s2 >> 16;
    d[10] = s2 >> 8;
    d[11] = s2;
    s3 = (data_ov003_021d3ebc[t3 >> 24] & 0xff000000) ^ (data_ov003_021d3ebc[(t2 >> 16) & 0xff] & 0x00ff0000) ^
         (data_ov003_021d3ebc[(t1 >> 8) & 0xff] & 0x0000ff00) ^ (data_ov003_021d3ebc[t0 & 0xff] & 0x000000ff) ^ a[3];
    d[12] = s3 >> 24;
    d[13] = s3 >> 16;
    d[14] = s3 >> 8;
    d[15] = s3;
}

void func_ov003_021bbd70(Unk021bbd70 *a) {
    a->mUnk_14 = 0;
    a->mUnk_10 = a->mUnk_14;
    a->mUnk_00[0] = 0x67452301;
    a->mUnk_00[1] = 0xefcdab89;
    a->mUnk_00[2] = 0x98badcfe;
    a->mUnk_00[3] = 0x10325476;
}

void func_ov003_021bbcf0(Unk021bbd70 *a, const u8 *b, u32 c) {
    u32 i;
    u32 d;
    u32 e;
    d = (a->mUnk_10 >> 3) & 0x3f;
    a->mUnk_10 += c << 3;
    if (a->mUnk_10 < (c << 3)) {
        a->mUnk_14++;
    }
    a->mUnk_14 += c >> 29;
    e = 0x40 - d;
    if (c >= e) {
        func_ov003_021bb3bc(a->mUnk_18 + d, b, e);
        func_ov003_021bb438(a, a->mUnk_18);
        for (i = e; i + 63 < c; i += 64) {
            func_ov003_021bb438(a, b + i);
        }
        d = 0;
    } else {
        i = 0;
    }
    func_ov003_021bb3bc(a->mUnk_18 + d, b + i, c - i);
}

void func_ov003_021bbc94(u8 *a, Unk021bbd70 *b) {
    u8 c[8];
    u32 i;
    u32 d;
    func_ov003_021bb408(c, &b->mUnk_10, 8);
    i = (b->mUnk_10 >> 3) & 0x3f;
    if (i < 0x38) {
        d = 0x38 - i;
    } else {
        d = 0x78 - i;
    }
    func_ov003_021bbcf0(b, data_ov003_021d68dc, d);
    func_ov003_021bbcf0(b, c, 8);
    func_ov003_021bb408(a, b->mUnk_00, 0x10);
    func_ov003_021bb3a4(b, 0, 0x58);
}

void func_ov003_021bb438(Unk021bbd70 *p, const u8 *q) {
    u32 a = p->mUnk_00[0];
    u32 b = p->mUnk_00[1];
    u32 c = p->mUnk_00[2];
    u32 d = p->mUnk_00[3];
    u32 x[16];

    func_ov003_021bb3d8(x, q, 64);
    a += ((b & c) | (~b & d)) + x[0] + 0xd76aa478;
    a = (a << 7) | (a >> 25);
    a += b;
    d += ((a & b) | (~a & c)) + x[1] + 0xe8c7b756;
    d = (d << 12) | (d >> 20);
    d += a;
    c += ((d & a) | (~d & b)) + x[2] + 0x242070db;
    c = (c << 17) | (c >> 15);
    c += d;
    b += ((c & d) | (~c & a)) + x[3] + 0xc1bdceee;
    b = (b << 22) | (b >> 10);
    b += c;
    a += ((b & c) | (~b & d)) + x[4] + 0xf57c0faf;
    a = (a << 7) | (a >> 25);
    a += b;
    d += ((a & b) | (~a & c)) + x[5] + 0x4787c62a;
    d = (d << 12) | (d >> 20);
    d += a;
    c += ((d & a) | (~d & b)) + x[6] + 0xa8304613;
    c = (c << 17) | (c >> 15);
    c += d;
    b += ((c & d) | (~c & a)) + x[7] + 0xfd469501;
    b = (b << 22) | (b >> 10);
    b += c;
    a += ((b & c) | (~b & d)) + x[8] + 0x698098d8;
    a = (a << 7) | (a >> 25);
    a += b;
    d += ((a & b) | (~a & c)) + x[9] + 0x8b44f7af;
    d = (d << 12) | (d >> 20);
    d += a;
    c += ((d & a) | (~d & b)) + x[10] + 0xffff5bb1;
    c = (c << 17) | (c >> 15);
    c += d;
    b += ((c & d) | (~c & a)) + x[11] + 0x895cd7be;
    b = (b << 22) | (b >> 10);
    b += c;
    a += ((b & c) | (~b & d)) + x[12] + 0x6b901122;
    a = (a << 7) | (a >> 25);
    a += b;
    d += ((a & b) | (~a & c)) + x[13] + 0xfd987193;
    d = (d << 12) | (d >> 20);
    d += a;
    c += ((d & a) | (~d & b)) + x[14] + 0xa679438e;
    c = (c << 17) | (c >> 15);
    c += d;
    b += ((c & d) | (~c & a)) + x[15] + 0x49b40821;
    b = (b << 22) | (b >> 10);
    b += c;
    a += ((b & d) | (c & ~d)) + x[1] + 0xf61e2562;
    a = (a << 5) | (a >> 27);
    a += b;
    d += ((a & c) | (b & ~c)) + x[6] + 0xc040b340;
    d = (d << 9) | (d >> 23);
    d += a;
    c += ((d & b) | (a & ~b)) + x[11] + 0x265e5a51;
    c = (c << 14) | (c >> 18);
    c += d;
    b += ((c & a) | (d & ~a)) + x[0] + 0xe9b6c7aa;
    b = (b << 20) | (b >> 12);
    b += c;
    a += ((b & d) | (c & ~d)) + x[5] + 0xd62f105d;
    a = (a << 5) | (a >> 27);
    a += b;
    d += ((a & c) | (b & ~c)) + x[10] + 0x02441453;
    d = (d << 9) | (d >> 23);
    d += a;
    c += ((d & b) | (a & ~b)) + x[15] + 0xd8a1e681;
    c = (c << 14) | (c >> 18);
    c += d;
    b += ((c & a) | (d & ~a)) + x[4] + 0xe7d3fbc8;
    b = (b << 20) | (b >> 12);
    b += c;
    a += ((b & d) | (c & ~d)) + x[9] + 0x21e1cde6;
    a = (a << 5) | (a >> 27);
    a += b;
    d += ((a & c) | (b & ~c)) + x[14] + 0xc33707d6;
    d = (d << 9) | (d >> 23);
    d += a;
    c += ((d & b) | (a & ~b)) + x[3] + 0xf4d50d87;
    c = (c << 14) | (c >> 18);
    c += d;
    b += ((c & a) | (d & ~a)) + x[8] + 0x455a14ed;
    b = (b << 20) | (b >> 12);
    b += c;
    a += ((b & d) | (c & ~d)) + x[13] + 0xa9e3e905;
    a = (a << 5) | (a >> 27);
    a += b;
    d += ((a & c) | (b & ~c)) + x[2] + 0xfcefa3f8;
    d = (d << 9) | (d >> 23);
    d += a;
    c += ((d & b) | (a & ~b)) + x[7] + 0x676f02d9;
    c = (c << 14) | (c >> 18);
    c += d;
    b += ((c & a) | (d & ~a)) + x[12] + 0x8d2a4c8a;
    b = (b << 20) | (b >> 12);
    b += c;
    a += (b ^ c ^ d) + x[5] + 0xfffa3942;
    a = (a << 4) | (a >> 28);
    a += b;
    d += (a ^ b ^ c) + x[8] + 0x8771f681;
    d = (d << 11) | (d >> 21);
    d += a;
    c += (d ^ a ^ b) + x[11] + 0x6d9d6122;
    c = (c << 16) | (c >> 16);
    c += d;
    b += (c ^ d ^ a) + x[14] + 0xfde5380c;
    b = (b << 23) | (b >> 9);
    b += c;
    a += (b ^ c ^ d) + x[1] + 0xa4beea44;
    a = (a << 4) | (a >> 28);
    a += b;
    d += (a ^ b ^ c) + x[4] + 0x4bdecfa9;
    d = (d << 11) | (d >> 21);
    d += a;
    c += (d ^ a ^ b) + x[7] + 0xf6bb4b60;
    c = (c << 16) | (c >> 16);
    c += d;
    b += (c ^ d ^ a) + x[10] + 0xbebfbc70;
    b = (b << 23) | (b >> 9);
    b += c;
    a += (b ^ c ^ d) + x[13] + 0x289b7ec6;
    a = (a << 4) | (a >> 28);
    a += b;
    d += (a ^ b ^ c) + x[0] + 0xeaa127fa;
    d = (d << 11) | (d >> 21);
    d += a;
    c += (d ^ a ^ b) + x[3] + 0xd4ef3085;
    c = (c << 16) | (c >> 16);
    c += d;
    b += (c ^ d ^ a) + x[6] + 0x04881d05;
    b = (b << 23) | (b >> 9);
    b += c;
    a += (b ^ c ^ d) + x[9] + 0xd9d4d039;
    a = (a << 4) | (a >> 28);
    a += b;
    d += (a ^ b ^ c) + x[12] + 0xe6db99e5;
    d = (d << 11) | (d >> 21);
    d += a;
    c += (d ^ a ^ b) + x[15] + 0x1fa27cf8;
    c = (c << 16) | (c >> 16);
    c += d;
    b += (c ^ d ^ a) + x[2] + 0xc4ac5665;
    b = (b << 23) | (b >> 9);
    b += c;
    a += (c ^ (b | ~d)) + x[0] + 0xf4292244;
    a = (a << 6) | (a >> 26);
    a += b;
    d += (b ^ (a | ~c)) + x[7] + 0x432aff97;
    d = (d << 10) | (d >> 22);
    d += a;
    c += (a ^ (d | ~b)) + x[14] + 0xab9423a7;
    c = (c << 15) | (c >> 17);
    c += d;
    b += (d ^ (c | ~a)) + x[5] + 0xfc93a039;
    b = (b << 21) | (b >> 11);
    b += c;
    a += (c ^ (b | ~d)) + x[12] + 0x655b59c3;
    a = (a << 6) | (a >> 26);
    a += b;
    d += (b ^ (a | ~c)) + x[3] + 0x8f0ccc92;
    d = (d << 10) | (d >> 22);
    d += a;
    c += (a ^ (d | ~b)) + x[10] + 0xffeff47d;
    c = (c << 15) | (c >> 17);
    c += d;
    b += (d ^ (c | ~a)) + x[1] + 0x85845dd1;
    b = (b << 21) | (b >> 11);
    b += c;
    a += (c ^ (b | ~d)) + x[8] + 0x6fa87e4f;
    a = (a << 6) | (a >> 26);
    a += b;
    d += (b ^ (a | ~c)) + x[15] + 0xfe2ce6e0;
    d = (d << 10) | (d >> 22);
    d += a;
    c += (a ^ (d | ~b)) + x[6] + 0xa3014314;
    c = (c << 15) | (c >> 17);
    c += d;
    b += (d ^ (c | ~a)) + x[13] + 0x4e0811a1;
    b = (b << 21) | (b >> 11);
    b += c;
    a += (c ^ (b | ~d)) + x[4] + 0xf7537e82;
    a = (a << 6) | (a >> 26);
    a += b;
    d += (b ^ (a | ~c)) + x[11] + 0xbd3af235;
    d = (d << 10) | (d >> 22);
    d += a;
    c += (a ^ (d | ~b)) + x[2] + 0x2ad7d2bb;
    c = (c << 15) | (c >> 17);
    c += d;
    b += (d ^ (c | ~a)) + x[9] + 0xeb86d391;
    b = (b << 21) | (b >> 11);
    b += c;
    p->mUnk_00[0] += a;
    p->mUnk_00[1] += b;
    p->mUnk_00[2] += c;
    p->mUnk_00[3] += d;
    func_ov003_021bb3a4(x, 0, sizeof(x));
}

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
    memcpy(((u32 *) (u32) (a)), &data_ov003_021d8dc8, 0xe8);
    return 1;
}

void func_ov003_021bb03c(void) {
    u8 v1[8];
    func_ov003_021bb070(((u32 *) (void *) (v1)));
    (*(UnkFunc *) (u32) data_ov003_021d8c4c)(v1);
    return;
}
