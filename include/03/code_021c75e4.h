#pragma once

#include "types.h"

// Five functions called with the object at 0x08.
typedef struct Unk021d7310 {
    /* 00 */ void (*mUnk_00[5])(u8 *);
} Unk021d7310;

extern u8 data_ov003_021d7300[];
extern Unk021d7310 data_ov003_021d7310;
extern u8 data_ov003_021d73ac[];

void func_ov003_021c75e4(void);
void func_ov003_021c75f8(void);
void func_ov003_021c7614(void);
void func_ov003_021c7678(void);
void func_ov003_021c76b4(void);
void func_ov003_021c7748(void);
