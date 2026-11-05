#include "code_0214e308.h"

#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200f000.h"
#include "registers.h"
#include "code_0214d5b8.h"

u16 gTouchPanelInitialized;

void ReceiveTouchPanelReply(u32 a, u32 b, u32 c) {
    u16 x = b;
    u16 k = (x & 0x7f00) >> 8;
    u32 n;
    Unk0214ec18 w;
    Unk0214ec18 v;
    TouchSample *e;

    if (c != 0) {
        gTouchPanelState.mErrorFlags |= 1 << k;
        if (gTouchPanelState.mCallback != 0) {
            gTouchPanelState.mCallback(k, 4, 0);
        }
        return;
    }
    if (k == 0x10) {
        gTouchPanelState.mAutoSampleIndex++;
        if (gTouchPanelState.mAutoSampleIndex >= gTouchPanelState.mAutoSampleBufferCount) {
            gTouchPanelState.mAutoSampleIndex = 0;
        }
        e = gTouchPanelState.mAutoSampleBuffer + gTouchPanelState.mAutoSampleIndex;
        w.h[0] = *(u16 *) 0x27fffaa;
        w.h[1] = *(u16 *) 0x27fffac;
        e->mX = w.f.mUnk_00_0;
        e->mY = w.f.mUnk_00_12;
        e->mTouched = (u8) w.f.mUnk_00_24;
        e->mInvalidBits = (u8) w.f.mUnk_00_25;
        if (gTouchPanelState.mCallback != 0) {
            gTouchPanelState.mCallback(k, 0, gTouchPanelState.mAutoSampleIndex);
        }
        return;
    }
    if ((b & 0x1000000) == 0) {
        return;
    }
    switch (x & 0xff) {
        case 0:
            switch (k) {
                case 0:
                    v.h[0] = *(u16 *) 0x27fffaa;
                    v.h[1] = *(u16 *) 0x27fffac;
                    gTouchPanelState.mUnk_32 = 0;
                    gTouchPanelState.mRawSample.mX = v.f.mUnk_00_0;
                    gTouchPanelState.mRawSample.mY = v.f.mUnk_00_12;
                    gTouchPanelState.mRawSample.mTouched = (u8) v.f.mUnk_00_24;
                    gTouchPanelState.mRawSample.mInvalidBits = (u8) v.f.mUnk_00_25;
                    break;
                case 1:
                    gTouchPanelState.mUnk_32 = 2;
                    break;
                case 2:
                    gTouchPanelState.mUnk_32 = 0;
                    break;
            }
            gTouchPanelState.mBusyFlags &= ~(1 << k);
            if (gTouchPanelState.mCallback != 0) {
                gTouchPanelState.mCallback(k, 0, 0);
            }
            return;
        case 4:
            n = 3;
            break;
        case 2:
            n = 1;
            break;
        case 3:
            n = 2;
            break;
        default:
            goto fail;
    }
    gTouchPanelState.mErrorFlags |= 1 << k;
    gTouchPanelState.mBusyFlags &= ~(1 << k);
    if (gTouchPanelState.mCallback != 0) {
        gTouchPanelState.mCallback(k, n, 0);
    }
    return;
fail:
    IrqDisableLoopForever();
}

void TP_Init(void) {
    if (gTouchPanelInitialized != 0) {
        return;
    }
    gTouchPanelInitialized = 1;
    PxiInit();
    gTouchPanelState.mUnk_32 = 0;
    gTouchPanelState.mBusyFlags = 0;
    gTouchPanelState.mAutoSampleIndex = 0;
    gTouchPanelState.mCallback = 0;
    gTouchPanelState.mAutoSampleBuffer = 0;
    gTouchPanelState.mCalibrated = 0;
    gTouchPanelState.mErrorFlags = 0;
    while (!PxiCallbackBitIsSet(6, 1)) {
    }
    PxiCallbackSet(6, ReceiveTouchPanelReply);
}

u32 TP_GetUserInfo(Unk0214e334 *p) {
    Unk0214eadc *s = (Unk0214eadc *) 0x27ffc80;
    u16 e;
    u16 f;
    u8 d;
    u16 a;
    u16 b;
    u8 c;
    u8 g;
    u8 h;

    a = s->mUnk_58;
    b = s->mUnk_5a;
    c = s->mUnk_5c;
    d = s->mUnk_5d;
    e = s->mUnk_5e;
    f = s->mUnk_60;
    g = s->mUnk_62;
    h = s->mUnk_63;
    if ((a == 0 && e == 0 && b == 0 && f == 0) || TP_CalcCalibrateParam(p, a, b, c, d, e, f, g, h) != 0) {
        p->mUnk_00 = 0;
        p->mUnk_02 = 0;
        p->mUnk_04 = 0;
        p->mUnk_06 = 0;
        return 1;
    }
    return 1;
}

