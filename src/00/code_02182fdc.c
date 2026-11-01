#include "00/code_02182fdc.h"
#include "code_02148ca0.h"
#include "registers.h"

void func_ov000_02184130(void) {
    Unk020b4934 *chr;
    Unk020b47d8 *scrn;
    Unk020b4a44 *pltt;
    vu16 zero;
    u16 c;
    s32 i;

    func_020b4934(&chr, func_0204799c("WiFi_VS_matching_s_b.ncgr"));
    func_020b47d8(&scrn, func_0204799c("WiFi_VS_matching_s.nscr"));
    func_020b4a44(&pltt, func_0204799c("WiFi_VS_matching_s_b.nclr"));
    data_ov000_021b4c74->mUnk_16f0 = func_0204799c("WiFi_VS_matching.bncl");
    data_ov000_021b4c74->mUnk_16f4 = func_0204799c("WiFi_VS_matching.bnbl");
    data_ov000_021b4c74->mUnk_16f8 = func_0204799c("WiFi_VS_matching.bnll");
    func_020b49bc(&data_ov000_021b4c74->mUnk_16e8, func_0204799c("WiFi_VS_matching_s.nce.ncgr"));
    func_020b48b4(&data_ov000_021b4c74->mUnk_16e4, func_0204799c("WiFi_VS_matching_s.nce.ncer"));
    func_020b4a44(&data_ov000_021b4c74->mUnk_16ec, func_0204799c("WiFi_VS_matching_s_o.nclr"));
    (reg_G2S_DB_BG3CNT) = ((reg_G2S_DB_BG3CNT) & 0x43) | 0x4400;
    zero = 0;
    func_0214cfe4(zero, data_ov000_021b4c74->mUnk_d4, 0x1000);
    func_0214cffc(scrn->mUnk_0c, data_ov000_021b4c74->mUnk_d4, 0x800);
    func_02016468(0x17, 0, chr->mUnk_14, chr->mUnk_10);
    func_02016468(0x1b, 0, data_ov000_021b4c74->mUnk_d4, 0x1000);
    func_02016468(0x1f, 0, pltt->mUnk_0c, 0x80);
    func_02016468(0x23, 0, data_ov000_021b4c74->mUnk_16e8->mUnk_14, data_ov000_021b4c74->mUnk_16e8->mUnk_10);
    func_02016468(0x1e, 0, data_ov000_021b4c74->mUnk_16ec->mUnk_0c, data_ov000_021b4c74->mUnk_16ec->mUnk_08);
    for (i = 0; i < 5; i++) {
        c = (data_ov000_021b4c74->mUnk_16ec->mUnk_0c + 0x60 + data_ov000_021b0658[0])[i];
        data_ov000_021b4c74->mUnk_58[i][0] = c & 0x1f;
        data_ov000_021b4c74->mUnk_58[i][1] = (c & 0x3e0) >> 5;
        data_ov000_021b4c74->mUnk_58[i][2] = (c & 0x7c00) >> 10;
    }
    for (i = 0; i < 5; i++) {
        c = (data_ov000_021b4c74->mUnk_16ec->mUnk_0c + 0x60 + data_ov000_021b0658[1])[i];
        data_ov000_021b4c74->mUnk_94[i][0] = c & 0x1f;
        data_ov000_021b4c74->mUnk_94[i][1] = (c & 0x3e0) >> 5;
        data_ov000_021b4c74->mUnk_94[i][2] = (c & 0x7c00) >> 10;
    }
}

void func_ov000_021840c8(void) {
    s32 i;

    for (i = 0; i < 3; i++) {
        if (data_ov000_021b4c74->mUnk_24[i] == 0) {
            func_0212426c(1, data_ov000_021b0660[i], data_ov000_021b4c74->mUnk_16f8,
                          func_020b3f7c(data_ov000_021b4c74->mUnk_16fc, 10), data_ov000_021b4c74->mUnk_16f0,
                          data_ov000_021b4c74->mUnk_10d4);
        }
    }
}

