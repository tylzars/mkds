#include "Main/Unknown/code_020e2fac.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d4c28.h"

#include "Main/Unknown/code_020e2fe4.h"
#include "Main/Unknown/code_020e55b4.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020f8000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020f8ddc.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020e32a0.h"
#include "Main/Unknown/code_020e32a4.h"
#include "Main/Unknown/code_020e3300.h"
#include "Main/Unknown/code_020e331c.h"
#include "Main/Unknown/code_020e3338.h"
#include "Main/Unknown/code_020e337c.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020e34c0.h"
#include "Main/Unknown/code_020e34d0.h"
#include "Main/Unknown/code_020e34ec.h"
#include "Main/Unknown/code_020e34f8.h"
#include "Main/Unknown/code_020e3538.h"
#include "Main/Unknown/code_020e3584.h"
#include "Main/Unknown/code_020e35a0.h"
#include "Main/Unknown/code_020e35e4.h"
#include "Main/Unknown/code_020e35f4.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_020e360c.h"

void SetupDrawChoropuShadow(void) {
    u32 value12;
    func_020e55b4();
}

void DrawChoropuShadow(void *a, Unk020e1e98 *choropu, u32 c, u32 alpha) {
    func_020e54e4(&choropu->mUnk_0b4.mUnk_08, NULL, 0, alpha);
}

void func_020e35e4(u32 arg0, u32 object) {
    u32 value0;
    u32 value1 = object;
    u32 value12;
    value0 = (value1) + (0x80u);
    AdvanceStateMachine((void *) value0);
}

void EnterChoropuState0(Unk020e35a0 *choropu) {
    choropu->mUnk_08 = choropu->mUnk_ac;
    choropu->mUnk_14 = 0x0u;
    choropu->mUnk_02 |= data_02158bb8;
    choropu->mUnk_02 |= data_02158bb4;
}

