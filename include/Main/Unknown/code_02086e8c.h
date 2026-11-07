#pragma once

#include "types.h"

typedef struct Unk02086098 Unk02086098;

typedef struct Unk02086098 Unk02086098;
typedef struct Unk02086250 Unk02086250;

#include "Main/Unknown/unk_0217a000.h"

void UploadTextureAndPalette(Unk02086098 *a);
void UploadKartEmblem(u32 a, void *b, void *c);
void UploadKartEmblems(void);
void InitKartEmblemPointers(void);
void func_020870ec(Unk02086098 *a, u16 b);
void SetPaletteKartColor(Unk02086098 *a, u32 b);
void SetupKartEntryNameTexture(Unk02086098 *a, u32 b);
void SetupKartEmblemTexture(Unk02086098 *a, u16 b);
void func_020872a4(void);
u16 GetKartPaletteColor(int a);
void SetTextureSizeFromBits(Unk02086098 *a);
void func_02087508(Unk02086250 *a, u16 b, void *c);
void func_020875b4(void);
void func_0208784c(s32 a, s32 b);
