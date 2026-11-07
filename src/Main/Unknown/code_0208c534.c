#include "Main/Unknown/code_0208c534.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"

void InitKartTurnEffects(void *a) {
    u16 i;
    u16 j;
    KartTurnEffects *e;

    gKartTurnEffects = HeapAlloc(a, data_021759c0->mKartCount * 0x88);
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        e = &gKartTurnEffects[i];
        e->mIndex = i;
        if (i == data_021759c0->mEntryIndex || data_021759c0->mUnk_00c == 5 ||
            data_021759c0->mMode == MODE_TIME_ATTACK) {
            e->mTurnStartEffectId = 0x14;
            e->mLevel4FirstEffectId = 0x11;
            e->mLevel4SecondEffectId = 0x12;
            e->mStartLevel4Effects = StartKartLevel4EffectsWithSecond;
            e->mStopLevel4Emission = StopKartLevel4EmissionWithSecond;
            e->mStartLevel4Emission = StartKartLevel4EmissionWithSecond;
            e->mReleaseLevel4Effects = ReleaseKartLevel4EffectsWithSecond;
            e->mStopLevel4Effects = StopKartLevel4EffectsWithSecond;
            e->mPlaceLevel4Effects = PlaceKartLevel4EffectsWithSecond;
            e->mHideEffects = HideKartEffectsWithSecond;
            e->mShowEffects = ShowKartEffectsWithSecond;
        } else {
            e->mTurnStartEffectId = 0x15;
            e->mLevel4FirstEffectId = 0x13;
            e->mLevel4SecondEffectId = -1;
            e->mStartLevel4Effects = StartKartLevel4EffectsFirstOnly;
            e->mStopLevel4Emission = StopKartLevel4EmissionFirstOnly;
            e->mStartLevel4Emission = StartKartLevel4EmissionFirstOnly;
            e->mReleaseLevel4Effects = ReleaseKartLevel4EffectsFirstOnly;
            e->mStopLevel4Effects = StopKartLevel4EffectsFirstOnly;
            e->mPlaceLevel4Effects = PlaceKartLevel4EffectsFirstOnly;
            e->mHideEffects = HideKartEffectsFirstOnly;
            e->mShowEffects = ShowKartEffectsFirstOnly;
        }
        e->mLevel3FirstEffectId = 0x16;
        e->mLevel3SecondEffectId = 0x17;
        for (j = 0; j < 2; j++) {
            e->mLevel4FirstEffects[j] = NULL;
            e->mLevel4SecondEffects[j] = NULL;
            e->mTurnStartEffects[j] = NULL;
            e->mLevel3FirstEffects[j] = NULL;
            e->mLevel3SecondEffects[j] = NULL;
        }
        e->mLevel4StopFrames = 0;
        e->mLevel4StopRequested = FALSE;
        e->mLevel4Present = 0;
        e->mTurnStartPresent = 0;
        e->mLevel3Present = 0;
        e->mLevel2Present = FALSE;
        e->mLevel3Frames = 0;
        e->mLevel2Frames = 0;
        e->mLevel4RestartFrames = 0;
        e->mLevel4RestartRequested = 0;
    }
}

void StartKartTurnStartEffects(KartTurnEffects *p) {
    u16 i;

    if (p->mTurnStartPresent != 0) {
        for (i = 0; i < 2; i++) {
            func_0208b6d0(&p->mTurnStartEffects[i]);
        }
    }
    p->mTurnStartPresent = 0;
    for (i = 0; i < 2; i++) {
        p->mTurnStartEffects[i] = StartEffect(p->mTurnStartEffectId, &data_02155fcc);
        p->mTurnStartEffects[i]->mUnk_72 = 0x7fff;
        p->mTurnStartEffects[i]->mUnk_80_8 = 0x1c;
        p->mTurnStartEffects[i]->mUnk_6c = 0x1000;
    }
    p->mTurnStartPresent = 1;
}

