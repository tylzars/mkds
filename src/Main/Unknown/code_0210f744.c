#include "Main/Unknown/code_0210f744.h"
#include "Main/Unknown/code_02109054.h"

#include "Main/Unknown/unk_0217d000.h"
#include "code_0212bcac.h"
#include "Main/Unknown/code_0210f858.h"
#include "Main/Unknown/code_0210f868.h"
#include "Main/Unknown/code_0210e33c.h"
#include "Main/Unknown/code_02108950.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0210fa28.h"
#include "Main/Unknown/code_0210fa3c.h"
#include "Main/Unknown/code_0210fa40.h"
#include "Main/Unknown/code_0210faac.h"
#include "Main/Unknown/code_0210fad4.h"
#include "Main/Unknown/code_0210fb88.h"
#include "Main/Unknown/code_0210fb10.h"
#include "Main/Unknown/code_0210fb54.h"
#include "Main/Unknown/code_02110100.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_02108eb4.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_021100dc.h"
#include "Main/Unknown/code_0207a000.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02110484.h"
#include "Main/Unknown/code_02110534.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/code_0211057c.h"
#include "Main/Unknown/code_02110590.h"
#include "Main/Unknown/code_021105a0.h"
#include "Main/Unknown/code_021106a8.h"
#include "Main/Unknown/code_02110720.h"
#include "Main/Unknown/code_021108bc.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_021108ac.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02086058.h"
#include "01/code_021813f4.h"

void func_021108ac(u32 p0) {
    data_0217d1f4 = p0;
}

void func_02110874(void) {
    s32 a;
    a = data_0217d1f4;
    if (a == 7) {
        a = 6;
    }
    func_021108bc(a);
    data_0217d1f4 = 7;
}

void ResetSeqQueue(void) {
    s32 i;
    i = 0;
    gSeqQueue.mNextStartTimer = i;
    gSeqQueue.mWriteIndex = i;
    gSeqQueue.mReadIndex = i;
    for (i = 0; i < 14; i++) {
        gSeqQueue.mPairNo[i] = 13;
        gSeqQueue.mPairSide[i] = 2;
    }
}

// Starts the next queued seq once the delay since the previous start has run out.
void UpdateSeqQueue(void) {
    SeqQueue *p = &gSeqQueue;
    s32 i;
    s32 v;
    s32 w;
    s32 t;
    u32 x;
    if (p->mNextStartTimer == 0) {
        i = p->mReadIndex;
        v = p->mPairNo[i];
        if (v != 13) {
            w = p->mPairSide[i];
            t = 3;
            if (v == 12) {
                if (w == 0) {
                    x = 0x47;
                } else {
                    x = 0x48;
                }
                t = 0;
            } else {
                x = (u16) (w + v * 2);
            }
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, t, x);
            if (data_0217d068 != NULL) {
                SetSndHandleTrackVolume(&data_0217d068, 0x3c);
            }
            gSeqQueue.mPairNo[p->mReadIndex] = 13;
            data_0217d2dc[p->mReadIndex] = 2;
            p->mNextStartTimer = 0x19;
            p->mReadIndex = p->mReadIndex + 1;
            i = p->mReadIndex;
            if (i == 14) {
                i = 0;
            }
            p->mReadIndex = i;
        }
    }
    if (p->mNextStartTimer > 0) {
        p->mNextStartTimer = p->mNextStartTimer - 1;
    }
}

void AddSeqQueueEntry(u32 a, u32 b) {
    s32 i;
    s32 n;
    i = gSeqQueue.mWriteIndex;
    gSeqQueue.mPairNo[i] = a;
    n = i + 1;
    gSeqQueue.mPairSide[i] = b;
    if (n == 14) {
        n = 0;
    }
    gSeqQueue.mWriteIndex = n;
}

void func_021106a8(s32 a, s32 b) {
    u16 id;
    u32 mode;
    mode = 3;
    if (a == 0xc) {
        if (b == 0) {
            id = 0x47;
        } else {
            id = 0x48;
        }
        mode = 0;
    } else {
        id = b + a * 2;
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, mode, id);
    if (data_0217d068 != NULL) {
        SetSndHandleTrackVolume(&data_0217d068, 100);
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 4);
}

void func_02110698(void) {
    StartSoundOncePerFrame(0);
}