void func_ov000_0218401c(void) {
    data_ov000_021b4c74->mUnk_08 = data_ov000_021b4c74->mUnk_08 + 1;
    data_ov000_021b4c74->mUnk_08 = data_ov000_021b4c74->mUnk_08 + 1;
    data_ov000_021b4c74->mUnk_10 = func_020ae4c0(1, 0x100, 0, data_ov000_021b4c74->mUnk_08, 10);
    if (data_ov000_021b4c74->mUnk_08 >= 10) {
        data_ov000_021b4c74->mUnk_08 = 10;
    }
    if (data_ov000_021b4c74->mUnk_08 >= 10) {
        if (func_02125fa4() != 0) {
            data_ov000_021b4c74->mUnk_04 = 1;
            data_ov000_021b4c74->mUnk_08 = 0;
            if (func_ov000_02180644() != 0) {
                func_02121190(data_0217b488->mUnk_54, 0, 0);
                data_ov000_021b4c74->mUnk_3c = 0;
            } else {
                func_02121190(data_0217b488->mUnk_54, 1, 0);
                data_ov000_021b4c74->mUnk_3c = 1;
            }
            func_02108b2c();
        }
    }
}

void func_ov000_02183b80(void) {
    Unk02175628Index idx = UNK_02175628_INDEX_8;
    s32 a;
    s32 b;
    u16 v;
    u32 val;
    s32 j;
    s32 sh;
    s32 n;
    s32 i;
    s32 flag;
    u16 name[11];
    u16 buf2[10];
    u16 buf3[10];
    u8 *dst;
    s32 k;

    if (data_ov000_021b4c74->mUnk_08 >= 0x78) {
        data_ov000_021b4c74->mUnk_08 = 0x78;
    }
    data_ov000_021b4c74->mUnk_08 = data_ov000_021b4c74->mUnk_08 + 1;
    if (func_021213a0() != 0) {
        func_02128374();
    } else {
        func_021282c8();
    }
    if (data_ov000_021b4c74->mUnk_3c != 0) {
        if (func_02121434() == 0) {
            data_ov000_021b4c74->mUnk_3c = 0;
            func_02126638(func_020b3f7c(data_ov000_021b4c74->mUnk_16fc, 12), 0, 0, 1, 0, 1, 0);
        }
    }
    if (func_02125fa4() != 0 && func_02128294() != 0 && (u16) (data_02175628[idx].mUnk_00 & 2) != 0) {
        goto hit;
    }
    a = 0;
    b = 0;
    v = data_02175628[idx].mUnk_4c;
    if (v == 0 && data_02175628[idx].mUnk_58 < 5) {
        b = 1;
    }
    if (b == 0 && data_02175628[idx].mUnk_54 == 0 && v != 0) {
        a = 1;
    }
    if (a != 0 && func_02128210(data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a) != 0 && func_021213a0() != 0) {
    hit:
        func_021213e8();
        func_02128310(0);
        data_ov000_021b4c74->mUnk_04 = 10;
        data_ov000_021b4c74->mUnk_20 = 2;
        data_ov000_021b4c74->mUnk_08 = 0;
        func_02125fc0();
        func_0210895c();
        return;
    }
    if (func_02125fa4() != 0 && data_ov000_021b4c74->mUnk_08 >= 0x78 && func_0212111c() == -1) {
        func_ov000_021840c8();
        data_ov000_021b4c74->mUnk_04 = 9;
        data_ov000_021b4c74->mUnk_40 = 1;
        data_ov000_021b4c74->mUnk_08 = 0;
        for (i = 0; i < 3; i++) {
            data_ov000_021b4c74->mUnk_10d4[data_ov000_021b065c[i]].mUnk_00 = 0;
        }
        func_02125fc0();
        func_02128374();
        func_02108990();
        return;
    }
    if (func_02125fa4() != 0 && func_0212111c() == 1) {
        k = 0;
        data_ov000_021b4c74->mUnk_08 = 0;
        if (data_0217d384->mUnk_1f52 <= 1) {
            func_ov000_021840c8();
            data_ov000_021b4c74->mUnk_04 = 9;
            data_ov000_021b4c74->mUnk_40 = 1;
            for (i = 0; i < 3; i++) {
                data_ov000_021b4c74->mUnk_10d4[data_ov000_021b065c[i]].mUnk_00 = 0;
            }
            func_02125fc0();
            func_02128374();
            func_02108990();
            return;
        }
        data_ov000_021b4c74->mUnk_30 = data_0217d384->mUnk_1f52 - 1;
        for (j = 0; j < data_0217d384->mUnk_1f52; j++) {
            if (j != func_ov000_0219bb50()) {
                data_ov000_021b4c74->mUnk_34[k] = j;
                data_ov000_021b4c74->mUnk_24[k] = 1;
                k++;
            }
        }
        for (i = 0; i < data_ov000_021b4c74->mUnk_30; i++) {
            func_0214cffc(func_021202b0(data_ov000_021b4c74->mUnk_34[i]), name, 0x14);
            name[10] = 0;
            func_0212426c(1, data_ov000_021b0664[i], data_ov000_021b4c74->mUnk_16f8, name,
                          data_ov000_021b4c74->mUnk_16f0, data_ov000_021b4c74->mUnk_10d4);
            val = func_02120240(data_ov000_021b4c74->mUnk_34[i]);
            if (val > 9999) {
                val = 9999;
            }
            func_02124fac(func_0212025c(data_ov000_021b4c74->mUnk_34[i]), buf2);
            func_02124fac(val, buf3);
            func_0212426c(1, data_ov000_021b0670[i][0], data_ov000_021b4c74->mUnk_16f8, buf2,
                          data_ov000_021b4c74->mUnk_16f0, data_ov000_021b4c74->mUnk_10d4);
            func_0212426c(1, data_ov000_021b0670[i][1], data_ov000_021b4c74->mUnk_16f8, buf3,
                          data_ov000_021b4c74->mUnk_16f0, data_ov000_021b4c74->mUnk_10d4);
            dst = data_ov000_021b4c74->mUnk_10d8[0];
            dst += i * 0x200;
            func_020ac2fc(func_02120294(data_ov000_021b4c74->mUnk_34[i]), dst, 0x20);
            data_ov000_021b4c74->mUnk_16d8[i] = func_02120278(data_ov000_021b4c74->mUnk_34[i]);
        }
        for (i = 0; i < 3; i++) {
            data_ov000_021b4c74->mUnk_10d4[data_ov000_021b065c[i]].mUnk_00 = 0;
        }
        for (i = 0; i < data_ov000_021b4c74->mUnk_30; i++) {
            data_ov000_021b4c74->mUnk_10d4[data_ov000_021b065c[i]].mUnk_00 = 1;
        }
        data_ov000_021b4c74->mUnk_04 = 2;
        func_021282c8();
        func_02125fc0();
        func_0202b604();
        func_02108a40();
        data_ov000_021b4c74->mUnk_44 = 0;
        return;
    }
    n = func_02121418() - 1;
    flag = 0;
    if (n > 3) {
        n = 3;
    }
    data_ov000_021b4c74->mUnk_0c = data_ov000_021b4c74->mUnk_0c + 1;
    if (data_ov000_021b4c74->mUnk_0c >= 0x50) {
        data_ov000_021b4c74->mUnk_0c = 0;
    }
    if (n > 0) {
        sh = 0x50 >> (n - 1);
        if (data_ov000_021b4c74->mUnk_0c % sh >= sh / 2) {
            flag = 1;
        }
    }
    for (i = 0; i < 3; i++) {
        if (i < n && flag != 0) {
            data_ov000_021b4c74->mUnk_10d4[data_ov000_021b065c[i]].mUnk_00 = 1;
            if (i >= data_ov000_021b4c74->mUnk_38) {
                func_02108adc();
                data_ov000_021b4c74->mUnk_38 = data_ov000_021b4c74->mUnk_38 + 1;
            }
        } else {
            data_ov000_021b4c74->mUnk_10d4[data_ov000_021b065c[i]].mUnk_00 = 0;
        }
    }
    sh = data_ov000_021b4c74->mUnk_38;
    while (n < data_ov000_021b4c74->mUnk_38) {
        func_02108a8c();
        sh--;
        n++;
    }
    data_ov000_021b4c74->mUnk_38 = sh;
}

