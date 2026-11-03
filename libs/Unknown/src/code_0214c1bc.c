#include "code_0214c1bc.h"
#include "code_0214c778.h"
#include "Main/Unknown/code_02148000.h"
#include "code_02148950.h"
#include "code_02149e90.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_02180000.h"

// Stores func_02149004() in data_021802fc, and the halfwords at offset 6 * that value in data_021616cc, data_021616ce
// and data_021616d0, each shifted left by 12, in data_021802ec, data_02180300 and data_02180304.
void func_0214c6a8(void) {
    u32 i;
    u32 o;

    i = func_02149004();
    o = i * 6;
    data_021802fc = i;
    data_021802ec = *(u16 *) (data_021616cc + o) << 12;
    data_02180300 = *(u16 *) (data_021616ce + o) << 12;
    data_02180304 = *(u16 *) (data_021616d0 + o) << 12;
}

// Copies c bytes from a to data_021802ec + b; or, when data_02180300 is not 0, to data_02180300 + b - data_02180304 if
// b is at least data_02180304. A copy that crosses data_02180304 is split there: the first data_02180304 - b bytes go
// to data_021802ec + b, the rest to data_02180300. Each part uses func_0214c990 when data_0216f074 is not -1 (the first
// part uses func_0214cb88 when it is longer than 0x30), else func_0214d02c.
void func_0214c544(const void *a, u32 b, u32 c) {
    u8 *p;
    u32 q;
    u32 n;
    u8 *dst;

    p = (u8 *) data_02180300;
    if (p == 0) {
        dst = (u8 *) data_021802ec + b;
    } else {
        q = data_02180304;
        if (b + c < q) {
            dst = (u8 *) data_021802ec + b;
        } else if (b >= q) {
            dst = p + b - q;
        } else {
            n = q - b;
            dst = (u8 *) data_021802ec + b;
            if (data_0216f074[0] != -1 && n > 0x30) {
                func_0214cb88(data_0216f074[0], a, dst, n);
            } else {
                func_0214d02c(a, dst, n);
            }
            if (data_0216f074[0] != -1) {
                func_0214c990(data_0216f074[0], (const u8 *) a + n, p, c - n, 0, 0);
            } else {
                func_0214d02c((const u8 *) a + n, p, c - n);
            }
            return;
        }
    }
    if (data_0216f074[0] != -1) {
        func_0214c990(data_0216f074[0], a, dst, c, 0, 0);
    } else {
        func_0214d02c(a, dst, c);
    }
}

void func_0214c4d4(void) {
    if (data_0216f074[0] != -1) {
        func_0214c920(data_0216f074[0]);
    }
    func_021495e4(data_021802fc);
    data_02180304 = 0;
    data_02180300 = 0;
    data_021802ec = 0;
    data_021802fc = 0;
}

void func_0214c48c(void) {
    s32 v = func_02148ff0();
    data_021802f4 = v;
    data_021802f0 = (u8 *) (data_021616bc[v >> 4] << 12);
}

void func_0214c418(const void *a, u32 b, u32 c) {
    u8 *p = data_021802f0 + b;
    if (data_0216f074[0] != -1) {
        func_0214c990(data_0216f074[0], a, p, c, 0, 0);
    } else {
        func_0214d02c(a, p, c);
    }
}

void func_0214c3c0(void) {
    if (data_0216f074[0] != -1) {
        func_0214c920(data_0216f074[0]);
    }
    func_021494f0(data_021802f4);
    data_021802f4 = 0;
    data_021802f0 = 0;
}

void func_0214c2f8(void) {
    u32 v = func_02148fdc();
    data_021802e8 = v;
    switch (v) {
        case 2:
        case 3:
            data_021802f8 = (u8 *) 0x6800000;
            break;
        case 8:
        case 12:
            data_021802f8 = (u8 *) 0x6840000;
            break;
        case 1:
            data_021802f8 = (u8 *) 0x67e0000;
            break;
        case 4:
            data_021802f8 = (u8 *) 0x6820000;
            break;
    }
}

void func_0214c288(const void *a, u32 b) {
    u8 *p = data_021802f8;
    if (data_0216f074[0] != -1) {
        func_0214c990(data_0216f074[0], a, p, b, 0, 0);
    } else {
        func_0214d02c(a, p, b);
    }
}

void func_0214c214(const void *a, u32 b) {
    u8 *p = data_021802f8 + 0x20000;
    if (data_0216f074[0] != -1) {
        func_0214c990(data_0216f074[0], a, p, b, 0, 0);
    } else {
        func_0214d02c(a, p, b);
    }
}

void func_0214c1bc(void) {
    if (data_0216f074[0] != -1) {
        func_0214c920(data_0216f074[0]);
    }
    func_021493b0(data_021802e8);
    data_021802e8 = 0;
    data_021802f8 = 0;
}
