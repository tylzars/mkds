#include "Main/Unknown/code_02060c68.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/unk_0217a000.h"

s32 func_02060c68(Unk0217aa00_45c *p0, u32 p1) {
    u32 v2 = ((u32) * (u8 *) (((u32) p0) + (532)));
    u32 v3 = ((u32) (&data_0217aa08));
    u32 v4 = 0x874u;
    u32 v7 = ((u32) * (u32 *) ((v3) + (0)));
    u32 v9 = ((u32) * (u32 *) ((v7) + (32)));
    u32 v10 = (u32) &p0->mUnk_218;
    u32 v11 = ((v9) + (v4));
    u32 v13 = func_02060d1c((u8 *) v11, p0, (u8 *) v10, (u32) 0x0u, v2, p1);
    return v13;
}
