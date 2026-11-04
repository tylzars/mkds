#pragma once

#include "types.h"
#include "code_02134008.h" // FloatTrapTable

extern u32 gFloatStatus;
extern FloatTrapTable gFloatTrapTable;
extern void (*data_usa_02161748[])(void);

void SwiWriteByte(const void *a);
u32 SwiReadByte(void);
void SwiCall24(void);
s32 func_0214241c(void);
s32 SwiWriteBytes(s32 a, const u8 *b, const u32 *c);
s32 SwiReadBytes(s32 a, u8 *b, u32 *c);
void RunListNodeCallbacks(void);
void CallCtorTable(void);
u32 *GetFloatStatus(void);
FloatTrapTable *GetFloatTrapTable(void);
void func_02142590(void);
