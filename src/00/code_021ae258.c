#include "00/code_021ae258.h"

void func_ov000_021ae2d8(void) {
    int v1;
    v1 = *(int *) (*(int *) (((int) (u32) ((u8 *) &data_0216ff5c)) + 4) + 0xa4);
    if (v1 != 0) {
        *(u8 *) (v1 + 8) = 10;
        *(u32 *) (v1 + 0x44) = 0;
    }
}

void func_ov000_021ae290(int param_1, u16 param_2, int param_3) {
    u16 v1;
    int v2;
    v2 = *(int *) (*(int *) (((int) (u32) ((u8 *) &data_0216ff5c)) + 4) + 0xa4);
    if (v2 != 0) {
        if (param_3 == 0x7f000001) {
            param_3 = *(int *) &data_ov000_021b63b4;
        }
        *(u16 *) (v2 + 0x1a) = param_2;
        *(u16 *) (v2 + 0x18) = *(u16 *) (v2 + 0x1a);
        *(int *) (v2 + 0x20) = param_3;
        *(u32 *) (v2 + 0x1c) = *(u32 *) (v2 + 0x20);
        if (param_1 == 0) {
            v1 = func_ov000_021ae340();
            *(u16 *) (v2 + 10) = v1;
            return;
        }
        *(short *) (v2 + 10) = (short) param_1;
    }
}

void func_ov000_021ae270(void) {
    int *v1;
    v1 = *(int **) (*(int *) (((int) (u32) ((u8 *) &data_0216ff5c)) + 4) + 0xa4);
    if (v1 != (int *) 0x0) {
        *v1 = *(int *) (((int) (u32) ((u8 *) &data_0216ff5c)) + 4);
        *(u8 *) (v1 + 2) = 0;
        v1[0x11] = 0;
        v1[0x18] = 0;
        v1[0xe] = 0;
    }
}

void func_ov000_021ae258(void) {
    u32 *v1;
    v1 = *(u32 **) (*(int *) (((int) (u32) ((u8 *) &data_0216ff5c)) + 4) + 0xa4);
    if (v1 != (u32 *) 0x0) {
        *v1 = 0;
    }
}
