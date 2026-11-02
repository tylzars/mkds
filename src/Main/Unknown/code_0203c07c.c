#include "Main/Unknown/code_0203c07c.h"
#include "Main/Unknown/code_020ada94.h"

#include "00/code_02182fdc.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_02039000.h"
#include "Main/Unknown/code_02043a34.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_0204a5f8.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020ad344.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_0218155c.h"

void func_0203c1a8(void *a, u32 b) {
    s32 v;
    if (func_0204176c(a, &v) == 0) {
        return;
    }
    if (v != 0) {
        if (data_021759c0->mUnk_08 == 4) {
            func_ov001_021816fc();
        }
        if (data_021759c0->mUnk_08 != 4) {
            return;
        }
        func_0203e788(b, 0);
    } else {
        func_0203e788(b, 6);
    }
}

s32 func_0203c174(void) {
    return data_0217561c->mUnk_4fa > data_021759c0->mUnk_038;
}

u32 func_0203c0bc(void) {
    u32 v;
    s32 i = data_021759c0->mUnk_62;
    if (i == -1) {
        return 0;
    }
    if (data_0217561c->mUnk_000[0].mUnk_0a >= 7) {
        return 1;
    }
    if (func_0204a620((Unk02175650 *) &data_02175628[i].mUnk_28) != 0) {
        return 1;
    }
    if (func_020617a8(&v) != 0) {
        if (v > 0x384) {
            return 1;
        }
    }
    return 0;
}

void func_0203c094(void) {
    func_020364e0(func_020364e8());
    func_02039a1c();
    func_020ad344();
    func_02043c14();
}

void func_0203c088(void) {
    u32 value12;
    value12 = (u32) &func_020ad32c;
    func_020ad32c();
}

void func_0203c07c(void) {
    u32 value12;
    value12 = (u32) &func_020ada94;
    func_020ada94();
}
