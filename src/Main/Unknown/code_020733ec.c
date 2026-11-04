#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02066ac0.h"
#include "Main/Unknown/code_02067cb0.h"
#include "Main/Unknown/code_02067f94.h"
#include "Main/Unknown/code_020733ec.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02067000.h"
#include "Main/Unknown/code_02067c70.h"
#include "Main/Unknown/code_02067f78.h"
#include "Main/Unknown/code_020681e0.h"
#include "Main/Unknown/code_020681e4.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_0207a73c.h"
#include "Main/Unknown/code_0208ae60.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020e0650.h"
#include "Main/Unknown/unk_02165000.h"
#include "code_02147cd8.h"
#include "ITCM/code_01ff9598.h"

void func_02073630(void) {
    Unk021759c0 *d;
    u16 i;
    void **a;
    void **b;

    data_0217ac14 = func_01ffa478;
    d = data_021759c0;
    i = 0;
    a = data_0217ac18;
    b = data_0217ac54;
    if (d->mCourseId == 0x1d || d->mCourseId == 0x28) {
        data_0217ac14 = func_01ffa380;
    }
    data_0217ac10 = 0;
    if (d->mMode == 2) {
        switch (d->mCourseId) {
            case 0x2a:
            case 0x2b:
                data_0217ac10 = 1;
                data_0217ac14 = func_01ffa41c;
                break;
        }
    }
    for (; i < 15; i++, a++, b++) {
        switch (i) {
            case 0:
                *a = func_02067f88;
                *b = func_020681e0;
                break;
            case 2:
                *a = func_02067f78;
                *b = func_020681e0;
                break;
            case 3:
                *a = func_02067ec4;
                *b = func_020681e0;
                break;
            case 4:
                *a = func_02067e10;
                *b = func_020681e0;
                break;
            case 5:
                *a = func_02067d0c;
                *b = func_020681e0;
                break;
            case 6:
                *a = func_02067d88;
                *b = func_020681e0;
                break;
            case 7:
                *a = func_02067cb0;
                *b = func_020681e0;
                break;
            case 9:
                *a = func_02067c90;
                *b = func_02068094;
                break;
            case 8:
                *a = func_02067ca0;
                *b = func_020680e0;
                break;
            case 10:
                *a = func_02067c80;
                *b = func_02067f94;
                break;
            case 11:
                *a = func_02067b0c;
                *b = func_020681e0;
                break;
            case 12:
                *a = func_02067c70;
                *b = func_020681e0;
                break;
            case 13:
                *a = func_02067bf4;
                *b = func_020681e0;
                break;
            case 14:
                *a = func_02067b60;
                *b = func_020681e0;
                break;
            default:
                *a = func_020681e4;
                *b = func_020681e0;
                break;
        }
    }
    data_usa_021654ec = DivFixed12(0x1000, ((s64) (s32) func_0208ae60() * 0xd9aLL) >> 12);
}

void func_020733ec(Kart *p) {
    void *h;
    Vec3 *v;
    u16 i;

    h = GetHeap(func_020364e8());
    p->mUnk_230 = func_02071568;
    func_020726bc(p);
    func_02071e28(p);
    if (p->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) {
        func_0207a73c(DivFixed12(0x1000, p->mUnk_2cc->mUnk_10));
    }
    func_02071c18(p);
    func_020e0650((u32 *) &p->mUnk_208);
    p->mUnk_310 = HeapAlloc(h, 0x158);
    if (gCourseMap->mUnk_70 != 0 || gCourseMap->mUnk_90 != 0) {
        if (data_021759c0->mCurrentEntries[p->mIndex].mUnk_08.mKind == 1) {
            p->mUnk_7c |= 2;
            if (p->mUnk_7c & 2) {
                for (i = 0; i < 12; i++) {
                    if (i != 0) {
                        p->mUnk_2cc->mUnk_38[i] = p->mUnk_2cc->mUnk_38[i] << 2;
                        if (p->mUnk_2cc->mUnk_38[i] > p->mUnk_2cc->mUnk_38[0]) {
                            p->mUnk_2cc->mUnk_38[i] = p->mUnk_2cc->mUnk_38[0];
                        }
                    }
                }
            }
        }
    }
    p->mUnk_2ca = -1;
    p->mUnk_2c8 = p->mUnk_2ca;
    if (data_021759c0->mMode == 5) {
        v = &p->mUnk_1d8;
    } else {
        v = &p->mUnk_1b8;
    }
    if (p->mUnk_2c8 == -1) {
        p->mUnk_2c8 = func_020d555c(v, p->mUnk_2cc->mUnk_00 + 0xd000, 0x8000, p);
    }
    if (p->mUnk_2ca == -1) {
        p->mUnk_2ca = func_020d555c(&p->mUnk_1f0, (s32) (((s64) p->mUnk_2cc->mUnk_00 << 15) >> 12), 0x800, p);
    }
    p->mUnk_44 |= 0x10;
    p->mUnk_4d0 = 0x64;
    p->mUnk_1d0 = p->mUnk_2cc->mUnk_00;
    func_020719d0(p);
    if (data_021759c0->mMode == 5) {
        p->mUnk_514 = HeapAlloc(h, 0xb8);
        func_02071fb8(p, h);
    }
    if (func_02062eb0() != 0) {
        p->mUnk_44 |= 0x1000000;
    }
}
