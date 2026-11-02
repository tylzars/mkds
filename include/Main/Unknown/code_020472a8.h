#pragma once

#include "types.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_020483e4.h"

extern const char data_usa_02165008[];
extern const char data_usa_02165010[];
extern const char data_usa_02165018[];
extern const char data_usa_02165020[];
extern const char data_usa_02165028[];
extern const char data_usa_02165030[];
extern const char data_usa_02165038[];
extern const char data_usa_02165040[];

void func_020472a8(void);
void func_020472e4(void *a, void *b);
void func_020473a8(void);
void func_020473e4(void);
void func_02047468(const void *a, u32 b);
void func_02047498(const void *a, s32 b);
void func_020474e4(void);
void func_02047544(Unk02017f24 *a, Unk02017f24 *b, Unk02017f24 *c);
void func_02047634(void *a, s32 b, s32 c, u32 d, u32 e);
void func_020476ac(void);
void func_020476ec(void);
void func_02047728(void);
void func_0204775c(void);
void *LoadKartModelFile(const char *path);
void *FindKartModelFile(const char *path);
void *func_02047950(const char *path);
void *FindCourseFile(const char *path);
void *func_0204799c(const char *name);
void *func_02047a28(const char *name);
void *func_02047b08(const char *path);
u32 FindArchiveFile(u32 archiveName, const char *path);
void func_02047b6c(u16 arg0);
