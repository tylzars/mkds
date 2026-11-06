#include "code_0214f4a4.h"
#include "code_0200fc8c.h"
#include "code_0200c4a4.h"
#include "code_0200c914.h"
#include "code_0200edc0.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0214d5b8.h"

u16 gPowerInitialized;
vu32 data_02180438;
CallbackEntry *gPowerPostSleepCallbacks;
u32 data_02180440;
CallbackEntry *gPowerPreSleepCallbacks;
vu32 gPowerSleepHandshakeReplyReceived;
PowerCommand gPowerCommand;
OSMutex data_02180458;
PowerRegisterSlot gPowerRegisterSlots[4];

int TryLockPowerCommand(void) {
    u32 v;

    v = IrqDisable();
    if (gPowerCommand.mLocked != 0) {
        IrqRestore(v);
        return 0;
    }
    gPowerCommand.mLocked = 1;
    IrqRestore(v);
    return 1;
}

void WaitPowerCommandDone(void) {
    vu32 *p;

    p = &gPowerCommand.mLocked;
    while (*p != 0) {
    }
}

void WordStore(u32 a, u32 *p) {
    *p = a;
}

void FinishPowerCommand(u32 a) {
    u32 f;
    void (*fn)(u32 a, u32 *b);
    u32 *arg;

    f = gPowerCommand.mLocked;
    fn = gPowerCommand.mCallback;
    arg = gPowerCommand.mCallbackArg;
    if (f != 0) {
        gPowerCommand.mLocked = 0;
    }
    if (fn == 0) {
        return;
    }
    gPowerCommand.mCallback = 0;
    fn(a, arg);
}

void PM_Init(void) {
    int i;

    if (gPowerInitialized != 0) {
        return;
    }
    gPowerInitialized = 1;
    gPowerCommand.mLocked = 0;
    gPowerCommand.mCallback = 0;
    PxiInit();
    while (PxiCallbackBitIsSet(8, 1) == 0) {
    }
    PxiCallbackSet(8, ReceivePowerReply);
    for (i = 0; i < 4; i++) {
        gPowerRegisterSlots[i].mReplyReceived = 0;
    }
    OS_InitMutex(&data_02180458);
    data_02180440 = *(u32 *) 0x27ffc3c;
}

void ReceivePowerReply(u32 a, u32 b, u32 c) {
    u16 v;
    u16 t;
    u32 *p;

    if (c != 0) {
        FinishPowerCommand(2);
        return;
    }
    t = (b & 0x7f00) >> 8;
    v = b & 0xff;
    if (t >= 0x70 && t <= 0x73) {
        u16 *q;
        u16 w;

        w = v & 0xff;
        q = gPowerRegisterSlots[t - 0x70].mBuffer;
        if (q != 0) {
            *q = w;
        }
        gPowerRegisterSlots[t - 0x70].mReplyReceived = 1;
        v = 0;
    } else if (t == 0x60) {
        gPowerSleepHandshakeReplyReceived = 1;
    } else if (t == 0x62) {
        data_02180438 = 1;
    } else if (t == 0x67) {
        p = gPowerCommand.mLedPatternBuffer;
        if (p != 0) {
            *p = v;
        }
        v = 0;
    }
    FinishPowerCommand(v);
}

int SendPowerSleepRequest(u32 a, u16 b) {
    if (TryLockPowerCommand() == 0) {
        return 1;
    }
    gPowerSleepHandshakeReplyReceived = 0;
    SendPowerFifoWord(0x3006000);
    while (gPowerSleepHandshakeReplyReceived == 0) {
    }
    gPowerSleepHandshakeReplyReceived = 0;
    data_02180438 = 0;
    TrySetLcdPowerAndLed(0, 2, 0, 0);
    SendPowerFifoWord((a & 0xff) | 0x2006100);
    SendPowerFifoWord((b & 0xffff) | 0x1010000);
    return 0;
}

