#pragma once

#include "types.h"
#include "code_02010804.h"
#include "code_02012b30.h" // NNSG3dResFileHeader, NNSG3dResMdl
#include "code_0212d214.h"

typedef struct MtxFx43 MtxFx43;

// A registered resource file and its texture; the entries form the list gResFileEntries (links at 0x00 and 0x04).
typedef struct ResFileEntry {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ NNSG3dResFileHeader *mFile;
    /* 0c */ NNSG3dResTex *mTexture;
} ResFileEntry;

// 0x6c-byte model object: a render object up to 0x53, then mCullModesSwapped, mDrawKind and the file entry.
typedef struct Nsbmd {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ NNSG3dResMdl *mResMdl;
    /* 08 */ u8 mUnk_08[0x4c];
    /* 54 */ s32 mCullModesSwapped;
    /* 58 */ s32 mDrawKind;
    /* 5c */ ResFileEntry mResFileEntry;
} Nsbmd;

void func_020846c0(void *a);
void ReleaseAllResFiles(void);
void SetNsbmdCullModeAll(void *a, u32 b);
void func_02084968(void *a, u32 b, u32 c, u32 d);
void SetNsbmdEmiAll(void *a, u32 b);
void SetNsbmdLightEnableFlagAll(void *a, u32 b);
void SetNsbmdPolygonIdAll(void *a, u32 b);
void DrawNsbmd(void *a);
void DrawNsbmdWithMatrix(void *a, MtxFx43 *b, u32 *c);
void func_02084a88(void *a, u8 b, u8 c);
void func_02084ad8(void *a, u8 b);
NNSG3dResMdl *InitNsbmdWithTextureInfoCopy(void *a, Nsbmd *b, NNSG3dResFileHeader *c, NNSG3dResFileHeader *d);
NNSG3dResMdl *InitNsbmdWithoutCullSwap(Nsbmd *a, NNSG3dResFileHeader *b);
NNSG3dResMdl *InitNsbmdWithTextureFile(Nsbmd *a, NNSG3dResFileHeader *b, NNSG3dResFileHeader *c);
NNSG3dResMdl *InitNsbmd(void *a, NNSG3dResFileHeader *b);
void func_02084f10(Nsbmd *a, NNSG3dResMdl *b);
void func_02084f20(Nsbmd *a);
void func_02084f68(Nsbmd *a);
void InitNsbmdRenderObj(Nsbmd *a, NNSG3dResMdl *b, u32 c);
u32 UploadResTexture(NNSG3dResTex *a);
void AddResFileEntry(ResFileEntry *a, NNSG3dResFileHeader *b, NNSG3dResFileHeader *c);
