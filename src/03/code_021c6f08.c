#include "03/code_021c6f08.h"

#include "03/code_021c209c.h"
#include "03/code_021c6a18.h"
#include "03/code_021cdbd0.h"
#include "03/code_021cea3c.h"
#include "03/code_021cef90.h"
#include "03/code_021cd2e0.h"
#include "03/unk_021da000.h"
#include "code_021510a4.h"
#include "03/code_021bf4dc.h"
#include "03/code_021bf000.h"
#include "03/code_021bf410.h"
#include "03/code_021c2000.h"
#include "03/code_021c9000.h"
#include "03/code_021c7d30.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"
#include "03/code_021c0fd8.h"
#include "03/code_021ce000.h"
#include "03/code_021c7000.h"
#include "03/code_021cd000.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "03/code_021d27d8.h"
#include "03/code_021d2ecc.h"
#include "code_0213a460.h"
#include "code_0214d018.h"
#include "03/code_021c1000.h"
#include "03/unk_021d5000.h"
#include "03/code_021d1440.h"
#include "03/code_021bf810.h"
#include "03/code_021d1c18.h"
#include "string.h"
#include "code_02134398.h"

void func_ov003_021c7748(void) {
    Unk021d7310 a;
    u8 b[5];
    s32 c;
    Unk021da1fc *d;
    a = data_ov003_021d7310;
    b[0] = data_ov003_021d7300[0];
    b[1] = data_ov003_021d7300[1];
    b[2] = data_ov003_021d7300[2];
    b[3] = data_ov003_021d7300[3];
    b[4] = data_ov003_021d7300[4];
    data_ov003_021da1fc = func_ov003_021d283c(0x18, 4);
    func_ov003_021c20dc(&c, NULL);
    a.mUnk_00[c](data_ov003_021da1fc->mUnk_08);
    d = data_ov003_021da1fc;
    if (memcmp(d->mUnk_08, data_ov003_021d73ac, 3) != 0) {
        d->mUnk_14 = 3;
    } else {
        MemFill(d->mUnk_08, 0, 0xc);
        data_ov003_021da1fc->mUnk_14 = 0;
    }
    func_ov003_021c76b4();
    func_ov003_021bf86c(c + 0xb);
    func_ov003_021bf43c(b[c], -1, 0);
    func_ov003_021bf5ec(2);
    data_ov003_021da1fc->mUnk_00 = func_ov003_021d2288(0, 0);
    data_ov003_021da1fc->mUnk_04 = func_ov003_021d1c18(0, 0x3f);
    data_ov003_021da1fc->mUnk_04->mUnk_04 = (data_ov003_021da1fc->mUnk_04->mUnk_04 & 0xfffff3ff) | 0xc00;
    func_ov003_021c7160();
    func_ov003_021c71a0();
    func_ov003_021c212c(func_ov003_021c7678);
}

void func_ov003_021c76b4(void) {
    void *v2 = &data_ov003_021d7350;
    void *v3 = &func_0214c090;
    u32 v4 = func_ov003_021bf620(v2, v3);
    void *v5 = &data_ov003_021d7364;
    void *v6 = &MemCopyWordsToG2Bg2CntBits2To5Address;
    u32 v7 = func_ov003_021bf620(v5, v6);
    void *v8 = &data_ov003_021d737c;
    void *v9 = &func_0214c160;
    u32 v10 = func_ov003_021bf620(v8, v9);
    void *v11 = &data_ov003_021d7394;
    void *v12 = &MemCopyHalfwordsToG2Bg2CntBits8To12Address;
    u32 v13 = func_ov003_021bf620(v11, v12);
    u32 v14 = 0x4001008u;
    u32 v15 = ((u32) * (u16 *) ((v14) + (0)));
    u32 v17 = ((v15) & ~(0x3u));
    u32 v18 = ((v17) | (0x3u));
    u32 v20;
    u32 v21;
    u32 v22;
    u32 v23;
    u32 v25;
    u32 v26;
    u32 v27;
    u32 v29;
    u32 v31;
    u32 v32;
    u32 v33;
    u32 v34;
    u32 v36;
    u32 v37;
    u32 v38;
    u32 v39;
    *(u16 *) ((v14) + (0)) = (u16) v18;
    v20 = 0x400100au;
    v21 = ((u32) * (u16 *) ((v20) + (0)));
    v22 = ((v21) & ~(0x3u));
    v23 = ((v22) | (0x3u));
    *(u16 *) ((v20) + (0)) = (u16) v23;
    v25 = 0x4000008u;
    v26 = ((u32) * (u16 *) ((v25) + (0)));
    v27 = ((v26) & ~(0x3u));
    v29 = ((v27) | (0x2u));
    *(u16 *) ((v25) + (0)) = (u16) v29;
    v31 = 0x400000au;
    v32 = ((u32) * (u16 *) ((v31) + (0)));
    v33 = ((v32) & ~(0x3u));
    v34 = ((v33) | (0x3u));
    *(u16 *) ((v31) + (0)) = (u16) v34;
    v36 = 0x400000cu;
    v37 = ((u32) * (u16 *) ((v36) + (0)));
    v38 = ((v37) & ~(0x3u));
    v39 = ((v38) | (0x3u));
    *(u16 *) ((v36) + (0)) = (u16) v39;
}

