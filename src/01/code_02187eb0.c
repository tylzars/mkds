#include "01/code_02187eb0.h"
#include "01/code_02188158.h"
#include "01/code_02188e88.h"
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
#include "Main/Unknown/code_020f36d8.h"
#include "01/unk_021a7000.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02042000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020da000.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_020fd000.h"
#include "Main/Unknown/code_02042044.h"

Kart *func_ov001_02188104(Unk02188950 *a, s32 b, s32 c) {
    Kart *q;

    q = GetKart((u16) data_021759c0->mEntryIndex);
    if (q != NULL && func_ov001_021881a8(a, &q->mPos, (s32) (b), (s32) (c)) != FALSE && (q->mUnk_48 & 0x40) == 0) {
        return q;
    }
    return NULL;
}

Kart *func_ov001_02188084(Unk02188950 *a, s32 b, s32 c, s32 d) {
    Kart *q;

    q = GetKart((u16) data_021759c0->mEntryIndex);
    if (q != NULL && (q->mUnk_48 & 0x40) == 0 && (c != 0 || d != 0)) {
        if (c == 0 || func_ov001_02188f04(a, &q->mPos, c) != 0) {
            if (d == 0 || func_ov001_02188eac(a, a->mAngle + b, &q->mPos, d) != 0) {
                return q;
            }
        }
    }
    return NULL;
}

Kart *func_ov001_02188000(Unk02188950 *a, s32 b, s32 c) {
    Kart *q;

    q = GetKart((u16) data_021759c0->mEntryIndex);
    if (q != NULL && (q->mUnk_48 & 0x40) == 0 && (b != 0 || c != 0)) {
        if (b == 0 || func_ov001_02188f04(a, &q->mPos, b) != 0) {
            if (c == 0 || func_ov001_02188eac(a, q->mUnk_236 + 0x8000, &q->mPos, c) != 0) {
                return q;
            }
        }
    }
    return NULL;
}

Unk02042044 *func_ov001_02187fc0(Unk02188950 *a) {
    if (a->mUnk_148 < gCourseMap->mEntryGroupCount) {
        return GetCourseMapGroupEntry((u16) (a->mUnk_148), (u16) (a->mUnk_14c));
    }
    return NULL;
}

s32 func_ov001_02187f7c(Unk02188950 *a) {
    if (a->mUnk_148 < gCourseMap->mEntryGroupCount) {
        return GetCourseMapGroupEntry((u16) (a->mUnk_148), (u16) (a->mUnk_14c))->mUnk_0e;
    }
    return 0;
}

s32 func_ov001_02187f38(Unk02188950 *a) {
    if (a->mUnk_148 < gCourseMap->mEntryGroupCount) {
        return GetCourseMapGroupEntry((u16) (a->mUnk_148), (u16) (a->mUnk_14c))->mUnk_10;
    }
    return 0;
}

Unk02042044 *func_ov001_02187ee8(Unk02188950 *a) {
    CourseMap *g = gCourseMap;
    s32 n;

    if (a->mUnk_148 < g->mEntryGroupCount) {
        n = a->mUnk_14c + 1;
        if (n >= g->mEntryGroups[(u16) a->mUnk_148].mEntryCount) {
            n = 0;
        }
        return GetCourseMapGroupEntry((u16) (a->mUnk_148), (u16) (n));
    }
    return NULL;
}

void func_ov001_02187eb0(Unk02188950 *b) {
    CourseMap *g;
    CourseMapEntryGroup *e;
    s32 a;
    s32 n;

    g = gCourseMap;
    a = b->mUnk_148;
    if (a < g->mEntryGroupCount) {
        e = &g->mEntryGroups[(u16) a];
        n = b->mUnk_14c - 1;
        if (n <= 0) {
            n = e->mEntryCount - 1;
        }
        b->mUnk_14c = n;
    }
}
