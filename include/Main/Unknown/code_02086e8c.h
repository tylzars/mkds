#pragma once

#include "types.h"

typedef struct TexPlttEntry TexPlttEntry;

typedef struct TexPlttEntry TexPlttEntry;
typedef struct Unk02086250 Unk02086250;

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
void func_02087508(Unk02086250 *kartObject, u16 kartIndex, void *heap);
void func_020875b4(void);
void func_0208784c(s32 texWidthFixed, s32 texHeightFixed);
