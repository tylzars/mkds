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

void SetGivenKart(u8 *rawPicks, u32 entryIndex, u32 kartIndex);
void SetGivenCharacter(u8 *rawPicks, u32 entryIndex, u32 characterIndex);
void InitCharacterKartPicks(u8 *rawPicks);
u8 *func_0203bedc(void *heap);
void func_0203bf04(Unk0203bf04_a *courseGhost, Unk0203bf04_b *slotGhost);
void GetClockTimeOrZero(RTCTime *time);
void GetClockDateOrDefault(s32 *date);
// Scene function of gSceneFuncs[0] (scene 'Title' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
u32 RunTitleScene(SceneNumbers *sceneNumbers);
void UpdateTitleScene(s32 a);
void func_0203c07c(void);
void ReleaseTitleScene(void);
void InitTitleScene(void);
u32 func_0203c0bc(void);
BOOL IsFramesSinceFinishPastWait(void);
void func_0203c1a8(Vec3 *position, u32 kartIndex);