void func_ov000_02183a0c(void) {
    s32 t = data_ov000_021b4c74->mUnk_08;
    u16 x = (t << 16) / 0x14;
    s32 y = ((0x13 - t) * 0xf33) / 0x14 + 0xcd;
    s32 i;
    Unk020b4a44 *q;

    for (i = 0; i < 3; i++) {
        func_02124b1c(&data_ov000_021b4c74->mUnk_10d4[data_ov000_021b0668[i]], x, y);
    }
    data_ov000_021b4c74->mUnk_08 = data_ov000_021b4c74->mUnk_08 + 1;
    if (data_ov000_021b4c74->mUnk_08 >= 0x14) {
        if (func_02125f88() != 0) {
            q = func_02077f00();
            for (i = 0; i < 3; i++) {
                data_ov000_021b4c74->mUnk_10d4[data_ov000_021b0668[i]].mUnk_00 = 0;
            }
            func_ov000_021840c8();
            for (i = 0; i < data_ov000_021b4c74->mUnk_30; i++) {
                if (data_ov000_021b4c74->mUnk_16d8[i] != 0) {
                    func_02016468(0x23,
                                  func_0212497c(data_ov000_021b0668[i], data_ov000_021b4c74->mUnk_16e4,
                                                data_ov000_021b4c74->mUnk_16f0)
                                      << 5,
                                  data_ov000_021b4c74->mUnk_10d8[i], 0x200);
                    func_02016468(0x1e, (i + 3) << 5, q->mUnk_0c, 0x20);
                }
                data_ov000_021b4c74->mUnk_10d4[data_ov000_021b0660[i] + data_ov000_021b4c74->mUnk_16f0->mUnk_06]
                    .mUnk_00 = 0;
            }
            func_02126638(func_020b3f7c(data_ov000_021b4c74->mUnk_16fc, 11), 0, 0, 1, 0, 0, 0);
            data_ov000_021b4c74->mUnk_04 = 3;
            data_ov000_021b4c74->mUnk_08 = 0;
        }
    }
}

