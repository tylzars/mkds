#include "Main/Unknown/code_02035d18.h"

#include "registers.h"
#include "Main/Unknown/code_02035000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02108c1c.h"
#include "Main/Unknown/code_0205905c.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_0203606c.h"
#include "Main/Unknown/code_020360e4.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02058b38.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02058efc.h"
#include "Main/Unknown/code_0204aa04.h"
#include "Main/Unknown/code_0205e2cc.h"
#include "00/code_02181f98.h"

void func_02036058(u32 value) {
    data_0217b488->mUnk_04 = value;
}

void func_02036044(u32 value) {
    data_0217b488->mUnk_08 = value;
}

#pragma thumb on

s32 func_02035f5c(u32 sceneNumbers) {
    s32 result;
    WLMenuMessage *wlMenuMessage;

    switch (gWLMenuMessage->mState) {
        case 0:
            if (func_0205579c(0, 1) == 1) {
                gWLMenuMessage->mState = 2;
            }
            break;
        case 2:
            result = func_02055730(0);
            switch (result) {
                case 1:
                    func_0204aa28(func_020360e4());
                    gWLMenuMessage->mState = 4;
                    break;
                case 2:
                    break;
            }
            break;
        case 4:
            result = func_02058cac();
            switch (result) {
                case 1:
                    if (func_02035e44() != 0) {
                        func_02035e38();
                    }
                    StartCopyOtherEmblems(1);
                    gWLMenuMessage->mState = 6;
                    break;
                case 2:
                    break;
            }
            break;
        case 6:
            if (IsBackupBusy() == 0) {
                func_02036058(1);
                func_02036044(4);
                if (sceneNumbers != 0) {
                    SetNextScene(sceneNumbers, 1);
                }
                gWLMenuMessage->mState = 11;
            }
            break;
    }
    wlMenuMessage = gWLMenuMessage;
    wlMenuMessage->mBg3Offset = (wlMenuMessage->mBg3Offset + 1) % 0x100;
    return -1;
}

s32 func_02035ee0(u32 sceneNumbers) {
    s32 result;
    WLMenuMessage *wlMenuMessage;

    switch (gWLMenuMessage->mState) {
        case 9:
            result = func_020591c4();
            switch (result) {
                case 1:
                    if (func_02035e44() != 0) {
                        func_02035e38();
                    }
                    gWLMenuMessage->mState = 10;
                    break;
                case 2:
                    break;
            }
            break;
        case 10:
            if (sceneNumbers != 0) {
                SetNextScene(sceneNumbers, 2);
            }
            gWLMenuMessage->mState = 11;
            break;
    }
    wlMenuMessage = gWLMenuMessage;
    wlMenuMessage->mBg3Offset = (wlMenuMessage->mBg3Offset + 1) % 0x100;
    return -1;
}

s32 func_02035e64(u32 sceneNumbers) {
    s32 result;
    WLMenuMessage *wlMenuMessage;

    switch (gWLMenuMessage->mState) {
        case 9:
            result = func_02058f20();
            switch (result) {
                case 1:
                    if (func_02035e44() != 0) {
                        func_02035e38();
                    }
                    gWLMenuMessage->mState = 10;
                    break;
                case 2:
                    break;
            }
            break;
        case 10:
            if (sceneNumbers != 0) {
                SetNextScene(sceneNumbers, 10);
            }
            gWLMenuMessage->mState = 11;
            break;
    }
    wlMenuMessage = gWLMenuMessage;
    wlMenuMessage->mBg3Offset = (wlMenuMessage->mBg3Offset + 1) % 0x100;
    return -1;
}

#pragma thumb off

u32 func_02035e44(void) {
    return data_0217aa00->mUnk_0457 != 0;
}

void func_02035e38(void) {
    u32 value12;
    func_02108d80();
}

void SetNextScene(u32 sceneNumbers, u32 nextScene) {
    *OFFSET_PTR(u16, sceneNumbers, 4) = nextScene;
}

#pragma thumb on

s32 func_02035db4(u32 sceneNumbers) {
    s32 result;
    WLMenuMessage *wlMenuMessage;

    switch (gWLMenuMessage->mState) {
        case 9:
            result = func_020591bc();
            switch (result) {
                case 1:
                    if (func_02035e44() != 0) {
                        func_02035e38();
                    }
                    gWLMenuMessage->mState = 10;
                    break;
                case 2:
                    break;
            }
            break;
        case 10:
            if (sceneNumbers != 0) {
                SetNextScene(sceneNumbers, 1);
            }
            gWLMenuMessage->mState = 11;
            break;
    }
    wlMenuMessage = gWLMenuMessage;
    wlMenuMessage->mBg3Offset = (wlMenuMessage->mBg3Offset + 1) % 0x100;
    return -1;
}

#pragma thumb off

#pragma thumb on

void ReleaseWLMenuMessage(void) {
    HeapDestroy(gWLMenuMessage->mHeap);
    *&gWLMenuMessage = NULL;
}

#pragma thumb off

void WriteSubDispcntBits(int bits) {
    u32 value0 = bits;
    u32 registerValue;
    u32 registerAddress;
    registerAddress = 0x4001000u;
    registerValue = *(const u32 *) ((registerAddress) + (0));
    registerValue = (registerValue) & ~(0x1f00u);
    value0 = (registerValue) | ((value0 << 8));
    *(u32 *) ((registerAddress) + (0)) = value0;
}

void WriteSubBg3Offset(u32 offsetX, int offsetY) {
    reg_G2S_DB_BG3OFS = (offsetX & 0x1ff) | ((offsetY << 16) & 0x01ff0000);
}

#pragma thumb on

void func_02035d20(void) {
    WriteSubDispcntBits(10);
    WriteSubBg3Offset(-gWLMenuMessage->mBg3Offset, 0);
}

#pragma thumb off

#pragma thumb on
void func_02035d18(void) {
    u32 value3;
    func_02035d20();
}
#pragma thumb off
