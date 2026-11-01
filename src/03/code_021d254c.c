#include "03/code_021d254c.h"

void func_ov003_021d254c(int a, int b, u32 c, int d) {
    u32 e;

    switch (b) {
        case 0:
            if (a == 1) {
                e = *(u16 *) 0x4001048;
                e = (e & ~0x3f) | c;
                if (d != 0) {
                    e |= 0x20;
                }
                *(u16 *) 0x4001048 = e;
            } else {
                e = *(u16 *) 0x4000048;
                e = (e & ~0x3f) | c;
                if (d != 0) {
                    e |= 0x20;
                }
                *(u16 *) 0x4000048 = e;
            }
            break;
        case 1:
            if (a == 1) {
                e = (*(u16 *) 0x4001048 & 0xffffc0ff) | (c << 8);
                if (d != 0) {
                    e |= 0x2000;
                }
                *(u16 *) 0x4001048 = e;
            } else {
                e = (*(u16 *) 0x4000048 & 0xffffc0ff) | (c << 8);
                if (d != 0) {
                    e |= 0x2000;
                }
                *(u16 *) 0x4000048 = e;
            }
            break;
        case 2:
            if (a == 1) {
                e = (*(u16 *) 0x400104a & 0xffffc0ff) | (c << 8);
                if (d != 0) {
                    e |= 0x2000;
                }
                *(u16 *) 0x400104a = e;
            } else {
                e = (*(u16 *) 0x400004a & 0xffffc0ff) | (c << 8);
                if (d != 0) {
                    e |= 0x2000;
                }
                *(u16 *) 0x400004a = e;
            }
            break;
        case 3:
            if (a == 1) {
                e = *(u16 *) 0x400104a;
                e = (e & ~0x3f) | c;
                if (d != 0) {
                    e |= 0x20;
                }
                *(u16 *) 0x400104a = e;
            } else {
                e = *(u16 *) 0x400004a;
                e = (e & ~0x3f) | c;
                if (d != 0) {
                    e |= 0x20;
                }
                *(u16 *) 0x400004a = e;
            }
            break;
    }
}

void func_ov003_021d2658(int a, int b, u16 *c) {
    u16 d;
    u16 e;
    u16 f;

    if (a == 1) {
        if (b == 0) {
            d = c[3];
            e = c[1];
            f = c[0];
            *(u16 *) 0x4001040 = ((f << 8) & 0xff00) | (c[2] & 0xff);
            *(u16 *) 0x4001044 = ((e << 8) & 0xff00) | (d & 0xff);
        } else {
            d = c[3];
            e = c[1];
            f = c[0];
            *(u16 *) 0x4001042 = ((f << 8) & 0xff00) | (c[2] & 0xff);
            *(u16 *) 0x4001046 = ((e << 8) & 0xff00) | (d & 0xff);
        }
    } else {
        if (b == 0) {
            d = c[3];
            e = c[1];
            f = c[0];
            *(u16 *) 0x4000040 = ((f << 8) & 0xff00) | (c[2] & 0xff);
            *(u16 *) 0x4000044 = ((e << 8) & 0xff00) | (d & 0xff);
        } else {
            d = c[3];
            e = c[1];
            f = c[0];
            *(u16 *) 0x4000042 = ((f << 8) & 0xff00) | (c[2] & 0xff);
            *(u16 *) 0x4000046 = ((e << 8) & 0xff00) | (d & 0xff);
        }
    }
}

void func_ov003_021d272c(int param_1, u32 param_2) {
    vu32 *a;
    u32 b;

    if (param_1 == 1) {
        a = (vu32 *) 0x4001000;
        b = (*a & 0x1f00) >> 8;
        *a = (*a & 0xffffe0ff) | ((~param_2 & b) << 8);
    } else {
        a = (vu32 *) 0x4000000;
        b = (*a & 0x1f00) >> 8;
        *a = (*a & 0xffffe0ff) | ((~param_2 & b) << 8);
    }
}

void func_ov003_021d2784(int param_1, u32 param_2) {
    vu32 *a;
    u32 b;

    if (param_1 == 1) {
        a = (vu32 *) 0x4001000;
        b = (*a & 0x1f00) >> 8;
        *a = (*a & 0xffffe0ff) | ((param_2 | b) << 8);
    } else {
        a = (vu32 *) 0x4000000;
        b = (*a & 0x1f00) >> 8;
        *a = (*a & 0xffffe0ff) | ((param_2 | b) << 8);
    }
}
