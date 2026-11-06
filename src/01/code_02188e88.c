#include "01/code_02188e88.h"
#include "01/code_02185ef4.h"
#include "01/code_02187000.h"
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
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020c0000.h"
#include "code_02147cd8.h"

RaceHudSubScreenCells *data_ov001_021a9ba8;
RaceHudSubScreenCells *data_ov001_021a9ba4;

#pragma thumb off

s32 func_ov001_02189290(void) {
    return CreateRaceHudSubScreenCells(&data_ov001_021a9ba8, 0x1f6);
}

void func_ov001_0218927c(void) {
    ClearRaceHudSubScreenCells(&data_ov001_021a9ba8);
}

void func_ov001_02189160(void) {
    s32 i;
    s32 n = 0;
    u32 v = func_020c0db0();
    Unk0217b498_00 *el;
    Vec3 *pos;

    for (i = 0; i < data_ov001_021a9ba8->mObjectCount; i++) {
        el = data_ov001_021a9ba8->mObjects[i];
        if (!(el->mFlags & 1)) {
            pos = &el->mPos;
            if (ComputeRaceHudSubScreenPosition(pos, &data_ov001_021a9ba8->mCells[n].mUnk_00, v, 1, 1) != FALSE) {
                data_ov001_021a9ba8->mCells[n].mUnk_08 = GetRaceSNcerEntry(0xc5);
                data_ov001_021a9ba8->mCells[n].mUnk_0c = func_020b4e70(pos) ? 2 : 3;
                data_ov001_021a9ba8->mCells[n].mUnk_0e = el->mFlags & 0x20;
                data_ov001_021a9ba8->mCells[n].mUnk_10 = el->mAngle;
                n++;
            }
        }
    }
    data_ov001_021a9ba8->mCellCount = n;
}

void func_ov001_02189144(void *a) {
    DrawRaceHudSubScreenCells(a, data_ov001_021a9ba8, 0);
}

s32 func_ov001_02189128(void) {
    return CreateRaceHudSubScreenCells(&data_ov001_021a9ba4, 0x1fd);
}

void func_ov001_02189114(void) {
    ClearRaceHudSubScreenCells(&data_ov001_021a9ba4);
}

void func_ov001_02188ff8(void) {
    s32 i;
    s32 n = 0;
    u32 v = func_020c0db0();
    Unk0217b498_00 *el;
    Vec3 *pos;

    for (i = 0; i < data_ov001_021a9ba4->mObjectCount; i++) {
        el = data_ov001_021a9ba4->mObjects[i];
        if (!(el->mFlags & 1)) {
            pos = &el->mPos;
            if (ComputeRaceHudSubScreenPosition(pos, &data_ov001_021a9ba4->mCells[n].mUnk_00, v, 1, 1) != FALSE) {
                data_ov001_021a9ba4->mCells[n].mUnk_08 = GetRaceSNcerEntry(0xc5);
                data_ov001_021a9ba4->mCells[n].mUnk_0c = func_020b4e70(pos) ? 2 : 3;
                data_ov001_021a9ba4->mCells[n].mUnk_0e = el->mFlags & 0x20;
                data_ov001_021a9ba4->mCells[n].mUnk_10 = el->mAngle;
                n++;
            }
        }
    }
    data_ov001_021a9ba4->mCellCount = n;
}

void func_ov001_02188fdc(void *a) {
    DrawRaceHudSubScreenCells(a, data_ov001_021a9ba4, 0);
}

#pragma thumb on

u32 func_ov001_02188f04(Unk02188950 *a, Vec3 *b, s32 c) {
    Vec3 local;
    s32 dx;
    s32 dz;
    float f1;
    float f2;

    if (b != NULL) {
        VEC_Subtract(b, &a->mUnk_000.mPos, &local);
        dx = a->mUnk_000.mPos.x - b->x;
        dz = a->mUnk_000.mPos.z - b->z;
        if (c > 0) {
            f1 = 0.5f + (c << 12);
        } else {
            f1 = (c << 12) - 0.5f;
        }
        if (c > 0) {
            f2 = 0.5f + (c << 12);
        } else {
            f2 = (c << 12) - 0.5f;
        }
        if ((s64) dx * dx + (s64) dz * dz < (s64) (s32) f2 * (s32) f1) {
            return 1;
        }
        return 0;
    }
    return 0;
}

u32 func_ov001_02188eac(Unk02188950 *a, s32 b, Vec3 *c, s32 d) {
    s32 v;

    if (c != NULL) {
        v = (u16) (FX_Atan2Idx(c->x - a->mUnk_000.mPos.x, c->z - a->mUnk_000.mPos.z) - b);
        if (v > 0x8000) {
            v -= 0x10000;
        }
        if (-d <= v && v <= d) {
            return 1;
        }
        return 0;
    }
    return 0;
}

void func_ov001_02188e94(Unk02188950 *a, void (**b)()) {
    void (*fn)() = *b;

    *b = NULL;
    if (fn != NULL) {
        fn(a, b, 0);
    }
}

void func_ov001_02188e88(Unk02188950 *a) {
    func_ov001_02187218(a, 0, (s32(*)(Unk02188950 *))(0));
}
