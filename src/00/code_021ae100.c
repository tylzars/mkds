#include "00/code_021ae100.h"
#include "00/code_021a9228.h"
#include "Main/Unknown/unk_0216f000.h"

u32 func_ov000_021ae100(u16 *a, u32 *b) {
    Unk021a998c *v1;
    v1 = *(Unk021a998c **) data_0216ff5c.mUnk_04->mUnk_a4;
    if ((v1 != NULL) && ((v1->mState == 4 || (v1->mState == '\n')))) {
        if (a != NULL) {
            *a = v1->mUnk_18;
        }
        if (b != NULL) {
            *b = v1->mUnk_14;
        }
        return v1->mUnk_1c;
    }
    return 0;
}
