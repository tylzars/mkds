#include "01/code_0219b540.h"

#include "01/unk_021a6000.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_02048000.h"
#include "01/unk_021a9000.h"
#include "code_02013740.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"
#include "code_02135014.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128244.h"
#include "Main/Unknown/code_0212775c.h"
#include "01/code_0219c000.h"
#include "Main/Unknown/code_0212b000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/unk_02175628.h"
#include "code_0201ea58.h"
#include "Main/Unknown/code_02117218.h"
#include "registers.h"
#include "Main/Unknown/code_02116000.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_0211d000.h"
#include "Main/Unknown/code_0211e000.h"
#include "Main/Unknown/code_02148ca0.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0211732c.h"

void func_ov001_0219c6f0(void) {
    Unk020b4934 *p3 = 0;
    Unk02021dc8 *p4 = 0;
    Unk020b4a44 *p5 = 0;
    Unk020b4934 *p0 = 0;
    Unk020b4a44 *p2 = 0;
    Unk020b47d8 *p1 = 0;

    func_020b496c(&p0, func_0204799c(data_ov001_021a87b8));
    func_020b4810(&p1, func_0204799c(data_ov001_021a8794));
    func_020b4a7c(&p2, func_0204799c(data_ov001_021a87a8));
    func_020b49f4(&p3, func_0204799c(data_ov001_021a87a4));
    func_020b48ec(&p4, func_0204799c(data_ov001_021a87b4));
    func_020b4a7c(&p5, func_0204799c(data_ov001_021a8798));
    func_0211732c();
}

void func_ov001_0219c544(void) {
    Unk020b4934 *a;
    Unk020b4934 *b;
    Unk020b4a44 *c;
    Unk020b47d8 *d;

    a = 0;
    b = 0;
    c = 0;
    d = 0;
    func_020b4934(&b, func_0204799c(data_ov001_021a87b8));
    func_020b47d8(&d, func_0204799c(data_ov001_021a8794));
    func_020b4a44(&c, func_0204799c(data_ov001_021a87a8));
    data_ov001_021a9bf4->mUnk_40 = func_02036bec(data_ov001_021a9bf4->mUnk_44, 0x800);
    data_ov001_021a9bf4->mUnk_04 = func_0204799c(data_ov001_021a879c);
    data_ov001_021a9bf4->mUnk_08 = func_0204799c(data_ov001_021a87b0);
    func_020b48b4(&data_ov001_021a9bf4->mUnk_00, func_0204799c(data_ov001_021a87bc));
    data_ov001_021a9bf4->mUnk_10 = func_0204799c(data_ov001_021a8790);
    data_ov001_021a9bf4->mUnk_14 = func_0204799c(data_ov001_021a87a0);
    data_ov001_021a9bf4->mUnk_18 = func_0204799c(data_ov001_021a87ac);
    func_020b49bc(&a, func_0204799c(data_ov001_021a87a4));
    func_020b48b4(&data_ov001_021a9bf4->mUnk_0c, func_0204799c(data_ov001_021a87b4));
    func_020b4a44(&data_ov001_021a9bf4->mUnk_1c, func_0204799c(data_ov001_021a8798));
    data_ov001_021a9bf4->mUnk_20 = func_020b4018(0);
    data_ov001_021a9bf4->mUnk_24 = func_020b400c(0);
    data_ov001_021a9bf4->mUnk_28 = func_020b4030(0);
    data_ov001_021a9bf4->mUnk_2c = func_020b4000(0);
    func_02016468(0x17, 0, b->mUnk_14, b->mUnk_10);
    func_02016468(0x1f, 0, c->mUnk_0c, 0x20);
    func_02016468(0x1b, 0, d->mUnk_0c, d->mUnk_08);
    func_02016468(0x1b, 0x800, data_ov001_021a9bf4->mUnk_40, 0x800);
    func_02016468(0x23, 0, a->mUnk_14, a->mUnk_10);
    func_02016468(0x1e, 0, data_ov001_021a9bf4->mUnk_1c->mUnk_0c, data_ov001_021a9bf4->mUnk_1c->mUnk_08);
}

