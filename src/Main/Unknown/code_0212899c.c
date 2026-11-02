#include "Main/Unknown/code_0212899c.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_0205edcc.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_02125ebc.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ab000.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02128884.h"
#include "Main/Unknown/code_02129000.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020ab798.h"
#include "Main/Unknown/code_021296b4.h"
#include "code_0201ea58.h"
#include "code_0214cfe4.h"
#include "code_0212df7c.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_02182fdc.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_020ad000.h"
#include "Main/Unknown/code_02129cbc.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02129788.h"
#include "Main/Unknown/code_020aba9c.h"

#pragma thumb on
void func_021295f4(void) {
    Unk0217d400 *p;
    data_0217d400->mUnk_28++;
    data_0217d400->mUnk_84 = func_020ae4c0(1, 0xc0, 0, data_0217d400->mUnk_28, 0xf);
    data_0217d400->mUnk_86[1][1] =
        func_020ae4c0(1, data_0215d108[1][1], data_0215d100[1][1], data_0217d400->mUnk_28, 0xf);
    p = data_0217d400;
    if (p->mUnk_2c[2].mUnk_10 != 0) {
        data_0217d400->mUnk_86[0][0] = func_020ae4c0(1, data_0215d108[0][0], data_0215d100[0][0], p->mUnk_28, 0xf);
    }
    if (data_0217d400->mUnk_28 >= 0xf) {
        data_0217d400->mUnk_28 = 0xf;
    }
    if (data_0217d400->mUnk_28 >= 0xf && func_02125fa4() != 0) {
        data_0217d400->mUnk_10 = 7;
        data_0217d400->mUnk_24 = 1;
        data_0217d400->mUnk_28 = 0;
    }
    func_021296b4();
    func_02128b0c();
}

