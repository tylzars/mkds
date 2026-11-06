#include "00/code_021857b8.h"

#include "Main/Unknown/code_02036c5c.h"
#include "00/code_02180608.h"
#include "00/code_021832d8.h"
#include "code_02148950.h"
#include "code_021458c4.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/unk_0217a000.h"
#include "registers.h"
#include "code_0200e77c.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02036820.h"

void func_ov000_0218592c(void *a) {
    data_ov000_021b4c8c = HeapAlloc(a, 8);
    data_ov000_021b4c8c->mState = 0;
    data_ov000_021b4c8c->mNextState = 0;
    StartFadeToFadedNegative(0x1e);
}

void func_ov000_02185920(void) {
    data_ov000_021b4c8c = NULL;
}

void func_ov000_0218583c(void) {
    u32 a;
    Unk0217aa08_00 *p;
    s8 b;

    if (AreBrightnessFadesFaded() != 0) {
        data_ov000_021b4c8c->mNextState = 1;
        StartFadeToClear(0x1e);
        reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | 0x1208;
        reg_G2_BG1CNT = reg_G2_BG1CNT & ~3;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1f00;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | 0x1700;
        reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
        GX_SetGraphicsMode(1, 0, 1);
        if (data_0217b488->mUnk_6c != FALSE) {
            p = data_0217aa08->mUnk_00;
            a = p->mUnk_34[5];
            b = gWiFiSession->mKartCountCopy - 1;
            if (b > 0) {
                if (a < b) {
                    a = 0;
                } else {
                    a -= b;
                }
            }
            p->mUnk_34[5] = a;
            func_02056d40();
            func_02057d9c();
            if (data_021759d4->mUnk_0c != 0) {
                CARD_WaitBackupAsync();
            }
        }
    }
}

void func_ov000_02185818(void) {
    int v1;
    v1 = AreBrightnessFadesClear();
    if (v1 != 0) {
        RequestWiFiState(2);
        data_0217b488->mUnk_1c = 1;
    }
}

void func_ov000_021857e0(void) {
    data_ov000_021b4c8c->mState = data_ov000_021b4c8c->mNextState;
    switch (data_ov000_021b4c8c->mState) {
        case 0:
            func_ov000_0218583c();
            break;
        case 1:
            func_ov000_02185818();
            break;
    }
}

void func_ov000_021857dc(void) {}

void func_ov000_021857b8(void) {
    WiFiStateCallbacks callbacks = data_ov000_021b0fd8;
    SetWiFiStateCallbacks(&callbacks);
}
