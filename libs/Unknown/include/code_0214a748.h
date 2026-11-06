#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43

// Sixteen words written by ComputeOrthoMatrix.
typedef struct Unk0214ad4c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
} Unk0214ad4c;

// Copies 8 words (32 bytes) from the argument to 0x4000360.
void G3X_SetFogTable(const void *a);
// Returns -1 when bit 27 of 0x4000600 is set. Otherwise copies the 9 words at 0x4000680 to the buffer and returns
// 0.
s32 G3X_GetVectorMtx(void *a);
// Returns -1 when bit 27 of 0x4000600 is set. Otherwise copies the 16 words at 0x4000640 to the buffer and returns
// 0.
s32 G3X_GetClipMtx(void *a);
// When the first argument is nonzero: stores the fourth at 0x400035c and replaces bits 6 and 8-13 of 0x4000060 by
// (third << 8) | (second << 6) with bit 7 set. Otherwise clears bits 7, 12 and 13 of 0x4000060.
void G3X_SetFog(s32 a, u32 b, u32 c, u32 d);
// As G3X_InitMtxStack except that no identity is loaded after the mode 0 pop. Its only caller is G3X_Reset.
void G3X_ResetMtxStack(void);
// Sets bit 15 of 0x4000600, reads the stack levels (bits 8-12 and bit 13 of 0x4000600, retrying while bit 14 is set),
// then: matrix mode 3 and identity; mode 0, pops the bit 13 level count when it is not 0 and loads identity; mode 2,
// pops the bits 8-12 level count and loads identity. Called by G3X_Init and by one game function; G3X_ResetMtxStack
// differs only by the missing identity after the mode 0 pop.
void G3X_InitMtxStack(void);
// Writes 128 zero words to the geometry FIFO at 0x4000400, then waits until bit 27 of 0x4000600 is clear.
void G3X_ClearFifo(void);
// Waits until bit 27 of 0x4000600 is clear, sets bit 15 of 0x4000600 and bits 13 and 12 of 0x4000060, calls
// G3X_ResetMtxStack and writes 0x1f0080, 0 and 0 to 0x40004a4, 0x40004a8 and 0x40004ac.
void G3X_Reset(void);
// Calls G3X_ClearFifo, writes 0 to the end-of-vertices command at 0x4000504, waits until bit 27 of 0x4000600 is
// clear, writes 0 to 0x4000060 and 0x4000600 and 0 to BG0 offset, sets bits 13 and 12 and clears them again
// together with bit 1 of 0x4000060, sets 0x10 there and clears bit 2, sets bit 15 of 0x4000600 and then its top two
// bits to 2, calls G3X_InitMtxStack, writes clear color 0, clear depth 0x7fff, clear-image offset 0, fog color 0
// and fog offset 0, clears bits 0-1 of the BG0 control, calls G3X_InitTable and writes 0x1f0080, 0 and 0 to the
// polygon attribute, texture parameter and palette base commands (0x40004a4, 0x40004a8, 0x40004ac).
void G3X_Init(void);
// Builds a view matrix from a position, an up vector and a look-at point, a load flag and an optional output block
// (12 words: three rotation rows and the translation). With a nonzero flag it sets matrix mode 2 and writes the 12
// words to 0x400045c; with a non-null output block it stores them there.
void ComputeLookAtMatrix(const Vec3 *a, const Vec3 *b, const Vec3 *c, int d, MtxFx43 *out);
// Builds an orthographic projection matrix from six edge values in the same order as ComputeFrustumMatrix, a scale,
// a load flag and an optional output block. With a nonzero flag it sets matrix mode 0 and writes the 16 words to
// 0x4000458; with a non-null output block it stores the 16 words there.
void ComputeOrthoMatrix(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, int h, Unk0214ad4c *i);
// Builds a perspective projection matrix from six edge values (top, bottom, left, right, near, far), a scale
// (0x1000 = 1.0), a load flag and an optional output block. With a nonzero flag it sets matrix mode 0 and writes
// the 16 words to 0x4000458; with a non-null output block it stores the 16 words there.
void ComputeFrustumMatrix(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, int h, Unk0214ad4c *i);