void func_ov001_0219c480(void) {
    u16 cnt;
    s32 i;

    data_ov001_021a9bf4->mUnk_4c = 0;
    data_ov001_021a9bf4->mUnk_50 = 0;
    data_ov001_021a9bf4->mUnk_58 = 0;
    data_ov001_021a9bf4->mUnk_5c = -0xc0;
    for (i = 0; i < 6; i++) {
        data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b6c[i]].mUnk_06 = -0xc0;
    }
    data_ov001_021a9bf4->mUnk_34[10].mUnk_06 = -0xc0;
    data_ov001_021a9bf4->mUnk_34[11].mUnk_06 = -0xc0;
    cnt = data_ov001_021a9bf4->mUnk_10->mUnk_06;
    for (i = 0; i < 5; i++) {
        data_ov001_021a9bf4->mUnk_34[cnt + data_ov001_021a6b54[i]].mUnk_06 = -0xc0;
    }
    data_ov001_021a9bf4->mUnk_34[cnt + 5].mUnk_06 = -0xc0;
    for (i = 0; i < 2; i++) {
        data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b3c[i]].mUnk_06 = -0xc0;
        data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b38[i]].mUnk_06 = -0xc0;
    }
}

void func_ov001_0219c46c(void) {
    data_ov001_021a9bf4->mUnk_4c = 1;
    data_ov001_021a9bf4->mUnk_50 = 0;
}

void func_ov001_0219c458(void) {
    data_ov001_021a9bf4->mUnk_4c = 2;
    data_ov001_021a9bf4->mUnk_50 = 0;
}

void func_ov001_0219c428(void) {
    data_ov001_021a9bf4->mUnk_4c = 3;
    data_ov001_021a9bf4->mUnk_50 = 0;
    func_0212b7e8();
    func_0212ecc0(&data_0217d068, 0, 5);
}

void func_ov001_0219c3ec(void) {
    data_ov001_021a9bf4->mUnk_4c = 4;
    data_ov001_021a9bf4->mUnk_50 = 0;
    func_021277f8(func_020b3f7c(data_ov001_021a9bf4->mUnk_38, 4), func_020b3f7c(data_ov001_021a9bf4->mUnk_38, 2), 0);
}

void func_ov001_0219c3d8(void) {
    data_ov001_021a9bf4->mUnk_4c = 5;
    data_ov001_021a9bf4->mUnk_50 = 0;
}

void func_ov001_0219c3bc(void) {
    data_ov001_021a9bf4->mUnk_4c = 6;
    data_ov001_021a9bf4->mUnk_50 = 0;
    func_021277e4();
}

void func_ov001_0219c3a8(void) {
    data_ov001_021a9bf4->mUnk_4c = 7;
    data_ov001_021a9bf4->mUnk_50 = 0;
}

void func_ov001_0219c358(void) {
    data_ov001_021a9bf4->mUnk_34[10].mUnk_00 = 1;
    data_ov001_021a9bf4->mUnk_34[11].mUnk_00 = 0;
    data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b6c[0]].mUnk_00 = 1;
    data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b6c[1]].mUnk_00 = 0;
    data_ov001_021a9bf4->mUnk_34[10].mUnk_00 = 0;
    data_ov001_021a9bf4->mUnk_34[11].mUnk_00 = 1;
}

void func_ov001_0219c2a4(void) {
    s32 i;
    data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b38[0]].mUnk_04 = -func_020adc64(6 - data_ov001_021a9bf4->mUnk_54[0]);
    data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b38[1]].mUnk_04 = func_020adc64(6 - data_ov001_021a9bf4->mUnk_54[1]);
    for (i = 0; i < 2; i++) {
        if (data_ov001_021a9bf4->mUnk_54[i] > 0) {
            data_ov001_021a9bf4->mUnk_54[i]--;
            data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b3c[i]].mUnk_00 = 0;
            data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b38[i]].mUnk_00 = 1;
        } else {
            data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b3c[i]].mUnk_00 = 1;
            data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b38[i]].mUnk_00 = 0;
        }
    }
}

