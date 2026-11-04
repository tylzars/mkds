#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020ca534.h"
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
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020c0d9c.h"

void func_020ca568(void) {
    s32 i;
    s32 n;
    u32 v;

    n = 0;
    v = func_020c0db0();
    for (i = 0; i < data_0217b434->mUnk_08; i++) {
        Unk0217b498_00 *p;

        p = data_0217b434->mUnk_00[i];
        if (!(p->mUnk_02 & 1)) {
            if (func_020b5ae8(&p->mUnk_04, &data_0217b434->mUnk_10[n].mUnk_00, v, 1, 1)) {
                data_0217b434->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(0xb6);
                data_0217b434->mUnk_10[n].mUnk_0c = (p->mUnk_02 & 0x20) ? 2 : 1;
                data_0217b434->mUnk_10[n].mUnk_0e = p->mUnk_02 & 0x20;
                n++;
            }
        }
    }
    data_0217b434->mUnk_04 = n;
}

void func_020ca54c(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b434, 0);
}

s32 func_020ca534(void) {
    return func_020c0c2c(&data_0217b430, 0x1ac);
}
