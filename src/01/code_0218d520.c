#include "01/code_0218d520.h"
#include "01/code_02187d14.h"
#include "01/code_02187eb0.h"
#include "01/code_02188230.h"
#include "01/code_02188cd8.h"
#include "01/code_02187000.h"
#include "01/code_02187e78.h"
#include "01/code_02185ef4.h"
#include "01/code_02188000.h"
#include "01/code_02188158.h"
#include "01/code_02188218.h"
#include "01/code_02188e24.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020a126c.h"
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
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/code_021000d0.h"

void func_ov001_0218dc20(Unk02188950 *a) {
    Unk0218dabc *r7 = a->mUnk_0a4;
    int r5;
    u16 ang = (r7->mUnk_184 + 0x8000);
    int idx;

    switch (a->mUnk_0a8) {
        case 1:
            r5 = a->mPrm->mUnk_0c0;
            break;
        case 2:
            r5 = a->mPrm->mUnk_0c4;
            break;
        case 3:
            r5 = a->mPrm->mUnk_0c8;
            break;
        case 4:
            r5 = a->mPrm->mUnk_0cc;
            break;
    }
    idx = (ang >> 4) * 2;
    a->mUnk_000.mPos.x = r7->mUnk_004 + (s32) (((s64) r5 * gPairsByAngle[idx]) >> 12);
    a->mUnk_000.mPos.z = a->mUnk_0a4->mUnk_00c + (s32) (((s64) r5 * gPairsByAngle[idx + 1]) >> 12);
}

void func_ov001_0218dba8(Unk02188950 *a) {
    int diff;
    int step;
    int limit;
    s32 cur;

    a->mUnk_13c = a->mUnk_13c - 1;
    if (a->mUnk_13c <= 0) {
        a->mUnk_13c = 0;
        cur = a->mAngle;
        diff = (u16) (a->mUnk_0a4->mUnk_184 - cur);
        if (diff > 0x8000) {
            diff -= 0x10000;
        }
        limit = a->mAnglePerCall;
        step = diff < -limit ? -limit : (diff > limit ? limit : diff);
        a->mAngle = (u16) (cur + step);
        a->mMoveAngle = a->mAngle;
    }
}

void func_ov001_0218dadc(Unk02188950 *a) {
    Unk0218dabc *r7 = a->mUnk_0a4;
    int r5;
    u16 ang = (r7->mUnk_184 + 0x8000);
    int idx;

    switch (a->mUnk_0a8) {
        case 1:
            r5 = a->mPrm->mUnk_0c0;
            break;
        case 2:
            r5 = a->mPrm->mUnk_0c4;
            break;
        case 3:
            r5 = a->mPrm->mUnk_0c8;
            break;
        case 4:
            r5 = a->mPrm->mUnk_0cc;
            break;
    }
    idx = (ang >> 4) * 2;
    a->mUnk_000.mPos.x = r7->mUnk_004 + (s32) (((s64) r5 * gPairsByAngle[idx]) >> 12);
    a->mUnk_000.mPos.y = a->mUnk_0a4->mUnk_008;
    a->mUnk_000.mPos.z = a->mUnk_0a4->mUnk_00c + (s32) (((s64) r5 * gPairsByAngle[idx + 1]) >> 12);
}

void func_ov001_0218dabc(Unk02188950 *a) {
    a->mAngle = a->mUnk_0a4->mUnk_184;
    a->mMoveAngle = a->mAngle;
}

void func_ov001_0218da1c(Unk02188950 *a) {
    ReleaseEffects(a);
    StartEffectAtOffset(a, 0, a->mOffset.y >> 4, 0, 0x427, 0xf);
    StartEffectAtOffset(a, 0, a->mOffset.y >> 4, 0, 0x426, 0xf);
    StartMapObjectSound(&a->mUnk_000, 0x24d);
    func_ov001_02188230(a);
    if (func_ov001_02188220(a) == 2) {
        StartMapObjectSound(&a->mUnk_000, 0x24c);
    } else if (func_ov001_02188220(a) >= 3) {
        a->mUnk_0ac = 0;
    }
    SetMapObjectModelNsbtpFrameIndex(a->mNsbmd, func_ov001_02188220(a));
}

void func_ov001_0218d9cc(Unk02188950 *a) {
    Unk0218d87c *list;
    int i;
    Unk02188950 *q;

    list = FindMapObjectKindUpdateList(0x1fe);
    if (list != NULL) {
        for (i = 0; i < list->mUnk_04 && (q = list->mUnk_00[i]) != NULL; i++) {
            StartStateFrameCountCallback(q, (q->mUnk_0a8 * 15), (UnkFunc *) func_ov001_0218da1c);
        }
    }
    func_ov001_0218da1c(a);
}

void func_ov001_0218d950(Unk02188950 *a) {
    s32 prod;
    float f;
    ModelAnimationView *s;

    func_ov001_02187218(a, 1, NULL);
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_088, a->mPrm->mUnk_08c);
    prod = a->mPrm->mUnk_0d0 * a->mUnk_0a8;
    if (prod > 0) {
        f = 0.5f + (prod << 12);
    } else {
        f = (prod << 12) - 0.5f;
    }
    s = a->mNsbmd->mNsbcaAnimation;
    s->mUnk_0c = f;
    *s->mUnk_1c[s->mUnk_1a] = s->mUnk_0c;
}