void TP_SetCalibrateParam(Unk0214e334 *p) {
    u32 v;
    s16 a;
    s16 b;
    vu32 *den;

    if (p == 0) {
        gTouchPanelState.mCalibrated = 0;
        return;
    }
    v = IrqDisable();
    a = p->mUnk_04;
    if (a != 0) {
        *(vu16 *) 0x4000280 = 0;
        *(vu32 *) 0x4000290 = 0x10000000;
        den = (vu32 *) 0x4000298;
        den[0] = a;
        den[1] = 0;
        gTouchPanelState.mCalibration.mUnk_00 = p->mUnk_00;
        gTouchPanelState.mCalibration.mUnk_04 = p->mUnk_04;
        while (*(vu16 *) 0x4000280 & 0x8000) {
        }
        gTouchPanelState.mCalibration.mUnk_08 = *(vu32 *) 0x40002a0;
    } else {
        gTouchPanelState.mCalibration.mUnk_00 = 0;
        gTouchPanelState.mCalibration.mUnk_04 = 0;
        gTouchPanelState.mCalibration.mUnk_08 = 0;
    }
    b = p->mUnk_06;
    if (b != 0) {
        *(vu16 *) 0x4000280 = 0;
        *(vu32 *) 0x4000290 = 0x10000000;
        den = (vu32 *) 0x4000298;
        den[0] = b;
        den[1] = 0;
        gTouchPanelState.mCalibration.mUnk_0c = p->mUnk_02;
        gTouchPanelState.mCalibration.mUnk_10 = p->mUnk_06;
        while (*(vu16 *) 0x4000280 & 0x8000) {
        }
        gTouchPanelState.mCalibration.mUnk_14 = *(vu32 *) 0x40002a0;
    } else {
        gTouchPanelState.mCalibration.mUnk_0c = 0;
        gTouchPanelState.mCalibration.mUnk_10 = 0;
        gTouchPanelState.mCalibration.mUnk_14 = 0;
    }
    IrqRestore(v);
    gTouchPanelState.mCalibrated = 1;
}

void TP_RequestSamplingAsync(void) {
    u32 v = IrqDisable();
    s32 r = PxiSendFifoWord(6, 0x3000000, 0);
    u32 ok = r >= 0 ? 1 : 0;

    if (ok == 0) {
        IrqRestore(v);
        gTouchPanelState.mErrorFlags |= 1;
        if (gTouchPanelState.mCallback != 0) {
            gTouchPanelState.mCallback(0, 4, 0);
        }
    } else {
        gTouchPanelState.mBusyFlags |= 1;
        gTouchPanelState.mErrorFlags &= ~1;
        IrqRestore(v);
    }
}

u32 TP_WaitRawResult(TouchSample *out) {
    TP_WaitBusy(1);
    if (gTouchPanelState.mErrorFlags & 1) {
        return 1;
    }
    *out = gTouchPanelState.mRawSample;
    return 0;
}

void TP_RequestAutoSamplingStartAsync(u32 a, u32 b, TouchSample *p, u32 n) {
    u32 i;
    u32 s;
    u8 ok;
    void (*f)(u32, u8, u8);

    gTouchPanelState.mAutoSampleBuffer = p;
    gTouchPanelState.mAutoSampleIndex = 0;
    gTouchPanelState.mUnk_0e = b;
    gTouchPanelState.mAutoSampleBufferCount = n;
    for (i = 0; i < n; i++) {
        gTouchPanelState.mAutoSampleBuffer[i].mTouched = 0;
    }
    s = IrqDisable();
    if (PxiSendFifoWord(6, (b & 0xff) | 0x2000100, 0) < 0) {
        ok = 0;
    } else {
        if (PxiSendFifoWord(6, a | 0x1010000, 0) < 0) {
            ok = 0;
        } else {
            ok = 1;
        }
    }
    if ((ok & 0xff) == 0) {
        IrqRestore(s);
        gTouchPanelState.mErrorFlags |= 2;
        f = gTouchPanelState.mCallback;
        if (f != 0) {
            f(1, 4, 0);
        }
    } else {
        gTouchPanelState.mBusyFlags |= 2;
        gTouchPanelState.mErrorFlags &= ~2;
        IrqRestore(s);
    }
}

