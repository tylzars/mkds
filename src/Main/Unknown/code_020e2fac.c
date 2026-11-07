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

void DrawChoropuShadow(void *a, Unk020e1e98 *b, u32 c, u32 d) {
    func_020e54e4(&b->mUnk_0b4.mUnk_08, NULL, 0, d);
}

void func_020e35e4(u32 arg0, u32 arg1) {
    u32 value0;
    u32 value1 = arg1;
    u32 value12;
    value0 = (value1) + (0x80u);
    AdvanceStateMachine((void *) value0);
}

void EnterChoropuState0(Unk020e35a0 *p0) {
    p0->mUnk_08 = p0->mUnk_ac;
    p0->mUnk_14 = 0x0u;
    p0->mUnk_02 |= data_02158bb8;
    p0->mUnk_02 |= data_02158bb4;
}

void UpdateChoropuState0(Unk020e1e98 *a) {
    if (a->mUnk_000.mStateMachine.mStateFrames >= a->mUnk_0a0) {
        a->mUnk_000.mStateMachine.mNextState = 1;
        a->mUnk_000.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterChoropuState1(Unk020e3538 *p0) {
    p0->mUnk_08 = p0->mUnk_ac;
    p0->mUnk_14 = 0x1000u;
    p0->mUnk_b8 = 0x0u;
    p0->mUnk_02 |= data_02158bb8;
    p0->mUnk_02 |= data_02158bb4;
}

void UpdateChoropuState1(Unk020e1e98 *a) {
    a->mUnk_000.mPos.y = a->mUnk_000.mPos.y + a->mUnk_000.mUnk_10.y;
    if (a->mUnk_000.mPos.y > a->mUnk_0ac + 0x11199) {
        a->mUnk_000.mPos.y = a->mUnk_0ac + 0x11199;
        a->mUnk_000.mStateMachine.mNextState = 2;
        a->mUnk_000.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterChoropuState2(Unk020e34ec *p0) {
    p0->mUnk_14 = 0x0u;
}

void UpdateChoropuState2(Unk020e1e98 *a) {
    if (a->mUnk_000.mStateMachine.mStateFrames >= 0x14) {
        a->mUnk_000.mStateMachine.mNextState = 3;
        a->mUnk_000.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterChoropuState3(Unk020e34c0 *p0) {
    p0->mUnk_14 = ((0x0u) - (0x1000u));
}

void UpdateChoropuState3(Unk020e1e98 *a) {
    Unk0210b7a8 buf;
    s32 v;

    a->mUnk_000.mPos.y = a->mUnk_000.mPos.y + a->mUnk_000.mUnk_10.y;
    if (a->mUnk_000.mPos.y >= a->mUnk_0ac) {
        return;
    }
    if ((a->mUnk_000.mDistanceSquaredAndFlags & 0x4) == 0) {
        v = a->mUnk_000.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20
                ? 2
                : (a->mUnk_000.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20 ? 3 : 4);
        buf.mUnk_00 = 0x128;
        buf.mUnk_04 = &a->mUnk_000.mPos;
        buf.mUnk_08 = v;
        buf.mUnk_0c = GetHorizontalCameraDistanceSquared(&a->mUnk_000.mPos);
        func_0210b7a8(&buf);
    }
    a->mUnk_000.mStateMachine.mNextState = 4;
    a->mUnk_000.mStateMachine.mNextStateRequested = 1;
}

void EnterChoropuState4(Unk020e1e98 *a) {
    a->mUnk_000.mPos.y = a->mUnk_0ac;
    a->mUnk_000.mUnk_10.y = 0x4800;
    a->mUnk_000.mFlags &= ~0x1;
    if ((a->mUnk_000.mDistanceSquaredAndFlags & 0x3) != 0) {
        if (func_0203c5e4() == 0) {
            return;
        }
    }
    StartEffect(0x30, &a->mUnk_000.mCourseMapRow->mUnk_00);
}

void UpdateChoropuState4(Unk020e1e98 *a) {
    a->mUnk_000.mUnk_10.y -= 0x266;
    a->mUnk_000.mPos.y = a->mUnk_000.mPos.y + a->mUnk_000.mUnk_10.y;
    if (a->mUnk_000.mPos.y < a->mUnk_0b0) {
        a->mUnk_000.mStateMachine.mNextState = 5;
        a->mUnk_000.mStateMachine.mNextStateRequested = 1;
    }
}

// Same body as EnterChoropuState0; this is the enter slot of state 5.
void func_020e3338(Unk020e3338 *p0) {
    p0->mUnk_08 = p0->mUnk_ac;
    p0->mUnk_14 = 0x0u;
    p0->mUnk_02 |= data_02158bb8;
    p0->mUnk_02 |= data_02158bb4;
}

void UpdateChoropuState5(Unk020e1e98 *a) {
    if (a->mUnk_000.mStateMachine.mStateFrames >= a->mUnk_0a4) {
        a->mUnk_000.mStateMachine.mNextState = 1;
        a->mUnk_000.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterChoropuState6(Unk020e1e98 *p0) {
    p0->mUnk_000.mFlags = (((p0->mUnk_000.mFlags)) | ((data_02158bb4)));
}

void UpdateChoropuState6(Unk020e1e98 *a) {
    if (a->mUnk_0b4.mUnk_00 != 0) {
        a->mUnk_0b4.mUnk_04 += 0x400;
    } else {
        a->mUnk_0b4.mUnk_04 -= 0x400;
    }
    a->mUnk_000.mUnk_10.y -= 0x400;
    a->mUnk_000.mPos.y = a->mUnk_000.mPos.y + a->mUnk_000.mUnk_10.y;
    if (a->mUnk_000.mPos.y < a->mUnk_0b0) {
        a->mUnk_000.mStateMachine.mNextState = 5;
        a->mUnk_000.mStateMachine.mNextStateRequested = 1;
    }
}

u32 func_020e32a0(u32 p0) {
    return p0;
}

void UpdateChoropuState7(Unk020e1e98 *a) {
    a->mUnk_000.mUnk_10.y -= 0x266;
    a->mUnk_000.mPos.y = a->mUnk_000.mPos.y + a->mUnk_000.mUnk_10.y;
    if (a->mUnk_000.mPos.y < a->mUnk_0b0) {
        Unk020e005c_080 *p = &a->mUnk_000.mStateMachine;

        p->mNextState = 5;
        p->mNextStateRequested = 1;
    }
    if (a->mUnk_0b4.mUnk_00 != 0) {
        a->mUnk_0b4.mUnk_04 += 0x400;
    } else {
        a->mUnk_0b4.mUnk_04 -= 0x400;
    }
}

// Case 1 starts state 6 with an upward speed; case 2 starts state 7 unless player kind 2 or already there.
u8 CollideKartWithChoropu(Unk020e1e98 *a, Kart *b, u8 *c, u8 *d) {
    Vec3 v;

    switch (c[0]) {
        case 2:
            if (gRaceSetup->mCurrentEntries[b->mIndex].mPlayer.mKind == PLAYER_KIND_GHOST) {
                return d[0];
            }
            if (a->mUnk_000.mStateMachine.mState == 7) {
                return d[0];
            }
            a->mUnk_000.mStateMachine.mNextState = 7;
            a->mUnk_000.mStateMachine.mNextStateRequested = 1;
            StartSoundIfKartStarOrKiller(&a->mUnk_000, b);
            break;
        case 1:
            VEC_Subtract(&a->mUnk_000.mPos, &b->mPos, &v);
            if ((s64) v.z * b->mVelocity.x - (s64) v.x * b->mVelocity.z < 0) {
                a->mUnk_0b4.mUnk_00 = 1;
            } else {
                a->mUnk_0b4.mUnk_00 = 0;
            }
            a->mUnk_000.mUnk_10.y = 0x4000;
            a->mUnk_000.mStateMachine.mNextState = 6;
            a->mUnk_000.mStateMachine.mNextStateRequested = 1;
            a->mUnk_000.mFlags |= data_02158bb4;
            StartSoundIfKartStarOrKiller(&a->mUnk_000, b);
            break;
    }
    return d[0];
}

// Case 1 starts state 6 with an upward speed, as CollideKartWithChoropu does for a kart.
u8 CollideItemObjectWithChoropu(Unk020e1e98 *a, Unk020e246c *b, u8 *c, u8 *d) {
    Vec3 v;
    Vec3 w;

    if (c[0] == 1) {
        if (b != NULL) {
            VEC_Subtract(&a->mUnk_000.mPos, &b->mUnk_050, &v);
            if ((s64) v.z * b->mUnk_05c - (s64) v.x * b->mUnk_064 < 0) {
                a->mUnk_0b4.mUnk_00 = 1;
            } else {
                a->mUnk_0b4.mUnk_00 = 0;
            }
            a->mUnk_000.mUnk_10.y = 0x4000;
            a->mUnk_000.mStateMachine.mNextState = 6;
            a->mUnk_000.mStateMachine.mNextStateRequested = 1;
            a->mUnk_000.mFlags |= data_02158bb4;
            func_020f8ddc(b);
        } else {
            VEC_Subtract(&a->mUnk_000.mPos, &a->mUnk_000.mPos, &w);
            if ((s64) w.z * data_02158c7c.x - (s64) w.x * data_02158c7c.z < 0) {
                a->mUnk_0b4.mUnk_00 = 1;
            } else {
                a->mUnk_0b4.mUnk_00 = 0;
            }
            a->mUnk_000.mUnk_10.y = 0x4000;
            a->mUnk_000.mStateMachine.mNextState = 6;
            a->mUnk_000.mStateMachine.mNextStateRequested = 1;
            a->mUnk_000.mFlags |= data_02158bb4;
        }
    }
    return d[0];
}

#pragma thumb on

void CreateChoropu(void) {
    void *v1;
    void *v2;
    v1 = FindCourseMapObjFile(gChoropuNsbmdName);
    v2 = FindCourseMapObjFile(gChoropuNsbtpName);
    func_020e6488((Unk020e6488 **) (((u32 *) &gChoropu)), v1, v2, 0);
    func_020e6ab8(gChoropu);
}

#pragma thumb off
