#include "Main/Unknown/code_02061874.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0203ca20.h"
#include "Main/Unknown/code_0207a30c.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_02062ed8.h"

// non-matching: same instructions except the registers of the first table loop.
void func_02061c28(void) {
    u32 a[32];
    u16 i;
    u8 m;

    func_02061944(72, 1);
    data_021653e8 = 72;
    data_0217aa4c = 0;
    data_0217aa64 = 0;
    data_0217aa2c = 0;
    data_0217aa54->mUnk_24 = 0;
    data_0217aa54->mUnk_20 = data_0217aa54->mUnk_24;
    if (data_02175620->mUnk_018->mUnk_05 != 0) {
        m = data_02175620->mUnk_018->mUnk_06;
        if (m == 0) {
            for (i = 0; i < 8; i++) {
                data_0217aabc[i] = (i * 16) | ((i * 16 + 4) << 8) | ((i * 16 + 8) << 16) | ((i * 16 + 12) << 24);
            }
        } else if (m == 1) {
            for (i = 0; i < 32; i++) {
                a[i] = ((i + 1) * (i + 1)) / 8;
                if (a[i] > 127) {
                    a[i] = 127;
                }
            }
            a[0] = 0;
            for (i = 0; i < 8; i++) {
                data_0217aabc[i] = a[i * 4] | (a[i * 4 + 1] << 8) | (a[i * 4 + 2] << 16) | (a[i * 4 + 3] << 24);
            }
        } else if (m == 2) {
            for (i = 0; i < 32; i++) {
                a[i] = 128 - ((32 - (i + 1)) * (32 - (i + 1))) / 8;
                if (a[i] > 127) {
                    a[i] = 127;
                }
            }
            a[0] = 0;
            for (i = 0; i < 8; i++) {
                data_0217aabc[i] = a[i * 4] | (a[i * 4 + 1] << 8) | (a[i * 4 + 2] << 16) | (a[i * 4 + 3] << 24);
            }
        }
        data_0217aa38 = data_02175620->mUnk_018->mUnk_14 & 0x7fff;
        data_0217aa50 = ((u32) data_02175620->mUnk_018->mUnk_14 >> 15) & 31;
        data_0217aa80 = data_02175620->mUnk_018->mUnk_07;
        data_0217aa48 = data_02175620->mUnk_018->mUnk_10 / 512;
        data_0217aa40 = data_0217aa38 & 31;
        data_0217aa34 = (data_0217aa38 >> 5) & 31;
        data_0217aa3c = (data_0217aa38 >> 10) & 31;
    }
    if (data_02175620->mUnk_018->mUnk_05 != 0) {
        func_0214a7ec(1, 0, data_0217aa80, data_0217aa48);
        *(u32 *) 0x04000358 = data_0217aa38 | (data_0217aa50 << 16);
        func_0214a748(data_0217aabc);
    } else {
        func_0214a7ec(0, 0, 5, 0);
    }
}

// non-matching: same size, 32 words differ: the original multiplies the data_0217aa8c elements as signed values
// (element first, its asr inside the loop), ours zero-extends them with u as the first operand; at the start the
// data_0217aa44 value and u are in r5/r4 here (original r4/r5).
void func_02061944(s32 a, s32 b) {
    s32 t;
    s32 u;
    u32 j;
    u32 w;
    u16 i;

    if (data_02175620->mUnk_018->mUnk_05 != 0 && b == 0) {
        t = (s32) (((s64) 57 * (a << 12) + 0x800) >> 12);
        data_0217aa78 = t;
        u = 4096 - t;
        data_0217aa84 = u;
        data_0217aa44 = (s32) (((s64) t * 72 + 0x800) >> 12);
        data_0217aa28 = (s32) (((s64) data_0217aa40 * u + 0x800) >> 12) +
                        ((s32) (((s64) data_0217aa34 * u + 0x800) >> 12) << 5) +
                        ((s32) (((s64) data_0217aa3c * u + 0x800) >> 12) << 10);
        data_0217aa68 =
            (s32) (((s64) u * data_0217aa50 + 0x800) >> 12) + (s32) (((s64) t * data_0217aa60 + 0x800) >> 12);
        data_0217aa70 = (s32) (((s64) u * data_0217aa48 + 0x800) >> 12);
        for (i = 0; i < 8; i++) {
            w = data_0217aabc[i];
            data_0217aa8c[0] = w & 0xff;
            data_0217aa8c[1] = (w & 0xff00) >> 8;
            data_0217aa8c[2] = (w & 0xff0000) >> 16;
            data_0217aa8c[3] = (w & 0xff000000) >> 24;
            for (j = 0; j < 4; j++) {
                data_0217aa8c[j] = (s32) (((s64) data_0217aa8c[j] * u + 0x800) >> 12) + data_0217aa44;
            }
            data_0217aa9c[i] =
                data_0217aa8c[0] | (data_0217aa8c[1] << 8) | (data_0217aa8c[2] << 16) | (data_0217aa8c[3] << 24);
        }
        data_0217aa58 = w;
    } else {
        for (i = 0; i < 8; i++) {
            data_0217aa9c[i] = a | (a << 8) | (a << 16) | (a << 24);
        }
    }
}

void func_02061874(void) {
    if (data_0217aa54->mUnk_24 == 1) {
        data_0217aa54->mUnk_24 = 0;
    }
    data_0217aa54->mUnk_20 = 1;
    func_0207a5f0(0);
    func_02062ef8(1);
    data_021653e8 = 72;
    func_02061944(72, 1);
    data_0217aa4c = 0;
    data_0217aa64 = 1;
    data_0217aa2c = 0;
    data_0217aa70 = 0;
    data_0217aa28 = data_0217aa30;
    data_0217aa68 = data_0217aa60;
}
