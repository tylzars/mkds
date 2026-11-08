#include "Main/Unknown/code_02057fe4.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_020562b4.h"
#include "Main/Unknown/code_02056464.h"
#include "Main/Unknown/code_02058000.h"
#include "Main/Unknown/code_02058b38.h"
#include "Main/Unknown/code_02058efc.h"
#include "Main/Unknown/code_02059000.h"

#include "Main/Unknown/code_02050000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02051000.h"
#include "Main/Unknown/code_02052000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02175000.h"
#include "code_0200eddc.h"
#include "code_02142eac.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02059920.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204bca0.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_02050034.h"
#include "Main/Unknown/code_0205928c.h"

#pragma thumb on

void func_02058b10(void) {
    MPStateMachine *v1;
    CombineParticipantBits();
    v1 = &data_0217aa00->mUnk_1608;
    v1->mNextState = 0xf;
    v1->mNextStateRequested = 1;
}

#pragma thumb off

#pragma thumb on

static inline u32 func_02058a40_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

void UpdateMPState5(void) {
    u8 v;
    u16 w;

    if (func_02058a40_inline() == 1) {
        v = data_0217aa00->mParticipantMask;
        if (IsAllMPChildSharedDataCopied() != 0) {
            if (QueueMPDataHalfwordAndWord(1, v, v) != FALSE) {
                SetParticipantMask(v);
            }
        } else {
            w = data_0217aa00->mUnk_1608.mUnk_14;
            if (w > 0xe10) {
                func_02050e60(7);
                return;
            }
            data_0217aa00->mUnk_1608.mUnk_14 = w + 1;
        }
    }
}

void UpdateMPState6(void) {
    MPStateMachine *p;

    if (func_02058a40_inline() == 1 && (data_0217aa00->mUnk_0454 & 1)) {
        if (QueueMPDataHalfwordAndWord(2, data_0217aa00->mUnk_0044.mChildMask, data_0217aa00->mUnk_0457) != FALSE) {
            p = &data_0217aa00->mUnk_1608;
            p->mNextState = 1;
            p->mNextStateRequested = 1;
        }
    }
}

void EnterMPState3(void) {
    data_0217aa00->mUnk_1e34 = 0;
    data_0217aa00->mUnk_1e44 &= ~2;
}

#pragma thumb off

#pragma thumb on

void UpdateMPState3(void) {
    int v1;
    MPStateMachine *v2;
    v1 = func_0205955c();
    if (v1 == 1) {
        v2 = &data_0217aa00->mUnk_1608;
        v2->mNextState = 4;
        v2->mNextStateRequested = 1;
    }
}

#pragma thumb off

#pragma thumb on

static inline void func_02058910_inline(u16 v) {
    MPStateMachine *p = &data_0217aa00->mUnk_1608;
    p->mNextState = v;
    p->mNextStateRequested = 1;
}

void UpdateMPState1(void) {
    BOOL r;
    BOOL a;
    BOOL b;
    s32 v;
    ConnectionWork *p;

    r = TRUE;
    b = FALSE;
    p = data_0217aa00;
    if (p->mUnk_0454 & 0x40) {
        a = TRUE;
        if (p == NULL) {
            v = 0;
        } else {
            v = p->mUnk_0000;
        }
        if (v != 1 && ((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
            a = FALSE;
        }
        if (a != FALSE) {
            b = TRUE;
        }
    }
    if (b != FALSE) {
        if (GetRomArchiveState() == 2) {
            func_0204f8a0(data_0217aa00->mUnk_0457);
        } else {
            r = FALSE;
        }
    }
    if (r != FALSE) {
        func_02058910_inline(2);
    }
}

void EnterMPState2(void) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        StartLoadOverlay(2);
    }
}

void UpdateMPState2(void) {
    if (TryFinishOverlayLoad() != 0) {
        if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
            CreateOverlayFrmHeap();
            func_020474e4();
        }
        func_02058910_inline(3);
    }
}

void EnterMPState4(void) {
    data_0217aa00->mUnk_1e34 = 0;
    data_0217aa00->mUnk_1e44 &= ~2;
    data_0217aa00->mUnk_164f = 0;
}

#pragma thumb off

#pragma thumb on

void UpdateMPState4(void) {
    int v1;
    MPStateMachine *p;
    v1 = func_02058dc0(func_02058efc);
    if (v1 == 1) {
        p = &data_0217aa00->mUnk_1608;
        p->mNextState = 0xc;
        p->mNextStateRequested = 1;
    }
}