int PM_SendUtilityCommandAsync(u32 a, void (*fn)(u32 a, u32 *b), u32 *arg) {
    if (TryLockPowerCommand() == 0) {
        return 1;
    }
    gPowerCommand.mCallback = fn;
    gPowerCommand.mCallbackArg = arg;
    SendPowerFifoWord(((a >> 16) & 0xff) | 0x2006300);
    SendPowerFifoWord((a & 0xffff) | 0x1010000);
    return 0;
}

int ReadPowerRegisterAsync(u32 a, u16 *p, void (*fn)(u32 a, u32 *b), u32 *arg) {
    if (TryLockPowerCommand() == 0) {
        return 1;
    }
    gPowerRegisterSlots[a].mReplyReceived = 0;
    gPowerCommand.mCallback = fn;
    gPowerCommand.mCallbackArg = arg;
    gPowerRegisterSlots[a].mBuffer = p;
    SendPowerFifoWord((a & 0xff) | 0x3006500);
    return 0;
}

int ReadPowerRegister(u32 a, u16 *p) {
    u32 v;
    int r;

    r = ReadPowerRegisterAsync(a, p, WordStore, &v);
    if (r != 0) {
        return r;
    }
    WaitPowerCommandDone();
    return v;
}

int WritePowerRegisterAsync(u32 a, u16 b, void (*fn)(u32 a, u32 *b), u32 *arg) {
    if (TryLockPowerCommand() == 0) {
        return 1;
    }
    gPowerCommand.mCallback = fn;
    gPowerCommand.mCallbackArg = arg;
    SendPowerFifoWord((a & 0xff) | 0x2006400);
    SendPowerFifoWord((b & 0xffff) | 0x1010000);
    return 0;
}

int WritePowerRegister(u32 a, u16 b) {
    u32 v;
    int r;

    r = WritePowerRegisterAsync(a, b, WordStore, &v);
    if (r != 0) {
        return r;
    }
    WaitPowerCommandDone();
    return v;
}

int SetPowerLedAsync(u32 a, void (*fn)(u32 a, u32 *b), u32 *arg) {
    u32 b;

    switch (a) {
        case 1:
            b = 1;
            break;
        case 3:
            b = 2;
            break;
        case 2:
            b = 3;
            break;
        default:
            b = 0;
            break;
    }
    if (b == 0) {
        return 0xffff;
    }
    return PM_SendUtilityCommandAsync(b, fn, arg);
}

int SetPowerLed(u32 a) {
    u32 v;
    int r;

    r = SetPowerLedAsync(a, WordStore, &v);
    if (r != 0) {
        return r;
    }
    WaitPowerCommandDone();
    return v;
}

int PM_SetBackLightAsync(u32 a, u32 b, void (*fn)(u32 a, u32 *b), u32 *arg) {
    u32 c;

    c = 0;
    if (a == 0) {
        if (b == 1) {
            c = 6;
        }
        if (b == 0) {
            c = 7;
        }
    } else if (a == 1) {
        if (b == 1) {
            c = 4;
        }
        if (b == 0) {
            c = 5;
        }
    } else if (a == 2) {
        if (b == 1) {
            c = 8;
        }
        if (b == 0) {
            c = 9;
        }
    }
    if (c == 0) {
        return 0xffff;
    }
    return PM_SendUtilityCommandAsync(c, fn, arg);
}

int PM_SetBackLight(u32 a, u32 b) {
    u32 v;
    int r;

    r = PM_SetBackLightAsync(a, b, WordStore, &v);
    if (r != 0) {
        return r;
    }
    WaitPowerCommandDone();
    return v;
}

int PM_ForceToPowerOffAsync(void (*fn)(u32 a, u32 *b), u32 *arg) {
    return PM_SendUtilityCommandAsync(0xe, fn, arg);
}

int PM_ForceToPowerOff(void) {
    u32 v;
    int r;

    r = PM_ForceToPowerOffAsync(WordStore, &v);
    if (r != 0) {
        return r;
    }
    WaitPowerCommandDone();
    return v;
}

