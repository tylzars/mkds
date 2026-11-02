#include "00/code_02184354.h"
#include "Main/Unknown/code_0210895c.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02148ca0.h"
#include "00/unk_021b4000.h"
#include "00/code_02180608.h"
#include "registers.h"

void func_ov000_02184354(void) {
    u32 a;
    func_0210895c();
    a = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | ((a & ~8) << 8);
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0xf00;
    data_ov000_021b4c74 = 0;
}

// non-matching: 0x1fc bytes against 0x204; the original keeps the three zero constants in r4, r6 and a stack offset
// 0x1c and uses stack offsets 0x20/0x14 for the pointer locals, ours folds the zeros into immediates
void func_ov000_021843a8(void *a) {
    s32 i;
    s32 j;
    s32 k;
    void *b;
    u8 *r;
    u8 *p1;
    u8 *p2;
    u8 *p3;
    u8 *p4;

    func_02029930();
    data_ov000_021b4c74 = func_02036bec(a, 0x170c);
    data_ov000_021b4c74->mUnk_d0 = a;
    data_ov000_021b4c74->mUnk_00 = 0;
    data_ov000_021b4c74->mUnk_04 = 0;
    data_ov000_021b4c74->mUnk_20 = -1;
    data_ov000_021b4c74->mUnk_08 = 0;
    data_ov000_021b4c74->mUnk_0c = 0;
    data_ov000_021b4c74->mUnk_38 = 0;
    for (i = 0; i < 3; i++) {
        data_ov000_021b4c74->mUnk_24[i] = 0;
    }
    data_ov000_021b4c74->mUnk_40 = 0;
    func_ov000_02184130();
    b = func_ov000_021804f4();
    func_020ae6d4(b, func_ov000_021804e0());
    func_02124ed0(a, data_ov000_021b4c74->mUnk_16f0, data_ov000_021b4c74->mUnk_16f8, &data_ov000_021b4c74->mUnk_10d4);
    data_ov000_021b4c74->mUnk_16fc = func_0204799c(data_ov000_021b0e18);
    data_ov000_021b4c74->mUnk_1700 = func_02047a28(data_ov000_021b0e24);
    func_ov000_02184670();
    i = 0;
    r = &data_ov000_021b068c[0][0];
    p1 = data_ov000_021b0668;
    p2 = data_ov000_021b0664;
    p3 = &data_ov000_021b0670[0][0];
    p4 = data_ov000_021b066c;
    for (; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            data_ov000_021b4c74->mUnk_10d4[r[j]].mUnk_00 = 0;
        }
        data_ov000_021b4c74->mUnk_10d4[*p1].mUnk_00 = 1;
        data_ov000_021b4c74->mUnk_10d4[*p2 + data_ov000_021b4c74->mUnk_16f0->mUnk_06].mUnk_00 = 0;
        for (k = 0; k < 2; k++) {
            data_ov000_021b4c74->mUnk_10d4[p3[k] + data_ov000_021b4c74->mUnk_16f0->mUnk_06].mUnk_00 = 0;
        }
        data_ov000_021b4c74->mUnk_10d4[*p4].mUnk_00 = 1;
        r += 5;
        p1++;
        p2++;
        p3 += 2;
        p4++;
    }
    data_ov000_021b4c74->mUnk_10 = 0x100;
    for (i = 0; i < 3; i++) {
        data_ov000_021b4c74->mUnk_12[i] = 0;
        data_ov000_021b4c74->mUnk_18[i] = 0;
    }
    func_ov000_021845ac();
    if (func_ov000_02180644() != 0) {
        func_02126638(func_020b3f7c(data_ov000_021b4c74->mUnk_16fc, 12), 0, 0, 1, 0, 1, 0);
    } else {
        func_02126638(func_020b3f7c(data_ov000_021b4c74->mUnk_16fc, 8), 0, 0, 1, 0, 1, 0);
    }
    data_ov000_021b4c74->mUnk_48 = 0;
}

