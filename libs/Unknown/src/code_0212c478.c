#include "code_0212c478.h"
#include "code_020207ec.h"
#include "code_0202041c.h"
#include "code_0212bcac.h"
#include "code_0212f788.h"
#include "Main/Unknown/unk_02152000.h"

void func_0212c620(Unk0212c400 **a, s32 b, s32 c) {
    Unk0212c400 *p = *a;

    if (p == 0) {
        return;
    }
    if (p->mUnk_2c == 2) {
        return;
    }
    func_0212f834(&p->mUnk_1c, b << 8, c);
}

void func_0212c5f4(Unk0212c400 **a, u32 b) {
    if (*a == 0) {
        return;
    }
    func_0212bcac(*a, b);
}

void func_0212c5c4(Unk0212c400 **a, u32 b) {
    Unk0212c400 *p = *a;

    if (p == 0) {
        return;
    }
    func_02020d68(p->mUnk_3c, b);
}

void func_0212c594(Unk0212c400 **a, u32 b, u32 c) {
    Unk0212c400 *p = *a;

    if (p == 0) {
        return;
    }
    func_02020af8(p->mUnk_3c, b, c);
}

void func_0212c554(Unk0212c400 **a, u32 b, u32 c) {
    Unk0212c400 *p = *a;

    if (p == 0) {
        return;
    }
    func_02020d0c(p->mUnk_3c, b, data_02152ce4[c]);
}

void func_0212c524(Unk0212c400 **a, u32 b, u32 c) {
    Unk0212c400 *p = *a;

    if (p == 0) {
        return;
    }
    func_02020ce4(p->mUnk_3c, b, c);
}

u32 func_0212c4f4(Unk0212c400 **a, u32 b, u32 c) {
    Unk0212c400 *p = *a;

    if (p == 0) {
        return (u32) p;
    }
    func_02020cbc(p->mUnk_3c, b, c);
}

void func_0212c4c4(Unk0212c400 **a, u32 b, u32 c) {
    Unk0212c400 *p = *a;

    if (p == 0) {
        return;
    }
    func_02020c94(p->mUnk_3c, b, c);
}

void func_0212c494(Unk0212c400 **a, u32 b) {
    Unk0212c400 *p = *a;

    if (p == 0) {
        return;
    }
    func_02020d98(p->mUnk_3c, b);
}

void func_0212c478(Unk0212c400 **a, u32 b) {
    Unk0212c400 *p = *a;

    if (p != 0) {
        p->mUnk_34 = 1;
        (*a)->mUnk_38 = b;
    }
}
