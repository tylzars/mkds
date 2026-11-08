#pragma once

#include "types.h"

typedef struct TexPlttEntry TexPlttEntry;

typedef struct TexPlttEntry TexPlttEntry;
typedef struct KartNameTag KartNameTag;

#include "Main/Unknown/unk_0217a000.h"

void UploadTextureAndPalette(TexPlttEntry *texPlttEntry);
void UploadKartEmblem(u32 kartIndex, void *texData, void *plttData);
void UploadKartEmblems(void);
void InitKartEmblemPointers(void);
void func_020870ec(TexPlttEntry *texPlttEntry, u16 kartIndex);
void SetPaletteKartColor(TexPlttEntry *texPlttEntry, u32 kartIndex);
void SetupKartEntryNameTexture(TexPlttEntry *texPlttEntry, u32 kartIndex);
void SetupKartEmblemTexture(TexPlttEntry *texPlttEntry, u16 kartIndex);
void func_020872a4(void);
u16 GetKartPaletteColor(int kartIndex);
void SetTextureSizeFromBits(TexPlttEntry *texPlttEntry);
void InitKartNameTag(KartNameTag *kartObject, u16 kartIndex, void *heap);
void InitKartNameTagsAndDistanceOrder(void);
void func_0208784c(s32 texWidthFixed, s32 texHeightFixed);
