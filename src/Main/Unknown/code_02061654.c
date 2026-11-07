#include "Main/Unknown/code_02061654.h"

#include "Main/Unknown/code_02056b30.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0203ca20.h"
#include "Main/Unknown/code_0207a30c.h"
#include "Main/Unknown/code_02062ed8.h"
#include "Main/Unknown/code_02036820.h"
#include "registers.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_02076cd0.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02063000.h"
#include "Main/Unknown/code_0203d568.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0208eb10.h"
#include "Main/Unknown/code_02017000.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_02075000.h"
#include "Main/Unknown/code_02076000.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_02078000.h"
#include "code_02013740.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"
#include "Main/Unknown/unk_02155000.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_02073e04.h"
#include "Main/Unknown/code_02073e98.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_02086e8c.h"
#include "Main/Unknown/code_02088338.h"
#include "Main/Unknown/code_02089fa0.h"
#include "Main/Unknown/code_02018000.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_0208533c.h"
#include "Main/Unknown/code_0203c5ac.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/code_020a02f8.h"
#include "Main/Unknown/code_020af66c.h"
#include "Main/Unknown/code_020d2d94.h"
#include "Main/Unknown/code_020d2dec.h"
#include "Main/Unknown/code_020d4130.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d50c4.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020e7a84.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_02148d24.h"
#include "code_0214a730.h"
#include "code_02010c84.h"
#include "code_02012b20.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "00/code_021832d8.h"
#include "00/code_02181f98.h"
#include "code_02015f98.h"
#include "code_020162b0.h"
#include "code_0214a748.h"
#include "Main/Unknown/code_02042064.h"
#include "01/code_0218155c.h"
#include "Main/Unknown/code_0203ca38.h"

u32 GetRaceUseChainCameras(void) {
    return (gRace->mUseChainCameras);
}

u32 IsRaceAwardOrStaffRoll(void) {
    return (gRace->mIsAwardOrStaffRoll);
}

// Builds the race world and gRace. Not part of it: the screen and 3D engine set-up (Init3dEngine, called before), the
// net and the HUD, which are in the scene slot InitRaceScene.
void InitRace(void) {
    void *a;
    u16 b;
    s16 i;
    u16 j;

    a = GetHeap(func_020364e8());
    SetKartModelPathPrefix(0);
    gRace = HeapAlloc(a, 72);
    InitRaceFields();
    b = GX_GetBankForTex();
    NNS_GfdInitFrmTexVramManager(((b >> 3) & 1) + ((b >> 2) & 1) + ((b >> 1) & 1) + (b & 1), 1);
    NNS_GfdInitFrmPlttVramManager(0x10000, 1);
    func_0208533c();
    func_02077998();
    SetHeapGroupId(1);
    func_020875b4();
    InitKartModels(a, gRaceSetup->mKartCount);
    func_0207800c();
    func_020872a4();
    func_02047728();
    InitMap2D();
    SetHeapGroupId(2);
    CreateCourseMap(a);
    InitCourseModels(a);
    func_020476ec();
    SetHeapGroupId(7);
    CreateRaceProgress(a);
    func_0205cd24(a);
    SetHeapGroupId(2);
    InitCourseCollision();
    SetHeapGroupId(8);
    func_020d58c0();
    SetHeapGroupId(1);
    func_0208aa30(a);
    InitKartAiShared();
    InitKarts(gRaceSetup->mKartCount);
    CreateChaseCamera();
    func_020777ac(gRaceSetup->mFollowedKartIndex);
    if (gRace->mUseChainCameras != 0) {
        if (gRace->mUseFirstChainCamera != 0) {
            CreateFirstChainCamera();
        } else {
            CreateChainCameraPair();
        }
    }
    gRaceChaseCamera = GetChaseCamera();
    gRaceEntryCamera = func_02074898();
    gCurrentCamera = gRaceChaseCamera;
    gCurrentViewMatrix = &gRaceChaseCamera->mViewMatrix;
    RefreshCameraProjection(gRaceChaseCamera);
    SetHeapGroupId(3);
    switch (gRaceSetup->mMode) {
        case MODE_BATTLE:
            InitStandings();
            break;
        case MODE_MISSION_RUN:
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                CreateMissionRunData();
            }
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                InitStandings();
            }
            break;
    }
    SetHeapGroupId(3);
    func_020e7460();
    func_020e7760();
    InitMapObjects();
    InitItems();
    SetHeapGroupId(6);
    func_0208b934(a);
    func_020846c0(a);
    InitModelEffects(a);
    InitPosStrips(a);
    SetHeapGroupId(9);
    *(u16 *) 0x05000000 = 0xff00;
    reg_G3X_DISP3DCNT = reg_G3X_DISP3DCNT & 0xffffcffd;
    G3X_SetToonTable(data_0217aadc);
    for (i = 0; i < 8; i++) {
        data_0217aadc[i] = data_02154970[i];
        data_0217aadc[i + 16] = data_02154980[i];
    }
    for (i = 0; i < 8; i++) {
        data_0217aadc[i + 8] = data_0217aadc[i];
        data_0217aadc[i + 24] = data_0217aadc[i + 16];
    }
    InitRaceFog();
    SetKoopaCourseLight2();
    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        for (j = 0; j < 3; j++) {
            StartAwardKartPosStrip(j);
        }
    }
}

