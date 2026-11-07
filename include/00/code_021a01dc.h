#pragma once

#include "types.h"
#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_0219c93c.h"
#include "00/unk_021b5000.h"
#include "00/code_0219cc00.h"
#include "00/code_0219d128.h"
#include "00/code_021988e8.h"
#include "00/code_0219b580.h"
#include "00/code_0219d000.h"
#include "00/code_0219e000.h"
#include "00/code_0219f000.h"
#include "00/code_021a0000.h"

// Address and byte-swapped port of a peer, built by ReceiveMatchingCommand for func_ov000_0219db18.
typedef struct PeerAddress {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mPort;
    /* 04 */ u32 mAddress;
} PeerAddress;

s32 ReceiveMatchingCommand(s32 command, u32 profileId, u32 c, u16 d, u32 *values, s32 valueCount);
