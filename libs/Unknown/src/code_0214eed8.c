#include "code_0214eed8.h"

#include "code_0214d5b8.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200f000.h"

u16 gMicrophoneInitialized;

void MIC_Init(void) {
    if (gMicrophoneInitialized != 0) {
        return;
    }
    gMicrophoneInitialized = 1;
    gMicrophoneCommand.mUnk_00 = 0;
    gMicrophoneCommand.mUnk_04 = 0;
    PxiInit();
    while (!PxiCallbackBitIsSet(9, 1)) {
    }
    *(u32 *) 0x27fff90 = 0;
    PxiCallbackSet(9, ReceiveMicrophoneReply);
}

u32 MIC_StartAutoSamplingAsync(Unk0214f2a8 *p, void (*fn)(), u32 arg) {
    u32 f;
    u32 v;
    u32 b;
    u8 g;

    if ((p->mUnk_04 & 0x1f) != 0) {
        return 2;
    }
    b = p->mUnk_08;
    if ((b & 0x1f) != 0) {
        return 2;
    }
    if (b == 0) {
        return 2;
    }
    if (p->mUnk_0c < 0x400) {
        return 2;
    }
    switch (p->mUnk_00) {
        case 0:
            f = 0;
            break;
        case 1:
            f = 1;
            break;
        case 2:
            f = 2;
            break;
        case 3:
            f = 3;
            break;
        case 4:
            f = 5;
            break;
        case 5:
            f = 7;
            break;
        default:
            return 2;
    }
    g = p->mUnk_10 != 0 ? (f | 0x10) & 0xff : f & 0xff;
    v = OS_DisableInterrupts();
    if (gMicrophoneCommand.mUnk_00 != 0) {
        OS_RestoreInterrupts(v);
        return 1;
    }
    gMicrophoneCommand.mUnk_00 = 1;
    OS_RestoreInterrupts(v);
    gMicrophoneCommand.mUnk_04 = fn;
    gMicrophoneCommand.mUnk_08 = arg;
    gMicrophoneCommand.mUnk_10 = p->mUnk_14;
    gMicrophoneCommand.mUnk_14 = p->mUnk_18;
    return TrySendMicrophoneStartCommand(p->mUnk_04, p->mUnk_08, p->mUnk_0c, g) != 0 ? 0 : 3;
}

u32 MIC_StartAutoSampling(Unk0214f2a8 *p) {
    gMicrophoneCommand.mUnk_0c = MIC_StartAutoSamplingAsync(p, SetMicrophoneResult, 0);
    if (gMicrophoneCommand.mUnk_0c == 0) {
        WaitMicrophoneIdle();
    }
    return gMicrophoneCommand.mUnk_0c;
}

u32 MIC_StopAutoSamplingAsync(void (*fn)(), u32 arg) {
    u32 v = OS_DisableInterrupts();

    if (gMicrophoneCommand.mUnk_00 != 0) {
        OS_RestoreInterrupts(v);
        return 1;
    }
    gMicrophoneCommand.mUnk_00 = 1;
    OS_RestoreInterrupts(v);
    gMicrophoneCommand.mUnk_04 = fn;
    gMicrophoneCommand.mUnk_08 = arg;
    return TrySendMicrophoneStopCommand() != 0 ? 0 : 3;
}

u32 MIC_StopAutoSampling(void) {
    gMicrophoneCommand.mUnk_0c = MIC_StopAutoSamplingAsync(SetMicrophoneResult, 0);
    if (gMicrophoneCommand.mUnk_0c == 0) {
        WaitMicrophoneIdle();
    }
    return gMicrophoneCommand.mUnk_0c;
}

u32 MIC_GetLastSamplingAddress(void) {
    u32 value0;
    value0 = 0x27fff90u;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    return value0;
}

void ReceiveMicrophoneReply(u32 a, u32 b, u32 c) {
    u16 x;
    u16 k;
    u32 n;

    if (c != 0) {
        if (gMicrophoneCommand.mUnk_00 != 0) {
            gMicrophoneCommand.mUnk_00 = 0;
        }
        if (gMicrophoneCommand.mUnk_04 != 0) {
            void (*g)() = gMicrophoneCommand.mUnk_04;
            gMicrophoneCommand.mUnk_04 = 0;
            g(6, gMicrophoneCommand.mUnk_08);
        }
    }
    x = b & 0xff;
    k = (b & 0x7f00) >> 8;
    switch (x) {
        case 0:
            n = 0;
            break;
        case 1:
            n = 4;
            break;
        case 2:
            n = 2;
            break;
        case 3:
            n = 5;
            break;
        case 4:
            n = 1;
            break;
        default:
            n = 6;
            break;
    }
    if (k == 0x51) {
        if (gMicrophoneCommand.mUnk_10 != 0) {
            gMicrophoneCommand.mUnk_10(n, gMicrophoneCommand.mUnk_14);
        }
        return;
    }
    if (k == 0x40) {
        if (gMicrophoneCommand.mUnk_18 != 0) {
            *gMicrophoneCommand.mUnk_18 = *(u16 *) 0x27fff94;
        }
    }
    if (gMicrophoneCommand.mUnk_00 != 0) {
        gMicrophoneCommand.mUnk_00 = 0;
    }
    if (gMicrophoneCommand.mUnk_04 != 0) {
        void (*f)() = gMicrophoneCommand.mUnk_04;
        gMicrophoneCommand.mUnk_04 = 0;
        f(n, gMicrophoneCommand.mUnk_08);
    }
}

u32 TrySendMicrophoneStartCommand(u32 a, u32 b, u32 c, u32 d) {
    if (PxiSendFifoWord(9, d | 0x2004100, 0) < 0) {
        return 0;
    }
    if (PxiSendFifoWord(9, (a >> 16) | 0x10000, 0) < 0) {
        return 0;
    }
    if (PxiSendFifoWord(9, (a & 0xffff) | 0x20000, 0) < 0) {
        return 0;
    }
    if (PxiSendFifoWord(9, (b >> 16) | 0x30000, 0) < 0) {
        return 0;
    }
    if (PxiSendFifoWord(9, (b & 0xffff) | 0x40000, 0) < 0) {
        return 0;
    }
    if (PxiSendFifoWord(9, (c >> 16) | 0x50000, 0) < 0) {
        return 0;
    }
    return PxiSendFifoWord(9, (c & 0xffff) | 0x1060000, 0) >= 0;
}

s32 TrySendMicrophoneStopCommand(void) {
    return PxiSendFifoWord(9, 0x3004200, 0) >= 0;
}

void SetMicrophoneResult(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    gMicrophoneCommand.mUnk_0c = value0;
}

// clang-format off
// Hand-written asm: waits while the first word of gMicrophoneCommand is 1. It keeps the address in ip, a register
// compiled C would not use for it.
asm void WaitMicrophoneIdle(void) {
    ldr ip, =gMicrophoneCommand
wait_loop:
    ldr r0, [ip]
    cmp r0, #0x1
    beq wait_loop
    bx lr
}
// clang-format on
