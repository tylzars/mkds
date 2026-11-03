#include "00/code_021ab548.h"
#include "00/code_021a998c.h"
#include "00/types_021a998c.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_02139f70.h"

void func_ov000_021ab594(u32 a, u32 b) {
    Unk021a998c *v1;
    Unk021a998c_0c *v2;
    v1 = *(Unk021a998c **) data_0216ff5c.mUnk_04->mUnk_a4;
    if ((v1 != NULL) && (v2 = v1->mUnk_0c, v2 != NULL)) {
        v2->mUnk_7e8 = a;
        v2->mUnk_7ec = b;
    }
}

u32 func_ov000_021ab548(Unk021a998c_0c *a, const s8 *b) {
    int v1;
    int v2;
    u32 *v3;
    u32 *v4;
    int v5;
    v2 = 0;
    v1 = a->mUnk_7ec;
    if (0 < v1) {
        v4 = (u32 *) a->mUnk_7e8;
        v3 = v4;
        do {
            v5 = strcmp((const u8 *) (*(u32 *) *v3), (const u8 *) b);
            if (v5 == 0) {
                return v4[v2];
            }
            v3 = v3 + 1;
            v2 = v2 + 1;
        } while (v2 < v1);
    }
    return 0;
}