void func_021293b4(void) {
    Unk02175628Index i = UNK_02175628_INDEX_8;
    Unk0217d400 *p;
    Unk0217d400_2c *q;
    void *w;
    s32 v;
    s32 f;
    s32 g;
    s32 n;
    u16 c;
    f = 0;
    v = -1;
    g = 0;
    c = data_02175674[i].mUnk_00;
    if (c == 0 && data_02175680[i].mUnk_00 < 5) {
        g = 1;
    }
    if (g == 0 && data_0217567c[i].mUnk_00 == 0 && c != 0) {
        f = 1;
    }
    if (f != 0) {
        v = func_0201ea84(data_0217d400->mUnk_a4[1], data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
    }
    p = data_0217d400;
    q = &p->mUnk_2c[p->mUnk_04];
    w = func_020ab798();
    func_0214cffc(w, q, 0x18);
    func_021296b4();
    if (v == 5 || (func_020ab8c4() == 1 && (u16) (data_02175628[i].mUnk_00 & 1) != 0)) {
        p = data_0217d400;
        if (p->mUnk_1c[0] != 0) {
            p->mUnk_10 = 8;
            data_0217d400->mUnk_2c[2].mUnk_10 = 1;
            func_02125fc0();
            func_020ab8cc(1);
            data_0217d400->mUnk_24 = 0;
            func_0212ecc0(&data_0217d068, 0, 4);
        } else {
            func_0212ecc0(&data_0217d068, 0, 0x16);
        }
    } else if (v == 6 || (func_020ab8c4() == 2 && (u16) (data_02175628[i].mUnk_00 & 1) != 0)) {
        p = data_0217d400;
        if (p->mUnk_1c[1] != 0) {
            p->mUnk_10 = 8;
            data_0217d400->mUnk_2c[2].mUnk_10 = 0;
            func_02125fc0();
            func_020ab8cc(2);
            data_0217d400->mUnk_24 = 0;
            func_0212ecc0(&data_0217d068, 0, 0xe);
        } else {
            func_0212ecc0(&data_0217d068, 0, 0x16);
        }
    } else if ((u16) (data_02175628[i].mUnk_00 & 0x800) != 0) {
        if (data_021759d0->mUnk_00 == 0) {
            data_0217d400->mUnk_08 = data_0215d11c[data_0217d400->mUnk_08];
        } else {
            data_0217d400->mUnk_08 = data_0215d122[data_0217d400->mUnk_08];
        }
        func_020ab9d0(data_0217d400->mUnk_08);
        func_0212ecc0(&data_0217d068, 0, 0x1e5);
    } else {
        p = data_0217d400;
        n = p->mUnk_08;
        f = 0;
        switch (v) {
            case 0:
                p->mUnk_08 = 1;
                func_020ab9d0(data_0217d400->mUnk_08);
                f = 1;
                break;
            case 1:
                p->mUnk_08 = 2;
                func_020ab9d0(data_0217d400->mUnk_08);
                f = 1;
                break;
            case 2:
                p->mUnk_08 = 3;
                func_020ab9d0(data_0217d400->mUnk_08);
                f = 1;
                break;
            case 3:
                p->mUnk_08 = 4;
                func_020ab9d0(data_0217d400->mUnk_08);
                f = 1;
                break;
            case 4:
                p->mUnk_08 = 5;
                func_020ab9d0(data_0217d400->mUnk_08);
                f = 1;
                break;
        }
        if (f != 0) {
            if (n != data_0217d400->mUnk_08) {
                func_0212ecc0(&data_0217d068, 0, 0x1e5);
            } else {
                func_0212ecc0(&data_0217d068, 0, 0x1ed);
            }
        }
    }
    func_02128b0c();
}

void func_021291d4(void) {
    u16 buf[10];
    u16 buf2[0xfe];
    Unk0217d400 *p;
    s32 n;
    s32 a;
    s32 b;
    s32 c;
    data_0217d400->mUnk_28++;
    data_0217d400->mUnk_84 = func_020ae4c0(1, 0, 0xc0, data_0217d400->mUnk_28, 0xf);
    data_0217d400->mUnk_86[1][1] =
        func_020ae4c0(1, data_0215d100[1][1], data_0215d108[1][1], data_0217d400->mUnk_28, 0xf);
    p = data_0217d400;
    if (p->mUnk_2c[2].mUnk_10 == 0) {
        data_0217d400->mUnk_86[0][0] = func_020ae4c0(1, data_0215d100[0][0], data_0215d108[0][0], p->mUnk_28, 0xf);
    }
    if (data_0217d400->mUnk_28 >= 0xf) {
        data_0217d400->mUnk_28 = 0xf;
    }
    if (data_0217d400->mUnk_28 >= 0xf && func_02125f88() != 0) {
        p = data_0217d400;
        if (p->mUnk_2c[2].mUnk_10 != 0) {
            if (p->mUnk_2c[2].mUnk_14 == 0xc) {
                a = (s32) func_020b3f7c(p->mUnk_c0, 0x11);
                b = (s32) func_020b3f7c(data_0217d400->mUnk_c0, 0);
                c = (s32) func_020b3f7c(p->mUnk_c0, 1);
                func_02125fd4(a, b, c, 0, 0, 1, 1, 0);
            } else {
                a = (s32) func_020b3f7c(p->mUnk_c0, 0xe);
                n = func_020adc7c(data_0217d400->mUnk_2c[1].mUnk_00, buf);
                buf[n] = 0;
                func_0212513c(buf, (u16 *) a, &buf2[1], 0x1f4);
                b = (s32) func_020b3f7c(data_0217d400->mUnk_c0, 0);
                c = (s32) func_020b3f7c(data_0217d400->mUnk_c0, 1);
                func_02125fd4((u32) &buf2[1], b, c, 0, 0, 1, 1, 0);
            }
            data_0217d400->mUnk_10 = 9;
            data_0217d400->mUnk_28 = 0;
        } else if (p->mUnk_2c[2].mUnk_14 == 0xc) {
            p->mUnk_04 = 0;
            data_0217d400->mUnk_08 = 0;
            func_020ab9d0(data_0217d400->mUnk_08);
            func_020ab758(data_0215d0e0[0]);
            func_02129e78();
            func_0212a4bc();
            data_0217d400->mUnk_10 = 1;
            data_0217d400->mUnk_28 = 0;
            func_02126638(func_020b3f7c(data_0217d400->mUnk_c0, 7), 0, 0, 0, 0, 0, 0);
        } else {
            p->mUnk_2c[2].mUnk_16 = 7;
        }
    }
}

void func_0212913c(void) {
    s16 v;
    data_0217d400->mUnk_28++;
    v = data_0215d100[1][0];
    data_0217d400->mUnk_86[0][0] =
        func_020ae4c0(1, data_0215d100[0][0], data_0215d100[0][0] - (0xc0 - v), data_0217d400->mUnk_28, 0xf);
    data_0217d400->mUnk_86[1][0] = func_020ae4c0(1, data_0215d108[1][0], v, data_0217d400->mUnk_28, 0xf);
    if (data_0217d400->mUnk_28 >= 0xf) {
        data_0217d400->mUnk_28 = 0xf;
    }
    if (data_0217d400->mUnk_28 >= 0xf) {
        if (func_02125fa4() != 0) {
            data_0217d400->mUnk_10 = 0xa;
            data_0217d400->mUnk_28 = 0;
        }
    }
}

void func_02128f7c(void) {
    Unk0217d400 *p;
    s16 v;
    s32 a;
    s32 b;
    if (data_0217d400->mUnk_28 >= 0xf) {
        data_0217d400->mUnk_28 = 0xf;
    }
    if (func_02125f54() != 0 && func_02125f60() == 1) {
        v = data_0215d100[1][0];
        data_0217d400->mUnk_86[1][0] = func_020ae4c0(1, v, data_0215d108[1][0], data_0217d400->mUnk_28, 0xf);
        data_0217d400->mUnk_86[0][0] =
            func_020ae4c0(1, data_0215d100[0][0] - (0xc0 - v), data_0215d100[0][0], data_0217d400->mUnk_28, 0xf);
    }
    if (func_02125f88() != 0 && data_0217d400->mUnk_28 >= 0xf) {
        if (func_02125f60() == 0) {
            p = data_0217d400;
            if (p->mUnk_2c[2].mUnk_14 == 0xc) {
                func_02060cb4(&p->mUnk_2c[2], &p->mUnk_2c[1]);
                func_0205edf8();
                a = (s32) func_020b3f7c(data_0217d400->mUnk_c0, 0x81);
                func_02126248(a, 0, 1, 1, 0, 1);
                data_0217d400->mUnk_10 = 0xb;
            } else {
                data_0217aa08->mUnk_00->mUnk_31_0 = 1;
                func_0214d168(data_0217aa08->mUnk_00->mUnk_0c, 0, 0x14);
                func_0214d1fc(&p->mUnk_2c[1], data_0217aa08->mUnk_00->mUnk_0c, 0x14);
                func_02056d40();
                func_02125ebc(0x21);
                a = (s32) func_020b3f7c(data_0217d400->mUnk_c0, 0x10);
                b = (s32) func_020b3f7c(data_0217d400->mUnk_c0, 4);
                func_02126138(a, b, 0, 1, 1, 0);
                data_0217d400->mUnk_10 = 0xc;
            }
            data_0217d400->mUnk_28 = 0;
        } else {
            data_0217d400->mUnk_10 = 6;
            data_0217d400->mUnk_2c[2].mUnk_10 = 0;
            data_0217d400->mUnk_28 = 0;
            func_02126638(func_020b3f7c(data_0217d400->mUnk_c0, 0xf), 0, 0, 0, 0, 0, 0);
        }
    } else {
        if (func_02125f54() != 0 || func_02125f88() != 0) {
            func_02125fc0();
            data_0217d400->mUnk_28++;
        }
    }
}

void func_02128ecc(void) {
    Unk0217d400 *p;
    s32 a;
    s32 w;
    s32 b;
    if (func_02125f6c() != 0) {
        func_0212ecc0(&data_0217d068, 0, 0x22);
    }
    data_0217d400->mUnk_28++;
    if (func_02125fa4() != 0) {
        p = data_0217d400;
        if (p->mUnk_28 > 0x5a) {
            w = (data_0217aa08->mUnk_28 == 0) ? (data_021759d4->mUnk_0c != 0 ? data_021759d4->mUnk_10 : 0) : 1;
            if (w == 0) {
                p->mUnk_10 = 0xc;
                data_0217d400->mUnk_28 = 0;
                func_02125ebc(0x21);
                a = (s32) func_020b3f7c(data_0217d400->mUnk_c0, 9);
                b = (s32) func_020b3f7c(data_0217d400->mUnk_c0, 4);
                func_02126138(a, b, 0, 1, 1, 0);
            }
        }
    }
}

void func_02128e08(void) {
    s32 a;
    s32 w;
    s32 b;
    s32 c;
    s32 v;
    if (func_02125f54() != 0) {
        func_02125fc0();
    }
    if (func_02125f88() != 0) {
        w = (data_0217aa08->mUnk_28 == 0) ? (data_021759d4->mUnk_0c != 0 ? data_021759d4->mUnk_10 : 0) : 1;
        if (w == 0) {
            func_02125ebc(0x23);
            v = data_0217d400->mUnk_2c[2].mUnk_14;
            if (v == 0xc || v == 7) {
                data_0217d400->mUnk_2c[2].mUnk_16 = v;
                return;
            }
            if (v == 0xb) {
                data_0217d400->mUnk_10 = 0xd;
                data_0217d400->mUnk_28 = 0;
                a = (s32) func_020b3f7c(data_0217d400->mUnk_c0, 0x13);
                b = (s32) func_020b3f7c(data_0217d400->mUnk_c0, 0);
                c = (s32) func_020b3f7c(data_0217d400->mUnk_c0, 1);
                func_02125fd4(a, b, c, 0, 0, 1, 1, 0);
            }
        }
    }
}

void func_02128dbc(void) {
    if (func_02125f88() != 0) {
        if (func_02125f60() == 0) {
            data_0217d400->mUnk_2c[2].mUnk_16 = 3;
        } else {
            data_0217d400->mUnk_2c[2].mUnk_16 = 0;
        }
    } else {
        if (func_02125f54() != 0) {
            func_02125fc0();
        }
    }
}

void func_02128cfc(void) {
    s32 i;
    s32 j;
    s32 k;
    u16 buf[2];
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < data_0215d0e0[i]; k++) {
                buf[0] = 0;
                buf[1] = 0;
                buf[0] = data_0217d400->mUnk_2c[i].mUnk_00[k];
                func_0212426c(j, data_0215d134[i][k], data_0217d400->mUnk_ac[i], buf, data_0217d400->mUnk_9c[i],
                              data_0217d400->mUnk_74[i][j]);
            }
        }
    }
}

