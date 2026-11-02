#include "03/code_021c7d30.h"
#include "03/code_021bf000.h"
#include "03/code_021c209c.h"
#include "03/code_021c7000.h"
#include "03/code_021c2000.h"
#include "03/code_021ce000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/code_021c7844.h"
#include "03/code_021c8000.h"
#include "03/code_021c9000.h"
#include "03/code_021c91fc.h"
#include "03/code_021cc8d4.h"
#include "03/code_021cd000.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"
#include "code_0214b824.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf410.h"
#include "03/code_021bf698.h"
#include "03/code_021ccd18.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d3488.h"
#include "03/unk_021d6000.h"
#include "code_021510a4.h"
#include "code_02133048.h"
#include "Main/Unknown/code_02147000.h"
#include "03/code_021d2940.h"

#include "03/code_021cef6c.h"
#include "03/code_021c85a0.h"
#include "code_02147cd8.h"

u32 func_ov003_021c8400(void) {
    Unk021d299c a;
    Unk021d299c *b;
    s32 c;
    s32 d;
    s32 e;
    Unk021d299c *f;
    if (func_ov003_021d2a34(&data_ov003_021d67e8) == 0) {
        return 0xe;
    }
    c = func_02147d30(*(u16 *) data_ov003_021da210, 0x1d);
    b = &a;
    a = data_ov003_021d643c;
    for (d = 0; d < 4; d++, c++, a.mUnk_02 += 0x1d) {
        if (c != 2 && c != 6) {
            if (func_ov003_021d2970(b) != 0) {
                return data_ov003_021d6454[c];
            }
        }
    }
    e = func_02147d30(*(u16 *) data_ov003_021da210, 0x1d);
    for (d = 0; d < 4; d++, e++) {
        if (e == 2) {
            a = data_ov003_021d644c;
            d = d * 0x1d;
            a.mUnk_02 = a.mUnk_02 + d;
            if (func_ov003_021d2970(&a) != 0) {
                return 2;
            }
            a = data_ov003_021d6444;
            a.mUnk_02 = a.mUnk_02 + d;
            if (func_ov003_021d2970(&a) != 0) {
                return 3;
            }
            break;
        }
    }
    e = func_02147d30(*(u16 *) data_ov003_021da210, 0x1d);
    for (d = 0; d < 4; d++, e++) {
        if (e == 6) {
            a = data_ov003_021d644c;
            d = d * 0x1d;
            a.mUnk_02 = a.mUnk_02 + d;
            if (func_ov003_021d2970(&a) != 0) {
                return 7;
            }
            a = data_ov003_021d6444;
            a.mUnk_02 = a.mUnk_02 + d;
            if (func_ov003_021d2970(&a) != 0) {
                return 8;
            }
            break;
        }
    }
    d = 0;
    f = data_ov003_021d649c;
    for (; d < 3; d++) {
        if (func_ov003_021d2a34(f) != 0) {
            return d + 0xb;
        }
        f++;
    }
    return 0xe;
}

int func_ov003_021c83cc(int a) {
    int v1;
    int v2;
    v1 = func_02147d30((u32) ((*(u16 *) &data_ov003_021da210)), 0x1d);
    v2 = 0;
    do {
        if (v1 == a) {
            return v2;
        }
        v2 = v2 + 1;
        v1 = v1 + 1;
    } while (v2 < 4);
    return -1;
}

int func_ov003_021c83b0(int a) {
    int v1;
    v1 = func_02147d30((u32) ((*(u16 *) &data_ov003_021da210)), 0x1d);
    return v1 + a;
}

void func_ov003_021c8320(u32 b) {
    s32 a;
    func_ov003_021cce38();
    func_ov003_021bf698();
    if (*(u16 *) data_ov003_021da210 > 6) {
        *(u16 *) data_ov003_021da210 = *(u16 *) data_ov003_021da210 - 6;
    } else {
        *(u16 *) data_ov003_021da210 = 0;
    }
    a = func_02147cd8(*(u16 *) data_ov003_021da210, 0x1d);
    if (a == 0x17) {
        func_ov003_021c8b94();
        return;
    }
    if (a > 0x17) {
        *(u16 *) data_ov003_021da210 = *(u16 *) data_ov003_021da210 + (0x1d - a);
        a = 0;
    }
    func_ov003_021c85a0();
    if (a == 0) {
        func_ov003_021cce58((s32) _s32_div_f(*(u16 *) data_ov003_021da210 * 0x37, 0x91));
        func_ov003_021cce48();
        func_ov003_021c812c();
        data_ov003_021da214->mUnk_38 = 0;
        func_ov003_021d34c8(0, b);
    }
}

