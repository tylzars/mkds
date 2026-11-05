#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209eb54.h"
#include "ITCM/code_01ff8000.h"
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

void CreatePicture1AndPicture2(void *a) {
    gPicture1 = func_0209be84(a, gPicture1NsbmdName);
    func_0209be50(gPicture1, gPicture1NsbcaName);
    gPicture2 = func_0209be84(a, gPicture2NsbmdName);
    func_0209be50(gPicture2, gPicture2NsbcaName);
    func_0209b940(gPicture1, 0x3f);
    func_0209b940(gPicture2, 0x3f);
}

void DrawPicture(void *a, Unk0209ec80 *b) {
    s32 s;

    s = 0x1e;
    func_01ff9048(0x14, &s, 1);
    b->mUnk_00.mMatrix.mUnk_00[3].x = b->mUnk_00.mPos.x >> 4;
    b->mUnk_00.mMatrix.mUnk_00[3].y = b->mUnk_00.mPos.y >> 4;
    b->mUnk_00.mMatrix.mUnk_00[3].z = b->mUnk_00.mPos.z >> 4;
    func_01ff9048(0x19, &b->mUnk_00.mMatrix, 0xc);
    func_01ff9048(0x1b, &b->mUnk_00.mScale, 3);
    switch (b->mUnk_a4) {
        case 0:
            func_0209b77c(gPicture1, b->mUnk_a0);
            func_0209bb2c(a, gPicture1, b);
            break;
        case 1:
            func_0209b77c(gPicture2, b->mUnk_a0);
            func_0209bb2c(a, gPicture2, b);
            break;
    }
}

void UpdatePicture(void *a, Unk0209ec80 *b) {
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
                if (n >= func_0209b758(gPicture1)) {
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
                        s1.mUnk_04 = &b->mUnk_00.mPos;
                        s1.mUnk_08 = t;
                        s1.mUnk_0c = func_020d4ef4(&b->mUnk_00.mPos);
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
                        s2.mUnk_04 = &b->mUnk_00.mPos;
                        s2.mUnk_08 = t;
                        s2.mUnk_0c = func_020d4ef4(&b->mUnk_00.mPos);
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
                        s3.mUnk_04 = &b->mUnk_00.mPos;
                        s3.mUnk_08 = t;
                        s3.mUnk_0c = func_020d4ef4(&b->mUnk_00.mPos);
                        func_0210b7a8(&s3);
                    }
                }
            } else if (b->mUnk_a4 == 1) {
                n = b->mUnk_a0 + 1;
                if (n >= func_0209b758(gPicture2)) {
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
                        s4.mUnk_04 = &b->mUnk_00.mPos;
                        s4.mUnk_08 = t;
                        s4.mUnk_0c = func_020d4ef4(&b->mUnk_00.mPos);
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

u32 func_0209ec60(void) {
    return func_0209bf1c(CreatePicture1AndPicture2, DrawPicture, NULL);
}

u32 func_0209ec44(void) {
    return func_0209bf48(NULL, UpdatePicture, NULL);
}

void CreatePuddle(void *a) {
    gPuddle = func_0209bd08(a, gPuddleNsbmdName);
}

void func_0209ec00(void *a) {
    func_0209bbd0(a, gPuddle);
}

void DrawPuddle(void *a, Unk0209ec80 *b) {
    s32 s;
    s32 x;
    s32 y;
    s32 z;
    Vec3 v;

    s = 0x1e;
    func_01ff9048(0x14, &s, 1);
    z = b->mUnk_00.mPos.z >> 4;
    y = (b->mUnk_00.mPos.y + 0x1ccd) >> 4;
    x = b->mUnk_00.mPos.x >> 4;
    v.x = x;
    v.y = y;
    v.z = z;
    func_01ff9048(0x1c, &v, 3);
    func_01ff9048(0x1b, &b->mUnk_00.mScale, 3);
    func_01ff9048(0x1a, &b->mUnk_00.mMatrix, 9);
    func_0209bb2c(a, gPuddle, b);
}
