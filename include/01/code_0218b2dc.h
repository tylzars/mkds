#pragma once

#include "types.h"
#include "01/code_02188950.h"

typedef struct Unk02188950 Unk02188950;
typedef struct Unk021a7b64 Unk021a7b64;
typedef struct Unk0218d87c Unk0218d87c;

extern Unk021a7b64 data_ov001_021a7b64;

void *func_ov001_0218b2dc(void);
void *func_ov001_0218b2f4(void);
void func_ov001_0218b310(void);
void DrawKuriking(void *a,
                  Unk02188950 *b); /* only calls the two draw helpers shared with five other ov001 draw callbacks */
void InitKuriking(Unk0218d87c *a);
void UpdateKuriking(u32 a, Unk02188950 *b); /* skipped for objects with mFlags & 4 (parked pool objects) */
void InitKurikingObjects(Unk0218d87c *a);
void func_ov001_0218b640(Unk02188950 *a, void *b);
void func_ov001_0218b6f8(Unk02188950 *a, void *b);
void func_ov001_0218b72c(Unk02188950 *a);
void func_ov001_0218b770(Unk02188950 *a);
void func_ov001_0218b7a4(Unk02188950 *a);
void func_ov001_0218b7c8(Unk02188950 *a);
void func_ov001_0218b7fc(Unk02188950 *a);
void func_ov001_0218b828(Unk02188950 *a);
s32 func_ov001_0218b850(Unk02188950 *a);
s32 func_ov001_0218b8d4(Unk02188950 *a);
void func_ov001_0218b8f0(void);
void func_ov001_0218b8f8(Unk02188950 *a);
void func_ov001_0218b928(Unk02188950 *a);
