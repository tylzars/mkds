#include "Main/Unknown/code_02094e1c.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020cee0c.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020ceeec.h"
#include "Main/Unknown/code_02095000.h"
#include "Main/Unknown/code_02133000.h"

#pragma optimize_for_size on

#pragma thumb on
void func_020cee5c(void) {
    s32 a[8];
    s32 n;
    s32 i;
    s32 j;
    s32 k;
    Unk020f41c4_B *p;

    n = 8;
    if (data_0217b488->mUnk_12c == 0) {
        if (func_020cef08() == 1 || func_020cef08() == 2) {
            p = func_020ceeec();
            for (i = 0; i < 8; i++) {
                a[i] = i;
            }
            for (i = 0; i < 8; i++) {
                j = (func_020951b4(p) >> 8) % n;
                data_0217b488->mUnk_10c[i] = a[j];
                n--;
                for (k = j; k < n; k++) {
                    a[k] = a[k + 1];
                }
            }
            data_0217b488->mUnk_12c = 1;
        }
    }
}

void func_020cee28(void) {
    s32 i;
    BOOL v;

    v = FALSE;
    for (i = 0; i < 8; i++) {
        data_0217b488->mUnk_10c[i] = v;
    }
    data_0217b488->mUnk_12c = v;
}
#pragma thumb off

s32 func_020cee0c(void) {
    return func_020c0c2c(&data_0217b484, 0x1ab);
}
