#pragma once

#include "types.h"
#include "code_0212d214.h"

// Element of a list: func_0212ee8c compares mUnk_08 with its second argument.
typedef struct Unk0212ee8c {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ void *mUnk_08;
} Unk0212ee8c;

// Object pointed to by data_0217df04: the 0x18 bytes at 0x4cc are passed to ThreadLockWait and ThreadLockUnlock, and
// 0x4e4 is a list header.
typedef struct Unk0212ef48 {
    /* 000 */ u8 mUnk_000[0x4cc];
    /* 4cc */ u8 mUnk_4cc[0x18];
    /* 4e4 */ LinkedList mUnk_4e4;
} Unk0212ef48;

#include "code_0212c7f0.h" // Unk0212c7f0

u32 func_0212ee54(void *arg0);
void func_0212ee8c(LinkedList *a, void *b);
void func_0212ef00(Unk0212c7f0 *a);
void func_0212ef48(Unk0212c7f0 *a);
void func_0212efb8(Unk0212c7f0 *a);
void func_0212f058(Unk0212c7f0 *a);
void func_0212f094(void);
