#pragma once

#include "types.h"
#include "Main/Unknown/code_020f9c6c.h"

typedef struct Unk020e1e98_154 Unk020e1e98_154;
typedef struct Unk020e3ef4 Unk020e3ef4;
typedef struct Unk020e1dc0 Unk020e1dc0;
typedef struct Bridge Bridge;

// Block of twelve words.
typedef struct Unk020e3e48 {
    /* 00 */ u32 mUnk_00[12];
} Unk020e3e48;

void func_020e4380(Unk020e3ef4 *object);
void func_020e435c(void *viewMatrix);
BOOL func_020e4320(s32 kind);
void func_020e4184(Unk020e1dc0 *list);
void func_020e410c(Unk020e1dc0 *list);
void func_020e3ef4(Unk020e3ef4 *object, struct CourseMapRow *courseRow, Unk020e1e98_154 *kindInfo);
void *CreateBridgeKindData(void);
void *CreateBridgeDrawList(void);
void *CreateBridgeUpdateList(void);
void UpdateBridge(s32 a, Bridge *bridge); /* skipped for objects with mFlags & 4 (parked pool objects) */
void DrawBridge(Unk020e3ef4 *object, void *viewMatrix, u32 alpha);
void DrawAllBridges(void *viewMatrix);
