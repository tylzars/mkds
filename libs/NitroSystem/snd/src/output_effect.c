#include "output_effect.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "snd_interface.h"
#include "code_0201ec30.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0214cfe4.h"
#include "code_0212c9d4.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0216e000.h"

// Sets the output effect to type, then starts an effect capture of 32000 Hz with two parts, handled by EffectCallback.
void NNS_SndCaptureStartOutputEffect(void *buffer, u32 bufSize, s32 type) {
    NNS_SndCaptureChangeOutputEffect(type);
    NNS_SndCaptureStartEffect(buffer, bufSize, 0, 32000, 2, EffectCallback, &data_0216eaa4);
}

// Does nothing when type is already set. Otherwise clears CallbackInfo.mBuffer, stores type in CallbackInfo.mType and
// the matching function (type 0 to 3: NothingProc, SurroundProc, HeadphoneProc, MonoProc) in CallbackInfo.mEffectFunc;
// the surround decay is reset first when the old type is 1 and set to 0x3000 last when type is 1.
void NNS_SndCaptureChangeOutputEffect(s32 type) {
    u32 enabled;
    volatile u16 zero;

    if (type == data_0216eaa4.mType) {
        return;
    }
    if (data_0216eaa4.mType == 1) {
        SNDi_SetSurroundDecay(0);
    }
    enabled = OS_DisableInterrupts();
    zero = 0;
    MIi_CpuClear16(zero, &data_0216eaa4.mBuffer, 0xc0);
    data_0216eaa4.mType = type;
    switch (type) {
        case 1:
            data_0216eaa4.mEffectFunc = SurroundProc;
            break;
        case 2:
            data_0216eaa4.mEffectFunc = HeadphoneProc;
            break;
        case 3:
            data_0216eaa4.mEffectFunc = MonoProc;
            break;
        case 0:
            data_0216eaa4.mEffectFunc = NothingProc;
            break;
        default:
            data_0216eaa4.mEffectFunc = NothingProc;
            break;
    }
    OS_RestoreInterrupts(enabled);
    if (type == 1) {
        SNDi_SetSurroundDecay(0x3000);
    }
}

// Capture callback: runs CallbackInfo.mCbFunc, CallbackInfo.mEffectFunc and CallbackInfo.mCbPostFunc on the buffers
// (the callbacks only when not null), then flushes both.
void EffectCallback(void *bufferL, void *bufferR, u32 len, u32 format, void *arg) {
    CallbackInfo *info = arg;

    if (info->mCbFunc != 0) {
        info->mCbFunc(bufferL, bufferR, len, format, info->mCbArg);
    }
    info->mEffectFunc(bufferL, bufferR, len, info);
    if (info->mCbPostFunc != 0) {
        info->mCbPostFunc(bufferL, bufferR, len, format, info->mCbPostArg);
    }
    DC_FlushRange(bufferL, len);
    DC_FlushRange(bufferR, len);
}

// Does nothing.
void NothingProc(s16 *bufferL, s16 *bufferR, u32 len, CallbackInfo *info) {}

