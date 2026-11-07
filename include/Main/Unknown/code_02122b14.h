#pragma once

#include "types.h"

// 0xc-byte object built on the stack by AdvanceWiFiSessionStep1.
typedef struct Unk02123384 {
    /* 00 */ s32 mKind;
    /* 04 */ s32 mSize;
    /* 08 */ u8 mFromIndex;
    /* 09 */ u8 mToIndex;
    // The sender's mKartMask; written, not read through this struct.
    /* 0a */ u8 mKartMask;
} Unk02123384;

void CombineKartRemoveMask(void);
void AdvanceWiFiSessionStep9(void);
void AdvanceWiFiSessionStep8(void);
void AdvanceWiFiSessionStep5(void);
void AdvanceWiFiSessionStep4(void);
void AdvanceWiFiSessionStep3(void);
void AdvanceWiFiSessionStep1(void);
void AdvanceWiFiSessionStep0(void);
s32 UpdateWiFiSessionStep(void);
void SetupWiFiSession(u32 mode);
