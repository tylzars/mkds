#include "Main/Unknown/code_0202ee88.h"
#include "Main/Unknown/code_020291c4.h"
#include "Main/Unknown/code_0202e68c.h"
#include "Main/Unknown/code_0202f020.h"
#include "Main/Unknown/code_0202f028.h"
#include "Main/Unknown/code_0202f058.h"
#include "Main/Unknown/code_0202f0a8.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0202edfc.h"
#include "Main/Unknown/unk_02174000.h"

#pragma optimize_for_size on

u32 func_0202efe8(Unk02175628_48 *a) {
    u32 r;
    if (func_0202f028(a) != 0 || func_0202f020(a) != 0) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

u32 func_0202efc8(u32 a) {
    return func_0202efe8((Unk02175628_48 *) &data_02175628[a].mUnk_48);
}

#pragma thumb on

void func_0202eec0(void) {
    u32 a = func_020435bc();
    u32 b;
    u32 c;
    s32 d;
    if (func_0202f0a8(a) != 0) {
        b = func_0202f080(a);
        c = func_0202f058(a);
        data_02174e48->mUnk_01c = func_020291c4(b, c, data_02174e48->mUnk_00c);
        data_02174e48->mUnk_020 = data_02174e48->mUnk_01c;
        data_02174e48->mUnk_66c = 1;
    } else {
        data_02174e48->mUnk_020 = -1;
    }
    if (data_02174e48->mUnk_66c != 0) {
        if (func_0202efc8(a) != 0) {
            b = func_0202f080(a);
            c = func_0202f058(a);
            d = func_020291c4(b, c, data_02174e48->mUnk_00c);
            if (d != data_02174e48->mUnk_01c) {
                data_02174e48->mUnk_01c = -1;
                data_02174e48->mUnk_66c = 0;
            }
        } else {
            data_02174e48->mUnk_01c = -1;
            data_02174e48->mUnk_66c = 0;
        }
    }
    if (func_0202ec7c(a, 0x40) != 0 || data_02174e48->mUnk_01c == data_02174e48->mUnk_010) {
        data_02174e48->mUnk_050 = data_02174e48->mUnk_050 + 1;
    } else {
        data_02174e48->mUnk_050 = 0;
    }
    if (func_0202ec7c(a, 0x80) != 0 || data_02174e48->mUnk_01c == data_02174e48->mUnk_014) {
        data_02174e48->mUnk_054 = data_02174e48->mUnk_054 + 1;
    } else {
        data_02174e48->mUnk_054 = 0;
    }
}

void func_0202ee88(void) {
    if (data_02174e48->mUnk_008[data_02174e48->mUnk_02e].mUnk_00 != 0) {
        data_02174e48->mUnk_008[data_02174e48->mUnk_02e].mUnk_06 = data_02174e48->mUnk_030 *
                                                                   (data_02174e48->mUnk_040 - data_02174e48->mUnk_044) /
                                                                   (data_02174e48->mUnk_034 - 5);
    }
}
