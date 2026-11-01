#include "Main/Unknown/code_020be950.h"
#include "Main/Unknown/code_020b1cf4.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020c8000.h"
#include "Main/Unknown/code_020c9000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_0217b000.h"

void func_020beb40(void) {
    s32 i;

    for (i = 0; i < data_0217b3dc->mUnk_00c; i++) {
        data_0217b3dc->mUnk_010[i]();
    }
    data_0217b3dc = 0;
}

void func_020be9d4(void) {
    Vec3 v;
    s32 i;
    s32 n;
    float f;

    switch (func_020b1dbc()) {
        case 0:
            func_020c97c0();
            break;
        case 1:
        case 2:
        case 3:
            if (func_020b1d50() * 3 > 0) {
                f = 0.5f + (float) (func_020b1d50() * 0x3000);
            } else {
                f = (float) (func_020b1d50() * 0x3000) - 0.5f;
            }
            n = (s32) f;
            data_0217b3dc->mUnk_004 = (s32) (((s64) n * 20) >> 12);
            data_0217b3dc->mUnk_008 = func_02147f34(0x2400, data_0217b3dc->mUnk_004);
            func_020b503c(func_020b1d34(), data_0217b3dc->mUnk_004);
            func_0207a91c(&v, func_020b4d9c());
            data_0217b3dc->mUnk_000 = func_020b4e70(&v) != 0 ? 0 : 3;
            for (i = 0; i < data_0217b3dc->mUnk_00c; i++) {
                data_0217b3dc->mUnk_0d4[i]();
            }
            break;
    }
}

void func_020be950(void *param_1) {
    s32 i;

    switch (func_020b1dbc()) {
        case 0:
            func_020c8dbc(param_1);
            break;
        case 1:
        case 2:
        case 3:
            for (i = 0; i < data_0217b3dc->mUnk_00c; i++) {
                data_0217b3dc->mUnk_198[i](param_1);
            }
            break;
    }
}
