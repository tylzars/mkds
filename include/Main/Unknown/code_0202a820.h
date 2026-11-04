#pragma once

#include "types.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_020d22c0.h"

// Object behind gWiFiVSCourseSelect, 0x158 bytes (InitWiFiVSCourseSelect allocates it).
typedef struct Unk02174e28 {
    /* 000 */ Unk02174e60_00 mUnk_000[2];
    /* 048 */ Unk02174e14_00 mUnk_048;
    /* 064 */ Unk02174e14_00 mUnk_064;
    /* 080 */ void *mUnk_080[2];
    /* 088 */ void *mUnk_088;
    /* 08c */ void *mUnk_08c;
    /* 090 */ void *mHeap;
    /* 094 */ Unk020f41c4_B mUnk_094;
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ s32 mUnk_0b0;
    /* 0b4 */ s32 mUnk_0b4;
    /* 0b8 */ s32 mUnk_0b8;
    /* 0bc */ s32 mUnk_0bc[4];
    /* 0cc */ Unk02025ebc mUnk_0cc[3];
    /* 0fc */ Unk02025ebc mUnk_0fc[4];
    /* 13c */ s32 mUnk_13c;
    /* 140 */ s32 mUnk_140;
    /* 144 */ s32 mUnk_144;
    /* 148 */ s32 mUnk_148;
    /* 14c */ u16 mUnk_14c[4];
    /* 154 */ s16 mUnk_154;
} Unk02174e28;

// 8-byte entries of the tables at data_usa_021539f4 and data_usa_02153a14.
typedef struct Unk021539f4 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
} Unk021539f4;

extern char gCommonBmgName3[];
extern char gWiFiBmgName[];
extern char gWiFiVSCourseSelectMBNcgrName[];
extern char gWiFiVSCourseSelectMBNclrName[];
extern char gWiFiVSCourseSelectMNscrName[];
extern char gWiFiVSCourseSelectMNcgrName[];
extern char gWiFiVSCourseSelectMNcerName[];
extern char gWiFiVSCourseSelectMONclrName[];
extern char gWiFiVSCourseSelectMBnclName[];
extern char gWiFiVSCourseSelectMBnllName[];
extern char gWiFiVSCourseSelectSBNcgrName[];
extern char gWiFiVSCourseSelectSBNclrName[];
extern char gWiFiVSCourseSelectSNscrName[];
extern char gWiFiVSCourseSelectSNcgrName[];
extern char gWiFiVSCourseSelectSNcerName[];
extern char gWiFiVSCourseSelectSONclrName[];
extern char gWiFiVSCourseSelectSBnclName[];
extern char gWiFiVSCourseSelectSBnllName[];
extern char gWiFiVSCourseSelectSBnblName[];

s32 AdvanceWiFiVSCourseSelect(void);
void InitWiFiVSCourseSelect(u32 param_1, void *param_2, void *param_3);

extern u16 data_usa_021539d8[];
extern u16 data_usa_021539e0[];
extern Unk021539f4 data_usa_021539f4[];
extern Unk021539f4 data_usa_02153a14[];
extern s32 data_usa_02153a4c[];

void func_0202a820(void);
void func_0202a90c(void);
s32 func_0202af60(void);
void func_0202afe4(void);
void func_0202b100(void);
void func_0202b264(void);
void func_0202b2bc(void);
void func_0202b3f4(void);
void func_0202b4bc(s32 a, s32 b, s32 c, s32 d);
void func_0202b554(s32 a, s32 b);
void func_0202cb2c(s32 a);
void func_0202cb68(s32 a);
