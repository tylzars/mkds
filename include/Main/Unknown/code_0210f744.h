#pragma once

#include "types.h"
#include "code_0212bcac.h"

// Object data_0217d254: a signed halfword at 0x00, a signed halfword at 0x02, a signed word at 0x04 and four
// bytes at 0x08; func_0210f744 and func_0210f75c read the word at 0x04, func_0210f780 reads and writes all of
// them, and func_0210f808 writes all of them.
typedef struct Unk0217d254 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08[4];
} Unk0217d254;

extern Unk0217d254 data_0217d254[];

void func_0210f808(void);
void func_0210f780(NNSSndSeqPlayer **a);
u32 func_0210f75c(u32 a);
u32 func_0210f744(u32 a);
