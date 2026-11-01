#include "00/code_0218536c.h"
#include "00/code_02184bec.h"
#include "00/code_021855f8.h"
#include "00/code_021806e0.h"
#include "00/code_021804f4.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/unk_02175628.h"

void func_ov000_0218536c(void) {
    Unk021b4c88 *p;

    data_ov000_021b4c88->mUnk_00 = data_ov000_021b4c88->mUnk_04;
    switch (data_ov000_021b4c88->mUnk_00) {
        case 0:
            func_ov000_021854a8();
            break;
        case 1:
            func_ov000_02185418();
            break;
        case 2:
            func_ov000_021853c4();
            break;
    }
    func_ov000_021854f8();
    p = data_ov000_021b4c88;
    func_02124c30(p->mUnk_40, p->mUnk_34, p->mUnk_48, func_ov000_021804f4(), p->mUnk_30);
}

void func_ov000_021853c4(void) {
    data_ov000_021b4c88->mUnk_08 = data_ov000_021b4c88->mUnk_08 + 1;
    data_ov000_021b4c88->mUnk_0c = func_020ae4c0(1, 0, 0x50, data_ov000_021b4c88->mUnk_08, 15);
    if (data_ov000_021b4c88->mUnk_08 >= 15 && func_02125f88() != 0 && func_02128294() != 0) {
        func_ov000_021806e0(data_ov000_021b4c88->mUnk_28);
    }
}

void func_ov000_02185418(void) {
    Unk02175628Index i = UNK_02175628_INDEX_8;
    s32 a;
    s32 b;
    u16 c;

    if ((u16) (data_02175628[i].mUnk_00 & 2) == 0) {
        a = 0;
        b = 0;
        c = data_02175628[i].mUnk_4c;
        if (c == 0 && data_02175628[i].mUnk_58 < 5) {
            b = 1;
        }
        if (b == 0 && data_02175628[i].mUnk_54 == 0 && c != 0) {
            a = 1;
        }
        if (a == 0 || func_02128210(data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a) == 0) {
            return;
        }
    }
    data_ov000_021b4c88->mUnk_04 = 2;
    data_ov000_021b4c88->mUnk_28 = 8;
    func_02128310(0);
    func_02125fc0();
}

void func_ov000_021854a8(void) {
    data_ov000_021b4c88->mUnk_08 = data_ov000_021b4c88->mUnk_08 + 1;
    data_ov000_021b4c88->mUnk_0c = func_020ae4c0(1, 0x50, 0, data_ov000_021b4c88->mUnk_08, 15);
    if (data_ov000_021b4c88->mUnk_08 >= 15 && func_02125fa4() != 0) {
        data_ov000_021b4c88->mUnk_04 = 1;
        data_ov000_021b4c88->mUnk_08 = 0;
    }
}

void func_ov000_021854f8(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        data_ov000_021b4c88->mUnk_30[data_ov000_021b06d8[i]].mUnk_06 = data_ov000_021b4c88->mUnk_0c;
    }
    for (i = 0; i < 12; i++) {
        data_ov000_021b4c88->mUnk_30[data_ov000_021b06dc[i] + data_ov000_021b4c88->mUnk_40->mUnk_06].mUnk_06 =
            data_ov000_021b4c88->mUnk_0c;
    }
}