void func_ov000_021839d0(void) {
    data_ov000_021b4c74->mUnk_08 = data_ov000_021b4c74->mUnk_08 + 1;
    if (data_ov000_021b4c74->mUnk_08 >= 0x28) {
        data_ov000_021b4c74->mUnk_04 = 4;
        data_ov000_021b4c74->mUnk_08 = 0;
        func_0212ecc0(&data_0217d068, 0, 0x20b);
    }
}

void func_ov000_02183858(void) {
    s32 orig;
    s32 i1;
    s32 i2;
    s32 cur;
    s32 a;
    s32 b;
    u32 base;
    u16 c;
    s32 j;
    u32 e;

    orig = data_ov000_021b4c74->mUnk_08;
    i1 = orig;
    i2 = orig;
    cur = data_ov000_021b4c74->mUnk_44;
    base = data_ov000_021b4c74->mUnk_16f0->mUnk_06;
    if (orig >= 0x1e) {
        i1 = 0x1d;
    }
    if (orig >= 0x28) {
        i2 = 0x27;
    }
    a = (data_ov000_021b0ce4[i1] << 12) / 100;
    b = (data_ov000_021b0d04[i2] << 12) / 100;
    if (orig < 0x20) {
        c = (i2 << 17) / 0x20;
    } else {
        c = 0;
    }
    data_ov000_021b4c74->mUnk_10d4[base + data_ov000_021b0664[cur]].mUnk_00 = 1;
    for (j = 0; j < 2; j++) {
        data_ov000_021b4c74->mUnk_10d4[(&data_ov000_021b0678[0][0] + cur * 2)[j]].mUnk_00 = 1;
        data_ov000_021b4c74->mUnk_10d4[base + (&data_ov000_021b0670[0][0] + cur * 2)[j]].mUnk_00 = 1;
    }
    e = data_ov000_021b0668[cur] << 6;
    ((Unk02124b1c *) ((u32) data_ov000_021b4c74->mUnk_10d4 + e))->mUnk_00 = 1;
    *(s16 *) ((u8 *) data_ov000_021b4c74->mUnk_18 + cur * 2) = data_ov000_021b069c[i1];
    for (j = 0; j < 2; j++) {
        func_02124b1c(&data_ov000_021b4c74->mUnk_10d4[(&data_ov000_021b0678[0][0] + cur * 2)[j]], 0, a);
    }
    func_02124b1c((Unk02124b1c *) ((u32) data_ov000_021b4c74->mUnk_10d4 + e), c, b);
    data_ov000_021b4c74->mUnk_08 = data_ov000_021b4c74->mUnk_08 + 1;
    if (data_ov000_021b4c74->mUnk_08 >= 0x1e && data_ov000_021b4c74->mUnk_08 >= 0x28) {
        data_ov000_021b4c74->mUnk_08 = 0;
        if (data_ov000_021b4c74->mUnk_44 == data_ov000_021b4c74->mUnk_30 - 1) {
            data_ov000_021b4c74->mUnk_04 = 8;
            return;
        }
        data_ov000_021b4c74->mUnk_44 = data_ov000_021b4c74->mUnk_44 + 1;
        data_ov000_021b4c74->mUnk_04 = 5;
    }
}

