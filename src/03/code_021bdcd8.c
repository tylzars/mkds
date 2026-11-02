#include "03/code_021bdcd8.h"
#include "03/code_021bb000.h"
#include "03/code_021bb03c.h"
#include "03/code_021bd000.h"
#include "03/code_021be000.h"
#include "03/code_021be4e0.h"
#include "00/code_021a8aa8.h"
#include "00/code_021a6fa8.h"
#include "00/code_021a86bc.h"
#include "code_0200dc3c.h"
#include "code_0200f7a0.h"
#include "code_02134d30.h"
#include "code_02139f70.h"

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

s32 func_ov003_021bdd1c(s32 v1, const Unk021bdcd8 *v2, const u8 *param_2, const void *v3, u32 v4) {
    s32 a;
    a = func_ov000_021a9018(v1, v3, v4, 0, v2);
    if (a < 0) {
        a = -4;
    }
    return a;
}

// non-matching: 95.9: size 0x2e8 against 0x2ec. The original keeps a second loop counter that nothing reads (g and h
// both incremented in their stack slots, one slot more), and steps three pointers (name, record, the six-byte value)
// where this has four (mUnk_2e uses its own g pointer); the zero values hoisted out of the outer loop get other
// registers and slots (the original's r7 zero is a switch case's c = 0).
s32 func_ov003_021bdd3c(void) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    u32 e;
    u32 f;
    s32 g;
    s32 h;
    Unk021bdd3c *j;
    Unk021bdd3c *k;
    Unk021d8c2c *l;
    Unk021bdd3c_Entry *m;
    u8 *s;
    u8 *t;
    u32 i;
    char o[0x20];
    Unk0200fb08 n;
    a = 0;
    j = 0;
    a = -1;
    k = 0;
    i = 0;
    e = data_ov003_021d8c40 * 0x30 + 0x34;
    j = func_ov003_021bb328(1, e);
    if (j == 0) {
        goto end;
    }
    k = func_ov003_021bb328(1, e);
    if (k == 0) {
        goto end;
    }
    b = 0;
    while (b < 30 && data_ov003_021d8be0 == 0) {
        if (func_ov003_021bb354() >= data_ov003_021d68b8) {
            break;
        }
        if (func_ov003_021be860(0, 0, 0, 0x30bffe) == 0) {
            a = -2;
            goto end;
        }
        func_0200fb08(&n);
        func_0200f950(&n, 0xffb10, (void (*)(void *)) func_ov003_021be4e0, (void *) 0x13);
        c = 1;
        a = 0;
        do {
            func_0200dc3c(10);
            if (func_ov003_021bb354() >= data_ov003_021d68b8 || data_ov003_021d8be0 != 0) {
                break;
            }
            while ((f = func_ov003_021be528()) != 0) {
                switch (f) {
                    case 4:
                    case 8:
                    case 18:
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
                        c = 0;
                        break;
                    case 19:
                        c = 0;
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
                        c = 0;
                        break;
                }
            }
        } while (c != 0);
        func_0200f8b8(&n);
        while (func_ov003_021be528() != 0) {
        }
        if (data_ov003_021d8be0 != 0) {
            break;
        }
        if (a >= data_ov003_021d8c40) {
            a = -6;
            goto end;
        }
        g = 0;
        h = 0;
        l = data_ov003_021d8c2c;
        if (a > 0) {
            do {
                func_02134eb8(j->mUnk_04[g].mUnk_04, l->mUnk_0c, 0x20);
                j->mUnk_04[h].mUnk_00 = l->mUnk_0a;
                j->mUnk_04[h].mUnk_04[l->mUnk_0a] = 0;
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
        if (data_ov003_021d8c08 != 1 && func_ov003_021be028(j, k, &i) != 0) {
            m = &j->mUnk_04[i];
            data_ov003_021d8be8 = i;
            func_0213a2d0(data_ov003_021d8ce4, m->mUnk_04);
            t = (u8 *) &data_ov003_021d8c5c;
            s = (u8 *) &m->mUnk_28;
            t[0] = s[0];
            t[1] = s[1];
            t[2] = s[2];
            t[3] = s[3];
            t[4] = s[4];
            t[5] = s[5];
            func_ov003_021bb29c((u8 *) o, (const s8 *) &data_ov003_021d8c5c);
            break;
        }
        func_02134eb8(k, j, e);
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
    if (j != 0) {
        func_ov003_021bb314(j);
    }
    if (k != 0) {
        func_ov003_021bb314(k);
    }
    return a;
}

s32 func_ov003_021be028(Unk021bdd3c *a, Unk021bdd3c *b, u32 *c) {
    s32 e;
    s32 d;
    s32 f;
    s32 g;
    Unk021bdd3c_Entry *h;
    Unk021bdd3c_Entry *i;
    u32 l;
    u32 j;
    u32 k;
    u32 m;
    e = 0;
    d = 0;
    h = a->mUnk_04;
    i = b->mUnk_04;
    j = 0;
    for (; j < a->mUnk_00; j++) {
        u8 n[0x22] = {0};
        func_02134eb8(n, h->mUnk_04, 0x20);
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
                if (func_02134d30(n, i->mUnk_04, func_0213a434(n)) == 0 &&
                    func_02134d30(h->mUnk_28.mUnk_00, i->mUnk_28.mUnk_00, 4) == 0 && h->mUnk_2e != i->mUnk_2e &&
                    h->mUnk_2e == 0) {
                    e = 1;
                    break;
                }
                i++;
                k++;
            } while (k < l);
        }
        if (e != 0) {
            break;
        }
        h++;
        i = b->mUnk_04;
    }
    if (e == 0) {
        u8 o[0x22] = {0};
        f = 0;
        g = 0;
        h = a->mUnk_04;
        i = b->mUnk_04;
        k = 0;
        for (; k < b->mUnk_00; k++) {
            func_02134eb8(o, i->mUnk_04, 0x20);
            o[i->mUnk_00] = 0;
            if (func_02134d30(o, data_ov003_021d68c0, func_0213a434(data_ov003_021d68c0)) == 0 && i->mUnk_2e == 0) {
                g = 1;
                break;
            }
            i++;
        }
        j = 0;
        for (; j < a->mUnk_00; j++) {
            func_02134eb8(o, h->mUnk_04, 0x20);
            o[h->mUnk_00] = 0;
            if (func_0213a434(o) == func_0213a434(data_ov003_021d68c0) &&
                func_02134d30(o, data_ov003_021d68c0, func_0213a434(data_ov003_021d68c0)) == 0 && h->mUnk_2e == 0) {
                f = 1;
                break;
            }
            h++;
        }
        if (f != 0 && g == 0) {
            e = 1;
        }
    }
    if (e != 0) {
        *c = j;
        d = 1;
    }
    return d;
}

void func_ov003_021be1fc(void) {
    s32 a;
    u32 b;
    a = 1;
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
                            a = 0;
                            break;
                        default:
                            a = 0;
                            break;
                    }
                }
            } while (a != 0);
        }
        data_ov003_021d8bf0 = 0;
    }
    if (data_ov003_021d8bf4 != 0) {
        data_ov003_021d8bf4 = 0;
        func_ov000_021a8c8c();
    }
}