void InitRaceFields(void) {
    Vec3 v;
    s32 m;

    gRace->mUpdateFrames = 0;
    gRace->mDrawFrames = 0;
    gRace->mUpdateFramesModKartCount = 0;
    gRace->mUpdateFramesMod2 = 0;
    gRace->mUpdateFramesMod8 = 0;
    gRace->mToonTableOffset = 0;
    gRace->mToonTableFrames = 0;
    gRace->mUpdateFramesLimitReached = FALSE;
    gRace->mUpdateFramesUnlimited = FALSE;
    gRace->mUpdateFramesAtEntryEnd = 0;
    v = data_021653f0;
    gRace->mLightVectorX = v.x;
    gRace->mLightVectorY = v.y;
    gRace->mLightVectorZ = v.z;
    gRace->mUseChainCameras = (gRaceSetup->mRaceKind - 3) <= 2 ? 1 : 0;
    gRace->mUseFirstChainCamera = gRaceSetup->mRaceKind == 4 ? 1 : 0;
    gRace->mIsAwardOrStaffRoll =
        (gRaceSetup->mRaceKind == RACE_KIND_AWARD || gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) != 0 ? 1 : 0;
    gRace->mStarted = gRace->mIsAwardOrStaffRoll != 0 ? 1 : 0;
}

void func_020629a4(void) {
    u16 b;

    b = GX_GetBankForTex();
    NNS_GfdInitFrmTexVramManager(((b >> 3) & 1) + ((b >> 2) & 1) + ((b >> 1) & 1) + (b & 1), 1);
    NNS_GfdInitFrmPlttVramManager(0x10000, 1);
    func_0208533c();
}

void Init3dEngine(void) {
    NNS_G3dInit();
    NNS_G3dGlbInit();
    func_01ff92b4();
    NNS_G3dGeUseFastDma(1);
    data_021759d0->mUnk_1c |= 8;
    NNS_G3dGlbLightVector(0, 0, -0x1000, 0);
    NNS_G3dGlbLightVector(1, 0x93d, 0x93d, 0x93d);
    NNS_G3dGlbLightVector(2, 0, -0x1000, 0);
    NNS_G3dGlbLightVector(3, 0, 0xfff, 0);
    NNS_G3dGlbLightColor(0, 0x7fff);
    NNS_G3dGlbLightColor(1, 0x6318);
    NNS_G3dGlbLightColor(2, 31);
    NNS_G3dGlbLightColor(3, 0x3ff);
    NNS_G3dGlbMaterialColorDiffAmb(0x5294, 0x5294, 0);
    NNS_G3dGlbMaterialColorSpecEmi(0, 0, 1);
    NNS_G3dGlbPolygonAttr(15, 0, 2, 0, 31, 0);
    data_0217aa74 = HeapAlloc(data_021759d0->mHeap, 772);
    func_01ff92e0(data_0217aa74);
}

