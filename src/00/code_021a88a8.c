#include "00/code_021a88a8.h"
#include "00/code_02186d7c.h"
#include "00/code_021ae2f4.h"
#include "00/code_021ae304.h"
#include "00/code_021b0014.h"
#include "00/unk_021b5000.h"
#include "00/code_021a8878.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"

s32 func_ov000_021a88e4(const u8 *a) {
    Unk021a88e4 b;
    u8 *c;
    s32 d;
    if (a == 0) {
        return 0;
    }
    c = data_ov000_021b5f94->mUnk_18(0x1154);
    if (c == 0) {
        return 0;
    }
    func_0214d168(&b, 0, 0x64);
    b.mUnk_3c.mUnk_04 = c;
    b.mUnk_3c.mUnk_00 = 0xb68;
    b.mUnk_48.mUnk_04 = c + 0xb68;
    b.mUnk_48.mUnk_00 = 0x5ea;
    func_ov000_021ae304(&b);
    d = func_ov000_021acef8((const char *) a);
    func_ov000_021ae2f4();
    data_ov000_021b5f94->mUnk_1c(c);
    return d;
}

s32 func_ov000_021a88a8(u32 a) {
    u32 b = func_0200fca0();
    u32 c = data_ov000_021b63d8[0];
    u32 d = data_ov000_021b63d8[1];
    s32 e;
    data_ov000_021b63d8[0] = 0;
    data_ov000_021b63d8[1] = 0;
    e = func_ov000_021acef8((const char *) a);
    data_ov000_021b63d8[0] = c;
    data_ov000_021b63d8[1] = d;
    func_0200fcb4(b);
    return e;
}
