#include "01/code_02180ce8.h"

#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_02147cd8.h"
#include "01/code_0218155c.h"
#include "01/code_02188950.h"
#include "01/code_02188e88.h"
#include "01/code_02181000.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0d9c.h"

void func_ov001_02181274(s32 p0, s32 p1, s32 p2) {
    s32 j;
    s32 i;
    void *heap;

    heap = func_020364e0(func_020364e8());
    data_ov001_021a9b88 = func_02036b74(heap, 0x30, 0x20);
    data_ov001_021a9b88->mUnk_00 = p0;
    data_ov001_021a9b88->mUnk_04 = p1;
    data_ov001_021a9b88->mUnk_08 = p2;
    heap = func_020364e0(func_020364e8());
    data_ov001_021a9b88->mUnk_18 = (u16 *) func_02036b74(heap, data_ov001_021a9b88->mUnk_08 * 2, 0x20);
    heap = func_020364e0(func_020364e8());
    data_ov001_021a9b88->mUnk_1c =
        (u8 *) func_02036b74(heap, data_ov001_021a9b88->mUnk_04 / 8 * (data_ov001_021a9b88->mUnk_04 / 8), 0x20);
    func_0214d168(data_ov001_021a9b88->mUnk_1c, data_ov001_021a9b88->mUnk_00 / 8 * data_ov001_021a9b88->mUnk_00 / 8,
                  data_ov001_021a9b88->mUnk_04 / 8 * (data_ov001_021a9b88->mUnk_04 / 8));
    for (i = 0; i < data_ov001_021a9b88->mUnk_00 / 8; i++) {
        for (j = 0; j < data_ov001_021a9b88->mUnk_00 / 8; j++) {
            data_ov001_021a9b88->mUnk_1c[i * data_ov001_021a9b88->mUnk_04 / 8 + j] =
                j + i * data_ov001_021a9b88->mUnk_00 / 8;
        }
    }
    heap = func_020364e0(func_020364e8());
    data_ov001_021a9b88->mUnk_20 =
        (u8 *) func_02036b74(heap, data_ov001_021a9b88->mUnk_00 * data_ov001_021a9b88->mUnk_00 + 0x40, 0x20);
    heap = func_020364e0(func_020364e8());
    data_ov001_021a9b88->mUnk_24 =
        (u8 *) func_02036b74(heap, data_ov001_021a9b88->mUnk_00 * data_ov001_021a9b88->mUnk_00 + 0x40, 0x20);
    heap = func_020364e0(func_020364e8());
    data_ov001_021a9b88->mUnk_28 =
        (u8 *) func_02036b74(heap, data_ov001_021a9b88->mUnk_00 * data_ov001_021a9b88->mUnk_00, 0x20);
    heap = func_020364e0(func_020364e8());
    data_ov001_021a9b88->mUnk_2c =
        (u8 *) func_02036b74(heap, data_ov001_021a9b88->mUnk_00 * data_ov001_021a9b88->mUnk_00 * 2, 0x20);
}

u32 func_ov001_02181268(void) {
    return ((u32) data_ov001_021a9b88->mUnk_00);
}

u8 *func_ov001_02181200(s32 p0, s32 p1) {
    if (p0 >= 0 && p0 < data_ov001_021a9b88->mUnk_00 && p1 >= 0 && p1 < data_ov001_021a9b88->mUnk_00) {
        return data_ov001_021a9b88->mUnk_20 +
               ((p1 & 7) * 8 + ((p0 & 7) + p0 / 8 * 64) + data_ov001_021a9b88->mUnk_00 / 8 * (p1 / 8 * 64));
    }
    return NULL;
}

void func_ov001_021811c8(void) {
    if (data_ov001_021a9b88->mUnk_0c == 0) {
        data_ov001_021a9b88->mUnk_10 = 1;
        data_ov001_021a9b88->mUnk_0c = 1;
        data_ov001_021a9b88->mUnk_14 = 0;
        func_0214d0a8(data_ov001_021a9b88->mUnk_20, data_ov001_021a9b88->mUnk_24,
                      data_ov001_021a9b88->mUnk_00 * data_ov001_021a9b88->mUnk_00);
    }
}

u32 func_ov001_021811bc(void) {
    return ((u32) data_ov001_021a9b88->mUnk_1c);
}

u32 func_ov001_021811b8(void) {
    return 0x0u;
}

int func_ov001_02181198(void) {
    int v1;
    v1 = _s32_div_f((u32) data_ov001_021a9b88->mUnk_04, 8);
    return v1 * v1;
}

u32 func_ov001_02181194(void) {
    return 0x0u;
}

u32 func_ov001_02181180(void) {
    return (u32) data_ov001_021a9b88->mUnk_00 * (u32) data_ov001_021a9b88->mUnk_00 + 0x40;
}

