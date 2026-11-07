#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217a000.h" // Camera, Unk0217ad08
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_02073eb8.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020799a0.h"
#include "Main/Unknown/code_0207ae58.h"
#include "Main/Unknown/code_02077bc0.h"

// 0x88-byte object built from an entry of the table at CourseMap.mCameras: the entry, two PosCurve and two
// halfwords.
typedef struct Unk02077750 {
    /* 00 */ CourseMapCamera *mUnk_00;
    /* 04 */ PosCurve mUnk_04;
    /* 40 */ PosCurve mUnk_40;
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
// Allocates gFirstChainCamera (0x270 bytes), sets gSecondChainCamera to NULL, runs SetupCamera, sets mKind 2, starts it
// at CourseMap.mFirstChainStartEntry and sets up its mPosCurve when the entry has a group. With no entry it sets
// gRaceProgress->mUnk_4d0 to 1 and returns. InitRace calls it when gRaceSetup->mUnk_00c is 4.
void CreateFirstChainCamera(void);
// Allocates gFirstChainCamera and gSecondChainCamera (0x270 bytes each), runs SetupCamera on both, sets mKind 2, starts
// them at CourseMap.mFirstChainStartEntry and mSecondChainStartEntry and sets up their mPosCurve when the entries have
// a group. With no first entry it sets gRaceProgress->mUnk_4d0 to 1 and returns. InitRace calls it when
// gRaceSetup->mUnk_00c is 3 or 5.
void CreateChainCameraPair(void);
void func_02077750(Unk02077750 *a, CourseMapCamera *b);
void func_020777ac(u32 a);
// Allocates the chase camera (gChaseCamera), sets it up behind the selected Kart (SetupCameraBehindKart), keeps that
// Kart's forward vector in mSavedKartForward and refreshes the projection.
void CreateChaseCamera(void);
void func_02077998(void);
void LoadEmblemSBNclr(void *a);
u16 func_02077a4c(void);
u16 func_02077a5c(void);
u32 func_02077a70(s32 *a, u32 b);
void func_02077b1c(void);
void func_02077b3c(void);
