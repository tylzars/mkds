#include "01/code_0219eab4.h"

#include "01/code_0219e000.h"
#include "01/code_0219f000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02105000.h"
#include "code_0201ea58.h"
#include "code_02148ca0.h"
#include "01/unk_021a9000.h"

void func_ov001_0219f85c(void) {
    Unk020b4934 *v1 = 0;
    Unk02021dc8 *v2 = 0;
    Unk020b4a44 *v3 = 0;
    Unk020b4934 *v4 = 0;
    Unk020b47d8 *v5 = 0;
    Unk020b4a44 *v6 = 0;

    LoadNcgrData(&v4, FindSceneFile(data_ov001_021a90a8));
    LoadNscrData(&v5, FindSceneFile(data_ov001_021a90e4));
    LoadNclrData(&v6, FindSceneFile(data_ov001_021a90cc));
    LoadNcgrData2(&v1, FindSceneFile(data_ov001_021a90d4));
    LoadNcerData(&v2, FindSceneFile(data_ov001_021a90c4));
    LoadNclrData(&v3, FindSceneFile(data_ov001_021a90c0));
}

void func_ov001_0219f6e0(void) {
    Unk020b4934 *v1 = 0;
    Unk020b4a44 *v2 = 0;
    Unk020b4934 *v3 = 0;
    Unk020b47d8 *v4 = 0;
    Unk020b4a44 *v5 = 0;

    LocateNcgr(&v3, FindSceneFile(data_ov001_021a90a8));
    LocateNscr(&v4, FindSceneFile(data_ov001_021a90e4));
    LocateNclr(&v5, FindSceneFile(data_ov001_021a90cc));
    if (data_ov001_021ca410->mUnk_4a >= 6) {
        data_ov001_021ca410->mUnk_04 = FindSceneFile(data_ov001_021a90dc);
        data_ov001_021ca410->mUnk_08 = FindSceneFile(data_ov001_021a90b8);
        data_ov001_021ca410->mUnk_0c = FindSceneFile(data_ov001_021a90bc);
    } else {
        data_ov001_021ca410->mUnk_04 = FindSceneFile(data_ov001_021a90c8);
        data_ov001_021ca410->mUnk_08 = FindSceneFile(data_ov001_021a90a4);
        data_ov001_021ca410->mUnk_0c = FindSceneFile(data_ov001_021a90d8);
    }
    LocateNcgr2(&v1, FindSceneFile(data_ov001_021a90d4));
    LocateNcer(&data_ov001_021ca410->mUnk_00, FindSceneFile(data_ov001_021a90c4));
    LocateNclr(&v2, FindSceneFile(data_ov001_021a90c0));
    data_ov001_021ca410->mUnk_14 = func_02036bec(data_ov001_021ca410->mUnk_18, 0x800);
    func_02016468(4, 0, v3->mUnk_14, v3->mUnk_10);
    func_02016468(8, 0, v4->mUnk_0c, v4->mUnk_08);
    func_02016468(8, 0x800, data_ov001_021ca410->mUnk_14, 0x800);
    func_02016468(0xf, 0, v5->mUnk_0c, 0x40);
    func_02016468(0x23, 0, v1->mUnk_14, v1->mUnk_10);
    func_02016468(0x1e, 0, v2->mUnk_0c, v2->mUnk_08);
}

s32 func_ov001_0219f6a0(s16 a) {
    s32 i;
    s32 result;
    s32 out;
    u8 next;

    result = 8;
    i = 0;
    next = a + 1;

    for (; i < 9; i++) {
        if (func_0205fd78(next, (u8) (i + 1), &out)) {
            if (out < result) {
                result = out;
            }
        } else {
            result = 9;
        }
    }
    return result;
}

u32 func_ov001_0219f688(int a) {
    if (data_ov001_021ca410->mUnk_4a >= a) {
        return 1;
    }
    return 0;
}