s32 StepValueTowardTarget(Unk0217c7f0 *a, s32 b) {
    s32 c;
    s32 d;
    c = a->mUnk_04 >> 12;
    if (b == c) {
        return -1;
    }
    if (c <= b) {
        d = a->mUnk_04 + a->mUnk_00;
        if ((d >> 12) > b) {
            d = b << 12;
        }
    } else {
        d = a->mUnk_04 - a->mUnk_00;
        if ((d >> 12) < b) {
            d = b << 12;
        }
    }
    a->mUnk_04 = d;
    return a->mUnk_04 >> 12;
}

void func_021105d8(void) {
    s32 i;
    Unk0217d26c *p;
    for (i = 0, p = data_0217d26c; i < 7; i++, p++) {
        s32 t[7] = {1, 3, 2, 1, 3, 2, 3};
        func_0210e094(p, t[i], data_0217d130);
    }
}

void func_021105a0(void) {
    s32 i;
    Unk0217d26c *p;
    for (i = 0, p = data_0217d26c; i < 7; i++, p++) {
        func_0210e03c(p);
    }
}

s32 GetLapProgressSoundGap(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) &gLapProgressSoundGaps;
    value0 = *(const u32 *) ((value1) + ((value0 << 2)));
    return value0;
}

u16 GetLapProgressSoundId(int a) {
    return data_0216cba0[a];
}

void SetLapProgressSoundGaps(u32 a) {
    s32 i;
    for (i = 0; i < 2; i++) {
        gLapProgressSoundGaps[i] = FX_Div(data_0215c3a4[i], a);
    }
}

void func_021104dc(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value4;
    u32 value5;
    u32 value12;
    u32 value14;
    value14 = (u32) &data_0217d1ec;
    value12 = (u32) &data_0217d20c;
    value5 = 3u;
    value3 = (u32) &data_0217d1f8;
    value2 = (u32) &data_0217d21c;
    value1 = (u32) &data_0217d1e8;
    value4 = 0u;
    *(u32 *) ((value14) + (0)) = value0;
    *(u32 *) ((value12) + (0)) = value5;
    *(u32 *) ((value3) + (0)) = value5;
    *(u32 *) ((value2) + (0)) = value5;
    *(u32 *) ((value1) + (0)) = value4;
}

u32 func_02110484(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value0 = (u32) &data_0216cb28;
    value1 = 0x8340000u;
    value0 = *(const u32 *) ((value0) + (0));
    value0 = (value0) - (0x14u);
    value0 = (value0 << 12);
    value0 = FX_Div(value0, value1);
    value2 = (u32) &data_0217d200;
    value1 = 0x8340000u;
    *(u32 *) ((value2) + (0)) = value0;
    value0 = 0x61000u;
    value0 = FX_Div(value0, value1);
    value1 = (u32) &data_0217d208;
    *(u32 *) ((value1) + (0)) = value0;
    return value0;
}

void func_021103c0(void) {
    data_0217d1fc = FX_Div(0x7f000, 0x1e000);
    data_0217d224[0] = FX_Div(0x7f000, 0x1e000);
    data_0217d224[1] = FX_Div(0x7f000, 0x5a000);
    data_0217d210 = FX_Div(data_0216cb28 << 12, 0x23000);
    data_0217d214 = FX_Div(0x7f000, 0x19000);
    gVolumeFade.mVolumePerFrame = data_0217d1fc;
    gVolumeFade.mVolume = 0x7f000;
    data_0217d218 = data_0216cb28;
}

void func_02110350(Unk020e71a0_94 *a) {
    s32 v;
    v = (s32) (((s64) data_0217d214 * (0x1f000 - func_ov001_02181528()) + 0x800) >> 12) >> 12;
    if (v < 0) {
        v = 0;
    } else if (v > 0x7f) {
        v = 0x7f;
    }
    StartSoundWhileRequested(&a->mSoundSource, 0x231, (0x7f - v) & 0xff, 0);
}

u32 func_02110324(void) {
    u32 a;
    u32 b;
    a = 0;
    b = data_0217d20c;
    if (b <= 5) {
        if ((1 << b) & 0x25) {
            a = 1;
        }
    }
    return a;
}