void func_ov001_0219c0bc(void) {
    Unk021a9bf4 *p = data_ov001_021a9bf4;
    Unk0201ea30 *q;
    u16 n;
    u16 a;
    u16 b;
    u16 x;
    u16 y;
    u8 *blk;
    s32 r;
    s32 k;
    u8 buf14[4];
    u16 buf18[16];

    q = p->mUnk_10;
    n = q->mUnk_06;
    func_0212426c(1, data_ov001_021a6b54[4], data_ov001_021a9bf4->mUnk_18,
                  func_020b3f7c(p->mUnk_3c, data_ov001_021a6b40[p->mUnk_60]), q, p->mUnk_34);
    if (data_ov001_021a9bf4->mUnk_60 == 0) {
        data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b6c[2]].mUnk_00 = 0;
        data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b6c[3]].mUnk_00 = 0;
        data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b6c[4]].mUnk_00 = 0;
        data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b6c[5]].mUnk_00 = 0;
        data_ov001_021a9bf4->mUnk_34[n + data_ov001_021a6b54[0]].mUnk_00 = 0;
        data_ov001_021a9bf4->mUnk_34[n + data_ov001_021a6b54[1]].mUnk_00 = 0;
        data_ov001_021a9bf4->mUnk_34[n + data_ov001_021a6b54[2]].mUnk_00 = 0;
        return;
    }
    data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b6c[2]].mUnk_00 = 1;
    data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b6c[3]].mUnk_00 = 1;
    a = data_ov001_021a6b6c[4];
    data_ov001_021a9bf4->mUnk_34[a].mUnk_00 = 1;
    b = data_ov001_021a6b6c[5];
    data_ov001_021a9bf4->mUnk_34[b].mUnk_00 = 1;
    data_ov001_021a9bf4->mUnk_34[n + data_ov001_021a6b54[0]].mUnk_00 = 1;
    y = data_ov001_021a6b54[1];
    data_ov001_021a9bf4->mUnk_34[n + y].mUnk_00 = 1;
    x = data_ov001_021a6b54[2];
    data_ov001_021a9bf4->mUnk_34[n + x].mUnk_00 = 1;
    r = data_ov001_021a6b88[func_0211e274(data_ov001_021a6b78[data_ov001_021a9bf4->mUnk_60])];
    func_02124748((u32) (r), (void *) (data_ov001_021a9bf4->mUnk_24), (void *) (data_ov001_021a9bf4->mUnk_20),
                  (void *) (data_ov001_021a9bf4->mUnk_2c), 1, (u32) (a), (void *) (data_ov001_021a9bf4->mUnk_0c),
                  (void *) (data_ov001_021a9bf4->mUnk_10));
    blk = data_ov001_021a9bf4->mUnk_28->mUnk_0c;
    func_02016468(
        0x1e, 0x100,
        blk +
            (func_02124a68((u32) (r), (void *) (data_ov001_021a9bf4->mUnk_24), (void *) (data_ov001_021a9bf4->mUnk_2c))
             << 5),
        0x20);
    k = func_0211e1f0(data_ov001_021a6b78[data_ov001_021a9bf4->mUnk_60]);
    func_021171a0(k, data_ov001_021a9bf4->mUnk_0c, data_ov001_021a9bf4->mUnk_10, b, 9, 1);
    func_0211e38c(data_ov001_021a6b78[data_ov001_021a9bf4->mUnk_60], buf14);
    func_02116b80(buf14, buf18);
    func_02124224(1, y, data_ov001_021a9bf4->mUnk_18, buf18, data_ov001_021a9bf4->mUnk_10, data_ov001_021a9bf4->mUnk_34,
                  9);
    func_0211e2f8(data_ov001_021a6b78[data_ov001_021a9bf4->mUnk_60], buf18);
    func_0212426c(1, x, data_ov001_021a9bf4->mUnk_18, buf18, data_ov001_021a9bf4->mUnk_10,
                  data_ov001_021a9bf4->mUnk_34);
}

