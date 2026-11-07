#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_021052fc.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_020f36d8.h" // ItemKind, ItemInfo

// Element of gItemPools[8]: 0x14c bytes (the size in gItemKinds[8]), handled by func_02104a0c to
// func_02104f58: the Unk020f2df0 part, words at 0x130 and 0x138, the Unk021052fc at 0x134, a vector at 0x13c and a
// word at 0x148.
typedef struct Unk02104c68 {
    /* 000 */ Unk020f2df0 mUnk_000;
    /* 130 */ s32 mUnk_130;
    /* 134 */ Unk021052fc *mUnk_134;
    /* 138 */ s32 mUnk_138;
    /* 13c */ Vec3 mUnk_13c;
    /* 148 */ s32 mUnk_148;
} Unk02104c68;

extern Vec3 data_0217c748;

extern Vec3 data_0217c73c;

extern struct CourseMapRow data_0217c730;

extern const u16 data_0215a584;
extern const ItemInfo data_0215a588;
// Default record: its only function pointer is the shared func_01ffd778 hook.
extern const ItemKind gItemKindKiller;

void func_02105214(void);
void func_021051d4(ItemInUse *p0, Unk020f40dc *p1);
void func_0210515c(s32 a);
void func_02104ff8(void);
void func_02104f84(s32 a);
void func_02104f58(Unk02104c68 *p);
void func_02104f14(Unk02104c68 *p);
void func_02104ee0(Unk02104c68 *p, void *a);
void func_02104e58(Unk02104c68 *p);
void func_02104d78(ItemInUse *p0, Unk02104c68 *p1);
s32 func_02104c68(ItemInUse *p0, Unk02104c68 *p1);
void func_02104a0c(Unk02104c68 *p);
