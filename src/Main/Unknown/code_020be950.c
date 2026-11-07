#include "Main/Unknown/code_020be950.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020ae730.h"

#include "Main/Unknown/code_020b1cf4.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_020b4000.h"
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
#include "Main/Unknown/code_020c7464.h"
#include "Main/Unknown/code_020c8000.h"
#include "Main/Unknown/code_020c9000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ca534.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020cccd8.h"
#include "Main/Unknown/code_020ce6a8.h"
#include "Main/Unknown/code_020cee0c.h"
#include "Main/Unknown/code_020cf310.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/code_020d0e3c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020beb9c.h"
#include "Main/Unknown/code_020c7000.h"
#include "Main/Unknown/code_020ca000.h"
#include "Main/Unknown/code_020cc000.h"
#include "Main/Unknown/code_020cd000.h"
#include "Main/Unknown/code_020ce000.h"
#include "Main/Unknown/code_020cf000.h"
#include "Main/Unknown/code_020d0000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/unk_02169000.h"
#include "01/code_021892ac.h"
#include "01/code_02188e88.h"
#include "Main/Unknown/code_020c06c4.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_02100094.h"
#include "Main/Unknown/code_021000c8.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "01/code_021813f4.h"
#include "Main/Unknown/code_02077bc0.h"

u32 func_020c0dc4(void) {
    return (gRaceHudSubScreenCellGroups->mUnk_000);
}

u32 func_020c0db0(void) {
    return (gRaceHudSubScreenCellGroups->mUnk_004);
}

u32 func_020c0d9c(void) {
    return (gRaceHudSubScreenCellGroups->mUnk_008);
}

BOOL CreateRaceHudSubScreenCells(RaceHudSubScreenCells **a, s32 b) {
    BOOL t;
    void *q;
    void *p;
    s32 i;
    s32 n;

    t = FALSE;
    q = func_021000d0(b);
    p = func_02100138(b);
    if (b == 0x1ae || b == 0x1ab) {
        t = TRUE;
    }
    if (t != FALSE) {
        if (p == NULL) {
            return FALSE;
        }
        n = func_021000c8(p);
        if (n == 0) {
            return FALSE;
        }
    } else {
        if (q == NULL) {
            return FALSE;
        }
        n = func_02100094(q);
        if (n == 0) {
            return FALSE;
        }
    }
    *a = HeapAlloc(GetHeap(func_020364e8()), 0x14);
    if (t != FALSE) {
        (*a)->mObjects = (Unk0217b498_00 **) func_0210008c(p);
    } else {
        (*a)->mObjects = func_02100084(q);
    }
    (*a)->mCellCount = 0;
    (*a)->mObjectCount = n;
    (*a)->mUnk_0c = HeapAlloc(GetHeap(func_020364e8()), n * 8);
    for (i = 0; i < n; i++) {
        ComputeRaceHudSubScreenCoursePosition(&(*a)->mObjects[i]->mPos, &(*a)->mUnk_0c[i]);
    }
    (*a)->mCells = func_020ae730(n * 2, 0x14);
    return TRUE;
}

BOOL CreateRaceHudSubScreenCellsWithCount(RaceHudSubScreenCells **a, s32 b) {
    if (b == 0) {
        return FALSE;
    }
    *a = HeapAlloc(GetHeap(func_020364e8()), 0x14);
    (*a)->mCellCount = 0;
    (*a)->mObjectCount = b;
    (*a)->mUnk_0c = HeapAlloc(GetHeap(func_020364e8()), b * 8);
    (*a)->mCells = func_020ae730(b, 0x14);
    return TRUE;
}

void ClearRaceHudSubScreenCells(RaceHudSubScreenCells **a) {
    (*a)->mObjects = NULL;
    (*a)->mUnk_0c = NULL;
    (*a)->mCells = NULL;
    *a = NULL;
}

