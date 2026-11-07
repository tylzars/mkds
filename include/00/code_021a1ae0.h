#pragma once

#include "types.h"
#include "os_printf.h"
#include "code_0200f5ac.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0213a460.h"
#include "code_0214d018.h"
#include "00/code_0218a000.h"
#include "00/code_0218b000.h"
#include "00/code_0218c000.h"
#include "00/code_021a3000.h"
#include "00/code_0218aea4.h"
#include "00/code_0219887c.h"
#include "00/code_0219a000.h"
#include "00/code_0219b580.h"
#include "00/code_0219c384.h"
#include "00/unk_021b5000.h"
#include "00/code_0219d000.h"
#include "00/code_0219de5c.h"
#include "00/code_0219e000.h"
#include "00/code_0219f000.h"
#include "00/code_0219f9bc.h"
#include "00/code_021a0000.h"
#include "00/code_021a1000.h"
#include "00/code_021a17bc.h"
#include "00/code_021a1ac0.h"
#include "00/code_021a4000.h"
#include "00/unk_021b4000.h"
#include "00/code_021a3a18.h"
#include "00/code_0218e2dc.h"

// Address and byte-swapped port built by WiFiUnmatchedDataCallback and handed on with the data.
typedef struct UnmatchedDataAddress {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mPort;
    /* 04 */ u32 mAddress;
} UnmatchedDataAddress;

void ParseMatchingGpMessage(GpConnection *param_1, u32 param_2, const char *param_3);
void WiFiGt2ResultCallback(Unk0219887c *param_1, s32 param_2);
void WiFiIncomingConnectionCallback(u32 param_1, Unk0219887c *connection, u32 address, u32 port, s32 param_5,
                                    char *text);
u32 WiFiUnmatchedDataCallback(u32 param_1, u32 address, u16 port, u8 *data, u32 size);
void UpdateMatching(s32 param_1);
void StartMatchingWithBuddies(const void *param_1, s32 param_2, s32 param_3, s32 param_4, void *param_5, u32 param_6,
                              u32 param_7, u32 param_8);
void StartMatchingWithFilter(u32 param_1, const void *param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6);
u32 func_ov000_021a2768(u32 param_1);
void InitMatching(WiFiMatching *param_1, GpConnection *param_2, void **param_3, void *param_4, void *param_5,
                  void *param_6, void *param_7, u32 param_8);

#include "00/code_021a3760.h"
