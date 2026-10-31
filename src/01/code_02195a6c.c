#include "01/code_02195a6c.h"
#include "Main/Unknown/code_02111488.h"
#include "Main/Unknown/code_02117218.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02148ca0.h"
#include "code_0201ea58.h"
#include "registers.h"

void func_ov001_02196d8c(void) {
    data_ov001_021a9bdc->mUnk_54 = 0x10;
    data_ov001_021a9bdc->mUnk_58 = 0;
    func_02125fc0();
}

void func_ov001_02196d78(void) {
    data_ov001_021a9bdc->mUnk_54 = 0x11;
    data_ov001_021a9bdc->mUnk_58 = 0;
}

void func_ov001_02196cd0(void) {
    s32 i;

    data_ov001_021a9bdc->mUnk_3c[data_ov001_021a67c4[0]].mUnk_04 = -func_020adc64(6 - data_ov001_021a9bdc->mUnk_78[0]);
    data_ov001_021a9bdc->mUnk_3c[data_ov001_021a67c4[1]].mUnk_04 = func_020adc64(6 - data_ov001_021a9bdc->mUnk_78[1]);
    for (i = 0; i < 2; i++) {
        if (data_ov001_021a9bdc->mUnk_78[i] > 0) {
            data_ov001_021a9bdc->mUnk_78[i]--;
            data_ov001_021a9bdc->mUnk_3c[data_ov001_021a67c0[i]].mUnk_00 = 0;
            data_ov001_021a9bdc->mUnk_3c[data_ov001_021a67c4[i]].mUnk_00 = 1;
        } else {
            data_ov001_021a9bdc->mUnk_3c[data_ov001_021a67c0[i]].mUnk_00 = 1;
            data_ov001_021a9bdc->mUnk_3c[data_ov001_021a67c4[i]].mUnk_00 = 0;
        }
    }
}

s32 func_ov001_02196c4c(void) {
    Unk02175628Index idx = UNK_02175628_INDEX_8;
    u16 m;

    m = data_02175628[idx].mUnk_00;
    if (m != 0) {
        if (data_ov001_021a681c[0] == (data_ov001_021a681c[0] | m)) {
            data_ov001_021a9bdc->mUnk_80 = 1;
            data_ov001_021a9bdc->mUnk_84 = 0;
        } else if (data_ov001_021a681c[data_ov001_021a9bdc->mUnk_80] ==
                   (data_ov001_021a681c[data_ov001_021a9bdc->mUnk_80] | m)) {
            data_ov001_021a9bdc->mUnk_80++;
            data_ov001_021a9bdc->mUnk_84 = 0;
            if (data_ov001_021a9bdc->mUnk_80 >= 6) {
                data_ov001_021a9bdc->mUnk_80 = 0;
                return 1;
            }
        } else {
            data_ov001_021a9bdc->mUnk_80 = 0;
        }
    }
    return 0;
}