void func_ov001_0219f4f8(void) {
    s32 i;
    u16 cnt;
    s32 r;
    cnt = data_ov001_021ca410->mUnk_04->mUnk_06;
    for (i = 0; i < 7; i++) {
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][0]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][1]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][2]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][3]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][4]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][5]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][6]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][7]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][8]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][9]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][10]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[cnt + data_ov001_021a6c60[i]].mUnk_00 = 0;
        if (func_ov001_0219f688((s16) i)) {
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][0]].mUnk_00 = 1;
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][1]].mUnk_00 = 1;
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][5]].mUnk_00 = 1;
            r = func_ov001_0219f6a0((s16) i);
            if (r <= 4) {
                data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][7]].mUnk_00 = 1;
                data_ov001_021ca410->mUnk_10[cnt + data_ov001_021a6c60[i]].mUnk_00 = 1;
                func_0212426c(1, data_ov001_021a6c60[i], data_ov001_021ca410->mUnk_0c, data_ov001_021a90e8[r],
                              data_ov001_021ca410->mUnk_04, data_ov001_021ca410->mUnk_10);
            } else if (r <= 7) {
                data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][r + 3]].mUnk_00 = 1;
            }
        } else if (i != 6) {
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][0]].mUnk_00 = 1;
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][4]].mUnk_00 = 1;
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][6]].mUnk_00 = 1;
        }
        func_02124a98(data_ov001_021a6ce0[i][0], 1, data_ov001_021ca410->mUnk_00, data_ov001_021ca410->mUnk_04);
    }
}

void func_ov001_0219f430(void) {
    s32 i;
    for (i = 0; i < 7; i++) {
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][1]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][2]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][3]].mUnk_00 = 0;
        data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][4]].mUnk_00 = 0;
        if (data_ov001_021ca410->mUnk_28[i] > 0) {
            data_ov001_021ca410->mUnk_28[i] = data_ov001_021ca410->mUnk_28[i] - 1;
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][3]].mUnk_00 = 1;
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][3]].mUnk_06 =
                data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][2]].mUnk_06 + 1;
        } else if (data_ov001_021ca410->mUnk_4c == i) {
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][2]].mUnk_00 = 1;
        } else if (func_ov001_0219f688((s16) i)) {
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][1]].mUnk_00 = 1;
        } else if (i != 6) {
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][4]].mUnk_00 = 1;
        }
    }
}

void func_ov001_0219f3a4(void) {
    s32 all = 1;
    s32 i = 0;
    s32 ok;
    s32 j;
    s32 out;
    u8 x;
    data_ov001_021ca410->mUnk_4a = 0;
    for (i = 0; i < 7; i++) {
        ok = 1;
        j = 0;
        x = i + 1;
        for (; j < 9; j++) {
            ok &= func_0205fd78(x, (u8) (j + 1), &out);
            if (!ok || out < 5) {
                all = 0;
            }
        }
        if (ok) {
            if (i == 5) {
                if (all) {
                    data_ov001_021ca410->mUnk_4a = i + 1;
                }
            } else {
                data_ov001_021ca410->mUnk_4a = i + 1;
            }
        }
    }
}

void func_ov001_0219f37c(void) {
    func_0202948c((u32) ((data_ov001_021ca410->mUnk_4c + 1) * 0x1000000 >> 0x18));
    func_0202947c((u32) 1);
}

s32 func_ov001_0219f31c(void) {
    s32 i;
    s32 ok = 1;
    s32 result;
    s32 out;

    for (i = 0; i < 8; i++) {
        ok &= func_0205fd78((u8) (data_ov001_021ca410->mUnk_4c + 1), (u8) (i + 1), &out);
    }
    result = func_0205fd78((u8) (data_ov001_021ca410->mUnk_4c + 1), 9, &out);
    if (ok != 0 && result == 0) {
        return 1;
    }
    return 0;
}

void func_ov001_0219f2a4(void) {
    s32 i;
    s32 j;
    s32 count;

    count = data_ov001_021ca410->mUnk_04->mUnk_06;
    i = 0;
    data_ov001_021ca410->mUnk_20 = 0;
    data_ov001_021ca410->mUnk_24 = 0;
    data_ov001_021ca410->mUnk_44 = -192;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 11; j++) {
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][j]].mUnk_04 = 0x100;
        }
        data_ov001_021ca410->mUnk_10[count + data_ov001_021a6c60[i]].mUnk_04 = 0x100;
    }
}