void func_ov003_021c7678(void) {
    func_ov003_021d1ee0(2, 1, (u32) 1, (u16) 8);
    func_ov003_021d1ee0(2, 0, (u32) 0x15, (u16) 8);
    func_ov003_021d2784(1, (u32) 1);
    func_ov003_021d2784(0, (u32) 0x15);
    func_ov003_021c212c(func_ov003_021c7614);
}

void func_ov003_021c7614(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_ov003_021c1cd8();
        func_ov003_021cdc10((u32) 0x14);
        if (data_ov003_021da1fc->mUnk_14 == 0) {
            func_ov003_021c1c90((u8) 0);
            func_ov003_021c1c70((u8) 0);
        } else {
            v1 = func_ov003_021c735c(0x1a);
            if (v1 != 0) {
                func_ov003_021c1c80((u8) 0);
            }
            func_ov003_021c1c70((u8) 0);
        }
        func_ov003_021c212c(func_ov003_021c75f8);
    }
}

void func_ov003_021c75f8(void) {
    if (func_ov003_021c1ca0() != 31) {
        func_ov003_021c212c(func_ov003_021c75e4);
    }
}

void func_ov003_021c75e4(void) {
    func_ov003_021c73cc();
    func_ov003_021c7358();
    return;
}

void func_ov003_021c73cc(void) {
    s32 a;
    u8 *b;
    s32 k;
    Unk021da1fc *h;
    Unk021da1fc **g;
    u8 e;
    a = func_ov003_021c1ca0();
    switch (a) {
        case 0:
            return;
        case 0x10:
            if (data_ov003_021da1fc->mUnk_14 == 0 && data_ov003_021da1fc->mUnk_08[2] == 0) {
                break;
            }
            func_ov003_021cdc10(3);
            if (data_ov003_021da1fc->mUnk_08[data_ov003_021da1fc->mUnk_14 * 3 + 2] == 0) {
                data_ov003_021da1fc->mUnk_14--;
            }
            MemFill(data_ov003_021da1fc->mUnk_08 + data_ov003_021da1fc->mUnk_14 * 3, 0, 3);
            if (data_ov003_021da1fc->mUnk_14 == 0 && data_ov003_021da1fc->mUnk_08[2] == 0) {
                func_ov003_021c1c90(0);
            }
            func_ov003_021c1c80(1);
            func_ov003_021c1c70(0);
            break;
        case 0x11:
            e = data_ov003_021da1fc->mUnk_14;
            if (e >= 3) {
                break;
            }
            if (data_ov003_021da1fc->mUnk_08[e * 3 + 2] == 0) {
                break;
            }
            func_ov003_021cdc10(1);
            data_ov003_021da1fc->mUnk_14 = data_ov003_021da1fc->mUnk_14 + 1;
            func_ov003_021c1c70(0);
            break;
        case 0x12:
            data_ov003_021da1fc->mUnk_15 = 0;
            func_ov003_021cdc10(7);
            func_ov003_021c212c(func_ov003_021c733c);
            return;
        case 0x13:
            if (func_ov003_021c6f64() != 0) {
                func_ov003_021cdc10(6);
                data_ov003_021da1fc->mUnk_15 = 1;
            } else {
                data_ov003_021da1fc->mUnk_15 = 2;
                func_ov003_021cdc10(9);
            }
            data_ov003_021da1fc->mUnk_14 = 3;
            data_ov003_021da1fc->mUnk_04->mUnk_00 = (data_ov003_021da1fc->mUnk_04->mUnk_00 & 0xc1fffcff) | 0x200;
            func_ov003_021c7160();
            func_ov003_021c7050();
            func_ov003_021c212c(func_ov003_021c733c);
            return;
        default:
            if (data_ov003_021da1fc->mUnk_14 == 3) {
                if (func_ov003_021c735c(0x1a) != 0) {
                    break;
                }
            }
            func_ov003_021cdc10(1);
            g = (Unk021da1fc **) &data_ov003_021da1fc;
            b = (*g)->mUnk_08;
            k = (*g)->mUnk_14 * 3;
            if (b[k + 2] == 0) {
                b[k + 2] = a;
            } else if (b[k + 1] == 0) {
                b[k + 1] = b[k + 2];
                b[k + 2] = a;
                if (func_ov003_021c735c(0x1a) != 0) {
                    h = data_ov003_021da1fc;
                    if (h->mUnk_14 < 3) {
                        h->mUnk_14 = h->mUnk_14 + 1;
                    }
                }
            } else {
                b[k] = b[k + 1];
                b[k + 1] = b[k + 2];
                b[k + 2] = a;
                if ((*g)->mUnk_14 < 3) {
                    (*g)->mUnk_14 = (*g)->mUnk_14 + 1;
                }
            }
            func_ov003_021c1c90(1);
            if (data_ov003_021da1fc->mUnk_14 < 3) {
                func_ov003_021c1c70(1);
            } else {
                func_ov003_021c1c70(0);
            }
            if (data_ov003_021da1fc->mUnk_14 == 3) {
                if (func_ov003_021c735c(0x1a) != 0) {
                    func_ov003_021c1c80(0);
                }
            }
            break;
    }
    func_ov003_021c71a0();
    func_ov003_021c7160();
}

