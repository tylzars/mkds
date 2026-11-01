#include "code_020182c0.h"
#include "Main/Unknown/code_02004d80.h"
#include "Main/Unknown/code_02004238.h"
#include "code_02003be0.h"
#include "code_02004270.h"
#include "code_02139f70.h"

u32 func_020184a0(Unk02018344 *a) {
    if (a->mUnk_00 != 0x4352414e) {
        return 0;
    }
    if (a->mUnk_04 != 0xfffe) {
        return 0;
    }
    return a->mUnk_06 == 0x100 ? 1 : 0;
}

u32 func_02018344(Unk020182c0 *a, const u8 *b, Unk02018344 *c) {
    u8 *p6;
    u8 *p5;
    u8 *p4;
    s32 i;
    u8 *p;
    s32 n;

    p6 = 0;
    p5 = 0;
    p4 = 0;
    if (func_020184a0(c) == 0) {
        return 0;
    }
    p = (u8 *) c + c->mUnk_0c;
    n = c->mUnk_0e;
    for (i = 0; i < n; i++) {
        switch (*(u32 *) p) {
            case 0x46415442:
                p6 = p;
                break;
            case 0x464e5442:
                p5 = p;
                break;
            case 0x46494d47:
                p4 = p;
                break;
        }
        p += *(u32 *) (p + 4);
    }
    func_02004238(&a->mUnk_00);
    a->mUnk_5c = c;
    a->mUnk_60 = p6;
    p4 = (u8 *) p4 + 8;
    a->mUnk_64 = p4;
    if (func_02004128(&a->mUnk_00, b, func_0213a434(b)) == 0) {
        return 0;
    }
    if (func_02004018(&a->mUnk_00, p4, p6 + 0xc - p4, *(u32 *) (p6 + 4) - 0xc, p5 + 8 - p4, *(u32 *) (p5 + 4) - 8, 0,
                      0) != 0) {
        return 1;
    }
    func_02004090(&a->mUnk_00);
    return 0;
}

u32 func_02018314(Unk02003a6c *a) {
    if (func_02003f50(a) == 0) {
        return 0;
    }
    func_02004090(a);
    return 1;
}

u32 func_020182c0(const u8 *a) {
    Unk02003024 s;
    u32 r;

    r = 0;
    func_02004d80(&s);
    if (func_02004a30(&s, a) != 0) {
        r = (u32) (((Unk020182c0 *) s.mUnk_08)->mUnk_64 + s.mUnk_20.w.mUnk_04);
        func_020049e8(&s);
    }
    return r;
}
