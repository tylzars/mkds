#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"

// Element of the lists behind data_0217b08c, which has a list of elements at 0x08 of its own.
typedef struct Unk0208ec64_08 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ s32 mUnk_08;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ Vec3 mUnk_10;
} Unk0208ec64_08;

// Entry func_0208ec64 takes from the list at 0x0c of data_0217b08c.
typedef struct Unk0208ec64 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ NNSFndList mUnk_08;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
} Unk0208ec64;

typedef struct Unk0208ec64_08 Unk0208ec64_08;
typedef struct Unk0208ec64 Unk0208ec64;

// Declared here until the code that defines them is decompiled.

#include "code_02012b30.h" // MtxFx43

typedef struct Unk0208fd8c Unk0208fd8c;

struct KartAi;

void func_0208eb10(unsigned int p0);
Unk0208ec64 *func_0208eb1c(s32 a);
s32 func_0208ec64(u32 a);
void func_0208ecd8(Unk0208ec64_08 *a, Unk0208ec64 *b);
void func_0208ee40(u32 arg0, u32 arg1);
void func_0208ee7c(const MtxFx43 *a);
void func_0208f0a0(void);
void func_0208f0f8(void *a);
void UseItemBehindAfterInUseOrNearTarget(Unk0208fd8c *a, struct KartAi *b);
void func_0208f434(Unk0208fd8c *a, struct KartAi *b);
void func_0208f4e8(Unk0208fd8c *a, struct KartAi *b);
void func_0208f5c4(Unk0208fd8c *a, struct KartAi *b);
void func_0208f670(Unk0208fd8c *a, struct KartAi *b);
void func_0208f6d4(Unk0208fd8c *a, struct KartAi *b);
void func_0208f754(Unk0208fd8c *a, struct KartAi *b);
void UseItemAfterInUse(Unk0208fd8c *a, struct KartAi *b);
void func_0208f810(Unk0208fd8c *a, struct KartAi *b);
void func_0208f8ac(Unk0208fd8c *a, struct KartAi *b);
void func_0208f948(Unk0208fd8c *a, struct KartAi *b);
void func_0208f9ac(Unk0208fd8c *a, struct KartAi *b);
void func_0208fa50(Unk0208fd8c *a, struct KartAi *b);
void func_0208fafc(Unk0208fd8c *a, struct KartAi *b);
void func_0208fba0(Unk0208fd8c *a, struct KartAi *b);
void ThrowItemAtNearTarget(Unk0208fd8c *a, struct KartAi *b);
void func_0208fd24(Unk0208fd8c *a, struct KartAi *b);
unsigned int func_0208fd88(unsigned int p0);