void func_ov001_0219f260(void) {
    data_ov001_021ca410->mUnk_20 = 1;
    data_ov001_021ca410->mUnk_24 = 0;
    if (func_020cccb4() == 0x13) {
        data_ov001_021ca410->mUnk_48 = -256;
    } else {
        data_ov001_021ca410->mUnk_48 = 0x100;
    }
}

void func_ov001_0219f244(void) {
    data_ov001_021ca410->mUnk_20 = 2;
    data_ov001_021ca410->mUnk_24 = 0;
    func_02128374();
}

void func_ov001_0219f230(void) {
    data_ov001_021ca410->mUnk_20 = 3;
    data_ov001_021ca410->mUnk_24 = 0;
}

void func_ov001_0219f1f4(void) {
    data_ov001_021ca410->mUnk_20 = 4;
    data_ov001_021ca410->mUnk_24 = 0;
    data_ov001_021ca410->mUnk_48 = 0x100;
    func_ov001_0219f37c();
    func_0212ecc0(&data_0217d068, 0, 5);
}

void func_ov001_0219f198(void) {
    data_ov001_021ca410->mUnk_20 = 5;
    data_ov001_021ca410->mUnk_24 = 0;
    switch (data_ov001_021ca410->mUnk_58) {
        case 1:
            if (func_ov001_0219f31c() != 0) {
                func_02105980(3, 10);
            } else {
                func_02105980(0, 10);
            }
            break;
        case 2:
            func_02105980(4, 10);
            break;
    }
}

void func_ov001_0219f058(void *a, void *b, void *c) {
    s32 i;
    s32 remaining;

    *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & 0x43) | 0x9004;
    {
        void *heap = func_02036948(a);

        data_ov001_021ca410 = func_02036bec(heap, 0x5c);
        data_ov001_021ca410->mUnk_18 = heap;
    }
    data_ov001_021ca410->mUnk_1c = 0;
    data_ov001_021ca410->mUnk_50 = b;
    data_ov001_021ca410->mUnk_54 = c;
    data_ov001_021ca410->mUnk_58 = 0;
    for (i = 0; i < 7; i++) {
        data_ov001_021ca410->mUnk_28[i] = 0;
    }
    if (data_0217b488->mUnk_14 != 0) {
        data_ov001_021ca410->mUnk_4c = 6;
        data_0217b488->mUnk_14 = 0;
        func_02105a30(2);
    } else {
        data_ov001_021ca410->mUnk_4c = func_02029608() - 1;
        if (func_020cccb4() == 0x1f) {
            func_02105a30(1);
        } else {
            func_02105a30(0);
        }
    }
    func_ov001_0219f3a4();
    func_ov001_0219f6e0();
    func_020ae6d4(data_ov001_021ca410->mUnk_50, data_ov001_021ca410->mUnk_54);
    func_02124ed0(data_ov001_021ca410->mUnk_18, data_ov001_021ca410->mUnk_04, data_ov001_021ca410->mUnk_0c,
                  &data_ov001_021ca410->mUnk_10);
    remaining = func_02148ca0();
    for (i = 0; i < 7; i++) {
        remaining -= func_021243ac(data_ov001_021ca410->mUnk_18, data_ov001_021a6c60[i], data_ov001_021ca410->mUnk_0c,
                                   data_ov001_021a6c70[i], data_ov001_021a6c80[i], data_ov001_021a6ce0[i][7],
                                   data_ov001_021ca410->mUnk_00, data_ov001_021ca410->mUnk_04,
                                   data_ov001_021ca410->mUnk_10, remaining);
    }
    func_ov001_0219f4f8();
    func_ov001_0219f2a4();
    func_02036820((void *) data_ov001_021ca410->mUnk_18);
}

void func_ov001_0219efec(void) {
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | 0x1800;
    switch (data_ov001_021ca410->mUnk_58) {
        case 1:
            if (func_ov001_0219f31c() != 0) {
                func_02105980(3, 10);
            } else {
                func_02105980(0, 10);
            }
            break;
        case 2:
            func_0210593c(4);
            break;
    }
    func_02036ab0((void *) data_ov001_021ca410->mUnk_18);
    data_ov001_021ca410 = 0;
}