void func_02128ca0(void) {
    s32 i;
    s32 n;
    for (i = 0; i < 2; i++) {
        if (data_0217d400->mUnk_14[i] != 0) {
            n = data_0217d400->mUnk_04;
            data_0217d400->mUnk_74[n][1][data_0215d128[n][i][0]].mUnk_00 = 1;
        } else {
            n = data_0217d400->mUnk_04;
            data_0217d400->mUnk_74[n][1][data_0215d128[n][i][0]].mUnk_00 = 0;
        }
    }
}

void func_02128c40(void) {
    s32 i;
    s32 n;
    for (i = 0; i < 2; i++) {
        if (data_0217d400->mUnk_1c[i] != 0) {
            n = data_0217d400->mUnk_04;
            data_0217d400->mUnk_74[n][1][data_0215d128[n][i][1]].mUnk_00 = 0;
        } else {
            n = data_0217d400->mUnk_04;
            data_0217d400->mUnk_74[n][1][data_0215d128[n][i][1]].mUnk_00 = 1;
        }
    }
}

void func_02128bd4(void) {
    s32 i;
    for (i = 0; i < data_0215d0e0[data_0217d400->mUnk_04]; i++) {
        data_0217d400->mUnk_74[data_0217d400->mUnk_04][1][data_0215d14c[data_0217d400->mUnk_04][i]].mUnk_00 = 0;
    }
    data_0217d400->mUnk_74[data_0217d400->mUnk_04][1][data_0215d14c[data_0217d400->mUnk_04][func_020ab748()]].mUnk_00 =
        1;
}

