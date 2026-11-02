#include "00/code_021aa1e0.h"
#include "00/code_021aa380.h"
#include "00/code_021aa398.h"
#include "00/code_021ab000.h"
#include "00/code_021ab6d4.h"
#include "00/code_021ab7b4.h"
#include "00/code_021abc24.h"
#include "00/code_021abd2c.h"
#include "code_02134d30.h"
#include "code_0214d018.h"

s32 func_ov000_021aa1e0(Unk021a998c_0c *a, u8 *b) {
    u8 c[0x14];
    u8 d[0x30];
    s32 e;
    u32 f;
    u32 *g;
    e = func_ov000_021aa380((u32) a, (u32) (b + 5), (b[3] << 8) + b[4]);
    switch (a->mUnk_006) {
        case 4:
            e -= 0x10;
            b[3] = e >> 8;
            b[4] = e;
            g = (u32 *) a->mUnk_3d0;
            func_ov000_021ab7b4(g);
            func_ov000_021ab728(g, a->mUnk_1a8, 0x10);
            func_0214d168(d, 0x36, 0x30);
            func_ov000_021ab728(g, d, 0x30);
            func_ov000_021ab728(g, a->mUnk_2b8, 8);
            func_ov000_021ab728(g, b, 1);
            func_ov000_021ab728(g, b + 3, 2);
            func_ov000_021ab728(g, b + 5, e);
            func_ov000_021ab6d4((s32) g, (u32) c);
            func_ov000_021ab7b4(g);
            func_ov000_021ab728(g, a->mUnk_1a8, 0x10);
            func_0214d168(d, 0x5c, 0x30);
            func_ov000_021ab728(g, d, 0x30);
            func_ov000_021ab728(g, c, 0x10);
            func_ov000_021ab6d4((s32) g, (u32) c);
            f = 0x10;
            break;
        case 5:
            e -= 0x14;
            b[3] = e >> 8;
            b[4] = e;
            g = (u32 *) a->mUnk_31c;
            func_ov000_021abd2c(g);
            func_ov000_021abca0(g, a->mUnk_1a8, 0x14);
            func_0214d168(d, 0x36, 0x28);
            func_ov000_021abca0(g, d, 0x28);
            func_ov000_021abca0(g, a->mUnk_2b8, 8);
            func_ov000_021abca0(g, b, 1);
            func_ov000_021abca0(g, b + 3, 2);
            func_ov000_021abca0(g, b + 5, e);
            func_ov000_021abc4c((s32) g, (u32) c);
            func_ov000_021abd2c(g);
            func_ov000_021abca0(g, a->mUnk_1a8, 0x14);
            func_0214d168(d, 0x5c, 0x28);
            func_ov000_021abca0(g, d, 0x28);
            func_ov000_021abca0(g, c, 0x14);
            func_ov000_021abc4c((s32) g, (u32) c);
            f = 0x14;
            break;
    }
    if (memcmp(b + 5 + e, c, f) != 0) {
        a->mUnk_429 = 9;
    }
    func_ov000_021aa398(a->mUnk_2b8, 8);
    return e + 5;
}
