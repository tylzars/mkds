#pragma once

#include "types.h"
#include "code_0200db4c.h"

// 0x40 bytes at data_0217fa00; func_021458c4 clears it, func_02145b54 fills mUnk_04 and mUnk_18 to mUnk_3c.
typedef struct Unk021458b4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mUnk_34;
    /* 38 */ u32 mUnk_38;
    /* 3c */ u32 mUnk_3c;
} Unk021458b4;

// 0x620 bytes at data_0217fa40, set up by func_021458c4; mUnk_44 is started with the 0x400 bytes at mUnk_220.
typedef struct Unk021458c4 {
    /* 000 */ Unk021458b4 *mUnk_00;
    /* 004 */ s32 mUnk_04;
    /* 008 */ vs32 mUnk_08;
    /* 00c */ vs32 mUnk_0c;
    /* 010 */ ThreadQueue mUnk_10;
    /* 018 */ u32 mUnk_18;
    /* 01c */ u32 mUnk_1c;
    /* 020 */ u32 mUnk_20;
    /* 024 */ u32 mUnk_24;
    /* 028 */ u32 mUnk_28;
    /* 02c */ u32 mUnk_2c;
    /* 030 */ u32 mUnk_30;
    /* 034 */ u32 mUnk_34;
    /* 038 */ UnkFunc *mUnk_38;
    /* 03c */ u32 mUnk_3c;
    /* 040 */ UnkFunc *mUnk_40;
    /* 044 */ Thread mUnk_44;
    /* 0fc */ u8 mUnk_fc[8];
    /* 104 */ Thread *mUnk_104;
    /* 108 */ u32 mUnk_108;
    /* 10c */ ThreadQueue mUnk_10c;
    /* 114 */ vu32 mUnk_114;
    /* 118 */ u8 mUnk_118[8];
    /* 120 */ u8 mUnk_120[0x100];
    /* 220 */ u8 mUnk_220[0x400];
} Unk021458c4;

// 0x220 bytes at data_02180080: a function pointer, two words, and the 0x200 bytes at mUnk_20 that func_021463a4 fills.
typedef struct Unk02146154 {
    /* 00 */ UnkFunc *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 mUnk_0c[0x14];
    /* 20 */ u32 mUnk_20[0x80];
} Unk02146154;

extern Unk021458b4 data_0217fa00;
extern u32 data_02180060;
extern Unk02146154 data_02180080;

void func_021458c4(void);
void func_021459cc(u32 a, u32 b);
void func_02145a70(u32 a, u32 b);
void func_02145b0c(UnkFunc *f);
void func_02145b54(s32 a);
int func_02145d2c(void);
int func_02145d38(void);
int func_02145d44(s32 a);
int func_02145e8c(u32 a, u32 b, u32 c, UnkFunc *d, void *e, u32 f, u32 g, u32 h, u32 i);
void func_02145f80(Unk021458c4 *p);
UnkFunc *func_0214613c(void);
int func_02146148(void);
void func_02146154(void);
void func_021461d8(u32 a, u32 b, u32 c, u32 d, UnkFunc *e, u32 f, u32 g);
void func_02146300(Unk021458c4 *a);
void func_021463a4(Unk02146154 *p);
int func_021464a4(Unk02146154 *p);
void func_02146600(void);
void func_021466d8(void);
void func_02146730(u32 a, u32 b);
int func_021467d0(Unk02146154 *p);
int func_02146868(Unk021458c4 *p, s32 a, s32 b);
void func_021469a4(void *a);
