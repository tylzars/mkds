#include "code_02003024.h"
#include "code_02004d80.h"
#include "code_0200dc3c.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0214d000.h"

s32 FileCloseReturnOk(Unk02003024 *a) {
    return 0;
}

void FileFinishCommand(Unk02003024 *a, s32 b) {
    u32 s;
    Unk02003024 *p;
    Unk02003024 *q;

    s = func_0200fca0();
    p = a->mUnk_00;
    q = a->mUnk_04;
    if (p != 0) {
        p->mUnk_04 = q;
    }
    if (q != 0) {
        q->mUnk_00 = p;
    }
    a->mUnk_00 = 0;
    a->mUnk_04 = a->mUnk_00;
    a->mUnk_0c &= ~0x4f;
    a->mUnk_14 = b;
    func_0200df9c(&a->mUnk_18);
    func_0200fcb4(s);
}

s32 FileDispatchCommand(Unk02003024 *a, u32 b) {
    s32 r;
    Unk02003a6c *p;
    u32 m;
    u32 s;

    p = a->mUnk_08;
    m = 1 << b;
    if (((a->mUnk_0c & 4) ? 1 : 0) != 0) {
        p->mUnk_1c |= 0x200;
    } else {
        p->mUnk_1c |= 0x100;
    }
    if (p->mUnk_58 & m) {
        r = p->mUnk_54(a, b);
        switch (r) {
            case 0:
            case 1:
            case 4:
                a->mUnk_14 = r;
                break;
            case 8:
                p->mUnk_58 = p->mUnk_58 & ~m;
                r = 7;
                break;
        }
    } else {
        r = 7;
    }
    if (r == 7) {
        r = data_02152b5c[b](a);
    }
    if (r == 6) {
        if (((a->mUnk_0c & 4) ? 1 : 0) != 0) {
            s = func_0200fca0();
            if (p->mUnk_1c & 0x200) {
                do {
                    func_0200e01c(&p->mUnk_0c);
                } while (p->mUnk_1c & 0x200);
            }
            r = a->mUnk_14;
            func_0200fcb4(s);
        }
    } else if (((a->mUnk_0c & 4) ? 1 : 0) != 0) {
        p->mUnk_1c &= ~0x200;
        a->mUnk_14 = r;
    } else {
        p->mUnk_1c &= ~0x100;
        FileFinishCommand(a, r);
    }
    return r;
}