void func_02128b54(void) {
    u16 buf[10];
    s32 n;
    s32 k;
    s32 l;
    s32 i;
    s32 j;
    u8 *q;
    if (data_0217d400->mUnk_04 == 1) {
        n = func_020adc7c(data_0217d400->mUnk_2c[1].mUnk_00, buf);
        k = 6;
        if (n > 4) {
            k = 10 - n;
        }
        i = 0;
        q = data_0215d0f0;
        l = 6 - k;
        for (; i < 6; i++) {
            for (j = 0; j < 2; j++) {
                if (i >= l && data_0217d400->mUnk_2c[2].mUnk_14 != 0xc) {
                    data_0217d400->mUnk_74[1][j][*q].mUnk_00 = 1;
                } else {
                    data_0217d400->mUnk_74[1][j][*q].mUnk_00 = 0;
                }
            }
            q++;
        }
    }
}

void func_02128b0c(void) {
    s32 i;
    s32 z;
    u8 *q;
    u8 c;
    i = 0;
    q = data_0215d0e8;
    z = 0;
    for (; i < 6; i++) {
        c = *q;
        if (c != 0xff) {
            data_0217d400->mUnk_74[1][1][c].mUnk_00 = z;
        }
        q++;
    }
    data_0217d400->mUnk_74[1][1][data_0215d0e8[data_0217d400->mUnk_08]].mUnk_00 = 1;
}

