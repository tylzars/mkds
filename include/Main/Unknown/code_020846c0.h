#pragma once

#include "types.h"
#include "code_02010804.h"
#include "code_02012b30.h" // NNSG3dResFileHeader, NNSG3dResMdl
#include "code_0212d214.h"

typedef struct MtxFx43 MtxFx43;

// 16-byte element of the list at data_0217aeb0 (links at 0x00): mUnk_08 is the argument of NNS_G3dGetTex and
// mUnk_0c the object it returns.
typedef struct Unk0208526c {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ NNSG3dResFileHeader *mUnk_08;
    /* 0c */ NNSG3dResTex *mUnk_0c;
} Unk0208526c;

// Object with an NNSG3dResMdl at 0x04 and an Unk0208526c at 0x5c.
typedef struct Unk02084b2c {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ NNSG3dResMdl *mUnk_04;
    /* 08 */ u8 mUnk_08[0x4c];
    /* 54 */ s32 mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ Unk0208526c mUnk_5c;
} Unk02084b2c;

void func_020846c0(void *a);
void func_020848fc(void);
void func_02084958(void *a, u32 b);
void func_02084968(void *a, u32 b, u32 c, u32 d);
void func_020849a0(void *a, u32 b);
void func_020849b0(void *a, u32 b);
void func_020849c0(void *a, u32 b);
void func_020849d0(void *a);
void func_020849f8(void *a, MtxFx43 *b, u32 *c);
void func_02084a88(void *a, u8 b, u8 c);
void func_02084ad8(void *a, u8 b);
NNSG3dResMdl *func_02084b2c(void *a, Unk02084b2c *b, NNSG3dResFileHeader *c, NNSG3dResFileHeader *d);
NNSG3dResMdl *func_02084c54(Unk02084b2c *a, NNSG3dResFileHeader *b);
NNSG3dResMdl *func_02084d3c(Unk02084b2c *a, NNSG3dResFileHeader *b, NNSG3dResFileHeader *c);
NNSG3dResMdl *func_02084e28(void *a, NNSG3dResFileHeader *b);
void func_02084f10(Unk02084b2c *a, NNSG3dResMdl *b);
void func_02084f20(Unk02084b2c *a);
void func_02084f68(Unk02084b2c *a);
void func_02084fb0(Unk02084b2c *a, NNSG3dResMdl *b, u32 c);
u32 func_020850c4(NNSG3dResTex *a);
void func_0208526c(Unk0208526c *a, NNSG3dResFileHeader *b, NNSG3dResFileHeader *c);
