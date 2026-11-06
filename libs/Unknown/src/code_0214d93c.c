#include "code_0214d93c.h"

#include "code_0200fc8c.h"
#include "code_0214d5b8.h"
#include "Main/Unknown/code_0200f000.h"

u16 gClockInitialized;

s32 TrySendReadDateCommand(void) {
    return TrySendClockCommand(0x11);
}

s32 TrySendReadTimeCommand(void) {
    return TrySendClockCommand(0x12);
}

// Calls TrySendClockCommand with 0x27.
s32 func_0214e1b0(void) {
    return TrySendClockCommand(0x27);
}

s32 TrySendClockCommand(u32 a) {
    return PxiSendFifoWord(5, (a << 8) & 0x7f00, 0) >= 0;
}

void RTC_Init(void) {
    if (gClockInitialized != 0) {
        return;
    }
    gClockInitialized = 1;
    gClockRequest.mLocked = 0;
    gClockRequest.mCallback = 0;
    gClockRequest.mEventCallback = 0;
    gClockRequest.mOutput = 0;
    gClockRequest.mSecondOutput = 0;
    PxiInit();
    while (PxiCallbackBitIsSet(5, 1) == 0) {
    }
    PxiCallbackSet(5, ReceiveClockReply);
}

u32 RTC_GetDateAsync(u32 *a, UnkFunc *b, u32 c) {
    u32 s;

    s = OS_DisableInterrupts();
    if (gClockRequest.mLocked != 0) {
        OS_RestoreInterrupts(s);
        return 1;
    }
    gClockRequest.mLocked = 1;
    OS_RestoreInterrupts(s);
    gClockRequest.mKind = 0;
    gClockRequest.mWriteReplyPending = 0;
    gClockRequest.mOutput = a;
    gClockRequest.mCallback = b;
    gClockRequest.mCallbackArg = c;
    return TrySendReadDateCommand() != 0 ? 0 : 3;
}

u32 RTC_GetDate(u32 *a) {
    gClockRequest.mResult = RTC_GetDateAsync(a, SetClockResult, 0);
    if (gClockRequest.mResult == 0) {
        WaitClockRequestDone();
    }
    return gClockRequest.mResult;
}

u32 RTC_GetTimeAsync(u32 *a, UnkFunc *b, u32 c) {
    u32 s;

    s = OS_DisableInterrupts();
    if (gClockRequest.mLocked != 0) {
        OS_RestoreInterrupts(s);
        return 1;
    }
    gClockRequest.mLocked = 1;
    OS_RestoreInterrupts(s);
    gClockRequest.mKind = 1;
    gClockRequest.mWriteReplyPending = 0;
    gClockRequest.mOutput = a;
    gClockRequest.mCallback = b;
    gClockRequest.mCallbackArg = c;
    return TrySendReadTimeCommand() != 0 ? 0 : 3;
}

u32 RTC_GetTime(u32 *a) {
    gClockRequest.mResult = RTC_GetTimeAsync(a, SetClockResult, 0);
    if (gClockRequest.mResult == 0) {
        WaitClockRequestDone();
    }
    return gClockRequest.mResult;
}