void func_ov001_0219efd0(void) {
    int v1;
    func_021059e0();
    v1 = func_02036c5c();
    if (v1 != 0) {
        func_ov001_0219f260();
    }
    return;
}

void func_ov001_0219ef24(void) {
    s32 i;
    s32 j;
    s32 count;
    s16 value;

    func_021059e0();
    count = data_ov001_021ca410->mUnk_04->mUnk_06;
    data_ov001_021ca410->mUnk_24 = data_ov001_021ca410->mUnk_24 + 1;
    value = func_020ae4c0(1, data_ov001_021ca410->mUnk_48, 0, data_ov001_021ca410->mUnk_24, 10);
    data_ov001_021ca410->mUnk_44 = func_020ae4c0(1, -192, 0, data_ov001_021ca410->mUnk_24, 10);
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 11; j++) {
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][j]].mUnk_04 = value;
        }
        data_ov001_021ca410->mUnk_10[count + data_ov001_021a6c60[i]].mUnk_04 = value;
    }
    if (data_ov001_021ca410->mUnk_24 >= 10) {
        func_ov001_0219f244();
    }
}

void func_ov001_0219ef08(void) {
    int v1;
    func_021059e0();
    v1 = func_02128294();
    if (v1 != 0) {
        func_ov001_0219f230();
    }
    return;
}

void func_ov001_0219ec38(void) {
    u32 sel = -1;
    Unk02175628Index i = UNK_02175628_INDEX_8;
    s32 f2;
    s32 f1;
    s16 n;

    func_021059e0();
    f2 = 0;
    f1 = 0;
    if (data_02175628[i].mUnk_4c == 0 && data_02175628[i].mUnk_58 < 5) {
        f1 = 1;
    }
    if (f1 == 0 && data_02175628[i].mUnk_54 == 0 && data_02175628[i].mUnk_4c != 0) {
        f2 = 1;
    }
    if (f2 != 0) {
        sel = func_0201ea84(data_ov001_021ca410->mUnk_08, data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a);
    }
    if ((u16) (data_02175628[i].mUnk_00 & 2) == 0) {
        s32 g2 = 0;
        s32 g1 = 0;
        if (data_02175628[i].mUnk_4c == 0 && data_02175628[i].mUnk_58 < 5) {
            g1 = 1;
        }
        if (g1 == 0 && data_02175628[i].mUnk_54 == 0 && data_02175628[i].mUnk_4c != 0) {
            g2 = 1;
        }
        if (g2 == 0 || func_02128210(data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a) == 0) {
            goto next;
        }
    }
    func_021281c8(0xe);
    func_ov001_0219f198();
    data_ov001_021ca410->mUnk_48 = 0x100;
    data_ov001_021ca410->mUnk_58 = 2;
    func_02128310(0);
    return;
next:
    if (sel <= 6) {
        n = data_ov001_021a6c90[sel];
        if (func_ov001_0219f688(n) != 0) {
            data_ov001_021ca410->mUnk_4c = n;
            data_ov001_021ca410->mUnk_28[data_ov001_021ca410->mUnk_4c] = 5;
            func_ov001_0219f1f4();
        } else {
            func_0212ecc0(&data_0217d068, 0, 0x16);
        }
        return;
    }
    if ((u16) (data_02175628[i].mUnk_00 & 1) != 0) {
        data_ov001_021ca410->mUnk_28[data_ov001_021ca410->mUnk_4c] = 5;
        func_ov001_0219f1f4();
        return;
    }
    if (func_020ae408(8, 0x40) != 0) {
        if (data_ov001_021a6ca0[data_ov001_021ca410->mUnk_4c] != 0) {
            n = data_ov001_021ca410->mUnk_4c + data_ov001_021a6ca0[data_ov001_021ca410->mUnk_4c];
            if (func_ov001_0219f688(n) != 0) {
                data_ov001_021ca410->mUnk_4c = n;
                data_ov001_021ca410->mUnk_28[data_ov001_021ca410->mUnk_4c] = 5;
                func_0212ecc0(&data_0217d068, 0, 0);
            }
        }
    } else if (func_020ae408(8, 0x80) != 0) {
        if (data_ov001_021a6cb0[data_ov001_021ca410->mUnk_4c] != 0) {
            n = data_ov001_021ca410->mUnk_4c + data_ov001_021a6cb0[data_ov001_021ca410->mUnk_4c];
            if (func_ov001_0219f688(n) != 0) {
                data_ov001_021ca410->mUnk_4c = n;
                data_ov001_021ca410->mUnk_28[data_ov001_021ca410->mUnk_4c] = 5;
                func_0212ecc0(&data_0217d068, 0, 0);
            }
        }
    } else if (func_020ae408(8, 0x20) != 0) {
        if (data_ov001_021a6cc0[data_ov001_021ca410->mUnk_4c] != 0) {
            n = data_ov001_021ca410->mUnk_4c + data_ov001_021a6cc0[data_ov001_021ca410->mUnk_4c];
            if (func_ov001_0219f688(n) != 0) {
                data_ov001_021ca410->mUnk_4c = n;
                data_ov001_021ca410->mUnk_28[data_ov001_021ca410->mUnk_4c] = 5;
                func_0212ecc0(&data_0217d068, 0, 0);
            }
        }
    } else if (func_020ae408(8, 0x10) != 0) {
        if (data_ov001_021a6cd0[data_ov001_021ca410->mUnk_4c] != 0) {
            n = data_ov001_021ca410->mUnk_4c + data_ov001_021a6cd0[data_ov001_021ca410->mUnk_4c];
            if (func_ov001_0219f688(n) != 0) {
                data_ov001_021ca410->mUnk_4c = n;
                data_ov001_021ca410->mUnk_28[data_ov001_021ca410->mUnk_4c] = 5;
                func_0212ecc0(&data_0217d068, 0, 0);
            }
        }
    }
}

