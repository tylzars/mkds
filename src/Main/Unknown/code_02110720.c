#include "Main/Unknown/code_02110720.h"
#include "Main/Unknown/code_021108bc.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212c478.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_021059e0.h"

void func_02110874(void) {
    s32 a;
    a = data_0217d1f4;
    if (a == 7) {
        a = 6;
    }
    func_021108bc(a);
    data_0217d1f4 = 7;
}

void func_02110838(void) {
    s32 i;
    i = 0;
    data_0217d2a4.mUnk_78 = i;
    data_0217d2a4.mUnk_70 = i;
    data_0217d2a4.mUnk_74 = i;
    for (i = 0; i < 14; i++) {
        data_0217d2a4.mUnk_00[i] = 13;
        data_0217d2a4.mUnk_38[i] = 2;
    }
}

void func_02110754(void) {
    Unk0217d2a4 *p = &data_0217d2a4;
    s32 i;
    s32 v;
    s32 w;
    s32 t;
    u32 x;
    if (p->mUnk_78 == 0) {
        i = p->mUnk_74;
        v = p->mUnk_00[i];
        if (v != 13) {
            w = p->mUnk_38[i];
            t = 3;
            if (v == 12) {
                if (w == 0) {
                    x = 0x47;
                } else {
                    x = 0x48;
                }
                t = 0;
            } else {
                x = (u16) (w + v * 2);
            }
            func_0212ecc0(&data_0217d068, t, x);
            if (data_0217d068 != 0) {
                func_02105b28(&data_0217d068, 0x3c);
            }
            data_0217d2a4.mUnk_00[p->mUnk_74] = 13;
            data_0217d2dc[p->mUnk_74] = 2;
            p->mUnk_78 = 0x19;
            p->mUnk_74 = p->mUnk_74 + 1;
            i = p->mUnk_74;
            if (i == 14) {
                i = 0;
            }
            p->mUnk_74 = i;
        }
    }
    if (p->mUnk_78 > 0) {
        p->mUnk_78 = p->mUnk_78 - 1;
    }
}

void func_02110720(u32 a, u32 b) {
    s32 i;
    s32 n;
    i = data_0217d2a4.mUnk_70;
    data_0217d2a4.mUnk_00[i] = a;
    n = i + 1;
    data_0217d2a4.mUnk_38[i] = b;
    if (n == 14) {
        n = 0;
    }
    data_0217d2a4.mUnk_70 = n;
}
