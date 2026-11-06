#include "00/code_021acc8c.h"
#include "00/code_021acec8.h"
#include "code_0214d018.h"

s32 func_ov000_021ace90(const u16 *a, s32 n) {
    if (a[n - 1] & 0x8000) {
        return -1;
    }
    if (func_ov000_021acec8(a, n) != 0) {
        return 1;
    }
    return 0;
}

void func_ov000_021ace14(u16 *a, const u16 *b, const u16 *c, s32 n) {
    s32 d;
    s32 e;
    s32 i;
    u32 t;
    u32 k;

    d = func_ov000_021acec8(b, n);
    e = func_ov000_021acec8(c, n);
    if (d < e) {
        d = e;
    }
    if (d != n) {
        d++;
    }
    k = 0;
    for (i = 0; i < d; i++) {
        t = b[i] + c[i] + k;
        a[i] = t;
        k = t >> 16;
    }
    if (a != b && a != c) {
        MI_CpuFill8(a + i, 0, (n - i) * 2);
    }
}

void func_ov000_021acdd0(u16 *a, const u16 *b, u32 c, s32 n) {
    s32 i;

    for (i = 0; i < n; i++) {
        c += b[i];
        a[i] = c;
        c >>= 16;
        if (c == 0) {
            break;
        }
    }
    if (a != b) {
        for (i++; i < n; i++) {
            a[i] = b[i];
        }
    }
}

void func_ov000_021acda8(u16 *a, s32 n) {
    s32 i;

    for (i = 0; i < n; i++) {
        a[i] = ~a[i];
    }
    func_ov000_021acdd0(a, a, 1, n);
}

void func_ov000_021acd24(u16 *a, const u16 *b, const u16 *c, s32 n) {
    s32 d;
    s32 e;
    s32 i;
    s32 t;
    s32 k;

    d = func_ov000_021acec8(b, n);
    e = func_ov000_021acec8(c, n);
    if (d < e) {
        d = e;
    }
    if (d != n) {
        d++;
    }
    k = 0;
    for (i = 0; i < d || (i < n && k != 0); i++) {
        t = b[i] - c[i] + k;
        a[i] = t;
        k = t >> 16;
    }
    if (a != b && a != c) {
        MI_CpuFill8(a + i, 0, (n - i) * 2);
    }
}

void func_ov000_021acccc(u16 *a, const u16 *b, u32 c, s32 n) {
    s32 i;

    for (i = 0; i < n; i++) {
        c = b[i] - c;
        a[i] = c;
        c = (c >> 16) & 1;
        if (c == 0) {
            break;
        }
    }
    if (a != b) {
        for (i++; i < n; i++) {
            a[i] = b[i];
        }
    }
}

s32 func_ov000_021acc8c(const u16 *a, const u16 *b, s32 n) {
    s32 i;

    for (i = n - 1; i >= 0; i--) {
        if (a[i] > b[i]) {
            return 1;
        }
        if (a[i] < b[i]) {
            return -1;
        }
    }
    return 0;
}
