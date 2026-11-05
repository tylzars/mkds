#pragma once

#include "types.h"
#include "00/code_0218f960.h"

typedef struct Unk02152490 Unk02152490;
typedef struct WiFiBuddySync WiFiBuddySync;

void StartBuddySync(s32 a, const char *b, void (*c)(s32, u8, void *), void *d, void (*e)(s32, u8, void *, void *),
                    void *f, void (*g)(s32, s32, void *), void *h);

u32 AddBuddy(u32 a);
s32 func_ov000_0219d14c(Unk02152490 *a, s32 b, s32 c);
BOOL func_ov000_0219d210(Unk02152490 *a, s32 b, s32 c);
void func_ov000_0219d288(Unk02152490 *a, s32 b, s32 c);
void FinishBuddySync(void);
void func_ov000_0219d2e8(Unk02152490 *a, s32 b);
void func_ov000_0219d478(void);
int func_ov000_0219d49c(void);
void func_ov000_0219d4f8(void);
void func_ov000_0219d504(s32 a);
u32 func_ov000_0219d558(s32 a, void *b, void *c);
void func_ov000_0219d5bc(void);
u32 FindBuddyEntryIndex(u32 a);
int GetBuddyEntryProfileId(int a);
s32 func_ov000_0219d660(void);
void WiFiGpBuddyStatusCallback(struct GpConnection *a, s32 *b);
u32 func_ov000_0219d6c4(u32 a, u32 *b, u32 c);
void WiFiGpBuddyRequestCallback(GpConnection *a, u32 *b);
void ReportBuddySyncError(s32 a, s32 b);
void UpdateBuddySync(void);
void InitBuddySync(WiFiBuddySync *a, struct GpConnection *b, char *c, Unk02152490 *d, s32 e);
