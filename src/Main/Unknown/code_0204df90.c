#include "Main/Unknown/code_0204df90.h"
#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_02009cc8.h"
#include "Main/Unknown/code_0200aeb4.h"
#include "Main/Unknown/code_0200b1b0.h"
#include "Main/Unknown/code_0200b200.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200b6e8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0204ea14.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200f5ac.h"

#pragma thumb on

void func_0204e928(void *a, u32 b, void *c) {
    u32 r;
    data_0217aa00->mUnk_1664 = a;
    r = GetScanConnectWorkSize();
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2 && r < 0xc000) {
        r = 0xc000;
    }
    data_0217aa00->mUnk_1660 = r;
    data_0217aa00->mUnk_165c = HeapAllocAligned(a, data_0217aa00->mUnk_1660, 0x20);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        data_0217aa00->mUnk_168c = func_02008880(NULL);
        if (data_0217aa00->mUnk_168c > 0x80000) {
            data_0217aa00->mUnk_168c = 0x80000;
        }
        data_0217aa00->mUnk_1658 = HeapAllocAligned(a, data_0217aa00->mUnk_168c, 0x20);
        func_0204ea14(c);
        data_0217aa00->mUnk_1668 = HeapAllocAligned(a, 0x4c0, 0x20);
    } else {
        data_0217aa00->mUnk_168c = 0;
        data_0217aa00->mUnk_1658 = 0;
        data_0217aa00->mUnk_1668 = 0;
    }
    func_0204e65c(&data_0217aa00->mUnk_1658_view);
}

void func_0204e6e8(u32 a, u32 b, Unk0204e4d8 *c) {
    data_0217aa00->mUnk_1658_view.mUnk_14[a] = b;
    if (data_0217aa00->mUnk_000c == 0x1b && b != 0xc) {
        return;
    }
    switch (b) {
        case 10: {
            u32 v = 1;
            if (data_0217aa00->mUnk_1694 & 1) {
                v = 0;
            } else if ((data_0217aa00->mUnk_008b & 4) && c->mUnk_00_4 == 0) {
                v = 0;
            }
            if (v != 0) {
                func_02007d50(a, 1);
            } else {
                func_02007d50(a, 0);
            }
            return;
        }
        case 7:
            data_0217aa00->mUnk_1697 |= 1 << a;
            if (data_0217aa00->mUnk_1696 == (data_0217aa00->mUnk_1696 & data_0217aa00->mUnk_1697)) {
                data_0217aa00->mRequestPending = 0;
            }
            break;
        case 9:
            data_0217aa00->mUnk_1695 |= 1 << a;
            break;
        case 12:
            data_0217aa00->mRequestPending = 0;
            break;
        case 1:
            data_0217aa00->mRequestPending = 0;
            break;
        case 3:
            if (data_0217aa00->mUnk_1695 & (1 << a)) {
                data_0217aa00->mUnk_1698 |= 1 << a;
                if (data_0217aa00->mUnk_1696 == (data_0217aa00->mUnk_1696 & data_0217aa00->mUnk_1698)) {
                    data_0217aa00->mRequestPending = 0;
                }
            }
            if (!(data_0217aa00->mUnk_1694 & 2)) {
                if (data_0217aa00->mUnk_1699 != 0) {
                    if (data_0217aa00->mUnk_1696 & (1 << a)) {
                        data_0217aa00->mUnk_1696 &= ~(1 << a);
                        data_0217aa00->mUnk_1699--;
                    }
                    if ((data_0217aa00->mUnk_1694 & 1) && data_0217aa00->mUnk_1696 == 0) {
                        func_02050e60(7);
                    }
                } else {
                    data_0217aa00->mUnk_1696 = 0;
                    data_0217aa00->mUnk_1698 = 0;
                    data_0217aa00->mUnk_1695 = 0;
                    data_0217aa00->mUnk_1699 = 0;
                }
            }
            if ((data_0217aa00->mUnk_1694 & 2) &&
                data_0217aa00->mUnk_1696 == (data_0217aa00->mUnk_1696 & data_0217aa00->mUnk_1698) &&
                data_0217aa00->mUnk_000c == 0x19) {
                data_0217aa00->mRequestPending = 0;
                return;
            }
            if ((data_0217aa00->mUnk_1694 & 1) &&
                data_0217aa00->mUnk_1696 == (data_0217aa00->mUnk_1696 & data_0217aa00->mUnk_1697) &&
                data_0217aa00->mUnk_000c == 0x18) {
                data_0217aa00->mRequestPending = 0;
                return;
            }
            break;
        case 14:
            if (!(data_0217aa00->mUnk_1696 & (1 << a))) {
                data_0217aa00->mUnk_1696 |= 1 << a;
                data_0217aa00->mUnk_1699++;
            }
            break;
    }
}

