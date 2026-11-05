#include "code_0214c778.h"
#include "code_0200fc8c.h"
#include "code_0200c914.h"
#include "Main/Unknown/code_0200f000.h"
#include "ITCM/code_01fff000.h"
#include "ITCM/code_01fff95c.h"

Unk0214ccd4 data_02180308;

// Runs f(arg) at once when c is 0. Otherwise waits until data_02180308.mUnk_00 is 0 and bits 24-26 of the word at
// 0x4000600 include bit 1, fills in data_02180308 (mUnk_00 = 1), saves the top two bits of that word and
// InterruptHandlerGet(0x200000), sets those bits to 1, installs GxFifoSendNextPiece with InterruptHandlerSet(0x200000,
// ...) and calls it.
void GxFifoSendWordsInPieces(u32 a, const void *b, u32 c, UnkFunc *f, u32 arg) {
    u32 s;
    vu32 *p;

    if (c == 0) {
        if (f != 0) {
            f(arg);
        }
        return;
    }
    while (data_02180308.mUnk_00 != 0) {
    }
    p = (vu32 *) 0x4000600;
    while ((((*p & 0x7000000) >> 0x18) & 2) == 0) {
    }
    data_02180308.mUnk_10 = f;
    data_02180308.mUnk_00 = 1;
    data_02180308.mUnk_04 = a;
    data_02180308.mUnk_08 = b;
    data_02180308.mUnk_0c = c;
    data_02180308.mUnk_14 = arg;
    CheckDma0SourceOrLoopForever(a, b, c, 0);
    MI_WaitDma(a);
    s = IrqDisable();
    data_02180308.mUnk_18 = (*(u32 *) 0x4000600 & 0xc0000000) >> 0x1e;
    data_02180308.mUnk_1c = InterruptHandlerGet(0x200000);
    *(u32 *) 0x4000600 = (*(u32 *) 0x4000600 & ~0xc0000000) | 0x40000000;
    InterruptHandlerSet(0x200000, GxFifoSendNextPiece);
    InterruptEnableSetBits(0x200000);
    GxFifoSendNextPiece();
    IrqRestore(s);
}

// Does nothing when data_02180308.mUnk_0c is 0. Otherwise takes n = min(mUnk_0c, 0x1d8), advances mUnk_08 by n and
// lowers mUnk_0c by n, and calls StartDmaTransfer with data_02180308.mUnk_04, the old mUnk_08, 0x4000400 and n >> 2
// under 0x84400000 (0xc4400000 and SetDmaDoneCallback(mUnk_04, GxFifoSendWordsInPiecesDone, 0) first when mUnk_0c
// reached 0), then InterruptFlagWrite(0x200000).
void GxFifoSendNextPiece(void) {
    const u8 *p;
    u32 n;

    n = data_02180308.mUnk_0c;
    if (n == 0) {
        return;
    }
    if (n >= 0x1d8) {
        n = 0x1d8;
    }
    p = data_02180308.mUnk_08;
    data_02180308.mUnk_0c = data_02180308.mUnk_0c - n;
    data_02180308.mUnk_08 = p + n;
    if (data_02180308.mUnk_0c == 0) {
        SetDmaDoneCallback(data_02180308.mUnk_04, GxFifoSendWordsInPiecesDone, 0);
        StartDmaTransfer(data_02180308.mUnk_04, p, (void *) 0x4000400, 0xc4400000 | (n >> 2));
        InterruptFlagWrite(0x200000);
        return;
    }
    StartDmaTransfer(data_02180308.mUnk_04, p, (void *) 0x4000400, 0x84400000 | (n >> 2));
    InterruptFlagWrite(0x200000);
}

// Restores the top two bits of the word at 0x4000600 from data_02180308.mUnk_18, passes mUnk_1c to InterruptHandlerSet,
// clears mUnk_00 and calls mUnk_10(mUnk_14) when mUnk_10 is not 0.
void GxFifoSendWordsInPiecesDone(void) {
    u32 v;

    InterruptEnableClearBits(0x200000);
    *(u32 *) 0x4000600 = (data_02180308.mUnk_18 << 0x1e) | (*(u32 *) 0x4000600 & ~0xc0000000);
    InterruptHandlerSet(0x200000, data_02180308.mUnk_1c);
    data_02180308.mUnk_00 = 0;
    v = data_02180308.mUnk_14;
    if (data_02180308.mUnk_10 != 0) {
        data_02180308.mUnk_10(v);
    }
}

