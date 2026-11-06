#pragma once

#include "types.h"

extern u8 data_ov003_021d6408[];
extern u16 data_ov003_021d6410[];
extern u16 data_ov003_021d6418[];
extern u16 data_ov003_021d641a[];
extern u16 gDecimalFormat[];

void SetJb4ErrorCode(u32 a);
void func_ov003_021c7850(void);
void func_ov003_021c78d8(void);
void func_ov003_021c7914(void);
void func_ov003_021c7934(void);
void func_ov003_021c7958(void);
void UpdateJb4ErrorInput(void);
void UpdateJb4Error(void);
void func_ov003_021c7990(void);
void func_ov003_021c79b4(void);
void func_ov003_021c79e4(void);
void PrintJb4Error(void);
// Declared here until the code that defines it is decompiled.