u32 func_ov003_021c735c(s32 a) {
    u8 b[4];
    u8 *c;
    u8 *d;
    s32 e;
    u8 f;
    d = data_ov003_021da1fc->mUnk_08;
    c = d + data_ov003_021da1fc->mUnk_14 * 3;
    f = *c;
    if (f != 0 && f != 0x20) {
        return 1;
    }
    MemCopy(c, b, 3);
    b[3] = 0;
    c = b;
    for (e = 0; e < 3; e++) {
        if (*c != 0) {
            break;
        }
        *c = 0x20;
        c++;
    }
    if (StrtolBase10((const char *) b) >= a) {
        return 1;
    }
    return 0;
}

void func_ov003_021c7358(void) {
    return;
}

void func_ov003_021c733c(void) {
    func_ov003_021d1dd0((u16) (8));
    func_ov003_021c212c(func_ov003_021c7314);
    return;
}

void func_ov003_021c7314(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        func_ov003_021c1cb0();
        func_ov003_021cdc10(0x15);
        func_ov003_021c212c(func_ov003_021c72a4);
    }
    return;
}

void func_ov003_021c72a4(void) {
    u8 a;
    if (func_ov003_021c1c5c() == 0) {
        a = data_ov003_021da1fc->mUnk_15;
        if (a == 0) {
            func_ov003_021c212c(func_ov003_021c722c);
            return;
        }
        if (a == 2) {
            func_ov003_021cefc0(0x2f, 3, 1, -1, 0);
            func_ov003_021c212c(func_ov003_021c6f3c);
            return;
        }
        func_ov003_021cefc0(0x9b, 2, 1, -1, 0);
        func_ov003_021c212c(func_ov003_021c7118);
    }
}

void func_ov003_021c722c(void) {
    int v1[1];
    func_ov003_021bf410();
    func_ov003_021d2f00((u32 *) (u32) (data_ov003_021da1fc->mUnk_04));
    func_ov003_021d2168(0);
    func_ov003_021bf620(&data_ov003_021d7338, &func_0214c090);
    func_ov003_021d272c(1, (u32) 1);
    func_ov003_021d272c(0, (u32) 0x15);
    func_ov003_021c20dc(v1, NULL);
    if (3 <= v1[0]) {
        v1[0] = v1[0] + 1;
    }
    func_ov003_021c2120((u32) 2, (u32) 1);
    func_ov003_021c20f8((u32) 0, (u32) (v1[0] + 3));
    func_ov003_021c212c(func_ov003_021c965c);
    func_ov003_021d2808(&data_ov003_021da1fc);
}

void func_ov003_021c71a0(void) {
    u16 a[6];
    s32 b;
    u8 *c;
    Unk021da1fc *s;
    u16 d;
    a[0] = data_ov003_021d7308[0];
    a[1] = data_ov003_021d7308[1];
    a[2] = data_ov003_021d7308[2];
    a[3] = data_ov003_021d7308[3];
    a[2] = data_ov003_021d63f8[0];
    a[3] = data_ov003_021d63f8[1];
    func_ov003_021d2060(data_ov003_021da1fc->mUnk_00, 0);
    b = 0;
    a[5] = 0;
    c = data_ov003_021d63fc;
    do {
        s = data_ov003_021da1fc;
        a[4] = s->mUnk_08[b];
        d = *c;
        a[0] = d;
        func_ov003_021d2070(s->mUnk_00, d, a[1], a[2], a[3], 2, 0x480, &a[4]);
        c++;
        b++;
    } while (b < 12);
    func_ov003_021d1fd0(data_ov003_021da1fc->mUnk_00);
}

