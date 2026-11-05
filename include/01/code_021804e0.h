#pragma once

#include "types.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/unk_02175628.h"

// Argument of func_ov001_0218052c.
typedef struct Unk0218052c {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
} Unk0218052c;

// Object at the start of a 0xdc-byte allocation made by func_02038d88.
typedef struct Unk02180774 {
    /* 00 */ u8 mUnk_00[0x28];
    /* 28 */ u8 mUnk_28[0x48];
    /* 70 */ u8 mUnk_70[0x6c];
} Unk02180774;

// Scene function of gSceneFuncs[5] (scene 'Test' in gSceneNames): copies the callbacks and calls
// RunScene. Returns 0.
int RunTestScene(void *p0);
void func_ov001_0218050c(Unk0218052c *p0);
void func_ov001_02180514(void);
void func_ov001_0218051c(void);
void func_ov001_02180524(void);
void func_ov001_0218052c(Unk0218052c *p0);
unsigned int func_ov001_021805bc(unsigned int p0, unsigned int p1);
u16 func_ov001_021805d8(Unk02175628 *p0, unsigned int p1);
unsigned int func_ov001_021805ec(void);
void func_ov001_021805f4(void);
void func_ov001_02180610(void);
void func_ov001_02180728(Unk02180728 *p0, void *p1, void *p2, s32 p3, s32 p4);
void func_ov001_02180740(Unk02180774 *p0, u32 p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6);
void func_ov001_02180774(Unk02180774 *p0, u32 p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6);
void func_ov001_021807a8(Unk02180774 *p0, u32 p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
void *func_ov001_021807e4(void);
void func_ov001_02180800(void);
unsigned int func_ov001_02180ad0(Unk02180728 *p0, u32 p1, u32 p2, u32 p3, u32 p4, u16 *p5);
