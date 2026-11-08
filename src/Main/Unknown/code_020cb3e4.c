#include "Main/Unknown/code_020cb3e4.h"
#include "Main/Unknown/code_020b4000.h"

#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020cb48c.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "gx.h"
#include "code_02148950.h"
#include "code_0214b824.h"

void func_020cb4a8(int bits) {
    u32 value0 = bits;
    u32 registerValue;
    u32 registerAddress;
    registerAddress = 0x4000000u;
    registerValue = *(const u32 *) ((registerAddress) + (0));
    registerValue = (registerValue) & ~(0x1f00u);
    value0 = (registerValue) | ((value0 << 8));
    *(u32 *) ((registerAddress) + (0)) = value0;
}

void func_020cb48c(int bits) {
    u32 value0 = bits;
    u32 registerValue;
    u32 registerAddress;
    registerAddress = 0x4001000u;
    registerValue = *(const u32 *) ((registerAddress) + (0));
    registerValue = (registerValue) & ~(0x1f00u);
    value0 = (registerValue) | ((value0 << 8));
    *(u32 *) ((registerAddress) + (0)) = value0;
}

#pragma thumb on

void SetupSinglePlaySelectGraphics(void) {
    int screenChanged;
    screenChanged = func_020cccc0();
    if (screenChanged != 0) {
        func_020cb4a8(0x18);
        GX_SetGraphicsMode(1, 0, 0);
        GX_LoadOBJPltt(data_0217b43c->mSinglePlaySelectModeMONclr->mData, 0, (0x000001a0u));
        GX_LoadOBJPltt(&data_0217b43c->mSinglePlaySelectModeMONclr->mData[0xe0], 0x1c0, 0x40);
        GX_LoadOBJ(data_0217b43c->mSinglePlaySelectModeMNcgr->mData, 0,
                   data_0217b43c->mSinglePlaySelectModeMNcgr->mDataSize);
        func_020cb48c(0x16);
        GXS_SetGraphicsMode(0);
        GXS_LoadOBJPltt(data_0217b43c->mSinglePlaySelectModeSONclr->mData, 0,
                        data_0217b43c->mSinglePlaySelectModeSONclr->mDataSize);
        GXS_LoadOBJ(data_0217b43c->mSinglePlaySelectModeSNcgr->mData, 0,
                    data_0217b43c->mSinglePlaySelectModeSNcgr->mDataSize);
    }
}

#pragma thumb off
