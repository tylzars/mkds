#include "Main/Unknown/code_02077bc0.h"

#include "Main/Unknown/code_02036820.h"
#include "code_020169a4.h"
#include "code_02016d34.h"
#include "code_020170e4.h"
#include "code_020172d0.h"
#include "Main/Unknown/code_020483e4.h"
#include "code_020176c0.h"
#include "code_02012b30.h"
#include "code_0214a5e0.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_0207851c.h"
#include "code_02013740.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/code_02078ee0.h"
#include "Main/Unknown/code_020790e0.h"
#include "Main/Unknown/code_02088338.h"
#include "Main/Unknown/code_0207adf8.h"
#include "Main/Unknown/code_02017000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_021488e8.h"

#pragma thumb on

void func_02077f48(u32 p0) {
    *(u32 *) ((u8 *) (u32) (((u32) data_0217ad08)) + 0 + (0x1d8u)) = p0;
}

void func_02077f0c(u16 *a, int b, u32 c) {
    u16 v1;
    int v2;
    int v3;
    v1 = *a;
    v3 = b - (u32) v1;
    if (v3 < 0) {
        v3 = 0xffff - v3;
    }
    v2 = MulFixed12(v3, c);
    *a = *a + v2;
    if (((*a + 100) - b) < 0) {
        *a = (u16) (*a + 100);
        return;
    }
    *a = v1;
}

#pragma thumb off

#pragma thumb on

Nclr *func_02077f00(void) {
    return data_usa_0217ace4;
}

#pragma thumb off

#pragma thumb on

void func_02077eb4(void *a, u32 *b) {
    u32 v1;
    u32 v2;
    v1 = ((u32) HeapAlloc(a, (u32) (((u32) 0x0000f000u))));
    v2 = (u32) ExpHeapCreate((void *) ((void *) v1), (u32) ((u32) (((u32) 0x0000f000u))), (u32) 0);
    b[1] = v2;
    *b = v1;
    b[4] = 0;
    b[3] = b[4];
    b[2] = b[3];
    b[7] = 0;
    b[6] = b[7];
    b[5] = b[6];
    b[10] = 0;
    b[9] = b[10];
    b[8] = b[9];
    b[0xb] = 0;
    *(u16 *) (b + 0xc) = 0;
}

#pragma thumb off

#pragma thumb on

void LoadKartAndCharacterFiles(void) {
    Unk0217ad08_1f4 *a;
    s32 b;
    Unk0217ad08_1f4 *p;
    s32 c;
    s32 i;
    char *e;

    a = data_0217ad08->mUnk_1f4;
    i = data_0217ad08->mUnk_266;
    p = &a[i];
    b = data_0217ad08->mUnk_020->mUnk_00;
    c = data_0217ad08->mUnk_020->mUnk_04;
    p->mUnk_30 = 0;
    ExpHeapDestroy(&p->mUnk_04->mUnk_00);
    p->mUnk_04 = ExpHeapCreate(p->mUnk_00, 0xf000, 0);
    if (b != -1 && p->mUnk_08 != NULL) {
        func_02012b30(p->mUnk_08);
        func_02012b30(p->mUnk_0c);
        func_02012b30(p->mUnk_10);
        func_02012b30(p->mUnk_18);
        func_02012b30(p->mUnk_1c);
        func_02012b30(p->mUnk_20);
        func_02012b30(p->mUnk_24);
        func_02012b30(p->mUnk_28);
    }
    e = (char *) &data_0217ad08->mUnk_1c8[c];
    func_02048590(BuildCharacterNsbmdPath(b, 1), (u32) p->mUnk_04, (void **) &p->mUnk_08);
    func_02048590(BuildCharacterNsbtxPath(b, 1), (u32) p->mUnk_04, (void **) &p->mUnk_0c);
    func_02048590(BuildCharacterNsbcaPath(b, 2), (u32) p->mUnk_04, (void **) &p->mUnk_14);
    func_02048590(BuildEmblemNsbtxPath(b), (u32) p->mUnk_04, (void **) &p->mUnk_10);
    func_02048590(BuildKartNsbmdPath(c), (u32) p->mUnk_04, (void **) &p->mUnk_18);
    func_02048590(BuildKartNsbtxPath(c), (u32) p->mUnk_04, (void **) &p->mUnk_1c);
    func_02048590(BuildKartShadowNsbmdPath(c), (u32) p->mUnk_04, (void **) &p->mUnk_28);
    func_02048590(BuildTireNsbmdPath(c, e), (u32) p->mUnk_04, (void **) &p->mUnk_20);
    func_02048590(BuildTireNsbtxPath(c, e), (u32) p->mUnk_04, (void **) &p->mUnk_24);
}

void func_02077c1c(void) {
    Unk0217ad08_1f4 *p;
    Unk0217ad08_058 *q;
    Unk0217ad08_058 *e;
    Unk0217ad08_058_08 *r;

    G2Bg0OfsWrite(data_0217ad08->mUnk_024.mUnk_2c);
    if (data_0217aa0c->mUnk_f8 == 0) {
        p = &data_0217ad08->mUnk_1f4[data_0217ad08->mUnk_266];
        if (p->mUnk_2c != 0) {
            q = data_0217ad08->mUnk_020;
            if (p->mUnk_30 == 0) {
                func_02079078(p->mUnk_04, q->mUnk_10, q->mUnk_08, p->mUnk_08, p->mUnk_0c, p->mUnk_14);
                p->mUnk_30++;
                return;
            }
            if (p->mUnk_30 == 1) {
                func_02078f78(p->mUnk_10);
                data_0217ad08->mUnk_020->mUnk_b4 = data_0217ad08->mUnk_1d4;
                func_02079008(q->mUnk_1c, p->mUnk_28);
                func_02079014(q->mUnk_18, p->mUnk_20, p->mUnk_24);
                p->mUnk_30++;
                return;
            }
            func_02079038(q->mUnk_14, p->mUnk_18, p->mUnk_1c);
            func_0207851c(data_0217ad08->mUnk_020);
            func_0207940c(q->mUnk_14, q->mUnk_04, data_0217ad08->mUnk_1d0);
            func_020792c8((struct Unk0206bcb0_590 *) q, 1);
            p->mUnk_2c = 0;
            p->mUnk_30 = 0;
            if (data_0217ad08->mUnk_264 >= 0) {
                e = &data_0217ad08->mUnk_058[data_0217ad08->mUnk_264];
                if (q->mUnk_00 == e->mUnk_00) {
                    r = q->mUnk_08;
                    r->mUnk_0c = e->mUnk_08->mUnk_0c;
                    *r->mUnk_1c[r->mUnk_1a] = r->mUnk_0c;
                }
            }
            data_0217ad08->mUnk_264 = data_0217ad08->mUnk_266;
            data_0217ad08->mUnk_266 = data_0217ad08->mUnk_266 == 0 ? 1 : 0;
            data_0217ad08->mUnk_020 = &data_0217ad08->mUnk_058[data_0217ad08->mUnk_266];
        }
    }
}

#pragma thumb off

#pragma thumb on

void func_02077bc0(void *a) {
    u32 v1;
    u32 v2;
    RangeEntry *v3;
    u32 v4;
    v1 = func_020170dc(0x20);
    v2 = func_020172d0(0x20);
    v3 = HeapAlloc(a, v1);
    v4 = ((u32) HeapAlloc(a, v2));
    func_02017070((u32) 0x00040000u, (u32) 0x00020000u, v3, v1, 1);
    func_02017274((u32) 0x00010000u, v4, v2, 1);
}

#pragma thumb off