void StopKartTurnStartEffects(KartTurnEffects *p) {
    u16 i;

    if (p->mTurnStartPresent == 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        p->mTurnStartEffects[i]->mUnk_24.mUnk_00_0 = 1;
        p->mTurnStartEffects[i] = NULL;
    }
    p->mTurnStartPresent = 0;
}

void AdvanceKartTurnStartEffects(KartTurnEffects *p, Kart *q) {
    u16 i;
    KartEffects *e;
    Vec3 a;
    Vec3 b;
    Vec3 c;
    Unk0201ca6c *f;

    if (p->mTurnStartPresent == 0) {
        return;
    }
    e = GetKartEffects(q->mIndex);
    for (i = 0; i < 2; i++) {
        a.x = ((s64) q->mEffectVelocity.x * 0xb33) >> 12;
        a.y = ((s64) q->mEffectVelocity.y * 0xb33) >> 12;
        a.z = ((s64) q->mEffectVelocity.z * 0xb33) >> 12;
        p->mTurnStartEffects[i]->mUnk_40 = a;
        b.x = -a.x;
        b.y = -a.y;
        b.z = -a.z;
        VEC_Add(&e->mSidePositions[i], &b, &c);
        f = p->mTurnStartEffects[i];
        f->mUnk_28.x = c.x + f->mUnk_20->mUnk_00->mUnk_04.x;
        f->mUnk_28.y = c.y + f->mUnk_20->mUnk_00->mUnk_04.y;
        f->mUnk_28.z = c.z + f->mUnk_20->mUnk_00->mUnk_04.z;
        if ((q->mUnk_44 & KART_44_ON_GROUND) == 0) {
            p->mTurnStartEffects[i]->mUnk_24.mUnk_00_1 = 1;
        } else {
            p->mTurnStartEffects[i]->mUnk_24.mUnk_00_1 = 0;
        }
    }
}

void StartKartLevel4EffectsWithSecond(KartTurnEffects *p) {
    u16 i;

    for (i = 0; i < 2; i++) {
        p->mLevel4FirstEffects[i] = StartEffect(p->mLevel4FirstEffectId, &data_02155fcc);
        p->mLevel4SecondEffects[i] = StartEffect(p->mLevel4SecondEffectId, &data_02155fcc);
    }
}

void StartKartLevel4EffectsFirstOnly(KartTurnEffects *p) {
    u16 i;

    for (i = 0; i < 2; i++) {
        p->mLevel4FirstEffects[i] = StartEffect(p->mLevel4FirstEffectId, &data_02155fcc);
    }
}

void StopKartLevel4EmissionWithSecond(KartTurnEffects *p) {
    u16 i;

    for (i = 0; i < 2; i++) {
        p->mLevel4FirstEffects[i]->mUnk_24.mUnk_00_1 = 1;
        p->mLevel4SecondEffects[i]->mUnk_24.mUnk_00_1 = 1;
    }
}

void StopKartLevel4EmissionFirstOnly(KartTurnEffects *p) {
    u16 i;

    for (i = 0; i < 2; i++) {
        p->mLevel4FirstEffects[i]->mUnk_24.mUnk_00_1 = 1;
    }
}

void StartKartLevel4EmissionWithSecond(KartTurnEffects *p) {
    u16 i;

    for (i = 0; i < 2; i++) {
        p->mLevel4FirstEffects[i]->mUnk_24.mUnk_00_1 = 0;
        p->mLevel4SecondEffects[i]->mUnk_24.mUnk_00_1 = 0;
    }
}

void StartKartLevel4EmissionFirstOnly(KartTurnEffects *p) {
    u16 i;

    for (i = 0; i < 2; i++) {
        p->mLevel4FirstEffects[i]->mUnk_24.mUnk_00_1 = 0;
    }
}

void ReleaseKartLevel4EffectsWithSecond(KartTurnEffects *p) {
    u16 i;

    for (i = 0; i < 2; i++) {
        func_0208b710(p->mLevel4FirstEffects[i]);
        func_0208b710(p->mLevel4SecondEffects[i]);
        p->mLevel4FirstEffects[i] = NULL;
        p->mLevel4SecondEffects[i] = NULL;
    }
}