void func_ov003_021c82b4(u32 b) {
    s32 a;
    func_ov003_021cce38();
    func_ov003_021bf698();
    *(u16 *) data_ov003_021da210 = *(u16 *) data_ov003_021da210 + 6;
    a = func_02147cd8(*(u16 *) data_ov003_021da210, 0x1d);
    if (a >= 6) {
        func_ov003_021c85a0();
        return;
    }
    *(u16 *) data_ov003_021da210 = *(u16 *) data_ov003_021da210 - a;
    func_ov003_021c8b94();
    func_ov003_021cce58((s32) _s32_div_f(*(u16 *) data_ov003_021da210 * 0x37, 0x91));
    func_ov003_021cce48();
    func_ov003_021c812c();
    data_ov003_021da214->mUnk_38 = 0;
    func_ov003_021d34c8(0, b);
}

void func_ov003_021c824c(void) {
    u32 a;
    s32 b;
    if (data_ov003_021da214->mUnk_44 != 0) {
        a = func_02147d30(*(u16 *) data_ov003_021da210, 0x1d);
        b = func_02147cd8(*(u16 *) data_ov003_021da210, 0x1d) - 0x33;
        *(vu32 *) 0x4000010 = (b << 16) & 0x1ff0000;
        *(vu32 *) 0x4000018 = ((b + data_ov003_021d6460[a]) << 16) & 0x1ff0000;
        data_ov003_021da214->mUnk_44 = 0;
    }
}

void func_ov003_021c81b8(void) {
    Unk021d73d0 a;
    Unk021d299c b;
    s32 d;
    a = data_ov003_021d73d0;
    d = a.mUnk_00[data_ov003_021da204[0]];
    if (d >= 3) {
        func_ov003_021bf760(3, data_ov003_021d64b4[d].mUnk_00, data_ov003_021d64b4[d].mUnk_04,
                            data_ov003_021d64b4[d].mUnk_02);
        return;
    }
    b = data_ov003_021d64b4[d];
    b.mUnk_02 = b.mUnk_02 + data_ov003_021da20c[0] * 0x1d;
    func_ov003_021bf760(1, b.mUnk_00, b.mUnk_04, b.mUnk_02);
}

void func_ov003_021c812c(void) {
    Unk021cdb6c *a;
    s32 b;
    if ((u8) (data_ov003_021da204[0] + 0xf5) <= 2) {
        func_ov003_021c81b8();
        return;
    }
    a = (Unk021cdb6c *) func_ov003_021cdb6c();
    b = data_ov003_021da20c[0] + func_02147d30(*(u16 *) data_ov003_021da210, 0x1d);
    switch (b) {
        case 2:
            if (a->mUnk_f5 != 0) {
                data_ov003_021da204[0] = 2;
            } else {
                data_ov003_021da204[0] = 3;
            }
            break;
        case 6:
            if (a->mUnk_f6 != 0) {
                data_ov003_021da204[0] = 7;
            } else {
                data_ov003_021da204[0] = 8;
            }
            break;
        default:
            data_ov003_021da204[0] = data_ov003_021d6454[b];
            break;
    }
    func_ov003_021c81b8();
}

void func_ov003_021c8100(u32 a) {
    data_ov003_021da204[0] = a;
    data_ov003_021da20c[0] = func_ov003_021c83cc(data_ov003_021d646c[a]);
    func_ov003_021c81b8();
}

