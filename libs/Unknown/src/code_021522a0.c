#include "code_021522a0.h"
#include "code_02150808.h"
#include "code_02152490.h"
#include "code_021526e4.h"
#include "code_02152ab4.h"
#include "code_02152ac8.h"
#include "Main/Unknown/code_02152000.h"
#include "Main/Unknown/code_02152918.h"
#include "Main/Unknown/code_02152ab0.h"
#include "Main/Unknown/code_02152ac4.h"

#pragma thumb on

void func_02152458(Unk02152500 *a, const void *b, char *c) {
    func_02152808(b, a->mUnk_24, c);
}

s32 func_02152390(const void *a, const void *b) {
    u32 c;
    c = func_02152a58(a);
    if (c != func_02152a58(b)) {
        return 0;
    }
    if (c == 3) {
        if (func_02152ab0(a) == func_02152ab0(b)) {
            return 1;
        }
        return 0;
    }
    if (c == 1) {
        if (func_02152ac8(a) == func_02152ac8(b) && func_02152ac4(a) == func_02152ac4(b)) {
            return 1;
        }
        return 0;
    }
    if (c == 2) {
        if (func_02152ab4(a) == func_02152ab4(b)) {
            return 1;
        }
        return 0;
    }
    return 0;
}

void func_02152340(void *a, void *b) {
    u8 c[0x24];
    u64 d;
    if (func_02152a58(b) != 3) {
        if (func_02152a58(b) == 2) {
            d = func_02152ab4(b);
            func_02152918((u32) d, (u32) (d >> 32), (u32) c);
            return;
        }
        if (func_02152a58(b) == 1) {
            func_02152808(b, *(u32 *) ((u8 *) a + 0x24), (char *) &c[0xd]);
        }
    }
}

void func_02152324(void *a) {
    func_02152340(a, (u8 *) a + 4);
    func_02152340(a, (u8 *) a + 0x10);
}

u32 IsMultipleOf4(u32 a) {
    if ((a & 3) == 0) {
        return 1;
    }
    return 0;
}

s32 func_021522a0(const u32 *a) {
    s32 b;
    if (a[0] >= 100 || a[1] < 1 || a[1] > 12 || a[2] < 1 || a[2] > 31 || (s32) a[3] >= 7 || a[1] < 1 || a[1] > 12) {
        return -1;
    }
    b = a[2] - 1 + ((const u32 *) &data_0216f26c)[a[1]];
    if (a[1] >= 3 && IsMultipleOf4(a[0]) != 0) {
        b++;
    }
    b = b + a[0] * 365;
    return b + ((a[0] + 3) >> 2);
}

#pragma thumb off