void UpdateChoropuState0(Unk020e1e98 *choropu) {
    if (choropu->mUnk_000.mStateMachine.mStateFrames >= choropu->mUnk_0a0) {
        choropu->mUnk_000.mStateMachine.mNextState = 1;
        choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterChoropuState1(Unk020e3538 *choropu) {
    choropu->mUnk_08 = choropu->mUnk_ac;
    choropu->mUnk_14 = 0x1000u;
    choropu->mUnk_b8 = 0x0u;
    choropu->mUnk_02 |= data_02158bb8;
    choropu->mUnk_02 |= data_02158bb4;
}

void UpdateChoropuState1(Unk020e1e98 *choropu) {
    choropu->mUnk_000.mPos.y = choropu->mUnk_000.mPos.y + choropu->mUnk_000.mUnk_10.y;
    if (choropu->mUnk_000.mPos.y > choropu->mUnk_0ac + 0x11199) {
        choropu->mUnk_000.mPos.y = choropu->mUnk_0ac + 0x11199;
        choropu->mUnk_000.mStateMachine.mNextState = 2;
        choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterChoropuState2(Unk020e34ec *choropu) {
    choropu->mUnk_14 = 0x0u;
}

void UpdateChoropuState2(Unk020e1e98 *choropu) {
    if (choropu->mUnk_000.mStateMachine.mStateFrames >= 0x14) {
        choropu->mUnk_000.mStateMachine.mNextState = 3;
        choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterChoropuState3(Unk020e34c0 *choropu) {
    choropu->mUnk_14 = ((0x0u) - (0x1000u));
}

void UpdateChoropuState3(Unk020e1e98 *choropu) {
    Unk0210b7a8 soundRequest;
    s32 falloffIndex;

    choropu->mUnk_000.mPos.y = choropu->mUnk_000.mPos.y + choropu->mUnk_000.mUnk_10.y;
    if (choropu->mUnk_000.mPos.y >= choropu->mUnk_0ac) {
        return;
    }
    if ((choropu->mUnk_000.mDistanceSquaredAndFlags & 0x4) == 0) {
        falloffIndex = choropu->mUnk_000.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20
                           ? 2
                           : (choropu->mUnk_000.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20 ? 3 : 4);
        soundRequest.mSoundId = 0x128;
        soundRequest.mPositionSource = &choropu->mUnk_000.mPos;
        soundRequest.mUnk_08 = falloffIndex;
        soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&choropu->mUnk_000.mPos);
        func_0210b7a8(&soundRequest);
    }
    choropu->mUnk_000.mStateMachine.mNextState = 4;
    choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
}

void EnterChoropuState4(Unk020e1e98 *choropu) {
    choropu->mUnk_000.mPos.y = choropu->mUnk_0ac;
    choropu->mUnk_000.mUnk_10.y = 0x4800;
    choropu->mUnk_000.mFlags &= ~0x1;
    if ((choropu->mUnk_000.mDistanceSquaredAndFlags & 0x3) != 0) {
        if (func_0203c5e4() == 0) {
            return;
        }
    }
    StartEffect(0x30, &choropu->mUnk_000.mCourseMapRow->mUnk_00);
}

void UpdateChoropuState4(Unk020e1e98 *choropu) {
    choropu->mUnk_000.mUnk_10.y -= 0x266;
    choropu->mUnk_000.mPos.y = choropu->mUnk_000.mPos.y + choropu->mUnk_000.mUnk_10.y;
    if (choropu->mUnk_000.mPos.y < choropu->mUnk_0b0) {
        choropu->mUnk_000.mStateMachine.mNextState = 5;
        choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
    }
}

// Same body as EnterChoropuState0; this is the enter slot of state 5.
void func_020e3338(Unk020e3338 *choropu) {
    choropu->mUnk_08 = choropu->mUnk_ac;
    choropu->mUnk_14 = 0x0u;
    choropu->mUnk_02 |= data_02158bb8;
    choropu->mUnk_02 |= data_02158bb4;
}

void UpdateChoropuState5(Unk020e1e98 *choropu) {
    if (choropu->mUnk_000.mStateMachine.mStateFrames >= choropu->mUnk_0a4) {
        choropu->mUnk_000.mStateMachine.mNextState = 1;
        choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterChoropuState6(Unk020e1e98 *choropu) {
    choropu->mUnk_000.mFlags = (((choropu->mUnk_000.mFlags)) | ((data_02158bb4)));
}

void UpdateChoropuState6(Unk020e1e98 *choropu) {
    if (choropu->mUnk_0b4.mUnk_00 != 0) {
        choropu->mUnk_0b4.mUnk_04 += 0x400;
    } else {
        choropu->mUnk_0b4.mUnk_04 -= 0x400;
    }
    choropu->mUnk_000.mUnk_10.y -= 0x400;
    choropu->mUnk_000.mPos.y = choropu->mUnk_000.mPos.y + choropu->mUnk_000.mUnk_10.y;
    if (choropu->mUnk_000.mPos.y < choropu->mUnk_0b0) {
        choropu->mUnk_000.mStateMachine.mNextState = 5;
        choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
    }
}

u32 func_020e32a0(u32 value) {
    return value;
}

void UpdateChoropuState7(Unk020e1e98 *choropu) {
    choropu->mUnk_000.mUnk_10.y -= 0x266;
    choropu->mUnk_000.mPos.y = choropu->mUnk_000.mPos.y + choropu->mUnk_000.mUnk_10.y;
    if (choropu->mUnk_000.mPos.y < choropu->mUnk_0b0) {
        Unk020e005c_080 *stateMachine = &choropu->mUnk_000.mStateMachine;

        stateMachine->mNextState = 5;
        stateMachine->mNextStateRequested = 1;
    }
    if (choropu->mUnk_0b4.mUnk_00 != 0) {
        choropu->mUnk_0b4.mUnk_04 += 0x400;
    } else {
        choropu->mUnk_0b4.mUnk_04 -= 0x400;
    }
}

// Case 1 starts state 6 with an upward speed; case 2 starts state 7 unless player kind 2 or already there.
u8 CollideKartWithChoropu(Unk020e1e98 *choropu, Kart *kart, u8 *c, u8 *d) {
    Vec3 offsetFromKart;

    switch (c[0]) {
        case 2:
            if (gRaceSetup->mCurrentEntries[kart->mIndex].mPlayer.mKind == PLAYER_KIND_GHOST) {
                return d[0];
            }
            if (choropu->mUnk_000.mStateMachine.mState == 7) {
                return d[0];
            }
            choropu->mUnk_000.mStateMachine.mNextState = 7;
            choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
            StartSoundIfKartStarOrKiller(&choropu->mUnk_000, kart);
            break;
        case 1:
            VEC_Subtract(&choropu->mUnk_000.mPos, &kart->mPos, &offsetFromKart);
            if ((s64) offsetFromKart.z * kart->mVelocity.x - (s64) offsetFromKart.x * kart->mVelocity.z < 0) {
                choropu->mUnk_0b4.mUnk_00 = 1;
            } else {
                choropu->mUnk_0b4.mUnk_00 = 0;
            }
            choropu->mUnk_000.mUnk_10.y = 0x4000;
            choropu->mUnk_000.mStateMachine.mNextState = 6;
            choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
            choropu->mUnk_000.mFlags |= data_02158bb4;
            StartSoundIfKartStarOrKiller(&choropu->mUnk_000, kart);
            break;
    }
    return d[0];
}

// Case 1 starts state 6 with an upward speed, as CollideKartWithChoropu does for a kart.
u8 CollideItemObjectWithChoropu(Unk020e1e98 *choropu, Unk020e246c *itemObject, u8 *c, u8 *d) {
    Vec3 offsetFromItem;
    Vec3 offset;

    if (c[0] == 1) {
        if (itemObject != NULL) {
            VEC_Subtract(&choropu->mUnk_000.mPos, &itemObject->mUnk_050, &offsetFromItem);
            if ((s64) offsetFromItem.z * itemObject->mUnk_05c - (s64) offsetFromItem.x * itemObject->mUnk_064 < 0) {
                choropu->mUnk_0b4.mUnk_00 = 1;
            } else {
                choropu->mUnk_0b4.mUnk_00 = 0;
            }
            choropu->mUnk_000.mUnk_10.y = 0x4000;
            choropu->mUnk_000.mStateMachine.mNextState = 6;
            choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
            choropu->mUnk_000.mFlags |= data_02158bb4;
            func_020f8ddc(itemObject);
        } else {
            VEC_Subtract(&choropu->mUnk_000.mPos, &choropu->mUnk_000.mPos, &offset);
            if ((s64) offset.z * data_02158c7c.x - (s64) offset.x * data_02158c7c.z < 0) {
                choropu->mUnk_0b4.mUnk_00 = 1;
            } else {
                choropu->mUnk_0b4.mUnk_00 = 0;
            }
            choropu->mUnk_000.mUnk_10.y = 0x4000;
            choropu->mUnk_000.mStateMachine.mNextState = 6;
            choropu->mUnk_000.mStateMachine.mNextStateRequested = 1;
            choropu->mUnk_000.mFlags |= data_02158bb4;
        }
    }
    return d[0];
}

#pragma thumb on

void CreateChoropu(void) {
    void *nsbmdFile;
    void *nsbtpFile;
    nsbmdFile = FindCourseMapObjFile(gChoropuNsbmdName);
    nsbtpFile = FindCourseMapObjFile(gChoropuNsbtpName);
    func_020e6488((NsbmdModel **) (((u32 *) &gChoropu)), nsbmdFile, nsbtpFile, 0);
    func_020e6ab8(gChoropu);
}

#pragma thumb off
