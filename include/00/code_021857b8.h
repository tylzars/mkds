#pragma once

#include "types.h"

typedef struct WiFiStateCallbacks WiFiStateCallbacks;

// mState selects the handler run by func_ov000_021857e0.
typedef struct Unk021b4c8c {
    /* 0 */ s32 mState;
    /* 4 */ s32 mNextState;
} Unk021b4c8c;

extern WiFiStateCallbacks data_ov000_021b0fd8;
extern Unk021b4c8c *data_ov000_021b4c8c;

void func_ov000_021857b8(void);
void func_ov000_021857dc(void);
void func_ov000_021857e0(void);
void func_ov000_02185818(void);
void func_ov000_0218583c(void);
void func_ov000_02185920(void);
void func_ov000_0218592c(void *a);
