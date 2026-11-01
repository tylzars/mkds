#include "00/code_02181758.h"
#include "00/code_02181904.h"
#include "00/code_02181d20.h"
#include "00/code_02181dd0.h"
#include "00/code_ov000_021804e0.h"
#include "00/code_0218198c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"

void func_ov000_02181854(void) {
    Unk02175628Index i = UNK_02175628_INDEX_8;
    s32 a;
    s32 b;
    u32 v;
    if (func_02125f6c() != 0) {
        func_0212ecc0(&data_0217d068, 0, 0x15);
    }
    if (func_02125fa4() != 0 && func_02128294() != 0) {
        if ((u16) (data_02175628[i].mUnk_00 & 2) == 0) {
            a = b = 0;
            v = data_02175628[i].mUnk_4c;
            if (v == 0 && data_02175628[i].mUnk_58 < 5) {
                a = 1;
            }
            if (a == 0 && data_02175628[i].mUnk_54 == 0 && v != 0) {
                b = 1;
            }
            if (b == 0 || func_02128210(data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a) == 0) {
                return;
            }
        }
        data_ov000_021b4c6c->mUnk_04 = 1;
        func_02128310(0);
        func_02125fc0();
    }
}

void func_ov000_021817e8(void) {
    s32 i = 0;
    s32 v1 = 0;
    const u8 *p = data_ov000_021b05c4;
    const u8 *q = data_ov000_021b05c8;
    for (; i < 3; i++) {
        if (i == data_ov000_021b4c6c->mUnk_08 && data_ov000_021b4c6c->mUnk_18 != 0) {
            data_ov000_021b4c6c->mUnk_1c[*p].mUnk_00 = 1;
            func_02124a20(*q, 0xe, data_ov000_021b4c6c->mUnk_20, data_ov000_021b4c6c->mUnk_2c);
        } else {
            data_ov000_021b4c6c->mUnk_1c[*p].mUnk_00 = v1;
            func_02124a20(*q, 0xf, data_ov000_021b4c6c->mUnk_20, data_ov000_021b4c6c->mUnk_2c);
        }
        p++;
        q++;
    }
}

void func_ov000_02181758(void) {
    Unk021b4c6c *p;
    data_ov000_021b4c6c->mUnk_00 = data_ov000_021b4c6c->mUnk_04;
    switch (data_ov000_021b4c6c->mUnk_00) {
        case 0:
            func_ov000_02181dd0();
            break;
        case 1:
            func_ov000_02181d44();
            break;
        case 2:
            func_ov000_02181d20();
            break;
        case 3:
            func_ov000_02181b4c();
            break;
        case 4:
            func_ov000_02181ab8();
            break;
        case 5:
            func_ov000_0218198c();
            break;
        case 6:
            func_ov000_02181940();
            break;
        case 7:
            func_ov000_02181904();
            break;
        case 8:
            func_ov000_02181854();
            break;
    }
    func_ov000_021817e8();
    p = data_ov000_021b4c6c;
    func_02124c30(p->mUnk_2c, p->mUnk_20, 0, func_ov000_021804e0(), p->mUnk_1c);
}
