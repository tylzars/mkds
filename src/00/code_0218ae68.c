#include "00/code_0218ae68.h"
#include "00/code_0218a9bc.h"

u32 func_ov000_0218ae68(Unk0218ae68 *a, SbServer *b) {
    SbServer *d;
    SbServer *c;
    c = NULL;
    d = a->mUnk_00;
    while (d != NULL) {
        if (d == b) {
            if (c != NULL) {
                c->mUnk_20 = d->mUnk_20;
            }
            if (a->mUnk_00 == d) {
                a->mUnk_00 = d->mUnk_20;
            }
            if (a->mUnk_04 == d) {
                a->mUnk_04 = c;
            }
            a->mUnk_08--;
            return 1;
        }
        c = d;
        d = d->mUnk_20;
    }
    return 0;
}