#pragma thumb off

#pragma thumb on

static inline u32 func_02058820_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline void func_020587d8_inline(u16 v) {
    MPStateMachine *p = &data_0217aa00->mUnk_1608;
    p->mNextState = v;
    p->mNextStateRequested = 1;
}

// Clears the per-slot flags of received chunks: 0x12 per slot for the parent, 2 for a child.
void EnterMPState7(void) {
    s32 i;
    u32 j;
    u32 n;

    WM_SetPortCallback(14, (UnkFunc *) func_02059920, NULL);
    if (func_02058820_inline() == 1) {
        SetMPFrequency(0);
    }
    for (i = 0; i < 8; i++) {
        if (func_02058820_inline() == 1) {
            n = 0x12;
        } else {
            n = 2;
        }
        for (j = 0; j < n; j++) {
            data_0217aa00->mChunkReceivedFlags[i][j] = 0;
        }
    }
    data_0217aa00->mUnk_162a = 0;
}

void UpdateMPState7(void) {
    if (data_0217aa00->mRequestPending == 0) {
        switch (data_0217aa00->mUnk_000c) {
            case 0xc:
                data_0217aa00->mUnk_000c = 0xb;
                break;
            case 0xb:
                func_020587d8_inline(8);
                break;
            default:
                func_02050e60(2);
                break;
        }
    }
}

void EnterMPState8(void) {
    u16 v;

    v = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mOwnIndex : 0;
    FillPlayerRecord(&data_0217aa00->mUnk_045c[v]);
    data_0217aa00->mUnk_1608.mUnk_1a |= 1;
    data_0217aa00->mEntryChunkIndex = 0;
    data_0217aa00->mUnk_1608.mUnk_16 = 0;
}

#pragma thumb off

#pragma thumb on
u32 func_02058754(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value0 = (u32) &data_0217aa00;
    value1 = *(const u32 *) ((value0) + 0u);
    value0 = 0x1622u;
    value1 = (value1) + (value0);
    value2 = *(const u8 *) ((value1) + 0u);
    value0 = 1u;
    value2 = (value2) | (value0);
    *(u8 *) ((value1) + 0u) = value2;
    return value0;
}
#pragma thumb off

#pragma thumb on

static inline u32 func_0205821c_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline void func_0205821c_inline2(u16 v) {
    MPStateMachine *p = &data_0217aa00->mUnk_1608;
    p->mNextState = v;
    p->mNextStateRequested = 1;
}

BOOL QueueMPChunk(u8 a, u8 *b, u16 c, u8 d, u8 e) {
    u8 *q;

    if ((data_0217aa00->mUnk_1608.mUnk_1a & 1) == 0) {
        return FALSE;
    }
    q = data_0217aa00->mChunkBuffer;
    q[1] = a;
    *(u16 *) (q + 2) = c;
    q[0] = d;
    if (b != NULL) {
        MI_CpuCopy8(b, q + 4, c);
    } else {
        c = 0;
    }
    DC_StoreRange(q, c + 4);
    data_0217aa00->mUnk_1608.mUnk_1a &= ~1;
    if (QueueMPDataToPort(data_0217aa00->mChunkBuffer, c + 4, e, NULL, &data_021652a0) == 0) {
        data_0217aa00->mUnk_1608.mUnk_1a |= 1;
        return FALSE;
    }
    return TRUE;
}

BOOL GetEntryChunk(u8 *entry, s32 chunkIndex, s32 chunkSize, u8 **outChunk, u16 *outSize) {
    s32 n;

    chunkIndex = chunkIndex * chunkSize;
    n = 0x22c - chunkIndex;
    if (n <= 0) {
        return FALSE;
    }
    if (n > chunkSize) {
        n = chunkSize;
    }
    *outSize = n;
    *outChunk = entry + chunkIndex;
    return TRUE;
}