void DrawRaceHudSubScreenCells(Unk020c06c4 *a, RaceHudSubScreenCells *b, s32 c) {
    s32 i;
    s32 l;
    u16 v;
    u16 n;
    s32 d[4];
    s32 e[2];
    s32 p;
    s32 q;
    s32 k;
    Unk020c06c4_08 *t;
    RaceHudSubScreenCell *r;
    s32 x;
    s32 y;
    void *z;

    l = gRaceHudSubScreenCellGroups->mUnk_000;
    if (c != 0) {
        v = func_020b6368();
    }
    for (i = 0; i < b->mCellCount; i++) {
        p = b->mCells[i].mUnk_0c;
        if (l <= p) {
            q = b->mCells[i].mUnk_0e;
            n = 0;
            if (c != 0) {
                if (gRaceSetup->mMirrorMode != 0) {
                    Matrix2x2Rotation(d, (u16) (b->mCells[i].mUnk_10 + 0x8000 - v));
                } else {
                    Matrix2x2Rotation(d, (u16) (v + (0x8000 - b->mCells[i].mUnk_10)));
                }
                n = func_020ae5c4(a);
                a->mUnk_000.mUnk_20[n].mUnk_06 = d[0] >> 4;
                a->mUnk_000.mUnk_20[n].mUnk_0e = d[1] >> 4;
                a->mUnk_000.mUnk_20[n].mUnk_16 = d[2] >> 4;
                a->mUnk_000.mUnk_20[n].mUnk_1e = d[3] >> 4;
            }
            r = &b->mCells[i];
            x = r->mDrawPos.mUnk_00;
            z = r->mCell;
            y = r->mDrawPos.mUnk_04;
            k = a->mUnk_400;
            e[0] = x << 12;
            e[1] = y << 12;
            a->mUnk_400 +=
                NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, z, c != 0 ? d : 0, e, n, 1);
            t = &a->mUnk_000.mUnk_00[k];
            for (; k < a->mUnk_400; k++, t++) {
                if ((q != 0 ? 1 : -1) != -1) {
                    t->mUnk_0a = q != 0 ? 1 : -1;
                }
                if (p != -1) {
                    t->mUnk_0e = p;
                }
            }
        }
    }
}

void DrawRaceHudSubScreenCellsScaled(Unk020c06c4 *a, RaceHudSubScreenCells *b, s32 c) {
    s32 i;
    s32 l;
    u16 v;
    s32 d[4];
    s32 e[2];
    s32 p;
    s32 q;
    s32 k;
    u16 n;
    Unk020c06c4_08 *t;
    RaceHudSubScreenCell *r;
    s32 x;
    s32 y;
    void *z;

    l = gRaceHudSubScreenCellGroups->mUnk_000;
    if (c != 0) {
        v = func_020b6368();
    }
    for (i = 0; i < b->mCellCount; i++) {
        p = b->mCells[i].mUnk_0c;
        if (l <= p) {
            q = b->mCells[i].mUnk_0e;
            if (c != 0) {
                if (gRaceSetup->mMirrorMode != 0) {
                    Matrix2x2RotationReciprocalScale(d, b->mUnk_0c[i].mUnk_00, (u16) (b->mCells[i].mUnk_10 - v));
                } else {
                    Matrix2x2RotationReciprocalScale(d, b->mUnk_0c[i].mUnk_00, (u16) (v - b->mCells[i].mUnk_10));
                }
            } else {
                Matrix2x2ReciprocalScale(d, b->mUnk_0c[i].mUnk_00);
            }
            n = func_020ae5c4(a);
            a->mUnk_000.mUnk_20[n].mUnk_06 = d[0] >> 4;
            a->mUnk_000.mUnk_20[n].mUnk_0e = d[1] >> 4;
            a->mUnk_000.mUnk_20[n].mUnk_16 = d[2] >> 4;
            a->mUnk_000.mUnk_20[n].mUnk_1e = d[3] >> 4;
            r = &b->mCells[i];
            x = r->mDrawPos.mUnk_00;
            z = r->mCell;
            y = r->mDrawPos.mUnk_04;
            k = a->mUnk_400;
            e[0] = x << 12;
            e[1] = y << 12;
            a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, z, d, e, n, 1);
            t = &a->mUnk_000.mUnk_00[k];
            for (; k < a->mUnk_400; k++, t++) {
                if ((q != 0 ? 1 : -1) != -1) {
                    t->mUnk_0a = q != 0 ? 1 : -1;
                }
                if (p != -1) {
                    t->mUnk_0e = p;
                }
            }
        }
    }
}

