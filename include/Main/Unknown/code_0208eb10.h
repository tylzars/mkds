#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"

// One point of a strip: its height, the frames since it was added and its position (the position shifted right by 4).
typedef struct PosStripPoint {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ s32 mHeight;
    /* 0c */ u16 mSinceAddedFrames;
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ Vec3 mPos;
} PosStripPoint;

// A strip: a list of points that follows a position; the draw joins neighbouring points with quads.
typedef struct PosStrip {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ NNSFndList mPoints;
    /* 14 */ u32 mFollowedPos;
    /* 18 */ u32 mStopped;
    /* 1c */ u32 mHeight;
    /* 20 */ s32 mKartIndex;
    /* 24 */ s32 mOffsetX;
    /* 28 */ s32 mOffsetY;
    /* 2c */ s32 mOffsetZ;
} PosStrip;

typedef struct PosStripPoint PosStripPoint;
typedef struct PosStrip PosStrip;

// Declared here until the code that defines them is decompiled.

#include "code_02012b30.h" // MtxFx43

typedef struct KartAiItemUse KartAiItemUse;

struct KartAi;

void StopPosStrip(unsigned int p0);
PosStrip *StartAwardKartPosStrip(s32 a);
s32 StartPosStrip(u32 a);
void SetPosStripPointFromKart(PosStripPoint *a, PosStrip *b);
void SetPosStripPointFromPos(u32 arg0, u32 arg1);
void DrawPosStrips(const MtxFx43 *a);
void UpdatePosStrips(void);
void InitPosStrips(void *a);
void UseItemBehindAfterInUseOrNearTarget(KartAiItemUse *a, struct KartAi *b);
void func_0208f434(KartAiItemUse *a, struct KartAi *b);
void func_0208f4e8(KartAiItemUse *a, struct KartAi *b);
void func_0208f5c4(KartAiItemUse *a, struct KartAi *b);
void ThrowItemByTrailKind(KartAiItemUse *a, struct KartAi *b);
void func_0208f6d4(KartAiItemUse *a, struct KartAi *b);
void func_0208f754(KartAiItemUse *a, struct KartAi *b);
void UseItemAfterInUse(KartAiItemUse *a, struct KartAi *b);
void func_0208f810(KartAiItemUse *a, struct KartAi *b);
void func_0208f8ac(KartAiItemUse *a, struct KartAi *b);
void UseItemByCircleKind(KartAiItemUse *a, struct KartAi *b);
void func_0208f9ac(KartAiItemUse *a, struct KartAi *b);
void func_0208fa50(KartAiItemUse *a, struct KartAi *b);
void func_0208fafc(KartAiItemUse *a, struct KartAi *b);
void func_0208fba0(KartAiItemUse *a, struct KartAi *b);
void ThrowItemAtNearTarget(KartAiItemUse *a, struct KartAi *b);
void ThrowItemByCircleKind(KartAiItemUse *a, struct KartAi *b);
unsigned int func_0208fd88(unsigned int p0);