void func_ov001_0219c058(void) {
    s32 ok = 1;
    data_ov001_021a9bf4->mUnk_60++;
    if (data_ov001_021a9bf4->mUnk_60 >= 4) {
        data_ov001_021a9bf4->mUnk_60 = 0;
    }
    if (func_0211e160(data_ov001_021a6b78[data_ov001_021a9bf4->mUnk_60]) == 0) {
        ok = 0;
        func_ov001_0219c058();
    }
    data_ov001_021a9bf4->mUnk_54[1] = 6;
    if (ok != 0) {
        func_0212ecc0(&data_0217d068, 0, 1);
        func_ov001_0219c0bc();
    }
}

void func_ov001_0219bff4(void) {
    s32 ok = 1;
    data_ov001_021a9bf4->mUnk_60--;
    if (data_ov001_021a9bf4->mUnk_60 < 0) {
        data_ov001_021a9bf4->mUnk_60 = 3;
    }
    if (func_0211e160(data_ov001_021a6b78[data_ov001_021a9bf4->mUnk_60]) == 0) {
        ok = 0;
        func_ov001_0219bff4();
    }
    data_ov001_021a9bf4->mUnk_54[0] = 6;
    if (ok != 0) {
        func_0212ecc0(&data_0217d068, 0, 1);
        func_ov001_0219c0bc();
    }
}

void func_ov001_0219bfc0(void) {
    func_0202949c(data_ov001_021a6b78[data_ov001_021a9bf4->mUnk_60]);
    func_0211e0c4(data_ov001_021a6b78[data_ov001_021a9bf4->mUnk_60]);
}

void func_ov001_0219be5c(void) {
    u16 n = data_ov001_021a9bf4->mUnk_04->mUnk_06;

    data_ov001_021a9bf4->mUnk_30[0].mUnk_00 = 1;
    data_ov001_021a9bf4->mUnk_30[2].mUnk_00 = 1;
    data_ov001_021a9bf4->mUnk_30[1].mUnk_00 = 1;
    data_ov001_021a9bf4->mUnk_30[4].mUnk_00 = 1;
    data_ov001_021a9bf4->mUnk_30[3].mUnk_00 = 1;
    data_ov001_021a9bf4->mUnk_30[5].mUnk_00 = 1;
    data_ov001_021a9bf4->mUnk_30[n].mUnk_00 = 1;
    data_ov001_021a9bf4->mUnk_30[n + 1].mUnk_00 = 1;
    data_ov001_021a9bf4->mUnk_30[n + 2].mUnk_00 = 1;
    data_ov001_021a9bf4->mUnk_30[n + 3].mUnk_00 = 1;
    data_ov001_021a9bf4->mUnk_30[n + 4].mUnk_00 = 1;
    data_ov001_021a9bf4->mUnk_30[n + 5].mUnk_00 = 1;
    func_0211de00(data_ov001_021a6ba4[func_0202968c()], data_ov001_021a9bf4->mUnk_00, data_ov001_021a9bf4->mUnk_04, 0,
                  0);
    func_0211ded0((u32) (data_ov001_021a6ba4[func_0202968c()]), (void *) data_ov001_021a9bf4->mUnk_00,
                  (void *) data_ov001_021a9bf4->mUnk_04, (u32) (5),
                  (u16) (func_02124a68((u32) (5), (void *) (data_ov001_021a9bf4->mUnk_00),
                                       (void *) (data_ov001_021a9bf4->mUnk_04))),
                  0);
    func_0212426c(0, 2, data_ov001_021a9bf4->mUnk_08, func_020b3f7c(data_ov001_021a9bf4->mUnk_38, 0x73),
                  data_ov001_021a9bf4->mUnk_04, data_ov001_021a9bf4->mUnk_30);
    func_0212426c(0, 4, data_ov001_021a9bf4->mUnk_08, func_020b3f7c(data_ov001_021a9bf4->mUnk_38, 0x74),
                  data_ov001_021a9bf4->mUnk_04, data_ov001_021a9bf4->mUnk_30);
    func_02124140(0, 0, data_ov001_021a9bf4->mUnk_08, data_ov001_021a9bf4->mUnk_30, data_ov001_021a9bf4->mUnk_04);
    func_02124140(1, 0, data_ov001_021a9bf4->mUnk_08, data_ov001_021a9bf4->mUnk_30, data_ov001_021a9bf4->mUnk_04);
    func_02124140(2, 0, data_ov001_021a9bf4->mUnk_08, data_ov001_021a9bf4->mUnk_30, data_ov001_021a9bf4->mUnk_04);
    func_02124140(4, 0, data_ov001_021a9bf4->mUnk_08, data_ov001_021a9bf4->mUnk_30, data_ov001_021a9bf4->mUnk_04);
}

