#pragma once

#include "types.h"
#include "Main/Unknown/code_02056b30.h"

typedef struct Unk020c06c4 Unk020c06c4;

// Time-attack record handling of the race (mode 1 only), one record behind gRaceNewRecordTa (0xe8 bytes, allocated by
// InitRaceNewRecordTa, set NULL by func_020c6f84): mUnk_00 is the function it runs every frame (func_020c6f14), which
// compares the finished run with the course's saved records, inserts and saves a new one (func_02056c6c) and slides in
// and draws the new-record page (DrawRaceNewRecordTa).
typedef struct RaceNewRecordTa {
    /* 00 */ void (*mUnk_00)(void);
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ u16 mUnk_14;
    /* 16 */ u8 mUnk_16[2];
    /* 18 */ s32 mUnk_18;
    // The course's six time records, copied from the save by InitRaceNewRecordTa (func_02056bc0): slots 0..4 are the
    // ranked list (an insert shifts them down and writes through func_02056c6c), slot 5 is a further record shown in a
    // sixth row: the best lap time.
    /* 1c */ TimeRecord mRecords[6];
    /* dc */ s32 mUnk_dc;
    // X of the whole page: -0x100 at allocation, eased to 0 over 0x14 frames by func_020c5e30, added to every sprite
    // and row x in the draw.
    /* e0 */ s32 mOffsetX;
    /* e4 */ s32 mUnk_e4;
} RaceNewRecordTa;

s32 func_020c70bc(void);
s32 func_020c70a0(void);
void InitRaceNewRecordTa(void);
void func_020c6f84(void);
void func_020c6f14(void);
void func_020c6adc(Unk020c06c4 *a, s32 b, s32 c, TimeRecord *d);
void func_020c692c(Unk020c06c4 *a, s32 b, s32 c, s32 d);
void DrawRaceNewRecordTa(Unk020c06c4 *a);
BOOL func_020c657c(s32 a);
BOOL func_020c6428(s32 a);
void func_020c610c(void);
void func_020c5f7c(void);
void func_020c5f08(void);
void func_020c5eb8(void);
void func_020c5e30(void);
