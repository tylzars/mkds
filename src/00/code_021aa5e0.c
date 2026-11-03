#include "00/code_021aa5e0.h"
#include "00/code_021ab000.h"
#include "00/code_021ab6d4.h"
#include "00/code_021ab728.h"
#include "00/code_021ab7b4.h"
#include "00/code_021abc24.h"
#include "00/code_021abca0.h"
#include "00/code_021abd2c.h"
#include "00/code_021ac3e4.h"
#include "00/types_021a998c.h"
#include "00/types_021ab5e4.h"

void func_ov000_021aa5e0(Unk021a998c_0c *a) {
    s32 x;
    s32 y;
    s32 z;
    s32 n;
    s32 o;
    s32 i;
    s32 j;
    u8 c[0x15];
    u32 *h;
    switch (a->mUnk_006) {
        case 4:
            x = 0x10;
            y = 0x10;
            z = 0;
            break;
        case 5:
            x = 0x14;
            y = 0x10;
            z = 0;
            break;
    }
    n = (x + y + z) * 2;
    i = 0;
    if (n > 0) {
        o = 0;
        do {
            h = (u32 *) a->mUnk_31c;
            func_ov000_021abd2c(h);
            c[0] = i + 0x41;
            for (j = 0; j < i + 1; j++) {
                func_ov000_021abca0(h, c, 1);
            }
            func_ov000_021abca0(h, a->mUnk_000->mUnk_20, 0x30);
            func_ov000_021abca0(h, a->mUnk_028, 0x20);
            func_ov000_021abca0(h, a->mUnk_008, 0x20);
            func_ov000_021abc4c((s32) h, (u32) (c + 1));
            h = (u32 *) a->mUnk_3d0;
            func_ov000_021ab7b4(h);
            func_ov000_021ab728(h, a->mUnk_000->mUnk_20, 0x30);
            func_ov000_021ab728(h, c + 1, 0x14);
            func_ov000_021ab6d4((s32) h, (u32) (a->mUnk_048 + o));
            o += 0x10;
            i++;
        } while (o < n);
    }
    if (a->mUnk_428 != 0) {
        a->mUnk_1a8 = a->mUnk_048;
        a->mUnk_1ac = a->mUnk_1a8 + x * 2;
        a->mUnk_1b0 = a->mUnk_1ac + y * 2;
        a->mUnk_090 = a->mUnk_048 + x;
        a->mUnk_094 = a->mUnk_090 + x + y;
        a->mUnk_098 = a->mUnk_094 + y + z;
    } else {
        a->mUnk_090 = a->mUnk_048;
        a->mUnk_094 = a->mUnk_090 + x * 2;
        a->mUnk_098 = a->mUnk_094 + y * 2;
        a->mUnk_1a8 = a->mUnk_048 + x;
        a->mUnk_1ac = a->mUnk_1a8 + x + y;
        a->mUnk_1b0 = a->mUnk_1ac + y + z;
    }
    func_ov000_021ac434(a->mUnk_1b4, a->mUnk_1ac, 0x10);
    func_ov000_021ac434(a->mUnk_09c, a->mUnk_094, 0x10);
}
