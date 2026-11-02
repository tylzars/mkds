#include "code_02017e70.h"

Unk02017e70 *func_02017e70(Unk02017ef8 *a, u16 b) {
    Unk02017e70 *p;

    p = (Unk02017e70 *) a->mUnk_00;
    p->mUnk_00 = b;
    p->mUnk_02 = 0;
    p->mUnk_04 = a->mUnk_04 - (u32) (p + 1);
    p->mUnk_08 = 0;
    p->mUnk_0c = 0;
    return p;
}