// Moves the object at gVolumeFade towards t.
static inline void func_02110114_inline(NNSSndSeqPlayer **p, s32 v, s32 k, s32 t) {
    s32 m;
    s32 c;
    s32 r;
    s32 x;
    func_02108eb4(1, v);
    NNS_SndPlayerSetTrackPitch(p, 0xffff, k);
    c = gVolumeFade.mVolume >> 12;
    if (t == c) {
        r = -1;
    } else {
        if (c <= t) {
            x = gVolumeFade.mVolume + gVolumeFade.mVolumePerFrame;
            if ((x >> 12) > t) {
                x = t << 12;
            }
        } else {
            x = gVolumeFade.mVolume - gVolumeFade.mVolumePerFrame;
            if ((x >> 12) < t) {
                x = t << 12;
            }
        }
        c = x >> 12;
        r = c;
        gVolumeFade.mVolume = x;
    }
    data_0217d218 = c;
    m = data_0216cb28;
    if (c <= m) {
        if (c < 0) {
            c = 0;
        }
        m = c;
    }
    data_0217d218 = m;
    if (r != -1) {
        NNS_SndPlayerSetVolume(p, r);
    }
}

void func_02110114(NNSSndSeqPlayer **a) {
    s32 b;
    s32 c;
    c = data_0217d20c;
    b = data_0216cb28;
    switch (c) {
        case 0:
            c = (s32) (((s64) data_0217d210 * (0x29000 - func_ov001_02181528()) + 0x800) >> 12) >> 12;
            b = 0;
            if (c >= 0) {
                b = data_0216cb28;
                if (c <= b) {
                    b = c;
                }
            }
            break;
        case 1:
            b = 0;
            break;
        case 2:
            b = 0;
            break;
        case 5:
            if (data_0217d21c == 2) {
                if (data_0217d1e8 < 0x14) {
                    b = 0;
                }
            }
            break;
        case 7:
            break;
    }
    if (data_0217d1f8 != data_0217d20c) {
        data_0217d1e8 = 0;
    } else {
        data_0217d1e8++;
    }
    if (b != data_0216cb28) {
        gVolumeFade.mVolumePerFrame = data_0217d224[0];
    } else {
        gVolumeFade.mVolumePerFrame = data_0217d224[1];
    }
    func_02110114_inline(a, 0x7f, 0, b);
}

u32 IsSndHandleSet(NNSSndSeqPlayer **a) {
    if (*a != NULL) {
        return 1;
    }
    return 0;
}

u32 IsSndHandleSeq(NNSSndSeqPlayer **arg0, u32 arg1, u32 arg2) {
    u32 value0 = (u32) arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value3;
    u32 value12;
    u32 compareLeft0;
    u32 compareRight0;
    u32 compareLeft1;
    u32 compareRight1;
    value12 = *(const u32 *) ((value0) + (0));
    value0 = 0u;
    value3 = *(const u16 *) ((value12) + (58));
    compareLeft0 = value3;
    compareRight0 = value2;
    if (compareLeft0 != compareRight0) {
        return value0;
    }
    value2 = *(const u16 *) ((value12) + (56));
    compareLeft1 = value2;
    compareRight1 = value1;
    if (compareLeft1 == compareRight1) {
        value0 = 1u;
    }
    return value0;
}

void StopSndHandleSeq(NNSSndSeqPlayer **a, u32 b) {
    NNS_SndPlayerStopSeq(a, b);
}

void func_0211003c(u32 a, NNSSndSeqPlayer **b) {
    if ((data_0217c780 & 1) == 0) {
        return;
    }
    if (data_0217d084.mUnk_0c == 0) {
        return;
    }
    if (*b != NULL) {
        NNS_SndPlayerStopSeq(b, 0);
    }
    if (*b != NULL) {
        NNS_SndPlayerStopSeq(b, 0);
    }
    NNS_SndArcPlayerStartSeqArc(b, 0, a);
}

// Fades the object at gVolumeFade towards t, then writes the value that was reached.
static inline void func_0210fb88_inline(NNSSndSeqPlayer **p, s32 v, s32 k, s32 t) {
    s32 m;
    s32 c;
    s32 r;
    s32 x;
    func_02108eb4(1, v);
    NNS_SndPlayerSetTrackPitch(p, 0xffff, k);
    c = gVolumeFade.mVolume >> 12;
    if (t == c) {
        r = -1;
    } else {
        if (c <= t) {
            x = gVolumeFade.mVolume + gVolumeFade.mVolumePerFrame;
            if ((x >> 12) > t) {
                x = t << 12;
            }
        } else {
            x = gVolumeFade.mVolume - gVolumeFade.mVolumePerFrame;
            if ((x >> 12) < t) {
                x = t << 12;
            }
        }
        c = x >> 12;
        r = c;
        gVolumeFade.mVolume = x;
    }
    data_0217d218 = c;
    m = data_0216cb28;
    if (c <= m) {
        if (c < 0) {
            c = 0;
        }
        m = c;
    }
    data_0217d218 = m;
    if (r != -1) {
        NNS_SndPlayerSetVolume(p, r);
    }
}

