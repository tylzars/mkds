#include "00/code_021afe5c.h"

#include "code_0200dc3c.h"
#include "code_0214d018.h"
#include "00/code_021a6934.h"

void func_ov000_021affcc(u8 *a, u32 b, const void *c, u32 d) {
    u8 e;

    if (a + b != c) {
        func_0214d1fc(c, a + b, d);
    }
    func_0214d1fc(data_ov000_021b4c40, a + 6, 6);
    if (func_ov000_021a6974(a, a + 6, b + d - 6) < 0) {
        e = 1;
    } else {
        e = 0;
    }
    data_ov000_021b6364 = e;
}

void func_ov000_021afe84(const void *a, const void *b, u8 *c, u32 d, void *e, u32 f) {
    u8 *g;
    u32 h;
    u32 i;
    u16 j;
    u32 k;
    u32 l;
    u32 m;

    g = data_ov000_021b63c4;
    if (g == 0) {
        return;
    }
    h = data_ov000_021b63c8;
    if (h == 0) {
        return;
    }
    i = d + f;
    if (i < 8 || i > 0x5e4) {
        return;
    }
    if (c[0] != data_ov000_021b4c40[0] || c[1] != data_ov000_021b4c40[1] || c[2] != data_ov000_021b4c40[2]) {
        return;
    }
    if (c[6] != 8) {
        return;
    }
    if (c[7] != 0 && c[7] != 6) {
        return;
    }
    j = (i + 9) & ~1;
    k = data_ov000_021b6394;
    l = k + j;
    m = l;
    i = data_ov000_021b63cc;
    if (k < i && i <= l) {
        return;
    }
    if (l == h) {
        m = 0;
        if (i == 0) {
            return;
        }
    } else if (l > h) {
        m = j;
        if (i <= j) {
            return;
        }
    }
    if (l > h) {
        if (h - k >= 2) {
            g[k] = 0;
            (data_ov000_021b63c4 + data_ov000_021b6394)[1] = 0;
        }
        data_ov000_021b6394 = 0;
    }
    data_ov000_021b63c4[data_ov000_021b6394] = j;
    (data_ov000_021b63c4 + data_ov000_021b6394)[1] = j >> 8;
    func_0214d1fc(b, data_ov000_021b63c4 + data_ov000_021b6394 + 2, 6);
    func_0214d1fc(a, data_ov000_021b63c4 + data_ov000_021b6394 + 8, 6);
    func_0214d1fc(c + 6, data_ov000_021b63c4 + data_ov000_021b6394 + 0xe, d - 6);
    if (e != 0 && f != 0) {
        func_0214d1fc(e, data_ov000_021b63c4 + data_ov000_021b6394 + 8 + d, f);
    }
    data_ov000_021b6394 = m;
}

void func_ov000_021afe5c(void *a, void *b, void *c, u16 d) {
    func_ov000_021afe84(a, b, c, d, 0, 0);
    if (data_ov000_021b63c0 != 0) {
        func_0200df68(data_ov000_021b63c0);
    }
}