void func_ov000_0218381c(void) {
    data_ov000_021b4c74->mUnk_08 = data_ov000_021b4c74->mUnk_08 + 1;
    if (data_ov000_021b4c74->mUnk_08 >= 0x50) {
        data_ov000_021b4c74->mUnk_04 = 4;
        data_ov000_021b4c74->mUnk_08 = 0;
        func_0212ecc0(&data_0217d068, 0, 0x20b);
    }
}

void func_ov000_021837b8(void) {
    data_ov000_021b4c74->mUnk_08 = data_ov000_021b4c74->mUnk_08 + 1;
    // mUnk_30 is 1 to 3 here and indexes the table from 1.
    if (data_ov000_021b4c74->mUnk_08 >= (data_ov000_021b0680 - 1)[data_ov000_021b4c74->mUnk_30]) {
        if (func_02128274() != 0) {
            data_ov000_021b4c74->mUnk_04 = 11;
            data_ov000_021b4c74->mUnk_20 = 4;
            data_ov000_021b4c74->mUnk_08 = 0;
            func_02125fc0();
            func_02036f10((s16) (30));
            func_0212ecc0(&data_0217d068, 0, 0x20c);
        }
    }
}

void func_ov000_021836f4(void) {
    s32 a;
    s32 b;
    u16 v;
    Unk02175628Index idx = UNK_02175628_INDEX_8;

    if (func_02125f88() != 0) {
        func_02126638(func_020b3f7c(data_ov000_021b4c74->mUnk_16fc, 13), 0, 0, 1, 0, 0, 0);
    }
    if (func_02125fa4() != 0) {
        if ((u16) (data_02175628[idx].mUnk_00 & 2) == 0) {
            a = 0;
            b = 0;
            v = data_02175628[idx].mUnk_4c;
            if (v == 0 && data_02175628[idx].mUnk_58 < 5) {
                b = 1;
            }
            if (b == 0 && data_02175628[idx].mUnk_54 == 0 && v != 0) {
                a = 1;
            }
            if (a == 0) {
                return;
            }
            if (func_02128210(data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a) == 0) {
                return;
            }
        }
        data_ov000_021b4c74->mUnk_04 = 10;
        data_ov000_021b4c74->mUnk_20 = 2;
        func_02128310(0);
        func_02125fc0();
    }
}

void func_ov000_02183674(void) {
    data_ov000_021b4c74->mUnk_08 = data_ov000_021b4c74->mUnk_08 + 1;
    data_ov000_021b4c74->mUnk_10 = func_020ae4c0(1, 0, 0x100, data_ov000_021b4c74->mUnk_08, 10);
    if (data_ov000_021b4c74->mUnk_08 >= 10) {
        data_ov000_021b4c74->mUnk_08 = 10;
    }
    if (func_02125f88() != 0 && func_02128294() != 0 && data_ov000_021b4c74->mUnk_08 >= 10) {
        if (data_ov000_021b4c74->mUnk_40 != 0) {
            func_ov000_021806e0(data_ov000_021b4c74->mUnk_20);
            return;
        }
        if (func_0212137c() != 0) {
            func_ov000_021806e0(data_ov000_021b4c74->mUnk_20);
        }
    }
}

void func_ov000_0218364c(void) {
    if (func_02036d08() != 0) {
        if (func_02125f88() != 0) {
            func_ov000_021806e0(data_ov000_021b4c74->mUnk_20);
        }
    }
}

void func_ov000_02183548(void) {
    s32 i;
    u32 base = data_ov000_021b4c74->mUnk_16f0->mUnk_06;
    s32 j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            data_ov000_021b4c74->mUnk_10d4[data_ov000_021b068c[i][j]].mUnk_04 = data_ov000_021b4c74->mUnk_10;
        }
    }
    for (i = 0; i < 3; i++) {
        (data_ov000_021b4c74->mUnk_10d4 + base)[data_ov000_021b0664[i]].mUnk_04 =
            data_ov000_021b4c74->mUnk_10 + data_ov000_021b4c74->mUnk_18[i];
        (data_ov000_021b4c74->mUnk_10d4 + base)[data_ov000_021b0660[i]].mUnk_04 = data_ov000_021b4c74->mUnk_10;
        for (j = 0; j < 2; j++) {
            (data_ov000_021b4c74->mUnk_10d4 + base)[data_ov000_021b0670[i][j]].mUnk_04 =
                data_ov000_021b4c74->mUnk_10 - data_ov000_021b4c74->mUnk_18[i];
        }
    }
    (data_ov000_021b4c74->mUnk_10d4 + base)[12].mUnk_04 = data_ov000_021b4c74->mUnk_10;
}

