#include "00/code_021ae048.h"
#include "00/code_021a9aa0.h"
#include "00/code_021a9228.h"
#include "00/code_021adbac.h"
#include "code_0200f5ac.h"

void func_ov000_021ae094(void) {
    Unk021a998c *s;

    s = *(Unk021a998c **) data_0216ff5c.mUnk_04->mUnk_a4;
    if (s != NULL) {
        if (s->mUnk_09 != 0) {
            func_ov000_021a9228(s);
        } else {
            func_ov000_021ae0c4(s);
        }
    }
}

void func_ov000_021ae048(void) {
    Unk021a998c *s;
    s32 t;

    s = *(Unk021a998c **) data_0216ff5c.mUnk_04->mUnk_a4;
    if (s != NULL) {
        t = func_0200f5ac() >> 16;
        while (data_ov000_021b6388() != 0 && s->mUnk_08 != 0 && (s32) (func_0200f5ac() >> 16) - t < 0x27) {
            func_ov000_021b04d4();
        }
    }
}
