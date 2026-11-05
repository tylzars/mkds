#pragma once

#include "types.h"

void LoadKartAndCharacterFiles(void);

#include "Main/Unknown/code_020b4000.h" // Nclr

typedef struct Unk0217ad00_014 Unk0217ad00_014;

typedef struct Unk0217ad08_058 Unk0217ad08_058;

typedef struct Unk0217ad08_058 Unk0217ad08_058;
typedef struct Unk0217ad08_024 Unk0217ad08_024;

typedef struct Unk020136f0 Unk020136f0;

typedef struct Unk0217ad08_024 Unk0217ad08_024;

void InitKartModels(void *a, u32 b);

#include "Main/Unknown/code_020ed5c0.h" // Unk0206bcb0_590

void LoadKartModelMenuFile(void *a, const void *b, void **c);
void CreateKillerItem(void *a);
void CreateKartShadow(Unk0206bcb0_590 *a, void *b);
void CreateTire(Unk0206bcb0_590 *a, void *b);
u16 *LoadKartAPaletteFromKartModelMenu(void *a);
u16 *LoadKartAPaletteFromKartModelFile(void);
void CreateKart(Unk0206bcb0_590 *a, void *b, s32 c);
void CreateCharacter(Unk0206bcb0_590 *a, void *b, s32 c);
void InitKartModels(void *a, u32 b);

// Declared here until the code that defines them is decompiled.

#include "Main/Unknown/code_020846c0.h" // Unk02084b2c

extern u8 data_usa_02154fe8[];
extern u32 data_usa_02155008[];
extern u32 data_usa_02155028[];
extern u32 data_usa_02155038[];
extern u32 data_usa_02155058[];
extern u32 data_usa_02155078[];
extern u32 data_usa_02155088[];
extern u32 data_usa_021550b8[];
extern u8 data_usa_021550c8[];
extern u8 data_usa_021550e8[];
extern u8 data_usa_02155108[];
extern u8 data_usa_02155128[];
extern u8 data_usa_02155148[];
extern Nclr *data_usa_0217ace4;
extern u8 *data_usa_0217acec;

void func_02077bc0(void *a);
void func_02077c1c(void);
void func_02077eb4(void *a, u32 *b);
Nclr *func_02077f00(void);
void func_02077f0c(u16 *a, int b, u32 c);
void func_02077f48(unsigned int p0);
void func_02077f5c(void);
Unk0217ad00_014 *func_02077f7c(int param_1);
void func_02077f9c(int param_1, struct Unk0206bcb0_590 *param_2, u8 *param_3);
void func_0207800c(void);
void func_02078078(void);
void func_020780b0(void);
void func_020780f4(void);
void func_02078158(void);
void func_020783c8(void);
void func_02078420(s32 param_1);
void func_0207851c(Unk0217ad08_058 *a);
void func_02078580(Unk0217ad08_058 *param_1, Unk0217ad08_024 *param_2, s32 param_3);
void func_020787f4(s32 param_1, s32 param_2);
void func_02078934(s32 param_1);
void func_020789d4(void);
void func_020789e4(void);
void func_020789f4(void);
void func_02078a34(s32 param_1);
void func_02078a9c(s32 param_1);
s16 *func_02078b04(s32 param_1, s32 param_2);
void func_02078b48(void *param_1);
void func_02078c58(void *param_1);
void func_02078d64(void *param_1);
void func_02078e4c(void *param_1, void *param_2);
void func_02078ee0(Unk0217ad08_024 *a, int b);
void func_02078f18(void *a, Unk0217ad08_058 *b);
void func_02078f78(Unk020136f0 *a);
void func_02078f9c(void *c);
void *func_02079008(void *a, void *b);
void func_02079014(void *a, Unk020136f0 *b, Unk020136f0 *c);
void func_02079038(void *a, Unk020136f0 *b, Unk020136f0 *c);
void func_02079078(void *a, void *b, void *c, Unk020136f0 *d, Unk020136f0 *e, void *f);
void func_020790e0(void *a, s32 b);
void func_020792c8(Unk0206bcb0_590 *a, s32 b);
void func_0207940c(Unk02084b2c *a, s32 b, void *c);
void func_02079678(void *a, s32 b);
void func_02079988(Unk0206bcb0_590 *a, u32 b);
void DrawKarts(void);
Kart *GetKart(s32 idx);
void GetKartPrevPos(Vec3 *dst, s32 idx);
void InitKarts(u32 a);
void UpdateKarts(void);
void func_0207a2d4(s32 a);
s32 func_0207a4fc(void);
s32 func_0207a538(void);
BOOL func_0207a574(void);
void func_0207a5f0(s32 a);
Unk0206cdd4_B *func_0207a6b0(void);
void func_0207a6c0(Kart *a);
void func_0207a70c(s32 a);
u32 func_0207a7fc(s32 a);
s32 func_0207a84c(s32 a);
void func_0207a8c4(Vec3 *a, s32 b);
void func_0207a91c(Vec3 *dst, u8 idx);
void func_0207a948(Vec3 *dst, s32 idx);
void func_0207a990(void);
void func_0207aa7c(void);
