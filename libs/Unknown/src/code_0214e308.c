#include "code_0214e308.h"

#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200f000.h"
#include "registers.h"
#include "code_0214d5b8.h"

u16 gTouchPanelInitialized;

// Handles a word from the other processor: stores automatic samples, finishes requests and reports errors.
void TPi_TpCallback(u32 tag, u32 data, BOOL err) {
    u16 result = data;
    u16 command = (result & 0x7f00) >> 8;
    TPRequestResult callbackResult;
    SPITpData spiTp;
    SPITpData spiTpRaw;
    TPData *sample;

    if (err != 0) {
        gTouchPanelState.mErrorFlags |= 1 << command;
        if (gTouchPanelState.mCallback != 0) {
            gTouchPanelState.mCallback(command, TP_RESULT_PXI_BUSY, 0);
        }
        return;
    }
    if (command == TP_REQUEST_COMMAND_AUTO_SAMPLING) {
        gTouchPanelState.mAutoSampleIndex++;
        if (gTouchPanelState.mAutoSampleIndex >= gTouchPanelState.mAutoSampleBufferCount) {
            gTouchPanelState.mAutoSampleIndex = 0;
        }
        sample = gTouchPanelState.mAutoSampleBuffer + gTouchPanelState.mAutoSampleIndex;
        spiTp.halfs[0] = *(u16 *) 0x27fffaa;
        spiTp.halfs[1] = *(u16 *) 0x27fffac;
        sample->mX = spiTp.e.mX;
        sample->mY = spiTp.e.mY;
        sample->mTouch = (u8) spiTp.e.mTouch;
        sample->mValidity = (u8) spiTp.e.mValidity;
        if (gTouchPanelState.mCallback != 0) {
            gTouchPanelState.mCallback(command, TP_RESULT_SUCCESS, gTouchPanelState.mAutoSampleIndex);
        }
        return;
    }
    if ((data & 0x1000000) == 0) {
        return;
    }
    switch (result & 0xff) {
        case 0:
            switch (command) {
                case TP_REQUEST_COMMAND_SAMPLING:
                    spiTpRaw.halfs[0] = *(u16 *) 0x27fffaa;
                    spiTpRaw.halfs[1] = *(u16 *) 0x27fffac;
                    gTouchPanelState.mState = TP_STATE_READY;
                    gTouchPanelState.mRawSample.mX = spiTpRaw.e.mX;
                    gTouchPanelState.mRawSample.mY = spiTpRaw.e.mY;
                    gTouchPanelState.mRawSample.mTouch = (u8) spiTpRaw.e.mTouch;
                    gTouchPanelState.mRawSample.mValidity = (u8) spiTpRaw.e.mValidity;
                    break;
                case TP_REQUEST_COMMAND_AUTO_ON:
                    gTouchPanelState.mState = TP_STATE_AUTO_SAMPLING;
                    break;
                case TP_REQUEST_COMMAND_AUTO_OFF:
                    gTouchPanelState.mState = TP_STATE_READY;
                    break;
            }
            gTouchPanelState.mBusyFlags &= ~(1 << command);
            if (gTouchPanelState.mCallback != 0) {
                gTouchPanelState.mCallback(command, TP_RESULT_SUCCESS, 0);
            }
            return;
        case 4:
            callbackResult = TP_RESULT_EXCLUSIVE;
            break;
        case 2:
            callbackResult = TP_RESULT_INVALID_PARAMETER;
            break;
        case 3:
            callbackResult = TP_RESULT_ILLEGAL_STATUS;
            break;
        default:
            goto fail;
    }
    gTouchPanelState.mErrorFlags |= 1 << command;
    gTouchPanelState.mBusyFlags &= ~(1 << command);
    if (gTouchPanelState.mCallback != 0) {
        gTouchPanelState.mCallback(command, callbackResult, 0);
    }
    return;
fail:
    OS_Terminate();
}

