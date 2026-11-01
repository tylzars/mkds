#include "01/code_021972f4.h"
#include "01/code_02195a6c.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02117000.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "00/code_02182fdc.h"
#include "03/code_021b94b8.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_02116000.h"

void func_ov001_021975f4(u16 param_1) {
    u32 time;
    u16 str[16];
    u16 name[10];
    s32 value;
    s32 result;
    u16 tile;
    u16 index;
    u16 slot;
    u16 pal;
    u8 *palette;

    if (param_1 == 0) {
        u16 cnt;

        value = data_ov001_021a6828[0];
        result = func_020601e4(data_ov001_021a6900[data_ov001_021a9bdc->mUnk_6c], value);
        index = data_ov001_021a6850[0][0];
        data_ov001_021a9bdc->mUnk_38[index].mUnk_00 = 1;
        tile = data_ov001_021a6864[result];
        func_02124748(tile, data_ov001_021a9bdc->mUnk_2c, data_ov001_021a9bdc->mUnk_28, data_ov001_021a9bdc->mUnk_34, 0,
                      index, data_ov001_021a9bdc->mUnk_04, data_ov001_021a9bdc->mUnk_08);
        palette = (u8 *) ((Unk020b4a44 *) data_ov001_021a9bdc->mUnk_30)->mUnk_0c;
        func_02016468(0xe, data_ov001_021a683c[0] << 5,
                      palette + (func_02124a68(tile, data_ov001_021a9bdc->mUnk_2c, data_ov001_021a9bdc->mUnk_34) << 5),
                      0x20);
        result = func_020601a0(data_ov001_021a6900[data_ov001_021a9bdc->mUnk_6c], value);
        slot = data_ov001_021a6850[0][1];
        data_ov001_021a9bdc->mUnk_38[slot].mUnk_00 = 1;
        func_021171a0(result, data_ov001_021a9bdc->mUnk_04, data_ov001_021a9bdc->mUnk_08, slot, data_ov001_021a683c[5],
                      0);
        cnt = data_ov001_021a9bdc->mUnk_08->mUnk_06;
        func_02060134(data_ov001_021a6900[data_ov001_021a9bdc->mUnk_6c], value, &time);
        func_02116b8c(&time, str);
        pal = data_ov001_021a67d4[0];
        data_ov001_021a9bdc->mUnk_38[cnt + pal].mUnk_00 = 1;
        func_02124224(0, pal, data_ov001_021a9bdc->mUnk_10, str, data_ov001_021a9bdc->mUnk_08,
                      data_ov001_021a9bdc->mUnk_38, 7);
        func_020600d0(data_ov001_021a6900[data_ov001_021a9bdc->mUnk_6c], value, name);
        func_0214d168(str, 0, 0x20);
        func_0214cffc(name, str, 0x14);
        pal = data_ov001_021a6810[0];
        data_ov001_021a9bdc->mUnk_38[cnt + pal].mUnk_00 = 1;
        func_0212426c(0, pal, data_ov001_021a9bdc->mUnk_10, str, data_ov001_021a9bdc->mUnk_08,
                      data_ov001_021a9bdc->mUnk_38);
    } else {
        u16 cnt;

        value = data_ov001_021a6828[param_1];
        result = func_020601e4(data_ov001_021a6900[data_ov001_021a9bdc->mUnk_6c], value);
        index = data_ov001_021a6850[param_1][0];
        data_ov001_021a9bdc->mUnk_3c[index].mUnk_00 = 1;
        tile = data_ov001_021a6864[result];
        func_02124748(tile, data_ov001_021a9bdc->mUnk_2c, data_ov001_021a9bdc->mUnk_28, data_ov001_021a9bdc->mUnk_34, 1,
                      index, data_ov001_021a9bdc->mUnk_18, data_ov001_021a9bdc->mUnk_1c);
        palette = (u8 *) ((Unk020b4a44 *) data_ov001_021a9bdc->mUnk_30)->mUnk_0c;
        func_02016468(0x1e, data_ov001_021a683c[param_1] << 5,
                      palette + (func_02124a68(tile, data_ov001_021a9bdc->mUnk_2c, data_ov001_021a9bdc->mUnk_34) << 5),
                      0x20);
        result = func_020601a0(data_ov001_021a6900[data_ov001_021a9bdc->mUnk_6c], value);
        slot = data_ov001_021a6852[param_1][0];
        data_ov001_021a9bdc->mUnk_3c[slot].mUnk_00 = 1;
        func_021171a0(result, data_ov001_021a9bdc->mUnk_18, data_ov001_021a9bdc->mUnk_1c, slot,
                      data_ov001_021a6846[param_1], 1);
        cnt = data_ov001_021a9bdc->mUnk_1c->mUnk_06;
        func_02060134(data_ov001_021a6900[data_ov001_021a9bdc->mUnk_6c], value, &time);
        func_02116b8c(&time, str);
        pal = data_ov001_021a67d4[param_1];
        data_ov001_021a9bdc->mUnk_3c[cnt + pal].mUnk_00 = 1;
        func_02124224(1, pal, data_ov001_021a9bdc->mUnk_24, str, data_ov001_021a9bdc->mUnk_1c,
                      data_ov001_021a9bdc->mUnk_3c, 7);
        func_020600d0(data_ov001_021a6900[data_ov001_021a9bdc->mUnk_6c], value, name);
        func_0214d168(str, 0, 0x20);
        func_0214cffc(name, str, 0x14);
        pal = data_ov001_021a6810[param_1];
        data_ov001_021a9bdc->mUnk_3c[cnt + pal].mUnk_00 = 1;
        func_0212426c(1, pal, data_ov001_021a9bdc->mUnk_24, str, data_ov001_021a9bdc->mUnk_1c,
                      data_ov001_021a9bdc->mUnk_3c);
    }
}

