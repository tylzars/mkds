#pragma once

#include "types.h"

typedef struct Unk0217aa14_104 Unk0217aa14_104;

// 0x24 bytes from 0x04 of Unk0205b504, followed by four 8-byte values.
typedef struct Unk0205b504_04 {
    /* 00 */ union {
        u16 mUnk_00;
        s16 mUnk_00_s;
        u8 mUnk_00_b[4];
        struct {
            u32 mUnk_00_0 : 24;
        };
    };
    /* 04 */ u64 mUnk_04[4];
} Unk0205b504_04;

// Message of 0x28 bytes from 0x04.
typedef struct Unk0205b504 {
    /* 00 */ union {
        u8 mUnk_00;
        struct {
            u8 mUnk_00_0 : 2;
            u8 mUnk_00_2 : 2;
            u8 mUnk_00_4 : 4;
        };
    };
    /* 01 */ u8 mUnk_01;
    /* 02 */ union {
        u8 mUnk_02;
        struct {
            u8 mUnk_02_0 : 4;
        };
    };
    /* 03 */ u8 mUnk_03;
    /* 04 */ Unk0205b504_04 mUnk_04;
} Unk0205b504;

void func_0205b0f4(void);
void func_0205b32c(void);
void func_0205b504(u32 a, Unk0205b504 *packet, u32 c, u32 d);
void func_0205b6bc(u32 a, Unk0205b504 *packet, u32 c);
void func_0205b778(u32 a, Unk0205b504 *packet, u32 c);
void func_0205b824(const u64 *ticks, s32 participant);
s32 func_0205b954(s32 participant);
Unk0217aa14_104 *func_0205b978(s32 participant, u32 b);
void func_0205b9a8(void);
void func_0205ba60(void);
u32 func_0205bba8(void);
u32 func_0205bbe8(void);
void func_0205bc08(void);
void func_0205be0c(void);
void func_0205c234(s32 dataSize);
int func_0205c340(u8 participant, u32 b, int dataSize);
void func_0205c470(void);
void func_0205c594(void);
void func_0205c610(u32 participant);
void func_0205c684(void);
void func_0205c6b0(void);
void func_0205c7a0(u32 participant);
void func_0205c800(u16 a, void (*callback)(u32));
void func_0205c898(void);
void func_0205c98c(void);
void func_0205cbe4(void);
void func_0205ccec(void);
void func_0205cd24(void *heap);
void SetParticipantKartMapFromMask(u32 participantMask);
void ResetParticipantKartMap(void);