void ReleaseKartLevel4EffectsFirstOnly(KartTurnEffects *p) {
    u16 i;

    for (i = 0; i < 2; i++) {
        func_0208b710(p->mLevel4FirstEffects[i]);
        p->mLevel4FirstEffects[i] = NULL;
    }
}

void StopKartLevel4EffectsWithSecond(KartTurnEffects *p) {
    u16 i;

    if (p->mLevel4Present == 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        p->mLevel4FirstEffects[i]->mUnk_24.mUnk_00_1 = 1;
        p->mLevel4SecondEffects[i]->mUnk_24.mUnk_00_1 = 1;
    }
}

void StopKartLevel4EffectsFirstOnly(KartTurnEffects *p) {
    if (p->mLevel4Present == 0) {
        return;
    }
    if (p->mLevel4Present != 0) {
        p->mReleaseLevel4Effects(p);
    }
    p->mLevel4Present = 0;
    p->mLevel4StopFrames = 0;
    p->mLevel4StopRequested = FALSE;
    p->mLevel4RestartFrames = 0;
    p->mLevel4RestartRequested = 0;
}

void PlaceKartLevel4EffectsWithSecond(KartTurnEffects *p, Vec3s16 *a, Vec3 *b) {
    u16 i;
    Unk0201ca6c *e;
    s32 n;

    for (i = 0; i < 2; i++) {
        p->mLevel4FirstEffects[i]->mUnk_50 = a[i];
        p->mLevel4SecondEffects[i]->mUnk_50 = a[i];
        e = p->mLevel4FirstEffects[i];
        n = b[i].x;
        e->mUnk_28.x = n + e->mUnk_20->mUnk_00->mUnk_04.x;
        n = b[i].y;
        e->mUnk_28.y = n + e->mUnk_20->mUnk_00->mUnk_04.y;
        n = b[i].z;
        e->mUnk_28.z = n + e->mUnk_20->mUnk_00->mUnk_04.z;
        e = p->mLevel4SecondEffects[i];
        n = b[i].x;
        e->mUnk_28.x = n + e->mUnk_20->mUnk_00->mUnk_04.x;
        n = b[i].y;
        e->mUnk_28.y = n + e->mUnk_20->mUnk_00->mUnk_04.y;
        n = b[i].z;
        e->mUnk_28.z = n + e->mUnk_20->mUnk_00->mUnk_04.z;
    }
}

void PlaceKartLevel4EffectsFirstOnly(KartTurnEffects *p, Vec3s16 *a, Vec3 *b) {
    u16 i;
    Unk0201ca6c *e;
    s32 t;

    for (i = 0; i < 2; i++) {
        e = p->mLevel4FirstEffects[i];
        e->mUnk_50 = a[i];
        e = p->mLevel4FirstEffects[i];
        t = b[i].x;
        e->mUnk_28.x = t + e->mUnk_20->mUnk_00->mUnk_04.x;
        t = b[i].y;
        e->mUnk_28.y = t + e->mUnk_20->mUnk_00->mUnk_04.y;
        t = b[i].z;
        e->mUnk_28.z = t + e->mUnk_20->mUnk_00->mUnk_04.z;
    }
}

void HideKartTurnStartLevel3Level2Effects(KartTurnEffects *p) {
    u16 i;

    if (p->mTurnStartPresent != 0) {
        for (i = 0; i < 2; i++) {
            p->mTurnStartEffects[i]->mUnk_24.mUnk_00_3 = 1;
        }
    }
    if (p->mLevel3Present != 0) {
        for (i = 0; i < 2; i++) {
            p->mLevel3FirstEffects[i]->mUnk_24.mUnk_00_3 = 1;
            p->mLevel3SecondEffects[i]->mUnk_24.mUnk_00_3 = 1;
        }
    }
    if (p->mLevel2Present == FALSE) {
        return;
    }
    for (i = 0; i < 2; i++) {
        p->mLevel2Effects[i]->mUnk_24.mUnk_00_3 = 1;
    }
}