void func_0204e65c(Unk0217aa00_1658 *a) {
    s32 i;
    if (data_0217aa00->mUnk_165c != 0) {
        MI_CpuFill8(data_0217aa00->mUnk_165c, 0, data_0217aa00->mUnk_1660);
    }
    if (data_0217aa00->mUnk_1668 != 0) {
        MI_CpuFill8(data_0217aa00->mUnk_1668, 0, 0x4c0);
    }
    for (i = 0; i < 8; i++) {
        a->mUnk_14[i] = 0;
    }
    a->mUnk_3c = 0;
    a->mUnk_3d = 0;
    a->mUnk_3e = 0;
    a->mUnk_3f = 0;
    a->mUnk_40 = 0;
    a->mUnk_41 = 0;
    a->mUnk_38 = 0;
    a->mUnk_3a = 0;
    a->mUnk_42 = -1;
    a->mUnk_44 = 0;
}

void func_0204e568(void) {
    Unk0204e4d8 b;
    data_0217aa00->mUnk_000c = 0x16;
    data_0217aa00->mRequestPending = 1;
    func_0204e65c(&data_0217aa00->mUnk_1658_view);
    b.mUnk_01 = 10;
    b.mUnk_00_0 = data_021759d0->mUnk_40;
    b.mUnk_00_4 = 8;
    MI_CpuCopy8(data_0217aa08->mUnk_00->mUnk_0c, b.mUnk_02, 0x14);
    data_0217aa00->mUnk_1690 = func_02052c5c(1);
    if (InitWirelessWork(data_0217aa00->mUnk_165c, (Unk02009ff4 *) &b, 0x25, data_0217aa00->mUnk_1690, 2) != 0) {
        func_02050e60(5);
    }
    SetMPLimits(0x1fe, 7);
    SetCallback(func_0204e6e8);
    if (((s32(*)(u32)) func_02009cc8)(data_0217aa00->mUnk_0088) != 0) {
        func_02050e60(5);
    }
    if (func_0204ea3c() == 0) {
        func_02050e60(5);
    }
    data_0217aa00->mUnk_008b &= ~4;
    data_0217aa00->mRequestPending = 0;
}

void SetupScanConnect(void) {
    Unk0204e4d8 b;
    data_0217aa00->mUnk_000c = 0x1c;
    data_0217aa00->mRequestPending = 1;
    b.mUnk_00_0 = data_021759d0->mUnk_40;
    b.mUnk_01 = 10;
    b.mUnk_00_4 = 9;
    MI_CpuCopy8(data_0217aa08->mUnk_00->mUnk_0c, b.mUnk_02, 0x14);
    data_0217aa00->mUnk_169a = -1;
    InitScanConnectWork(data_0217aa00->mUnk_165c, &b);
    SetScanConnectStateCallback(ScanConnectStateCallback);
    data_0217aa00->mRequestPending = 0;
}

void StartCloseScanConnect(void) {
    data_0217aa00->mUnk_000c = 0x1f;
    data_0217aa00->mRequestPending = 1;
    CloseScanConnect();
}

void func_0204e498(void) {
    data_0217aa00->mUnk_000c = 0x1d;
    data_0217aa00->mRequestPending = 1;
    StartRepeatedScan(RepeatedScanCallback, 0x25);
}

static inline u32 func_0204e1a8_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

void func_0204e474(void) {
    data_0217aa00->mUnk_000c = 0x1e;
    data_0217aa00->mRequestPending = 1;
    StartRepeatedScan(RepeatedScanCallback, 0x25);
}

// Returns the scan entry index with bytes 4..9 matching the first six of element a of mUnk_00ac[0].mUnk_c0, or -1.
s32 FindScanEntryIndex(u32 a) {
    s32 r;
    u16 i;
    Unk0217aa00_24 b;
    r = -1;
    if (data_0217aa00->mUnk_000c == 0x1e) {
        for (i = 0; i < 16; i++) {
            if (func_0200b1b0(i, &b) != 0) {
                u8 *p = data_0217aa00->mUnk_00ac[0].mUnk_c0;
                u8 *q = p + a * 0xe0;
                if (b.mUnk_02[2] == p[a * 0xe0] && b.mUnk_02[3] == q[1] && b.mUnk_02[4] == q[2] &&
                    b.mUnk_02[5] == q[3] && b.mUnk_02[6] == q[4] && b.mUnk_02[7] == q[5]) {
                    r = (s8) i;
                    break;
                }
            }
        }
    }
    return r;
}

// Codes: 2 is an error, 3 the end of the scan; 0 and 1 carry a table entry and are ignored.
void RepeatedScanCallback(u32 a) {
    switch (a) {
        case 0:
        case 1:
            break;
        case 2:
            func_02050e60(5);
            break;
        case 3:
            data_0217aa00->mRequestPending = 0;
            break;
    }
}

void ScanConnectStateCallback(u32 a) {
    switch (a) {
        case 11:
            data_0217aa00->mRequestPending = 0;
            break;
        case 20:
            data_0217aa00->mUnk_1692 = (OS_GetTick() >> 10) % 40;
            data_0217aa00->mRequestPending = 0;
            break;
        case 7:
            data_0217aa00->mUnk_169c = 1;
            data_0217aa00->mUnk_0004 = 6;
            break;
        case 4:
            func_02050e60(5);
            break;
        case 3:
        case 6:
            data_0217aa00->mUnk_169c = 0;
            data_0217aa00->mRequestPending = 0;
            break;
    }
}