void func_ov001_02196960(void *heap) {
    s32 i;
    s32 k;
    s32 rem;
    Unk021a9bdc *p;

    (reg_G2_BG0CNT) = ((reg_G2_BG0CNT) & ~3) | 1;
    (reg_G2_BG1CNT) = ((reg_G2_BG1CNT) & ~3) | 1;
    (reg_G2S_DB_BG3CNT) = ((reg_G2S_DB_BG3CNT) & ~3) | 1;
    (reg_G2_BG0CNT) = ((reg_G2_BG0CNT) & 0x43) | 0x8800;
    (reg_G2_BG1CNT) = ((reg_G2_BG1CNT) & 0x43) | 0xcc00;
    (reg_G2S_DB_BG1CNT) = ((reg_G2S_DB_BG1CNT) & 0x43) | 0x1018;
    (reg_G2S_DB_BG3CNT) = ((reg_G2S_DB_BG3CNT) & 0x43) | 0x5810;
    data_ov001_021a9bdc = func_02036bec(heap, 0x94);
    data_ov001_021a9bdc->mUnk_4c = heap;
    data_ov001_021a9bdc->mUnk_50 = 0;
    data_ov001_021a9bdc->mUnk_6c = 0;
    data_ov001_021a9bdc->mUnk_70 = 0;
    data_ov001_021a9bdc->mUnk_74 = 0;
    data_ov001_021a9bdc->mUnk_88 = 0;
    data_ov001_021a9bdc->mUnk_8c = 0;
    for (i = 0; i < 2; i++) {
        data_ov001_021a9bdc->mUnk_78[i] = 0;
    }
    func_ov001_021978b4();
    func_021172a8(heap);
    func_020ae6d4(func_02111318(), func_0211130c());
    func_02124ed0(heap, data_ov001_021a9bdc->mUnk_08, data_ov001_021a9bdc->mUnk_10, &data_ov001_021a9bdc->mUnk_38);
    func_02124ed0(heap, data_ov001_021a9bdc->mUnk_1c, data_ov001_021a9bdc->mUnk_24, &data_ov001_021a9bdc->mUnk_3c);
    data_ov001_021a9bdc->mUnk_40 = func_02047a28("common.bmg");
    data_ov001_021a9bdc->mUnk_44 = func_0204799c("ghost.bmg");
    data_ov001_021a9bdc->mUnk_48 = func_0204799c("record.bmg");
    rem = 0x8000;
    rem -= func_021243ac(heap, 0, data_ov001_021a9bdc->mUnk_10, 0xc8, 0x10, 0, data_ov001_021a9bdc->mUnk_04,
                         data_ov001_021a9bdc->mUnk_08, data_ov001_021a9bdc->mUnk_38, rem);
    rem -= func_021243ac(heap, 1, data_ov001_021a9bdc->mUnk_10, 0x46, 0x10, 1, data_ov001_021a9bdc->mUnk_04,
                         data_ov001_021a9bdc->mUnk_08, data_ov001_021a9bdc->mUnk_38, rem);
    rem -= func_021243ac(heap, 2, data_ov001_021a9bdc->mUnk_10, 0x46, 0x10, 2, data_ov001_021a9bdc->mUnk_04,
                         data_ov001_021a9bdc->mUnk_08, data_ov001_021a9bdc->mUnk_38, rem);
    rem -= func_021243ac(heap, 3, data_ov001_021a9bdc->mUnk_10, 0x7c, 0x10, 3, data_ov001_021a9bdc->mUnk_04,
                         data_ov001_021a9bdc->mUnk_08, data_ov001_021a9bdc->mUnk_38, rem);
    rem -= func_021243ac(heap, 4, data_ov001_021a9bdc->mUnk_10, 0x64, 0x10, 4, data_ov001_021a9bdc->mUnk_04,
                         data_ov001_021a9bdc->mUnk_08, data_ov001_021a9bdc->mUnk_38, rem);
    rem = func_02148ca0();
    for (k = 1; k < 5; k++) {
        rem -= func_021243ac(heap, data_ov001_021a67d4[k], data_ov001_021a9bdc->mUnk_24, data_ov001_021a67c8[k],
                             data_ov001_021a67e0[k], k, data_ov001_021a9bdc->mUnk_18, data_ov001_021a9bdc->mUnk_1c,
                             data_ov001_021a9bdc->mUnk_3c, rem);
        rem -= func_021243ac(heap, data_ov001_021a6810[k], data_ov001_021a9bdc->mUnk_24, data_ov001_021a6804[k],
                             data_ov001_021a67ec[k], k + 5, data_ov001_021a9bdc->mUnk_18, data_ov001_021a9bdc->mUnk_1c,
                             data_ov001_021a9bdc->mUnk_3c, rem);
    }
    func_021243ac(heap, 8, data_ov001_021a9bdc->mUnk_24, 0x98, 0x10, 0xd, data_ov001_021a9bdc->mUnk_18,
                  data_ov001_021a9bdc->mUnk_1c, data_ov001_021a9bdc->mUnk_3c, rem);
    p = data_ov001_021a9bdc;
    func_0212426c(1, 8, data_ov001_021a9bdc->mUnk_24, func_020b3f7c(p->mUnk_48, 3), p->mUnk_1c, p->mUnk_3c);
    func_ov001_02197058();
}

