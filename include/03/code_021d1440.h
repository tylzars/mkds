#pragma once

#include "types.h"

typedef struct FSFile FSFile;
typedef struct FSArchive FSArchive;

u32 func_ov003_021d1440(const u8 *c, const char *d, s32 e);
void func_ov003_021d1490(void *a, ...);
void *func_ov003_021d14b8(const u8 *f, u32 *g, s32 h);
s32 func_ov003_021d1564(void);
void func_ov003_021d1568(FSArchive *list);
u32 func_ov003_021d1574(int a, u32 b, int c, u32 d);
s32 func_ov003_021d15a4(FSFile *a, u32 b);
void func_ov003_021d15f4(void);
void func_ov003_021d1654(void);