void func_ov001_0219ebfc(void) {
    data_ov001_021ca410->mUnk_24 = data_ov001_021ca410->mUnk_24 + 1;
    func_021059e0();
    if (data_ov001_021ca410->mUnk_24 >= 5) {
        func_ov001_0219f198();
        data_ov001_021ca410->mUnk_48 = -256;
        data_ov001_021ca410->mUnk_58 = 1;
    }
}

void func_ov001_0219eb60(void) {
    s32 i;
    s32 j;
    s32 count;
    s16 value;

    count = data_ov001_021ca410->mUnk_04->mUnk_06;
    data_ov001_021ca410->mUnk_24 = data_ov001_021ca410->mUnk_24 + 1;
    value = func_020ae4c0(1, 0, data_ov001_021ca410->mUnk_48, data_ov001_021ca410->mUnk_24, 10);
    data_ov001_021ca410->mUnk_44 = func_020ae4c0(1, 0, -192, data_ov001_021ca410->mUnk_24, 10);
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 11; j++) {
            data_ov001_021ca410->mUnk_10[data_ov001_021a6ce0[i][j]].mUnk_04 = value;
        }
        data_ov001_021ca410->mUnk_10[count + data_ov001_021a6c60[i]].mUnk_04 = value;
    }
}

s32 func_ov001_0219ead4(void) {
    data_ov001_021ca410->mUnk_1c = data_ov001_021ca410->mUnk_20;
    switch (data_ov001_021ca410->mUnk_1c) {
        case 0:
            func_ov001_0219efd0();
            break;
        case 1:
            func_ov001_0219ef24();
            break;
        case 2:
            func_ov001_0219ef08();
            break;
        case 3:
            func_ov001_0219ec38();
            break;
        case 4:
            func_ov001_0219ebfc();
            break;
        case 5:
            func_ov001_0219eb60();
            break;
    }
    func_ov001_0219f430();
    func_02124c30(data_ov001_021ca410->mUnk_04, data_ov001_021ca410->mUnk_00, data_ov001_021ca410->mUnk_0c,
                  data_ov001_021ca410->mUnk_54, data_ov001_021ca410->mUnk_10);
    if (data_ov001_021ca410->mUnk_1c == 5 && data_ov001_021ca410->mUnk_24 >= 10) {
        return data_ov001_021ca410->mUnk_58;
    }
    return 0;
}

void func_ov001_0219eab4(void) {
    *(vu32 *) 0x4000010 = (-data_ov001_021ca410->mUnk_44 << 16) & 0x1ff0000;
}
