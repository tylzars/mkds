#include "00/code_021aa468.h"
#include "00/code_021ab000.h"
#include "00/code_021ab6d4.h"
#include "00/code_021ab728.h"
#include "00/code_021ab7b4.h"
#include "00/code_021abc24.h"
#include "00/code_021abca0.h"
#include "00/code_021abd2c.h"
#include "00/types_021a998c.h"
#include "00/types_021ab5e4.h"
#include "00/unk_021b4000.h"
#include "code_0214d018.h"

void func_ov000_021aa50c(Unk021a998c_0c *a, u8 *b, u32 c) {
    u8 d[0x30];
    u32 *e;
    e = (u32 *) a->mUnk_378;
    if ((a->mUnk_428 ^ c) != 0) {
        func_ov000_021ab728(e, data_ov000_021b4a48, 4);
    } else {
        func_ov000_021ab728(e, data_ov000_021b4a50, 4);
    }
    func_ov000_021ab728(e, a->mUnk_000->mUnk_20, 0x30);
    func_0214d168(d, 0x36, 0x30);
    func_ov000_021ab728(e, d, 0x30);
    func_ov000_021ab6d4((s32) e, (u32) b);
    func_ov000_021ab7b4(e);
    func_ov000_021ab728(e, a->mUnk_000->mUnk_20, 0x30);
    func_0214d168(d, 0x5c, 0x30);
    func_ov000_021ab728(e, d, 0x30);
    func_ov000_021ab728(e, b, 0x10);
    func_ov000_021ab6d4((s32) e, (u32) b);
}

void func_ov000_021aa468(Unk021a998c_0c *a, u8 *b, u32 c) {
    u8 d[0x28];
    u32 *e;
    e = (u32 *) a->mUnk_2c0;
    if ((a->mUnk_428 ^ c) != 0) {
        func_ov000_021abca0(e, data_ov000_021b4a48, 4);
    } else {
        func_ov000_021abca0(e, data_ov000_021b4a50, 4);
    }
    func_ov000_021abca0(e, a->mUnk_000->mUnk_20, 0x30);
    func_0214d168(d, 0x36, 0x28);
    func_ov000_021abca0(e, d, 0x28);
    func_ov000_021abc4c((s32) e, (u32) b);
    func_ov000_021abd2c(e);
    func_ov000_021abca0(e, a->mUnk_000->mUnk_20, 0x30);
    func_0214d168(d, 0x5c, 0x28);
    func_ov000_021abca0(e, d, 0x28);
    func_ov000_021abca0(e, b, 0x14);
    func_ov000_021abc4c((s32) e, (u32) b);
}