void InitRaceHudSubScreenCellGroups(void) {
    gRaceHudSubScreenCellGroups = HeapAlloc(GetHeap(func_020364e8()), 0x25c);
    gRaceHudSubScreenCellGroups->mUnk_000 = 0;
    gRaceHudSubScreenCellGroups->mUnk_004 = 0;
    gRaceHudSubScreenCellGroups->mUnk_008 = 0;
    gRaceHudSubScreenCellGroups->mGroupCount = 0;
    if (CreateRaceHudSubScreenKarts()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenKarts && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenItemCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenItemCells && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (func_020cf310()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != func_020cf310 && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenItemBoxCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenItemBoxCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenEarthenPipeCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenEarthenPipeCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenWanwanCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenWanwanCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenDossunCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenDossunCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (func_020ca534()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != func_020ca534 && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenSmanCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenSmanCells && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenMoveTreeCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenMoveTreeCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenPukupukuCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenPukupukuCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenChoropuCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenChoropuCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (func_020c8254()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != func_020c8254 && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenSecondHand()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenSecondHand && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (func_020ca670()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != func_020ca670 && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenPendulumCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenPendulumCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenNsKiller2Cells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenNsKiller2Cells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenFlipperCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenFlipperCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenMkdEfBubbleCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenMkdEfBubbleCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenKuriboCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenKuriboCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenObPakkunSfCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenObPakkunSfCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenRock2Cells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenRock2Cells && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenRockCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenRockCells && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenWoodbox1Cells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenWoodbox1Cells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenRainStarCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenRainStarCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenMkdEfBurnerCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenMkdEfBurnerCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenCoverPooHoleCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenCoverPooHoleCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenBoundCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenBoundCells && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (func_020cdf18()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != func_020cdf18 && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenFireball2Cells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenFireball2Cells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenIronBallCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenIronBallCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenSanboCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenSanboCells && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenBasabasaCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenBasabasaCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (func_020cee0c()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != func_020cee0c && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenBerryCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenBerryCells && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenCreamCells()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenCreamCells && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (gRaceSetup->mMode != MODE_MISSION_RUN) {
        return;
    }
    if (func_ov001_02181510()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != func_ov001_02181510 && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (func_ov001_02189584()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != func_ov001_02189584 && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (func_ov001_021896e0()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != func_ov001_021896e0 && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (func_ov001_02189848()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != func_ov001_02189848 && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (func_ov001_02189290()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != func_ov001_02189290 && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (func_ov001_02189bd8()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != func_ov001_02189bd8 && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (func_ov001_021899b0()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != func_ov001_021899b0 && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (func_ov001_02189d88()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != func_ov001_02189d88 && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (func_ov001_02189410()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != func_ov001_02189410 && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (func_ov001_02189128()) {
        s32 n;
        s32 i;

        n = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != func_ov001_02189128 && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[n] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
}

void ClearRaceHudSubScreenCellGroups(void) {
    s32 i;

    for (i = 0; i < gRaceHudSubScreenCellGroups->mGroupCount; i++) {
        gRaceHudSubScreenCellGroups->mClearFunctions[i]();
    }
    gRaceHudSubScreenCellGroups = NULL;
}

void UpdateRaceHudSubScreenCellGroups(void) {
    Vec3 v;
    s32 i;
    s32 n;
    float f;

    switch (GetRaceHudSubScreenState()) {
        case 0:
            UpdateRaceHudSubScreenKarts();
            break;
        case 1:
        case 2:
        case 3:
            if (func_020b1d50() * 3 > 0) {
                f = 0.5f + (func_020b1d50() * 0x3000);
            } else {
                f = (func_020b1d50() * 0x3000) - 0.5f;
            }
            n = f;
            gRaceHudSubScreenCellGroups->mUnk_004 = ((s64) n * 20) >> 12;
            gRaceHudSubScreenCellGroups->mUnk_008 = FX_Div(0x2400, gRaceHudSubScreenCellGroups->mUnk_004);
            UpdateRaceHudSubScreenProjectionAndBgAffine(GetRaceHudSubScreenBgAffine(),
                                                        gRaceHudSubScreenCellGroups->mUnk_004);
            func_0207a91c(&v, GetFollowedKartOrEntryIndex());
            gRaceHudSubScreenCellGroups->mUnk_000 = func_020b4e70(&v) != 0 ? 0 : 3;
            for (i = 0; i < gRaceHudSubScreenCellGroups->mGroupCount; i++) {
                gRaceHudSubScreenCellGroups->mUpdateFunctions[i]();
            }
            break;
    }
}

void DrawRaceHudSubScreenCellGroups(void *a) {
    s32 i;

    switch (GetRaceHudSubScreenState()) {
        case 0:
            DrawRaceHudSubScreenKarts(a);
            break;
        case 1:
        case 2:
        case 3:
            for (i = 0; i < gRaceHudSubScreenCellGroups->mGroupCount; i++) {
                gRaceHudSubScreenCellGroups->mDrawFunctions[i](a);
            }
            break;
    }
}
