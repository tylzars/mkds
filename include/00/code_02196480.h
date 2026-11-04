#pragma once

#include "types.h"

// Block filled by GpiOpenSearchSocket.
typedef struct Unk021962d4Addr {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mUnk_04;
} Unk021962d4Addr;

#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_02190000.h"
#include "00/code_02193000.h"

extern char data_ov000_021b39a8[];
extern char data_ov000_021b39ac[];
extern char data_ov000_021b39c4[];
extern char data_ov000_021b39cc[];
extern u8 data_ov000_021b39fc[];

s32 func_ov000_02196480(GpConnection *a, s32 *b, GpiPeer *c, s32 d, const char *e);
s32 func_ov000_021964e4(GpConnection *a, GpiOperation *b, const char *c);
