#include "Main/Unknown/code_020d2090.h"

#include "Main/Unknown/code_020d2094.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020d6538.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02134398.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020b4000.h"

BOOL func_020d2234(MapObject *d, ItemObject *e) {
    s32 a;
    s32 c;
    s32 b;
    a = d->mKind;
    b = e->mKind;
    c = 0;
    while (a >= 100) {
        a -= 100;
        c++;
    }
    if (func_020d6d8c(0, b, c, a) == 0 || func_020d6d34(0, b, c, a, 3) != 2) {
        return FALSE;
    }
    return TRUE;
}

#pragma thumb on

void *FindMainRaceOrMainEffectMapObjFile(const char *a) {
    char buf[0x100];
    snprintf(buf, 0x100, "MapObj/%s", a);
    return FindMainRaceOrMainEffectFile(buf);
}

void *FindCourseMapObjFile(const char *a) {
    char buf[0x100];
    snprintf(buf, 0x100, "MapObj/%s", a);
    return FindCourseFile(buf);
}

u32 DecimalNonZeroDigitsToBitMask(s32 c) {
    u32 a;
    s32 b;
    a = 0;
    if (c >= 1000) {
        b = c / 1000;
        a |= 1 << b;
        c = (s16) (c - b * 1000);
    }
    if (c >= 100) {
        b = c / 100;
        a |= 1 << b;
        c = (s16) (c - b * 100);
    }
    if (c >= 10) {
        b = c / 10;
        a |= 1 << b;
        c = (s16) (c - b * 10);
    }
    if (c >= 1) {
        a |= 1 << c;
    }
    return a;
}

#pragma thumb off

void InitRaceMNumberPair(void) {
    RaceMNumberPair *p;
    p = HeapAlloc(GetHeap(func_020364e8()), 0x28);
    gRaceMNumberPair = p;
    p->mCourseNumber = data_021759c0->mCourseNumber;
    if (data_021759c0->mMode == 5) {
        gRaceMNumberPair->mCourseCount = 4;
    } else if (data_021759c0->mMode == MODE_VS && data_021759c0->mUnk_1c == 2) {
        gRaceMNumberPair->mCourseCount = data_021759c0->mUnk_3d8;
    } else {
        gRaceMNumberPair->mCourseCount = 0;
    }
    func_020b4cec(gRaceMNumberPair->mUnk_08, 0x1000);
    gRaceMNumberPair->mUnk_18 = NULL;
    gRaceMNumberPair->mUnk_1c = 0;
    gRaceMNumberPair->mUnk_20 = 0;
    gRaceMNumberPair->mOffsetX = 0;
}

u32 func_020d2094(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRaceMNumberPair;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void func_020d2090(void) {}
