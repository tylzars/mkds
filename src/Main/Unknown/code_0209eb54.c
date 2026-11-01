#include "Main/Unknown/code_0209eb54.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_02167000.h"

void func_0209eb54(void *a, Unk0209ec80 *b) {
    s32 s;
    s32 x;
    s32 y;
    s32 z;
    Vec3 v;

    s = 0x1e;
    func_01ff9048(0x14, &s, 1);
    z = b->mUnk_00.mUnk_04.z >> 4;
    y = (b->mUnk_00.mUnk_04.y + 0x1ccd) >> 4;
    x = b->mUnk_00.mUnk_04.x >> 4;
    v.x = x;
    v.y = y;
    v.z = z;
    func_01ff9048(0x1c, &v, 3);
    func_01ff9048(0x1b, &b->mUnk_00.mUnk_1c, 3);
    func_01ff9048(0x1a, &b->mUnk_00.mUnk_28, 9);
    func_0209bb2c(a, data_usa_0217b174, b);
}

void func_0209ec00(void *a) {
    func_0209bbd0(a, data_usa_0217b174);
}

void func_0209ec18(void *a) {
    data_usa_0217b174 = func_0209bd08(a, data_usa_0216745c);
}

u32 func_0209ec44(void) {
    return func_0209bf48(0, (u32) func_0209ec80, 0);
}

u32 func_0209ec60(void) {
    return func_0209bf1c((u32) func_0209f0a8, (u32) func_0209efb4, 0);
}

void func_0209ec80(void *a, Unk0209ec80 *b) {
    Unk0210b7a8 s1;
    Unk0210b7a8 s2;
    Unk0210b7a8 s3;
    Unk0210b7a8 s4;
    Unk020f41c4_B *r;
    s32 n;
    s32 t;

    switch (b->mUnk_ac) {
        case 1:
            if (b->mUnk_a8-- <= 0) {
                b->mUnk_ac = 2;
            }
            break;
        case 2:
            if (b->mUnk_a4 == 0) {
                n = b->mUnk_a0 + 1;
                if (n >= func_0209b758(data_usa_0217b178)) {
                    n = 0;
                }
                b->mUnk_a0 = n;
                if (b->mUnk_a0 == 0 || b->mUnk_a0 == 0xf || b->mUnk_a0 == 0x1f || b->mUnk_a0 == 0x37 ||
                    b->mUnk_a0 == 0x51) {
                    if (func_020d4ddc(&b->mUnk_00) == 0) {
                        if (b->mUnk_00.mUnk_70 == data_0217ca6c[2].mUnk_20) {
                            t = 2;
                        } else if (b->mUnk_00.mUnk_70 == data_0217ca6c[3].mUnk_20) {
                            t = 3;
                        } else {
                            t = 4;
                        }
                        s1.mUnk_00 = 0x116;
                        s1.mUnk_04 = &b->mUnk_00.mUnk_04;
                        s1.mUnk_08 = t;
                        s1.mUnk_0c = func_020d4ef4(&b->mUnk_00.mUnk_04);
                        func_0210b7a8(&s1);
                    }
                } else if (b->mUnk_a0 == 8 || b->mUnk_a0 == 0x14 || b->mUnk_a0 == 0x2c || b->mUnk_a0 == 0x44) {
                    if (func_020d4ddc(&b->mUnk_00) == 0) {
                        if (b->mUnk_00.mUnk_70 == data_0217ca6c[2].mUnk_20) {
                            t = 2;
                        } else if (b->mUnk_00.mUnk_70 == data_0217ca6c[3].mUnk_20) {
                            t = 3;
                        } else {
                            t = 4;
                        }
                        s2.mUnk_00 = 0x117;
                        s2.mUnk_04 = &b->mUnk_00.mUnk_04;
                        s2.mUnk_08 = t;
                        s2.mUnk_0c = func_020d4ef4(&b->mUnk_00.mUnk_04);
                        func_0210b7a8(&s2);
                    }
                } else if (b->mUnk_a0 == 0x78) {
                    if (func_020d4ddc(&b->mUnk_00) == 0) {
                        if (b->mUnk_00.mUnk_70 == data_0217ca6c[2].mUnk_20) {
                            t = 2;
                        } else if (b->mUnk_00.mUnk_70 == data_0217ca6c[3].mUnk_20) {
                            t = 3;
                        } else {
                            t = 4;
                        }
                        s3.mUnk_00 = 0x115;
                        s3.mUnk_04 = &b->mUnk_00.mUnk_04;
                        s3.mUnk_08 = t;
                        s3.mUnk_0c = func_020d4ef4(&b->mUnk_00.mUnk_04);
                        func_0210b7a8(&s3);
                    }
                }
            } else if (b->mUnk_a4 == 1) {
                n = b->mUnk_a0 + 1;
                if (n >= func_0209b758(data_usa_0217b17c)) {
                    n = 0;
                }
                b->mUnk_a0 = n;
                if (b->mUnk_a0 == 0) {
                    if (func_020d4ddc(&b->mUnk_00) == 0) {
                        if (b->mUnk_00.mUnk_70 == data_0217ca6c[2].mUnk_20) {
                            t = 2;
                        } else if (b->mUnk_00.mUnk_70 == data_0217ca6c[3].mUnk_20) {
                            t = 3;
                        } else {
                            t = 4;
                        }
                        s4.mUnk_00 = 0x118;
                        s4.mUnk_04 = &b->mUnk_00.mUnk_04;
                        s4.mUnk_08 = t;
                        s4.mUnk_0c = func_020d4ef4(&b->mUnk_00.mUnk_04);
                        func_0210b7a8(&s4);
                    }
                }
            }
            if (b->mUnk_a0 != 0) {
                return;
            }
            r = &data_0217561c->mUnk_498;
            r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
            b->mUnk_a8 = (u16) (((r->mUnk_00 >> 32) * 0x78) >> 32) + 0x3c;
            b->mUnk_ac = 1;
            break;
    }
}

void func_0209efb4(void *a, Unk0209ec80 *b) {
    s32 s;

    s = 0x1e;
    func_01ff9048(0x14, &s, 1);
    b->mUnk_00.mUnk_28.mUnk_24.x = b->mUnk_00.mUnk_04.x >> 4;
    b->mUnk_00.mUnk_28.mUnk_24.y = b->mUnk_00.mUnk_04.y >> 4;
    b->mUnk_00.mUnk_28.mUnk_24.z = b->mUnk_00.mUnk_04.z >> 4;
    func_01ff9048(0x19, &b->mUnk_00.mUnk_28, 0xc);
    func_01ff9048(0x1b, &b->mUnk_00.mUnk_1c, 3);
    switch (b->mUnk_a4) {
        case 0:
            func_0209b77c(data_usa_0217b178, b->mUnk_a0);
            func_0209bb2c(a, data_usa_0217b178, b);
            break;
        case 1:
            func_0209b77c(data_usa_0217b17c, b->mUnk_a0);
            func_0209bb2c(a, data_usa_0217b17c, b);
            break;
    }
}

void func_0209f0a8(void *a) {
    data_usa_0217b178 = func_0209be84(a, data_usa_021674d4);
    func_0209be50(data_usa_0217b178, data_usa_021674e4);
    data_usa_0217b17c = func_0209be84(a, data_usa_021674f4);
    func_0209be50(data_usa_0217b17c, data_usa_02167504);
    func_0209b940(data_usa_0217b178, 0x3f);
    func_0209b940(data_usa_0217b17c, 0x3f);
}
