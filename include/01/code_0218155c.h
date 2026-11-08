#pragma once

#include "types.h"
#include "Main/Unknown/code_020a2e4c.h" // Balloon

// List of entries: an array of pointers and its length.
typedef struct BalloonList {
    /* 00 */ Balloon **mObjects;
    /* 04 */ u16 mObjectCount;
} BalloonList;

#include "01/code_02181000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "01/code_02188950.h"
#include "Main/Unknown/code_020a1728.h"

void func_ov001_0218155c(s32 stepCount);
void func_ov001_021815d0(s32 stepCount);
void func_ov001_02181630(short param_1);
void func_ov001_02181660(u16 amount);
void func_ov001_02181678(u32 amount);
void func_ov001_02181690(UnkFunc *callback);
void func_ov001_0218169c(UnkFunc *callback);
void func_ov001_021816a8(UnkFunc *callback);
BOOL func_ov001_021816b4(void);
void func_ov001_021816fc(void);
void func_ov001_0218171c(void);
void func_ov001_0218173c(void);
void func_ov001_0218175c(s32 b);
void func_ov001_021817e0(void);
s32 func_ov001_02181800(void);
u32 GetMissionRunCountLimit(void);
unsigned int GetMissionRunCount(void);
void SetMissionRunTimer(unsigned int timer);
s32 GetMissionRunTimer(void);
void func_ov001_02181844(u16 a, u16 b, u16 c, u16 d);
void UpdateMissionRunData(void);
void CreateMissionRunData(void);
u16 GetMissionRunPrevKartHeadingAngle(void);
u16 GetMissionRunKartHeadingAngle(void);
Vec3 *GetMissionRunPrevKartPos(void);
Vec3 *GetMissionRunKartPos(void);
void func_ov001_02181aa0(void);
u16 GetMissionRunMapObjectLastIndex(void);
u8 func_ov001_02181b54(void);
Unk02188950 *GetMissionRunMapObject(int entryIndex);
void AddMissionRunMapObject(Unk02188950 *mapObject);