void func_ov000_021845ac(void) {
    s32 i;
    s32 j;
    u8 *p;
    u8 *q;
    s32 x;
    u8 *r;

    x = data_ov000_021b4c74->mUnk_16f0->mUnk_06;
    i = 0;
    r = &data_ov000_021b0678[0][0];
    p = &data_ov000_021b0670[0][0];
    q = data_ov000_021b0668;
    for (; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            data_ov000_021b4c74->mUnk_10d4[r[j]].mUnk_10 = 1;
            data_ov000_021b4c74->mUnk_10d4[x + p[j]].mUnk_10 = 1;
            func_02124b1c(&data_ov000_021b4c74->mUnk_10d4[r[j]], 0, 0x1000);
        }
        data_ov000_021b4c74->mUnk_10d4[*q].mUnk_10 = 1;
        func_02124b1c(&data_ov000_021b4c74->mUnk_10d4[*q], 0, 0x1000);
        r += 2;
        p += 2;
        q++;
    }
}

// non-matching: size 0x248 against 0x258; stack frame 0x4c against 0x54 and the byte arrays at stack offsets 0x30..
// against 0x38..; same call sequence
void func_ov000_02184670(void) {
    s32 n;
    u32 q;

    n = func_02148ca0();
    {
        s32 i;
        u8 b[3][2] = {{0x78, 0x10}, {0x78, 0x10}, {0x78, 0x10}};
        u8 *t1 = &b[0][0];
        u8 *t2 = data_ov000_021b066c;
        u8 *t3 = data_ov000_021b0664;

        for (i = 0; i < 3; i++) {
            n -= func_021243ac(data_ov000_021b4c74->mUnk_d0, *t3, data_ov000_021b4c74->mUnk_16f8, t1[0], t1[1], *t2,
                               data_ov000_021b4c74->mUnk_16e4, data_ov000_021b4c74->mUnk_16f0,
                               data_ov000_021b4c74->mUnk_10d4, n);
            t2++;
            t1 += 2;
            t3++;
        }
    }
    {
        s32 i;
        s32 j;
        u8 e[3][2][2] = {{{0x30, 0x10}, {0x30, 0x10}}, {{0x30, 0x10}, {0x30, 0x10}}, {{0x30, 0x10}, {0x30, 0x10}}};
        u8 *w = &e[0][0][0];
        u8 *t1 = &data_ov000_021b0678[0][0];
        u8 *t2 = &data_ov000_021b0670[0][0];

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 2; j++) {
                n -= func_021243ac(data_ov000_021b4c74->mUnk_d0, t2[j], data_ov000_021b4c74->mUnk_16f8, w[0], w[1],
                                   t1[j], data_ov000_021b4c74->mUnk_16e4, data_ov000_021b4c74->mUnk_16f0,
                                   data_ov000_021b4c74->mUnk_10d4, n);
                w += 2;
            }
            t1 += 2;
            t2 += 2;
        }
    }
    {
        s32 i;
        void *p;
        u8 c[3][2] = {{0x78, 0x20}, {0x78, 0x20}, {0x78, 0x20}};
        u8 *w = &c[0][0];
        u8 *t1 = data_ov000_021b0668;
        u8 *t2 = data_ov000_021b0660;

        for (i = 0; i < 3; i++) {
            n -= func_021243ac(data_ov000_021b4c74->mUnk_d0, *t2, data_ov000_021b4c74->mUnk_16f8, w[0], w[1], *t1,
                               data_ov000_021b4c74->mUnk_16e4, data_ov000_021b4c74->mUnk_16f0,
                               data_ov000_021b4c74->mUnk_10d4, n);
            p = func_020b3f7c(data_ov000_021b4c74->mUnk_16fc, 9);
            func_0212426c(1, *t2, data_ov000_021b4c74->mUnk_16f8, p, data_ov000_021b4c74->mUnk_16f0,
                          data_ov000_021b4c74->mUnk_10d4);
            t1++;
            w += 2;
            t2++;
        }
    }
    {
        u8 a[2] = {0xa0, 0x10};

        func_ov000_0218065c();
        q = func_ov000_02180668(0);
        func_021243ac(data_ov000_021b4c74->mUnk_d0, 0xc, data_ov000_021b4c74->mUnk_16f8, a[0], a[1],
                      data_ov000_021b4c74->mUnk_16f0->mUnk_06, data_ov000_021b4c74->mUnk_16e4,
                      data_ov000_021b4c74->mUnk_16f0, data_ov000_021b4c74->mUnk_10d4, n);
        func_0212426c(1, 0xc, data_ov000_021b4c74->mUnk_16f8, func_020b3f7c(data_ov000_021b4c74->mUnk_16fc, q),
                      data_ov000_021b4c74->mUnk_16f0, data_ov000_021b4c74->mUnk_10d4);
    }
}