void func_ov001_0219bb48(u32 param_1, u32 param_2, u32 param_3) {
    void *heap;
    s32 rem;
    s32 i;

    reg_G2S_DB_BG0CNT = reg_G2S_DB_BG0CNT & ~3;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 1;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x8300;
    heap = func_02036948((void *) param_1);
    data_ov001_021a9bf4 = func_02036bec(heap, 0x70);
    data_ov001_021a9bf4->mUnk_44 = heap;
    data_ov001_021a9bf4->mUnk_48 = 0;
    data_ov001_021a9bf4->mUnk_60 = 0;
    data_ov001_021a9bf4->mUnk_64 = param_2;
    data_ov001_021a9bf4->mUnk_68 = param_3;
    data_ov001_021a9bf4->mUnk_6c = 0;
    func_ov001_0219c544();
    func_02117224(data_ov001_021a9bf4->mUnk_44);
    func_02124ed0(data_ov001_021a9bf4->mUnk_44, data_ov001_021a9bf4->mUnk_04, data_ov001_021a9bf4->mUnk_08,
                  &data_ov001_021a9bf4->mUnk_30);
    func_02124ed0(data_ov001_021a9bf4->mUnk_44, data_ov001_021a9bf4->mUnk_10, data_ov001_021a9bf4->mUnk_18,
                  &data_ov001_021a9bf4->mUnk_34);
    data_ov001_021a9bf4->mUnk_38 = func_02047a28("common.bmg");
    data_ov001_021a9bf4->mUnk_3c = func_0204799c("menu.bmg");
    rem = 0x8000;
    rem -= func_021243ac(data_ov001_021a9bf4->mUnk_44, 0, data_ov001_021a9bf4->mUnk_08, 0xb4, 0xd, 0,
                         data_ov001_021a9bf4->mUnk_00, data_ov001_021a9bf4->mUnk_04, data_ov001_021a9bf4->mUnk_30, rem);
    rem -= func_021243ac(data_ov001_021a9bf4->mUnk_44, 1, data_ov001_021a9bf4->mUnk_08, 0xb4, 0xd, 1,
                         data_ov001_021a9bf4->mUnk_00, data_ov001_021a9bf4->mUnk_04, data_ov001_021a9bf4->mUnk_30, rem);
    rem -= func_021243ac(data_ov001_021a9bf4->mUnk_44, 2, data_ov001_021a9bf4->mUnk_08, 0x96, 0xd, 2,
                         data_ov001_021a9bf4->mUnk_00, data_ov001_021a9bf4->mUnk_04, data_ov001_021a9bf4->mUnk_30, rem);
    rem -= func_021243ac(data_ov001_021a9bf4->mUnk_44, 3, data_ov001_021a9bf4->mUnk_08, 0x50, 0xd, 3,
                         data_ov001_021a9bf4->mUnk_00, data_ov001_021a9bf4->mUnk_04, data_ov001_021a9bf4->mUnk_30, rem);
    rem -= func_021243ac(data_ov001_021a9bf4->mUnk_44, 4, data_ov001_021a9bf4->mUnk_08, 0x96, 0xd, 4,
                         data_ov001_021a9bf4->mUnk_00, data_ov001_021a9bf4->mUnk_04, data_ov001_021a9bf4->mUnk_30, rem);
    func_021243ac(data_ov001_021a9bf4->mUnk_44, 5, data_ov001_021a9bf4->mUnk_08, 0x50, 0xd, 5,
                  data_ov001_021a9bf4->mUnk_00, data_ov001_021a9bf4->mUnk_04, data_ov001_021a9bf4->mUnk_30, rem);
    rem = func_02148ca0();
    for (i = 0; i < 5; i++) {
        rem -= func_021243ac(data_ov001_021a9bf4->mUnk_44, data_ov001_021a6b54[i], data_ov001_021a9bf4->mUnk_18,
                             data_ov001_021a6b48[i], data_ov001_021a6b60[i], i, data_ov001_021a9bf4->mUnk_0c,
                             data_ov001_021a9bf4->mUnk_10, data_ov001_021a9bf4->mUnk_34, rem);
    }
    func_021243ac(data_ov001_021a9bf4->mUnk_44, 5, data_ov001_021a9bf4->mUnk_18, 0x32, 0xd, 0xb,
                  data_ov001_021a9bf4->mUnk_0c, data_ov001_021a9bf4->mUnk_10, data_ov001_021a9bf4->mUnk_34, rem);
    func_0212426c(1, data_ov001_021a6b54[0], data_ov001_021a9bf4->mUnk_18,
                  func_020b3f7c(data_ov001_021a9bf4->mUnk_3c, 8), data_ov001_021a9bf4->mUnk_10,
                  data_ov001_021a9bf4->mUnk_34);
    func_0212426c(1, data_ov001_021a6b54[3], data_ov001_021a9bf4->mUnk_18,
                  func_020b3f7c(data_ov001_021a9bf4->mUnk_3c, 9), data_ov001_021a9bf4->mUnk_10,
                  data_ov001_021a9bf4->mUnk_34);
    func_0212426c(1, data_ov001_021a6b54[4], data_ov001_021a9bf4->mUnk_18,
                  func_020b3f7c(data_ov001_021a9bf4->mUnk_3c, data_ov001_021a6b40[0]), data_ov001_021a9bf4->mUnk_10,
                  data_ov001_021a9bf4->mUnk_34);
    func_0212426c(1, 5, data_ov001_021a9bf4->mUnk_18, func_020b3f7c(data_ov001_021a9bf4->mUnk_38, 4),
                  data_ov001_021a9bf4->mUnk_10, data_ov001_021a9bf4->mUnk_34);
    func_0211de40(data_ov001_021a9bf4->mUnk_44);
    func_0211df44(data_ov001_021a9bf4->mUnk_44);
    func_0212b928(data_ov001_021a9bf4->mUnk_44, data_ov001_021a9bf4->mUnk_1c, 4);
    func_0212b7fc();
    func_ov001_0219be5c();
    func_ov001_0219c480();
    for (i = 3; i >= 0; i--) {
        if (func_0211e160(data_ov001_021a6b78[i]) != 0) {
            data_ov001_021a9bf4->mUnk_60 = i;
            break;
        }
    }
    func_ov001_0219c0bc();
    func_02036820((void *) (data_ov001_021a9bf4->mUnk_44));
}