void func_0210fb88(Unk0217d244 *a, NNSSndSeqPlayer **b) {
    u32 i;
    s32 j;
    s32 k;
    s32 l;
    s32 n;
    s32 x;
    s32 y;
    s64 w;
    s32 z;
    NNSSndSeqPlayer **p;
    k = 0;
    i = k;
    l = 0x7f;
    n = -1;
    if (a->mVolumeOverride > 0) {
        switch (a->mVolumeOverride) {
            case 1:
                l = k;
                break;
            case 2:
                break;
        }
        func_0210fb88_inline(b, 0x7f, 0, l);
        return;
    }
    if (data_0217d1ec != 0) {
        func_02110114(b);
        return;
    }
    a->mKartNear = (TryGetMinKartDistanceSquared(&x) != FALSE && x < 0x8d04) ? 1 : 0;
    if ((a->mFlags >> 2) & 1) {
        j = 0;
        l = 0x1e;
        n = 0xff;
        i = 0x7f;
    } else if (a->mKartNear != 0) {
        y = (x - 2500) << 12;
        w = y;
        z = (s32) (((s64) data_0217d208 * y + 0x800) >> 12) >> 12;
        z += 0x1e;
        if (z < 0) {
            z = 0;
        } else if (z > 0x7f) {
            z = 0x7f;
        }
        l = z & 0xff;
        z = (s32) ((data_0217d200 * w + 0x800) >> 12) >> 12;
        i = (0x9d - l) & 0xff;
        j = z + 0x14;
        n = 0xfe;
        if (j < 0) {
            j = 0;
        } else if (j > 0x7f) {
            j = 0x7f;
        }
    } else {
        j = data_0216cb28;
    }
    if (gSceneSoundState.mRaceState != 1) {
        k = 0;
    } else if ((a->mFlags >> 1) & 1) {
        a->mPitchAngle += 0x1111;
        a->mPitchAngle &= 0xffff;
        k = (s32) (((s64) gPairsByAngle[(a->mPitchAngle >> 4) * 2] * 0x30000 + 0x800) >> 12) >> 12;
        k += 0x80;
        if (j > 0x3c) {
            j = 0x3c;
        }
    } else if ((a->mFlags >> 3) & 1) {
        k = 0x40;
        if (j == data_0216cb28) {
            j = data_0216cb28 - 10;
        }
    }
    func_0210fb88_inline(b, l, k, j);
    p = GetSndHandleSlot(5);
    if (n != -1 && i != 0) {
        l = IsSndHandleSet(p);
        if (l != 0 && IsSndHandleSeq(p, 0, n) == 0) {
            StopSndHandleSeq(p, 0);
            func_0211003c(n & 0xff, p);
        } else if (l == 0) {
            func_0211003c(n & 0xff, p);
        }
        if (IsSndHandleSet(p) == 0) {
            return;
        }
        if (i > 0x7f) {
            i = 0x7f;
        }
        SetSndHandleTrackVolume(p, i);
    } else {
        if (IsSndHandleSet(p) == 0) {
            return;
        }
        StopSndHandleSeq(p, 0x1e);
    }
}

u32 func_0210fb68(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217d244;
    value1 = 0u;
    data_0217d244.mPitchAngle = value1;
    data_0217d244.mFlags = value1;
    data_0217d244.mKartNear = value1;
    data_0217d244.mVolumeOverride = value1;
    return value0;
}

u32 func_0210fb54(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217d244;
    value1 = 1u;
    data_0217d244.mVolumeOverride = value1;
    return value0;
}

void func_0210fb10(void) {
    NNSSndSeqPlayer **v1;
    v1 = &data_0217d07c;
    *((u32 *) ((u32) (&data_0217d244))) = 2;
    NNS_SndPlayerSetTrackMuteEx(v1, 1, 1);
    NNS_SndPlayerSetTempoRatio(&data_0217d07c, 0xd9);
}

void func_0210faf4(void) {
    func_0210fb88(&data_0217d244, &data_0217d07c);
}