int PM_SetAmp(u32 a) {
    return WritePowerRegister(2, a);
}

int PM_SetAmpGain(u32 a) {
    return WritePowerRegister(3, a);
}

int PM_GetBackLight(u32 *a, u32 *b) {
    u16 v;
    int r;

    r = ReadPowerRegister(0, &v);
    if (r != 0) {
        return r;
    }
    if (a != 0) {
        *a = (v & 8) != 0 ? 1 : 0;
    }
    if (b != 0) {
        *b = (v & 4) != 0 ? 1 : 0;
    }
    return r;
}

void SendPowerFifoWord(u32 a) {
    while (PxiSendFifoWord(8, a, 0) != 0) {
    }
}

static inline u32 func_0214f83c_inline(void) {
    return *(vu32 *) 0x27ffc3c;
}

void PM_GoSleepMode(u32 a, u32 b, u32 c) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 w0;
    u32 w1;
    vu32 t;
    u32 d;
    u32 k0;
    u32 k1;
    u32 g;
    u16 saved;
    u16 tmp;

    d = 0;
    CallbackListRun(gPowerPreSleepCallbacks);
    saved = *(vu16 *) 0x4000208;
    *(vu16 *) 0x4000208 = 0;
    v0 = IrqDisable();
    v1 = OS_DisableIrqMask(0x3fffff);
    OS_SetIrqMask(0x40000);
    IrqRestore(v0);
    tmp = *(vu16 *) 0x4000208;
    *(vu16 *) 0x4000208 = 1;
    if ((a & 8) != 0) {
        if (*(vu16 *) 0x27ffc40 == 2) {
            a &= ~8;
        }
    }
    if ((a & 0x10) != 0) {
        if (CTRDG_IsExisting() == 0) {
            a &= ~0x10;
        }
    }
    k0 = *(vu32 *) 0x4000000;
    k1 = *(vu32 *) 0x4001000;
    v2 = PM_GetLCDPower();
    PM_GetBackLight(&w0, &w1);
    PM_SetBackLight(2, 0);
    t = func_0214f83c_inline();
    while (t == func_0214f83c_inline()) {
    }
    t = func_0214f83c_inline();
    *(vu32 *) 0x4000000 &= ~0x30000;
    *(vu32 *) 0x4001000 &= ~0x10000;
    while (t == func_0214f83c_inline()) {
    }
    t = func_0214f83c_inline();
    while (t == func_0214f83c_inline()) {
    }
    g = (u16) (a | (w0 << 5) | (w1 << 6));
    while (SendPowerSleepRequest(g, (u16) (b | c)) != 0) {
    }
    OS_Halt();
    func_0200fd10(0x332340);
    if ((a & 8) != 0) {
        if ((*(vu32 *) 0x4000214 & 0x100000) != 0) {
            d = 1;
        }
    }
    if (d == 0) {
        if (v2 == 1) {
            TrySetLcdPowerAndLed(1, 1, 1, 0);
        } else {
            SetPowerLed(1);
        }
        *(vu32 *) 0x4000000 = k0;
        *(vu32 *) 0x4001000 = k1;
    }
    IrqDisable();
    OS_SetIrqMask(v1);
    IrqRestore(v0);
    tmp = *(vu16 *) 0x4000208;
    *(vu16 *) 0x4000208 = saved;
    if (d != 0) {
        PM_ForceToPowerOff();
    }
    CallbackListRun(gPowerPostSleepCallbacks);
}

int TrySetLcdPowerAndLed(u32 a, u32 b, u32 c, u32 d) {
    switch (a) {
        case 1:
            if (c == 0) {
                if (*(vu32 *) 0x27ffc3c - data_02180440 <= 7) {
                    return 0;
                }
            }
            if (b != 0) {
                if (d != 0) {
                    SetPowerLed(b);
                } else {
                    SetPowerLedAsync(b, 0, 0);
                }
            }
            *(vu16 *) 0x4000304 |= 1;
            break;
        case 0:
            *(vu16 *) 0x4000304 &= ~1;
            data_02180440 = *(vu32 *) 0x27ffc3c;
            if (b != 0) {
                if (d != 0) {
                    SetPowerLed(b);
                } else {
                    SetPowerLedAsync(b, 0, 0);
                }
            }
            break;
    }
    return 1;
}

