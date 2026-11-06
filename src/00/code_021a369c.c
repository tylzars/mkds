#include "00/code_021a369c.h"
#include "00/unk_021b5000.h"
#include "03/code_021b94b8.h"
#include "code_0214d018.h"

u32 func_ov000_021a3744(void *(*arg0)(u32, u32, s32), void (*arg1)(u32, void *)) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    value2 = (u32) &data_ov000_021b5df0;
    *(u32 *) ((value2) + 0u) = value0;
    value0 = (u32) &data_ov000_021b5dec;
    *(u32 *) ((value0) + 0u) = value1;
    return value0;
}

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

void *func_ov000_021a369c(u32 a, void *b, u32 c, u32 d, u32 e) {
    void *v1;
    v1 = (*(void *(**) (u32, u32, u32)) & data_ov000_021b5df0)(a, d, e);
    if (v1 == NULL) {
        return NULL;
    }
    if (b != NULL) {
        MI_CpuCopy8(b, v1, d);
        (*(UnkWordFunc *) (*(u32 *) &data_ov000_021b5dec))(a, b, c);
    }
    return v1;
}
