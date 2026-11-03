#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020cce24.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/unk_0217b000.h"

void func_020cce58(void) {
    s32 i;
    s32 a;
    u32 n;
    Unk0217b498_00 *e;

    a = 0;
    n = func_020c0db0();
    for (i = 0; i < data_0217b444->mUnk_08; i++) {
        e = data_0217b444->mUnk_00[i];
        if ((e->mUnk_02 & 1) == 0 && (e->mUnk_02 & 2) == 0) {
            if (func_020b5ae8(&e->mUnk_04, &data_0217b444->mUnk_10[a].mUnk_00, n, 1, 1) != 0) {
                data_0217b444->mUnk_10[a].mUnk_08 = GetRaceSNcerEntry(0xad);
                data_0217b444->mUnk_10[a].mUnk_0c = 3;
                data_0217b444->mUnk_10[a].mUnk_0e = 0;
                data_0217b444->mUnk_10[a].mUnk_10 = e->mUnk_7e;
                a++;
            }
        }
    }
    data_0217b444->mUnk_04 = a;
}

void func_020cce3c(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b444, 1);
}

s32 func_020cce24(void) {
    return func_020c0c2c(&data_0217b440, 0xcf);
}
