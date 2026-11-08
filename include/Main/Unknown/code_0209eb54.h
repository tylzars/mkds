#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object of UpdatePicture: after the shared part, a halfword at 0xa0, the phase at 0xa4, a counter at 0xa8 and the
// state at 0xac.
typedef struct Picture {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ u16 mNsbcaFrameIndex;
    /* a2 */ u8 mUnk_a2[2];
    /* a4 */ s32 mPictureIndex;
    /* a8 */ s32 mState1Timer;
    /* ac */ s32 mState;
} Picture;

/* kind 0xd objects are MapObject-sized (0xa0) */
void DrawPuddle(void *a, MapObject *b);
void SetupDrawPuddle(void *a);
void CreatePuddle(void *a);
void *CreatePictureUpdateList(void);
void *CreatePictureDrawList(void);
void UpdatePicture(void *a, Picture *b); /* skipped for objects with mFlags & 4 (parked pool objects) */
void DrawPicture(void *a, Picture *b);
void CreatePicture1AndPicture2(void *a);
