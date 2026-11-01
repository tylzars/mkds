#include "03/code_021c7a0c.h"

void func_ov003_021c7a0c(void) {
    s32 a;
    s32 b;
    s32 c;
    void *d;
    int e;
    u16 f;
    u16 g;
    u16 h[8];
    func_ov003_021c20dc(0, &b);
    a = *(s32 *) data_ov003_021da200;
    if (a >= -0x4e83) {
        c = 0x0;
    } else if (a >= -0x4e84) {
        c = 0x15;
    } else if (a >= -0x4e85) {
        c = 0x4a;
    } else if (a >= -0x4e8b) {
        c = 0x15;
    } else if (a >= -0x4e8c) {
        c = 0x49;
    } else if (a >= -0x4e8d) {
        c = 0x15;
    } else if (a >= -0x4e8e) {
        c = 0x18;
    } else if (a >= -0x5207) {
        c = 0x15;
    } else if (a >= -0x59d7) {
        c = 0x0;
    } else if (a >= -0x5dbf) {
        c = 0x4a;
    } else if (a >= -0xc34f) {
        c = 0x0;
    } else if (a >= -0xc352) {
        c = 0x35;
    } else if (a >= -0xc353) {
        c = 0x26;
    } else if (a >= -0xc3b2) {
        c = 0x0;
    } else if (a >= -0xc3b3) {
        if (b == 2) {
            c = 0x26;
        } else {
            c = 0x35;
        }
    } else if (a >= -0xc79a) {
        c = 0x0;
    } else if (a >= -0xc79b) {
        if (b == 2) {
            c = 0x26;
        } else {
            c = 0x36;
        }
    } else if (a >= -0xc79e) {
        c = 0x37;
    } else if (a >= -0xc79f) {
        c = 0x26;
    } else if (a >= -0xc7ff) {
        c = 0x0;
    } else if (a >= -0xc863) {
        c = 0x4c;
    } else if (a >= -0xc866) {
        c = 0x4d;
    } else if (a >= -0xc867) {
        c = 0x25;
    } else if (a >= -0xcb1f) {
        c = 0x0;
    } else if (a >= -0xcb22) {
        c = 0x38;
    } else if (a >= -0xcb23) {
        c = 0x4e;
    } else if (a >= -0xcb83) {
        c = 0x0;
    } else if (a >= -0xcb87) {
        c = 0x3b;
    } else if (a >= -0xcbe7) {
        c = 0x0;
    } else if (a >= -0xcbeb) {
        c = 0x3b;
    } else if (a >= -0xcc4b) {
        c = 0x0;
    } else if (a >= -0xccaf) {
        c = 0x15;
    } else if (a >= -0xcf07) {
        c = 0x0;
    } else if (a >= -0xd033) {
        c = 0x15;
    } else {
        c = 0;
    }
    d = func_ov003_021d2288(0, data_ov003_021d6408[func_ov003_021c20d0()]);
    e = func_ov003_021c2530((int *) data_ov003_021da19c, c);
    func_0213ca64(h, 8, data_ov003_021d73b0, -*(s32 *) data_ov003_021da200);
    f = data_ov003_021d641a[func_ov003_021c20d0() * 2];
    g = data_ov003_021d6418[func_ov003_021c20d0() * 2];
    func_ov003_021d2094(d, g, f, 2, 0xa, h, 0);
    func_ov003_021d2070(d, data_ov003_021d6410[0], data_ov003_021d6410[1], data_ov003_021d6410[2],
                        data_ov003_021d6410[3], 2, func_ov003_021bf4dc(), (void *) e);
    func_ov003_021d1fd0(d);
}