// Advances the race one frame. Skipped while func_02049b6c or func_0204359c refuse (the draw is not), and in kind 6 for
// the first 0x708 frames (neither update nor draw). The HUD step and the end-of-race state are in the scene slot
// UpdateRaceScene, which calls this; the exit loop also runs it with a == NULL.
void UpdateRace(void) {
    void *v;

    data_0217d020 = 1;
    func_01ffdb70();
    UpdateCourseModels();
    UpdateKarts();
    if (gRace->mUpdateFramesMod8 == 0) {
        UpdateKartAiShared();
    }
    switch (gRaceSetup->mMode) {
        case MODE_BATTLE:
            UpdateStandings();
            break;
        case MODE_MISSION_RUN:
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                UpdateMissionRunData();
            }
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                UpdateStandings();
            }
            break;
    }
    ClearCameraEntryFlags();
    if (gRace->mUseChainCameras != 0) {
        if (gRace->mUseFirstChainCamera != 0) {
            v = UpdateFirstChainCamera();
        } else {
            v = UpdateChainCameraPair();
        }
        gCurrentViewMatrix = v;
        gCurrentCamera = GetCurrentChainCamera();
    } else if (func_0203c5e4() != 0) {
        UpdateChaseCamera(gRaceChaseCamera, GetKart(gRaceSetup->mFollowedKartIndex));
        UpdateCameraView(gRaceChaseCamera);
        if (TryUpdateEntryCamera(gRaceEntryCamera) != 0) {
            gCurrentCamera = gRaceEntryCamera;
            gCurrentViewMatrix = &gRaceEntryCamera->mViewMatrix;
        } else {
            gCurrentCamera = gRaceChaseCamera;
            gCurrentViewMatrix = &gRaceChaseCamera->mViewMatrix;
        }
    } else {
        UpdateChaseCamera(gRaceChaseCamera, GetKart(gRaceSetup->mEntryIndex));
        UpdateCameraView(gRaceChaseCamera);
        gCurrentCamera = gRaceChaseCamera;
        gCurrentViewMatrix = &gRaceChaseCamera->mViewMatrix;
    }
    RefreshCameraProjection(gCurrentCamera);
    UpdateViewFrustum((Unk020d4f94 *) gCurrentViewMatrix);
    if (GetCameraEntryChanged() != 0) {
        RequestViewTestRefresh();
    }
    UpdateItems();
    UpdateJg();
    UpdateMapObjects();
    UpdateModelEffects();
    UpdatePosStrips();
    func_0208b8c8();
    if (gFadeFogActive != 0) {
        if (gFadeFogStepping != 0) {
            if (data_021653e8 == 0) {
                gRace->mFadeFog = 0;
                SetKartModelsFogEnable(1);
                SetCourseModelsFogEnableFlags(0);
                gFadeFogActive = 0;
                gFadeFogStepping = 0;
            } else {
                BuildFadeFog(data_021653e8, 0);
            }
            data_021653e8 -= 4;
        } else {
            gFadeFogHoldFrames++;
            if (gFadeFogHoldFrames >= 72) {
                gFadeFogStepping = 1;
            }
        }
    }
    func_0208a218();
    UpdateRaceProgress();
    UpdateKartSoundDistancesSquared();
    func_0208677c();
    if (gRaceSetup->mMode == 5) {
        if (gRace->mUpdateFramesUnlimited == FALSE) {
            if (gRace->mUpdateFramesLimitReached == FALSE) {
                gRace->mUpdateFrames++;
                if ((u32) gRace->mUpdateFrames >= 128) {
                    gRace->mUpdateFramesLimitReached = TRUE;
                }
            }
        } else {
            gRace->mUpdateFrames++;
        }
    } else {
        gRace->mUpdateFrames++;
    }
    gRace->mUpdateFramesMod8 = gRace->mUpdateFrames & 7;
    gRace->mUpdateFramesMod2 = gRace->mUpdateFrames & 1;
    gRace->mUpdateFramesModKartCount = (u32) gRace->mUpdateFrames % gRaceSetup->mKartCount;
    G3X_SetToonTable(&data_0217aadc[gRace->mToonTableOffset]);
    gRace->mToonTableFrames++;
    if ((u32) gRace->mToonTableFrames > data_021653ec) {
        gRace->mToonTableFrames = 0;
        gRace->mToonTableOffset++;
    }
    if ((u32) gRace->mToonTableOffset > 7) {
        gRace->mToonTableOffset = 0;
    }
}

