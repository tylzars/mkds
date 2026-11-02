#include "00/code_02197ddc.h"
#include "00/code_021a3690.h"

u32 func_ov000_02197e60(int *a, int b) {
    int v1;
    v1 = (s32) func_ov000_021a3690(b);
    *a = v1;
    if (*a == 0) {
        return 0;
    }
    a[1] = b;
    return 1;
}

int func_ov000_02197e58(int a) {
    return *(s32 *) (a + 4) - *(s32 *) (a + 8);
}

void func_ov000_02197e20(int *a, u8 b) {
    int v1;
    if (a[2] >= a[1]) {
        func_0213442c(data_ov000_021b3f34, data_ov000_021b3ebc, 0, 0x23);
    }
    v1 = a[2];
    a[2] = v1 + 1;
    *(u8 *) (*a + v1) = b;
    return;
}

void func_ov000_02197ddc(int *a, u32 b) {
    int v1;
    if (a[2] + 2 > a[1]) {
        func_0213442c(data_ov000_021b3f10, data_ov000_021b3ebc, 0, 0x2e);
    }
    v1 = a[2];
    a[2] = v1 + 1;
    *(s8 *) (*a + v1) = (s32) b >> 8;
    v1 = a[2];
    a[2] = v1 + 1;
    *(s8 *) (*a + v1) = (s8) b;
    return;
}