// Runs f(arg) at once when c is 0. Otherwise waits until data_02180308.mUnk_00 is 0, sets mUnk_00 to 1, stores a, f and
// arg at mUnk_04, mUnk_10 and mUnk_14, calls CheckDmaTimingConflictOrLoopForever(a, 0x38000000),
// CheckDma0SourceOrLoopForever(a, b, c, 0) and MI_WaitDma(a), and installs GxFifoSendWordsDone with
// SetDmaDoneCallback(a, ..., 0) before calling StartDmaTransfer with 0x4000400 as destination.
void GxFifoSendWords(u32 a, const void *b, u32 c, UnkFunc *f, u32 arg) {
    if (c == 0) {
        if (f != 0) {
            f(arg);
        }
        return;
    }
    while (data_02180308.mUnk_00 != 0) {
    }
    data_02180308.mUnk_00 = 1;
    data_02180308.mUnk_04 = a;
    data_02180308.mUnk_10 = f;
    data_02180308.mUnk_14 = arg;
    CheckDmaTimingConflictOrLoopForever(a, 0x38000000);
    CheckDma0SourceOrLoopForever(a, b, c, 0);
    MI_WaitDma(a);
    SetDmaDoneCallback(a, GxFifoSendWordsDone, 0);
    StartDmaTransfer(a, b, (void *) 0x4000400, 0xfc400000 | (c >> 2));
}

// Clears data_02180308.mUnk_00 and calls mUnk_10(mUnk_14) when mUnk_10 is not 0.
void GxFifoSendWordsDone(void) {
    u32 v;

    data_02180308.mUnk_00 = 0;
    v = data_02180308.mUnk_14;
    if (data_02180308.mUnk_10 != 0) {
        data_02180308.mUnk_10(v);
    }
}

void MI_DmaFill32(u32 a, void *b, u32 c, u32 d) {
    u32 s;

    if (d == 0) {
        return;
    }
    while (*(vu32 *) (0x40000b0 + (a * 3 + 2) * 4) & 0x80000000) {
    }
    s = IrqDisable();
    *(vu32 *) (0x4000000 + a * 4 + 0xe0) = c;
    StartDmaTransferAndChannel0DummyWithoutIrqDisable(a, (const void *) (0x40000e0 + a * 4), b, (d >> 2) | 0x85000000);
    IrqRestore(s);
    while (*(vu32 *) (0x40000b0 + (a * 3 + 2) * 4) & 0x80000000) {
    }
}

void MI_DmaCopy32(u32 a, const void *b, void *c, u32 d) {
    CheckDma0SourceOrLoopForever(a, b, d, 0);
    if (d == 0) {
        return;
    }
    while (*(vu32 *) (0x40000b0 + (a * 3 + 2) * 4) & 0x80000000) {
    }
    StartDmaTransferAndChannel0Dummy(a, b, c, (d >> 2) | 0x84000000);
    while (*(vu32 *) (0x40000b0 + (a * 3 + 2) * 4) & 0x80000000) {
    }
}

void MI_DmaCopy16(u32 a, const void *b, void *c, u32 d) {
    if (d == 0) {
        return;
    }
    CheckDma0SourceOrLoopForever(a, b, d, 0);
    while (*(vu32 *) (0x40000b0 + (a * 3 + 2) * 4) & 0x80000000) {
    }
    StartDmaTransferAndChannel0Dummy(a, b, c, (d >> 1) | 0x80000000);
    while (*(vu32 *) (0x40000b0 + (a * 3 + 2) * 4) & 0x80000000) {
    }
}