// Draws the 3D scene and writes the fog registers when the fade state changes; advances no game value. Has its own gate
// in the scene slot; the HUD draw is in the scene slot too.
void DrawRace(void) {
    if (gFadeFogStepping != 0) {
        G3X_SetFog(1, 0, data_0217aa80, gFadeFogOffset);
        G3X_SetFogTable(gFadeFogTable);
        reg_G3X_FOG_COLOR = data_0217aa28 | (data_0217aa68 << 16);
    } else if (gRace->mFadeFog != gRace->mDrawnFadeFog) {
        if (gRace->mFadeFog == 0) {
            if (gCourseMap->mSettings->mFogEnabled != 0) {
                G3X_SetFog(1, 0, data_0217aa80, gCourseFogOffset);
                reg_G3X_FOG_COLOR = data_0217aa38 | (data_0217aa50 << 16);
                G3X_SetFogTable(gCourseFogTable);
            } else {
                G3X_SetFog(0, 0, 5, 0);
            }
        } else {
            G3X_SetFog(1, 0, data_0217aa80, 0);
            reg_G3X_FOG_COLOR = data_0217aa30 | (data_0217aa60 << 16);
            G3X_SetFogTable(gFadeFogTable);
        }
    }
    gRace->mDrawnFadeFog = gRace->mFadeFog;
    DrawRaceWorld();
    func_0208b870(gCurrentViewMatrix);
    DrawPosStrips(gCurrentViewMatrix);
    func_02089fa0();
    if (gRace->mUseChainCameras == 0) {
        func_02086250(gCurrentViewMatrix);
    }
    DrawOrthoQuads();
    gRace->mDrawFrames++;
}

void SetRaceLightVector(const Vec3 *a) {
    gRace->mLightVectorX = a->x;
    gRace->mLightVectorY = a->y;
    gRace->mLightVectorZ = a->z;
}

void DrawRaceWorld(void) {
    Vec3 c;
    Vec3 a;
    Vec3 b;
    u32 v;
    Camera *p;

    ApplyCameraFrustum(gCurrentCamera, 1);
    ApplyCameraLookAt(gCurrentCamera);
    p = gCurrentCamera;
    NNS_G3dGlbLightVector(0, gRace->mLightVectorX, gRace->mLightVectorY, gRace->mLightVectorZ);
    NNS_G3dGlbLightColor(0, 0x7fff);
    a.x = p->mViewMatrix.mUnk_00[0].y;
    a.y = p->mViewMatrix.mUnk_00[1].y;
    a.z = p->mViewMatrix.mUnk_00[2].y;
    b.x = -p->mViewMatrix.mUnk_00[0].z;
    b.y = -p->mViewMatrix.mUnk_00[1].z;
    b.z = -p->mViewMatrix.mUnk_00[2].z;
    VEC_Subtract(&b, &a, &c);
    if ((s64) c.x * c.x + (s64) c.y * c.y + (s64) c.z * c.z >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(&c, &c);
    }
    NNS_G3dGlbLightVector(1, (s16) c.x, (s16) c.y, (s16) c.z);
    NNS_G3dGlbLightColor(1, 0x7fff);
    NNS_G3dGlbFlushP();
    func_01ff9048(23, gCurrentViewMatrix, 12);
    v = 30;
    func_01ff9048(19, &v, 1);
    DrawCourseModelV();
    ApplyCameraFrustum(gCurrentCamera, 0);
    NNS_G3dGlbFlushP();
    func_01ff92e0(data_0217aa74);
    DrawCourseModel();
    func_020d4418((Unk020d4418 *) gCurrentCamera);
    func_01ff92b4();
    DrawKarts();
    NNS_G3dGlbLightVector(0, gRace->mLightVectorX, gRace->mLightVectorY, gRace->mLightVectorZ);
    DrawJg();
    DrawMapObjects((Unk020d4418 *) gCurrentCamera);
    DrawItems(gCurrentViewMatrix);
    DrawModelEffects();
    func_01ff9234();
}

void func_02062004(void) {
    WiFiSession *p;
    BOOL f;

    func_020d2d94();
    func_0207a990();
    ReleaseAllResFiles();
    func_0203d568();
    f = FALSE;
    p = gWiFiSession;
    if (p != NULL && p->mHeapCreated != FALSE) {
        f = TRUE;
    }
    if (f != FALSE) {
        p->mKartMask = data_0217aa14->mUnk_749;
    }
    data_0217aa14 = NULL;
}

void func_02062000(void) {}

u32 IsRaceStarted(void) {
    return (gRace->mStarted);
}

void StartRace(void) {
    gRace->mStarted = 1;
    StartRaceClock();
}

u32 GetRaceUpdateFrames(void) {
    return (gRace->mUpdateFrames);
}

u32 GetRaceUpdateFramesModKartCount(void) {
    return (gRace->mUpdateFramesModKartCount);
}

u32 GetRaceUpdateFramesMod8(void) {
    return (gRace->mUpdateFramesMod8);
}

