#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_02128244.h"
#include "Main/Unknown/code_021285b0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02128570.h"
#include "Main/Unknown/unk_0217d068.h"

#pragma thumb on
void func_02128508(void) {
    Unk0217d3f8 *p;
    p = data_0217d3f8;
    p->mUnk_81c = data_0215d0b4[p->mUnk_0c];
    data_0217d3f8->mUnk_0c++;
    p = data_0217d3f8;
    if (p->mUnk_0c >= 9) {
        if (p->mUnk_818 != 0) {
            p->mUnk_08 = 4;
            func_02128624(0);
        } else {
            p->mUnk_08 = 2;
            func_02128624(1);
        }
        data_0217d3f8->mUnk_0c = 0;
        data_0217d3f8->mUnk_814 = 0;
    }
}

void func_021284c0(void) {
    Unk0217d3f8 *p;
    data_0217d3f8->mUnk_81c = func_02128244(data_0217d3f8->mUnk_0c);
    data_0217d3f8->mUnk_0c++;
    p = data_0217d3f8;
    if (p->mUnk_0c >= 10) {
        p->mUnk_08 = 0;
        data_0217d3f8->mUnk_0c = 0;
        data_0217d3f8->mUnk_818 = 0;
    }
}

void func_02128458(void) {
    Unk0217d3f8 *p;
    p = data_0217d3f8;
    if (p->mUnk_00 != 0) {
        p->mUnk_04 = p->mUnk_08;
        switch (data_0217d3f8->mUnk_04) {
            case 0:
                func_021285f8();
                break;
            case 1:
                func_021285b0();
                break;
            case 2:
                func_02128570();
                break;
            case 3:
                func_02128508();
                break;
            case 4:
                func_021284c0();
                break;
        }
    }
}

void func_021283bc(void) {
    Unk0217d3f8 *p;
    u32 t;
    p = data_0217d3f8;
    if (p->mUnk_00 != 0) {
        if (p->mUnk_820 != 0) {
            if (((*(vu32 *) 0x4001000 & 0x1f00) >> 8 & 4) == 0) {
                t = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
                *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | ((t | 4) << 8);
            }
        } else {
            if (((*(vu32 *) 0x4001000 & 0x1f00) >> 8 & 4) != 0) {
                t = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
                *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | ((t & ~4) << 8);
            }
        }
        *(vu32 *) 0x4001018 = (data_0217d3f8->mUnk_81c << 16) & 0x1ff0000;
    }
}

void func_02128374(void) {
    if (func_02128294() != 0) {
        data_0217d3f8->mUnk_810 = 0;
    } else {
        data_0217d3f8->mUnk_810 = 1;
    }
    data_0217d3f8->mUnk_814 = 0;
    data_0217d3f8->mUnk_818 = 0;
}

void func_02128310(s32 a) {
    s32 v;
    data_0217d3f8->mUnk_810 = 0;
    data_0217d3f8->mUnk_814 = 1;
    if (a != 0) {
        data_0217d3f8->mUnk_818 = 1;
    } else {
        data_0217d3f8->mUnk_818 = 0;
    }
    v = data_0217d3f8->mUnk_824;
    if (v != -1) {
        func_0212ecc0(&data_0217d068, 0, (u16) v);
    }
}

void func_021282c8(void) {
    if (func_02128274() != 0) {
        data_0217d3f8->mUnk_818 = 0;
    } else {
        data_0217d3f8->mUnk_818 = 1;
    }
    data_0217d3f8->mUnk_810 = 0;
    data_0217d3f8->mUnk_814 = 0;
}

s32 func_02128294(void) {
    s32 r;
    s32 t;
    Unk0217d3f8 *p;
    r = 0;
    t = 0;
    p = data_0217d3f8;
    if (p->mUnk_04 == 2 && p->mUnk_818 == 0) {
        t = 1;
    }
    if (t != 0) {
        if (p->mUnk_814 == 0) {
            r = 1;
        }
    }
    return r;
}

s32 func_02128274(void) {
    s32 r;
    Unk0217d3f8 *p;
    r = 0;
    p = data_0217d3f8;
    if (p->mUnk_04 == 0 && p->mUnk_810 == 0) {
        r = 1;
    }
    return r;
}
#pragma thumb off
