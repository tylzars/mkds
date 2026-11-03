#include "00/code_021ae958.h"
#include "00/code_021a998c.h"

void func_ov000_021ae958(const Unk021ae3f0 *a, const Unk021ae87c *b) {
    Unk021a998c *p;

    p = func_ov000_021af090(a, b);
    if (p != NULL) {
        func_0200dd94();
        p->mState = 0;
        if (p->mUnk_04 - 1 <= 1) {
            p->mUnk_04 = 0;
            func_0200df68(p->mThread);
        }
    }
}