u32 GetRaceUpdateFramesMod2(void) {
    return (gRace->mUpdateFramesMod2);
}

// Also writes FOG_COLOR, FOG_OFFSET and FOG_TABLE directly and resets the fade state.
void InitRaceFog(void) {
    u32 a[32];
    u16 i;
    u8 m;

    BuildFadeFog(72, 1);
    data_021653e8 = 72;
    gFadeFogStepping = 0;
    gFadeFogActive = 0;
    gFadeFogHoldFrames = 0;
    gRace->mDrawnFadeFog = 0;
    gRace->mFadeFog = gRace->mDrawnFadeFog;
    if (gCourseMap->mSettings->mFogEnabled != 0) {
        m = gCourseMap->mSettings->mFogTableMode;
        if (m == 0) {
            for (i = 0; i < 8; i++) {
                gCourseFogTable[i] =
                    ((i * 4) << 2) | ((i * 16 + 4) << 8) | ((i * 16 + 8) << 16) | ((i * 16 + 12) << 24);
            }
        } else if (m == 1) {
            for (i = 0; i < 32; i++) {
                a[i] = ((i + 1) * (i + 1)) / 8;
                if (a[i] > 127) {
                    a[i] = 127;
                }
            }
            a[0] = 0;
            for (i = 0; i < 8; i++) {
                gCourseFogTable[i] = a[i * 4] | (a[i * 4 + 1] << 8) | (a[i * 4 + 2] << 16) | (a[i * 4 + 3] << 24);
            }
        } else if (m == 2) {
            for (i = 0; i < 32; i++) {
                a[i] = 128 - ((32 - (i + 1)) * (32 - (i + 1))) / 8;
                if (a[i] > 127) {
                    a[i] = 127;
                }
            }
            a[0] = 0;
            for (i = 0; i < 8; i++) {
                gCourseFogTable[i] = a[i * 4] | (a[i * 4 + 1] << 8) | (a[i * 4 + 2] << 16) | (a[i * 4 + 3] << 24);
            }
        }
        data_0217aa38 = gCourseMap->mSettings->mColorAndFogAlpha & 0x7fff;
        data_0217aa50 = ((u32) gCourseMap->mSettings->mColorAndFogAlpha >> 15) & 31;
        data_0217aa80 = gCourseMap->mSettings->mUnk_07;
        gCourseFogOffset = gCourseMap->mSettings->mFogOffset / 512;
        data_0217aa40 = data_0217aa38 & 31;
        data_0217aa34 = (data_0217aa38 >> 5) & 31;
        data_0217aa3c = (data_0217aa38 >> 10) & 31;
    }
    if (gCourseMap->mSettings->mFogEnabled != 0) {
        G3X_SetFog(1, 0, data_0217aa80, gCourseFogOffset);
        reg_G3X_FOG_COLOR = data_0217aa38 | (data_0217aa50 << 16);
        G3X_SetFogTable(gCourseFogTable);
    } else {
        G3X_SetFog(0, 0, 5, 0);
    }
}

void BuildFadeFog(s32 a, s32 b) {
    s32 t;
    s32 u;
    u32 j;
    u32 w;
    u16 i;
    s32 e;

    if (gCourseMap->mSettings->mFogEnabled != 0 && b == 0) {
        t = ((s64) 57 * (a << 12) + 0x800) >> 12;
        data_0217aa78 = t;
        u = 4096 - t;
        data_0217aa84 = u;
        data_0217aa44 = ((s64) t * 72 + 0x800) >> 12;
        data_0217aa28 = (s32) (((s64) data_0217aa40 * u + 0x800) >> 12) +
                        ((s32) (((s64) data_0217aa34 * u + 0x800) >> 12) << 5) +
                        ((s32) (((s64) data_0217aa3c * u + 0x800) >> 12) << 10);
        data_0217aa68 =
            (s32) (((s64) u * data_0217aa50 + 0x800) >> 12) + (s32) (((s64) t * data_0217aa60 + 0x800) >> 12);
        gFadeFogOffset = ((s64) u * gCourseFogOffset + 0x800) >> 12;
        for (i = 0; i < 8; i++) {
            w = gCourseFogTable[i];
            data_0217aa8c[0] = w & 0xff;
            data_0217aa8c[1] = (w & 0xff00) >> 8;
            data_0217aa8c[2] = (w & 0xff0000) >> 16;
            data_0217aa8c[3] = (w & 0xff000000) >> 24;
            for (j = 0; j < 4; j++) {
                e = data_0217aa8c[j];
                data_0217aa8c[j] = (s32) (((s64) e * (s32) u + 0x800) >> 12) + data_0217aa44;
            }
            gFadeFogTable[i] =
                data_0217aa8c[0] | (data_0217aa8c[1] << 8) | (data_0217aa8c[2] << 16) | (data_0217aa8c[3] << 24);
        }
        data_0217aa58 = w;
    } else {
        for (i = 0; i < 8; i++) {
            gFadeFogTable[i] = a | (a << 8) | (a << 16) | (a << 24);
        }
    }
}

