#pragma once

#include "types.h"
#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02108e94.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125da0.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02037a04.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b4000.h"
#include "code_0214a390.h"
#include "code_0214b824.h"
#include "01/code_02198854.h"

// Object whose halfword at 0x04 func_02001a74 clears.
typedef struct Unk02001a74 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
} Unk02001a74;

extern const char data_usa_ov001_021a768c[];
extern const char data_usa_ov001_021a76a8[];
extern const char data_usa_ov001_021a76c4[];
extern const char data_usa_ov001_021a76dc[];
extern const char data_usa_ov001_021a76f4[];
extern const char data_usa_ov001_021a770c[];
extern const char data_usa_ov001_021a7720[];

void func_020019b0(void);
void func_02001a44(void);
void func_02001a74(Unk02001a74 *a);
void func_02001abc(void);
void func_02001b38(void);
void func_02001ba0(void *a);
void func_02001d30(Unk02001d30 *a, s32 b, const char *c, const char *d, const char *e);
