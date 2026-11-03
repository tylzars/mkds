#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_020a7eb4.h"
#include "Main/Unknown/code_020a8098.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_0217b000.h"

u8 func_020a7fc4(Unk020a7f18 *p, Unk0206bcb0 *a, u8 *b, u8 *c) {
    Unk0210b7a8 s;
    u32 d;

    d = *c;
    if (*b == 1) {
        func_020a8098(p);
        p->mUnk_000.mFlags = p->mUnk_000.mFlags | data_021567e4;
        p->mUnk_000.mFlags = p->mUnk_000.mFlags | data_021567e8;
        func_020d26f8(&p->mUnk_000, a);
    } else {
        if (p->mUnk_0a4 == 0) {
            s.mUnk_00 = 0x193;
            s.mUnk_04 = &p->mUnk_000.mPos;
            s.mUnk_08 = 2;
            s.mUnk_0c = func_020d4ef4(&p->mUnk_000.mPos);
            func_0210b7a8(&s);
            p->mUnk_0ac = 0x14;
        }
        p->mUnk_0a4 = 0x3c;
    }
    return d;
}

u8 func_020a7f18(Unk020a7f18 *p, Unk0206bcb0 *a, u8 *b, u8 *c) {
    Unk0210b7a8 s;
    u32 d;

    d = *c;
    if (*b == 1) {
        func_020a8098(p);
        p->mUnk_000.mFlags = p->mUnk_000.mFlags | data_021567e4;
        p->mUnk_000.mFlags = p->mUnk_000.mFlags | data_021567e8;
    } else {
        if (p->mUnk_0a4 == 0) {
            s.mUnk_00 = 0x193;
            s.mUnk_04 = &p->mUnk_000.mPos;
            s.mUnk_08 = 2;
            s.mUnk_0c = func_020d4ef4(&p->mUnk_000.mPos);
            func_0210b7a8(&s);
            p->mUnk_0ac = 0x14;
        }
        p->mUnk_0a4 = 0x3c;
    }
    return d;
}

void CreateSanboHAndSanboB(void *a) {
    gSanboH = func_0209bd08(a, gSanboHNsbmdName);
    gSanboB = func_0209bd08(a, gSanboBNsbmdName);
    func_0209b940(gSanboH, 0x3f);
    func_0209b940(gSanboB, 0x3f);
}
