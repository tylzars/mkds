#include "Main/Unknown/code_020ac2fc.h"

#pragma thumb on

void func_020ac454(void *a, u8 *b, s32 c) {
    s32 y;
    s32 v1;
    s32 v2;
    s32 v3;
    s32 j;
    s32 x;
    s32 s0;
    s32 i;

    v1 = c / 2;
    y = 0;
    if (c > 0) {
        v2 = y;
        v3 = c / 8;
        do {
            j = 0;
            if (v1 > 0) {
                x = j;
                s0 = 1;
                do {
                    i = j + v2;
                    b[(y & 7) * 8 + ((x & 7) + x / 8 * 64) + v3 * (y / 8 * 64)] = ((u8 *) a)[i] & 0xf;
                    b[(y & 7) * 8 + ((s0 & 7) + s0 / 8 * 64) + v3 * (y / 8 * 64)] = (((u8 *) a)[i] >> 4) & 0xf;
                    x += 2;
                    s0 += 2;
                    j++;
                } while (j < v1);
            }
            v2 += v1;
            y++;
        } while (y < c);
    }
}

void func_020ac390(void *a, u8 *b, s32 c) {
    s32 y;
    s32 v1;
    s32 v2;
    s32 v3;
    s32 j;
    s32 x;
    s32 s0;

    v1 = c / 2;
    y = 0;
    if (c > 0) {
        v2 = y;
        v3 = c / 8;
        do {
            j = 0;
            if (v1 > 0) {
                x = 1;
                s0 = j;
                do {
                    b[j + v2] = ((u8 *) a)[(y & 7) * 8 + ((s0 & 7) + s0 / 8 * 64) + v3 * (y / 8 * 64)] |
                                ((u8 *) a)[(y & 7) * 8 + ((x & 7) + x / 8 * 64) + v3 * (y / 8 * 64)] << 4;
                    x += 2;
                    s0 += 2;
                    j++;
                } while (j < v1);
            }
            v2 += v1;
            y++;
        } while (y < c);
    }
}

void func_020ac2fc(void *a, u8 *b, s32 c) {
    s32 y;
    s32 v1;
    s32 v2;
    s32 j;
    s32 x;
    s32 k;

    v2 = c / 2;
    y = 0;
    if (c > 0) {
        k = y;
        v1 = c / 8;
        do {
            j = 0;
            if (v2 > 0) {
                x = j;
                do {
                    b[((y & 7) * 8 + ((x & 7) + x / 8 * 64) + v1 * (y / 8 * 64)) / 2] = ((u8 *) a)[j + k];
                    x += 2;
                    j++;
                } while (j < v2);
            }
            k += v2;
            y++;
        } while (y < c);
    }
}

#pragma thumb off
