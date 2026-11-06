#include "Main/Unknown/code_0202dd9c.h"

#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/code_021171a0.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_0202e274.h"
#include "Main/Unknown/code_0202e43c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_02061428.h"
#include "Main/Unknown/code_0206152c.h"
#include "Main/Unknown/code_02061540.h"
#include "Main/Unknown/code_02061644.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_02117218.h"
#include "Main/Unknown/code_021172a8.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125da0.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_02125f2c.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/unk_02153bec.h"
#include "Main/Unknown/unk_02162c74.h"
#include "code_0214d018.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02025cd0.h"
#include "registers.h"

#pragma thumb on

void func_0202dfd4(void *a) {
    Unk02125de0 v;
    u8 *q;
    s32 i;
    u32 e;
    u8 *p;
    s32 n;
    data_02174e44 = HeapAlloc(a, 0x8dc);
    MemFillWordsByBlock_inline(data_02174e44, 0x8dc);
    data_02174e44->mUnk_8d0 = HeapAllocAligned(a, 0xe00, 0x20);
    data_02174e44->mUnk_8d4 = HeapAllocAligned(a, 0x1000, 0x20);
    q = CreateDisplaySettings(a, data_usa_02154840);
    SetBg0Record(q + 0x28, 1, 0, 0, 0, 0, 1, 0);
    SetBg3RecordParams(q + 0x70, 2, 0, 0, 0, 0xf, 0);
    InitDisplayFromSettings(q);
    func_0202e274();
    v.mUnk_00 = 1;
    v.mUnk_04 = func_020b403c(1);
    v.mUnk_08 = 1;
    v.mUnk_0c = 1;
    v.mUnk_10 = 0;
    v.mUnk_14 = 0;
    v.mUnk_18 = NULL;
    v.mUnk_1c = 1;
    v.mUnk_20 = 1;
    v.mUnk_24 = 0;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    func_02125de0(a, &v);
    SetTxtSystemMode(1);
    func_0212abdc(a, data_02174e44);
    CreateKartIcon(a);
    for (i = 0; i < 0x20; i++) {
        data_02174e44->mUnk_814[i] = -1;
    }
    for (i = 0; i < 10; i++) {
        data_02174e44->mUnk_894[i] = -1;
    }
    data_02174e44->mUnk_8bc = (u8 *) func_02061644((u32) a);
    func_02061540(data_02174e44->mUnk_8bc);
    func_02057d9c();
    for (i = 0; i < 0x20; i++) {
        e = func_0202e43c(i);
        p = data_02174e44->mUnk_8bc;
        n = func_0204684c(e);
        if (func_0206174c(p + n * 0x30) != FALSE) {
            data_02174e44->mUnk_814[data_02174e44->mUnk_80c] = i;
            data_02174e44->mUnk_808++;
            data_02174e44->mUnk_80c++;
        }
    }
    data_02174e44->mUnk_8c0 = (u8 *) func_0206152c((u32) a);
    func_02061428(data_02174e44->mUnk_8c0);
    func_02057d9c();
    for (i = 0; i < 10; i++) {
        if (func_0206174c(data_02174e44->mUnk_8c0 + (u8) i * 0x230) != FALSE) {
            data_02174e44->mUnk_894[data_02174e44->mUnk_810] = i;
            data_02174e44->mUnk_808++;
            data_02174e44->mUnk_810++;
        }
    }
    func_020ae6d4(data_02174e44, data_02174e44->mUnk_404);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | 0x10;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | 0x10;
    switch (data_0217b488->mUnk_0c) {
        case 0:
            data_02174e44->mUnk_8c8 = 0;
            break;
        case 1:
            data_02174e44->mUnk_8c8 = 1;
            break;
    }
    data_02174e44->mUnk_8cc = data_02174e44->mUnk_8c8;
    data_02174e44->mUnk_8c4 = data_usa_02162f4c[data_02174e44->mUnk_8c8];
    data_02174e44->mUnk_8d8 = CreateExpHeapFromMaxFree(a);
    data_02174e44->mUnk_8c4->mUnk_00(data_02174e44->mUnk_8d8, data_02174e44, data_02174e44->mUnk_404);
}

void func_0202df34(s32 a) {
    s32 b;
    s32 c;
    s32 r;
    Unk02162f4c *p;
    b = data_02174e44->mUnk_8c8;
    c = data_02174e44->mUnk_8cc;
    if (c != b) {
        p = data_02174e44->mUnk_8c4;
        data_02174e44->mUnk_8c4 = data_usa_02162f4c[b];
        data_02174e44->mUnk_8cc = data_02174e44->mUnk_8c8;
        p->mUnk_08();
        data_02174e44->mUnk_8c4->mUnk_00(data_02174e44->mUnk_8d8, data_02174e44, data_02174e44->mUnk_404);
    } else {
        func_020ae6ac(data_02174e44, data_02174e44->mUnk_404);
        r = data_02174e44->mUnk_8c4->mUnk_04(a);
        if (r != -1) {
            data_02174e44->mUnk_8c8 = r;
        }
        func_020ae630(data_02174e44, data_02174e44->mUnk_404);
    }
    func_02125928();
    func_0212a920();
}

void func_0202defc(void) {
    reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
    func_02125da0();
    func_0212abd0();
    func_02117218();
    func_0204f7f4();
}

void func_0202dec8(void) {
    func_021258f0();
    data_02174e44->mUnk_8c4->mUnk_0c();
    func_020ae5f0(data_02174e44, data_02174e44->mUnk_404);
}

#pragma thumb off

#pragma thumb on

void func_0202de00(Unk02174e14 *a, s16 (*b)[4], void *c, s32 d, s32 e, s32 f, Unk0202de00_g *g) {
    u16 s[10];
    u16 t[11];
    Unk02174e14_00 *h;
    h = &a->mUnk_038;
    func_0212426c(0, b[0][0], a->mUnk_000.mUnk_14, GetBmgEntry(a->mUnk_058, func_02025d8c(f)), a->mUnk_000.mUnk_0c,
                  a->mUnk_000.mUnk_18);
    func_02025cd0((s16 *) s, g->mUnk_02, g->mUnk_03, g->mUnk_00);
    func_02124224(0, b[1][0], a->mUnk_000.mUnk_14, s, a->mUnk_000.mUnk_0c, a->mUnk_000.mUnk_18, 7);
    MIi_CpuCopy16(c, t, 0x14);
    t[10] = 0;
    func_0212426c(0, b[2][0], a->mUnk_000.mUnk_14, t, a->mUnk_000.mUnk_0c, a->mUnk_000.mUnk_18);
    func_0212463c(d, h->mUnk_08, a->mUnk_038.mUnk_00, h->mUnk_04, h->mUnk_0c, 0, b[0][3], a->mUnk_000.mUnk_08,
                  a->mUnk_000.mUnk_0c);
    QueueKartIcon(e, a->mUnk_000.mUnk_08, a->mUnk_000.mUnk_0c, b[1][3],
                  func_02124a68(b[1][3], a->mUnk_000.mUnk_08, a->mUnk_000.mUnk_0c), 0);
}

#pragma thumb off

#pragma thumb on

void *func_0202ddec(void) {
    return data_02174e44->mUnk_8d0;
}

u32 func_0202ddd8(void) {
    return ((u32) data_02174e44->mUnk_8d4);
}

u32 func_0202ddc4(void) {
    return (data_02174e44->mUnk_808);
}

u32 func_0202ddb0(void) {
    return (data_02174e44->mUnk_80c);
}

u32 func_0202dd9c(void) {
    return (data_02174e44->mUnk_810);
}

#pragma thumb off
