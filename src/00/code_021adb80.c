#include "00/code_021adb80.h"

void func_ov000_021adb80(void) {
    int v1;
    v1 = *(int *) (*(int *) (((int) (u32) ((u8 *) &data_0216ff5c)) + 4) + 0xa4);
    if ((v1 != 0) && (*(int *) (v1 + 0x60) != 0)) {
        func_ov000_021adc64((const u8 *) (*(u32 *) (v1 + 0x5c)), (int) (*(int *) (v1 + 0x60)), (const u8 *) 0, 0);
        *(u32 *) (v1 + 0x60) = 0;
    }
}
