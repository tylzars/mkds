#include "Main/Unknown/code_0211d650.h"

#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02125000.h"
#include "code_02016468.h"

#pragma thumb on

void func_0211db30(Unk0215ce70 *a, s32 b) {
    Unk0215ce70 v;

    if (data_0217d368->mUnk_2c == 3) {
        v = data_0215ce70[b];
    } else {
        v = data_0215ce0c[b];
    }
    *a = v;
}

void func_0211d9dc(void) {
    Unk0215ce70 buf;
    s32 i;

    for (i = 0; i < 5; i++) {
        if (data_0217d368->mUnk_7c == 0 && data_0217d368->mUnk_60 == i) {
            func_02124100(data_0215cd4c[i].mUnk_00[0], 1, data_0217d368->mUnk_0c, data_0217d368->mUnk_14,
                          data_0217d368->mUnk_04);
        } else {
            func_02124100(data_0215cd4c[i].mUnk_00[0], 0, data_0217d368->mUnk_0c, data_0217d368->mUnk_14,
                          data_0217d368->mUnk_04);
        }
    }
    if (data_021759d0->mUnk_20 != 2) {
        if (data_0217d368->mUnk_7c != 0 && data_0217d368->mUnk_84 != 0) {
            data_0217d368->mUnk_14[0x28].mUnk_00 = 0;
            data_0217d368->mUnk_14[0x29].mUnk_00 = 1;
            func_02124100(0xd, 1, data_0217d368->mUnk_0c, data_0217d368->mUnk_14, data_0217d368->mUnk_04);
        } else {
            data_0217d368->mUnk_14[0x28].mUnk_00 = 1;
            data_0217d368->mUnk_14[0x29].mUnk_00 = 0;
            func_02124100(0xd, 0, data_0217d368->mUnk_0c, data_0217d368->mUnk_14, data_0217d368->mUnk_04);
        }
    }
    if (data_0217d368->mUnk_80 == data_0217d368->mUnk_7c && data_0217d368->mUnk_64 == data_0217d368->mUnk_60) {
        return;
    }
    for (i = 0; i < 5; i++) {
        func_0211db30(&buf, i);
        func_020b44a4(&data_0217d368->mUnk_20->mUnk_0c, buf.mUnk_00, buf.mUnk_04, buf.mUnk_08, buf.mUnk_0c,
                      buf.mUnk_10);
    }
    if (data_0217d368->mUnk_7c == 0) {
        func_0211db30(&buf, data_0217d368->mUnk_60);
        func_020b44a4(&data_0217d368->mUnk_20->mUnk_0c, buf.mUnk_00, buf.mUnk_04, buf.mUnk_08, buf.mUnk_0c,
                      buf.mUnk_12);
    }
    func_02016468(0x1b, 0, &data_0217d368->mUnk_20->mUnk_0c, 0x600);
}

void func_0211d910(s16 a) {
    u16 buf[0x40];
    u16 buf2[0x40];

    if (a < 1) {
        a = 1;
    }
    if (a > 0xa) {
        a = 0xa;
    }
    data_0217d368->mUnk_88 = a;
    func_02124f4c(data_0217d368->mUnk_88, buf2);
    if (data_021759d0->mUnk_20 != 2) {
        func_0212426c(1, 9, data_0217d368->mUnk_0c, GetBmgEntry(data_0217d368->mUnk_1c, data_0216dc0c[3][0]),
                      data_0217d368->mUnk_04, data_0217d368->mUnk_14);
        func_02124248(1, 8, data_0217d368->mUnk_0c, buf2, data_0217d368->mUnk_04, data_0217d368->mUnk_14, 0xb);
    } else {
        func_02124f4c(data_0217d368->mUnk_88, buf);
        func_0212513c(buf, GetBmgEntry(data_0217d368->mUnk_1c, 0x16), buf2, 0x80);
        func_0212426c(1, 0xa, data_0217d368->mUnk_0c, buf2, data_0217d368->mUnk_04, data_0217d368->mUnk_14);
    }
}

