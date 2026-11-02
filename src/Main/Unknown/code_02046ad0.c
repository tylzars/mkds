#include "Main/Unknown/code_02046ad0.h"

#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_02037a04.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/unk_02154000.h"

void func_02046bcc(void *b, u16 c) {
    Unk02046b40 *a;

    a = b;
    a->mUnk_04 = 0;
    a->mUnk_12 = 1;
    a->mUnk_0e = c;
    a->mUnk_10 = c;
}

void func_02046b40(void *b) {
    Unk02046b40 *a;
    Unk02046b40_00 *e;

    a = b;
    if (a->mUnk_12 != 0) {
        a->mUnk_04 = 0;
        a->mUnk_12 = 0;
        a->mUnk_0e = a->mUnk_10;
        a->mUnk_10 = 0;
        e = &a->mUnk_00[a->mUnk_0e];
        if (e->mUnk_00 != 0) {
            e->mUnk_00(a->mUnk_08);
        }
    } else {
        e = &a->mUnk_00[a->mUnk_0e];
    }
    if (e->mUnk_04 != 0) {
        e->mUnk_04(a->mUnk_08);
    }
    a->mUnk_04++;
}

void func_02046ae4(void) {
    u8 *p;

    p = func_02038d88(func_020364e0(func_020364e8()), data_usa_02154868);
    func_02038d28(p + 0x28, 0, 0, 0, 0, 4, 0, 0);
    func_02037abc(p);
}

void func_02046ad8(void) {
    func_020446e0();
}

u32 func_02046ad4(u32 p0) {
    return p0;
}

u32 func_02046ad0(u32 p0) {
    return p0;
}