void TP_RequestAutoSamplingStopAsync(void) {
    u32 s;
    s32 ok;
    void (*f)(u32, u8, u8);

    s = IrqDisable();
    ok = PxiSendFifoWord(6, 0x3000200, 0) >= 0;
    if ((ok & 0xff) == 0) {
        IrqRestore(s);
        gTouchPanelState.mErrorFlags |= 4;
        f = gTouchPanelState.mCallback;
        if (f != 0) {
            f(2, 4, 0);
        }
    } else {
        gTouchPanelState.mBusyFlags |= 4;
        gTouchPanelState.mErrorFlags &= ~4;
        IrqRestore(s);
    }
}

u32 TP_GetLatestIndexInAuto(void) {
    u32 value0;
    value0 = (u32) gTouchPanelState.mAutoSampleIndex;
    return value0;
}

u32 TP_CalcCalibrateParam(Unk0214e334 *out, u16 a, u16 b, u16 c, u16 d, u16 e, u16 f, u16 g, u16 h) {
    s32 z;
    s32 w;
    s32 q;
    u32 s;

    if (a >= 0x1000 || b >= 0x1000 || e >= 0x1000 || f >= 0x1000) {
        return 1;
    }
    if (c >= 0x100 || g >= 0x100 || d >= 0xc0 || h >= 0xc0) {
        return 1;
    }
    if (c == g || d == h || a == e || b == f) {
        return 1;
    }
    s = IrqDisable();
    reg_CP_DIVCNT = 0;
    *(vu32 *) 0x04000290 = (a - e) << 8;
    reg_CP_DIV_DENOM = (u32) (c - g);
    z = b - f;
    w = d - h;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    q = *(vs32 *) 0x040002a0;
    reg_CP_DIVCNT = 0;
    *(vu32 *) 0x04000290 = z << 8;
    reg_CP_DIV_DENOM = (u32) w;
    if (q >= 0x8000 || q < -0x8000) {
        IrqRestore(s);
        return 1;
    }
    out->mUnk_04 = q;
    q = (s16) ((((a + e) << 8) - out->mUnk_04 * (c + g)) >> 7);
    if (q >= 0x8000 || q < -0x8000) {
        IrqRestore(s);
        return 1;
    }
    out->mUnk_00 = q;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    q = *(vs32 *) 0x040002a0;
    IrqRestore(s);
    if (q >= 0x8000 || q < -0x8000) {
        return 1;
    }
    out->mUnk_06 = q;
    q = (s16) ((((b + f) << 8) - out->mUnk_06 * (d + h)) >> 7);
    if (q >= 0x8000 || q < -0x8000) {
        return 1;
    }
    out->mUnk_02 = q;
    return 0;
}

void TP_GetCalibratedPoint(Unk0214e334 *out, const TouchSample *in) {
    TouchCalibration *c;
    s64 t;

    if (gTouchPanelState.mCalibrated == 0) {
        *(TouchSample *) out = *in;
        return;
    }
    c = &gTouchPanelState.mCalibration;
    out->mUnk_04 = in->mTouched;
    out->mUnk_06 = in->mInvalidBits;
    if (in->mTouched == 0) {
        out->mUnk_00 = 0;
        out->mUnk_02 = 0;
        return;
    }
    t = ((s64) (in->mX * 4) - c->mUnk_00) * c->mUnk_08;
    out->mUnk_00 = t >> 22;
    if (out->mUnk_00 < 0) {
        out->mUnk_00 = 0;
    } else if (out->mUnk_00 > 0xff) {
        out->mUnk_00 = 0xff;
    }
    t = ((s64) (in->mY * 4) - c->mUnk_0c) * c->mUnk_14;
    out->mUnk_02 = t >> 22;
    if (out->mUnk_02 < 0) {
        out->mUnk_02 = 0;
        return;
    }
    if (out->mUnk_02 > 0xbf) {
        out->mUnk_02 = 0xbf;
    }
}

void TP_WaitBusy(u32 a) {
    while (gTouchPanelState.mBusyFlags & a) {
    }
}

u32 TP_CheckError(u32 a) {
    return gTouchPanelState.mErrorFlags & a;
}