// Child: queues its own entry chunk by chunk, again and again. Parent: waits for the children's entries.
void UpdateMPState8(void) {
    ConnectionWork *p;
    u32 a;
    u8 b;
    u8 c;
    u8 *d;
    u16 v1;
    u16 v;

    if (func_0205821c_inline() == 1) {
        p = data_0217aa00;
        a = p->mUnk_0044.mUnk_42;
        b = p->mUnk_162a;
        if (a == (a & b)) {
            if (QueueMPChunk(0xfe, NULL, (u8) (b | 1), 0, b) != FALSE) {
                func_0205821c_inline2(9);
            }
        } else {
            if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
                v = 0x708;
            } else {
                v = 0x258;
            }
            data_0217aa00->mUnk_1608.mUnk_16++;
            if (data_0217aa00->mUnk_1608.mUnk_16 > v) {
                data_0217aa00->mUnk_0044.mUnk_42 = data_0217aa00->mUnk_0044.mChildMask;
            }
        }
    } else {
        if ((data_0217aa00->mUnk_1608.mUnk_1a & 1) != 0) {
            c = data_0217aa00->mEntryChunkIndex;
            v = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mOwnIndex : 0;
            if (GetEntryChunk((u8 *) &data_0217aa00->mUnk_045c[v], c, 0x20, &d, &v1) != FALSE) {
                v = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mOwnIndex : 0;
                QueueMPChunk(c, d, v1, v, 1);
                data_0217aa00->mEntryChunkIndex = c + 1;
            } else {
                data_0217aa00->mEntryChunkIndex = 0;
            }
        }
    }
}

void EnterMPState9(void) {
    data_0217aa00->mUnk_0004 = 10;
    data_0217aa00->mUnk_1608.mUnk_16 = 0;
    data_0217aa00->mUnk_162a = 0;
    data_0217aa00->mEntryChunkIndex = 0;
    data_0217aa00->mEntryChunkSlot = 0;
}

// Parent: queues the entries of all slots to the children, chunk by chunk, until the wait ends.
void UpdateMPState9(void) {
    u32 f;
    u8 a;
    u8 b;
    u8 *d;
    u16 v1;
    u16 v;

    if (func_0205821c_inline() == 1) {
        if ((data_0217aa00->mUnk_1608.mUnk_1a & 1) != 0) {
            f = 1;
            b = data_0217aa00->mEntryChunkSlot;
            if (((u8) (data_0217aa00->mUnk_0044.mChildMask | 1) & (1 << b)) != 0) {
                a = data_0217aa00->mEntryChunkIndex;
                if (GetEntryChunk((u8 *) &data_0217aa00->mUnk_045c[b], a, 0x168, &d, &v1) != FALSE) {
                    QueueMPChunk(a, d, v1, b, data_0217aa00->mUnk_0044.mChildMask);
                    data_0217aa00->mEntryChunkIndex = a + 1;
                    f = 0;
                }
            }
            if (f != 0) {
                data_0217aa00->mEntryChunkSlot++;
                data_0217aa00->mEntryChunkIndex = 0;
                if (data_0217aa00->mEntryChunkSlot >= 8) {
                    data_0217aa00->mEntryChunkSlot = 0;
                }
            }
        }
        if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
            v = 0x708;
        } else {
            v = 0x258;
        }
        data_0217aa00->mUnk_1608.mUnk_16++;
        if (data_0217aa00->mUnk_1608.mUnk_16 > v) {
            data_0217aa00->mUnk_162a = data_0217aa00->mUnk_0044.mChildMask;
            func_0205821c_inline2(10);
        }
    }
}

void EnterMPState10(void) {
    u8 i;

    WM_SetPortCallback(14, NULL, NULL);
    data_0217aa00->mUnk_043c = data_0217aa00->mUnk_045c[0].mUnk_228_4;
    if (*(u16 *) 0x027ffc40 == 2) {
        data_021759d0->mLanguageIndex = data_0217aa00->mUnk_043c;
    }
    for (i = 1; i < 8; i++) {
        if ((data_0217aa00->mUnk_162a & (1 << i)) == 0) {
            MI_CpuFill8(&data_0217aa00->mUnk_045c[i], 0, 0x22c);
        }
    }
}

void UpdateMPState10(void) {
    if (data_0217aa00->mRequestPending == 0) {
        switch (data_0217aa00->mUnk_000c) {
            case 0xb:
                func_02052da4();
                break;
            case 0x25:
                func_0205821c_inline2(6);
                break;
        }
    }
}

void EnterMPState11(void) {
    data_0217aa00->mUnk_164e = 0;
    data_0217aa00->mUnk_164c = 0;
}

