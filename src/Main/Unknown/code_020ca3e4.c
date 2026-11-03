#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020ca3e4.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02169000.h"

void func_020ca454(void) {
    s32 i;
    s32 n;
    u32 v;

    n = 0;
    v = func_020c0db0();
    for (i = 0; i < data_0217b430->mUnk_08; i++) {
        Unk0217b498_00 *p;

        p = data_0217b430->mUnk_00[i];
        if (!(p->mUnk_02 & 1)) {
            if (func_020b5ae8(&p->mUnk_04, &data_0217b430->mUnk_10[n].mUnk_00, v, 1, 1)) {
                data_0217b430->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(0x8a);
                data_0217b430->mUnk_10[n].mUnk_0c = 2;
                n++;
            }
        }
    }
    data_0217b430->mUnk_04 = n;
}

void func_020ca438(Unk020c06c4 *a) {
    func_020c092c(a, data_0217b430, 0);
}

s32 func_020ca3e4(void) {
    s32 a;
    s32 i;

    a = 0;
    for (i = 0; i < 10; i++) {
        a += data_0217bc34[data_021696c0[i]].mUnk_0c;
    }
    return func_020c0ba8(&data_0217b42c, a);
}