void func_ov001_0219baf4(void) {
    if (data_ov001_021a9bf4->mUnk_6c == 1) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | 0x1800;
    }
    func_0212b91c();
    func_0211de34();
    func_0211df38();
    func_02117218();
    func_02036ab0(data_ov001_021a9bf4->mUnk_44);
    data_ov001_021a9bf4 = 0;
}

void func_ov001_0219ba3c(void) {
    u16 n;
    s16 v;
    s32 i;

    func_ov001_0219c2a4();
    n = data_ov001_021a9bf4->mUnk_10->mUnk_06;
    data_ov001_021a9bf4->mUnk_50++;
    v = func_020ae4c0(1, ~0xbf, 0, data_ov001_021a9bf4->mUnk_50, 10);
    data_ov001_021a9bf4->mUnk_5c = v;
    for (i = 0; i < 6; i++) {
        data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b6c[i]].mUnk_06 = v;
    }
    for (i = 0; i < 5; i++) {
        data_ov001_021a9bf4->mUnk_34[n + data_ov001_021a6b54[i]].mUnk_06 = v;
    }
    for (i = 0; i < 2; i++) {
        data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b3c[i]].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b38[i]].mUnk_06 = v;
    }
    if (data_ov001_021a9bf4->mUnk_50 >= 10) {
        func_ov001_0219c46c();
    }
}

