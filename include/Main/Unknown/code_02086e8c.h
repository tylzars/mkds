#pragma once

#include "types.h"

typedef struct TexPlttEntry TexPlttEntry;

typedef struct TexPlttEntry TexPlttEntry;
typedef struct Unk02086250 Unk02086250;

#include "Main/Unknown/unk_0217a000.h"

void UploadTextureAndPalette(TexPlttEntry *a);
void UploadKartEmblem(u32 a, void *b, void *c);
void UploadKartEmblems(void);
void InitKartEmblemPointers(void);
void func_020870ec(TexPlttEntry *a, u16 b);
void SetPaletteKartColor(TexPlttEntry *a, u32 b);
void SetupKartEntryNameTexture(TexPlttEntry *a, u32 b);
void SetupKartEmblemTexture(TexPlttEntry *a, u16 b);
void func_020872a4(void);
u16 GetKartPaletteColor(int a);
void SetTextureSizeFromBits(TexPlttEntry *a);
void func_02087508(Unk02086250 *a, u16 b, void *c);
void func_020875b4(void);
void func_0208784c(s32 a, s32 b);