void func_ov001_0219750c(u16 param_1) {
    u16 cnt;

    if (param_1 == 0) {
        data_ov001_021a9bdc->mUnk_38[data_ov001_021a6850[0][0]].mUnk_00 = 0;
        data_ov001_021a9bdc->mUnk_38[data_ov001_021a6850[0][1]].mUnk_00 = 0;
        cnt = data_ov001_021a9bdc->mUnk_08->mUnk_06;
        data_ov001_021a9bdc->mUnk_38[cnt + data_ov001_021a67d4[0]].mUnk_00 = 1;
        func_02124224(0, data_ov001_021a67d4[0], data_ov001_021a9bdc->mUnk_10, L"--:--:---",
                      data_ov001_021a9bdc->mUnk_08, data_ov001_021a9bdc->mUnk_38, 7);
        data_ov001_021a9bdc->mUnk_38[cnt + data_ov001_021a6810[0]].mUnk_00 = 0;
    } else {
        data_ov001_021a9bdc->mUnk_3c[data_ov001_021a6850[param_1][0]].mUnk_00 = 0;
        data_ov001_021a9bdc->mUnk_3c[data_ov001_021a6852[param_1][0]].mUnk_00 = 0;
        cnt = data_ov001_021a9bdc->mUnk_1c->mUnk_06;
        data_ov001_021a9bdc->mUnk_3c[cnt + data_ov001_021a67d4[param_1]].mUnk_00 = 1;
        func_02124224(1, data_ov001_021a67d4[param_1], data_ov001_021a9bdc->mUnk_24, L"--:--:---",
                      data_ov001_021a9bdc->mUnk_1c, data_ov001_021a9bdc->mUnk_3c, 7);
        data_ov001_021a9bdc->mUnk_3c[cnt + data_ov001_021a6810[param_1]].mUnk_00 = 0;
    }
}

