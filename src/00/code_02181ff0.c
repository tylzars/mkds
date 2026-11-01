#include "00/code_02181ff0.h"

void func_ov000_02182270(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 v;

    v = data_ov000_021b4c70->mUnk_104c->mUnk_06;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_ov000_021b0600[i]; j++) {
            data_ov000_021b4c70->mUnk_103c[data_ov000_021b060c[i][j]].mUnk_04 = data_ov000_021b4c70->mUnk_14[i][0];
            data_ov000_021b4c70->mUnk_103c[data_ov000_021b060c[i][j]].mUnk_06 = data_ov000_021b4c70->mUnk_14[i][1];
        }
    }
    for (i = 0; i < 3; i++) {
        (data_ov000_021b4c70->mUnk_103c + v)[data_ov000_021b05e8[i]].mUnk_04 = data_ov000_021b4c70->mUnk_14[i][0];
        (data_ov000_021b4c70->mUnk_103c + v)[data_ov000_021b05e8[i]].mUnk_06 = data_ov000_021b4c70->mUnk_14[i][1];
    }
    for (k = 0; k < 3; k++) {
        (data_ov000_021b4c70->mUnk_103c + v)[1].mUnk_04 = data_ov000_021b4c70->mUnk_14[1][0];
        (data_ov000_021b4c70->mUnk_103c + v)[1].mUnk_06 = data_ov000_021b4c70->mUnk_14[1][1];
    }
    for (i = 0; i < 3; i++) {
        data_ov000_021b4c70->mUnk_103c[data_ov000_021b05f8[i][0]].mUnk_04 -=
            func_020adc64(6 - data_ov000_021b4c70->mUnk_2c);
        data_ov000_021b4c70->mUnk_103c[data_ov000_021b05f8[i][1]].mUnk_04 +=
            func_020adc64(6 - data_ov000_021b4c70->mUnk_30);
    }
}

void func_ov000_021821e0(void) {
    s32 i;
    s32 z = 0;

    for (i = 0; i < 3; i++) {
        if (i == data_ov000_021b4c70->mUnk_08 && data_ov000_021b4c70->mUnk_24 != 0) {
            data_ov000_021b4c70->mUnk_103c[data_ov000_021b060c[i][1]].mUnk_00 = 1;
            func_02124100(data_ov000_021b05e8[i], 14, data_ov000_021b4c70->mUnk_1054, data_ov000_021b4c70->mUnk_103c,
                          data_ov000_021b4c70->mUnk_104c);
        } else {
            data_ov000_021b4c70->mUnk_103c[data_ov000_021b060c[i][1]].mUnk_00 = z;
            func_02124100(data_ov000_021b05e8[i], 15, data_ov000_021b4c70->mUnk_1054, data_ov000_021b4c70->mUnk_103c,
                          data_ov000_021b4c70->mUnk_104c);
        }
    }
}

void func_ov000_02182150(void) {
    s32 i;
    s32 z = 0;
    s32 y = 0;

    for (i = 0; i < 2; i++) {
        if (data_ov000_021b4c70->mUnk_08 == 1) {
            if ((&data_ov000_021b4c70->mUnk_2c)[i] > 0) {
                data_ov000_021b4c70->mUnk_103c[data_ov000_021b05f8[0][i]].mUnk_00 = 1;
                data_ov000_021b4c70->mUnk_103c[data_ov000_021b05f8[1][i]].mUnk_00 = 1;
                (&data_ov000_021b4c70->mUnk_2c)[i]--;
            } else {
                data_ov000_021b4c70->mUnk_103c[data_ov000_021b05f8[0][i]].mUnk_00 = y;
                data_ov000_021b4c70->mUnk_103c[data_ov000_021b05f8[1][i]].mUnk_00 = 1;
            }
        } else {
            data_ov000_021b4c70->mUnk_103c[data_ov000_021b05f8[0][i]].mUnk_00 = z;
            data_ov000_021b4c70->mUnk_103c[data_ov000_021b05f8[1][i]].mUnk_00 = z;
        }
    }
}

void func_ov000_02182084(void) {
    data_ov000_021b4c70->mUnk_00 = data_ov000_021b4c70->mUnk_04;
    switch (data_ov000_021b4c70->mUnk_00) {
        case 0:
            func_ov000_02182d74();
            break;
        case 1:
            func_ov000_02182d28();
            break;
        case 2:
            func_ov000_02182cb8();
            break;
        case 3:
            func_ov000_02182c60();
            break;
        case 4:
            func_ov000_021828e4();
            break;
        case 5:
            func_ov000_02182878();
            break;
        case 6:
            func_ov000_02182688();
            break;
        case 7:
            func_ov000_021825b8();
            break;
        case 8:
            func_ov000_021824e8();
            break;
        case 9:
            func_ov000_02182474();
            break;
        case 10:
            func_ov000_021823e4();
            break;
        case 11:
            func_ov000_021823b0();
            break;
    }
    func_0212b80c();
    func_ov000_02182270();
    func_ov000_021821e0();
    func_ov000_02182150();
    func_02124c30(data_ov000_021b4c70->mUnk_104c, data_ov000_021b4c70->mUnk_1040, data_ov000_021b4c70->mUnk_1054,
                  func_ov000_021804e0(), data_ov000_021b4c70->mUnk_103c);
}

void func_ov000_02181ff0(void) {
    u32 a;
    u32 b;
    s32 v;

    a = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
    a |= 4;
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | (a << 8);
    b = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    b |= 9;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | (b << 8);
    func_0214a40c((u32 *) 0x4000050, 0, 2, 6, 10);
    v = -data_ov000_021b4c70->mUnk_14[1][0];
    if (v <= -256) {
        v = -256;
    }
    if (v >= 0x100) {
        v = 0x100;
    }
    *(vu32 *) 0x400101c = v & 0x1ff;
}
