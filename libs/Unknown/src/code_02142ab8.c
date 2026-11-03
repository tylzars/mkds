#include "code_0200eddc.h"
#include "code_02142ab8.h"
#include "code_02142eac.h"
#include "code_0200e77c.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0214c778.h"
#include "code_0214d5b8.h"
#include "Main/Unknown/unk_0217e000.h"

s32 func_02142ab8(u32 a, u16 b, ...) {
    void *p;
    u32 *ap;
    s32 i;
    s32 r;

    if (func_0200ea3c(&data_0217eed8, &p, 0) == 0) {
        return 8;
    }
    func_0200ee3c(p, 2);
    if ((*(u16 *) p & 0x8000) == 0) {
        func_0200e988(&data_0217eed8, p, 1);
        return 8;
    }
    if (b == 0) {
        func_0200ee58(data_0217eed4->mUnk_00c, 0x100);
        func_0200ee3c(p, 0x100);
        func_0214cb88(data_0217eed4->mUnk_014, data_0217eed4->mUnk_00c, p, 0x100);
    }
    *(u16 *) p = a;
    ap = (u32 *) (((u32) &b & ~3) + 4);
    for (i = 0; i < b; i++) {
        ap++;
        ((u32 *) ((u8 *) p + 4))[i] = ap[-1];
    }
    func_0200ee58(p, 0x100);
    r = func_0214d6e8(0xa, (u32) p, 0);
    func_0200eae8(&data_0217eed8, p, 1);
    if (r < 0) {
        return 8;
    }
    return 2;
}
