#include "Main/Unknown/code_020d655c.h"
#include "Main/Unknown/code_020e6f58.h"

#include "Main/Unknown/code_020d6000.h"

#pragma thumb on
void func_020e6f58(Unk020e6fd4 *p, MapObject *q) {
    u16 n;
    MapObjectKindData *t;

    n = p->mUnk_04;
    p->mUnk_04 = n + 1;
    p->mUnk_00[n] = q;
    if (p->mUnk_18 == 3) {
        t = q->mKindData;
        p->mUnk_18 = t->mUnk_20;
    }
    if (p->mUnk_1c == NULL) {
        t = q->mKindData;
        p->mUnk_1c = t->mUnk_04;
    }
    if (p->mUnk_20 == 3) {
        p->mUnk_20 = func_020d6910(6, q);
    }
}
#pragma thumb off
