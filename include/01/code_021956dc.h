#pragma once

#include "types.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_0212426c.h"
#include "00/code_02182fdc.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02060004.h"

typedef struct RecordTAtt {
    /* 00 */ Ncgr *mUnk_00;
    /* 04 */ struct Unk02021dc8 *mUnk_04;
    /* 08 */ Unk0201ea30 *mUnk_08;
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ Unk0201ea30 *mUnk_10;
    /* 14 */ Ncgr *mUnk_14;
    /* 18 */ struct Unk02021dc8 *mUnk_18;
    /* 1c */ Unk0201ea30 *mUnk_1c;
    /* 20 */ void *mUnk_20;
    /* 24 */ Unk0201ea30 *mUnk_24;
    /* 28 */ void *mUnk_28;
    /* 2c */ void *mUnk_2c;
    /* 30 */ Nclr *mUnk_30;
    /* 34 */ void *mUnk_34;
    /* 38 */ Unk02124b1c *mUnk_38;
    /* 3c */ Unk02124b1c *mUnk_3c;
    /* 40 */ void *mUnk_40;
    /* 44 */ void *mUnk_44;
    /* 48 */ void *mUnk_48;
    /* 4c */ void *mUnk_4c;
    /* 50 */ s32 mUnk_50;
    /* 54 */ s32 mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ s32 mUnk_60;
    /* 64 */ s32 mUnk_64;
    /* 68 */ s32 mUnk_68;
    /* 6c */ s32 mUnk_6c;
    /* 70 */ s32 mUnk_70;
    /* 74 */ s32 mUnk_74;
    /* 78 */ s32 mUnk_78[2];
    /* 80 */ s16 mUnk_80;
    /* 82 */ u8 mUnk_82[2];
    /* 84 */ s32 mUnk_84;
    /* 88 */ s32 mUnk_88;
    /* 8c */ s32 mUnk_8c;
    /* 90 */ s32 mUnk_90;
} RecordTAtt;

// Object behind data_021759d4.
typedef struct Unk021759d4 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ u32 *mUnk_20;
    /* 24 */ u16 mUnk_24;
    /* 26 */ u8 mUnk_26[0x2];
    /* 28 */ u32 *mUnk_28;
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ u8 mUnk_3c[0x4];
    /* 40 */ u32 *mUnk_40;
    /* 44 */ u32 mUnk_44;
    /* 48 */ u32 mUnk_48;
    /* 4c */ u8 mUnk_4c[0x4];
    /* 50 */ s32 mUnk_50;
    /* 54 */ void (*mUnk_54)(u32 *, u32);
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ void *mUnk_60;
    /* 64 */ void *mUnk_64;
    /* 68 */ void *mUnk_68;
    /* 6c */ u8 mUnk_6c;
} Unk021759d4;

extern u16 data_ov001_021a6850[][2];

#include "Main/Unknown/code_021172a8.h"
#include "Main/Unknown/code_0211130c.h"

#include "code_021458c4.h"

extern Unk021759d4 *data_021759d4;
extern u16 data_ov001_021a67c0[];
extern u16 data_ov001_021a67c4[];
extern u16 data_ov001_021a67c8[];
extern u16 data_ov001_021a67d4[];
extern u16 data_ov001_021a67e0[];
extern u16 data_ov001_021a67ec[];
extern u16 data_ov001_021a67f8[];
extern u16 data_ov001_021a6804[];
extern u16 data_ov001_021a6810[];
extern u16 data_ov001_021a681c[];
extern s32 data_ov001_021a6900[];
extern RecordTAtt *gRecordTAtt;

void RegisterRecordTAttCallbacks(void);
void func_ov001_02195704(void);
void func_ov001_0219574c(void);
void AdvanceRecordTAtt(void);
void func_ov001_02195894(void);
void func_ov001_021959c0(void);
void func_ov001_021959d8(void);
void func_ov001_02195a54(void);
void func_ov001_02195a6c(void);
void func_ov001_02195ba4(void);
void func_ov001_02195d64(void);
void func_ov001_02195e38(void);
void func_ov001_02195ea0(void);
void func_ov001_02195eb8(void);
void func_ov001_02195ff8(void);
void func_ov001_02196058(void);
void func_ov001_021960a4(void);
void func_ov001_0219623c(void);
void func_ov001_021963a8(void);
void func_ov001_02196514(void);
void func_ov001_02196724(void);
void func_ov001_021968bc(void);
void func_ov001_02196904(void);
void InitRecordTAtt(void *heap);
BOOL func_ov001_02196c4c(void);
void func_ov001_02196cd0(void);
void func_ov001_02196d78(void);
void func_ov001_02196d8c(void);
void func_ov001_02196da8(void);
void func_ov001_02196dbc(void);
void func_ov001_02196e30(void);
void func_ov001_02196e54(void);
void func_ov001_02196e88(void);
void func_ov001_02196eb0(void);
void func_ov001_02196ecc(void);
void func_ov001_02196f64(void);
void func_ov001_02196f80(void);
void func_ov001_02196fb0(void);
void func_ov001_02196fc4(void);
void func_ov001_02196fd8(void);
void func_ov001_02197010(void);
void func_ov001_02197024(void);
void func_ov001_0219703c(void);
void func_ov001_02197058(void);
BOOL func_ov001_02197210(void);
void func_ov001_02197274(void);
void func_ov001_021972b4(void);
void func_ov001_021972f4(void);
void func_ov001_0219750c(u16 a);
void func_ov001_021975f4(u16 a);
void func_ov001_021978b4(void);