void HideKartEffectsWithSecond(KartTurnEffects *p) {
    u16 i;

    if (p->mLevel4Present != 0) {
        for (i = 0; i < 2; i++) {
            p->mLevel4FirstEffects[i]->mUnk_24.mUnk_00_3 = 1;
            p->mLevel4SecondEffects[i]->mUnk_24.mUnk_00_3 = 1;
        }
    }
    HideKartTurnStartLevel3Level2Effects(p);
}

void HideKartEffectsFirstOnly(KartTurnEffects *p) {
    u16 i;

    if (p->mLevel4Present != 0) {
        for (i = 0; i < 2; i++) {
            p->mLevel4FirstEffects[i]->mUnk_24.mUnk_00_3 = 1;
        }
    }
    HideKartTurnStartLevel3Level2Effects(p);
}

void ShowKartTurnStartLevel3Level2Effects(KartTurnEffects *p) {
    u16 i;

    if (p->mTurnStartPresent != 0) {
        for (i = 0; i < 2; i++) {
            p->mTurnStartEffects[i]->mUnk_24.mUnk_00_3 = 0;
        }
    }
    if (p->mLevel3Present != 0) {
        for (i = 0; i < 2; i++) {
            p->mLevel3FirstEffects[i]->mUnk_24.mUnk_00_3 = 0;
            p->mLevel3SecondEffects[i]->mUnk_24.mUnk_00_3 = 0;
        }
    }
    if (p->mLevel2Present == FALSE) {
        return;
    }
    for (i = 0; i < 2; i++) {
        p->mLevel2Effects[i]->mUnk_24.mUnk_00_3 = 0;
    }
}

void ShowKartEffectsWithSecond(KartTurnEffects *p) {
    u16 i;

    if (p->mLevel4Present != 0) {
        for (i = 0; i < 2; i++) {
            p->mLevel4FirstEffects[i]->mUnk_24.mUnk_00_3 = 0;
            p->mLevel4SecondEffects[i]->mUnk_24.mUnk_00_3 = 0;
        }
    }
    ShowKartTurnStartLevel3Level2Effects(p);
}

void ShowKartEffectsFirstOnly(KartTurnEffects *p) {
    u16 i;

    if (p->mLevel4Present != 0) {
        for (i = 0; i < 2; i++) {
            p->mLevel4FirstEffects[i]->mUnk_24.mUnk_00_3 = 0;
        }
    }
    ShowKartTurnStartLevel3Level2Effects(p);
}

void ResetKartLevel4Effects(KartTurnEffects *p) {
    if (p->mLevel4Present != 0) {
        p->mReleaseLevel4Effects(p);
    }
    p->mLevel4Present = 0;
    p->mLevel4StopFrames = 0;
    p->mLevel4StopRequested = FALSE;
    p->mLevel4RestartFrames = 0;
    p->mLevel4RestartRequested = 0;
}

void AdvanceKartLevel4Effects(KartTurnEffects *p, Kart *q) {
    KartEffects *e;

    if (p->mLevel4StopRequested != FALSE) {
        p->mLevel4StopFrames++;
        if (p->mLevel4StopFrames > 10) {
            if (p->mLevel4Present != 0) {
                p->mReleaseLevel4Effects(p);
            }
            p->mLevel4Present = 0;
            p->mLevel4StopFrames = 0;
            p->mLevel4StopRequested = FALSE;
            p->mLevel4RestartFrames = 0;
            p->mLevel4RestartRequested = 0;
        }
    }
    if ((q->mUnk_44 & KART_44_DRIFTING) && p->mLevel4RestartRequested != 0) {
        p->mLevel4RestartFrames++;
        if (p->mLevel4RestartFrames > 10) {
            if (p->mLevel4Present != 0) {
                p->mReleaseLevel4Effects(p);
            }
            p->mLevel4Present = 0;
            p->mLevel4StopFrames = 0;
            p->mLevel4StopRequested = FALSE;
            p->mLevel4RestartFrames = 0;
            p->mLevel4RestartRequested = 0;
            p->mStartLevel4Effects(p);
            p->mLevel4Present = 1;
            p->mLevel4RestartFrames = 0;
            p->mLevel4RestartRequested = 0;
        }
    }
    if (p->mLevel4Present == 0) {
        return;
    }
    e = GetKartEffects(q->mIndex);
    p->mPlaceLevel4Effects(p, e->mSideDirections, e->mSidePositions);
    if ((q->mUnk_44 & KART_44_ON_GROUND) == 0) {
        p->mStopLevel4Emission(p);
        return;
    }
    if (p->mLevel4StopRequested == FALSE) {
        p->mStartLevel4Emission(p);
    }
}