void func_021289e0(void) {
    s32 i;
    Unk0217d400 *p;
    func_0212a920();
    func_02125928();
    data_0217d400->mUnk_0c = data_0217d400->mUnk_10;
    if (data_0217d400->mUnk_24 != 0) {
        func_020abae0();
    }
    switch (data_0217d400->mUnk_0c) {
        case 0:
            func_02129bdc();
            break;
        case 1:
            func_02129acc();
            break;
        case 2:
            func_02129994();
            break;
        case 3:
            func_0212982c();
            break;
        case 4:
            func_021297cc();
            break;
        case 5:
            func_02129788();
            break;
        case 6:
            func_021295f4();
            break;
        case 7:
            func_021293b4();
            break;
        case 8:
            func_021291d4();
            break;
        case 9:
            func_0212913c();
            break;
        case 10:
            func_02128f7c();
            break;
        case 11:
            func_02128ecc();
            break;
        case 12:
            func_02128e08();
            break;
        case 13:
            func_02128dbc();
            break;
    }
    func_02128cfc();
    func_02128bd4();
    func_02128b54();
    func_02128ca0();
    func_02128c40();
    func_02129ea4();
    for (i = 0; i < 2; i++) {
        p = data_0217d400;
        func_02124c30(p->mUnk_9c[i], p->mUnk_90, p->mUnk_ac[i], func_02128898(), p->mUnk_74[i][0]);
    }
    p = data_0217d400;
    func_02124c30(p->mUnk_9c[p->mUnk_04], p->mUnk_90, p->mUnk_ac[p->mUnk_04], func_02128884(),
                  p->mUnk_74[p->mUnk_04][1]);
}

void func_0212899c(void) {
    func_020ab94c(0, data_0217d400->mUnk_84 + 0x28);
    *(vu32 *) 0x400101c = (-data_0217d400->mUnk_84 << 16) & 0x1ff0000;
    func_020aba9c();
    func_021258f0();
}
#pragma thumb off
