#include "Main/Unknown/code_02128884.h"

#include "Main/Unknown/code_021288a4.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_0212898c.h"
#include "Main/Unknown/code_0212899c.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02128940.h"
#include "Main/Unknown/code_02128958.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_0212a000.h"

#pragma thumb on
void func_02128958(s16 *a) {
    void *h;
    h = func_020364e0(func_020364e8());
    data_0217d3fc = func_02036bec(h, 0x808);
    func_0212a1e0(h, a[0]);
}
#pragma thumb off

#pragma thumb on
void func_02128940(void) {
    u32 value0;
    u32 value1;
    func_0212a1c4();
    value1 = 0u;
    value0 = (u32) &data_0217d3fc;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

Unk021a9034 data_0216e8e0 = {func_02128958, func_021288d8, func_02128940, func_0212891c, 0, 0, 10, 10, 0};

#pragma thumb on
void func_0212891c(void) {
    func_0212899c();
    func_020ae5f0(data_0217d3fc, &data_0217d3fc->mUnk_404);
}

void func_021288d8(s16 *a) {
    func_020ae6ac(data_0217d3fc, &data_0217d3fc->mUnk_404);
    func_021289e0();
    func_020ae630(data_0217d3fc, &data_0217d3fc->mUnk_404);
    if (a != 0) {
        if (func_0212898c() != -1) {
            a[2] = func_0212898c();
        }
    }
}

s32 func_021288a4(void *a) {
    Unk021a9034 v = data_0216e8e0;
    func_020487fc(a, &v);
    return 0;
}
#pragma thumb off

#pragma thumb on

Unk0217d3fc_00 *func_02128898(void) {
    return &data_0217d3fc->mUnk_00;
}

Unk0217d3fc_00 *func_02128884(void) {
    return &data_0217d3fc->mUnk_404;
}

#pragma thumb off
