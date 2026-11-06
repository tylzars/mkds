#include "Main/Unknown/code_02087934.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "registers.h"

void func_02087c9c(Unk02087d0c *a, s32 b, u16 c) {
    a->mUnk_00 = c == 0 ? UNK_02087CFC_KIND_0 : UNK_02087CFC_KIND_1;
    a->mUnk_02 = 0;
    a->mUnk_08 = 0x1000;
    a->mUnk_04 = b;
    a->mUnk_0c = 0;
    a->mUnk_10 = 0;
    a->mUnk_12 = 0;
}

void func_02087b9c(Unk02087d0c *a) {
    s32 c;
    switch (a->mUnk_00) {
        case 1:
            if (a->mUnk_0c >= a->mUnk_04) {
                a->mUnk_0c = a->mUnk_0c - a->mUnk_04;
            } else if (a->mUnk_0c <= 0) {
                c = a->mUnk_0c;
                a->mUnk_0c = a->mUnk_04 - 0x1000 + c;
            }
            break;
        case 0:
            if (a->mUnk_0c >= a->mUnk_04 - 0x1000) {
                a->mUnk_0c = a->mUnk_04 - 0x1000;
                a->mUnk_08 = 0;
                a->mUnk_02 = 1;
            }
            break;
        case 2:
            if (a->mUnk_10 >= a->mUnk_12) {
                return;
            }
            if (a->mUnk_0c >= a->mUnk_04) {
                a->mUnk_0c = a->mUnk_0c - a->mUnk_04;
                a->mUnk_10++;
            } else if (a->mUnk_0c <= 0) {
                c = a->mUnk_0c;
                a->mUnk_0c = a->mUnk_04 - 0x1000 + c;
                a->mUnk_10++;
            }
            if (a->mUnk_10 >= a->mUnk_12) {
                a->mUnk_0c = a->mUnk_04 - 0x1000;
                a->mUnk_08 = 0;
                a->mUnk_02 = 1;
            }
            break;
    }
}

void func_02087b78(Unk02087d0c *a) {
    a->mUnk_02 = 0;
    a->mUnk_0c = a->mUnk_0c + a->mUnk_08;
    func_02087b9c(a);
}

void func_02087ab0(s32 a, s32 b) {
    u32 x;
    reg_G3_TEXCOORD = 0;
    reg_G3_VTX_16 = data_02155a74[0] | data_02155a74[1] << 16;
    reg_G3_VTX_16 = data_02155a74[2];
    x = (u16) ((b << 8) >> 16);
    reg_G3_TEXCOORD = x << 16;
    reg_G3_VTX_16 = data_02155a74[3] | data_02155a74[4] << 16;
    reg_G3_VTX_16 = data_02155a74[5];
    reg_G3_TEXCOORD = (u16) ((a << 8) >> 16) | x << 16;
    reg_G3_VTX_16 = data_02155a74[6] | data_02155a74[7] << 16;
    reg_G3_VTX_16 = data_02155a74[8];
    reg_G3_TEXCOORD = (u16) ((a << 8) >> 16);
    reg_G3_VTX_16 = data_02155a74[9] | data_02155a74[10] << 16;
    reg_G3_VTX_16 = data_02155a74[11];
}

void func_020879e8(s32 a, s32 b) {
    u32 x;
    reg_G3_TEXCOORD = 0;
    reg_G3_VTX_16 = data_02155a74[0] | data_02155a74[1] << 16;
    reg_G3_VTX_16 = data_02155a74[2];
    x = (u16) ((b << 8) >> 16);
    reg_G3_TEXCOORD = x << 16;
    reg_G3_VTX_16 = data_02155a74[3] | data_02155a74[4] << 16;
    reg_G3_VTX_16 = data_02155a74[5];
    reg_G3_TEXCOORD = (u16) ((a << 8) >> 16) | x << 16;
    reg_G3_VTX_16 = data_02155a74[6] | data_02155a74[7] << 16;
    reg_G3_VTX_16 = data_02155a74[8];
    reg_G3_TEXCOORD = (u16) ((a << 8) >> 16);
    reg_G3_VTX_16 = data_02155a74[9] | data_02155a74[10] << 16;
    reg_G3_VTX_16 = data_02155a74[11];
}

void func_02087934(u32 a) {
    s32 x;
    s32 y;
    reg_G3_COLOR = a;
    x = data_021659b4;
    y = data_021659c0;
    reg_G3_MTX_SCALE = y;
    reg_G3_MTX_SCALE = x;
    reg_G3_MTX_SCALE = 0x1333;
    reg_G3_VTX_16 = data_02155a74[0] | data_02155a74[1] << 16;
    reg_G3_VTX_16 = data_02155a74[2];
    reg_G3_VTX_16 = data_02155a74[3] | data_02155a74[4] << 16;
    reg_G3_VTX_16 = data_02155a74[5];
    reg_G3_VTX_16 = data_02155a74[6] | data_02155a74[7] << 16;
    reg_G3_VTX_16 = data_02155a74[8];
    reg_G3_VTX_16 = data_02155a74[9] | data_02155a74[10] << 16;
    reg_G3_VTX_16 = data_02155a74[11];
}