void func_ov000_021834b0(s32 t) {
    s32 i;

    for (i = 0; i < 5; i++) {
        Unk021b4c74 *p = data_ov000_021b4c74;

        p->mUnk_4c[i] = ((((0x1000 - t) * p->mUnk_58[i][2] + t * p->mUnk_94[i][2]) >> 12) << 10) |
                        ((((0x1000 - t) * p->mUnk_58[i][0] + t * p->mUnk_94[i][0]) >> 12) |
                         ((((0x1000 - t) * p->mUnk_58[i][1] + t * p->mUnk_94[i][1]) >> 12) << 5));
    }
    func_02016468(0x1e, 0x36, data_ov000_021b4c74->mUnk_4c, 10);
}

void func_ov000_02183444(void) {
    s32 t;

    if (data_ov000_021b4c74->mUnk_00 == 8 || data_ov000_021b4c74->mUnk_00 == 11) {
        data_ov000_021b4c74->mUnk_48 = data_ov000_021b4c74->mUnk_48 + 1;
        if (data_ov000_021b4c74->mUnk_48 >= 0x3c) {
            data_ov000_021b4c74->mUnk_48 = 0;
        }
        t = data_ov000_021b4c74->mUnk_48;
        if (t < 0x14) {
            func_ov000_021834b0((t << 12) / 0x14);
            return;
        }
        if (t < 0x28) {
            func_ov000_021834b0(((0x28 - t) << 12) / 0x14);
            return;
        }
        func_ov000_021834b0(0);
    }
}

void func_ov000_0218338c(void) {
    data_ov000_021b4c74->mUnk_00 = data_ov000_021b4c74->mUnk_04;
    switch (data_ov000_021b4c74->mUnk_00) {
        case 0:
            func_ov000_0218401c();
            break;
        case 1:
            func_ov000_02183b80();
            break;
        case 2:
            func_ov000_02183a0c();
            break;
        case 3:
            func_ov000_021839d0();
            break;
        case 4:
            func_ov000_02183858();
            break;
        case 5:
            func_ov000_0218381c();
            break;
        case 8:
            func_ov000_021837b8();
            break;
        case 9:
            func_ov000_021836f4();
            break;
        case 10:
            func_ov000_02183674();
            break;
        case 11:
            func_ov000_0218364c();
            break;
    }
    func_ov000_02183548();
    func_ov000_02183444();
    func_02124c30(data_ov000_021b4c74->mUnk_16f0, data_ov000_021b4c74->mUnk_16e4, data_ov000_021b4c74->mUnk_16f8,
                  func_ov000_021804e0(), data_ov000_021b4c74->mUnk_10d4);
}

void func_ov000_02183330(void) {
    s32 x;
    u32 plane;

    plane = ((reg_GXS_DB_DISPCNT) & 0x1f00) >> 8;
    (reg_GXS_DB_DISPCNT) = ((reg_GXS_DB_DISPCNT) & 0xffffe0ff) | ((plane | 8) << 8);
    x = -data_ov000_021b4c74->mUnk_10;
    if (x <= -0x100) {
        x = -0x100;
    }
    if (x >= 0x100) {
        x = 0x100;
    }
    (reg_G2S_DB_BG3OFS) = x & 0x1ff;
}

void func_ov000_0218330c(void) {
    Unk021b0cd4 x = {func_ov000_021843a8, func_ov000_02184354, func_ov000_0218338c, func_ov000_02183330};

    func_ov000_021806ec(&x);
}

s32 func_ov000_021832f0(void) {
    if (func_0205e548() != 0) {
        return 1;
    }
    return 0;
}