int PM_SetLCDPower(u32 a) {
    if (a != 1) {
        a = 0;
    }
    return TrySetLcdPowerAndLed(a, 0, 0, 1);
}

int PM_GetLCDPower(void) {
    return (*(vu16 *) 0x4000304 & 1) != 0 ? 1 : 0;
}

int SendPowerLedPatternAsync(u32 a, void (*fn)(u32 a, u32 *b), u32 *arg) {
    if (TryLockPowerCommand() == 0) {
        return 1;
    }
    gPowerCommand.mCallback = fn;
    gPowerCommand.mCallbackArg = arg;
    SendPowerFifoWord((a & 0xff) | 0x3006600);
    return 0;
}

int SendPowerLedPattern(u32 a) {
    u32 v;
    int r;

    r = SendPowerLedPatternAsync(a, WordStore, &v);
    if (r != 0) {
        return r;
    }
    WaitPowerCommandDone();
    return v;
}

int PM_GetLEDPatternAsync(u32 *p, void (*fn)(u32 a, u32 *b), u32 *arg) {
    if (TryLockPowerCommand() == 0) {
        return 1;
    }
    gPowerCommand.mCallback = fn;
    gPowerCommand.mCallbackArg = arg;
    gPowerCommand.mLedPatternBuffer = p;
    SendPowerFifoWord(0x3006700);
    return 0;
}

int PM_GetLEDPattern(u32 *p) {
    u32 v;
    int r;

    r = PM_GetLEDPatternAsync(p, WordStore, &v);
    if (r != 0) {
        return r;
    }
    WaitPowerCommandDone();
    return v;
}

void CallbackListPrepend(CallbackEntry **pp, CallbackEntry *p) {
    if (pp != 0) {
        p->mNext = *pp;
        *pp = p;
    }
}

void CallbackListAppend(CallbackEntry **pp, CallbackEntry *p) {
    CallbackEntry *a;
    CallbackEntry *b;

    if (pp == 0) {
        return;
    }
    a = *pp;
    if (a == 0) {
        p->mNext = 0;
        *pp = p;
        return;
    }
    b = a->mNext;
    while (b != 0) {
        a = b;
        b = b->mNext;
    }
    p->mNext = b;
    a->mNext = p;
}

void CallbackListRemove(CallbackEntry **pp, CallbackEntry *p) {
    CallbackEntry *a;
    CallbackEntry *b;

    if (pp == 0) {
        return;
    }
    a = *pp;
    b = a;
    if (a == 0) {
        return;
    }
    do {
        if (a == p) {
            if (a == b) {
                *pp = a->mNext;
            } else {
                b->mNext = a->mNext;
            }
            return;
        }
        b = a;
        a = a->mNext;
    } while (a != 0);
}

void CallbackListRun(CallbackEntry *p) {
    if (p == 0) {
        return;
    }
    do {
        p->mCallback(p->mArg);
        p = p->mNext;
    } while (p != 0);
}

void PM_AppendPreSleepCallback(CallbackEntry *p) {
    CallbackListAppend(&gPowerPreSleepCallbacks, p);
}

void PM_PrependPreSleepCallback(CallbackEntry *p) {
    CallbackListPrepend(&gPowerPreSleepCallbacks, p);
}

void PM_AppendPostSleepCallback(CallbackEntry *p) {
    CallbackListAppend(&gPowerPostSleepCallbacks, p);
}

void PM_DeletePreSleepCallback(CallbackEntry *p) {
    CallbackListRemove(&gPowerPreSleepCallbacks, p);
}

void PM_DeletePostSleepCallback(CallbackEntry *p) {
    CallbackListRemove(&gPowerPostSleepCallbacks, p);
}