void UpdateMPState11(void) {
    u8 a;
    u8 b;
    u32 c;

    switch (func_0205821c_inline()) {
        case 1:
            a = data_0217aa00->mUnk_164e;
            b = data_0217aa00->mUnk_162a;
            c = b & (1 << a);
            if (c != 0) {
                if (func_020504a4(a, b) != FALSE) {
                    data_0217aa00->mUnk_164e++;
                }
            } else {
                data_0217aa00->mUnk_164e++;
            }
            if (data_0217aa00->mUnk_164e >= 8) {
                func_0205821c_inline2(6);
            }
            break;
        case 2:
            a = data_0217aa00->mUnk_162a;
            b = data_0217aa00->mUnk_164c;
            if (a == (a & b)) {
                func_0205821c_inline2(6);
            }
            break;
    }
}

#pragma thumb off

#pragma thumb on

void EnterMPState12(void) {
    int v1;
    if (data_0217aa00 == NULL) {
        v1 = 0;
    } else {
        v1 = data_0217aa00->mUnk_0000;
    }
    if (v1 == 1) {
        SetMPFrequency(1);
    }
}

#pragma thumb off

#pragma thumb on

static inline u32 func_020580a4_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline void func_020580a4_inline2(u16 v) {
    MPStateMachine *p = &data_0217aa00->mUnk_1608;
    p->mNextState = v;
    p->mNextStateRequested = 1;
}

void UpdateMPState12(void) {
    if (data_0217aa00->mRequestPending != 0) {
        return;
    }
    switch (data_0217aa00->mUnk_000c) {
        case 0xc:
        case 0x25:
        case 0x27:
            StartDataSharing();
            break;
        case 0xe:
            data_0217aa00->mUnk_0004 = 7;
            func_020580a4_inline2(5);
            break;
    }
}

void EnterMPState13(void) {
    s32 i;

    data_0217aa00->mUnk_164d = 0;
    i = 0;
    if (data_0217aa00->mUnk_0000 == 2) {
        i = data_0217aa00->mOwnIndex;
    }
    MI_CpuCopy8(data_0217aa08->mUnk_00->mUnk_20, data_0217aa00->mUnk_045c[(u16) i].mBits, 4);
    data_0217aa00->mUnk_162a |= 1;
}

void UpdateMPState13(void) {
    s32 v;

    if (func_020580a4_inline() == 1) {
        if (data_0217aa00->mUnk_0044.mChildMask == (data_0217aa00->mUnk_0044.mChildMask & data_0217aa00->mUnk_164d)) {
            func_020580a4_inline2(0xe);
        }
    } else if (data_0217aa00->mUnk_164d != 0) {
        func_020580a4_inline2(0xe);
    } else {
        if (data_0217aa00->mUnk_0000 == 2) {
            v = data_0217aa00->mOwnIndex;
        } else {
            v = 0;
        }
        func_020503cc((u8) (u16) v, 1);
    }
}
#pragma thumb off

#pragma thumb on
u32 EnterMPState14(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value2 = 0u;
    value0 = (u32) &data_0217aa00;
    value1 = *(const u32 *) ((value0) + 0u);
    value0 = 0x164eu;
    *(u8 *) ((value1) + (value0)) = value2;
    return value0;
}
#pragma thumb off

#pragma thumb on

static inline u32 func_02057fe8_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline void func_02057fe8_inline2(u16 v) {
    MPStateMachine *p = &data_0217aa00->mUnk_1608;
    p->mNextState = v;
    p->mNextStateRequested = 1;
}

void UpdateMPState14(void) {
    if (func_02057fe8_inline() == 1) {
        if ((data_0217aa00->mUnk_162a & (1 << data_0217aa00->mUnk_164e)) != 0) {
            if (func_020503cc(data_0217aa00->mUnk_164e, data_0217aa00->mUnk_0044.mChildMask) != FALSE) {
                data_0217aa00->mUnk_164e += 1;
            }
        } else {
            data_0217aa00->mUnk_164e += 1;
        }
        if (data_0217aa00->mUnk_164e > 8) {
            func_02057fe8_inline2(0xb);
        }
    } else if (data_0217aa00->mUnk_162a == (data_0217aa00->mUnk_162a & data_0217aa00->mUnk_164d)) {
        func_02057fe8_inline2(0xb);
    }
}
#pragma thumb off

#pragma thumb on

u32 func_02057fe4(u32 p0) {
    return p0;
}

#pragma thumb off
