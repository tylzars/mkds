#pragma once

#include "types.h"
#include "code_0214d93c.h" // RTCTime

typedef struct Vec3 Vec3;

typedef struct SceneNumbers SceneNumbers;

// Object func_0203bf04 reads: the first 0x30 bytes and the 0xdcc bytes from 0x30.
typedef struct Unk0203bf04_a {
    /* 000 */ u8 mUnk_000[0x30];
    /* 030 */ u8 mUnk_030[0xdcc];
} Unk0203bf04_a;

// Object func_0203bf04 fills: a word at 0x08, two bits at 0x2f, 0x200 bytes at 0x30 and 0xdcc bytes from 0x230.
typedef struct Unk0203bf04_b {
    /* 000 */ u8 mUnk_000[0x8];
    /* 008 */ u32 mUnk_008;
    /* 00c */ u8 mUnk_00c[0x23];
    /* 02f */ union {
        u8 mUnk_02f;
        struct {
            u8 mUnk_02f_0 : 2;
        };
    };
    /* 030 */ u8 mUnk_030[0x200];
    /* 230 */ u8 mUnk_230[0xdcc];
} Unk0203bf04_b;

void func_0203be88(u8 *a, u32 b, u32 c);
void func_0203bea4(u8 *a, u32 b, u32 c);
void func_0203bec0(u8 *a);
u8 *func_0203bedc(void *a);
void func_0203bf04(Unk0203bf04_a *a, Unk0203bf04_b *b);
void GetClockTimeOrZero(RTCTime *a);
void GetClockDateOrDefault(s32 *a);
// Scene function of gSceneFuncs[0] (scene 'Title' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
u32 RunTitleScene(SceneNumbers *a);
void UpdateTitleScene(s32 a);
void func_0203c07c(void);
void ReleaseTitleScene(void);
void InitTitleScene(void);
u32 func_0203c0bc(void);
BOOL IsFramesSinceFinishPastWait(void);
void func_0203c1a8(Vec3 *a, u32 b);