u32 IsThunderShrinkFlagSet(void) {
    if ((data_0217d244.mFlags >> 2) & 1) {
        return 1;
    }
    return 0;
}

u32 IsKartNear(void) {
    u32 value0;
    value0 = data_0217d244.mKartNear;
    return value0;
}

u32 func_0210faac(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217d244;
    value1 = data_0217d244.mFlags;
    value1 = (value1) | (8u);
    data_0217d244.mFlags = value1;
    return value0;
}

void func_0210fa74(u32 a) {
    if (a == 1) {
        data_0217d244.mFlags |= 2;
    } else {
        data_0217d244.mFlags &= ~2;
    }
    data_0217d244.mPitchAngle = 0;
}

void func_0210fa40(u32 a, u32 b) {
    if (b == 0) {
        return;
    }
    if (a == 1) {
        data_0217d244.mFlags |= 4;
    } else {
        data_0217d244.mFlags &= ~4;
    }
}

u32 func_0210fa3c(u32 p0) {
    return p0;
}

u32 func_0210fa28(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217d1f0;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void func_0210f9f0(void *a0, int b) {
    Kart *a = a0;
    u32 v = data_0217d1f0;
    data_0217d1f0 = v + 1;
    StartSound(&a->mSoundSource, v + 0xea, 0x7f, 0);
}

void func_0210f9ac(Kart *a) {
    func_0210ddf4(&data_0217d28c, func_02086080(a->mIndex), func_0210f9f0, a, 0);
}

void func_0210f8b0(Unk0217d060 *a, s32 b, s32 c) {
    u8 i;
    s32 j;
    ReleaseLoadedSoundSet();
    if (b == 4) {
        c = 0x23;
    }
    func_0210dccc(a, b, c, 0xff, func_02108950());
    for (i = 0; i < 2; i++) {
        gSeqVariableReadings[i].mValue = -1;
        gSeqVariableReadings[i].mPrevValue = -1;
        gSeqVariableReadings[i].mSinceChangeFrames = -1;
        gSeqVariableReadings[i].mVariableNo[0] = i;
    }
    gSeqVariableEnabled[0] = 1;
    for (j = 0; j < 2; j++) {
        if (gSeqVariableEnabled[j] == 1) {
            break;
        }
    }
    gSeqVariableEnabled[1] = 1;
    for (j = 0; j < 2; j++) {
        if (gSeqVariableEnabled[j] == 1) {
            gAnySeqVariableEnabled = 1;
            return;
        }
    }
    gAnySeqVariableEnabled = 0;
}

void SetSeqVariableEnabled(u32 a, u32 b) {
    s32 i;
    gSeqVariableEnabled[a] = b;
    for (i = 0; i < 2; i++) {
        if (gSeqVariableEnabled[i] == 1) {
            gAnySeqVariableEnabled = 1;
            return;
        }
    }
    gAnySeqVariableEnabled = 0;
}

u32 IsAnySeqVariableEnabled(void) {
    return gAnySeqVariableEnabled;
}

void ResetSeqVariableReadings(void) {
    u8 i;

    for (i = 0; i < 2; i++) {
        gSeqVariableReadings[i].mValue = -1;
        gSeqVariableReadings[i].mPrevValue = -1;
        gSeqVariableReadings[i].mSinceChangeFrames = -1;
        gSeqVariableReadings[i].mVariableNo[0] = i;
    }
}

// Reads each enabled slot's sequence variable and counts the updates since it last changed.
void UpdateSeqVariableReadings(NNSSndSeqPlayer **a) {
    SeqVariableReading *p;
    s32 i;

    for (i = 0; i < 2; i++) {
        p = &gSeqVariableReadings[i];
        if (gSeqVariableEnabled[i] == 0) {
            continue;
        }
        if (NNS_SndPlayerReadVariable(a, p->mVariableNo[0], (s16 *) p) == 0) {
            continue;
        }
        if (p->mPrevValue != p->mValue) {
            p->mSinceChangeFrames = 0;
        } else {
            if (p->mSinceChangeFrames >= 0) {
                p->mSinceChangeFrames++;
            }
        }
        p->mPrevValue = p->mValue;
    }
}

u32 IsSeqVariableChanged(u32 a) {
    return gSeqVariableReadings[a].mSinceChangeFrames == 0;
}

u32 GetSeqVariableSinceChangeFrames(u32 a) {
    return gSeqVariableReadings[a].mSinceChangeFrames;
}
