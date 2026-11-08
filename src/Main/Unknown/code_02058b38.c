#include "Main/Unknown/code_02058b38.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02056464.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200f5ac.h"

#pragma opt_rebuildconditionals off

static inline u32 func_02058b38_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline void func_02058b74_inline(u16 nextState) {
    MPStateMachine *stateMachine = &data_0217aa00->mUnk_1608;
    stateMachine->mNextState = nextState;
    stateMachine->mNextStateRequested = 1;
}

static inline s32 func_02058cac_inline2(void) {
    BOOL r = FALSE;
    if (func_02058b38_inline() != 0 && data_0217aa00->mUnk_0004 != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02058cac_inline3(void) {
    BOOL r = FALSE;
    if (func_02058cac_inline2() && !(data_0217aa00->mUnk_0454 & 0x80)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02058cac_inline4(void) {
    BOOL r = FALSE;
    if (func_02058cac_inline3() && data_0217aa00->mUnk_0008 != 9) {
        r = TRUE;
    }
    return r;
}

#pragma thumb on

s32 func_02058dc0(void (*callback)(void)) {
    BOOL done;

    done = FALSE;
    switch (data_0217aa00->mUnk_1e34) {
        case 0:
            if (data_0217aa00->mUnk_0454 & 1) {
                switch (func_02058b38_inline()) {
                    case 1:
                        data_0217aa00->mUnk_1e34 = 6;
                        break;
                    case 2:
                        data_0217aa00->mUnk_1e34 = 2;
                        break;
                }
            }
            break;
        case 7:
            QueueMPDataHalfword(5, 0xff);
            data_0217aa00->mUnk_1e44 |= 2;
            data_0217aa00->mUnk_1d54 = done;
            data_0217aa00->mUnk_1e34 = 1;
            break;
        case 6:
            if (data_0217aa00->mUnk_0044.mChildMask ==
                (data_0217aa00->mUnk_0044.mChildMask & data_0217aa00->mUnk_1d54)) {
                data_0217aa00->mUnk_1e34 = 7;
            }
            break;
        case 2:
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
                QueueThreadFunction(callback);
                gThreadFunctionQueue->mRunRequested = 1;
            }
            data_0217aa00->mUnk_1e34 = 3;
            QueueMPDataHalfword(3, 1);
            break;
        case 3:
            if (gThreadFunctionQueue->mRunRequested == 0) {
                if (data_0217aa00->mUnk_164f != 0) {
                    func_02050e60(7);
                } else {
                    data_0217aa00->mUnk_1e34 = 5;
                }
            }
            break;
        case 5:
            if (QueueMPDataHalfword(4, 1) != FALSE) {
                data_0217aa00->mUnk_1e34 = 1;
            }
            break;
        case 1:
            if (data_0217aa00->mUnk_1e44 & 2) {
                done = TRUE;
            }
            break;
    }
    return done;
}

s32 func_02058cac(void) {
    BOOL finished;
    u16 ownIndex;

    finished = FALSE;
    if (!func_02058cac_inline2()) {
        return 1;
    }
    ownIndex = ((const ConnectionWork *) data_0217aa00)->mUnk_0000 == 2 ? data_0217aa00->mOwnIndex : 0;
    if (ownIndex == 0xffff && func_02058b38_inline() == 2) {
        if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
            func_02050e60(0);
            return 3;
        }
        return 2;
    }
    AdvanceStateMachine(&data_0217aa00->mUnk_1608);
    if (!func_02058cac_inline4()) {
        if (func_02058b38_inline() == 1 && data_0217aa00->mUnk_0044.mChildCount == 0) {
            func_02050e60(7);
        }
    }
    if (data_0217aa00->mUnk_1608.mState == 0xf) {
        finished = TRUE;
    }
    return finished;
}

void func_02058c74(void) {
    u16 ownIndex;

    ownIndex = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mOwnIndex : 0;
    FillPlayerRecord(&data_0217aa00->mUnk_045c[ownIndex]);
}

void func_02058c10(void) {
    if (data_0217aa00->mRequestPending != 0) {
        return;
    }
    if (func_02058b38_inline() != 1) {
        func_02058b74_inline(0x16);
        return;
    }
    switch (data_0217aa00->mUnk_000c) {
        case 11:
        case 15:
            SetEntry(0);
            return;
        case 13:
            func_02058b74_inline(7);
            break;
    }
}

void func_02058ba4(void) {
    u64 v;

    v = (u32) OS_GetTick() << 8;
    v = (u32) v & ~(u32) (v >> 32);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        v = v * 0x5d588b656c078965ull + 0x269ec3;
        data_0217aa00->mUnk_1608.mUnk_18 = (u16) (((v >> 32) * 0xb4) >> 32) + 0x78;
    } else {
        data_0217aa00->mUnk_1608.mUnk_18 = 0xb4;
    }
}

void func_02058b74(void) {
    data_0217aa00->mUnk_1608.mUnk_18 = data_0217aa00->mUnk_1608.mUnk_18 - 1;
    if (data_0217aa00->mUnk_1608.mUnk_18 < 0) {
        func_02058b74_inline(7);
    }
}

void func_02058b38(void) {
    if (func_02058b38_inline() == 1) {
        data_0217aa00->mParticipantMask = data_0217aa00->mUnk_0044.mChildMask | 1;
    }
    data_0217aa00->mUnk_1608.mUnk_14 = 0;
}

#pragma thumb off
