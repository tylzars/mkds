#include "01/code_021a0774.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_02029520.h"
#include "Main/Unknown/code_0203b680.h"

void func_ov001_021a0b3c(void) {
    u16 cnt10;
    s32 i;
    u16 cnt04;
    s32 j;
    s32 out;
    u16 buf[18];
    cnt04 = data_ov001_021ca414->mUnk_04->mUnk_06;
    cnt10 = data_ov001_021ca414->mUnk_10->mUnk_06;
    for (i = 0; i < 9; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6dd4[i]].mUnk_00 = 0;
        for (j = 0; j < 9; j++) {
            data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][j]].mUnk_00 = 0;
        }
        for (j = 0; j < 2; j++) {
            data_ov001_021ca414->mUnk_44[cnt10 + data_ov001_021a6e10[i][j]].mUnk_00 = 0;
        }
    }
    for (j = 0; j < 7; j++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6d88[j]].mUnk_00 = 0;
    }
    data_ov001_021ca414->mUnk_40[cnt04].mUnk_00 = 1;
    for (i = 0; i < 9; i++) {
        if (i == 8) {
            if (data_ov001_021ca414->mUnk_a0 != 0) {
                data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][1]].mUnk_00 = 1;
                func_ov001_021a6430((s32) ((s16) (func_02029608() - 1)), 1, (void *) data_ov001_021ca414->mUnk_0c,
                                    (void *) data_ov001_021ca414->mUnk_10, (u32) (0x2d), (u16) (8), 1);
            } else {
                data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][4]].mUnk_00 = 1;
                func_ov001_021a6430((s32) ((s16) (func_02029608() - 1)), 0, (void *) data_ov001_021ca414->mUnk_0c,
                                    (void *) data_ov001_021ca414->mUnk_10, (u32) (0x2d), (u16) (8), 1);
            }
        } else {
            data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][1]].mUnk_00 = 1;
        }
        data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][0]].mUnk_00 = 1;
        data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][2]].mUnk_00 = 0;
        data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][3]].mUnk_00 = 0;
        if (func_0205fd78((u8) func_02029608(), (u8) (i + 1), &out)) {
            if (out <= 4) {
                data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][5]].mUnk_00 = 1;
                data_ov001_021ca414->mUnk_44[cnt10 + data_ov001_021a6e10[i][0]].mUnk_00 = 1;
                func_0212426c(1, data_ov001_021a6e10[i][0], data_ov001_021ca414->mUnk_18, data_ov001_021a92c8[out],
                              data_ov001_021ca414->mUnk_10, data_ov001_021ca414->mUnk_44);
            } else if (out <= 7) {
                data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][out + 1]].mUnk_00 = 1;
            }
            if (i == 8) {
                data_ov001_021ca414->mUnk_a4 = 1;
            }
        }
        func_021057f0(0, func_02029608());
        if (i == 8) {
            func_02124a20(data_ov001_021a6e7c[i][2], 2, data_ov001_021ca414->mUnk_0c, data_ov001_021ca414->mUnk_10);
            func_02124a20(data_ov001_021a6e7c[i][1], 5, data_ov001_021ca414->mUnk_0c, data_ov001_021ca414->mUnk_10);
            if (data_ov001_021ca414->mUnk_a0 != 0) {
                if (func_020cccb4() == 0x12) {
                    data_ov001_021ca414->mUnk_9e = 8;
                }
                if (data_ov001_021ca414->mUnk_a4 == 0) {
                    data_ov001_021ca414->mUnk_9e = 8;
                    func_02124a20(data_ov001_021a6e7c[i][2], 0xb, data_ov001_021ca414->mUnk_0c,
                                  data_ov001_021ca414->mUnk_10);
                    func_02124a20(data_ov001_021a6e7c[i][1], 0xe, data_ov001_021ca414->mUnk_0c,
                                  data_ov001_021ca414->mUnk_10);
                    func_021057f0(3, func_02029608());
                }
            }
        }
        data_ov001_021ca414->mUnk_44[cnt10 + data_ov001_021a6e10[i][1]].mUnk_00 = 1;
        func_ov001_021a0e08((s32) ((s16) i), (u16 *) buf);
        func_0212426c(1, data_ov001_021a6e10[i][1], data_ov001_021ca414->mUnk_18, buf, data_ov001_021ca414->mUnk_10,
                      data_ov001_021ca414->mUnk_44);
        func_02124a98(data_ov001_021a6e7c[i][0], 1, data_ov001_021ca414->mUnk_0c, data_ov001_021ca414->mUnk_10);
    }
    data_ov001_021ca414->mUnk_44[45].mUnk_00 = 1;
}