void MI_DmaFill32Async(u32 a, void *b, u32 c, u32 d, UnkFunc *f, u32 arg) {
    u32 s;

    if (d == 0) {
        if (f != 0) {
            f(arg);
        }
        return;
    }
    MI_WaitDma(a);
    if (f != 0) {
        SetDmaDoneCallback(a, f, arg);
        s = IrqDisable();
        *(vu32 *) (0x4000000 + a * 4 + 0xe0) = c;
        StartDmaTransferWithoutIrqDisable(a, (const void *) (0x40000e0 + a * 4), b, (d >> 2) | 0xc5000000);
        IrqRestore(s);
    } else {
        s = IrqDisable();
        *(vu32 *) (0x4000000 + a * 4 + 0xe0) = c;
        StartDmaTransferWithoutIrqDisable(a, (const void *) (0x40000e0 + a * 4), b, (d >> 2) | 0x85000000);
        IrqRestore(s);
    }
}

void MI_DmaCopy32Async(u32 a, const void *b, void *c, u32 d, UnkFunc *f, u32 arg) {
    CheckDma0SourceOrLoopForever(a, b, d, 0);
    if (d == 0) {
        if (f != 0) {
            f(arg);
        }
        return;
    }
    MI_WaitDma(a);
    if (f != 0) {
        SetDmaDoneCallback(a, f, arg);
        StartDmaTransfer(a, b, c, (d >> 2) | 0xc4000000);
    } else {
        StartDmaTransfer(a, b, c, (d >> 2) | 0x84000000);
    }
}

void MI_WaitDma(u32 a) {
    u32 s;
    vu32 *d;

    s = IrqDisable();
    while (*(vu32 *) (0x40000b0 + (a * 3 + 2) * 4) & 0x80000000) {
    }
    if (a == 0) {
        *(vu32 *) (0x4000000 + a * 12 + 0xb0) = 0;
        d = (vu32 *) (0x40000b0 + a * 12);
        d[1] = 0;
        d[2] = 0x81400001;
    }
    IrqRestore(s);
}

void MI_StopDma(u32 a) {
    u32 s;
    vu32 *d;

    s = IrqDisable();
    *(vu16 *) (0x4000000 + (a * 6 + 5) * 2 + 0xb0) &= ~0x3a00;
    *(vu16 *) (0x4000000 + (a * 6 + 5) * 2 + 0xb0) &= ~0x8000;
    *(vu16 *) (0x4000000 + (a * 6 + 5) * 2 + 0xb0);
    *(vu16 *) (0x4000000 + (a * 6 + 5) * 2 + 0xb0);
    if (a == 0) {
        *(vu32 *) (0x4000000 + a * 12 + 0xb0) = 0;
        d = (vu32 *) (0x40000b0 + a * 12);
        d[1] = 0;
        d[2] = 0x81400001;
    }
    IrqRestore(s);
}

void CheckDmaTimingConflictOrLoopForever(u32 a, u32 b) {
    s32 i;
    u32 *p;
    u32 v;
    u32 w;

    p = (u32 *) 0x40000b8;
    for (i = 0; i < 3; i++, p += 3) {
        if (i == a) {
            continue;
        }
        w = *p;
        if ((w & 0x80000000) == 0) {
            continue;
        }
        v = w & 0x38000000;
        if (v == b) {
            continue;
        }
        if (v == 0x8000000 && b == 0x10000000) {
            continue;
        }
        if (v == 0x10000000 && b == 0x8000000) {
            continue;
        }
        if (v == 0x18000000 || v == 0x20000000 || v == 0x28000000 || v == 0x30000000 || v == 0x38000000 ||
            v == 0x8000000 || v == 0x10000000) {
            IrqDisableLoopForever();
        }
    }
}

void CheckDma0SourceOrLoopForever(u32 a, const void *b, u32 c, u32 d) {
    u32 x;
    u32 y;

    if (a != 0) {
        return;
    }
    x = (u32) b;
    y = x & 0xff000000;
    if (d != 0) {
        if (d == 0x800000) {
            x = x - c;
        }
    } else {
        x = x + c;
    }
    if (y == 0x4000000 || y >= 0x8000000 || (x & 0xff000000) == 0x4000000 || (x & 0xff000000) >= 0x8000000) {
        IrqDisableLoopForever();
    }
}
