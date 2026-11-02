#include "Main/Unknown/code_020c4bb0.h"

#include "Main/Unknown/code_020c4bd8.h"

u32 func_020c4bd8(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRaceStartGp;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

u16 func_020c4bb0(void) {
    u16 *v1;
    int *v2;
    v1 = ((u16 *) 0x04000304u);
    v2 = (int *) gRaceStartGp;
    *v2 = (*(u32 *) v2) + 1;
    return *v1;
}
