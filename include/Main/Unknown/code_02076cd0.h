#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217a000.h" // Camera, Unk0217ad08
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_02073eb8.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020799a0.h"
#include "Main/Unknown/code_0207ae58.h"
#include "Main/Unknown/code_02077bc0.h"

// 0x88-byte object built from an entry of the table at CourseMap::mUnk_7c: the entry, two Unk0207b960 and two
// halfwords.
typedef struct Unk02077750 {
    /* 00 */ CourseMapCamera *mUnk_00;
    /* 04 */ Unk0207b960 mUnk_04;
    /* 40 */ Unk0207b960 mUnk_40;
    /* 7c */ s16 mUnk_7c;
    /* 7e */ s16 mUnk_7e;
    /* 80 */ s32 mUnk_80;
    /* 84 */ s32 mUnk_84;
} Unk02077750;

// Declared here until the code that defines them is decompiled.
extern const char data_usa_02165714[];

void UpdateCameraView(Camera *p);
void UpdateCameraViewWithWorldUp(Camera *p);
void RefreshCameraProjection(Camera *p);
void SetupCamera(Camera *p);
void func_020775e4(void);
void func_0207767c(void);
void func_02077750(Unk02077750 *a, CourseMapCamera *b);
void func_020777ac(u32 a);
// Allocates the chase camera (data_0217ac94), sets it up behind the selected Kart (SetupCameraBehindKart), keeps that
// Kart's forward vector in mSavedKartForward and refreshes the projection.
void CreateChaseCamera(void);
void func_02077998(void);
void func_02077a28(void *a);
u16 func_02077a4c(void);
u16 func_02077a5c(void);
u32 func_02077a70(s32 *a, u32 b);
void func_02077b1c(void);
void func_02077b3c(void);