void func_ov001_02196904(void) {
    u32 a;
    u32 b;

    func_02117218();
    data_ov001_021a9bdc = 0;
    a = ((reg_GX_DISPCNT) & 0x1f00) >> 8;
    (reg_GX_DISPCNT) = ((reg_GX_DISPCNT) & ~0x1f00) | ((a & ~0x13) << 8);
    b = ((reg_GXS_DB_DISPCNT) & 0x1f00) >> 8;
    (reg_GXS_DB_DISPCNT) = ((reg_GXS_DB_DISPCNT) & ~0x1f00) | ((b & ~9) << 8);
}

void func_ov001_021968bc(void) {
    s16 v;

    data_ov001_021a9bdc->mUnk_58++;
    v = func_020ae4c0(1, -0xc0, 0, data_ov001_021a9bdc->mUnk_58, 10);
    data_ov001_021a9bdc->mUnk_5c = v;
    data_ov001_021a9bdc->mUnk_64 = v;
    data_ov001_021a9bdc->mUnk_38[0].mUnk_06 = v;
    if (data_ov001_021a9bdc->mUnk_58 >= 10) {
        func_ov001_0219703c();
    }
}

void func_ov001_02196724(void) {
    s32 i;
    u16 x;
    u16 y;
    s32 j;
    s16 v;

    data_ov001_021a9bdc->mUnk_58++;
    v = func_020ae4c0(1, 0x100, 0, data_ov001_021a9bdc->mUnk_58, 10);
    data_ov001_021a9bdc->mUnk_60 = v;
    data_ov001_021a9bdc->mUnk_68 = v;
    x = data_ov001_021a9bdc->mUnk_08->mUnk_06;
    y = data_ov001_021a9bdc->mUnk_1c->mUnk_06;
    data_ov001_021a9bdc->mUnk_38[0].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[1].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[2].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[3].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[4].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[5].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[6].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[x].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[x + 1].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[x + 2].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[x + 3].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[x + 4].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[15].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[16].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[12].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[13].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[14].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[y + 8].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        data_ov001_021a9bdc->mUnk_3c[data_ov001_021a67f8[i]].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_3c[y + data_ov001_021a67d4[i]].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_3c[y + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            data_ov001_021a9bdc->mUnk_3c[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (data_ov001_021a9bdc->mUnk_58 >= 10) {
        func_ov001_02197024();
    }
}

void func_ov001_02196514(void) {
    s32 a = -1;
    s32 b = -1;
    Unk02175628Index idx = UNK_02175628_INDEX_8;
    s32 x;
    s32 y;
    u16 v;

    func_ov001_02196cd0();
    x = 1;
    y = 0;
    v = data_02175628[idx].mUnk_4c;
    if (v == 0 && data_02175628[idx].mUnk_58 < 5) {
        y = 1;
    }
    if (y == 0 && v == 0) {
        x = 0;
    }
    if (x != 0) {
        a = func_0201ea84(data_ov001_021a9bdc->mUnk_20, data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a);
    }
    x = 0;
    y = 0;
    v = data_02175628[idx].mUnk_4c;
    if (v == 0 && data_02175628[idx].mUnk_58 < 5) {
        y = 1;
    }
    if (y == 0 && data_02175628[idx].mUnk_54 == 0 && v != 0) {
        x = 1;
    }
    if (x != 0) {
        b = func_0201ea84(data_ov001_021a9bdc->mUnk_20, data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a);
    }
    if (a != 0) {
        data_ov001_021a9bdc->mUnk_88 = 0;
    }
    if (a != 1) {
        data_ov001_021a9bdc->mUnk_8c = 0;
    }
    if ((u16) (data_02175628[idx].mUnk_00 & 2) == 0) {
        x = 0;
        y = 0;
        v = data_02175628[idx].mUnk_4c;
        if (v == 0 && data_02175628[idx].mUnk_58 < 5) {
            y = 1;
        }
        if (y == 0 && data_02175628[idx].mUnk_54 == 0 && v != 0) {
            x = 1;
        }
        if (x == 0 || func_02128210(data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a) == 0) {
            goto other;
        }
    }
    func_ov001_02196fc4();
    data_ov001_021a9bdc->mUnk_90 = 0;
    func_02128310(0);
    goto done;
other:
    if (b == 2 || (u16) (data_02175628[idx].mUnk_00 & 0x400) != 0) {
        func_ov001_02196f80();
    } else if ((a == 0 && data_ov001_021a9bdc->mUnk_88 != 0) || (b == 0 && data_ov001_021a9bdc->mUnk_88 == 0) ||
               (u16) (data_02175628[idx].mUnk_02 & 0x20) != 0) {
        data_ov001_021a9bdc->mUnk_70 = 1;
        data_ov001_021a9bdc->mUnk_78[0] = 6;
        data_ov001_021a9bdc->mUnk_88 = 1;
        func_ov001_02197010();
        func_0212ecc0(&data_0217d068, 0, 2);
    } else if ((a == 1 && data_ov001_021a9bdc->mUnk_8c != 0) || (b == 1 && data_ov001_021a9bdc->mUnk_8c == 0) ||
               (u16) (data_02175628[idx].mUnk_02 & 0x10) != 0) {
        data_ov001_021a9bdc->mUnk_70 = 0;
        data_ov001_021a9bdc->mUnk_78[1] = 6;
        data_ov001_021a9bdc->mUnk_8c = 1;
        func_ov001_02197010();
        func_0212ecc0(&data_0217d068, 0, 2);
    }
done:
    if (func_ov001_02196c4c() != 0) {
        if (func_ov001_02197210() != 0) {
            func_ov001_02196e30();
        }
    }
}

void func_ov001_021963a8(void) {
    s32 i;
    u16 x;
    u16 y;
    s32 j;
    s32 k;
    s16 v;

    k = 0;
    func_ov001_02196cd0();
    switch (data_ov001_021a9bdc->mUnk_70) {
        case 0:
            k = -0x100;
            break;
        case 1:
            k = 0x100;
            break;
    }
    data_ov001_021a9bdc->mUnk_58++;
    v = func_020ae4c0(1, 0, k, data_ov001_021a9bdc->mUnk_58, 10);
    data_ov001_021a9bdc->mUnk_60 = v;
    data_ov001_021a9bdc->mUnk_68 = v;
    x = data_ov001_021a9bdc->mUnk_08->mUnk_06;
    y = data_ov001_021a9bdc->mUnk_1c->mUnk_06;
    data_ov001_021a9bdc->mUnk_38[0].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[1].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[2].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[3].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[4].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[5].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[6].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[x].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[x + 1].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[x + 2].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[x + 3].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[x + 4].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        data_ov001_021a9bdc->mUnk_3c[data_ov001_021a67f8[i]].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_3c[y + data_ov001_021a67d4[i]].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_3c[y + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            data_ov001_021a9bdc->mUnk_3c[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (data_ov001_021a9bdc->mUnk_58 >= 10) {
        func_ov001_02196fd8();
    }
}

void func_ov001_0219623c(void) {
    s32 i;
    u16 x;
    u16 y;
    s32 j;
    s32 k;
    s16 v;

    k = 0;
    func_ov001_02196cd0();
    switch (data_ov001_021a9bdc->mUnk_70) {
        case 0:
            k = 0x100;
            break;
        case 1:
            k = -0x100;
            break;
    }
    data_ov001_021a9bdc->mUnk_58++;
    v = func_020ae4c0(1, k, 0, data_ov001_021a9bdc->mUnk_58, 10);
    data_ov001_021a9bdc->mUnk_60 = v;
    data_ov001_021a9bdc->mUnk_68 = v;
    x = data_ov001_021a9bdc->mUnk_08->mUnk_06;
    y = data_ov001_021a9bdc->mUnk_1c->mUnk_06;
    data_ov001_021a9bdc->mUnk_38[0].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[1].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[2].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[3].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[4].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[5].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[6].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[x].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[x + 1].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[x + 2].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[x + 3].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[x + 4].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        data_ov001_021a9bdc->mUnk_3c[data_ov001_021a67f8[i]].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_3c[y + data_ov001_021a67d4[i]].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_3c[y + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            data_ov001_021a9bdc->mUnk_3c[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (data_ov001_021a9bdc->mUnk_58 >= 10) {
        func_ov001_02197024();
    }
}

void func_ov001_021960a4(void) {
    s32 i;
    u16 x;
    u16 y;
    s32 j;
    s16 v;

    data_ov001_021a9bdc->mUnk_58++;
    v = func_020ae4c0(1, 0, 0x100, data_ov001_021a9bdc->mUnk_58, 10);
    data_ov001_021a9bdc->mUnk_60 = v;
    data_ov001_021a9bdc->mUnk_68 = v;
    x = data_ov001_021a9bdc->mUnk_08->mUnk_06;
    y = data_ov001_021a9bdc->mUnk_1c->mUnk_06;
    data_ov001_021a9bdc->mUnk_38[0].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[1].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[2].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[3].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[4].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[5].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[6].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[x].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[x + 1].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[x + 2].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[x + 3].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_38[x + 4].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[15].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[16].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[12].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[13].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[14].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[y + 8].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        data_ov001_021a9bdc->mUnk_3c[data_ov001_021a67f8[i]].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_3c[y + data_ov001_021a67d4[i]].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_3c[y + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            data_ov001_021a9bdc->mUnk_3c[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (data_ov001_021a9bdc->mUnk_58 >= 10) {
        func_ov001_02196fb0();
    }
}

void func_ov001_02196058(void) {
    s16 v;

    data_ov001_021a9bdc->mUnk_58++;
    v = func_020ae4c0(1, 0, -0xc0, data_ov001_021a9bdc->mUnk_58, 10);
    data_ov001_021a9bdc->mUnk_5c = v;
    data_ov001_021a9bdc->mUnk_64 = v;
    data_ov001_021a9bdc->mUnk_38[0].mUnk_06 = v;
    if (data_ov001_021a9bdc->mUnk_58 >= 10) {
        func_02111488(data_ov001_021a9bdc->mUnk_90);
    }
}

void func_ov001_02195ff8(void) {
    s16 v;
    u16 x;

    data_ov001_021a9bdc->mUnk_58++;
    v = func_020ae488(data_ov001_021a9bdc->mUnk_58);
    x = data_ov001_021a9bdc->mUnk_1c->mUnk_06;
    data_ov001_021a9bdc->mUnk_3c[12].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[13].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[14].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[x + 8].mUnk_04 = v;
    if (data_ov001_021a9bdc->mUnk_58 >= 10) {
        func_ov001_02196f64();
    }
}

void func_ov001_02195eb8(void) {
    s32 i;
    u16 x;
    s32 j;
    s16 v;

    data_ov001_021a9bdc->mUnk_58++;
    v = func_020ae4c0(1, 0, 0x100, data_ov001_021a9bdc->mUnk_58, 10);
    data_ov001_021a9bdc->mUnk_68 = v;
    x = data_ov001_021a9bdc->mUnk_1c->mUnk_06;
    data_ov001_021a9bdc->mUnk_3c[15].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[16].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[12].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[13].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[14].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[x + 8].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        data_ov001_021a9bdc->mUnk_3c[data_ov001_021a67f8[i]].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_3c[x + data_ov001_021a67d4[i]].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_3c[x + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            data_ov001_021a9bdc->mUnk_3c[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (data_ov001_021a9bdc->mUnk_58 > 10) {
        if (func_02128274() != 0) {
            func_ov001_02196ecc();
        }
    }
    if (data_ov001_021a9bdc->mUnk_58 == 7) {
        data_ov001_021a9bdc->mUnk_3c[12].mUnk_00 = 0;
        data_ov001_021a9bdc->mUnk_3c[13].mUnk_00 = 0;
    }
}

void func_ov001_02195ea0(void) {
    if (func_02125fa4() != 0) {
        func_ov001_02196eb0();
    }
}

void func_ov001_02195e38(void) {
    if (func_02125f54() != 0) {
        if (func_02125f60() == 0) {
            if (func_02060268(data_ov001_021a6900[data_ov001_021a9bdc->mUnk_6c]) == 0) {
                func_02060004(data_ov001_021a6900[data_ov001_021a9bdc->mUnk_6c]);
                func_02057d9c();
                if (data_021759d4->mUnk_0c != 0) {
                    func_02145d38();
                }
            }
            data_ov001_021a9bdc->mUnk_74 = 1;
        }
        func_ov001_02196e88();
    }
}

void func_ov001_02195d64(void) {
    s16 v;
    u16 w;

    data_ov001_021a9bdc->mUnk_58++;
    if (data_ov001_021a9bdc->mUnk_74 != 0) {
        v = func_020ae4c0(1, 0, 0x100, data_ov001_021a9bdc->mUnk_58, 10);
        data_ov001_021a9bdc->mUnk_60 = v;
        w = data_ov001_021a9bdc->mUnk_08->mUnk_06;
        data_ov001_021a9bdc->mUnk_38[0].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_38[1].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_38[2].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_38[3].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_38[4].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_38[5].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_38[6].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_38[w].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_38[w + 1].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_38[w + 2].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_38[w + 3].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_38[w + 4].mUnk_04 = v;
    }
    if (data_ov001_021a9bdc->mUnk_58 >= 10) {
        if (func_02125f88() != 0) {
            func_ov001_02196e54();
        }
    }
}

void func_ov001_02195ba4(void) {
    s32 i;
    u16 x;
    s32 j;
    s16 v;

    data_ov001_021a9bdc->mUnk_58++;
    v = func_020ae4c0(1, 0x100, 0, data_ov001_021a9bdc->mUnk_58, 10);
    if (data_ov001_021a9bdc->mUnk_74 != 0) {
        u16 w;

        data_ov001_021a9bdc->mUnk_60 = v;
        w = data_ov001_021a9bdc->mUnk_08->mUnk_06;
        data_ov001_021a9bdc->mUnk_38[0].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_38[1].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_38[2].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_38[3].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_38[4].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_38[5].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_38[6].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_38[w].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_38[w + 1].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_38[w + 2].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_38[w + 3].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_38[w + 4].mUnk_04 = v;
    }
    data_ov001_021a9bdc->mUnk_68 = v;
    x = data_ov001_021a9bdc->mUnk_1c->mUnk_06;
    data_ov001_021a9bdc->mUnk_3c[15].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[16].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[12].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[13].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[14].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[x + 8].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        data_ov001_021a9bdc->mUnk_3c[data_ov001_021a67f8[i]].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_3c[x + data_ov001_021a67d4[i]].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_3c[x + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            data_ov001_021a9bdc->mUnk_3c[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (data_ov001_021a9bdc->mUnk_58 > 10) {
        if (func_02128294() != 0) {
            func_ov001_02197024();
        }
    }
    if (data_ov001_021a9bdc->mUnk_58 == 2) {
        data_ov001_021a9bdc->mUnk_3c[12].mUnk_00 = 1;
    }
}

void func_ov001_02195a6c(void) {
    s32 i;
    u16 x;
    s32 j;
    s16 v;

    data_ov001_021a9bdc->mUnk_58++;
    v = func_020ae4c0(1, 0, 0x100, data_ov001_021a9bdc->mUnk_58, 10);
    data_ov001_021a9bdc->mUnk_68 = v;
    x = data_ov001_021a9bdc->mUnk_1c->mUnk_06;
    data_ov001_021a9bdc->mUnk_3c[15].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[16].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[12].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[13].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[14].mUnk_04 = v;
    data_ov001_021a9bdc->mUnk_3c[x + 8].mUnk_04 = v;
    for (i = 1; i < 5; i++) {
        data_ov001_021a9bdc->mUnk_3c[data_ov001_021a67f8[i]].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_3c[x + data_ov001_021a67d4[i]].mUnk_04 = v;
        data_ov001_021a9bdc->mUnk_3c[x + data_ov001_021a6810[i]].mUnk_04 = v;
        for (j = 0; j < 2; j++) {
            data_ov001_021a9bdc->mUnk_3c[data_ov001_021a6850[i][j]].mUnk_04 = v;
        }
    }
    if (data_ov001_021a9bdc->mUnk_58 > 10) {
        func_ov001_02196dbc();
    }
    if (data_ov001_021a9bdc->mUnk_58 == 7) {
        data_ov001_021a9bdc->mUnk_3c[12].mUnk_00 = 0;
        data_ov001_021a9bdc->mUnk_3c[13].mUnk_00 = 0;
    }
}