void func_ov001_0219b9dc(void) {
    u16 n;
    s16 w;

    func_ov001_0219c2a4();
    n = data_ov001_021a9bf4->mUnk_10->mUnk_06;
    data_ov001_021a9bf4->mUnk_50++;
    w = -func_0212825c(data_ov001_021a9bf4->mUnk_50);
    data_ov001_021a9bf4->mUnk_34[10].mUnk_06 = w;
    data_ov001_021a9bf4->mUnk_34[11].mUnk_06 = w;
    data_ov001_021a9bf4->mUnk_34[n + 5].mUnk_06 = w;
    if (data_ov001_021a9bf4->mUnk_50 >= 10) {
        func_ov001_0219c458();
    }
}

void func_ov001_0219b874(void) {
    s32 r;
    s32 b;
    s32 a;
    s32 d;
    s32 c;
    Unk02175628Index idx;

    r = -1;
    func_ov001_0219c2a4();
    idx = UNK_02175628_INDEX_8;
    b = 0;
    a = 0;
    if (data_02175628[idx].mUnk_4c == 0 && data_02175628[idx].mUnk_58 < 5) {
        a = 1;
    }
    if (a == 0 && data_02175628[idx].mUnk_54 == 0 && data_02175628[idx].mUnk_4c != 0) {
        b = 1;
    }
    if (b != 0) {
        r = func_0201ea84(data_ov001_021a9bf4->mUnk_14, data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a);
    }
    if ((u16) (data_02175628[idx].mUnk_00 & 2) == 0) {
        d = 0;
        c = 0;
        if (data_02175628[idx].mUnk_4c == 0 && data_02175628[idx].mUnk_58 < 5) {
            c = 1;
        }
        if (c == 0 && data_02175628[idx].mUnk_54 == 0 && data_02175628[idx].mUnk_4c != 0) {
            d = 1;
        }
        if (d == 0 || func_02128210(data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a) == 0) {
            goto next;
        }
    }
    func_021281c8(14);
    func_ov001_0219c3a8();
    data_ov001_021a9bf4->mUnk_6c = 2;
    func_02128310(0);
    return;
next:
    if (r == 0) {
        func_ov001_0219bff4();
        return;
    }
    if (r == 1) {
        func_ov001_0219c058();
        return;
    }
    if (r == 3) {
        func_ov001_0219c428();
        return;
    }
    if (r == 2) {
        func_ov001_0219c058();
        return;
    }
    if ((u16) (data_02175628[idx].mUnk_00 & 1) != 0) {
        func_ov001_0219c428();
        return;
    }
    if (func_020ae408(8, 0x20) != 0) {
        func_ov001_0219bff4();
        return;
    }
    if (func_020ae408(8, 0x10) != 0) {
        func_ov001_0219c058();
    }
}

void func_ov001_0219b84c(void) {
    func_ov001_0219c2a4();
    data_ov001_021a9bf4->mUnk_50++;
    if (data_ov001_021a9bf4->mUnk_50 >= 10) {
        func_ov001_0219c3ec();
    }
}

void func_ov001_0219b834(void) {
    if (func_021277c8() != 0) {
        func_ov001_0219c3d8();
    }
}

void func_ov001_0219b81c(void) {
    int v1;
    v1 = func_02127788();
    if (v1 != 0) {
        func_ov001_0219c3bc();
    }
    return;
}

void func_ov001_0219b7c8(void) {
    s32 r;

    if (func_021277ac() == 0) {
        return;
    }
    r = func_02127794();
    switch (r) {
        case 0:
            func_ov001_0219bfc0();
            data_ov001_021a9bf4->mUnk_6c = 1;
            func_ov001_0219c3a8();
            func_021282c8();
            break;
        case -1:
        case 1:
            func_0212b7d8();
            func_ov001_0219c458();
            break;
    }
}

