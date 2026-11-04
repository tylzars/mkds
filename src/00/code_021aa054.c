#include "00/code_021aa054.h"
#include "00/code_021aa398.h"
#include "00/code_021ab6d4.h"
#include "00/code_021ab728.h"
#include "00/code_021ab7b4.h"
#include "00/code_021abc24.h"
#include "00/code_021abca0.h"
#include "00/code_021abd2c.h"
#include "00/code_021ac3e4.h"
#include "00/types_021a998c.h"
#include "code_0214d018.h"

s32 func_ov000_021aa054(void *g, u8 *h) {
    Unk021a998c_0c *a = g;
    u8 *b = h;
    s32 c = (b[3] << 8) + b[4];
    u8 *d = b + 5 + c;
    u8 e[0x30];
    u8 *f;
    switch (a->mUnk_006) {
        case 4:
            f = a->mUnk_3d0;
            func_ov000_021ab7b4((u32 *) f);
            func_ov000_021ab728(f, a->mUnk_090, 0x10);
            MemFill(e, 0x36, 0x30);
            func_ov000_021ab728(f, e, 0x30);
            func_ov000_021ab728(f, a->mUnk_1a0, 8);
            func_ov000_021ab728(f, b, 1);
            func_ov000_021ab728(f, b + 3, 2);
            func_ov000_021ab728(f, b + 5, c);
            func_ov000_021ab6d4((s32) f, (u32) d);
            func_ov000_021ab7b4((u32 *) f);
            func_ov000_021ab728(f, a->mUnk_090, 0x10);
            MemFill(e, 0x5c, 0x30);
            func_ov000_021ab728(f, e, 0x30);
            func_ov000_021ab728(f, d, 0x10);
            func_ov000_021ab6d4((s32) f, (u32) d);
            c += 0x10;
            break;
        case 5:
            f = a->mUnk_31c;
            func_ov000_021abd2c((u32 *) f);
            func_ov000_021abca0(f, a->mUnk_090, 0x14);
            MemFill(e, 0x36, 0x28);
            func_ov000_021abca0(f, e, 0x28);
            func_ov000_021abca0(f, a->mUnk_1a0, 8);
            func_ov000_021abca0(f, b, 1);
            func_ov000_021abca0(f, b + 3, 2);
            func_ov000_021abca0(f, b + 5, c);
            func_ov000_021abc4c((s32) f, (u32) d);
            func_ov000_021abd2c((u32 *) f);
            func_ov000_021abca0(f, a->mUnk_090, 0x14);
            MemFill(e, 0x5c, 0x28);
            func_ov000_021abca0(f, e, 0x28);
            func_ov000_021abca0(f, d, 0x14);
            func_ov000_021abc4c((s32) f, (u32) d);
            c += 0x14;
            break;
    }
    b[3] = c >> 8;
    b[4] = c;
    func_ov000_021ac3e4((u8 *) a->mUnk_09c, (u8 *) (b + 5), c);
    func_ov000_021aa398(a->mUnk_1a0, 8);
    return c + 5;
}
