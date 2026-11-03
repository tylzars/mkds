#include "Main/Unknown/code_020562b4.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void func_020562e8(void) {
    u8 i;
    u8 j;
    u8 v;
    u8 *p;
    Unk0217aa00_45c *e;

    func_020562b4();
    for (i = 0; i < 8; i++) {
        if ((data_0217aa00->mUnk_15f6 & (1 << i)) != 0) {
            for (j = 0; j < 4; j++) {
                e = &data_0217aa00->mUnk_045c[i];
                p = &e->mUnk_224[j];
                if (i == 0) {
                    data_0217aa08->mUnk_30[j] = *p;
                    data_0217aa08->mUnk_34[j] = *p;
                } else {
                    data_0217aa08->mUnk_30[j] &= *p;
                    data_0217aa08->mUnk_34[j] |= *p;
                }
            }
            e = &data_0217aa00->mUnk_045c[i];
            v = func_02056dac(e->mUnk_224);
            if (i == 0) {
                data_0217aa08->mUnk_38 = v;
                data_0217aa08->mUnk_39 = v;
            } else {
                if (v > data_0217aa08->mUnk_38) {
                    data_0217aa08->mUnk_38 = v;
                }
                if (v < data_0217aa08->mUnk_39) {
                    data_0217aa08->mUnk_39 = v;
                }
            }
        }
    }
}

void func_020562b4(void) {
    u8 i;

    for (i = 0; i < 4; i++) {
        data_0217aa08->mUnk_30[i] = 0;
        data_0217aa08->mUnk_34[i] = 0;
    }
    data_0217aa08->mUnk_38 = 0;
    data_0217aa08->mUnk_39 = 0;
}
#pragma thumb off