u32 func_ov001_02181174(void) {
    return ((u32) data_ov001_021a9b88->mUnk_20);
}

u32 func_ov001_02181124(u8 *a) {
    int i;
    u32 ret;

    ret = 0;
    for (i = 0; i < data_ov001_021a9b88->mUnk_00 * data_ov001_021a9b88->mUnk_00; i++) {
        if (data_ov001_021a9b88->mUnk_20[i] != a[i]) {
            ret = 1;
            func_ov001_021811c8();
            data_ov001_021a9b88->mUnk_20[i] = a[i];
        }
    }
    return ret;
}

s32 func_ov001_021810bc(u8 *p0, u16 *p1) {
    s32 i;
    BOOL changed;

    changed = FALSE;
    for (i = 0; i < data_ov001_021a9b88->mUnk_00 * data_ov001_021a9b88->mUnk_00; i++) {
        if (p0[i] < data_ov001_021a9b88->mUnk_08 && data_ov001_021a9b88->mUnk_20[i] != (u8) p1[p0[i]]) {
            changed = TRUE;
            func_ov001_021811c8();
            data_ov001_021a9b88->mUnk_20[i] = p1[p0[i]];
        }
    }
    return changed;
}

void func_ov001_02181098(void) {
    u8 *tmp;

    tmp = data_ov001_021a9b88->mUnk_20;
    data_ov001_021a9b88->mUnk_20 = data_ov001_021a9b88->mUnk_24;
    data_ov001_021a9b88->mUnk_24 = tmp;
    data_ov001_021a9b88->mUnk_14 = data_ov001_021a9b88->mUnk_14 == 0 ? 1 : 0;
}

u32 func_ov001_0218108c(void) {
    return ((u32) data_ov001_021a9b88->mUnk_14);
}

void func_ov001_0218107c(void) {
    data_ov001_021a9b88->mUnk_0c = 0;
}

u32 func_ov001_02181070(void) {
    return ((u32) data_ov001_021a9b88->mUnk_10);
}

void func_ov001_02181048(void) {
    data_ov001_021a9b88->mUnk_10 = 0;
    data_ov001_021a9b88->mUnk_0c = 0;
    data_ov001_021a9b88->mUnk_14 = 0;
    func_0214d0a8(data_ov001_021a9b88->mUnk_20, data_ov001_021a9b88->mUnk_24,
                  data_ov001_021a9b88->mUnk_00 * data_ov001_021a9b88->mUnk_00);
}

u32 func_ov001_02181020(u32 a, u32 b, u32 c) {
    u8 *v1;
    u32 v2;
    v2 = 0;
    v1 = func_ov001_02181200(a, b);
    if ((v1 != NULL) && (*v1 != c)) {
        v2 = 1;
        func_ov001_021811c8();
        *v1 = (u8) c;
    }
    return v2;
}

u8 func_ov001_02181004(s32 a, s32 b) {
    u8 *v1;
    v1 = func_ov001_02181200(a, b);
    if (v1 != NULL) {
        return *v1;
    }
    return 0;
}

s32 func_ov001_02180eec(s32 p0, s32 p1, s32 p2, s32 p3, s32 p4) {
    s32 dy;
    s32 dx;
    s32 stepY;
    s32 stepX;
    BOOL changed;
    s32 n;
    s32 i;
    u8 *ptr;

    changed = FALSE;
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
        if (ptr != NULL && *ptr != p4) {
            changed = TRUE;
            func_ov001_021811c8();
            *ptr = p4;
        }
    }
    ptr = func_ov001_02181200(p2 >> 12, p3 >> 12);
    if (ptr != NULL && *ptr != p4) {
        changed = TRUE;
        func_ov001_021811c8();
        *ptr = p4;
    }
    return changed;
}

s32 func_ov001_02180ce8(s32 p0, s32 p1, s32 p2) {
    BOOL result;
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

    result = FALSE;
    s0.mUnk_00 = p0;
    s0.mUnk_01 = p1;
    ptr = func_ov001_02181200(s0.mUnk_00, s0.mUnk_01);
    if (ptr != NULL) {
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
                        if (ptr == NULL || *ptr != val) {
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
                        if (ptr != NULL && *ptr == val && *q == 0) {
                            do {
                                s1.mUnk_00++;
                                ptr = func_ov001_02181200(s1.mUnk_00, s1.mUnk_01);
                                q = &data_ov001_021a9b88
                                         ->mUnk_28[s1.mUnk_00 + s1.mUnk_01 * data_ov001_021a9b88->mUnk_00];
                            } while (ptr != NULL && *ptr == val && *q == 0);
                            s1.mUnk_00--;
                            ((Unk02180ce8 *) data_ov001_021a9b88->mUnk_2c)[top++] = s1;
                        }
                    }
                    sm++;
                }
            } while (top > 0);
            result = TRUE;
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