s32 func_0204e29c(void) {
    BOOL r = FALSE;
    switch (data_0217aa00->mUnk_000c) {
        case 0:
            data_0217aa00->mUnk_0454 |= 0x40;
            data_0217aa00->mUnk_0004 = 1;
            Initialize();
            break;
        case 1:
            MeasureChannel(r);
            break;
        case 4:
            func_0204f814();
            func_0204e568();
            break;
        case 0x16:
            func_0200104c();
            r = TRUE;
            break;
    }
    return r;
}

s32 func_0204e204(void) {
    BOOL s = FALSE;
    BOOL r = FALSE;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        switch (data_0217aa00->mUnk_000c) {
            case 0:
                data_0217aa00->mUnk_0454 |= 0x40;
                data_0217aa00->mUnk_0004 = 1;
                Initialize();
                break;
            case 1:
                s = TRUE;
                break;
        }
    } else {
        switch (data_0217aa00->mUnk_000c) {
            case 0:
                data_0217aa00->mUnk_0454 |= 0x40;
                data_0217aa00->mUnk_0004 = 1;
                Initialize();
                break;
            case 1:
                SetupScanConnect();
                break;
            case 0x1c:
                func_0204e498();
                s = TRUE;
                break;
        }
    }
    if (s != FALSE) {
        data_0217aa00->mUnk_0004 = 3;
        r = TRUE;
    }
    return r;
}

s32 func_0204e1a8(s32 a) {
    s32 r = 0;
    if (data_0217aa00->mRequestPending != 0) {
        return 0;
    }
    switch (func_0204e1a8_inline()) {
        case 1:
            r = func_0204e29c();
            break;
        case 2:
            r = func_0204e204();
            break;
        case 0:
            if (a != 0) {
                data_0217aa00->mUnk_0000 = 1;
            } else {
                data_0217aa00->mUnk_0000 = 2;
            }
            break;
    }
    return r;
}

void func_0204e128(void) {
    u8 i;
    u8 n;
    if (data_0217aa00->mUnk_1696 == 0) {
        func_02050e60(5);
        return;
    }
    data_0217aa00->mUnk_000c = 0x18;
    i = 1;
    data_0217aa00->mRequestPending = i;
    n = 0;
    data_0217aa00->mUnk_1697 = n;
    data_0217aa00->mUnk_1694 |= i;
    for (; i <= 15; i++) {
        if (func_02007d50(i, 2) == 1) {
            n++;
        }
    }
    if (n == 0) {
        data_0217aa00->mUnk_1694 &= ~1;
    }
}

void func_0204e0bc(void) {
    u8 i;
    u8 n;
    data_0217aa00->mUnk_000c = 0x19;
    i = 1;
    data_0217aa00->mRequestPending = i;
    data_0217aa00->mUnk_1694 |= 2;
    n = 0;
    data_0217aa00->mUnk_1695 = n;
    for (; i <= 15; i++) {
        if (func_02007d50(i, 3) == 1) {
            n++;
        }
    }
    if (n == 0) {
        data_0217aa00->mUnk_1694 &= ~2;
    }
}

void func_0204e090(void) {
    data_0217aa00->mUnk_000c = 0x1b;
    data_0217aa00->mRequestPending = 1;
    data_0217aa00->mUnk_1694 &= ~2;
    func_02009c04();
}

void StartRequestEndScan(void) {
    data_0217aa00->mUnk_000c = 0x21;
    data_0217aa00->mRequestPending = 1;
    RequestEndScan();
}

void func_0204e03c(u32 a) {
    data_0217aa00->mUnk_000c = 0x22;
    data_0217aa00->mRequestPending = 1;
    data_0217aa00->mUnk_169c = 0;
    if (StartConnectToEntry(a) == 0) {
        func_02050e60(5);
    }
}

void func_0204dfe0(u32 a) {
    u32 r;
    data_0217aa00->mUnk_000c = 0x23;
    data_0217aa00->mRequestPending = 1;
    r = func_0200b15c(a, (ScanBlock *) data_0217aa00->mUnk_0024, 0x1bc, 0x36, 0, 0);
    data_0217aa00->mRequestPending = 0;
    data_0217aa00->mUnk_0024->mUnk_48 = (data_0217aa00->mUnk_0024->mUnk_48 + 7) & 0x7fff;
    if (r == 0) {
        func_02050e60(5);
    }
}

void func_0204df90(void) {
    data_0217aa00->mUnk_000c = 0x1a;
    data_0217aa00->mRequestPending = 1;
    func_02007ec4((ScanBlock *) data_0217aa00->mUnk_0024, 0x1bc, 0x36, 0, 0);
    data_0217aa00->mUnk_0024->mUnk_48 = (data_0217aa00->mUnk_0024->mUnk_48 + 7) & 0x7fff;
    data_0217aa00->mRequestPending = 0;
}

#pragma thumb off
