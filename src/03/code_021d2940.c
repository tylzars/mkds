#include "03/code_021d2940.h"

#include "03/unk_021da000.h"
#include "03/code_021d250c.h"
#include "03/types_021d299c.h"
#include "tp.h"
#include "code_02147cd8.h"
#include "03/code_021d2c78.h"
#include "03/code_021d27d8.h"

void ReleaseKeyTouchInput(void) {
    do {
        TP_RequestAutoSamplingStopAsync();
        TP_WaitBusy(4);
    } while (TP_CheckError(4) != 0);
    FreeExpHeapBlockAndClearPointer(&gKeyTouchInput);
}

void UpdateKeyTouchInput(void) {
    UpdateKeyInput();
    UpdateTouchInput();
}

void UpdateKeyInput(void) {
    KeyTouchInput *input = gKeyTouchInput;
    u16 keys = ((*(u16 *) 0x4000130 | *(u16 *) 0x27fffa8) ^ 0x2fff) & 0x2fff;
    s32 i;
    u16 keyBit;

    input->mKeysPressed = keys & (keys ^ input->mKeysDown);
    gKeyTouchInput->mKeysReleased = input->mKeysDown & (keys ^ input->mKeysDown);
    gKeyTouchInput->mKeysDown = keys;
    gKeyTouchInput->mKeysPressedOrRepeated = gKeyTouchInput->mKeysPressed;
    for (i = 0; i < 14; i++) {
        keyBit = 1 << i;
        if ((keys & keyBit) == 0) {
            gKeyRepeatFrames[i] = 0;
        } else {
            gKeyRepeatFrames[i]++;
            if (gKeyRepeatFrames[i] == 0x28) {
                gKeyTouchInput->mKeysPressedOrRepeated |= keyBit;
            } else if (gKeyRepeatFrames[i] == 0x2f) {
                gKeyTouchInput->mKeysPressedOrRepeated |= keyBit;
                gKeyRepeatFrames[i] = 0x28;
            }
        }
    }
}

void UpdateTouchInput(void) {
    u8 found;
    u32 wasDown;
    u32 c;
    s32 i;
    TPData point;
    KeyTouchInput *input;

    if (gKeyTouchInput->mBits.mBit_0 != 0) {
        wasDown = 1;
    } else {
        wasDown = 0;
    }
    found = 0;
    c = TP_GetLatestIndexInAuto();
    input = gKeyTouchInput;
    input->mPrevTouchX = input->mTouchX;
    input->mPrevTouchY = input->mTouchY;
    i = 0;
    do {
        TPData *sample = &gKeyTouchInput->mTouchSamples[c];

        if (sample->mTouch == 1 && sample->mValidity == 0) {
            found = 1;
            TP_GetCalibratedPoint(&point, sample);
            SetPosition(point.mX, point.mY, &gKeyTouchInput->mTouchX);
            break;
        }
        i++;
        c = FX_ModS32(c + 4, 5);
    } while (i < 4);
    c = found ^ wasDown;
    gKeyTouchInput->mBits.mBit_1 = found & c;
    gKeyTouchInput->mBits.mBit_3 = wasDown & c;
    gKeyTouchInput->mBits.mBit_0 = found;
    gKeyTouchInput->mBits.mBit_2 = gKeyTouchInput->mBits.mBit_1;
    if (found == 0) {
        gTouchRepeatFrames = 0;
        return;
    }
    gTouchRepeatFrames++;
    if (gTouchRepeatFrames == 0x28) {
        gKeyTouchInput->mBits.mBit_2 = 1;
    } else if (gTouchRepeatFrames == 0x2f) {
        gKeyTouchInput->mBits.mBit_2 = 1;
        gTouchRepeatFrames = 0x28;
    }
}

BOOL AreKeysDown(u32 keys) {
    if (keys == (keys & gKeyTouchInput->mKeysDown)) {
        return 1;
    }
    return 0;
}

BOOL AreKeysPressed(u32 keys) {
    if (keys == (keys & gKeyTouchInput->mKeysPressed)) {
        return 1;
    }
    return 0;
}

BOOL AreKeysPressedOrRepeated(u32 keys) {
    if (keys == (keys & gKeyTouchInput->mKeysPressedOrRepeated)) {
        return 1;
    }
    return 0;
}

BOOL AreKeysReleased(u32 keys) {
    if (keys == (keys & gKeyTouchInput->mKeysReleased)) {
        return 1;
    }
    return 0;
}

BOOL IsTouchDownInRect(const Rect *rect) {
    KeyTouchInput *input = gKeyTouchInput;
    if (input->mBits.mBit_0 == 0) {
        return 0;
    }
    if (rect->mUnk_00 > input->mTouchX) {
        return 0;
    }
    if (rect->mUnk_04 < input->mTouchX) {
        return 0;
    }
    if (rect->mUnk_02 > input->mTouchY) {
        return 0;
    }
    if (rect->mUnk_06 >= input->mTouchY) {
        return 1;
    }
    return 0;
}

BOOL IsTouchPressedInRect(const Rect *rect) {
    KeyTouchInput *input = gKeyTouchInput;
    if ((((u32) input->mTouchFlags << 30) >> 31) == 0) {
        return 0;
    }
    if (rect->mUnk_00 > input->mTouchX) {
        return 0;
    }
    if (rect->mUnk_04 < input->mTouchX) {
        return 0;
    }
    if (rect->mUnk_02 > input->mTouchY) {
        return 0;
    }
    if (rect->mUnk_06 >= input->mTouchY) {
        return 1;
    }
    return 0;
}

BOOL IsTouchPressedOrRepeatedInRect(const Rect *rect) {
    KeyTouchInput *input = gKeyTouchInput;
    if ((((u32) input->mTouchFlags << 29) >> 31) == 0) {
        return 0;
    }
    if (rect->mUnk_00 > input->mTouchX) {
        return 0;
    }
    if (rect->mUnk_04 < input->mTouchX) {
        return 0;
    }
    if (rect->mUnk_02 > input->mTouchY) {
        return 0;
    }
    if (rect->mUnk_06 >= input->mTouchY) {
        return 1;
    }
    return 0;
}

BOOL IsTouchReleasedInRect(const Rect *rect) {
    KeyTouchInput *input = gKeyTouchInput;
    if ((((u32) input->mTouchFlags << 28) >> 31) == 0) {
        return 0;
    }
    if (rect->mUnk_00 > input->mTouchX) {
        return 0;
    }
    if (rect->mUnk_04 < input->mTouchX) {
        return 0;
    }
    if (rect->mUnk_02 > input->mTouchY) {
        return 0;
    }
    if (rect->mUnk_06 >= input->mTouchY) {
        return 1;
    }
    return 0;
}

BOOL IsTouchPressedInOriginSizeRect(const Rect *input) {
    Rect rect;
    rect.mUnk_00 = input->mUnk_00;
    rect.mUnk_02 = input->mUnk_02;
    rect.mUnk_04 = input->mUnk_00 + input->mUnk_04;
    rect.mUnk_06 = input->mUnk_02 + input->mUnk_06;
    return IsTouchPressedInRect(&rect);
}

BOOL GetTouchPoint(u16 *output) {
    KeyTouchInput *state = gKeyTouchInput;
    if (state->mBits.mBit_0 == 0) {
        output[0] = state->mPrevTouchX;
        output[1] = state->mPrevTouchY;
        return FALSE;
    }
    output[0] = state->mTouchX;
    output[1] = state->mTouchY;
    return TRUE;
}