void ReceiveClockReply(u32 a, u32 b, s32 c) {
    u8 k;
    u32 x;
    u32 n;
    u32 *p;
    UnkFunc *f;

    if (c != 0) {
        if (gClockRequest.mWriteReplyPending != 0) {
            gClockRequest.mWriteReplyPending = 0;
        }
        if (gClockRequest.mLocked != 0) {
            gClockRequest.mLocked = 0;
        }
        f = gClockRequest.mCallback;
        if (f != 0) {
            gClockRequest.mCallback = 0;
            f(6, gClockRequest.mCallbackArg);
        }
        return;
    }
    k = (b & 0x7f00) >> 8;
    x = b & 0xff;
    if (k == 0x30) {
        if (gClockRequest.mEventCallback != 0) {
            gClockRequest.mEventCallback();
        }
        return;
    }
    if (x == 0) {
        n = 0;
        switch (gClockRequest.mKind) {
            case 0:
                p = gClockRequest.mOutput;
                p[0] = DecimalNibblesToValue(((ClockDateWord *) 0x027ffde8)->mYear);
                p[1] = DecimalNibblesToValue(((ClockDateWord *) 0x027ffde8)->mMonth);
                p[2] = DecimalNibblesToValue(((ClockDateWord *) 0x027ffde8)->mDay);
                p[3] = ((ClockDateWord *) 0x027ffde8)->mWeekday;
                break;
            case 1:
                p = gClockRequest.mOutput;
                p[0] = DecimalNibblesToValue(((ClockTimeWord *) 0x027ffdec)->mHour);
                p[1] = DecimalNibblesToValue(((ClockTimeWord *) 0x027ffdec)->mMinute);
                p[2] = DecimalNibblesToValue(((ClockTimeWord *) 0x027ffdec)->mSecond);
                break;
            case 2:
                p = gClockRequest.mOutput;
                p[0] = DecimalNibblesToValue(*(u32 *) 0x027ffde8 & 0xff);
                p[1] = DecimalNibblesToValue(((ClockDateWord *) 0x027ffde8)->mMonth);
                p[2] = DecimalNibblesToValue(((ClockDateWord *) 0x027ffde8)->mDay);
                p[3] = ((ClockDateWord *) 0x027ffde8)->mWeekday;
                p = gClockRequest.mSecondOutput;
                p[0] = DecimalNibblesToValue(((ClockTimeWord *) 0x027ffdec)->mHour);
                p[1] = DecimalNibblesToValue(((ClockTimeWord *) 0x027ffdec)->mMinute);
                p[2] = DecimalNibblesToValue(((ClockTimeWord *) 0x027ffdec)->mSecond);
                break;
            case 3:
            case 4:
            case 5:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
                break;
            case 6:
                p = gClockRequest.mOutput;
                switch (((Unk027ffdea *) 0x027ffdea)->mUnk_00_0) {
                    case 4:
                        p[0] = 1;
                        break;
                    default:
                        p[0] = 0;
                        break;
                }
                break;
            case 7:
                p = gClockRequest.mOutput;
                if (((Unk027ffdea *) 0x027ffdea)->mUnk_00_6) {
                    p[0] = 1;
                } else {
                    p[0] = 0;
                }
                break;
            case 8:
                p = gClockRequest.mOutput;
                p[0] = ((Unk027ffdec_b *) 0x027ffdec)->mUnk_00_0;
                p[1] = DecimalNibblesToValue(((Unk027ffdec_b *) 0x027ffdec)->mUnk_00_8);
                p[2] = DecimalNibblesToValue(((Unk027ffdec_b *) 0x027ffdec)->mUnk_00_16);
                p[3] = 0;
                if (((Unk027ffdec_b *) 0x027ffdec)->mUnk_00_7) {
                    p[3] += 1;
                }
                if (((Unk027ffdec_b *) 0x027ffdec)->mUnk_00_15) {
                    p[3] += 2;
                }
                if (((Unk027ffdec_b *) 0x027ffdec)->mUnk_00_23) {
                    p[3] += 4;
                }
                break;
            case 9:
                if (gClockRequest.mWriteReplyPending == 0) {
                    if (*gClockRequest.mOutput == 1) {
                        if (((Unk027ffdea *) 0x027ffdea)->mUnk_00_0 != 4) {
                            gClockRequest.mWriteReplyPending++;
                            ((Unk027ffdea *) 0x027ffdea)->mUnk_00_0 = 4;
                            if (func_0214e1b0() == 0) {
                                n = 3;
                                gClockRequest.mWriteReplyPending = 0;
                            }
                        }
                    } else {
                        if (((Unk027ffdea *) 0x027ffdea)->mUnk_00_0 != 0) {
                            gClockRequest.mWriteReplyPending++;
                            ((Unk027ffdea *) 0x027ffdea)->mUnk_00_0 = 0;
                            if (func_0214e1b0() == 0) {
                                n = 3;
                                gClockRequest.mWriteReplyPending = 0;
                            }
                        }
                    }
                } else {
                    gClockRequest.mWriteReplyPending = 0;
                }
                break;
            case 10:
                if (gClockRequest.mWriteReplyPending == 0) {
                    if (*gClockRequest.mOutput == 1) {
                        if (((Unk027ffdea *) 0x027ffdea)->mUnk_00_6 == 0) {
                            gClockRequest.mWriteReplyPending++;
                            ((Unk027ffdea *) 0x027ffdea)->mUnk_00_6 = 1;
                            if (func_0214e1b0() == 0) {
                                n = 3;
                                gClockRequest.mWriteReplyPending = 0;
                            }
                        }
                    } else {
                        if (((Unk027ffdea *) 0x027ffdea)->mUnk_00_6 != 0) {
                            gClockRequest.mWriteReplyPending++;
                            ((Unk027ffdea *) 0x027ffdea)->mUnk_00_6 = 0;
                            if (func_0214e1b0() == 0) {
                                n = 3;
                                gClockRequest.mWriteReplyPending = 0;
                            }
                        }
                    }
                } else {
                    gClockRequest.mWriteReplyPending = 0;
                }
                break;
            default:
                gClockRequest.mWriteReplyPending = 0;
                n = 4;
                break;
        }
    } else {
        gClockRequest.mWriteReplyPending = 0;
        switch (x) {
            case 1:
                n = 4;
                break;
            case 2:
                n = 5;
                break;
            case 3:
                n = 1;
                break;
            case 0:
            case 4:
            default:
                n = 6;
                break;
        }
    }
    if (gClockRequest.mWriteReplyPending != 0) {
        return;
    }
    if (gClockRequest.mLocked != 0) {
        gClockRequest.mLocked = 0;
    }
    f = gClockRequest.mCallback;
    if (f != 0) {
        gClockRequest.mCallback = 0;
        f(n, gClockRequest.mCallbackArg);
    }
}

// Returns the value of x read as 8 decimal digits (4 bits each, least significant first), or 0 when a digit is above 9.
u32 DecimalNibblesToValue(u32 x) {
    u32 r;
    u32 m;
    s32 i;

    r = 0;
    for (i = 0; i < 8; i++) {
        if (((x >> (i * 4)) & 0xf) >= 10) {
            return 0;
        }
    }
    m = 1;
    for (i = 0; i < 8; i++) {
        r += m * ((x >> (i * 4)) & 0xf);
        m *= 10;
    }
    return r;
}

void SetClockResult(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    gClockRequest.mResult = value0;
}

// clang-format off
// Hand-written asm: waits while the first word of gClockRequest is 1. It keeps the address in ip, a register
// compiled C would not use for it.
asm void WaitClockRequestDone(void) {
    ldr ip, =gClockRequest
wait_loop:
    ldr r0, [ip]
    cmp r0, #0x1
    beq wait_loop
    bx lr
}
// clang-format on