// Sets up the touch panel channel on the first call only.
void TP_Init(void) {
    if (gTouchPanelInitialized != 0) {
        return;
    }
    gTouchPanelInitialized = 1;
    PXI_Init();
    gTouchPanelState.mState = TP_STATE_READY;
    gTouchPanelState.mBusyFlags = 0;
    gTouchPanelState.mAutoSampleIndex = 0;
    gTouchPanelState.mCallback = 0;
    gTouchPanelState.mAutoSampleBuffer = 0;
    gTouchPanelState.mCalibrated = 0;
    gTouchPanelState.mErrorFlags = 0;
    while (!PXI_IsCallbackReady(6, 1)) {
    }
    PXI_SetFifoRecvCallback(6, TPi_TpCallback);
}

// Computes the calibration from the values stored in the shared block; zeroes it when there are none or they are
// refused.
BOOL TP_GetUserInfo(TPCalibrateParam *calibrate) {
    Unk0214eadc *info = (Unk0214eadc *) 0x27ffc80;
    u16 rawX1;
    u16 y1;
    u16 x2;
    u16 y2;
    u16 dx1;
    u16 dy1;
    u16 dx2;
    u16 dy2;

    rawX1 = info->mRawX1;
    y1 = info->mRawY1;
    dx1 = info->mDx1;
    dy1 = info->mDy1;
    x2 = info->mRawX2;
    y2 = info->mRawY2;
    dx2 = info->mDx2;
    dy2 = info->mDy2;
    if ((rawX1 == 0 && x2 == 0 && y1 == 0 && y2 == 0) ||
        TP_CalcCalibrateParam(calibrate, rawX1, y1, dx1, dy1, x2, y2, dx2, dy2) != 0) {
        calibrate->mX0 = 0;
        calibrate->mY0 = 0;
        calibrate->mXDotSize = 0;
        calibrate->mYDotSize = 0;
        return TRUE;
    }
    return TRUE;
}

// Stores the calibration, with 0x10000000 divided by each dot size.
void TP_SetCalibrateParam(TPCalibrateParam *param) {
    OSIntrMode enabled;
    s16 xDotSize;
    s16 yDotSize;
    vu32 *den;

    if (param == 0) {
        gTouchPanelState.mCalibrated = 0;
        return;
    }
    enabled = OS_DisableInterrupts();
    xDotSize = param->mXDotSize;
    if (xDotSize != 0) {
        reg_CP_DIVCNT = 0;
        *(vu32 *) 0x4000290 = 0x10000000;
        den = (vu32 *) 0x4000298;
        den[0] = xDotSize;
        den[1] = 0;
        gTouchPanelState.mCalibration.mX0 = param->mX0;
        gTouchPanelState.mCalibration.mXDotSize = param->mXDotSize;
        while (reg_CP_DIVCNT & 0x8000) {
        }
        gTouchPanelState.mCalibration.mXDotSizeInv = *(vu32 *) 0x40002a0;
    } else {
        gTouchPanelState.mCalibration.mX0 = 0;
        gTouchPanelState.mCalibration.mXDotSize = 0;
        gTouchPanelState.mCalibration.mXDotSizeInv = 0;
    }
    yDotSize = param->mYDotSize;
    if (yDotSize != 0) {
        reg_CP_DIVCNT = 0;
        *(vu32 *) 0x4000290 = 0x10000000;
        den = (vu32 *) 0x4000298;
        den[0] = yDotSize;
        den[1] = 0;
        gTouchPanelState.mCalibration.mY0 = param->mY0;
        gTouchPanelState.mCalibration.mYDotSize = param->mYDotSize;
        while (reg_CP_DIVCNT & 0x8000) {
        }
        gTouchPanelState.mCalibration.mYDotSizeInv = *(vu32 *) 0x40002a0;
    } else {
        gTouchPanelState.mCalibration.mY0 = 0;
        gTouchPanelState.mCalibration.mYDotSize = 0;
        gTouchPanelState.mCalibration.mYDotSizeInv = 0;
    }
    OS_RestoreInterrupts(enabled);
    gTouchPanelState.mCalibrated = 1;
}