void func_ov001_021a09a4(void) {
    s32 k;
    s32 ra;
    s32 ga;
    s32 ba;
    s32 rb;
    s32 gb;
    s32 bb;
    s32 c0;
    s32 c1;
    s32 c2;
    volatile u16 zero;
    u8 *pal;
    s32 col0;
    s32 col1;
    s32 cnt;
    s32 t;
    s32 d;
    s32 r;
    s32 g;
    s32 bl;

    if (data_ov001_021ca414->mUnk_a0 != 0) {
        if (data_ov001_021ca414->mUnk_a4 == 0) {
            data_ov001_021ca414->mUnk_a8 = data_ov001_021ca414->mUnk_a8 + 1;
            if (data_ov001_021ca414->mUnk_a8 >= 100) {
                data_ov001_021ca414->mUnk_a8 = 0;
            }
            if (data_ov001_021ca414->mUnk_9e == 8) {
                c0 = 9;
                c1 = 10;
                c2 = 11;
            } else {
                c0 = 12;
                c1 = 13;
                c2 = 14;
            }
            zero = 0;
            func_0214cfe4(zero, data_ov001_021ca414->mUnk_20, 0x20);
            pal = data_ov001_021ca414->mUnk_1c->mUnk_0c;
            for (k = 0; k < 16; k++) {
                col0 = ((u16 *) (pal + c0 * 32))[k];
                col1 = ((u16 *) (pal + c1 * 32))[k];
                ra = col0 & 0x1f;
                ga = (col0 & 0x3e0) >> 5;
                ba = (col0 & 0x7c00) >> 10;
                rb = col1 & 0x1f;
                gb = (col1 & 0x3e0) >> 5;
                bb = (col1 & 0x7c00) >> 10;
                cnt = data_ov001_021ca414->mUnk_a8;
                if (cnt < 50) {
                    r = ra + cnt * (rb - ra) * 2 / 100;
                    g = ga + cnt * (gb - ga) * 2 / 100;
                    bl = ba + cnt * (bb - ba) * 2 / 100;
                } else {
                    t = cnt - 50;
                    d = ra - rb;
                    r = rb + d * t * 2 / 100;
                    d = ga - gb;
                    g = gb + d * t * 2 / 100;
                    d = ba - bb;
                    bl = bb + d * t * 2 / 100;
                }
                data_ov001_021ca414->mUnk_20[k] = r | ((bl << 10) | (g << 5));
            }
            func_0200ee74(data_ov001_021ca414->mUnk_20, 0x20);
            func_02016468(0x1e, c2 << 5, data_ov001_021ca414->mUnk_20, 0x20);
        }
    }
}

void func_ov001_021a08d8(void) {
    s32 i;
    s32 cnt;
    s16 n;
    for (i = 0; i < 9; i++) {
        data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][1]].mUnk_00 = 0;
        data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][2]].mUnk_00 = 0;
        data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][3]].mUnk_00 = 0;
        data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][4]].mUnk_00 = 0;
        cnt = data_ov001_021ca414->mUnk_6c[i];
        if (cnt > 0) {
            data_ov001_021ca414->mUnk_6c[i] = cnt - 1;
            data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][3]].mUnk_00 = 1;
            n = data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][2]].mUnk_06 + 1;
            data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][3]].mUnk_06 = n;
        } else if (data_ov001_021ca414->mUnk_9e == i) {
            data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][2]].mUnk_00 = 1;
        } else if (i == 8) {
            if (data_ov001_021ca414->mUnk_a0) {
                data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][1]].mUnk_00 = 1;
            } else {
                data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][4]].mUnk_00 = 1;
            }
        } else {
            data_ov001_021ca414->mUnk_44[data_ov001_021a6e7c[i][1]].mUnk_00 = 1;
        }
    }
}

void func_ov001_021a0774(void) {
    Unk021ca414 *d;
    s32 i;
    s32 out;
    s32 ret;
    data_ov001_021ca414->mUnk_40[data_ov001_021a6d88[func_02029608() - 1]].mUnk_00 = 0;
    data_ov001_021ca414->mUnk_40[9].mUnk_00 = 0;
    for (i = 0; i < 9; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6dd4[i]].mUnk_00 = 0;
    }
    if (data_ov001_021ca414->mUnk_9e == 8) {
        data_ov001_021ca414->mUnk_40[0].mUnk_00 = 0;
        data_ov001_021ca414->mUnk_40[1].mUnk_00 = 1;
    } else {
        data_ov001_021ca414->mUnk_40[0].mUnk_00 = 1;
        data_ov001_021ca414->mUnk_40[1].mUnk_00 = 0;
        data_ov001_021ca414->mUnk_40[data_ov001_021a6d88[func_02029608() - 1]].mUnk_00 = 1;
        data_ov001_021ca414->mUnk_40[9].mUnk_00 = 1;
        data_ov001_021ca414->mUnk_40[data_ov001_021a6dd4[data_ov001_021ca414->mUnk_9e]].mUnk_00 = 1;
    }
    ret = func_0205fd78((u8) func_02029608(), (u8) (data_ov001_021ca414->mUnk_9e + 1), &out);
    data_ov001_021ca414->mUnk_40[18].mUnk_00 = 0;
    for (i = 0; i < 6; i++) {
        data_ov001_021ca414->mUnk_40[data_ov001_021a6d7c[i]].mUnk_00 = 0;
    }
    if (ret != 0 && out <= 7) {
        if (out <= 4) {
            data_ov001_021ca414->mUnk_40[18].mUnk_00 = 1;
        }
        data_ov001_021ca414->mUnk_40[data_ov001_021a6d7c[out - 2]].mUnk_00 = 1;
    }
    d = data_ov001_021ca414;
    func_0212426c(0, 0, data_ov001_021ca414->mUnk_08,
                  func_020b3f7c(d->mUnk_58, d->mUnk_50[func_0203b680((u32) (data_ov001_021ca414->mUnk_4c),
                                                                     (u32) (func_02029608()), (u32) (d->mUnk_9e + 1)) -
                                                       1]
                                                .mUnk_0c),
                  d->mUnk_04, d->mUnk_40);
}
