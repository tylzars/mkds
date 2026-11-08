#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object of kind 0x6c (Balloon, the battle balloons), also held by the kind 0x69 controller (UpdateKartBalloons,
// code_020a3fa8.h) and by src/01/code_0218155c.c. Object of the list FindMapObjectKindUpdateList(0x6c), set up by
// StartBalloon: the shared MapObject part, then the value passed to StartBalloon at 0xa8, two Vec3s at 0xb0 and 0xbc,
// words up to 0xe4, a Vec3 at 0xe8 and words up to 0xfc; the pointer array at 0xf8 has the count at 0xf4.
typedef struct Balloon {
    /* 00 */ MapObject mUnk_00;
    // Frames left while the balloon has no kart: 0x1e from the let-go function, counted down in the update; at 0 the
    // end effects start and the object is parked.
    /* a0 */ s32 mNoKartTimer;
    // Index of the kart whose list holds the balloon, -1 while it has no kart (set at creation and by the let-go
    // function).
    /* a4 */ s32 mKartIndex;
    // Frame index of the balloon's .nsbtp animation, stored at creation from the kart's mBalloonNsbtpFrameIndex and
    // held fixed; the draw passes it to the frame setter and the effect callback uses it as an index into a table.
    /* a8 */ s32 mNsbtpFrameIndex;
    /* ac */ u8 mUnk_ac[4];
    // The point the balloon follows, derived from the kart's position; set at creation and every frame by
    // SetBalloonTargetPosAndVelocity and moved by mTargetVelocity.
    /* b0 */ Vec3 mTargetPos;
    // Velocity of mTargetPos: the kart's velocity while attached; a balloon without a kart falls (y -0x2000 per frame).
    /* bc */ Vec3 mTargetVelocity;
    /* c8 */ s32 mUnk_c8;
    /* cc */ s32 mUnk_cc;
    // Size of the balloon in 20.12 fixed point (0x1000 = full size): grows while inflating; UpdateKartBalloons treats
    // <= 0 as gone and >= 0x1000 as full.
    /* d0 */ s32 mScaleFactor;
    /* d4 */ s32 mUnk_d4;
    /* d8 */ s32 mUnk_d8;
    /* dc */ s32 mUnk_dc;
    /* e0 */ s32 mUnk_e0;
    /* e4 */ s32 mDrawScale;
    /* e8 */ Vec3 mDrawPos;
    // Number of balloons this object draws: 1 for the local kart's balloons (each draws itself), the kart's count for
    // the first balloon of another kart's list, 0 for its other balloons.
    /* f4 */ s32 mDrawCount;
    // The kart's balloon list that the first balloon draws (mDrawCount entries); NULL when a balloon draws only itself.
    /* f8 */ struct Balloon **mDrawList;
    /* State number of this kind's own per-frame switch in UpdateBalloon; this object does not use
       MapObject.mUnk_80's state machine */
    /* fc */ s32 mState;
} Balloon;

void SetBalloonDrawCountAndList(Balloon *balloon, u16 drawCount, void *drawList);
void SetBalloonKartIndex(Balloon *balloon, u16 kartIndex);
s32 GetBalloonScaleFactor(Balloon *balloon);
void func_020a2e68(Balloon *balloon);
