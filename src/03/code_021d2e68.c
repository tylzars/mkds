#include "03/code_021d2e68.h"
#include "code_0200c914.h"

void func_ov003_021d2e90(u32 p0) {
    u32 v1 = ((p0) + (0x0u));
    u32 v3 = OS_DisableIrqMask(0x1u);
    u32 v4 = (*(u32 *) ((v1) + (4)));
    u32 v5 = (*(u32 *) ((v1) + (0)));
    u32 v7;
    u32 v8;
    u32 v12;
    u32 v14;
    *(u32 *) ((v5) + (4)) = v4;
    v7 = (*(u32 *) ((v1) + (0)));
    v8 = (*(u32 *) ((v1) + (4)));
    *(u32 *) ((v8) + (0)) = v7;
    *(u32 *) ((v1) + (4)) = 0x0u;
    v12 = (*(u32 *) ((v1) + (4)));
    *(u32 *) ((v1) + (0)) = v12;
    v14 = OS_EnableIrqMask(v3);
}

void func_ov003_021d2e68(u32 p0, u32 p1) {
    u32 v2 = ((p0) + (0x0u));
    u32 v3 = ((p1) + (0x0u));
    u32 v5 = OS_DisableIrqMask(0x1u);
    u32 v6 = (*(u32 *) ((v2) + (0)));
    u32 v8;
    u32 v12;
    *(u32 *) ((v6) + (4)) = v3;
    v8 = (*(u32 *) ((v2) + (0)));
    *(u32 *) ((v3) + (0)) = v8;
    *(u32 *) ((v3) + (4)) = v2;
    *(u32 *) ((v2) + (0)) = v3;
    v12 = OS_EnableIrqMask(v5);
}
