#include "Main/Unknown/code_020ad2dc.h"
#include "registers.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_02090354.h"

#include "Main/Unknown/code_020ad32c.h"
#include "Main/Unknown/code_020ad344.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_02045000.h"
#include "Main/Unknown/code_0204aa04.h"
#include "Main/Unknown/code_02090000.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125de0.h"
#include "code_02148950.h"
#include "Main/Unknown/code_020acaa4.h"
#include "Main/Unknown/code_020ad268.h"
#include "Main/Unknown/code_020ad820.h"
#include "Main/Unknown/code_020ad870.h"
#include "Main/Unknown/code_020ad8a4.h"
#include "Main/Unknown/code_020ad8e0.h"
#include "Main/Unknown/code_020ad9fc.h"
#include "Main/Unknown/code_020ada10.h"
#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_020cee0c.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_0214a390.h"
#include "code_0214b338.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_02044618.h"

void *func_020ada10(void) {
    return GetHeap(GetCurrentHeapCall());
}

u32 GetTitleBlendDone(void) {
    return (data_0217b488->mUnk_00);
}

void func_020ad9c0(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    SetBg1Record(a->mMainBgRecords, b, c, d, e, f, g, h);
}

void func_020ad98c(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    SetBg2RecordParams(a->mMainBgRecords, b, c, d, e, f, g);
}

void func_020ad958(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    SetBg3RecordParams(a->mMainBgRecords, b, c, d, e, f, g);
}

void func_020ad924(Unk02180774 *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    SetBg3RecordParams(a->mSubBgRecords, b, c, d, e, f, g);
}

void func_020ad904(u32 a) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | a;
}

void func_020ad8e0(u32 a) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | a;
}

void func_020ad8a4(u32 a, u32 b, u32 c, u32 d) {
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, a, b, c, d);
}

u32 func_020ad88c(u32 a) {
    u32 v = (reg_GX_DISPCNT & ~0xe000u) | (a << 13);
    reg_GX_DISPCNT = v;
    return v;
}

u32 func_020ad870(u32 a) {
    u32 v = (reg_GXS_DB_DISPCNT & ~0xe000u) | (a << 13);
    reg_GXS_DB_DISPCNT = v;
    return v;
}

void func_020ad85c(u32 p0) {
    data_0217b488->mUnk_04 = p0;
}

void func_020ad848(u32 p0) {
    data_0217b488->mUnk_08 = p0;
}

void func_020ad834(u32 p0) {
    data_0217b488->mUnk_10 = p0;
}

void func_020ad820(u32 p0) {
    data_0217b488->mUnk_14 = p0;
}

#pragma thumb on

