#include "Main/Unknown/code_0210d740.h"

#include "Main/Unknown/code_0210d73c.h"
#include "Main/Unknown/code_0210dc60.h"
#include "code_0212bcac.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "code_0212df7c.h"
#include "code_0212d214.h"
#include "code_0212f1ac.h"
#include "code_0212ba68.h"
#include "Main/Unknown/code_0210d890.h"
#include "Main/Unknown/code_0210d894.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_0210d960.h"

void func_0210d990(u32 p0) {
    data_0217d064 = p0;
}

u32 func_0210d980(void) {
    return data_0217d064;
}

void func_0210d970(u32 p0) {
    data_0216cb2c = p0;
}

u32 func_0210d960(void) {
    return data_0216cb2c;
}

void func_0210d894(void *a, u32 b, const u8 *c) {
    NNS_SndInit();
    data_0217d130 = HeapStackCreate(a, b);
    data_0217d06c = HeapStackAlloc(data_0217d130, 0x1020, func_0210d890, NULL, 0);
    if (c != NULL) {
        func_0212d8e0(&data_0217d0a0, c, data_0217d130, 0);
        data_0217d064 = 1;
        func_0212edac(data_0217d130);
    }
    NNS_SndHandleInit(&data_0217d068);
    func_0210dc60(&data_0217d084, &data_0217d070, 0);
}

void func_0210d890(u32 p0) {}

void func_0210d854(u32 a) {
    NNS_SndCaptureStartOutputEffect((void *) (((u32) data_0217d06c + 0x1f) & ~0x1f), 0x1000, a);
    data_0216cb24 = a;
}

void func_0210d834(s32 a) {
    NNS_SndCaptureChangeOutputEffect(a);
    data_0216cb24 = a;
}

void func_0210d7dc(u32 a, u32 b, NNSSndSeqPlayer **c) {
    if (*c != NULL) {
        NNS_SndPlayerStopSeq(c, 0);
    }
    func_0212d254(((Unk0212ea28 *) func_0212d51c(a))->mUnk_00);
    func_0212ed58(c, a);
    NNS_SndPlayerSetVolume(c, b);
}

void func_0210d7ac(void) {
    if (data_0217d070.mUnk_00 != 0) {
        func_0210d73c(&data_0217d070);
    }
    NNS_SndMain();
}

void func_0210d740(Unk0217d070 *a, Unk0217c814 *b, u32 c, Unk021073ec d) {
    func_0210dc60(&data_0217d084, a, 0);
    *(Unk021073ec *) &a->mUnk_09 = d;
    a->mUnk_04 = b;
    a->mUnk_08 = c;
    NNS_SndHandleInit(&a->mUnk_0c);
    NNS_SndHandleInit(&a->mUnk_10);
    a->mUnk_00 = 1;
}
