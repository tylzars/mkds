#include "Main/Unknown/code_0202a5a0.h"
#include "Main/Unknown/code_02029a90.h"
#include "Main/Unknown/code_02029000.h"
#include "Main/Unknown/code_02032000.h"
#include "Main/Unknown/code_02032aa8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02049000.h"
#include "Main/Unknown/code_0204984c.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_0212a000.h"

#include "Main/Unknown/code_02029aa0.h"
#include "Main/Unknown/code_02032ab0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ae630.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0214a390.h"
#include "code_0214d018.h"
#include "registers.h"

#pragma thumb on

void InitResultsByMode(void *heap) {
    gResultScene = HeapAlloc(heap, 0x80c);
    MemFillWordsByBlock_inline(gResultScene, 0x80c);
    func_020ae6d4(gResultScene, gResultScene->mSubOam);
    gResultScene->mMode = gRaceSetup->mMode;
    if (gResultScene->mMode == 0) {
        InitResultsGp(heap, gResultScene, gResultScene->mSubOam);
    } else {
        InitResultsBattle(heap, (s32) gResultScene, (s32) gResultScene->mSubOam);
    }
    func_0212abdc(heap, gResultScene);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | 0x10;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | 0x10;
    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, 1, 0x3f, 8, 8);
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 0x2f, 8, 8);
    reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
}

#pragma thumb off

#pragma thumb on

void AdvanceResultsByMode(u32 sceneNumbers) {
    int result;
    result = func_02049b6c();
    if (result == 0) {
        func_020ae6ac(gResultScene, gResultScene->mSubOam);
        if (gResultScene->mMode == 0) {
            AdvanceResultsGp((Unk02029aa0 *) sceneNumbers);
        } else {
            AdvanceResultsBattle((Unk02032ac4 *) sceneNumbers);
        }
        func_020ae630(gResultScene, gResultScene->mSubOam);
        func_0212a920();
    }
}

void func_0202a5d8(void) {
    if (gResultScene->mMode == 0) {
        func_02029a98();
    } else {
        func_02032ab0();
    }
    func_0212abd0();
}

void func_0202a5a0(void) {
    if (gResultScene->mMode == 0) {
        func_02029a90();
    } else {
        func_02032aa8();
    }
    func_020ae5f0(gResultScene, gResultScene->mSubOam);
}

#pragma thumb off