void StartFadeFog(void) {
    if (gRace->mDrawnFadeFog == 1) {
        gRace->mDrawnFadeFog = 0;
    }
    gRace->mFadeFog = 1;
    SetKartModelsFogEnable(0);
    SetCourseModelsFogEnableFlags(1);
    data_021653e8 = 72;
    BuildFadeFog(72, 1);
    gFadeFogStepping = 0;
    gFadeFogActive = 1;
    gFadeFogHoldFrames = 0;
    gFadeFogOffset = 0;
    data_0217aa28 = data_0217aa30;
    data_0217aa68 = data_0217aa60;
}

void ClearFadeFogHoldFrames(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gFadeFogHoldFrames;
    value1 = 0u;
    *(u16 *) ((value0) + (0)) = value1;
}

void SetFadeFogHoldFramesToLimit(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gFadeFogHoldFrames;
    value1 = 0x48u;
    *(u16 *) ((value0) + (0)) = value1;
}

u32 IsFadeFogActive(void) {
    return (gFadeFogActive);
}

MtxFx43 *GetCurrentViewMatrix(void) {
    return gCurrentViewMatrix;
}

u32 GetCurrentCameraKind(void) {
    return (gCurrentCamera->mKind);
}

// The camera used this frame: gCurrentCamera (returned as void *).
void *GetCurrentCamera(void) {
    return (void *) ((u32) gCurrentCamera);
}

u32 SetRaceUpdateFramesUnlimited(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRace;
    value1 = 1u;
    value0 = *(const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (52)) = value1;
    return value0;
}

u32 SetRaceUpdateFramesAtEntryEnd(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRace;
    value1 = *(const u32 *) ((value0) + (0));
    value0 = gRace->mUpdateFrames;
    gRace->mUpdateFramesAtEntryEnd = value0;
    return value0;
}

s32 TryGetRaceUpdateFramesSinceEntryEnd(u32 *a) {
    Race *b;
    BOOL c;

    b = gRace;
    c = FALSE;
    if (b->mUpdateFramesAtEntryEnd != 0) {
        c = TRUE;
        *a = b->mUpdateFrames - b->mUpdateFramesAtEntryEnd;
    }
    return c;
}

s32 GetMapObjectFirstPolygonId(void) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        return 0x2e;
    }
    return 0x1f;
}

u16 GetSplMaxPolyId(void) {
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        return 0x2d;
    }
    return 0x1e;
}

BOOL IsGhostRecordFilled(void *v) {
    GhostRecord *a = v;

    if (a->mFilled == 1) {
        return TRUE;
    }
    return FALSE;
}

BOOL GetGhostRecordTime(void *v, TimeRecord *b) {
    GhostRecord *a = v;

    if (a->mFilled != 1) {
        return FALSE;
    }
    b->mMinute = a->mMinute;
    b->mSecond = a->mSecond;
    b->mMillisecond = a->mMillisecond;
    return TRUE;
}

BOOL GetGhostRecordName(void *v, void *b) {
    GhostRecord *a = v;

    if (a->mFilled != 1) {
        return FALSE;
    }
    MI_CpuCopy8(a->mName, b, 0x14);
    return TRUE;
}

s32 GetGhostRecordCharacterIndex(void *v) {
    GhostRecord *a = v;

    if (a->mFilled != 1) {
        return -1;
    }
    return a->mCharacterIndex;
}

s32 GetGhostRecordKartIndex(void *v) {
    GhostRecord *a = v;

    if (a->mFilled != 1) {
        return -1;
    }
    return a->mKartIndex;
}

u32 GetGhostRecordCourseId(void *v) {
    GhostRecord *a = v;

    if (a->mFilled != 1) {
        return 0;
    }
    return a->mCourseId;
}