// Sends the command word for one sample.
void TP_RequestSamplingAsync(void) {
    OSIntrMode enabled = OS_DisableInterrupts();
    s32 sent = PXI_SendWordByFifo(6, 0x3000000, 0);
    u32 ok = sent >= 0 ? 1 : 0;

    if (ok == 0) {
        OS_RestoreInterrupts(enabled);
        gTouchPanelState.mErrorFlags |= 1;
        if (gTouchPanelState.mCallback != 0) {
            gTouchPanelState.mCallback(TP_REQUEST_COMMAND_SAMPLING, TP_RESULT_PXI_BUSY, 0);
        }
    } else {
        gTouchPanelState.mBusyFlags |= 1;
        gTouchPanelState.mErrorFlags &= ~1;
        OS_RestoreInterrupts(enabled);
    }
}

// Waits for the single-sample request; copies the unconverted sample to result.
u32 TP_WaitRawResult(TPData *result) {
    TP_WaitBusy(1);
    if (gTouchPanelState.mErrorFlags & 1) {
        return 1;
    }
    *result = gTouchPanelState.mRawSample;
    return 0;
}

// Stores the ring and sends the two command words that start automatic sampling.
void TP_RequestAutoSamplingStartAsync(u16 vcount, u16 frequence, TPData *samplingBufs, u16 bufSize) {
    u32 i;
    OSIntrMode enabled;
    u8 ok;
    TPRecvCallback callback;

    gTouchPanelState.mAutoSampleBuffer = samplingBufs;
    gTouchPanelState.mAutoSampleIndex = 0;
    gTouchPanelState.mFrequence = frequence;
    gTouchPanelState.mAutoSampleBufferCount = bufSize;
    for (i = 0; i < bufSize; i++) {
        gTouchPanelState.mAutoSampleBuffer[i].mTouch = 0;
    }
    enabled = OS_DisableInterrupts();
    if (PXI_SendWordByFifo(6, (frequence & 0xff) | 0x2000100, 0) < 0) {
        ok = 0;
    } else {
        if (PXI_SendWordByFifo(6, vcount | 0x1010000, 0) < 0) {
            ok = 0;
        } else {
            ok = 1;
        }
    }
    if ((ok & 0xff) == 0) {
        OS_RestoreInterrupts(enabled);
        gTouchPanelState.mErrorFlags |= 2;
        callback = gTouchPanelState.mCallback;
        if (callback != 0) {
            callback(TP_REQUEST_COMMAND_AUTO_ON, TP_RESULT_PXI_BUSY, 0);
        }
    } else {
        gTouchPanelState.mBusyFlags |= 2;
        gTouchPanelState.mErrorFlags &= ~2;
        OS_RestoreInterrupts(enabled);
    }
}

// Sends the command word that stops automatic sampling.
void TP_RequestAutoSamplingStopAsync(void) {
    OSIntrMode enabled;
    s32 ok;
    TPRecvCallback callback;

    enabled = OS_DisableInterrupts();
    ok = PXI_SendWordByFifo(6, 0x3000200, 0) >= 0;
    if ((ok & 0xff) == 0) {
        OS_RestoreInterrupts(enabled);
        gTouchPanelState.mErrorFlags |= 4;
        callback = gTouchPanelState.mCallback;
        if (callback != 0) {
            callback(TP_REQUEST_COMMAND_AUTO_OFF, TP_RESULT_PXI_BUSY, 0);
        }
    } else {
        gTouchPanelState.mBusyFlags |= 4;
        gTouchPanelState.mErrorFlags &= ~4;
        OS_RestoreInterrupts(enabled);
    }
}

// Returns the ring position of the newest automatic sample.
u16 TP_GetLatestIndexInAuto(void) {
    return gTouchPanelState.mAutoSampleIndex;
}

