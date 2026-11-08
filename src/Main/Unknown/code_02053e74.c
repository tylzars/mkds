#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0204f240.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_02052000.h"
#include "Main/Unknown/code_02053000.h"
#include "Main/Unknown/code_02054000.h"
#include "Main/Unknown/code_02054f38.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_020562b4.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_020176c0.h"
#include "code_0214d018.h"

#pragma opt_rebuildconditionals off

static inline u32 func_02053e74_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline s32 func_02053e74_inline2(void) {
    BOOL r = FALSE;
    if (func_02053e74_inline() != 0 && data_0217aa00->mUnk_0004 != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02053e74_inline3(void) {
    BOOL r = FALSE;
    if (func_02053e74_inline2() && !(data_0217aa00->mUnk_0454 & 0x80)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02053e74_inline4(void) {
    BOOL r = FALSE;
    if (func_02053e74_inline3() && data_0217aa00->mUnk_0008 != 9) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02054754_inline(Unk0217aa00_15c8 *e) {
    BOOL r = FALSE;
    u8 f = e->mUnk_06_0;
    if (data_0217aa00->mUnk_15ec == 0) {
        if (f & 1) {
            r = TRUE;
        }
    } else {
        if (f & 2) {
            r = TRUE;
        }
    }
    return r;
}

static inline s32 func_02054754_inline2(DataSharing *dataSharing, Unk0217aa00_15c8 *e) {
    u8 mask = data_0217aa00->mUnk_0044.mChildMask;
    u8 i;
    BOOL ok = FALSE;
    u16 m;

    for (i = 1; i < 8; i++) {
        if (mask & (1 << i)) {
            if (dataSharing->mSharedDataCopied[i] == 0) {
                ok = FALSE;
                i = 8;
            } else {
                m = data_0217aa00->mUnk_15ec == 0 ? 1 : 2;
                if ((m & e[i].mUnk_06_0) == 0) {
                    ok = FALSE;
                    i = 8;
                } else {
                    ok = TRUE;
                }
            }
        }
    }
    return ok;
}

static inline u32 func_0205465c_inline(ConnectionWork *p) {
    if (p == NULL) {
        return 0;
    }
    return p->mUnk_0000;
}

// Returns 1 once the last step is issued, 2 on failure, 3 when an error has been recorded, 0 otherwise.
s32 AdvanceConnectionSetup(s32 isParent, void *b) {
    BOOL finished;

    finished = FALSE;
    if (data_0217aa00->mUnk_1e3c != 0) {
        u16 ownIndex;

        ownIndex = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mOwnIndex : 0;
        if (ownIndex == 0xffff) {
            return 2;
        }
    }
    if (func_02053e74_inline4()) {
        return 3;
    }
    if (data_0217aa00->mRequestPending != 0) {
        return 0;
    }
    switch (data_0217aa00->mUnk_000c) {
        case 0:
        case 21:
            data_0217aa00->mUnk_0454 &= ~0x40;
            data_0217aa00->mUnk_0004 = 1;
            Initialize();
            break;
        case 1:
            data_0217aa00->mUnk_0004 = 11;
            if (isParent != 0) {
                SetLifeTime(0x28);
            } else {
                StartScan(0, NULL, NULL);
            }
            break;
        case 2:
            if (isParent != 0) {
                SetLifeTime(0x28);
            } else {
                StartScan(0, NULL, NULL);
            }
            break;
        case 3:
            MeasureChannel(0);
            break;
        case 4:
            func_0204f814();
            FillGhostParentParameter(b);
            SetParentParameter();
            break;
        case 5:
            StartParent(NULL);
            break;
        case 6:
            func_0204ef1c();
            break;
        case 7:
            if (data_0217aa00->mUnk_1e45 == -1) {
                StartScan(0, NULL, NULL);
            } else {
                EndScan();
            }
            break;
        case 9:
            StartConnect(NULL, NULL, NULL, NULL, ResetOwnIndex);
            break;
        case 10:
            data_0217aa00->mUnk_1e3c = 1;
            func_0204ef1c();
            break;
        case 11:
            if (isParent != 0) {
                StartParentSideBlockTransfer();
            } else {
                StartChildSideBlockTransfer();
                SetOwnIndexFromConnection();
            }
            finished = TRUE;
            break;
        default:
            func_020533a0();
            break;
    }
    return finished;
}

// Child side; returns 1 when done, 2 on failure, 3 when an error has been recorded, 0 otherwise (the parent returns 1
// at once).
s32 AdvanceBlockCountRequest(void) {
    BOOL finished;

    finished = FALSE;
    if (func_02053e74_inline4()) {
        return 3;
    }
    if (data_0217aa00->mUnk_1e3c != 0) {
        u16 ownIndex;

        ownIndex = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mOwnIndex : 0;
        if (ownIndex == 0xffff) {
            return 2;
        }
    }
    if (data_0217aa00->mRequestPending != 0) {
        return 0;
    }
    if (func_02053e74_inline() == 1) {
        return 1;
    }
    switch (data_0217aa00->mUnk_000c) {
        case 0x28:
        case 0x29:
            StartBlockCountRequest();
            break;
        case 0x2a:
            switch (func_02053e74_inline()) {
                case 1:
                    data_0217aa00->mUnk_000c = 0x28;
                    break;
                case 2:
                    data_0217aa00->mUnk_000c = 0x29;
                    break;
            }
            finished = TRUE;
            break;
    }
    return finished;
}

void func_02054aa0(void) {
    s32 c0;
    s32 c1;

    if (data_0217aa00->mUnk_0004 != 11) {
        return;
    }
    if (data_0217aa00->mUnk_000c == 0x2c) {
        TryGetBlockReceiveProgress(data_0217aa00->mBlockInfos[0]->mBlockId, 0, &c0, &c1);
    }
    if (data_0217aa00->mSendTimer != 0) {
        data_0217aa00->mSendTimer = data_0217aa00->mSendTimer - 1;
        return;
    }
    if (func_02053e74_inline() == 0) {
        return;
    }
    func_0204ed84();
}

// Child side; returns 1 when done, 2 on failure, 3 when an error has been recorded, 0 otherwise (the parent returns 1
// at once).
s32 AdvanceBlockReceive(void) {
    BOOL finished;

    finished = FALSE;
    if (func_02053e74_inline4()) {
        return 3;
    }
    if (data_0217aa00->mUnk_1e3c != 0) {
        u16 ownIndex;

        ownIndex = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mOwnIndex : 0;
        if (ownIndex == 0xffff) {
            return 2;
        }
    }
    if (data_0217aa00->mRequestPending != 0) {
        return 0;
    }
    if (func_02053e74_inline() == 1) {
        return 1;
    }
    switch (data_0217aa00->mUnk_000c) {
        case 0x28:
        case 0x29:
        case 0x2a:
            data_0217aa00->mBlockIndex = 0;
            StartBlockNodeRequest();
            break;
        case 0x2b:
            StartBlockDataRequest();
            break;
        case 0x2c:
            func_0204ead0(1, 0);
            break;
        case 0x2e:
            data_0217aa00->mUnk_1e3c = 0;
            finished = TRUE;
            break;
    }
    return finished;
}

// Polled until it returns TRUE.
BOOL FinishDataSharingSync(void) {
    BOOL finished;
    DataSharing *dataSharing;

    finished = FALSE;
    dataSharing = &data_0217aa00->mUnk_15bc_view;
    if (!func_02053e74_inline2()) {
        return TRUE;
    }
    if (!(data_0217aa00->mUnk_0454 & 4)) {
        return TRUE;
    }
    if (func_0204ffbc() != 0) {
        return TRUE;
    }
    if (dataSharing->mSharedDataCopied[0] != 0) {
        ConnectionWork *connection;

        connection = data_0217aa00;
        if (func_02054754_inline(dataSharing->mUnk_0c) != 0) {
            if ((connection->mUnk_0454 & 8) != 0) {
                connection->mUnk_0004 = 9;
            } else {
                connection->mUnk_0004 = 8;
            }
            finished = TRUE;
            data_0217aa00->mUnk_15f4 = 0;
        } else if (func_02053e74_inline() == 1) {
            if (func_02054754_inline2(dataSharing, dataSharing->mUnk_0c) != 0) {
                connection->mUnk_008b |= 1;
            }
        }
    }
    return finished;
}

// Starts the wait that FinishDataSharingSync completes; always returns 1.
s32 StartDataSharingSync(void) {
    if (func_02053e74_inline2()) {
        data_0217aa00->mUnk_0004 = 7;
        data_0217aa00->mUnk_008b &= ~1;
        if (data_0217aa00->mUnk_15ec == 0) {
            data_0217aa00->mUnk_15ec = 1;
        } else {
            data_0217aa00->mUnk_15ec = 0;
        }
    }
    return 1;
}

s32 func_0205465c(void) {
    ConnectionWork *connection;
    s32 r;
    s32 count;

    r = 0;
    connection = data_0217aa00;
    if (func_0205465c_inline(connection) != 1) {
        r = 2;
    } else {
        if (func_0205465c_inline(connection) == 1) {
            if ((connection->mUnk_0454 & 0x40) != 0) {
                count = connection->mUnk_1699;
            } else {
                count = connection->mUnk_0044.mChildCount;
            }
        } else {
            count = 0;
        }
        if (count == 0) {
            if (connection->mUnk_1e38 != 0) {
                r = 1;
            } else {
                r = 2;
            }
        }
    }
    return r;
}

void InitConnection(void *heap) {
    data_0217aa00 = HeapAllocAligned(heap, 0x1f00, 0x20);
    data_0217aa00->mUnk_0000 = 0;
    data_0217aa00->mUnk_0004 = 0;
    data_0217aa00->mUnk_0008 = 9;
    data_0217aa00->mUnk_000c = 0;
    data_0217aa00->mRequestPending = 0;
    data_0217aa00->mUnk_0454 = 0;
    data_0217aa00->mUnk_0456_0 = 0;
}

void InitConnectionBuffers(void *heap) {
    data_0217aa00->mUnk_0014 = HeapAllocAligned(heap, 0xf00, 0x20);
    data_0217aa00->mParentParameter = HeapAllocAligned(heap, 0x40, 0x20);
    data_0217aa00->mUnk_001c = HeapAllocAligned(heap, 0x20, 0x20);
    data_0217aa00->mUnk_0024 = HeapAllocAligned(heap, 0xc0, 0x20);
    data_0217aa00->mUnk_0028 = HeapAllocAligned(heap, 0xc0, 0x20);
    data_0217aa00->mUnk_0020 = HeapAllocAligned(heap, 0x44, 0x20);
    data_0217aa00->mUnk_002c = HeapAllocAligned(heap, 0x400, 0x20);
    data_0217aa00->mUnk_0030 = 0x1c0;
    data_0217aa00->mUnk_0034 = HeapAllocAligned(heap, data_0217aa00->mUnk_0030, 0x20);
    data_0217aa00->mUnk_0038 = 0x400;
    data_0217aa00->mUnk_003c = HeapAllocAligned(heap, data_0217aa00->mUnk_0038, 0x20);
    data_0217aa00->mUnk_15bc = HeapAllocAligned(heap, 0x820, 0x20);
    data_0217aa00->mUnk_15c0 = HeapAllocAligned(heap, 0x200, 0x20);
    data_0217aa00->mUnk_15c4 = HeapAllocAligned(heap, 8, 0x20);
    data_0217aa00->mUnk_15c8 = HeapAllocAligned(heap, 0x40, 0x20);
    data_0217aa00->mUnk_0040 = HeapAllocAligned(heap, 0x18, 0x20);
    data_0217aa00->mUnk_1664 = 0;
    data_0217aa00->mUnk_165c = 0;
    data_0217aa00->mUnk_1658 = 0;
    data_0217aa00->mUnk_0044.mUnk_38 = HeapAllocAligned(heap, 0x1c, 0x20);
    data_0217aa00->mHeap = NNS_FndCreateExpHeapEx(HeapAlloc(heap, 0x7800), 0x7800, 1);
    data_0217aa00->mMPReceiveBuffer = 0;
    data_0217aa00->mMPReceiveBufferSize = 0;
    data_0217aa00->mMPSendBuffer = 0;
    data_0217aa00->mMPSendBufferSize = 0;
    data_0217aa00->mUnk_0456_0 = 1;
    func_02053d00();
}

void func_02054330(void) {
    while (func_02054f58() != 1) {
    }
    data_0217aa00->mUnk_0456_0 = 0;
}

void ResetDataSharing(DataSharing *dataSharing) {
    Unk0217aa00_1e4c *q;
    s32 i;
    s32 j;

    dataSharing->mParticipantMask = 0;
    MI_CpuFill8(data_0217aa00->mUnk_15c4, 0, 8);
    for (i = 0; i < 8; i++) {
        dataSharing->mSharedDataCopied[i] = 0;
        MI_CpuFill8(&dataSharing->mUnk_0c[i], 0, 8);
    }
    dataSharing->mUnk_3c[0] = 0;
    for (i = 0; i < 7; i++) {
        dataSharing->mUnk_3c[i] = 0;
    }
    dataSharing->mUnk_4a = 0;
    dataSharing->mUnk_34 = 5;
    dataSharing->mUnk_38 = 0;
    dataSharing->mUnk_30 = 0;
    data_0217aa00->mUnk_0454 &= ~0x10;
    data_0217aa00->mUnk_008b &= ~1;
    q = &data_0217aa00->mUnk_1e4c_view;
    q->mUnk_60 = 0;
    q->mUnk_68 = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 3; j++) {
            q->mUnk_00[i].mUnk_00[j] = 0;
        }
    }
    data_0217aa00->mUnk_0454 &= ~0x10;
}

void ResetConnectionData(void) {
    u8 *q;
    s32 i;
    s32 j;
    s32 k;
    s32 l;

    for (i = 0; i < 7; i++) {
        data_0217aa00->mUnk_0044.mEntries[i].mAid = 0xffff;
        q = data_0217aa00->mUnk_0044.mEntries[i].mUnk_00;
        for (j = 0; j < 6; j++) {
            q[j] = 0;
        }
    }
    data_0217aa00->mUnk_0044.mUnk_42 = 0;
    data_0217aa00->mUnk_0044.mChildMask = 0;
    data_0217aa00->mUnk_0044.mChildCount = 0;
    data_0217aa00->mUnk_0044.mUnk_3c = 0;
    data_0217aa00->mUnk_0044.mDisconnectingIndex = -1;
    data_0217aa00->mUnk_0088 = -1;
    data_0217aa00->mUnk_008a = 0;
    data_0217aa00->mUnk_008b = 0;
    data_0217aa00->mUnk_0044.mUnk_3e = 0;
    MI_CpuCopy8(data_0217aa08->mFirstBlock->mPlayerName, data_0217aa00->mUnk_0044.mUnk_38, 0x14);
    data_0217aa00->mUnk_0044.mUnk_38->mUnk_0e.mUnk_06_4 = data_021759d0->mLanguageIndex;
    data_0217aa00->mUnk_0044.mUnk_38->mUnk_0e.mUnk_06_0 = 0;
    for (j = 0; j < 4; j++) {
        data_0217aa00->mUnk_00ac[j].mUnk_dc_0 = 0;
        data_0217aa00->mUnk_00ac[j].mUnk_db = 0;
        q = data_0217aa00->mUnk_00ac[j].mUnk_c0;
        for (k = 0; k < 6; k++) {
            q[k] = 0;
        }
    }
    data_0217aa00->mOwnIndex = 0xffff;
    data_0217aa00->mUnk_0438 = 0;
    data_0217aa00->mUnk_0434 = 0;
    data_0217aa00->mUnk_0439 = 1;
    data_0217aa00->mUnk_043a = 0;
    data_0217aa00->mUnk_0436 = 0;
    data_0217aa00->mUnk_043c = 0;
    data_0217aa00->mUnk_043d = 0;
    data_0217aa00->mUnk_043b = 0;
    q = data_0217aa00->mUnk_00ac_view.mUnk_380;
    for (l = 0; l < 6; l++) {
        q[l] = 0;
    }
    data_0217aa00->mUnk_0457 = 0;
    data_0217aa00->mUnk_0458 = 0;
    data_0217aa00->mUnk_1699 = 0;
    data_0217aa00->mUnk_0454 &= ~1;
    ClearParticipantBits();
    ResetDataSharing(&data_0217aa00->mUnk_15bc_view);
}

void func_02053e74(void) {
    Unk0217aa00_1e4c *q;
    ConnectionWork *connection;
    RandomState *random;
    s32 i;
    s32 j;
    s32 a;
    s32 b;

    q = &data_0217aa00->mUnk_1e4c_view;
    q->mUnk_60 = 0;
    q->mUnk_68 = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 3; j++) {
            q->mUnk_00[i].mUnk_00[j] = 0;
        }
    }
    data_0217aa00->mUnk_0454 &= ~0x10;
    data_0217aa00->mUnk_0454 |= 8;
    connection = data_0217aa00;
    a = 0;
    switch (func_02053e74_inline()) {
        case 1:
            a = connection->mParentParameter->mUnk_0c;
            break;
        case 2:
            a = connection->mUnk_0024->mUnk_48;
            break;
    }
    b = 0;
    switch (func_02053e74_inline()) {
        case 1:
            b = connection->mParentParameter->mUnk_0c;
            break;
        case 2:
            b = connection->mUnk_0024->mUnk_48;
            break;
    }
    connection->mRandom.mStateLow = b + (a << 10);
    random = &connection->mRandom;
    random->mStateHigh = 0;
    random->mMultiplierLow = 0x6c078965;
    random->mMultiplierHigh = 0x5d588b65;
    random->mIncrementLow = 0x269ec3;
    random->mIncrementHigh = 0;
}
