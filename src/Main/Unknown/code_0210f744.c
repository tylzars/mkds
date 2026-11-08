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

void func_021108ac(u32 value) {
    data_0217d1f4 = value;
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
    SeqQueue *queue = &gSeqQueue;
    s32 readIndex;
    s32 pairNo;
    s32 pairSide;
    s32 seqArcNo;
    u32 seqIndex;
    if (queue->mNextStartTimer == 0) {
        readIndex = queue->mReadIndex;
        pairNo = queue->mPairNo[readIndex];
        if (pairNo != 13) {
            pairSide = queue->mPairSide[readIndex];
            seqArcNo = 3;
            if (pairNo == 12) {
                if (pairSide == 0) {
                    seqIndex = 0x47;
                } else {
                    seqIndex = 0x48;
                }
                seqArcNo = 0;
            } else {
                seqIndex = (u16) (pairSide + pairNo * 2);
            }
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, seqArcNo, seqIndex);
            if (data_0217d068 != NULL) {
                SetSndHandleTrackVolume(&data_0217d068, 0x3c);
            }
            gSeqQueue.mPairNo[queue->mReadIndex] = 13;
            data_0217d2dc[queue->mReadIndex] = 2;
            queue->mNextStartTimer = 0x19;
            queue->mReadIndex = queue->mReadIndex + 1;
            readIndex = queue->mReadIndex;
            if (readIndex == 14) {
                readIndex = 0;
            }
            queue->mReadIndex = readIndex;
        }
    }
    if (queue->mNextStartTimer > 0) {
        queue->mNextStartTimer = queue->mNextStartTimer - 1;
    }
}

void AddSeqQueueEntry(u32 pairNo, u32 pairSide) {
    s32 writeIndex;
    s32 nextIndex;
    writeIndex = gSeqQueue.mWriteIndex;
    gSeqQueue.mPairNo[writeIndex] = pairNo;
    nextIndex = writeIndex + 1;
    gSeqQueue.mPairSide[writeIndex] = pairSide;
    if (nextIndex == 14) {
        nextIndex = 0;
    }
    gSeqQueue.mWriteIndex = nextIndex;
}

void func_021106a8(s32 pairNo, s32 pairSide) {
    u16 seqIndex;
    u32 mode;
    mode = 3;
    if (pairNo == 0xc) {
        if (pairSide == 0) {
            seqIndex = 0x47;
        } else {
            seqIndex = 0x48;
        }
        mode = 0;
    } else {
        seqIndex = pairSide + pairNo * 2;
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, mode, seqIndex);
    if (data_0217d068 != NULL) {
        SetSndHandleTrackVolume(&data_0217d068, 100);
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 4);
}

void func_02110698(void) {
    StartSoundOncePerFrame(0);
}

s32 StepValueTowardTarget(Unk0217c7f0 *a, s32 target) {
    s32 currentValue;
    s32 nextValue;
    currentValue = a->mUnk_04 >> 12;
    if (target == currentValue) {
        return -1;
    }
    if (currentValue <= target) {
        nextValue = a->mUnk_04 + a->mUnk_00;
        if ((nextValue >> 12) > target) {
            nextValue = target << 12;
        }
    } else {
        nextValue = a->mUnk_04 - a->mUnk_00;
        if ((nextValue >> 12) < target) {
            nextValue = target << 12;
        }
    }
    a->mUnk_04 = nextValue;
    return a->mUnk_04 >> 12;
}

void InitSoundRequestQueues(void) {
    s32 i;
    SoundRequestQueue *queue;
    for (i = 0, queue = data_0217d26c; i < 7; i++, queue++) {
        s32 capacities[7] = {1, 3, 2, 1, 3, 2, 3};
        InitSoundRequestQueue(queue, capacities[i], data_0217d130);
    }
}

void ResetSoundRequestQueues(void) {
    s32 i;
    SoundRequestQueue *queue;
    for (i = 0, queue = data_0217d26c; i < 7; i++, queue++) {
        ResetSoundRequestQueue(queue);
    }
}

s32 GetLapProgressSoundGap(u32 arg0) {
    u32 value0 = arg0;
    u32 tableAddress;
    tableAddress = (u32) &gLapProgressSoundGaps;
    value0 = *(const u32 *) ((tableAddress) + ((value0 << 2)));
    return value0;
}

u16 GetLapProgressSoundId(int index) {
    return data_0216cba0[index];
}

