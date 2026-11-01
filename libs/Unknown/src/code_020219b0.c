#include "code_020219b0.h"

void func_020219b0(Unk02021968 *arg0, u32 arg1, void *arg2) {
    u32 value0 = (u32) arg0;
    u32 value1 = arg1;
    u32 value2 = (u32) arg2;
    u32 value4;
    u32 value5;
    u32 value6;
    value6 = value0;
    value5 = value1;
    value4 = value2;
    func_02020e50();
    value0 = (value6) + (0x3cu);
    value2 = (value6) + ((value5 << 2));
    value0 = (value0) + ((value5 << 2));
    value1 = 4u;
    *(u32 *) ((value2) + (60)) = value4;
    func_0200ee58((void *) value0, (int) value1);
    func_02020e3c();
}
