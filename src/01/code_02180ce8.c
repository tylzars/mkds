#include "01/code_02180ce8.h"
#include "01/code_021811c8.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_02147cd8.h"

s32 func_ov001_02180eec(s32 p0, s32 p1, s32 p2, s32 p3, s32 p4) {
    s32 dy;
    s32 dx;
    s32 stepY;
    s32 stepX;
    s32 changed;
    s32 n;
    s32 i;
    u8 *ptr;

    changed = 0;
    if ((p2 >> 12) > (p0 >> 12)) {
        dx = p2 - p0;
    } else if ((p0 >> 12) > (p2 >> 12)) {
        dx = p0 - p2;
    } else {
        dx = 0;
    }
    if ((p3 >> 12) > (p1 >> 12)) {
        dy = p3 - p1;
    } else if ((p1 >> 12) > (p3 >> 12)) {
        dy = p1 - p3;
    } else {
        dy = 0;
    }
    if (dx == 0) {
        stepX = 0;
    } else if (dx < dy) {
        stepX = func_02147f34(p2 - p0, dy);
    } else if (p2 > p0) {
        stepX = 0x1000;
    } else {
        stepX = -0x1000;
    }
    if (dy == 0) {
        stepY = 0;
    } else if (dy < dx) {
        stepY = func_02147f34(p3 - p1, dx);
    } else if (p3 > p1) {
        stepY = 0x1000;
    } else {
        stepY = -0x1000;
    }
    if (dx > dy) {
        n = dx >> 12;
    } else {
        n = dy >> 12;
    }
    for (i = 0; i <= n; i++, p0 += stepX, p1 += stepY) {
        ptr = func_ov001_02181200(p0 >> 12, p1 >> 12);
        if (ptr != 0 && *ptr != p4) {
            changed = 1;
            func_ov001_021811c8();
            *ptr = p4;
        }
    }
    ptr = func_ov001_02181200(p2 >> 12, p3 >> 12);
    if (ptr != 0 && *ptr != p4) {
        changed = 1;
        func_ov001_021811c8();
        *ptr = p4;
    }
    return changed;
}

s32 func_ov001_02180ce8(s32 p0, s32 p1, s32 p2) {
    s32 result;
    s32 top;
    s32 k;
    s32 *sm;
    u8 hi;
    s32 *sk;
    s32 py;
    s32 m;
    u8 *ptr;
    u8 *q;
    u8 val;
    u8 *b;
    Unk02180ce8 s0;
    u8 buf[2];
    Unk02180ce8 s1;

    result = 0;
    s0.mUnk_00 = p0;
    s0.mUnk_01 = p1;
    ptr = func_ov001_02181200(s0.mUnk_00, s0.mUnk_01);
    if (ptr != 0) {
        val = *ptr;
        if (val != p2) {
            top = 1;
            ((Unk02180ce8 *) data_ov001_021a9b88->mUnk_2c)[0] = s0;
            func_0214d05c_inline(data_ov001_021a9b88->mUnk_28,
                                 data_ov001_021a9b88->mUnk_00 * data_ov001_021a9b88->mUnk_00);
            do {
                s32 steps[2] = {-1, 1};

                top--;
                s0 = ((Unk02180ce8 *) data_ov001_021a9b88->mUnk_2c)[top];
                for (k = 0, b = buf, sk = steps, py = s0.mUnk_01; k < 2; k++) {
                    *b = s0.mUnk_00;
                    for (;;) {
                        ptr = func_ov001_02181200(*b, py);
                        q = &data_ov001_021a9b88->mUnk_28[*b + py * data_ov001_021a9b88->mUnk_00];
                        if (ptr == 0 || *ptr != val) {
                            break;
                        }
                        *b += *sk;
                        *q = 1;
                    }
                    *b -= *sk;
                    b++;
                    sk++;
                }
                for (m = 0, sm = steps, hi = buf[1]; m < 2; m++) {
                    s1.mUnk_01 = py + *sm;
                    for (s1.mUnk_00 = buf[0]; s1.mUnk_00 <= hi; s1.mUnk_00++) {
                        ptr = func_ov001_02181200(s1.mUnk_00, s1.mUnk_01);
                        q = &data_ov001_021a9b88->mUnk_28[s1.mUnk_00 + s1.mUnk_01 * data_ov001_021a9b88->mUnk_00];
                        if (ptr != 0 && *ptr == val && *q == 0) {
                            do {
                                s1.mUnk_00++;
                                ptr = func_ov001_02181200(s1.mUnk_00, s1.mUnk_01);
                                q = &data_ov001_021a9b88
                                         ->mUnk_28[s1.mUnk_00 + s1.mUnk_01 * data_ov001_021a9b88->mUnk_00];
                            } while (ptr != 0 && *ptr == val && *q == 0);
                            s1.mUnk_00--;
                            ((Unk02180ce8 *) data_ov001_021a9b88->mUnk_2c)[top++] = s1;
                        }
                    }
                    sm++;
                }
            } while (top > 0);
            result = 1;
            func_ov001_021811c8();
            for (s0.mUnk_01 = 0; s0.mUnk_01 < data_ov001_021a9b88->mUnk_00; s0.mUnk_01++) {
                for (s0.mUnk_00 = 0; s0.mUnk_00 < data_ov001_021a9b88->mUnk_00; s0.mUnk_00++) {
                    if (data_ov001_021a9b88->mUnk_28[s0.mUnk_00 + s0.mUnk_01 * data_ov001_021a9b88->mUnk_00] != 0) {
                        *func_ov001_02181200(s0.mUnk_00, s0.mUnk_01) = p2;
                    }
                }
            }
        }
    }
    return result;
}