// Computes the calibration from two raw points and their screen positions; 1 when a value is refused, otherwise 0.
u32 TP_CalcCalibrateParam(TPCalibrateParam *calibrate, u16 rawX1, u16 rawY1, u16 dx1, u16 dy1, u16 rawX2, u16 rawY2,
                          u16 dx2, u16 dy2) {
    s32 rxWidth;
    s32 dxWidth;
    s32 ryWidth;
    s32 dyWidth;
    s32 value;
    OSIntrMode enabled;

    if (rawX1 >= 0x1000 || rawY1 >= 0x1000 || rawX2 >= 0x1000 || rawY2 >= 0x1000) {
        return 1;
    }
    if (dx1 >= 0x100 || dx2 >= 0x100 || dy1 >= 0xc0 || dy2 >= 0xc0) {
        return 1;
    }
    if (dx1 == dx2 || dy1 == dy2 || rawX1 == rawX2 || rawY1 == rawY2) {
        return 1;
    }
    enabled = OS_DisableInterrupts();
    reg_CP_DIVCNT = 0;
    *(vu32 *) 0x04000290 = (rawX1 - rawX2) << 8;
    reg_CP_DIV_DENOM = (u32) (dx1 - dx2);
    ryWidth = rawY1 - rawY2;
    dyWidth = dy1 - dy2;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    value = *(vs32 *) 0x040002a0;
    reg_CP_DIVCNT = 0;
    *(vu32 *) 0x04000290 = ryWidth << 8;
    reg_CP_DIV_DENOM = (u32) dyWidth;
    if (value >= 0x8000 || value < -0x8000) {
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    calibrate->mXDotSize = value;
    value = (s16) ((((rawX1 + rawX2) << 8) - calibrate->mXDotSize * (dx1 + dx2)) >> 7);
    if (value >= 0x8000 || value < -0x8000) {
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    calibrate->mX0 = value;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    value = *(vs32 *) 0x040002a0;
    OS_RestoreInterrupts(enabled);
    if (value >= 0x8000 || value < -0x8000) {
        return 1;
    }
    calibrate->mYDotSize = value;
    value = (s16) ((((rawY1 + rawY2) << 8) - calibrate->mYDotSize * (dy1 + dy2)) >> 7);
    if (value >= 0x8000 || value < -0x8000) {
        return 1;
    }
    calibrate->mY0 = value;
    return 0;
}

// Converts the raw sample to screen coordinates, clamped to the screen; copies it unchanged when not calibrated.
void TP_GetCalibratedPoint(TPData *disp, const TPData *raw) {
    TPiCalibrateParam *calibration;

    if (gTouchPanelState.mCalibrated == 0) {
        *disp = *raw;
        return;
    }
    calibration = &gTouchPanelState.mCalibration;
    disp->mTouch = raw->mTouch;
    disp->mValidity = raw->mValidity;
    if (raw->mTouch == 0) {
        disp->mX = 0;
        disp->mY = 0;
        return;
    }
    disp->mX = (((u64) (raw->mX << 2) - calibration->mX0) * calibration->mXDotSizeInv) >> 22;
    if ((s16) disp->mX < 0) {
        disp->mX = 0;
    } else if ((s16) disp->mX > 0xff) {
        disp->mX = 0xff;
    }
    disp->mY = (((u64) (raw->mY << 2) - calibration->mY0) * calibration->mYDotSizeInv) >> 22;
    if ((s16) disp->mY < 0) {
        disp->mY = 0;
        return;
    }
    if ((s16) disp->mY > 0xbf) {
        disp->mY = 0xbf;
    }
}

// Spins until none of the busy bits in commandFlgs is set.
void TP_WaitBusy(u32 commandFlgs) {
    while (gTouchPanelState.mBusyFlags & commandFlgs) {
    }
}

// Returns the error bits selected by commandFlgs.
u32 TP_CheckError(u32 commandFlgs) {
    return gTouchPanelState.mErrorFlags & commandFlgs;
}
