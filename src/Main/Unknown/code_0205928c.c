#include "Main/Unknown/code_0205928c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_0204f644.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_02058b38.h"
#include "Main/Unknown/code_02051000.h"
#include "Main/Unknown/code_02058000.h"
#include "Main/Unknown/code_02059000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"

#include "Main/Unknown/code_0210e33c.h"
#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02004d80.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0214d000.h"

#pragma thumb on

void InitMPChunkBuffers(void *a) {
    int v1;
    int v2;
    void *v3;
    int *v4;
    v3 = HeapAllocAligned(a, (0x0000016cu), 0x20);
    v4 = (s32 *) &data_0217aa00;
    data_0217aa00->mChunkBuffer = v3;
    v1 = 0;
    v2 = 0;
    do {
        v3 = HeapAlloc(a, 0x12);
        *(void **) (*v4 + v2 + 0x162c) = v3;
        v2 = v2 + 4;
        v1 = v1 + 1;
    } while (v1 < 8);
}

#pragma thumb off

#pragma thumb on

static inline u32 func_0205955c_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline s32 func_0205955c_inline2(void) {
    BOOL r = FALSE;
    if (func_0205955c_inline() != 0 && data_0217aa00->mUnk_0004 != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_0205955c_inline3(void) {
    BOOL r = FALSE;
    if (func_0205955c_inline2() && !(data_0217aa00->mUnk_0454 & 0x80)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_0205955c_inline4(void) {
    BOOL r = FALSE;
    if (func_0205955c_inline3() && data_0217aa00->mUnk_0008 != 9) {
        r = TRUE;
    }
    return r;
}

void func_020597d0(const void *a, s32 b, s32 c, s32 d) {
    s32 v;
    s32 m;

    v = data_0217aa00->mUnk_0004;
    if (v != 11) {
        func_020559ec(a, c, d);
        return;
    }
    m = 1 << c;
    if (!(data_0217aa00->mUnk_164c & m)) {
        MI_CpuCopy8(a, &data_0217aa00->mUnk_045c[c], 0x14);
        data_0217aa00->mUnk_164c |= m;
    }
}

s32 IsAllMPChildSharedDataCopied(void) {
    s32 r;
    u16 i;
    u8 m;

    r = 1;
    i = r;
    m = data_0217aa00->mUnk_0044.mChildMask;
    for (; i < 8; i++) {
        if ((m & (r << i)) && data_0217aa00->mUnk_15bc_view.mSharedDataCopied[i] == 0) {
            r = 0;
            break;
        }
    }
    return r;
}

s32 func_02059700(void) {
    BOOL r;

    r = FALSE;
    switch (data_0217aa00->mUnk_1e34) {
        case 0:
            data_0217aa00->mUnk_1e34 = 6;
            break;
        case 6:
            if (data_0217aa00->mUnk_0044.mChildMask ==
                (data_0217aa00->mUnk_0044.mChildMask & data_0217aa00->mUnk_1d54)) {
                data_0217aa00->mUnk_1e34 = 7;
            }
            break;
        case 7:
            if (QueueMPDataHalfword(5, 0xff) != FALSE) {
                data_0217aa00->mUnk_1d54 = r;
                data_0217aa00->mUnk_1e34 = 1;
            }
            break;
        case 1:
            r = TRUE;
            break;
    }
    return r;
}

s32 func_020595e8(s32 a, void *b, void *c) {
    BOOL r;

    r = FALSE;
    switch (data_0217aa00->mUnk_1e34) {
        case 0:
            if (data_0217aa00->mUnk_0454 & 1) {
                data_0217aa00->mUnk_1e34 = 2;
            }
            break;
        case 2:
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
                switch (a) {
                    case 0:
                        func_020473e4();
                        break;
                    case 1:
                        RequestRaceArchives(b, c);
                        break;
                    case 2:
                        RequestResultDLArchives();
                        break;
                    case 3:
                        RequestMenuDLArchives();
                        break;
                }
                data_0217aa00->mUnk_000c = 0x27;
                data_0217aa00->mRequestPending = 1;
                data_0217aa00->mUnk_1d08 = 0;
                FS_InitFile(&data_0217aa00->mUnk_1d0c);
                data_0217aa00->mUnk_1e34 = 3;
            } else {
                data_0217aa00->mUnk_1e34 = 5;
            }
            QueueMPDataHalfword(3, 1);
            break;
        case 3:
            if (func_0204f644() != FALSE) {
                data_0217aa00->mUnk_1e34 = 5;
            }
            break;
        case 5:
            if (QueueMPDataHalfword(4, 1) != FALSE) {
                data_0217aa00->mUnk_1e34 = 1;
            }
            break;
        case 1:
            if (data_0217aa00->mUnk_1e44 & 2) {
                r = TRUE;
            }
            break;
    }
    return r;
}

u32 func_0205955c(void) {
    if (func_0205955c_inline4()) {
        return 3;
    }
    switch (func_0205955c_inline()) {
        case 1:
            return func_02059700();
        case 2:
            return func_020595e8(0, NULL, NULL);
        default:
            return 3;
    }
}

#pragma thumb off

#pragma thumb on

// Asks for state 16 with the next race's course and mode.
void RequestMPState16(void *a, void *b) {
    Unk0217aa00_1608 *part;
    data_0217aa00->mUnk_1e34 = 0;
    data_0217aa00->mUnk_1e44 &= ~2;
    part = &data_0217aa00->mUnk_1608;
    part->mNextState = 0x10;
    part->mNextStateRequested = 1;
    data_0217aa00->mCourseId = a;
    data_0217aa00->mMode = b;
}

#pragma thumb off

#pragma thumb on

static inline u32 func_020593dc_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline s32 func_020593dc_inline2(void) {
    BOOL r = FALSE;
    if (func_020593dc_inline() != 0 && data_0217aa00->mUnk_0004 != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_020593dc_inline3(void) {
    BOOL r = FALSE;
    if (func_020593dc_inline2() && !(data_0217aa00->mUnk_0454 & 0x80)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_020593dc_inline4(void) {
    BOOL r = FALSE;
    if (func_020593dc_inline3() && data_0217aa00->mUnk_0008 != 9) {
        r = TRUE;
    }
    return r;
}

void RequestMPState18(void) {
    Unk0217aa00_1608 *p;

    data_0217aa00->mUnk_1e34 = 0;
    data_0217aa00->mUnk_1e44 &= ~2;
    p = &data_0217aa00->mUnk_1608;
    p->mNextState = 0x12;
    p->mNextStateRequested = 1;
}

void RequestMPState21(void) {
    Unk0217aa00_1608 *p;

    data_0217aa00->mUnk_1e34 = 0;
    data_0217aa00->mUnk_1e44 &= ~2;
    p = &data_0217aa00->mUnk_1608;
    p->mNextState = 0x15;
    p->mNextStateRequested = 1;
}

u32 func_020593dc(void) {
    if (func_020593dc_inline4()) {
        return 3;
    }
    if (!func_020593dc_inline2()) {
        return 1;
    }
    switch (func_020593dc_inline()) {
        case 1:
            return func_02059700();
        case 2:
            return func_020595e8(1, data_0217aa00->mCourseId, data_0217aa00->mMode);
        default:
            return 3;
    }
}

#pragma thumb off

#pragma thumb on

void EnterMPState16(void) {
    int v1;
    if (data_0217aa00 == NULL) {
        v1 = 0;
    } else {
        v1 = data_0217aa00->mUnk_0000;
    }
    if (v1 == 1) {
        SetMPFrequency(0);
    }
}

void UpdateMPState16(void) {
    int v1;
    Unk0217aa00_1608 *v2;
    v1 = func_020593dc();
    if (v1 == 1) {
        v2 = &data_0217aa00->mUnk_1608;
        v2->mNextState = 0x11;
        v2->mNextStateRequested = 1;
    }
}

#pragma thumb off

#pragma thumb on

void func_0205933c(void) {
    u32 a;

    a = LoadCourseSoundSet((u32) data_0217aa00->mMode, (u32) data_0217aa00->mCourseId);
    if (*(u16 *) 0x027ffc40 == 2) {
        func_02043f28(0);
    }
    if (a == 0) {
        data_0217aa00->mUnk_164f = 1;
    }
}

void func_02059304(void) {
    data_0217aa00->mUnk_1e34 = 0;
    data_0217aa00->mUnk_1e44 &= ~2;
    data_0217aa00->mUnk_164f = 0;
}

#pragma thumb off

#pragma thumb on

void UpdateMPState17(void) {
    int v1;
    Unk0217aa00_1608 *v2;
    v1 = func_02058dc0(func_0205933c);
    if (v1 == 1) {
        v2 = &data_0217aa00->mUnk_1608;
        v2->mNextState = 0x14;
        v2->mNextStateRequested = 1;
    }
}

void EnterMPState20(void) {
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

void UpdateMPState20(void) {
    Unk0217aa00_1608 *v1;
    if (data_0217aa00->mRequestPending == 0) {
        v1 = &data_0217aa00->mUnk_1608;
        v1->mNextState = 0xf;
        v1->mNextStateRequested = 1;
    }
}

#pragma thumb off
