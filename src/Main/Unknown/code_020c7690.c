#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020c7690.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020de9f8.h"
#include "Main/Unknown/code_020e0680.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_0217b000.h"

void func_020c76c8(void) {
    s32 i;
    s32 n;
    u32 a;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < data_0217b404->mUnk_08; i++) {
        if (func_020b5ae8(&data_0217b404->mUnk_00[i]->mUnk_04, &data_0217b404->mUnk_10[n].mUnk_00, a, 1, 0) != 0) {
            data_0217b404->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(0xac);
            data_0217b404->mUnk_10[n].mUnk_0c = 1;
            n++;
        }
    }
    data_0217b404->mUnk_04 = n;
}

void func_020c76ac(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b404, 0);
}

s32 func_020c7690(void) {
    return func_020c0c2c(&data_0217b400, 0x12f);
}
