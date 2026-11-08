#include "Main/Unknown/code_020e3618.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e7a84.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020ea588.h"

#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_021000d0.h"

#pragma thumb off

BOOL IsBridgeKind(u32 kind) {
    switch (kind) {
        case MAP_OBJECT_KIND_BRIDGE:
            return TRUE;
        default:
            return FALSE;
    }
}

#pragma thumb on

void CreateBridge(void) {
    void *file;

    file = FindCourseMapObjFile(gBridgeNsbmdName);
    CreateNsbmd(&gBridge, file, NULL);
    CreateModelAnimation(0, gBridge, &gBridgeNsbca, file, FindCourseMapObjFile(gBridgeNsbcaName));
    ((Unk020e1dc0 *) *(void **) data_0217b7c4)->mUnk_2c = GetModelAnimationFrameCountFixed(gBridgeNsbca);
    func_02084968(gBridge, 0x3f, 2, 0x294a);
    SetMapObjectsModel(*(void **) data_0217b7c4, gBridge);
}

void InitBridge(Bridge *bridge, struct CourseMapRow *courseRow) {
    bridge->mUnk_0e8 = bridge->mUnk_000.mPos;
    bridge->mUnk_0a0 = *(Unk020e38a0_28 *) &bridge->mUnk_000.mMatrix;
    bridge->mUnk_0c4 = *(Unk020e38a0_28 *) &bridge->mUnk_000.mMatrix;
    bridge->mUnk_124.x = 0;
    bridge->mUnk_124.y = 0;
    bridge->mUnk_124.z = 0;
    bridge->mUnk_130 = 1;
    bridge->mUnk_144 = ((courseRow->mUnk_28 * 0x10000) / 0x168) >> 1;
    bridge->mUnk_146 = (0x10000 / courseRow->mUnk_2a) >> 1;
    bridge->mUnk_14c = courseRow->mUnk_2c;
    bridge->mUnk_14e = courseRow->mUnk_2e;
    bridge->mUnk_150 = 0;
    bridge->mUnk_148 = 0;
    if (gRaceSetup->mMode == 5) {
        bridge->mUnk_146 = 0;
        bridge->mUnk_148 = ((courseRow->mUnk_30 * 0x10000) / 0x168) >> 1;
    }
    bridge->mUnk_100 = ((s64) bridge->mUnk_000.mScale.x * 0x5a000) >> 12;
    bridge->mUnk_104 = (s32) (((s64) bridge->mUnk_000.mScale.y * 0x1e000) >> 12) >> 1;
    bridge->mUnk_108 = ((s64) bridge->mUnk_000.mScale.z * 0x15e000) >> 12;
    bridge->mUnk_10c = ((s64) bridge->mUnk_000.mScale.z * 0x32000) >> 12;
    bridge->mUnk_110 = 0;
    bridge->mUnk_114.x = 1;
    bridge->mUnk_114.y = 0;
    bridge->mUnk_114.z = 1;
    bridge->mUnk_120 = 0x800;
    bridge->mUnk_134 = 0;
    bridge->mUnk_138 = 0;
    bridge->mUnk_000.mFlags |= data_02158c88;
    bridge->mUnk_000.mFlags &= ~2;
    bridge->mUnk_000.mFlags &= ~8;
    bridge->mUnk_000.mAlpha = 0x1f;
    if (courseRow->mUnk_0c.y < 0) {
        CreateMapObjectSoundSourceFalloff4(&bridge->mUnk_000);
    }
}

#pragma thumb off

void *CreateChoropuKindData(void) {
    Unk020e03f8 *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = *(const Unk020e03f8 *) data_02158c3c;
    return kindData;
}

void *CreateChoropuDrawList(void) {
    void *drawList;

    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    data_0217b7bc = drawList;
    *(Unk020e039c *) drawList = *(const Unk020e039c *) data_02158c10;
    func_020d49d8(&data_0217b7bc);
    return data_0217b7bc;
}

void *CreateChoropuShadowDrawList(void) {
    void *drawList;

    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    data_0217b7c0 = drawList;
    *(Unk020e039c *) drawList = *(const Unk020e039c *) data_02158be4;
    func_020d49d8(&data_0217b7c0);
    return data_0217b7c0;
}

void *CreateChoropuUpdateList(void) {
    void *updateList;

    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    data_0217b7b4 = updateList;
    *(Unk020e0340 *) updateList = *(const Unk020e0340 *) data_02158bbc;
    func_020e6f50(&data_0217b7b4);
    return data_0217b7b4;
}

void SetupDrawChoropu(void) {
    func_020e6a18(gChoropu);
}

void DrawChoropu(s32 a, Unk020e1e98 *choropu, s32 c, u16 alpha) {
    MtxFx43 *matrix;

    switch (choropu->mUnk_000.mStateMachine.mState) {
        case 4:
            gChoropu->mUnk_18 = 1;
            matrix = SetViewTransposeMatrixPos(&choropu->mUnk_000.mPos);
            func_020e67c4(gChoropu, matrix, &choropu->mUnk_000.mScale, 0, alpha);
            break;
        case 5:
            break;
        case 6:
        case 7:
            gChoropu->mUnk_18 = 1;
            matrix = SetViewTransposeMatrixPos(&choropu->mUnk_000.mPos);
            func_020e66e4(gChoropu, matrix, choropu->mUnk_0b4.mUnk_04, &choropu->mUnk_000.mScale, 0, alpha);
            break;
        default:
            gChoropu->mUnk_18 = 0;
            matrix = SetViewTransposeMatrixPos(&choropu->mUnk_000.mPos);
            func_020e67c4(gChoropu, matrix, &choropu->mUnk_000.mScale, 0, alpha);
    }
}