void StartKartLevel3Effects(KartTurnEffects *p, int v1) {
    u16 i;

    if (v1 == 0) {
        return;
    }
    if (p->mLevel3Present != 0) {
        for (i = 0; i < 2; i++) {
            func_0208b710(p->mLevel3FirstEffects[i]);
            func_0208b710(p->mLevel3SecondEffects[i]);
            p->mLevel3FirstEffects[i] = NULL;
            p->mLevel3SecondEffects[i] = NULL;
        }
    }
    p->mLevel3Present = 0;
    p->mLevel3Frames = 0;
    for (i = 0; i < 2; i++) {
        p->mLevel3FirstEffects[i] = StartEffect(p->mLevel3FirstEffectId, &data_02155fcc);
        p->mLevel3SecondEffects[i] = StartEffect(p->mLevel3SecondEffectId, &data_02155fcc);
    }
    p->mLevel3Present = 1;
}

void AdvanceKartLevel3Effects(KartTurnEffects *p, Vec3s16 *a, Vec3 *b) {
    u16 i;
    Unk0201ca6c *e;
    s32 n;

    if (p->mLevel3Present == 0) {
        return;
    }
    p->mLevel3Frames++;
    if (p->mLevel3Frames > 10) {
        if (p->mLevel3Present != 0) {
            for (i = 0; i < 2; i++) {
                func_0208b710(p->mLevel3FirstEffects[i]);
                func_0208b710(p->mLevel3SecondEffects[i]);
                p->mLevel3FirstEffects[i] = NULL;
                p->mLevel3SecondEffects[i] = NULL;
            }
        }
        p->mLevel3Present = 0;
        p->mLevel3Frames = 0;
        return;
    }
    for (i = 0; i < 2; i++) {
        p->mLevel3FirstEffects[i]->mUnk_50 = a[i];
        p->mLevel3SecondEffects[i]->mUnk_50 = a[i];
        e = p->mLevel3FirstEffects[i];
        n = b[i].x;
        e->mUnk_28.x = n + e->mUnk_20->mUnk_00->mUnk_04.x;
        n = b[i].y;
        e->mUnk_28.y = n + e->mUnk_20->mUnk_00->mUnk_04.y;
        n = b[i].z;
        e->mUnk_28.z = n + e->mUnk_20->mUnk_00->mUnk_04.z;
        e = p->mLevel3SecondEffects[i];
        n = b[i].x;
        e->mUnk_28.x = n + e->mUnk_20->mUnk_00->mUnk_04.x;
        n = b[i].y;
        e->mUnk_28.y = n + e->mUnk_20->mUnk_00->mUnk_04.y;
        n = b[i].z;
        e->mUnk_28.z = n + e->mUnk_20->mUnk_00->mUnk_04.z;
    }
}

void StartKartLevel2Effects(KartTurnEffects *p, int v1) {
    u16 i;

    if (v1 == 0) {
        return;
    }
    if (p->mLevel2Present != FALSE) {
        for (i = 0; i < 2; i++) {
            func_0208b710(p->mLevel2Effects[i]);
            p->mLevel2Effects[i] = NULL;
        }
    }
    p->mLevel2Present = FALSE;
    p->mLevel2Frames = 0;
    for (i = 0; i < 2; i++) {
        p->mLevel2Effects[i] = StartEffect(0x7e, &data_02155fcc);
    }
    p->mLevel2Present = TRUE;
}

