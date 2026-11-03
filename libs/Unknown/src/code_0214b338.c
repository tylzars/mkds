#include "code_0214b338.h"
#include "Main/Unknown/code_02148000.h"
#include "code_02148d34.h"
#include "code_02149e90.h"
#include "code_0214c778.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_02180000.h"

void func_0214b720(void) {
    s32 v;

    v = func_0214903c();
    data_021802e0 = v;
    switch (v) {
        case 0:
            break;
        case 0x10:
            data_021802dc = 0x6880000;
            data_021802d8 = 0;
            break;
        case 0x40:
            data_021802dc = 0x6894000;
            data_021802d8 = 0x4000;
            break;
        case 0x20:
        case 0x60:
            data_021802dc = 0x6890000;
            data_021802d8 = 0;
            break;
    }
}

void func_0214b6a0(const void *a, u32 b, u32 c) {
    u32 d;

    d = data_021802dc + b - data_021802d8;
    if (data_0216f074[0] != -1) {
        func_0214c990(data_0216f074[0], a, (void *) d, c, 0, 0);
    } else {
        func_0214d02c(a, (void *) d, c);
    }
}

void func_0214b63c(void) {
    if (data_0216f074[0] != -1) {
        func_0214c920(data_0216f074[0]);
    }
    func_021498a0(data_021802e0);
    data_021802e0 = 0;
    data_021802dc = 0;
    data_021802d8 = 0;
}

void func_0214b5cc(void) {
    s32 v;

    v = func_02149018();
    data_021802d4 = v;
    if (v == 0) {
        return;
    }
    switch (v) {
        case 0x20:
            data_021802d0 = 0x6890000;
            break;
        case 0x40:
            data_021802d0 = 0x6894000;
            break;
    }
}

void func_0214b558(const void *a, u32 b, u32 c) {
    u32 d;

    d = data_021802d0 + b;
    if (data_0216f074[0] != -1) {
        func_0214c990(data_0216f074[0], a, (void *) d, c, 0, 0);
    } else {
        func_0214d02c(a, (void *) d, c);
    }
}

void func_0214b500(void) {
    if (data_0216f074[0] != -1) {
        func_0214c920(data_0216f074[0]);
    }
    func_021497e8(data_021802d4);
    data_021802d4 = 0;
    data_021802d0 = 0;
}

void func_0214b4dc(void) {
    data_021802cc = func_02148f8c();
}

void func_0214b468(const void *a, u32 b, u32 c) {
    if (data_0216f074[0] != -1) {
        func_0214c990(data_0216f074[0], a, (void *) (b + 0x6898000), c, 0, 0);
    } else {
        func_0214d02c(a, (void *) (b + 0x6898000), c);
    }
}

void func_0214b41c(void) {
    if (data_0216f074[0] != -1) {
        func_0214c920(data_0216f074[0]);
    }
    func_02149124(data_021802cc);
    data_021802cc = 0;
}

void func_0214b3f8(void) {
    data_021802e4 = func_02148f64();
}

void func_0214b384(const void *a, u32 b, u32 c) {
    if (data_0216f074[0] != -1) {
        func_0214c990(data_0216f074[0], a, (void *) (b + 0x68a0000), c, 0, 0);
    } else {
        func_0214d02c(a, (void *) (b + 0x68a0000), c);
    }
}

void func_0214b338(void) {
    if (data_0216f074[0] != -1) {
        func_0214c920(data_0216f074[0]);
    }
    func_02149098(data_021802e4);
    data_021802e4 = 0;
}