void CreateTitleScene(void) {
    s32 useTrueFiles;
    s32 d;
    void *displaySettings;
    Unk02125de0Arg s;

    useTrueFiles = IsAllGrandPrixRecordsTopRank();
    gTitleScene = HeapAlloc(func_020ada10(), 0x8bc);
    gTitleScene->mStateFrames = 0;
    gTitleScene->mStateChanged = TRUE;
    gTitleScene->mPrevState = 0;
    gTitleScene->mState = 0;
    gTitleScene->mNextState = 8;
    gTitleScene->mNoInputFrames = 0;
    gTitleScene->mBlendDone = GetTitleBlendDone() != 0;
    gTitleScene->mSelectedIndex = 0;
    gTitleScene->mSelectedPressed = FALSE;
    gTitleScene->mPreferEntry4 = TRUE;
    gTitleScene->mSelectedOffset = 0;
    gTitleScene->mBlendFrames = GetTitleBlendDone() != 0 ? 0x6b : 0;
    AdvanceTitleBlend();
    InitTitleStateHandlers();
    func_020ae6d4(&gTitleScene->mMainOam, &gTitleScene->mSubOam);
    LoadNclrData(&gTitleScene->mTitleTrueMBOrMBNclr,
                 FindSceneFileWrapper(useTrueFiles != 0 ? gTitleTrueMBNclrName : gTitleMBNclrName));
    LoadNclrData(&gTitleScene->mTitleSBNclr, FindSceneFileWrapper(gTitleSBNclrName));
    LoadNcgrData(&gTitleScene->mTitleTrueMBOrMBNcgr,
                 FindSceneFileWrapper(useTrueFiles != 0 ? gTitleTrueMBNcgrName : gTitleMBNcgrName));
    LoadNcgrData(&gTitleScene->mTitleSBNcgr, FindSceneFileWrapper(gTitleSBNcgrName));
    LoadNscrData(&gTitleScene->mTitleTrueM1OrM1Nscr,
                 FindSceneFileWrapper(useTrueFiles != 0 ? gTitleTrueM1NscrName : gTitleM1NscrName));
    LoadNscrData(&gTitleScene->mTitleTrueM2OrM2Nscr,
                 FindSceneFileWrapper(useTrueFiles != 0 ? gTitleTrueM2NscrName : gTitleM2NscrName));
    LoadNscrData(&gTitleScene->mTitleSBgNscr, FindSceneFileWrapper(gTitleSBgNscrName));
    LoadNclrData(&gTitleScene->mTitleSONclr, FindSceneFileWrapper(gTitleSONclrName));
    LoadNcgrData2(&gTitleScene->mTitleSNceNcgr, FindSceneFileWrapper(gTitleSNceNcgrName));
    LoadNcerData(&gTitleScene->mTitleSNceNcer, FindSceneFileWrapper(gTitleSNceNcerName));
    gTitleScene->mTitleSBncl = FindSceneFileWrapper(gTitleSBnclName);
    gTitleScene->mTitleSBnbl = FindSceneFileWrapper(gTitleSBnblName);
    gTitleScene->mTitleSBnll = FindSceneFileWrapper(gTitleSBnllName);
    displaySettings = CreateDisplaySettings(func_020ada10(), data_02156840);
    func_020ad9c0(displaySettings, 0, 0, 0, 0, 2, 0, 0);
    func_020ad98c(displaySettings, 2, 0, 0, 1, 14, 4);
    func_020ad958(displaySettings, 3, 0, 0, 1, 15, 4);
    func_020ad924(displaySettings, 3, 0, 0, 0, 1, 6);
    InitDisplayFromSettings(displaySettings);
    InitLayoutTable(func_020ada10(), gTitleScene->mTitleSBncl, gTitleScene->mTitleSBnll, &gTitleScene->mTitleTable);
    func_02124a98(0, 1, gTitleScene->mTitleSNceNcer, gTitleScene->mTitleSBncl);
    func_02124a98(1, 1, gTitleScene->mTitleSNceNcer, gTitleScene->mTitleSBncl);
    func_02124a98(2, 1, gTitleScene->mTitleSNceNcer, gTitleScene->mTitleSBncl);
    func_02124a98(3, 1, gTitleScene->mTitleSNceNcer, gTitleScene->mTitleSBncl);
    func_02124a98(4, 1, gTitleScene->mTitleSNceNcer, gTitleScene->mTitleSBncl);
    d = GX_GetSizeOfSubOBJ();
    d -= func_021243ac(func_020ada10(), 0, gTitleScene->mTitleSBnll, 0x55, 0xd, 0xd, gTitleScene->mTitleSNceNcer,
                       gTitleScene->mTitleSBncl, gTitleScene->mTitleTable, d);
    func_021243ac(func_020ada10(), 1, gTitleScene->mTitleSBnll, 0x55, 0xd, 0xe, gTitleScene->mTitleSNceNcer,
                  gTitleScene->mTitleSBncl, gTitleScene->mTitleTable, d);
    func_0212426c(1, 0, gTitleScene->mTitleSBnll, GetBmgEntry(FindSceneFileWrapper(gTitleBmgName), 1),
                  gTitleScene->mTitleSBncl, gTitleScene->mTitleTable);
    func_0212426c(1, 1, gTitleScene->mTitleSBnll, GetBmgEntry(FindSceneFileWrapper(gTitleBmgName2), 0),
                  gTitleScene->mTitleSBncl, gTitleScene->mTitleTable);
    GX_BeginLoadBGExtPltt();
    GX_LoadBGExtPltt(gTitleScene->mTitleTrueMBOrMBNclr->mData, 0x4000, gTitleScene->mTitleTrueMBOrMBNclr->mDataSize);
    GX_LoadBGExtPltt(gTitleScene->mTitleTrueMBOrMBNclr->mData, 0x6000, gTitleScene->mTitleTrueMBOrMBNclr->mDataSize);
    GX_EndLoadBGExtPltt();
    GX_LoadBG2Char(gTitleScene->mTitleTrueMBOrMBNcgr->mData, 0, gTitleScene->mTitleTrueMBOrMBNcgr->mDataSize);
    GX_LoadBG2Scr(gTitleScene->mTitleTrueM1OrM1Nscr->mData, 0, 0x800);
    GX_LoadBG3Scr(gTitleScene->mTitleTrueM2OrM2Nscr->mData, 0, 0x800);
    GXS_LoadBGPltt(gTitleScene->mTitleSBNclr->mData, 0, gTitleScene->mTitleSBNclr->mDataSize);
    GXS_LoadBG3Char(gTitleScene->mTitleSBNcgr->mData, 0, gTitleScene->mTitleSBNcgr->mDataSize);
    GXS_LoadBG3Scr(gTitleScene->mTitleSBgNscr->mData, 0, 0x800);
    GXS_LoadOBJPltt(gTitleScene->mTitleSONclr->mData, 0, gTitleScene->mTitleSONclr->mDataSize);
    GXS_LoadOBJ(gTitleScene->mTitleSNceNcgr->mData, 0, gTitleScene->mTitleSNceNcgr->mDataSize);
    func_020ad904(0x10);
    func_020ad8e0(0x10);
    func_020ad2f0(4, 8, 0, 0x10);
    func_020ad8a4(0, 0x3f, 6, 10);
    func_020ad88c(0);
    func_020ad870(0);
    s.mUnk_00 = 0;
    s.mUnk_04 = NULL;
    s.mUnk_08 = 0;
    s.mUnk_0c = 0;
    s.mUnk_10 = 0;
    s.mUnk_14 = 0;
    s.mUnk_18 = func_020b403c(0);
    s.mUnk_1c = 0;
    s.mUnk_20 = 0;
    s.mUnk_24 = 0;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    func_02125de0(func_020ada10(), &s);
    gTitleScene->mUnk_8b8 = func_0203bedc(func_020ada10());
    func_020acab8(0);
    func_0204aa28(0);
    ClearShuffledIndices();
    func_020ad85c(1);
    func_020ad848(0);
    func_020ad834(0);
    func_020ad820(0);
    ResetRaceSetup();
}

#pragma thumb off

#pragma thumb on

void func_020ad32c(void) {
    func_02125da0();
    gTitleScene = NULL;
}

#pragma thumb off

void func_020ad2f0(u32 a, u32 b, u32 c, u32 d) {
    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, a, b, c, d);
}

// Set when the title blend has run to its end; CreateTitleScene then starts its blend already finished.
void SetTitleBlendDone(u32 p0) {
    data_0217b488->mUnk_00 = p0;
}