void func_0211d844(s16 a) {
    u16 buf[0x40];
    u16 buf2[0x40];

    if (a < 1) {
        a = 1;
    }
    if (a > 0x20) {
        a = 0x20;
    }
    data_0217d368->mUnk_8a = a;
    func_02124f4c(data_0217d368->mUnk_8a, buf2);
    if (data_021759d0->mUnk_20 != 2) {
        func_0212426c(1, 9, data_0217d368->mUnk_0c, GetBmgEntry(data_0217d368->mUnk_1c, data_0216dc0c[3][1]),
                      data_0217d368->mUnk_04, data_0217d368->mUnk_14);
        func_02124248(1, 8, data_0217d368->mUnk_0c, buf2, data_0217d368->mUnk_04, data_0217d368->mUnk_14, 0xb);
    } else {
        func_02124f4c(data_0217d368->mUnk_8a, buf);
        func_0212513c(buf, GetBmgEntry(data_0217d368->mUnk_1c, 0x17), buf2, 0x80);
        func_0212426c(1, 0xa, data_0217d368->mUnk_0c, buf2, data_0217d368->mUnk_04, data_0217d368->mUnk_14);
    }
}

void func_0211d66c(void) {
    u16 h = data_0217d368->mUnk_04->mUnk_06;

    if (data_021759d0->mUnk_20 != 2) {
        switch (data_0217d368->mUnk_68[3]) {
            case 0:
            case 1:
                data_0217d368->mUnk_14[h + 9].mUnk_00 = 1;
                data_0217d368->mUnk_14[h + 10].mUnk_00 = 0;
                data_0217d368->mUnk_14[h + 8].mUnk_00 = 1;
                break;
            case 2:
                data_0217d368->mUnk_14[h + 9].mUnk_00 = 0;
                data_0217d368->mUnk_14[h + 10].mUnk_00 = 1;
                data_0217d368->mUnk_14[h + 8].mUnk_00 = 0;
                break;
        }
        switch (data_0217d368->mUnk_78) {
            case 0:
            case 1:
                data_0217d368->mUnk_14[h + 11].mUnk_00 = 1;
                data_0217d368->mUnk_14[h + 12].mUnk_00 = 0;
                break;
            case 2:
                data_0217d368->mUnk_14[h + 11].mUnk_00 = 0;
                data_0217d368->mUnk_14[h + 12].mUnk_00 = 1;
                break;
        }
    } else {
        data_0217d368->mUnk_14[0x1e].mUnk_00 = 0;
        data_0217d368->mUnk_14[0x1f].mUnk_00 = 0;
        switch (data_0217d368->mUnk_68[3]) {
            case 0:
                data_0217d368->mUnk_14[h + 10].mUnk_00 = 1;
                func_0211d910(data_0217d368->mUnk_88);
                break;
            case 1:
                data_0217d368->mUnk_14[h + 10].mUnk_00 = 1;
                func_0211d844(data_0217d368->mUnk_8a);
                break;
            case 2:
                data_0217d368->mUnk_14[h + 10].mUnk_00 = 1;
                func_0212426c(1, 0xa, data_0217d368->mUnk_0c, GetBmgEntry(data_0217d368->mUnk_1c, data_0216dc0c[3][2]),
                              data_0217d368->mUnk_04, data_0217d368->mUnk_14);
                break;
        }
        switch (data_0217d368->mUnk_78) {
            case 0:
            case 1:
                data_0217d368->mUnk_14[h + 11].mUnk_00 = 1;
                data_0217d368->mUnk_14[h + 12].mUnk_00 = 0;
                break;
            case 2:
                data_0217d368->mUnk_14[h + 11].mUnk_00 = 0;
                data_0217d368->mUnk_14[h + 12].mUnk_00 = 1;
                break;
        }
    }
    if (data_0217d368->mUnk_2c == 3) {
        data_0217d368->mUnk_14[h + data_0215cd4c[0].mUnk_00[1]].mUnk_00 = 0;
        data_0217d368->mUnk_14[h + data_0215cd4c[2].mUnk_00[1]].mUnk_00 = 0;
    }
}

u16 func_0211d650(void) {
    return data_0217d368->mUnk_ac[0] + data_0217d368->mUnk_ac[1];
}

#pragma thumb off
