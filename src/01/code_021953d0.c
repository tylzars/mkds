#include "01/code_021953d0.h"
#include "01/code_021959c0.h"
#include "01/code_021959d8.h"
#include "01/code_02195a54.h"
#include "01/code_02195a6c.h"
#include "01/code_02193b1c.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "01/unk_021a6000.h"
#include "01/code_021972f4.h"
#include "Main/Unknown/code_0205f000.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_02125000.h"

void func_ov001_02195894(void) {
    s32 i;
    s32 j;
    u16 m;
    s16 v;

    data_ov001_021a9bdc->mUnk_58++;
    v = func_020ae4c0(1, 0x100, 0, data_ov001_021a9bdc->mUnk_58, 10);
    data_ov001_021a9bdc->mUnk_68 = v;
    m = data_ov001_021a9bdc->mUnk_1c->mUnk_06;
    data_ov001_021a9bdc->mUnk_3c[15].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[16].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[12].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[13].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[14].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[m + 8].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        data_ov001_021a9bdc->mUnk_3c[data_ov001_021a67f8[i]].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_3c[m + data_ov001_021a67d4[i]].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_3c[m + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            data_ov001_021a9bdc->mUnk_3c[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (data_ov001_021a9bdc->mUnk_58 > 10) {
        func_ov001_02197024();
    }
    if (data_ov001_021a9bdc->mUnk_58 == 2) {
        data_ov001_021a9bdc->mUnk_3c[12].mUnk_00 = 1;
    }
}

void func_ov001_021957a8(void) {
    Unk021a9bdc *p;

    data_ov001_021a9bdc->mUnk_50 = data_ov001_021a9bdc->mUnk_54;
    switch (data_ov001_021a9bdc->mUnk_50) {
        case 0:
            func_ov001_021968bc();
            break;
        case 1:
            func_ov001_02196724();
            break;
        case 2:
            func_ov001_02196514();
            break;
        case 3:
            func_ov001_021963a8();
            break;
        case 4:
            func_ov001_0219623c();
            break;
        case 5:
            func_ov001_021960a4();
            break;
        case 6:
            func_ov001_02196058();
            break;
        case 7:
            func_ov001_02195ff8();
            break;
        case 8:
            func_ov001_02195eb8();
            break;
        case 9:
            func_ov001_02195ea0();
            break;
        case 10:
            func_ov001_02195e38();
            break;
        case 11:
            func_ov001_02195d64();
            break;
        case 12:
            func_ov001_02195ba4();
            break;
        case 13:
            func_ov001_02195a6c();
            break;
        case 14:
            func_ov001_02195a54();
            break;
        case 15:
            func_ov001_021959d8();
            break;
        case 16:
            func_ov001_021959c0();
            break;
        case 17:
            func_ov001_02195894();
            break;
    }
    p = data_ov001_021a9bdc;
    func_02124c30(p->mUnk_08, p->mUnk_04, p->mUnk_10, func_02111318(), p->mUnk_38);
    p = data_ov001_021a9bdc;
    func_02124c30(p->mUnk_1c, p->mUnk_18, p->mUnk_24, func_0211130c(), p->mUnk_3c);
}

void func_ov001_0219574c(void) {
    Unk021a9bdc *p;

    *(vu32 *) 0x4000010 = (-data_ov001_021a9bdc->mUnk_5c << 16) & 0x1ff0000;
    p = data_ov001_021a9bdc;
    *(vu32 *) 0x4000014 = (-p->mUnk_60 & 0x1ff) | ((-p->mUnk_64 << 16) & 0x1ff0000);
    *(vu32 *) 0x400101c = -data_ov001_021a9bdc->mUnk_68 & 0x1ff;
    func_02111428();
}

void func_ov001_02195704(void) {
    u32 t;
    u32 u;

    t = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
    t |= 0x13;
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | (t << 8);
    u = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    u |= 9;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | (u << 8);
}

void func_ov001_021956dc(void) {
    Unk021a8294 a = data_ov001_021a82d4;

    func_02111494(&a);
}

void func_ov001_021953d0(void) {
    Unk020b4a44 *l0 = 0;
    Unk020b4934 *l4 = 0;
    Unk020b4a44 *l8 = 0;
    Unk020b47d8 *lc = 0;
    Unk020b4a44 *l10 = 0;
    Unk020b4934 *l14 = 0;
    Unk020b4a44 *l18 = 0;
    u16 *x;

    func_020b49bc(&data_ov001_021a9bd8->mUnk_00, func_0204799c(data_0216cc98));
    func_020b48b4(&data_ov001_021a9bd8->mUnk_04, func_0204799c(data_0216ccd0));
    func_020b4a44(&l0, func_0204799c(data_0216ccec));
    data_ov001_021a9bd8->mUnk_08 = func_0204799c(data_0216cca4);
    data_ov001_021a9bd8->mUnk_10 = func_0204799c(data_0216cc80);
    func_020b49bc(&data_ov001_021a9bd8->mUnk_14, func_0204799c(data_0216cc94));
    func_020b48b4(&data_ov001_021a9bd8->mUnk_18, func_0204799c(data_0216cc70));
    func_020b4a44(&l10, func_0204799c(data_0216cc68));
    data_ov001_021a9bd8->mUnk_1c = func_0204799c(data_0216cc7c);
    data_ov001_021a9bd8->mUnk_20 = func_0204799c(data_0216cd34);
    data_ov001_021a9bd8->mUnk_24 = func_0204799c(data_0216ccb0);
    func_020b49bc(&data_ov001_021a9bd8->mUnk_28, func_0204799c(data_0216cd18));
    func_020b48b4(&data_ov001_021a9bd8->mUnk_2c, func_0204799c(data_0216cd28));
    func_020b4a44(&data_ov001_021a9bd8->mUnk_30, func_0204799c(data_0216ccb8));
    data_ov001_021a9bd8->mUnk_34 = func_0204799c(data_0216ccd8);
    data_ov001_021a9bd8->mUnk_38 = (void *) func_020b4018(0);
    data_ov001_021a9bd8->mUnk_3c = (void *) func_020b400c(0);
    data_ov001_021a9bd8->mUnk_40 = func_020b4030(0);
    data_ov001_021a9bd8->mUnk_44 = (void *) func_020b4000(0);
    func_020b4934(&l4, func_0204799c(data_0216cc6c));
    func_020b4a44(&l8, func_0204799c(data_0216ccc8));
    func_020b47d8(&lc, func_0204799c(data_0216cc9c));
    func_020b4934(&l14, func_0204799c(data_0216cd14));
    func_020b4a44(&l18, func_0204799c(data_0216ccbc));
    func_020b47d8(&data_ov001_021a9bd8->mUnk_48, func_0204799c(data_0216ccf8));
    x = l0->mUnk_0c;
    func_02016468(0x13, 0, data_ov001_021a9bd8->mUnk_00->mUnk_14, data_ov001_021a9bd8->mUnk_00->mUnk_10);
    func_02016468(0xe, 0, l0->mUnk_0c, 0x1a0);
    func_02016468(0xe, 0x1c0, (u8 *) x + 0x1c0, 0x40);
    func_02016468(0x23, 0, data_ov001_021a9bd8->mUnk_14->mUnk_14, data_ov001_021a9bd8->mUnk_14->mUnk_10);
    func_02016468(0x1e, 0, l10->mUnk_0c, l10->mUnk_08);
    func_02016468(4, 0, l4->mUnk_14, l4->mUnk_10);
    func_02016468(0xf, 0, l8->mUnk_0c, 0x40);
    func_02016468(8, 0, lc->mUnk_0c, lc->mUnk_08);
    func_02016468(0x17, 0, l14->mUnk_14, l14->mUnk_10);
    func_02016468(0x1f, 0, l18->mUnk_0c, 0x40);
    func_02016468(0x1b, 0, data_ov001_021a9bd8->mUnk_48->mUnk_0c, data_ov001_021a9bd8->mUnk_48->mUnk_08);
    x = data_ov001_021a9bd8->mUnk_30->mUnk_0c;
    func_02016468(0x1e, data_ov001_021a6604[0] << 5, (u8 *) x + (data_ov001_021a660c[0] << 5), 0x20);
    func_02016468(0x1e, data_ov001_021a6604[1] << 5, (u8 *) x + (data_ov001_021a660c[1] << 5), 0x20);
    func_02016468(0x1e, data_ov001_021a6604[2] << 5, (u8 *) x + (data_ov001_021a660c[2] << 5), 0x20);
}
