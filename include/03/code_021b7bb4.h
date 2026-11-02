#pragma once

#include "types.h"

static inline u16 func_ov003_021b7c44_inline(u16 value) {
    return ((value >> 8) & 0xff) | ((value << 8) & 0xff00);
}

typedef struct Unk021d6810 {
    /* 00 */ u8 pad_00[0x10];
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
} Unk021d6810;

#include "03/code_021b94b8.h"
#include "03/code_021b7000.h"
#include "03/unk_021d8000.h"
#include "Main/Unknown/code_02133000.h"

extern Unk021d6810 data_ov003_021d6810;
extern s32 data_ov003_021d7c48;
extern u32 data_ov003_021d7c60[3];

u16 func_ov003_021b7bb4(void);
int func_ov003_021b7c30(const void *a);
u16 func_ov003_021b7c44(u16 value);
u32 func_ov003_021b7c5c(u32 arg0);
u16 func_ov003_021b7c94(u16 value);
u32 func_ov003_021b7cac(u32 arg0);
s32 func_ov003_021b7ce4(s32 descriptor);
s32 func_ov003_021b7cec(s32 id, Unk021b7cec *addr, u32 length);
s32 func_ov003_021b7cf8(s32 domain, s32 type, s32 protocol);
s32 func_ov003_021b7d00(s32 id, s32 arg1, s32 arg2, void *value, s32 length);
s32 func_ov003_021b7d04(s32 a, void *b, s32 c, s32 d, Unk021b7cec *e, u32 f);
s32 func_ov003_021b7d1c(s32 count, Unk021b7ba0 *set, void *arg2, void *arg3, Unk021b7d1c *arg4);
s32 func_ov003_021b7d68(s32 id, void *buffer, s32 length, s32 flags, Unk021b7cec *out, s32 *outLength);
void func_ov003_021b7d84(void *arg0, s32 arg1, u32 arg2);
void func_ov003_021b7d90(void *arg0, const void *arg1, u32 arg2);
s32 func_ov003_021b7da0(const u8 *left, const u8 *right, s32 count);
s32 func_ov003_021b7dc8(void);
s32 func_ov003_021b7df4(u32 a, u32 b, u32 c);
void func_ov003_021b7e58(u32 param_1, u32 param_2);
u32 func_ov003_021b7e70(u32 param_1, int param_2);
void func_ov003_021b7e94(u8 *param_1, u32 param_2, u8 *param_3);
void func_ov003_021b7ed0(const s8 *key, u8 *buffer, s32 size);
