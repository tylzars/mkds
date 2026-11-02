#include "Main/Unknown/code_020071b4.h"
#include "Main/Unknown/unk_0216f000.h"

#pragma thumb on

u32 func_020072c0(void) {
    Unk020074d8_msg v1;
    Unk020072c0_buf v2;
    u8 v11;
    u8 v14;
    Unk0216fdac *v3;
    Unk0216fdac *v4;
    Unk0200adfc *v5;
    Unk0200adfc_30 *v6;
    s32 i;
    Unk0200adfc_30 *v7;
    u8 *v9;
    u32 v10;
    Unk02007478 *v8;
    Unk0216fdac *v12;
    Unk0216fdac *v13;
    v12 = data_0216fdac;
    if (v12->mUnk_1524 == 0) {
        return 21;
    }
    v11 = 0;
    do {
        v3 = data_0216fdac;
        v3->mUnk_1525 = (v3->mUnk_1525 + 1) % 16;
        v13 = (Unk0216fdac *) *(u32 *) &data_0216fdac;
        v4 = (Unk0216fdac *) ((u8 *) v13 + v13->mUnk_1525 * 0x5d4);
        if (v4->mUnk_1d52 != 0 && v4->mUnk_1d4c != 0) {
            break;
        }
        v11++;
    } while (v11 < 16);
    if (v11 == 16) {
        return 21;
    }
    func_02007154(v13->mUnk_1525);
    v3 = data_0216fdac;
    v4 = (Unk0216fdac *) ((u8 *) v3 + v3->mUnk_1525 * 0x5d4);
    if (func_0200806c(&v2, v3->mUnk_1d2c + v3->mUnk_1525 * 0x5d4, v4->mUnk_1d48,
                      v3->mUnk_1788 + v3->mUnk_1525 * 0x5d4) == 0) {
        return 21;
    }
    v1.mUnk_00 = 4;
    v3 = data_0216fdac;
    v1.mUnk_02 = v3->mUnk_1525;
    v1.mUnk_04 = ((Unk0216fdac *) ((u8 *) v3 + v3->mUnk_1525 * 0x5d4))->mUnk_1d48;
    v9 = func_0200c3a4((u8 *) &v1, (u8 *) v3);
    v14 = v2.mUnk_0c;
    v3 = data_0216fdac;
    v10 = v2.mUnk_08 - ((u32 *) ((Unk0216fdac *) ((u8 *) v3 + v3->mUnk_1525 * 0x5d4))->mUnk_1d2c)[v14] +
          ((Unk0216fdac *) ((u8 *) v3 + v3->mUnk_1525 * 0x5d4))->mUnk_1d58[v14];
    v4 = (Unk0216fdac *) ((u8 *) v3 + v3->mUnk_1525 * 0x5d4);
    v5 = v4->mUnk_1d54;
    if (func_0200adfc(v5, v10, v9, v2.mUnk_04) == 0) {
        v8 = (Unk02007478 *) data_0216fdac->mUnk_7ce0;
        if (func_0200aff8(&v8->mUnk_00) == 0) {
            if (v5->mUnk_00 != 0) {
                v7 = v5->mUnk_30;
                v6 = NULL;
                for (i = 0; i < 4; v7++, i++) {
                    if (v7->mUnk_0c == 2) {
                        if (v6 == NULL || v6->mUnk_00 > v7->mUnk_00) {
                            v6 = v7;
                        }
                    }
                }
                if (v6 == NULL) {
                    func_0200fd1c();
                }
                v5->mUnk_00 = 0;
                v6->mUnk_0c = 1;
                v6->mUnk_00 = v10 & ~0x1f;
                v8->mUnk_10 = v6;
                v8->mUnk_14 = v5;
                func_0200aeec(&v8->mUnk_00, (void *) func_02007478, NULL, 4);
            }
        }
        return 21;
    }
    v3 = data_0216fdac;
    return func_02008908(v2.mUnk_04 + 6, ((Unk0216fdac *) ((u8 *) v3 + v3->mUnk_1525 * 0x5d4))->mUnk_1d4c, (u32) v3);
}

int func_020071b4(void) {
    u16 v1[6];
    u16 i;
    int v2;
    Unk0216fdac *v3;
    v1[0] = 0;
    func_0214cfe4(v1[0], &v1[1], 10);
    i = 1;
    v3 = data_0216fdac;
    for (; i <= 15; i++) {
        switch (v3->mUnk_14e8[i - 1]) {
            case 2:
                v1[1] |= 1 << i;
                break;
            case 5:
                v1[2] |= 1 << i;
                break;
            case 4:
                v1[3] |= 1 << i;
                break;
            case 8:
                v1[4] |= 1 << i;
                break;
            case 11:
                v1[5] |= 1 << i;
                break;
        }
    }
    if (v1[4] != 0) {
        v2 = func_020075f8(5, v1[4]);
    } else if (v1[1] != 0) {
        v2 = func_020075f8(1, v1[1]);
    } else if (v1[5] != 0) {
        v2 = func_020075f8(6, v1[5]);
    } else if (v1[3] != 0) {
        v2 = func_020075f8(2, v1[3]);
    } else if (v1[2] != 0) {
        v2 = func_020074d8();
    } else {
        v2 = func_020072c0();
    }
    if (v2 == 21) {
        v2 = func_020075f8(0, 0xffff);
    }
    return v2;
}

#pragma thumb off
