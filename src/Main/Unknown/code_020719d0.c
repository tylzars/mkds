#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_020719d0.h"
#include "Main/Unknown/code_02024974.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_0210a598.h"
#include "Main/Unknown/code_0210b850.h"
#include "Main/Unknown/code_0210cf20.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"

void func_02071c18(Unk0206bcb0 *p) {
    func_02109110(&p->mUnk_00, 0, p->mUnk_508);
    func_0210a5a8(p, (Unk0210a5a8 *) &p->mUnk_450);
    func_020719d0(p);
    switch (p->mKartModelsEntry->mUnk_000) {
        case 0:
            p->mUnk_3cc = 4;
            break;
        case 1:
            p->mUnk_3cc = 0;
            break;
        case 2:
            p->mUnk_3cc = 1;
            break;
        case 3:
            p->mUnk_3cc = 2;
            break;
        case 4:
            p->mUnk_3cc = 5;
            break;
        case 5:
            p->mUnk_3cc = 6;
            break;
        case 6:
            p->mUnk_3cc = 7;
            break;
        case 7:
            p->mUnk_3cc = 3;
            break;
        case 8:
            p->mUnk_3cc = 10;
            break;
        case 9:
            p->mUnk_3cc = 8;
            break;
        case 10:
            p->mUnk_3cc = 9;
            break;
        case 11:
            p->mUnk_3cc = 11;
            break;
        case 12:
            p->mUnk_3cc = 12;
            break;
    }
    p->mUnk_3d0 = p->mKartModelsEntry->mUnk_004 % 3;
    if (p->mUnk_7c & 1) {
        if (!(p->mUnk_00.mUnk_34 & 1)) {
            func_0210cfbc(&p->mUnk_00, 2, 1);
        }
        if (data_021759c0->mUnk_00c == 2) {
            func_0210b850((Unk0210b7ec *) &p->mUnk_518);
        }
    } else {
        if (p->mUnk_00.mUnk_34 & 1) {
            func_0210cfbc(&p->mUnk_00, 2, 1);
        }
        func_0210b850((Unk0210b7ec *) &p->mUnk_518);
    }
}

void func_020719d0(Unk0206bcb0 *p) {
    Unk02024eec *q;
    Unk02024eec_40 t;
    s32 i;
    s32 k;
    s32 m;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    s32 g;

    p->mUnk_450.mUnk_00 = 0xa5;
    q = (Unk02024eec *) &p->mUnk_450;
    q->mUnk_04 = 0x64;
    q->mUnk_08 = -1;
    q->mUnk_0c = 0;
    q->mUnk_10 = 0;
    q->mUnk_14 = 0;
    q->mUnk_18 = DivFixed12(0x300000, 0xd000 - p->mUnk_2cc->mUnk_10);
    q->mUnk_1c = DivFixed12(0x580000, p->mUnk_2cc->mUnk_10);
    q->mUnk_20 = DivFixed12(0x480000, p->mUnk_2cc->mUnk_10);
    q->mUnk_24 = DivFixed12(0x280000, p->mUnk_2cc->mUnk_10);
    q->mUnk_28 = 0;
    q->mUnk_2c = 0;
    q->mUnk_30 = 0;
    q->mUnk_34 = -1;
    q->mUnk_38 = -1;
    switch (p->mKartModelsEntry->mUnk_004 / 3) {
        case 0:
            k = 4;
            break;
        case 1:
            k = 0;
            break;
        case 2:
            k = 1;
            break;
        case 3:
            k = 2;
            break;
        case 4:
            k = 5;
            break;
        case 5:
            k = 6;
            break;
        case 6:
            k = 7;
            break;
        case 7:
            k = 3;
            break;
        case 8:
            k = 10;
            break;
        case 9:
            k = 8;
            break;
        case 10:
            k = 9;
            break;
        case 11:
            k = 11;
            break;
        case 12:
            k = 12;
            break;
    }
    q->mUnk_68 = k;
    i = func_0202578c(p->mKartModelsEntry->mUnk_004);
    m = i * 0x1c;
    a = *(s32 *) (data_02161ae8 + m);
    b = *(s32 *) (data_02161aec + m);
    c = *(s32 *) (data_02161af0 + m);
    d = *(s32 *) (data_02161af4 + m);
    e = *(s32 *) (data_02161af8 + m);
    f = *(s32 *) (data_02161afc + m);
    g = *(s32 *) (data_02161b00 + m);
    t.mUnk_00 = i;
    t.mUnk_04 = a;
    t.mUnk_08 = b;
    t.mUnk_0c = c;
    t.mUnk_10 = d;
    t.mUnk_14 = e;
    t.mUnk_18 = f;
    t.mUnk_1c = g;
    if (p->mIndex != data_021759c0->mUnk_62) {
        b = c;
    }
    if (p->mIndex != data_021759c0->mUnk_62) {
        a = c;
    }
    t.mUnk_20 = b;
    t.mUnk_24 = a;
    q->mUnk_40_m = t;
}
