#pragma once

#include "types.h"

// The pair of input bits the item code tests to use the held item.
#define ITEM_BITS 0x600
// Item input bit held while the item is used: the held item is thrown in front of the kart.
#define ITEM_THROW_FORWARD_BIT 0x40

typedef struct Unk02029930_f8 Unk02029930_f8;

u32 func_020435c4(void);
void func_020435d4(u32 a);
void RequestBits(s32 a, u32 b);
void func_02043648(void);
unsigned int func_02043a20(void);
void func_02043a34(void);
void func_02043a9c(u32 a);
void func_02043ad4(void);
void func_02043ae0(void);
void func_02043b04(void);
void func_02043b3c(void);
void func_02043b48(void);
void func_02043c14(void);
void func_02043d10(void *a);
void func_02043f28(u32 a);
void func_02043fb0(u32 a);
void func_02044060(u32 a);
void func_0204419c(u32 a, u32 b);
void func_020442d0(u32 a);
void func_02044380(Unk02029930_f8 *a, u32 b, u32 c);
void func_0204451c(u32 a);
