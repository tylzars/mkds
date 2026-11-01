#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_021281b4.h"
#include "Main/Unknown/code_02127a84.h"
#include "Main/Unknown/code_02127a38.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02016468.h"
#include "code_0214a390.h"

#pragma thumb on

void func_021279a0(void) {
    if (data_0217d3f4->mUnk_00 != 0) {
        data_0217d3f4->mUnk_04 = data_0217d3f4->mUnk_08;
        switch (data_0217d3f4->mUnk_04) {
            case 0:
                func_02127c78();
                break;
            case 1:
                func_02127a84();
                break;
            case 2:
                func_02127a38();
                break;
        }
        data_0217d3f4->mUnk_10++;
        if ((data_0217d3f4->mUnk_14 != 0 && data_0217d3f4->mUnk_10 > 0x1e) ||
            (data_0217d3f4->mUnk_14 == 0 && data_0217d3f4->mUnk_10 > 0x14)) {
            data_0217d3f4->mUnk_14 = data_0217d3f4->mUnk_14 == 0;
            data_0217d3f4->mUnk_10 = 0;
            func_02127e30();
            if (*(vu16 *) 0x27ffc40 != 2) {
                func_02016468(0x18, 0, data_0217d3f4->mUnk_2c, 0x800);
            }
        }
    }
}

void func_021278f4(void) {
    u32 a;

    if (data_0217d3f4->mUnk_00 != 0) {
        *(vu32 *) 0x4001010 = 0;
        if (data_0217d3f4->mUnk_04 == 0 || data_0217d3f4->mUnk_8a4 == 0) {
            func_0214a390((u16 *) 0x4001050, 0x1e, 0x1f, 6, 10, 0);
            a = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
            *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | ((a & ~1) << 8);
        } else {
            func_0214a390((u16 *) 0x4001050, 0x1e, 0x1f, 6, 10, -10);
            a = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
            *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | ((a | 1) << 8);
        }
    }
}

void func_021278c8(void) {
    if ((data_0217d3f4->mUnk_04 == 0 && data_0217d3f4->mUnk_24 != 0) || data_0217d3f4->mUnk_04 == 1) {
        data_0217d3f4->mUnk_28 = 1;
    } else {
        data_0217d3f4->mUnk_28 = 0;
    }
    data_0217d3f4->mUnk_24 = 1;
}

void func_021277f8(void *param_1, void *param_2, s32 param_3) {
    Unk0217d3f0_2098 *p;

    p = &data_0217d3f4->mUnk_834[0];
    p->mUnk_18(p, 5);
    p = &data_0217d3f4->mUnk_834[1];
    p->mUnk_18(p, 5);
    func_0212583c(&data_0217d3f4->mUnk_874[0], 0x28, 0, 0xd8, 0x10, 0xc, 0x480, 1, param_1);
    func_0212583c(&data_0217d3f4->mUnk_874[1], 0x28, 0, 0xd8, 0x10, 0xc, 0x480, 1, param_2);
    func_021281b4();
    data_0217d3f4->mUnk_8a0 = 1;
    func_021278c8();
    if (param_3 == 0) {
        data_0217d3f4->mUnk_18 = 0;
    } else {
        data_0217d3f4->mUnk_18 = 1;
    }
    func_02127d74();
    data_0217d3f4->mUnk_1c = 0;
    data_0217d3f4->mUnk_10 = 0;
    data_0217d3f4->mUnk_14 = 1;
}

void func_021277e4(void) {
    data_0217d3f4->mUnk_24 = 0;
    data_0217d3f4->mUnk_28 = 1;
}

u32 func_021277c8(void) {
    u32 r;

    r = 0;
    if (data_0217d3f4->mUnk_04 == 1 && data_0217d3f4->mUnk_28 == 0) {
        r = 1;
    }
    return r;
}

s32 func_021277ac(void) {
    s32 r;

    r = 0;
    if (data_0217d3f4->mUnk_04 == 0 && data_0217d3f4->mUnk_24 == 0) {
        r = 1;
    }
    return r;
}
#pragma thumb off
