#include "code_02016468.h"

#include "code_02016574.h"
#include "code_020165d8.h"
#include "code_02016638.h"
#include "code_020165b8.h"
#include "Main/Unknown/unk_02173000.h"
#include "code_0201661c.h"

Unk02016468 data_02173220;

void func_02016554(void *arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value12;
    value2 = (u32) &data_02173220;
    value12 = (u32) &func_0201661c;
    *(u32 *) ((value2) + (0)) = value0;
    value0 = value2;
    *(u32 *) ((value2) + (4)) = value1;
    func_0201661c(value0);
}

void func_020164e8(void) {
    Unk02016468 *p;
    Unk02016638 *e;

    p = &data_02173220;
    e = func_020165c8(p);
    while (func_02016574(p) != 0) {
        func_02016638(e);
        p->mUnk_10 -= e->mUnk_0c;
        e = func_020165c8(p);
    }
}

s32 func_02016468(u32 a, u32 b, void *c, u32 d) {
    Unk02016468 *p;
    Unk02016638 *e;

    p = &data_02173220;
    if (func_02016960(p) != 0) {
        return 0;
    }
    e = func_020165b8((u32) p);
    e->mUnk_00 = a;
    e->mUnk_04 = (u32) c;
    e->mUnk_08 = b;
    e->mUnk_0c = d;
    func_020165d8(p);
    p->mUnk_10 = p->mUnk_10 + e->mUnk_0c;
    return 1;
}
