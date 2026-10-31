#include "01/code_0219bb48.h"
#include "01/code_0219c000.h"
#include "Main/Unknown/code_02116000.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_0211d000.h"
#include "Main/Unknown/code_0211e000.h"
#include "Main/Unknown/code_0212b000.h"
#include "Main/Unknown/code_02148ca0.h"
#include "registers.h"

void func_ov001_0219c3ec(void) {
    data_ov001_021a9bf4->mUnk_4c = 4;
    data_ov001_021a9bf4->mUnk_50 = 0;
    func_021277f8((void *) ((u32)func_020b3f7c(data_ov001_021a9bf4->mUnk_38, 4)), (void *) ((u32)func_020b3f7c(data_ov001_021a9bf4->mUnk_38, 2)), 0);
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
    func_0212426c(1, data_ov001_021a6b54[4], data_ov001_021a9bf4->mUnk_18, func_020b3f7c(p->mUnk_3c, data_ov001_021a6b40[p->mUnk_60]), q,
                  p->mUnk_34);
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
    func_02124748((u32) (r), (void *) (data_ov001_021a9bf4->mUnk_24), (void *) (data_ov001_021a9bf4->mUnk_20), (void *) (data_ov001_021a9bf4->mUnk_2c), 1, (u32) (a), (void *) (data_ov001_021a9bf4->mUnk_0c), (void *) (data_ov001_021a9bf4->mUnk_10));
    blk = data_ov001_021a9bf4->mUnk_28->mUnk_0c;
    func_02016468(0x1e, 0x100, blk + (func_02124a68((u32) (r), (void *) (data_ov001_021a9bf4->mUnk_24), (void *) (data_ov001_021a9bf4->mUnk_2c)) << 5), 0x20);
    k = func_0211e1f0(data_ov001_021a6b78[data_ov001_021a9bf4->mUnk_60]);
    func_021171a0(k, data_ov001_021a9bf4->mUnk_0c, data_ov001_021a9bf4->mUnk_10, b, 9, 1);
    func_0211e38c(data_ov001_021a6b78[data_ov001_021a9bf4->mUnk_60], buf14);
    func_02116b80(buf14, buf18);
    func_02124224(1, y, data_ov001_021a9bf4->mUnk_18, buf18, data_ov001_021a9bf4->mUnk_10, data_ov001_021a9bf4->mUnk_34, 9);
    func_0211e2f8(data_ov001_021a6b78[data_ov001_021a9bf4->mUnk_60], buf18);
    func_0212426c(1, x, data_ov001_021a9bf4->mUnk_18, buf18, data_ov001_021a9bf4->mUnk_10, data_ov001_021a9bf4->mUnk_34);
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
    func_0211de00(data_ov001_021a6ba4[func_0202968c()], data_ov001_021a9bf4->mUnk_00, data_ov001_021a9bf4->mUnk_04, 0, 0);
    func_0211ded0((u32) (data_ov001_021a6ba4[func_0202968c()]), (void *) data_ov001_021a9bf4->mUnk_00, (void *) data_ov001_021a9bf4->mUnk_04, (u32) (5), (u16) (func_02124a68((u32) (5), (void *) (data_ov001_021a9bf4->mUnk_00), (void *) (data_ov001_021a9bf4->mUnk_04))), 0);
    func_0212426c(0, 2, data_ov001_021a9bf4->mUnk_08, func_020b3f7c(data_ov001_021a9bf4->mUnk_38, 0x73), data_ov001_021a9bf4->mUnk_04, data_ov001_021a9bf4->mUnk_30);
    func_0212426c(0, 4, data_ov001_021a9bf4->mUnk_08, func_020b3f7c(data_ov001_021a9bf4->mUnk_38, 0x74), data_ov001_021a9bf4->mUnk_04, data_ov001_021a9bf4->mUnk_30);
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
    func_02124ed0(data_ov001_021a9bf4->mUnk_44, data_ov001_021a9bf4->mUnk_04, data_ov001_021a9bf4->mUnk_08, &data_ov001_021a9bf4->mUnk_30);
    func_02124ed0(data_ov001_021a9bf4->mUnk_44, data_ov001_021a9bf4->mUnk_10, data_ov001_021a9bf4->mUnk_18, &data_ov001_021a9bf4->mUnk_34);
    data_ov001_021a9bf4->mUnk_38 = func_02047a28("common.bmg");
    data_ov001_021a9bf4->mUnk_3c = func_0204799c("menu.bmg");
    rem = 0x8000;
    rem -= func_021243ac(data_ov001_021a9bf4->mUnk_44, 0, data_ov001_021a9bf4->mUnk_08, 0xb4, 0xd, 0, data_ov001_021a9bf4->mUnk_00, data_ov001_021a9bf4->mUnk_04, data_ov001_021a9bf4->mUnk_30, rem);
    rem -= func_021243ac(data_ov001_021a9bf4->mUnk_44, 1, data_ov001_021a9bf4->mUnk_08, 0xb4, 0xd, 1, data_ov001_021a9bf4->mUnk_00, data_ov001_021a9bf4->mUnk_04, data_ov001_021a9bf4->mUnk_30, rem);
    rem -= func_021243ac(data_ov001_021a9bf4->mUnk_44, 2, data_ov001_021a9bf4->mUnk_08, 0x96, 0xd, 2, data_ov001_021a9bf4->mUnk_00, data_ov001_021a9bf4->mUnk_04, data_ov001_021a9bf4->mUnk_30, rem);
    rem -= func_021243ac(data_ov001_021a9bf4->mUnk_44, 3, data_ov001_021a9bf4->mUnk_08, 0x50, 0xd, 3, data_ov001_021a9bf4->mUnk_00, data_ov001_021a9bf4->mUnk_04, data_ov001_021a9bf4->mUnk_30, rem);
    rem -= func_021243ac(data_ov001_021a9bf4->mUnk_44, 4, data_ov001_021a9bf4->mUnk_08, 0x96, 0xd, 4, data_ov001_021a9bf4->mUnk_00, data_ov001_021a9bf4->mUnk_04, data_ov001_021a9bf4->mUnk_30, rem);
    func_021243ac(data_ov001_021a9bf4->mUnk_44, 5, data_ov001_021a9bf4->mUnk_08, 0x50, 0xd, 5, data_ov001_021a9bf4->mUnk_00, data_ov001_021a9bf4->mUnk_04, data_ov001_021a9bf4->mUnk_30, rem);
    rem = func_02148ca0();
    for (i = 0; i < 5; i++) {
        rem -= func_021243ac(data_ov001_021a9bf4->mUnk_44, data_ov001_021a6b54[i], data_ov001_021a9bf4->mUnk_18, data_ov001_021a6b48[i], data_ov001_021a6b60[i], i,
                             data_ov001_021a9bf4->mUnk_0c, data_ov001_021a9bf4->mUnk_10, data_ov001_021a9bf4->mUnk_34, rem);
    }
    func_021243ac(data_ov001_021a9bf4->mUnk_44, 5, data_ov001_021a9bf4->mUnk_18, 0x32, 0xd, 0xb, data_ov001_021a9bf4->mUnk_0c, data_ov001_021a9bf4->mUnk_10, data_ov001_021a9bf4->mUnk_34, rem);
    func_0212426c(1, data_ov001_021a6b54[0], data_ov001_021a9bf4->mUnk_18, func_020b3f7c(data_ov001_021a9bf4->mUnk_3c, 8), data_ov001_021a9bf4->mUnk_10, data_ov001_021a9bf4->mUnk_34);
    func_0212426c(1, data_ov001_021a6b54[3], data_ov001_021a9bf4->mUnk_18, func_020b3f7c(data_ov001_021a9bf4->mUnk_3c, 9), data_ov001_021a9bf4->mUnk_10, data_ov001_021a9bf4->mUnk_34);
    func_0212426c(1, data_ov001_021a6b54[4], data_ov001_021a9bf4->mUnk_18, func_020b3f7c(data_ov001_021a9bf4->mUnk_3c, data_ov001_021a6b40[0]), data_ov001_021a9bf4->mUnk_10, data_ov001_021a9bf4->mUnk_34);
    func_0212426c(1, 5, data_ov001_021a9bf4->mUnk_18, func_020b3f7c(data_ov001_021a9bf4->mUnk_38, 4), data_ov001_021a9bf4->mUnk_10, data_ov001_021a9bf4->mUnk_34);
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
