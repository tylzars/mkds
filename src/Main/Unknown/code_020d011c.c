#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020d011c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0d9c.h"

void func_020d0150(void) {
    s32 i;
    s32 n;
    u32 a;
    Unk0217b498_00 *e;
    Vec3 *p;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < data_0217b498->mUnk_08; i++) {
        e = data_0217b498->mUnk_00[i];
        p = &e->mUnk_04;
        if (func_020b5ae8(p, (UnkPair020b502c *) &data_0217b498->mUnk_10[n], a, 1, 1) == 0) {
            continue;
        }
        data_0217b498->mUnk_10[n].mUnk_08 = GetRaceSNcerEntry(0xb8);
        data_0217b498->mUnk_10[n].mUnk_0c = func_020b4e70(p) != 0 ? 2 : 3;
        data_0217b498->mUnk_10[n].mUnk_10 = e->mUnk_7e;
        data_0217b498->mUnk_0c[n].mUnk_00 = e->mUnk_1c / 6;
        n++;
    }
    data_0217b498->mUnk_04 = n;
}

void func_020d0134(void *a) {
    func_020c06c4(a, data_0217b498, 1);
}

s32 func_020d011c(void) {
    return func_020c0c2c(&data_0217b494, 0x1b4);
}
