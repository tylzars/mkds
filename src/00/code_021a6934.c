#include "00/code_021a6934.h"
#include "00/code_021a669c.h"

#include "03/code_021b94b8.h"
#include "00/unk_021b5000.h"
#include "00/code_021a574c.h"
#include "00/code_021a5000.h"
#include "code_0200db4c.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "00/code_021a6908.h"
#include "00/code_021a68dc.h"
#include "code_0200edc0.h"
#include "code_02133048.h"
#include "code_02142eac.h"

void func_ov000_021a6bdc(void) {
    if (data_ov000_021b5f54.mUnk_00 == 0) {
        data_ov000_021b5f54.mUnk_00 = 1;
        data_ov000_021b5f54.mUnk_24 = 0;
        data_ov000_021b5f54.mUnk_04.mTail = NULL;
        data_ov000_021b5f54.mUnk_04.mHead = NULL;
        OS_InitMutex(&data_ov000_021b5f54.mUnk_0c);
    }
}

void func_ov000_021a6bb4(Unk021a6bb4 *b) {
    Unk021b5f54Func a = data_ov000_021b5f54.mUnk_28;

    if (a != NULL) {
        a(b->mUnk_1e, b->mUnk_18, b->mUnk_2c, b->mUnk_06);
    }
}

void func_ov000_021a6b54(void) {
    Unk021b5f50 *a;

    a = func_ov000_021a5b30();
    if (a != NULL && a->mUnk_2260 == 9 && a->mUnk_226b != 1) {
        if (func_ov000_021a6908(&data_ov000_021b5f54.mUnk_0c) != 0) {
            if (WM_SetDCFData((Unk021425e8Func) func_ov000_021a6934, a->mUnk_2144, a->mUnk_0f00, 0) != 2) {
                func_ov000_021a68dc(&data_ov000_021b5f54.mUnk_0c);
            }
        }
    }
}

u8 *func_ov000_021a6b10(void) {
    u8 *a = NULL;
    Unk021b5f50 *b;
    u32 c;

    b = func_ov000_021a5b30();
    c = OS_DisableInterrupts();
    if (b != NULL && b->mUnk_2260 == 9 && b->mUnk_226b == 0) {
        a = b->mUnk_2144;
    }
    OS_RestoreInterrupts(c);
    return a;
}

u8 *func_ov000_021a6abc(u16 *e) {
    u8 *a = NULL;
    u16 b = 0;
    Unk021b5f50 *c;
    u32 d;

    c = func_ov000_021a5b30();
    d = OS_DisableInterrupts();
    if (c != NULL && c->mUnk_2260 == 9 && c->mUnk_226b == 0) {
        a = c->mUnk_214c;
        b = c->mUnk_214a;
    }
    OS_RestoreInterrupts(d);
    if (e != NULL) {
        *e = b;
    }
    return a;
}

u32 func_ov000_021a6aa0(Unk021b5f54Func arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value4;
    value4 = (value0) + (0u);
    value0 = (u32) OS_DisableInterrupts();
    value1 = (u32) &data_ov000_021b5f54;
    *(u32 *) ((value1) + 40u) = value4;
    value0 = (u32) OS_RestoreInterrupts(value0);
    return value0;
}

s32 func_ov000_021a6974(const void *d, const void *e, s32 f) {
    u32 a;
    Unk021b5f50 *b;
    s32 c;

    a = OS_DisableInterrupts();
    if (func_ov000_021a5b30() == NULL) {
        OS_RestoreInterrupts(a);
        return -1;
    }
    OS_LockMutex(&data_ov000_021b5f54.mUnk_0c);
    b = func_ov000_021a5b30();
    if (b == NULL) {
        OS_UnlockMutex(&data_ov000_021b5f54.mUnk_0c);
        OS_RestoreInterrupts(a);
        return -1;
    }
    if (b->mUnk_2260 != 9 || b->mUnk_226b == 1) {
        OS_UnlockMutex(&data_ov000_021b5f54.mUnk_0c);
        OS_RestoreInterrupts(a);
        return -4;
    }
    MI_CpuCopy8(e, b->mUnk_0f00, f);
    c = WM_SetDCFData(func_ov000_021a6944, d, b->mUnk_0f00, f);
    switch (c) {
        case 0:
        case 1:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        default:
            OS_UnlockMutex(&data_ov000_021b5f54.mUnk_0c);
            OS_RestoreInterrupts(a);
            return -5;
        case 2:
            OS_SleepThread(&data_ov000_021b5f54.mUnk_04);
            switch (data_ov000_021b5f54.mUnk_24) {
                case 1:
                default:
                    OS_UnlockMutex(&data_ov000_021b5f54.mUnk_0c);
                    OS_RestoreInterrupts(a);
                    return -5;
                case 0:
                    OS_UnlockMutex(&data_ov000_021b5f54.mUnk_0c);
                    OS_RestoreInterrupts(a);
                    return f;
            }
    }
}

void func_ov000_021a6944(Unk021425e8 *a) {
    if (a->mCommand == 0x12) {
        data_ov000_021b5f54.mUnk_24 = a->mResultCode;
        if (a->mResultCode == 0) {
            func_ov000_021a57a8();
        }
        OS_WakeupThread(&data_ov000_021b5f54.mUnk_04);
    }
}

void func_ov000_021a6934(void) {
    func_ov000_021a68dc(&data_ov000_021b5f60);
}