void func_ov001_0219b64c(void) {
    s32 flag;
    s16 v;
    s16 w;
    u16 n;
    s32 i;

    flag = data_ov001_021a9bf4->mUnk_6c == 1;
    data_ov001_021a9bf4->mUnk_50++;
    v = func_020ae4c0(1, 0, ~0xbf, data_ov001_021a9bf4->mUnk_50, 10);
    if (flag) {
        n = data_ov001_021a9bf4->mUnk_04->mUnk_06;
        data_ov001_021a9bf4->mUnk_58 = v;
        data_ov001_021a9bf4->mUnk_30[0].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_30[2].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_30[1].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_30[4].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_30[3].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_30[5].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_30[n].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_30[n + 1].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_30[n + 2].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_30[n + 3].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_30[n + 4].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_30[n + 5].mUnk_06 = v;
    }
    n = data_ov001_021a9bf4->mUnk_10->mUnk_06;
    w = -func_02128244(data_ov001_021a9bf4->mUnk_50);
    data_ov001_021a9bf4->mUnk_5c = v;
    for (i = 0; i < 6; i++) {
        data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b6c[i]].mUnk_06 = v;
    }
    data_ov001_021a9bf4->mUnk_34[10].mUnk_06 = w;
    data_ov001_021a9bf4->mUnk_34[11].mUnk_06 = w;
    for (i = 0; i < 5; i++) {
        data_ov001_021a9bf4->mUnk_34[n + data_ov001_021a6b54[i]].mUnk_06 = v;
    }
    for (i = 0; i < 2; i++) {
        data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b3c[i]].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b38[i]].mUnk_06 = v;
    }
    data_ov001_021a9bf4->mUnk_34[n + 5].mUnk_06 = w;
}

int func_ov001_0219b574(void) {
    data_ov001_021a9bf4->mUnk_48 = data_ov001_021a9bf4->mUnk_4c;
    switch (data_ov001_021a9bf4->mUnk_48) {
        case 0:
            func_ov001_0219ba3c();
            break;
        case 1:
            func_ov001_0219b9dc();
            break;
        case 2:
            func_ov001_0219b874();
            break;
        case 3:
            func_ov001_0219b84c();
            break;
        case 4:
            func_ov001_0219b834();
            break;
        case 5:
            func_ov001_0219b81c();
            break;
        case 6:
            func_ov001_0219b7c8();
            break;
        case 7:
            func_ov001_0219b64c();
            break;
    }
    func_0212b80c();
    func_ov001_0219c358();
    func_02124c30(data_ov001_021a9bf4->mUnk_04, data_ov001_021a9bf4->mUnk_00, data_ov001_021a9bf4->mUnk_08,
                  (void *) data_ov001_021a9bf4->mUnk_64, data_ov001_021a9bf4->mUnk_30);
    func_02124c30(data_ov001_021a9bf4->mUnk_10, data_ov001_021a9bf4->mUnk_0c, data_ov001_021a9bf4->mUnk_18,
                  (void *) data_ov001_021a9bf4->mUnk_68, data_ov001_021a9bf4->mUnk_34);
    if (data_ov001_021a9bf4->mUnk_48 == 7) {
        switch (data_ov001_021a9bf4->mUnk_6c) {
            case 1:
                if (data_ov001_021a9bf4->mUnk_50 >= 10) {
                    if (func_02128274() != 0) {
                        return 1;
                    }
                }
                break;
            case 2:
                if (data_ov001_021a9bf4->mUnk_50 >= 10) {
                    return 2;
                }
                break;
        }
    }
    return 0;
}

void func_ov001_0219b540(void) {
    *(u32 *) 0x4000010 = (-data_ov001_021a9bf4->mUnk_58 << 16) & 0x1ff0000;
    *(u32 *) 0x400101c = (-data_ov001_021a9bf4->mUnk_5c << 16) & 0x1ff0000;
}