void func_ov003_021c7eec(s32 d) {
    Unk021cdb6c *a;
    s32 b;
    s32 c;
    a = (Unk021cdb6c *) func_ov003_021cdb6c();
    b = 0;
    c = data_ov003_021da204[0];
    if (c == 8 && a->mUnk_f5 == 0) {
        if (d == 0) {
            return;
        }
        if (d == 2) {
            return;
        }
    }
    switch (c) {
        case 0:
            if (d == 1) {
                data_ov003_021da204[0] = 0xb;
            } else if (d == 3) {
                data_ov003_021da20c[0] = data_ov003_021da20c[0] + 1;
            } else {
                b = 2;
            }
            break;
        case 0xa:
            if (d == 1) {
                data_ov003_021da20c[0] = data_ov003_021da20c[0] - 1;
            } else if (d == 3) {
                data_ov003_021da204[0] = data_ov003_021da214->mUnk_42;
            } else {
                b = 2;
            }
            break;
        case 0xb:
            if (d == 1) {
                if (data_ov003_021da214->mUnk_47 != 0) {
                    return;
                }
                func_ov003_021cdc10(9);
                data_ov003_021da214->mUnk_47 = 1;
                return;
            } else if (d == 3) {
                data_ov003_021da204[0] = 0;
                data_ov003_021da20c[0] = 0;
                *(u16 *) data_ov003_021da210 = 0;
                func_ov003_021c8b94();
                func_ov003_021cce58(0);
            } else {
                b = 2;
            }
            break;
        case 0xc:
        case 0xd:
            data_ov003_021da214->mUnk_42 = c;
            if (d == 1) {
                data_ov003_021da204[0] = 0xa;
                data_ov003_021da20c[0] = 3;
                *(u16 *) data_ov003_021da210 = 0x91;
                func_ov003_021c8b94();
                func_ov003_021cce58(0x37);
            } else if (d == 3) {
                if (data_ov003_021da214->mUnk_47 != 0) {
                    return;
                }
                func_ov003_021cdc10(9);
                data_ov003_021da214->mUnk_47 = 1;
                return;
            } else if (c == 0xc) {
                data_ov003_021da204[0] = 0xd;
            } else {
                data_ov003_021da204[0] = 0xc;
            }
            break;
        default:
            if (d == 1) {
                if (data_ov003_021da20c[0] != 0) {
                    data_ov003_021da20c[0] = data_ov003_021da20c[0] - 1;
                    break;
                }
                func_ov003_021cdc10(0x13);
                data_ov003_021da214->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c8320, NULL, 0x78);
                return;
            } else if (d == 3) {
                if (data_ov003_021da20c[0] < 3) {
                    data_ov003_021da20c[0] = data_ov003_021da20c[0] + 1;
                    break;
                }
                func_ov003_021cdc10(0x13);
                data_ov003_021da214->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c82b4, NULL, 0x78);
                return;
            } else {
                b = 2;
                if (c == 2) {
                    data_ov003_021da204[0] = 3;
                } else if (c == 3) {
                    data_ov003_021da204[0] = b;
                } else if (c == 7) {
                    data_ov003_021da204[0] = 8;
                } else if (c == 8) {
                    data_ov003_021da204[0] = 7;
                } else {
                    break;
                }
                func_ov003_021cdc10(8);
                func_ov003_021c81b8();
            }
            break;
    }
    if (b != 2) {
        func_ov003_021cdc10(8);
        if (b == 0) {
            func_ov003_021c812c();
        }
    }
}

void func_ov003_021c7ec4(void) {
    u8 a;
    a = data_ov003_021d6430[data_ov003_021da204[0] - 0xb];
    func_ov003_021cc948(data_ov003_021da214->mUnk_0c[1], a, a);
}

void func_ov003_021c7e8c(void) {
    s32 a;
    for (a = 0; a < 4; a++) {
        if (data_ov003_021da214->mUnk_04[a] != 0) {
            data_ov003_021da214->mUnk_04[a] = data_ov003_021da214->mUnk_04[a] - 1;
            if (data_ov003_021da214->mUnk_04[a] == 0) {
                func_ov003_021c8b94();
            }
        }
    }
}

void func_ov003_021c7e20(void) {
    u8 a[4];
    s32 c;
    u8 *b;
    u8 d;
    b = a;
    a[0] = data_ov003_021d73cc[0];
    a[1] = data_ov003_021d73cc[1];
    a[2] = data_ov003_021d73cc[2];
    a[3] = data_ov003_021d73cc[3];
    c = 0;
    d = data_ov003_021da204[0];
    for (; c < 4; c++) {
        if (d == *b) {
            data_ov003_021da214->mUnk_04[c] = 0x14;
            if ((c & 1) != 0) {
                data_ov003_021da214->mUnk_04[c - 1] = 0;
            } else {
                data_ov003_021da214->mUnk_04[c + 1] = 0;
            }
            return;
        }
        b++;
    }
}

u32 func_ov003_021c7d8c(void) {
    Unk021cdb6c *a;
    a = (Unk021cdb6c *) func_ov003_021cdb6c();
    if (a->mUnk_40 == 0) {
        return 0;
    }
    if (a->mUnk_f6 == 0) {
        if (func_02151620(a->mUnk_c8) == 0 && func_02151620(a->mUnk_cc) == 0) {
            return 0;
        }
    }
    if (a->mUnk_f5 == 0) {
        if (func_02151620(a->mUnk_c0) == 0) {
            return 0;
        }
        if (func_02151620(a->mUnk_c4) == 0) {
            return 0;
        }
        if (func_02151640(a->mUnk_c0, a->mUnk_f0) == 0) {
            return 0;
        }
    }
    return 1;
}

void func_ov003_021c7d58(void) {
    int v1;
    v1 = func_ov003_021cef80();
    if (v1 == 0) {
        func_ov003_021cdc10((u32) 6);
        func_ov003_021cef90();
        func_ov003_021cc900((u32) data_ov003_021da214->mUnk_0c[0]);
        func_ov003_021c212c(func_ov003_021c7d3c);
    }
}

void func_ov003_021c7d3c(void) {
    int v1;
    v1 = func_ov003_021cef6c();
    if (v1 == 0) {
        func_ov003_021c212c(func_ov003_021c9450);
    }
}

void func_ov003_021c7d30(u8 a) {
    *(u8 *) &data_ov003_021da208 = a;
}
