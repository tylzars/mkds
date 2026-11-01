#include "00/code_021a369c.h"

void *func_ov000_021a372c(u32 heap, u32 size) {
    return (*(void *(**) (u32, u32, u32)) & data_ov000_021b5df0)(heap, size, 0x20);
}

void *func_ov000_021a3718(u32 p0, u32 p1, u32 p2) {
    u32 v2 = ((u32) (&data_ov000_021b5df0));
    u32 v3 = ((u32) * (u32 *) ((v2) + (0)));
    u32 v4 = ((u32(*)(u32, u32, u32))(v3))(p0, p1, p2);
    return (void *) v4;
}

void func_ov000_021a3704(u32 p0, u32 p1, u32 p2) {
    u32 v2 = ((u32) (&data_ov000_021b5dec));
    u32 v3 = ((u32) * (u32 *) ((v2) + (0)));
    u32 v4 = ((u32(*)(u32, u32, u32))(v3))(p0, p1, p2);
}

void *func_ov000_021a36f0(u32 p0, void *p1, u32 p2, u32 p3) {
    return func_ov000_021a369c(p0, p1, p2, p3, 0x20);
}

void *func_ov000_021a369c(u32 param_1, void *param_2, u32 param_3, u32 param_4, u32 param_5) {
    void *v1;
    v1 = (*(void *(**) (u32, u32, u32)) & data_ov000_021b5df0)(param_1, param_4, param_5);
    if (v1 == 0) {
        return 0;
    }
    if (param_2 != 0) {
        func_0214d1fc(param_2, v1, param_4);
        (*(UnkWordFunc *) (*(u32 *) &data_ov000_021b5dec))(param_1, param_2, param_3);
    }
    return v1;
}