void SetLapProgressSoundGaps(u32 divisor) {
    s32 i;
    for (i = 0; i < 2; i++) {
        gLapProgressSoundGaps[i] = FX_Div(data_0215c3a4[i], divisor);
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

void func_02110350(Unk020e71a0_94 *mapSound) {
    s32 attenuation;
    attenuation = (s32) (((s64) data_0217d214 * (0x1f000 - func_ov001_02181528()) + 0x800) >> 12) >> 12;
    if (attenuation < 0) {
        attenuation = 0;
    } else if (attenuation > 0x7f) {
        attenuation = 0x7f;
    }
    StartSoundWhileRequested(&mapSound->mSoundSource, 0x231, (0x7f - attenuation) & 0xff, 0);
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
static inline void func_02110114_inline(NNSSndSeqPlayer **handle, s32 v, s32 pitch, s32 targetVolume) {
    s32 m;
    s32 c;
    s32 steppedVolume;
    s32 nextVolume;
    func_02108eb4(1, v);
    NNS_SndPlayerSetTrackPitch(handle, 0xffff, pitch);
    c = gVolumeFade.mVolume >> 12;
    if (targetVolume == c) {
        steppedVolume = -1;
    } else {
        if (c <= targetVolume) {
            nextVolume = gVolumeFade.mVolume + gVolumeFade.mVolumePerFrame;
            if ((nextVolume >> 12) > targetVolume) {
                nextVolume = targetVolume << 12;
            }
        } else {
            nextVolume = gVolumeFade.mVolume - gVolumeFade.mVolumePerFrame;
            if ((nextVolume >> 12) < targetVolume) {
                nextVolume = targetVolume << 12;
            }
        }
        c = nextVolume >> 12;
        steppedVolume = c;
        gVolumeFade.mVolume = nextVolume;
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
    if (steppedVolume != -1) {
        NNS_SndPlayerSetVolume(handle, steppedVolume);
    }
}

void func_02110114(NNSSndSeqPlayer **handle) {
    s32 targetVolume;
    s32 c;
    c = data_0217d20c;
    targetVolume = data_0216cb28;
    switch (c) {
        case 0:
            c = (s32) (((s64) data_0217d210 * (0x29000 - func_ov001_02181528()) + 0x800) >> 12) >> 12;
            targetVolume = 0;
            if (c >= 0) {
                targetVolume = data_0216cb28;
                if (c <= targetVolume) {
                    targetVolume = c;
                }
            }
            break;
        case 1:
            targetVolume = 0;
            break;
        case 2:
            targetVolume = 0;
            break;
        case 5:
            if (data_0217d21c == 2) {
                if (data_0217d1e8 < 0x14) {
                    targetVolume = 0;
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
    if (targetVolume != data_0216cb28) {
        gVolumeFade.mVolumePerFrame = data_0217d224[0];
    } else {
        gVolumeFade.mVolumePerFrame = data_0217d224[1];
    }
    func_02110114_inline(handle, 0x7f, 0, targetVolume);
}

u32 IsSndHandleSet(NNSSndSeqPlayer **handle) {
    if (*handle != NULL) {
        return 1;
    }
    return 0;
}

u32 IsSndHandleSeq(NNSSndSeqPlayer **handle, u32 seqArcNo, u32 index) {
    u32 value0 = (u32) handle;
    u32 value1 = seqArcNo;
    u32 value2 = index;
    u32 value3;
    u32 player;
    u32 compareLeft0;
    u32 compareRight0;
    u32 compareLeft1;
    u32 compareRight1;
    player = *(const u32 *) ((value0) + (0));
    value0 = 0u;
    value3 = *(const u16 *) ((player) + (58));
    compareLeft0 = value3;
    compareRight0 = value2;
    if (compareLeft0 != compareRight0) {
        return value0;
    }
    value2 = *(const u16 *) ((player) + (56));
    compareLeft1 = value2;
    compareRight1 = value1;
    if (compareLeft1 == compareRight1) {
        value0 = 1u;
    }
    return value0;
}

void StopSndHandleSeq(NNSSndSeqPlayer **handle, u32 fadeSteps) {
    NNS_SndPlayerStopSeq(handle, fadeSteps);
}

void func_0211003c(u32 soundId, NNSSndSeqPlayer **handle) {
    if ((data_0217c780 & 1) == 0) {
        return;
    }
    if (data_0217d084.mUnk_0c == 0) {
        return;
    }
    if (*handle != NULL) {
        NNS_SndPlayerStopSeq(handle, 0);
    }
    if (*handle != NULL) {
        NNS_SndPlayerStopSeq(handle, 0);
    }
    NNS_SndArcPlayerStartSeqArc(handle, 0, soundId);
}

// Fades the object at gVolumeFade towards t, then writes the value that was reached.
static inline void func_0210fb88_inline(NNSSndSeqPlayer **handle, s32 v, s32 pitch, s32 targetVolume) {
    s32 m;
    s32 c;
    s32 steppedVolume;
    s32 nextVolume;
    func_02108eb4(1, v);
    NNS_SndPlayerSetTrackPitch(handle, 0xffff, pitch);
    c = gVolumeFade.mVolume >> 12;
    if (targetVolume == c) {
        steppedVolume = -1;
    } else {
        if (c <= targetVolume) {
            nextVolume = gVolumeFade.mVolume + gVolumeFade.mVolumePerFrame;
            if ((nextVolume >> 12) > targetVolume) {
                nextVolume = targetVolume << 12;
            }
        } else {
            nextVolume = gVolumeFade.mVolume - gVolumeFade.mVolumePerFrame;
            if ((nextVolume >> 12) < targetVolume) {
                nextVolume = targetVolume << 12;
            }
        }
        c = nextVolume >> 12;
        steppedVolume = c;
        gVolumeFade.mVolume = nextVolume;
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
    if (steppedVolume != -1) {
        NNS_SndPlayerSetVolume(handle, steppedVolume);
    }
}

void func_0210fb88(SeqPlayerControl *control, NNSSndSeqPlayer **handle) {
    u32 slotVolume;
    s32 targetVolume;
    s32 pitch;
    s32 l;
    s32 slotSeqIndex;
    s32 minKartDistanceSquared;
    s32 y;
    s64 w;
    s32 z;
    NNSSndSeqPlayer **slotHandle;
    pitch = 0;
    slotVolume = pitch;
    l = 0x7f;
    slotSeqIndex = -1;
    if (control->mVolumeOverride > 0) {
        switch (control->mVolumeOverride) {
            case 1:
                l = pitch;
                break;
            case 2:
                break;
        }
        func_0210fb88_inline(handle, 0x7f, 0, l);
        return;
    }
    if (data_0217d1ec != 0) {
        func_02110114(handle);
        return;
    }
    control->mKartNear =
        (TryGetMinKartDistanceSquared(&minKartDistanceSquared) != FALSE && minKartDistanceSquared < 0x8d04) ? 1 : 0;
    if ((control->mFlags >> 2) & 1) {
        targetVolume = 0;
        l = 0x1e;
        slotSeqIndex = 0xff;
        slotVolume = 0x7f;
    } else if (control->mKartNear != 0) {
        y = (minKartDistanceSquared - 2500) << 12;
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
        slotVolume = (0x9d - l) & 0xff;
        targetVolume = z + 0x14;
        slotSeqIndex = 0xfe;
        if (targetVolume < 0) {
            targetVolume = 0;
        } else if (targetVolume > 0x7f) {
            targetVolume = 0x7f;
        }
    } else {
        targetVolume = data_0216cb28;
    }
    if (gSceneSoundState.mRaceState != 1) {
        pitch = 0;
    } else if ((control->mFlags >> 1) & 1) {
        control->mPitchAngle += 0x1111;
        control->mPitchAngle &= 0xffff;
        pitch = (s32) (((s64) gPairsByAngle[(control->mPitchAngle >> 4) * 2] * 0x30000 + 0x800) >> 12) >> 12;
        pitch += 0x80;
        if (targetVolume > 0x3c) {
            targetVolume = 0x3c;
        }
    } else if ((control->mFlags >> 3) & 1) {
        pitch = 0x40;
        if (targetVolume == data_0216cb28) {
            targetVolume = data_0216cb28 - 10;
        }
    }
    func_0210fb88_inline(handle, l, pitch, targetVolume);
    slotHandle = GetSndHandleSlot(5);
    if (slotSeqIndex != -1 && slotVolume != 0) {
        l = IsSndHandleSet(slotHandle);
        if (l != 0 && IsSndHandleSeq(slotHandle, 0, slotSeqIndex) == 0) {
            StopSndHandleSeq(slotHandle, 0);
            func_0211003c(slotSeqIndex & 0xff, slotHandle);
        } else if (l == 0) {
            func_0211003c(slotSeqIndex & 0xff, slotHandle);
        }
        if (IsSndHandleSet(slotHandle) == 0) {
            return;
        }
        if (slotVolume > 0x7f) {
            slotVolume = 0x7f;
        }
        SetSndHandleTrackVolume(slotHandle, slotVolume);
    } else {
        if (IsSndHandleSet(slotHandle) == 0) {
            return;
        }
        StopSndHandleSeq(slotHandle, 0x1e);
    }
}

u32 func_0210fb68(void) {
    u32 controlAddress;
    u32 zero;
    controlAddress = (u32) &data_0217d244;
    zero = 0u;
    data_0217d244.mPitchAngle = zero;
    data_0217d244.mFlags = zero;
    data_0217d244.mKartNear = zero;
    data_0217d244.mVolumeOverride = zero;
    return controlAddress;
}

u32 func_0210fb54(void) {
    u32 controlAddress;
    u32 overrideValue;
    controlAddress = (u32) &data_0217d244;
    overrideValue = 1u;
    data_0217d244.mVolumeOverride = overrideValue;
    return controlAddress;
}

void func_0210fb10(void) {
    NNSSndSeqPlayer **handle;
    handle = &data_0217d07c;
    *((u32 *) ((u32) (&data_0217d244))) = 2;
    NNS_SndPlayerSetTrackMuteEx(handle, 1, 1);
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
    u32 kartNear;
    kartNear = data_0217d244.mKartNear;
    return kartNear;
}

u32 func_0210faac(void) {
    u32 controlAddress;
    u32 flags;
    controlAddress = (u32) &data_0217d244;
    flags = data_0217d244.mFlags;
    flags = (flags) | (8u);
    data_0217d244.mFlags = flags;
    return controlAddress;
}

void func_0210fa74(u32 enabled) {
    if (enabled == 1) {
        data_0217d244.mFlags |= 2;
    } else {
        data_0217d244.mFlags &= ~2;
    }
    data_0217d244.mPitchAngle = 0;
}

void func_0210fa40(u32 enabled, u32 b) {
    if (b == 0) {
        return;
    }
    if (enabled == 1) {
        data_0217d244.mFlags |= 4;
    } else {
        data_0217d244.mFlags &= ~4;
    }
}

u32 func_0210fa3c(u32 value) {
    return value;
}

u32 func_0210fa28(void) {
    u32 counterAddress;
    u32 zero;
    counterAddress = (u32) &data_0217d1f0;
    zero = 0u;
    *(u32 *) ((counterAddress) + (0)) = zero;
    return counterAddress;
}

void func_0210f9f0(void *kartAddress, int b) {
    Kart *kart = kartAddress;
    u32 counter = data_0217d1f0;
    data_0217d1f0 = counter + 1;
    StartSound(&kart->mSoundSource, counter + 0xea, 0x7f, 0);
}

void func_0210f9ac(Kart *kart) {
    AddSoundRequest(&data_0217d28c, func_02086080(kart->mIndex), func_0210f9f0, kart, 0);
}

void func_0210f8b0(SoundSetPlayer *player, s32 seqId, s32 firstBankId) {
    u8 i;
    s32 j;
    ReleaseLoadedSoundSet();
    if (seqId == 4) {
        firstBankId = 0x23;
    }
    InitSoundSetPlayer(player, seqId, firstBankId, 0xff, GetLoadedSoundSet());
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

void SetSeqVariableEnabled(u32 slot, u32 enabled) {
    s32 i;
    gSeqVariableEnabled[slot] = enabled;
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
void UpdateSeqVariableReadings(NNSSndSeqPlayer **handle) {
    SeqVariableReading *reading;
    s32 i;

    for (i = 0; i < 2; i++) {
        reading = &gSeqVariableReadings[i];
        if (gSeqVariableEnabled[i] == 0) {
            continue;
        }
        if (NNS_SndPlayerReadVariable(handle, reading->mVariableNo[0], (s16 *) reading) == 0) {
            continue;
        }
        if (reading->mPrevValue != reading->mValue) {
            reading->mSinceChangeFrames = 0;
        } else {
            if (reading->mSinceChangeFrames >= 0) {
                reading->mSinceChangeFrames++;
            }
        }
        reading->mPrevValue = reading->mValue;
    }
}

u32 IsSeqVariableChanged(u32 slot) {
    return gSeqVariableReadings[slot].mSinceChangeFrames == 0;
}

u32 GetSeqVariableSinceChangeFrames(u32 slot) {
    return gSeqVariableReadings[slot].mSinceChangeFrames;
}