// Cross-feeds the channels with a delay of two samples: works on the last two entries of the buffers first, then on
// the rest from the end, with 16-bit clamping, and keeps the two delayed values in CallbackInfo.mBuffer.
void SurroundProc(s16 *bufferL, s16 *bufferR, u32 len, CallbackInfo *info) {
    s16 saved[2];
    u32 samples;
    s32 i;
    s32 j;
    s32 k;
    s32 newLeft;
    s32 newRight;
    s32 diff;
    s16 *leftPtr;
    s16 *rightPtr;

    samples = len >> 1;
    for (i = 0; i < 2; i++) {
        diff = *(bufferL + samples + i - 2) - *(bufferR + samples + i - 2);
        if (diff < -32768) {
            diff = -32768;
        } else if (diff > 32767) {
            diff = 32767;
        }
        saved[i] = diff;
    }
    leftPtr = bufferL + (samples - 1);
    rightPtr = bufferR + (samples - 1);
    for (; leftPtr >= bufferL + 2; leftPtr--, rightPtr--) {
        diff = leftPtr[-2] - rightPtr[-2];
        newLeft = leftPtr[0] + diff;
        newRight = rightPtr[0] - diff;
        if (diff >= 0) {
            if (newLeft < 32767) {
                leftPtr[0] = newLeft;
            } else {
                leftPtr[0] = 32767;
            }
            if (newRight > -32768) {
                rightPtr[0] = newRight;
            } else {
                rightPtr[0] = -32768;
            }
        } else {
            if (newLeft > -32768) {
                leftPtr[0] = newLeft;
            } else {
                leftPtr[0] = -32768;
            }
            if (newRight < 32767) {
                rightPtr[0] = newRight;
            } else {
                rightPtr[0] = 32767;
            }
        }
    }
    for (j = 1; j >= 0; j--) {
        newLeft = bufferL[j] + info->mBuffer.surround[j];
        if (newLeft < -32768) {
            newLeft = -32768;
        } else if (newLeft > 32767) {
            newLeft = 32767;
        }
        bufferL[j] = newLeft;
        newRight = bufferR[j] - info->mBuffer.surround[j];
        if (newRight < -32768) {
            newRight = -32768;
        } else if (newRight > 32767) {
            newRight = 32767;
        }
        bufferR[j] = newRight;
    }
    for (k = 0; k < 2; k++) {
        info->mBuffer.surround[k] = saved[k];
    }
}

// Adds the pairs in CallbackInfo.mBuffer to the buffers in blocks of 24 entries with 16-bit clamping and stores new
// pairs.
void HeadphoneProc(s16 *bufferL, s16 *bufferR, u32 len, CallbackInfo *info) {
    u32 samples;
    u32 rest;
    s32 i;
    s32 j;
    s32 left;
    s32 right;
    u32 offset;
    s32 clampedLeft;
    s32 clampedRight;

    samples = len >> 1;
    offset = 0;
    while (samples > offset + 24) {
        for (i = 0; i < 24; i++) {
            left = bufferL[i + offset];
            left += info->mBuffer.headphone[i][0];
            right = bufferR[i + offset];
            right += info->mBuffer.headphone[i][1];
            clampedLeft = left;
            if (left < -32768) {
                clampedLeft = -32768;
            } else if (left > 32767) {
                clampedLeft = 32767;
            }
            bufferL[i + offset] = clampedLeft;
            clampedRight = right;
            if (right < -32768) {
                clampedRight = -32768;
            } else if (right > 32767) {
                clampedRight = 32767;
            }
            bufferR[i + offset] = clampedRight;
            info->mBuffer.headphone[i][0] = (right + 1) >> 2;
            info->mBuffer.headphone[i][1] = (left + 1) >> 2;
        }
        offset += 24;
    }
    rest = samples - offset;
    for (i = 0; i < rest; i++) {
        j = bufferL[i + offset];
        j += info->mBuffer.headphone[i][0];
        right = bufferR[i + offset];
        right += info->mBuffer.headphone[i][1];
        if (j < -32768) {
            j = -32768;
        } else if (j > 32767) {
            j = 32767;
        }
        bufferL[i + offset] = j;
        if (right < -32768) {
            right = -32768;
        } else if (right > 32767) {
            right = 32767;
        }
        bufferR[i + offset] = right;
    }
    for (i = 0; i < 24 - rest; i++) {
        info->mBuffer.headphone[i][0] = (info->mBuffer.headphone + rest)[i][0];
        info->mBuffer.headphone[i][1] = (info->mBuffer.headphone + rest)[i][1];
    }
    for (i = 0; i < rest; i++) {
        info->mBuffer.headphone[24 + i - rest][0] = (bufferR[i + offset] + 1) >> 2;
        info->mBuffer.headphone[24 + i - rest][1] = (bufferL[i + offset] + 1) >> 2;
    }
}

// Replaces the left buffer with the rounded average of both channels, then copies it over the right buffer.
void MonoProc(s16 *bufferL, s16 *bufferR, u32 len, CallbackInfo *info) {
    u32 samples;
    u32 i;

    samples = len >> 1;
    for (i = 0; i < samples; i++) {
        bufferL[i] = (bufferL[i] + bufferR[i] + 1) >> 1;
    }
    MIi_CpuCopyFast(bufferL, bufferR, len);
}
