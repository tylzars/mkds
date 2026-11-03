#include "00/code_021a78a4.h"
#include "00/code_021a7bc8.h"

s32 func_ov000_021a7bc8(u32 p0, u32 p1, u32 p2, u32 p3, u32 p4) {
    u32 v2 = ((p0) + (0x0u));
    u32 v3 = ((p1) + (0x0u));
    u32 v4 = ((p2) + (0x0u));
    u32 v5 = ((p3) + (0x0u));
    Unk021a7064Func v6 = (Unk021a7064Func) func_ov000_021a7af0;
    u32 v7 = ((v2) + (0x0u));
    u32 v9 = ((u32) func_ov000_021a7064(v6, (Unk021a6fa8 *) v7, (s32) 0x1u));
    u32 v10 = ((v9) + (0x0u));
    u32 v14;
    u32 v16;
    u32 v17;
    *(u32 *) ((v10) + (16)) = v3;
    *(u32 *) ((v10) + (20)) = v4;
    *(u32 *) ((v10) + (24)) = v5;
    v14 = p4;
    *(u32 *) ((v10) + (28)) = v14;
    v16 = ((v2) + (0x0u));
    v17 = func_ov000_021a6fb4((Unk021a6fa8 *) v16, (Unk021a7064 *) v10);
    return v17;
}