void func_ov000_02182fdc(void *heap) {
    s32 i;

    data_ov000_021b4c70 = func_02036bec(heap, 0x1060);
    data_ov000_021b4c70->mUnk_1038 = heap;
    data_ov000_021b4c70->mUnk_00 = 0;
    data_ov000_021b4c70->mUnk_04 = 0;
    data_ov000_021b4c70->mUnk_08 = 1;
    data_ov000_021b4c70->mUnk_20 = -1;
    data_ov000_021b4c70->mUnk_10 = 0;
    data_ov000_021b4c70->mUnk_24 = 1;
    func_ov000_02180638(0);
    func_ov000_02182e18();
    func_0212b928(heap, data_ov000_021b4c70->mUnk_1048, 3);
    for (i = 0; i < 2; i++) {
        func_02124a98(data_ov000_021b060c[i][0], 1, data_ov000_021b4c70->mUnk_1040, data_ov000_021b4c70->mUnk_104c);
    }
    func_020ae6d4(func_ov000_021804f4(), func_ov000_021804e0());
    func_02124ed0(heap, data_ov000_021b4c70->mUnk_104c, data_ov000_021b4c70->mUnk_1054,
                  &data_ov000_021b4c70->mUnk_103c);
    data_ov000_021b4c70->mUnk_1058 = func_0204799c("wifi.bmg");
    data_ov000_021b4c70->mUnk_105c = func_02047a28("common.bmg");
    {
        s32 v = func_02148ca0();
        u8 a[1] = {1};
        u8 b[1][2] = {{0xc8, 0x10}};
        u32 c[1] = {1};

        for (i = 0; i < 1; i++) {
            v -= func_021243ac(heap, a[i], data_ov000_021b4c70->mUnk_1054, b[i][0], b[i][1], data_ov000_021b060c[i][11],
                               data_ov000_021b4c70->mUnk_1040, data_ov000_021b4c70->mUnk_104c,
                               data_ov000_021b4c70->mUnk_103c, v);
            func_0212426c(1, a[i], data_ov000_021b4c70->mUnk_1054, func_020b3f7c(data_ov000_021b4c70->mUnk_1058, c[i]),
                          data_ov000_021b4c70->mUnk_104c, data_ov000_021b4c70->mUnk_103c);
        }
        {
            u8 d[3][2] = {{0x80, 0x10}, {0xa0, 0x10}, {0x32, 0x10}};
            s32 k;
            void *t;

            for (i = 0; i < 3; i++) {
                k = 0;
                if (i == 1) {
                    data_ov000_021b4c70->mUnk_0c = data_ov000_021b05f0[data_0217b488->mUnk_54];
                    if (data_ov000_021b4c70->mUnk_0c == 0 && !func_ov000_021832f0()) {
                        data_ov000_021b4c70->mUnk_0c = 2;
                    }
                    k = data_ov000_021b4c70->mUnk_0c;
                }
                v -= func_021243ac(heap, data_ov000_021b05e8[i], data_ov000_021b4c70->mUnk_1054, d[i][0], d[i][1],
                                   data_ov000_021b060c[i][1], data_ov000_021b4c70->mUnk_1040,
                                   data_ov000_021b4c70->mUnk_104c, data_ov000_021b4c70->mUnk_103c, v);
                if (i == 2) {
                    t = func_020b3f7c(data_ov000_021b4c70->mUnk_105c, data_ov000_021b0628[i][k]);
                } else if (i == 1) {
                    t = func_020b3f7c(data_ov000_021b4c70->mUnk_1058,
                                      func_ov000_02180668(data_ov000_021b4c70->mUnk_0c));
                } else {
                    t = func_020b3f7c(data_ov000_021b4c70->mUnk_1058, data_ov000_021b0628[i][k]);
                }
                func_0212426c(1, data_ov000_021b05e8[i], data_ov000_021b4c70->mUnk_1054, t,
                              data_ov000_021b4c70->mUnk_104c, data_ov000_021b4c70->mUnk_103c);
            }
        }
    }
    for (i = 0; i < 3; i++) {
        if (i == 2) {
            data_ov000_021b4c70->mUnk_14[i][0] = 0;
            data_ov000_021b4c70->mUnk_14[i][1] = 0x28;
        } else if (i == 1) {
            data_ov000_021b4c70->mUnk_14[i][0] = -0x100;
            data_ov000_021b4c70->mUnk_14[i][1] = 0;
        } else {
            data_ov000_021b4c70->mUnk_14[i][0] = 0x100;
            data_ov000_021b4c70->mUnk_14[i][1] = 0;
        }
    }
    data_ov000_021b4c70->mUnk_2c = 0;
    data_ov000_021b4c70->mUnk_30 = 0;
    func_0212a910(1, 1);
    func_021281c8(0xe);
}