void AdvanceKartLevel2Effects(KartTurnEffects *p, Vec3s16 *a, Vec3 *b) {
    u16 i;
    Unk0201ca6c *e;
    s32 t;

    if (p->mLevel2Present == FALSE) {
        return;
    }
    p->mLevel2Frames++;
    if (p->mLevel2Frames > 8) {
        if (p->mLevel2Present != FALSE) {
            for (i = 0; i < 2; i++) {
                func_0208b710(p->mLevel2Effects[i]);
                p->mLevel2Effects[i] = NULL;
            }
        }
        p->mLevel2Present = FALSE;
        p->mLevel2Frames = 0;
        if (p->mTurnStartPresent == 0) {
            return;
        }
        for (i = 0; i < 2; i++) {
            p->mTurnStartEffects[i]->mUnk_24.mUnk_00_1 = 0;
        }
        return;
    }
    for (i = 0; i < 2; i++) {
        e = p->mLevel2Effects[i];
        e->mUnk_50 = a[i];
        e = p->mLevel2Effects[i];
        t = b[i].x;
        e->mUnk_28.x = t + e->mUnk_20->mUnk_00->mUnk_04.x;
        t = b[i].y;
        e->mUnk_28.y = t + e->mUnk_20->mUnk_00->mUnk_04.y;
        t = b[i].z;
        e->mUnk_28.z = t + e->mUnk_20->mUnk_00->mUnk_04.z;
    }
    if (p->mTurnStartPresent == 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        p->mTurnStartEffects[i]->mUnk_24.mUnk_00_1 = 1;
    }
}

void ReleaseKartTurnEffects(KartTurnEffects *p) {
    u16 i;
    u16 j;

    if (p->mTurnStartPresent != 0) {
        for (i = 0; i < 2; i++) {
            func_0208b6d0(&p->mTurnStartEffects[i]);
        }
    }
    p->mTurnStartPresent = 0;
    if (p->mLevel4Present != 0) {
        p->mReleaseLevel4Effects(p);
    }
    p->mLevel4Present = 0;
    p->mLevel4StopFrames = 0;
    p->mLevel4StopRequested = FALSE;
    p->mLevel4RestartFrames = 0;
    p->mLevel4RestartRequested = 0;
    if (p->mLevel3Present != 0) {
        for (i = 0; i < 2; i++) {
            func_0208b710(p->mLevel3FirstEffects[i]);
            func_0208b710(p->mLevel3SecondEffects[i]);
            p->mLevel3FirstEffects[i] = NULL;
            p->mLevel3SecondEffects[i] = NULL;
        }
    }
    p->mLevel3Present = 0;
    p->mLevel3Frames = 0;
    if (p->mLevel2Present != FALSE) {
        for (j = 0; j < 2; j++) {
            func_0208b710(p->mLevel2Effects[j]);
            p->mLevel2Effects[j] = NULL;
        }
    }
    p->mLevel2Present = FALSE;
    p->mLevel2Frames = 0;
}

KartTurnEffects *GetKartTurnEffects(int v1) {
    return gKartTurnEffects + v1;
}

void StopKartTurnEffects(KartTurnEffects *p) {
    u16 i;

    if (p->mLevel4Present == 0) {
        p->mLevel4StopRequested = FALSE;
    } else {
        p->mStopLevel4Effects(p);
        p->mLevel4StopRequested = TRUE;
    }
    p->mLevel4RestartFrames = 0;
    p->mLevel4RestartRequested = 0;
    if (p->mTurnStartPresent == 0) {
        return;
    }
    for (i = 0; i < 2; i++) {
        p->mTurnStartEffects[i]->mUnk_24.mUnk_00_0 = 1;
        p->mTurnStartEffects[i] = NULL;
    }
    p->mTurnStartPresent = 0;
}
