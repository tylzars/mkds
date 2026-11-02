#pragma once

#include "types.h"
#include "Main/Unknown/code_0202a820.h"
#include "Main/Unknown/code_02036c90.h"

// 8-byte entries of the tables at data_usa_021539f4 and data_usa_02153a14.
typedef struct Unk021539f4 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
} Unk021539f4;

extern u16 data_usa_021539d8[];
extern u16 data_usa_021539e0[];
extern Unk021539f4 data_usa_021539f4[];
extern Unk021539f4 data_usa_02153a14[];
extern s32 data_usa_02153a4c[];
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
void InitWiFiVSCourseSelect(u32 param_1, u32 param_2, u32 param_3);
s32 func_0202af60(void);
void func_0202afe4(void);
void func_0202b100(void);
void func_0202b264(void);
void func_0202b2bc(void);
void func_0202b3f4(void);
void func_0202b4bc(s32 a, s32 b, s32 c, s32 d);
void func_0202b554(s32 a, s32 b);

// Declared here until the code that defines them is decompiled.
void func_0202cb2c(s32 a);
void func_0202cb68(s32 a);