void func_ov003_021c7160(void) {
    Unk021da1fc *a;
    Unk021da1f8_04 *p;
    u32 t;
    s32 b;
    a = data_ov003_021da1fc;
    b = a->mUnk_14;
    if (b > 3) {
        b = 3;
    }
    p = a->mUnk_04;
    t = (data_ov003_021d63fc[b * 3 + 2] & 0x1ff) << 16;
    p->mUnk_00 = t | ((p->mUnk_00 & 0xfe00ff00) | 0x28);
}

void func_ov003_021c7118(void) {
    data_ov003_021da1fc->mUnk_15 = func_ov003_021cef80();
    switch (data_ov003_021da1fc->mUnk_15) {
        case 0:
            func_ov003_021cdc10(7);
            break;
        case 1:
            func_ov003_021cdc10(0xe);
            break;
        default:
            return;
    }
    func_ov003_021cef90();
    func_ov003_021c212c(func_ov003_021c70a4);
}

void func_ov003_021c70a4(void) {
    Unk021d7324 a;
    s32 b;
    a = data_ov003_021d7324;
    if (func_ov003_021cef6c() == 0) {
        if (data_ov003_021da1fc->mUnk_15 == 0) {
            data_ov003_021da1fc->mUnk_04->mUnk_00 = data_ov003_021da1fc->mUnk_04->mUnk_00 & 0xc1fffcff;
            func_ov003_021c212c(func_ov003_021c7614);
            return;
        }
        func_ov003_021c20dc(&b, NULL);
        a.mUnk_00[b](data_ov003_021da1fc->mUnk_08);
        func_ov003_021c212c(func_ov003_021c722c);
    }
}

void func_ov003_021c7050(void) {
    int v1;
    int v2;
    int v3;
    int v4;
    u8 v5;
    u8 v6;
    v1 = 0;
    v4 = 0;
    do {
        v2 = (s32) data_ov003_021da1fc + 8 + v4;
        v3 = 0;
        do {
            v6 = *(s8 *) (v2 + v3);
            if (((v6 != '0') && (v6 != ' ')) && (v6 != 0)) {
                break;
            }
            if (v3 == 2) {
                v5 = 0x30;
            } else {
                v5 = 0x20;
            }
            *(u8 *) (v2 + v3) = v5;
            v3 = v3 + 1;
        } while (v3 < 3);
        v4 = v4 + 3;
        v1 = v1 + 1;
    } while (v1 < 4);
    func_ov003_021c71a0();
}

BOOL func_ov003_021c6f64(void) {
    u8 a[4];
    u8 *k;
    u8 *j;
    s32 c;
    s32 e;
    s32 d;
    u8 *i;
    s32 f;
    u8 b[4];
    BOOL g;
    s32 h;
    u8 *m;
    a[0] = data_ov003_021d72fc[0];
    a[1] = data_ov003_021d72fc[1];
    a[2] = data_ov003_021d72fc[2];
    a[3] = data_ov003_021d72fc[3];
    c = 0;
    d = 0;
    k = (u8 *) data_ov003_021da1fc;
    do {
        j = k + 8 + d;
        if (*j != 0x20) {
            for (e = 0, i = a; e < 3; e++) {
                if (j[e] > *i) {
                    return FALSE;
                }
                if (j[e] < *i) {
                    break;
                }
                i++;
            }
        }
        d += 3;
        c++;
    } while (c < 4);
    k += 8;
    func_ov003_021cd2e0((char *) k, b);
    func_ov003_021c20dc(&f, NULL);
    if (f == 1) {
        g = FALSE;
        h = 0;
        m = b;
        do {
            for (e = 0; e < 8; e++) {
                if (g != FALSE) {
                    if ((*m & (1 << (7 - e))) != 0) {
                        return FALSE;
                    }
                } else if ((*m & (1 << (7 - e))) == 0) {
                    g = TRUE;
                }
            }
            m++;
            h++;
        } while (h < 4);
        return TRUE;
    }
    if (func_02151620(b) != 0) {
        return TRUE;
    }
    return FALSE;
}

void func_ov003_021c6f3c(void) {
    int v1;
    v1 = func_ov003_021cef80();
    if (v1 == 0) {
        func_ov003_021cdc10(6);
        func_ov003_021cef90();
        func_ov003_021c212c(func_ov003_021c6f08);
    }
    return;
}

void func_ov003_021c6f08(void) {
    int v1;
    v1 = func_ov003_021cef6c();
    if (v1 == 0) {
        data_ov003_021da1fc->mUnk_04->mUnk_00 = data_ov003_021da1fc->mUnk_04->mUnk_00 & ((u32) 0xc1fffcffu);
        func_ov003_021c212c(func_ov003_021c7614);
    }
    return;
}
