#include "code_0212d5e0.h"

#include "code_02004270.h"
#include "code_0212da38.h"
#include "code_02004d80.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0212d968.h"
#include "code_02020eb0.h"
#include "code_0201750c.h"
#include "Main/Unknown/code_02017000.h"
#include "code_020172d0.h"
#include "Main/Unknown/code_02018000.h"
#include "Main/Unknown/code_02021000.h"
#include "code_0212da1c.h"
#include "code_02017f24.h"

u32 func_0212d9dc(Unk0212d9dc *a, void *p) {
    func_02017538(&a->mUnk_04, 12);
    a->mUnk_00 = p;
    return func_0212d98c(a) != 0;
}

u32 func_0212d98c(Unk0212d9dc *a) {
    void *p;

    p = func_0201808c(a->mUnk_00, 0x14, 4);
    if (p == 0) {
        return 0;
    }
    func_0212da1c(p);
    func_020174a4(&a->mUnk_04, p);
    return 1;
}

void func_0212d968(void) {
    u32 v;

    v = func_02021114();
    func_020211e4(1);
    func_02021154(v);
}

void func_0212d8e0(Unk0212d5f8 *a, const u8 *path, void *p, u32 flag) {
    a->mUnk_8c = 0;
    a->mUnk_84 = 0;
    a->mUnk_88 = 0;
    if (func_02004b54(&a->mUnk_7c, path) == 0) {
        return;
    }
    func_02004d80(&a->mUnk_34);
    if (func_02004a80(&a->mUnk_34, a->mUnk_7c) == 0) {
        return;
    }
    a->mUnk_30 = 1;
    if (func_0212d6c4(a, p, flag) != 0) {
        data_0217dec4 = a;
    }
}

u32 func_0212d6c4(Unk0212d5f8 *a, void *p, u32 flag) {
    s32 n;

    if (func_02004840(&a->mUnk_34, 0, 0) == 0) {
        return 0;
    }
    if (func_020048ac(&a->mUnk_34, a, 0x30) != 0x30) {
        return 0;
    }
    if (p != 0) {
        a->mUnk_8c = func_0212db7c(p, a->mUnk_1c, func_0212d22c, a, 0);
        if (a->mUnk_8c == 0) {
            return 0;
        }
        if (func_02004840(&a->mUnk_34, a->mUnk_18, 0) == 0) {
            return 0;
        }
        n = func_020048ac(&a->mUnk_34, a->mUnk_8c, a->mUnk_1c);
        if (n != a->mUnk_1c) {
            return 0;
        }
        a->mUnk_84 = func_0212db7c(p, a->mUnk_24, func_0212d220, a, 0);
        if (a->mUnk_84 == 0) {
            return 0;
        }
        if (func_02004840(&a->mUnk_34, a->mUnk_20, 0) == 0) {
            return 0;
        }
        n = func_020048ac(&a->mUnk_34, a->mUnk_84, a->mUnk_24);
        if (n != a->mUnk_24) {
            return 0;
        }
        if (flag != 0 && a->mUnk_14 != 0) {
            a->mUnk_88 = func_0212db7c(p, a->mUnk_14, func_0212d214, a, 0);
            if (a->mUnk_88 == 0) {
                return 0;
            }
            if (func_02004840(&a->mUnk_34, a->mUnk_10, 0) == 0) {
                return 0;
            }
            n = func_020048ac(&a->mUnk_34, a->mUnk_88, a->mUnk_14);
            if (n != a->mUnk_14) {
                return 0;
            }
        }
    }
    return 1;
}

void func_0212d5f8(Unk0212d5f8 *a, void *buf) {
    u32 i;

    func_0214d02c(buf, a, 0x30);
    a->mUnk_8c = a->mUnk_18 == 0 ? 0 : (Unk0212d38c *) ((u8 *) buf + a->mUnk_18);
    a->mUnk_84 = a->mUnk_20 == 0 ? 0 : (Unk0212d254 *) ((u8 *) buf + a->mUnk_20);
    a->mUnk_88 = a->mUnk_10 == 0 ? 0 : (u8 *) buf + a->mUnk_10;
    for (i = 0; i < a->mUnk_84->mUnk_08; i++) {
        Unk0212d27c *e = &a->mUnk_84->mUnk_0c[i];

        e->mUnk_08 = e->mUnk_00 == 0 ? 0 : (Unk0212f788 *) ((u8 *) buf + e->mUnk_00);
    }
    a->mUnk_30 = 0;
    data_0217dec4 = a;
}

Unk0212d5f8 *func_0212d5e0(Unk0212d5f8 *a) {
    Unk0212d5f8 *old = data_0217dec4;

    data_0217dec4 = a;
    return old;
}
