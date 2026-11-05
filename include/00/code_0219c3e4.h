#pragma once

#include "types.h"
#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"

// Argument of the callbacks func_ov000_0219c400, WiFiLoginGpConnectCallback, func_ov000_0219cc94 and
// func_ov000_0219cd74.
typedef Unk0218eff8Arg Unk0219c400;

// Declared here until the code that defines them is decompiled.

#include "00/code_0219c000.h"

u32 IsWiFiLoginDone(void);
void func_ov000_0219c400(GpConnection *a, Unk0219c400 *b, u32 f);
void UpdateWiFiLoginRequest(void);
void StartWiFiLoginRequest(void (*a)(), void *b);
void StartWiFiLoginGpConnect(char *a, char *b, void (*c)(), s32 d);
void WiFiLoginRequestCallback(char *a, char *b);
void WiFiLoginGpConnectCallback(GpConnection *a, Unk0219c400 *b, u32 c);
s32 ReportWiFiLoginGpResult(s32 a);
