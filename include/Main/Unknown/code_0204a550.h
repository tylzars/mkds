#pragma once

#include "types.h"

// Object read at 0x00 and written at 0x04 by UpdateEmblemScene.
typedef struct Unk0204a598 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ u8 mUnk_02[0x2];
    /* 04 */ s16 mUnk_04;
} Unk0204a598;

#include "Main/Unknown/unk_02175000.h"

// Scene function of gSceneFuncs[3] (scene 'Emblem' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
s32 RunEmblemScene(void *a);
void UpdateEmblemScene(Unk0204a598 *a);
void func_0204a5e8(void);
unsigned int func_0204a5f4(unsigned int p0);
// Calls StopWvrAndWait, func_02043c14 and InitEmblem through func_ov001_021a23f4 (InitEmblem also
// calls InitEmblemChoises).
void InitEmblemScene(void);
BOOL func_0204a620(KeyRecording *a);
BOOL func_0204a650(KeyRecording *a);
u16 func_0204a664(KeyRecording *a);
void func_0204a798(KeyRecording *a, u16 b);
