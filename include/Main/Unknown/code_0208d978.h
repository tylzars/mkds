#pragma once

#include "types.h"
#include "code_02012b30.h" // Unk02012f58, Unk020136f0
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_02017000.h"
#include "Main/Unknown/code_0208eb10.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_0217b000.h"

// 0xb8-byte object of the lists behind data_0217b080: an Unk02084b2c at 0x08, a position at 0x74, the functions at
// 0x80 (called with the object and a value) and 0x84, three objects at 0x90 to 0x98 and three words at 0x9c.
typedef struct Unk0208e490 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ Unk02084b2c mUnk_08;
    /* 74 */ Vec3 mUnk_74;
    /* 80 */ void (*mUnk_80)(struct Unk0208e490 *, s32);
    /* 84 */ void (*mUnk_84)(struct Unk0208e490 *);
    /* 88 */ s32 mUnk_88;
    /* 8c */ u32 mUnk_8c;
    /* 90 */ Unk02087d0c *mUnk_90[3];
    /* 9c */ s32 mUnk_9c[3];
    /* a8 */ u32 mUnk_a8;
    /* ac */ u32 mUnk_ac;
    /* b0 */ u16 mUnk_b0;
    /* b4 */ s32 mUnk_b4;
} Unk0208e490;

void func_0208d978(const Vec3 *a, s32 b);
void func_0208da94(Unk0208e490 *a);
void func_0208dad4(Unk0208e490 *a, s32 b);
void func_0208db58(Unk0208e490 *a);
void func_0208db94(Unk0208e490 *a, s32 b);
void func_0208dc08(Unk0208e490 *a);
void func_0208dc50(Unk0208e490 *a);
void func_0208dcbc(Unk0208e490 *a);
void func_0208dd10(Unk0208e490 *a);
void func_0208dd6c(Unk0208e490 *a, s32 b);
void func_0208ddf4(void *a, s32 b, Unk020136f0 *c, void *d, void *e, void *f);
void func_0208e098(void *a);
void func_0208e23c(void);
void func_0208e2c8(Unk0216618c *a, s32 b);
void func_0208e358(void);
void func_0208e400(void);
Unk0208e490 *func_0208e490(u32 a, const Vec3 *b, s32 c);
void func_0208e570(void *a);
void func_0208e808(s32 a);
void func_0208e82c(const Unk02012f58 *a, Unk0208ec64_08 *b, Unk0208ec64_08 *c, Unk021663f4 *d);
void func_0208e99c(Unk0208ec64 *a);
