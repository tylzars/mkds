#include "Main/Unknown/code_02035c50.h"
#include "Main/Unknown/code_0202db04.h"
#include "Main/Unknown/code_0202dd9c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/unk_02174000.h"

#pragma thumb on

void func_02035c50(s32 a, s32 b, s32 c, s32 d) {
    Unk02174e14_00 *s;
    s32 i;
    s32 v;
    s32 e;
    u8 x[4];
    s16 w[12];

    s = &data_02174e68->mUnk_2c[1];
    if (a == 1) {
        c += func_0202ddb0();
        func_0212426c(1, b, s->mUnk_14, func_020b3f7c(data_02174e68->mUnk_88, func_02025d74(func_0202db04(c))),
                      s->mUnk_0c, s->mUnk_18);
        func_0202dcf4(c, x);
        func_02025cd0(w, x[2], x[3], *(u16 *) x);
        func_02124224(1, b + 7, s->mUnk_14, w, s->mUnk_0c, s->mUnk_18, 7);
    } else if (a == 0) {
        for (i = 0; i < 7; i++) {
            e = i + 7;
            if (i == d) {
                v = 14;
            } else {
                v = 15;
            }
            func_02124100(i, (u8) v, s->mUnk_14, s->mUnk_18, s->mUnk_0c);
            func_02124100(e, (u8) v, s->mUnk_14, s->mUnk_18, s->mUnk_0c);
        }
    }
}

#pragma thumb off
