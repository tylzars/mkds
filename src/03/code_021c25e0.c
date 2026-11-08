#include "03/code_021c25e0.h"
#include "03/code_021d083c.h"
#include "03/code_021d1000.h"
#include "03/code_021d3000.h"

#include "03/code_021d27d8.h"
#include "03/code_021d3488.h"
#include "code_0214cfe4.h"
#include "03/code_021c209c.h"
#include "03/code_021c2530.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/unk_021da000.h"
#include "03/code_021bf410.h"
#include "code_0200fc8c.h"

void func_ov003_021c2840(u32 callback) {
    Unk021d6e24 b;
    data_ov003_021da194 = AllocExpHeapBlock(0x1e2a4, 0x20);
    data_ov003_021da194->mCallback = (void (*)(s32)) callback;
    data_ov003_021da194->mUnk_1e2a0 = 0;
    data_ov003_021da194->mUnk_1e2a1 = 0;
    b = data_ov003_021d6e24;
    b.mUnk_04 = GetMessageEntry(gMessages, 0xf);
    b.mUnk_08 = GetMessageEntry(gMessages, 0x10);
    b.mUnk_18 = GetLanguageIndex() + 0x31;
    func_ov003_021d1358((Unk021da2ac *) data_ov003_021da194, (Unk021d1358 *) &b);
    if (func_ov003_021d11d4() == 0) {
        OS_Terminate();
    }
    data_ov003_021da194->mStepTask = func_ov003_021d3544(0, func_ov003_021c25e0, NULL, 0x78);
}

void func_ov003_021c2824(void) {
    func_ov003_021d3544(0, &func_ov003_021c27f8, NULL, 0x78);
}

void func_ov003_021c27f8(u32 task) {
    int result;
    result = func_ov003_021d1290();
    if (result != 0) {
        data_ov003_021da194->mUnk_1e2a1 = 1;
        func_ov003_021d34c8(0, task);
    }
}

BOOL func_ov003_021c27e4(void) {
    if (data_ov003_021da194 == NULL) {
        return 1;
    }
    return 0;
}

void func_ov003_021c27d0(void *callback) {
    data_ov003_021da194->mCallback = (void (*)(s32)) callback;
}

u32 func_ov003_021c27c8(void) {
    u32 result;
    u32 value3;
    value3 = (u32) &func_ov003_021d11a0;
    result = func_ov003_021d11a0();
    return result;
}

u8 *func_ov003_021c27b4(void) {
    return data_ov003_021da194->mUnk_1e280;
}

static inline void func_ov003_021c25e0_inline(const void *source, void *destination, s32 size) {
    MIi_CpuCopy16(source, destination, size);
}

void func_ov003_021c25e0(u32 task) {
    u8 stateInfo[2];
    Unk021da194 *object;
    func_ov003_021d0ee0();
    object = data_ov003_021da194;
    if (object->mUnk_1e2a0 != 0 && object->mUnk_1e2a1 == 0) {
        if (object->mCallback == NULL) {
            return;
        }
        object->mCallback(0);
        return;
    }
    func_ov003_021d0e9c(&stateInfo[0], &stateInfo[1]);
    switch (stateInfo[0]) {
        case 1:
        case 2:
        case 3:
        case 4:
            break;
        case 5:
            if (stateInfo[1] == 0) {
                break;
            }
            func_ov003_021c25e0_inline(func_ov003_021d0e90(), data_ov003_021da194->mUnk_1e280, 0x16);
            if (data_ov003_021da194->mCallback != NULL) {
                data_ov003_021da194->mCallback(0);
            } else {
                data_ov003_021da194->mUnk_1e2a0 = 1;
            }
            break;
        case 13:
            if (stateInfo[1] == 0) {
                break;
            }
            if (data_ov003_021da194->mCallback != NULL) {
                data_ov003_021da194->mCallback(1);
            } else {
                data_ov003_021da194->mUnk_1e2a0 = 1;
            }
            break;
        case 20:
        case 23:
            if (stateInfo[1] == 0) {
                break;
            }
            if (data_ov003_021da194->mCallback != NULL) {
                data_ov003_021da194->mCallback(3);
            } else {
                data_ov003_021da194->mUnk_1e2a0 = 1;
            }
            break;
        case 26:
        case 29:
            if (stateInfo[1] == 0) {
                break;
            }
            if (data_ov003_021da194->mCallback != NULL) {
                data_ov003_021da194->mCallback(4);
            } else {
                data_ov003_021da194->mUnk_1e2a0 = 1;
            }
            break;
        case 12:
            if (stateInfo[1] == 0) {
                break;
            }
            if (data_ov003_021da194->mCallback != NULL) {
                data_ov003_021da194->mCallback(2);
            } else {
                data_ov003_021da194->mUnk_1e2a0 = 1;
            }
            break;
        case 34:
            func_ov003_021d34c8(0, task);
            FreeExpHeapBlockAndClearPointer(&data_ov003_021da194);
            break;
    }
}
