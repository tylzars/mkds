#include "03/code_021d254c.h"
#include "registers.h"

void func_ov003_021d2784(int c, u32 d) {
    vu32 *a;
    u32 b;

    if (c == 1) {
        a = &reg_GXS_DB_DISPCNT;
        b = (*a & 0x1f00) >> 8;
        *a = (*a & 0xffffe0ff) | ((d | b) << 8);
    } else {
        a = &reg_GX_DISPCNT;
        b = (*a & 0x1f00) >> 8;
        *a = (*a & 0xffffe0ff) | ((d | b) << 8);
    }
}

void func_ov003_021d272c(int c, u32 d) {
    vu32 *a;
    u32 b;

    if (c == 1) {
        a = &reg_GXS_DB_DISPCNT;
        b = (*a & 0x1f00) >> 8;
        *a = (*a & 0xffffe0ff) | ((~d & b) << 8);
    } else {
        a = &reg_GX_DISPCNT;
        b = (*a & 0x1f00) >> 8;
        *a = (*a & 0xffffe0ff) | ((~d & b) << 8);
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
            reg_G2S_DB_WIN0H = ((f << 8) & 0xff00) | (c[2] & 0xff);
            reg_G2S_DB_WIN0V = ((e << 8) & 0xff00) | (d & 0xff);
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
            reg_G2_WIN0H = ((f << 8) & 0xff00) | (c[2] & 0xff);
            reg_G2_WIN0V = ((e << 8) & 0xff00) | (d & 0xff);
        } else {
            d = c[3];
            e = c[1];
            f = c[0];
            reg_G2_WIN1H = ((f << 8) & 0xff00) | (c[2] & 0xff);
            reg_G2_WIN1V = ((e << 8) & 0xff00) | (d & 0xff);
        }
    }
}

void func_ov003_021d254c(int a, int b, u32 c, int d) {
    u32 e;

    switch (b) {
        case 0:
            if (a == 1) {
                e = reg_G2S_DB_WININ;
                e = (e & ~0x3f) | c;
                if (d != 0) {
                    e |= 0x20;
                }
                reg_G2S_DB_WININ = e;
            } else {
                e = reg_G2_WININ;
                e = (e & ~0x3f) | c;
                if (d != 0) {
                    e |= 0x20;
                }
                reg_G2_WININ = e;
            }
            break;
        case 1:
            if (a == 1) {
                e = (reg_G2S_DB_WININ & 0xffffc0ff) | (c << 8);
                if (d != 0) {
                    e |= 0x2000;
                }
                reg_G2S_DB_WININ = e;
            } else {
                e = (reg_G2_WININ & 0xffffc0ff) | (c << 8);
                if (d != 0) {
                    e |= 0x2000;
                }
                reg_G2_WININ = e;
            }
            break;
        case 2:
            if (a == 1) {
                e = (reg_G2S_DB_WINOUT & 0xffffc0ff) | (c << 8);
                if (d != 0) {
                    e |= 0x2000;
                }
                reg_G2S_DB_WINOUT = e;
            } else {
                e = (reg_G2_WINOUT & 0xffffc0ff) | (c << 8);
                if (d != 0) {
                    e |= 0x2000;
                }
                reg_G2_WINOUT = e;
            }
            break;
        case 3:
            if (a == 1) {
                e = reg_G2S_DB_WINOUT;
                e = (e & ~0x3f) | c;
                if (d != 0) {
                    e |= 0x20;
                }
                reg_G2S_DB_WINOUT = e;
            } else {
                e = reg_G2_WINOUT;
                e = (e & ~0x3f) | c;
                if (d != 0) {
                    e |= 0x20;
                }
                reg_G2_WINOUT = e;
            }
            break;
    }
}