void func_ov001_0218d8f4(Unk02188950 *a, int b) {
    Unk0218d87c *list;
    int i;

    list = FindMapObjectKindUpdateList(0x1fe);
    if (list != NULL) {
        for (i = 0; i < list->mUnk_04 && list->mUnk_00[i] != NULL; i++) {
            StartAnimationNoEndCallback(a, a->mPrm->mUnk_088, (a->mPrm->mUnk_08c * b / 100));
        }
    }
}

void func_ov001_0218d87c(Unk02188950 *a, int b) {
    Unk0218d87c *list;
    int i;
    Unk02188950 *q;

    list = FindMapObjectKindUpdateList(0x1fe);
    if (list != NULL) {
        for (i = 0; i < list->mUnk_04 && (q = list->mUnk_00[i]) != NULL; i++) {
            q->mUnk_13c = q->mPrm->mUnk_0d8 * q->mUnk_0a8 * 100 / b;
            q->mAnglePerCall = a->mPrm->mUnk_0d4 * b / 100;
        }
    }
}

void func_ov001_0218d824(Unk02188950 *b, int c) {
    MissionRunPrm *a;

    a = b->mPrm;
    SetSpeedTargetAndPerCall(b, (a->mUnk_090 * c / 100), a->mUnk_094);
    a = b->mPrm;
    func_ov001_02188c48(b, a->mUnk_098 * c / 100, a->mUnk_09c);
    SetAnglePointAndMoveAnglePoint(b, &GetNextGroupEntry(b)->mPos);
}

void func_ov001_0218d800(Unk02188950 *a) {
    a->mUnk_150 = 1;
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_088, a->mPrm->mUnk_08c);
}

int func_ov001_0218d520(Unk02188950 *a) {
    int r4;
    s32 t;
    s32 *v;

    if (IsPointInRange(a, &GetCurrentGroupEntry(a)->mPos, a->mPrm->mUnk_0a0, 0)) {
        if (GetBalloonOrShineCount(gRaceSetup->mEntryIndex) <= 1) {
            r4 = 0x1000 - a->mPrm->mUnk_0ac;
            t = func_ov001_02187f38(a);
            r4 = (((s64) t * r4) >> 12);
        } else if (GetBalloonOrShineCount(gRaceSetup->mEntryIndex) <= 2) {
            r4 = 0x1000 - a->mPrm->mUnk_0a8;
            t = func_ov001_02187f38(a);
            r4 = (((s64) t * r4) >> 12);
        } else {
            r4 = func_ov001_02187f38(a);
        }
        if (func_ov001_02187f7c(a) >= 1) {
            func_ov001_0218d9cc(a);
        }
        if ((gRaceSetup->mMode == MODE_MISSION_RUN ? IsWinnerDecided() : 0) == FALSE && a->mUnk_0a8 == 0 &&
            func_ov001_021871f8(a, 3) != 0) {
            if (GetEntryKartInAngleRange(a, a->mPrm->mUnk_120, a->mPrm->mUnk_124, a->mPrm->mUnk_128)) {
                a->mUnk_0a8 = a->mPrm->mUnk_12c;
                a->mUnk_150 = 3;
                StartAnimationWithEndCallback(a, a->mPrm->mUnk_118, a->mPrm->mUnk_11c, (UnkFunc *) func_ov001_0218d800);
                r4 -= a->mPrm->mUnk_130;
                StartMapObjectSound(&a->mUnk_000, 0x24b);
            } else if (GetEntryKartInAngleRange(a, a->mPrm->mUnk_10c, a->mPrm->mUnk_110, a->mPrm->mUnk_114)) {
                a->mUnk_0a8 = a->mPrm->mUnk_12c;
                a->mUnk_150 = 3;
                StartAnimationWithEndCallback(a, a->mPrm->mUnk_104, a->mPrm->mUnk_108, (UnkFunc *) func_ov001_0218d800);
                r4 -= a->mPrm->mUnk_130;
                StartMapObjectSound(&a->mUnk_000, 0x24b);
            }
        }
        func_ov001_0218d824(a, r4);
        func_ov001_0218d87c(a, r4);
        IncrementEntryIndex(a);
        if (a->mEntryIndex == 0) {
            IncrementEntryGroupIndex(a, 4);
        }
    }
    if (a->mUnk_0a8 > 0) {
        a->mUnk_0a8 = a->mUnk_0a8 - 1;
    }
    if (func_ov001_021871f8(a, 5)) {
        if (func_ov001_02188220(a) == 2) {
            a->mUnk_140 = a->mUnk_140 + 1 >= 6 ? 0 : a->mUnk_140 + 1;
            if (a->mUnk_140 == 0) {
                StartEffectAtOffset(a, 0, 0, 0, 0x3f9, 0x1c);
            }
            a->mUnk_144 = a->mUnk_144 + 1 >= 0x12 ? 0 : a->mUnk_144 + 1;
            if (a->mUnk_144 == 0) {
                StartMapObjectSound(&a->mUnk_000, 0x24f);
            }
        } else if (func_ov001_02188220(a) == 1) {
            a->mUnk_140 = a->mUnk_140 + 1 >= 0x12 ? 0 : a->mUnk_140 + 1;
            if (a->mUnk_140 == 0) {
                StartEffectAtOffset(a, 0, 0, 0, 0x3f8, 0x1c);
                StartMapObjectSound(&a->mUnk_000, 0x24e);
            }
        }
    }
    return 0;
}