void func_ov001_021972f4(void) {
    Unk021a9bdc *p;
    u32 time;
    u16 str[16];
    u16 name[10];
    s32 i;
    s32 result;
    u16 tile;
    u8 *palette;
    u16 cnt;

    p = data_ov001_021a9bdc;
    func_0212426c(0, 0, data_ov001_021a9bdc->mUnk_10, func_020b3f7c(p->mUnk_40, data_ov001_021a6880[p->mUnk_6c]),
                  p->mUnk_08, p->mUnk_38);
    for (i = 0; i < 5; i++) {
        if (func_02060228(data_ov001_021a6900[data_ov001_021a9bdc->mUnk_6c], data_ov001_021a6828[i])) {
            func_ov001_021975f4(i);
        } else {
            func_ov001_0219750c(i);
        }
    }
    cnt = data_ov001_021a9bdc->mUnk_08->mUnk_06;
    if (func_02060228(data_ov001_021a6900[data_ov001_021a9bdc->mUnk_6c], 5)) {
        result = func_020601e4(data_ov001_021a6900[data_ov001_021a9bdc->mUnk_6c], 5);
        data_ov001_021a9bdc->mUnk_38[5].mUnk_00 = 1;
        tile = data_ov001_021a6864[result];
        func_02124748((u32) (tile), (void *) (data_ov001_021a9bdc->mUnk_2c), (void *) (data_ov001_021a9bdc->mUnk_28),
                      (void *) (data_ov001_021a9bdc->mUnk_34), 0, (u32) (5), (void *) (data_ov001_021a9bdc->mUnk_04),
                      (void *) (data_ov001_021a9bdc->mUnk_08));
        palette = (u8 *) ((Unk020b4a44 *) data_ov001_021a9bdc->mUnk_30)->mUnk_0c;
        func_02016468(0xe, 0x80,
                      palette + (func_02124a68((u32) (tile), (void *) (data_ov001_021a9bdc->mUnk_2c),
                                               (void *) (data_ov001_021a9bdc->mUnk_34))
                                 << 5),
                      0x20);
        result = func_020601a0(data_ov001_021a6900[data_ov001_021a9bdc->mUnk_6c], 5);
        data_ov001_021a9bdc->mUnk_38[6].mUnk_00 = 1;
        func_021171a0(result, data_ov001_021a9bdc->mUnk_04, data_ov001_021a9bdc->mUnk_08, 6, 6, 0);
        func_02060134(data_ov001_021a6900[data_ov001_021a9bdc->mUnk_6c], 5, &time);
        func_02116b8c(&time, str);
        data_ov001_021a9bdc->mUnk_38[cnt + 2].mUnk_00 = 1;
        func_02124224(0, 2, data_ov001_021a9bdc->mUnk_10, str, data_ov001_021a9bdc->mUnk_08,
                      data_ov001_021a9bdc->mUnk_38, 7);
        func_020600d0(data_ov001_021a6900[data_ov001_021a9bdc->mUnk_6c], 5, name);
        func_0214d168(str, 0, 0x20);
        func_0214cffc(name, str, 0x14);
        data_ov001_021a9bdc->mUnk_38[cnt + 4].mUnk_00 = 1;
        func_0212426c(0, 4, data_ov001_021a9bdc->mUnk_10, str, data_ov001_021a9bdc->mUnk_08,
                      data_ov001_021a9bdc->mUnk_38);
    } else {
        data_ov001_021a9bdc->mUnk_38[5].mUnk_00 = 0;
        data_ov001_021a9bdc->mUnk_38[6].mUnk_00 = 0;
        data_ov001_021a9bdc->mUnk_38[cnt + 2].mUnk_00 = 1;
        func_02124224(0, 2, data_ov001_021a9bdc->mUnk_10, L"--:--:---", data_ov001_021a9bdc->mUnk_08,
                      data_ov001_021a9bdc->mUnk_38, 7);
        data_ov001_021a9bdc->mUnk_38[cnt + 4].mUnk_00 = 0;
    }
}
