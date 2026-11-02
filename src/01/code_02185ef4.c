#include "01/code_02185ef4.h"

#include "Main/Unknown/code_0209bef0.h"
#include "01/code_0219e000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020eb000.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_02118000.h"
#include "Main/Unknown/code_0211e000.h"
#include "code_02147cd8.h"
#include "01/code_0218d520.h"
#include "01/unk_021a9000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d3000.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02021000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020e6000.h"
#include "01/code_02188950.h"
#include "01/code_02188158.h"
#include "01/code_02188e88.h"
#include "01/code_0219b240.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "code_02146d78.h"
#include "01/code_02186000.h"
#include "01/code_02187000.h"
#include "01/code_0219b250.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02148000.h"
#include "01/callees_0219b000.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_020d2000.h"
#include "01/code_021a2034.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_02042000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020da000.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_020fd000.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"

void func_ov001_02187b94(void *param_1, Vec3 *param_2, Vec3 *param_3, s32 param_4) {
    Vec3 local;
    Vec3 zero;
    Vec3 *p;
    s32 *z;

    if (param_1 != 0 && param_2 != 0) {
        local = data_ov001_021a7a64;
        p = &local;
        func_020fd684(param_1, p, param_2);
        if (param_3 != 0) {
            func_020fd540(&param_1, param_3, param_4);
        } else {
            z = (s32 *) &zero;
            z[0] = 0;
            z[1] = 0;
            z[2] = 0;
            func_020fd540(&param_1, &zero, param_4);
        }
    }
}

void func_ov001_02187b2c(void *param_1, Vec3 *param_2, Vec3 *param_3, s32 param_4) {
    Vec3 local;
    Vec3 zero;
    Vec3 *p;
    s32 *z;

    if (param_1 != 0 && param_2 != 0) {
        local = data_ov001_021a7a70;
        p = &local;
        func_020f4e78(param_1, p, param_2);
        if (param_3 != 0) {
            func_020f4dfc(&param_1, param_3, param_4);
        } else {
            z = (s32 *) &zero;
            z[0] = 0;
            z[1] = 0;
            z[2] = 0;
            func_020f4dfc(&param_1, &zero, param_4);
        }
    }
}

void func_ov001_02187af4(Unk02188950 *param_1) {
    s32 i;

    for (i = 0; i < 5; i++) {
        if (param_1->mUnk_0bc[i].mUnk_14 != 0) {
            func_0208b6b0(&param_1->mUnk_0bc[i].mUnk_14);
        }
    }
    param_1->mUnk_0b8 = 0;
}

// Writes to param_3 a point for entry param_2 of param_1->mUnk_0bc: param_1->mUnk_004 plus the entry's mUnk_08
// combined with the pair of data_0215d4b4 values selected by param_1->mUnk_184. The entry's mUnk_00 (1-5) selects
// the variant; other values write nothing.
void func_ov001_02187684(Unk02188950 *param_1, int param_2, Vec3 *param_3) {
    Unk02061808 *obj;
    s32 x;
    s32 y;
    s32 z;
    s32 t;

    switch (param_1->mUnk_0bc[param_2].mUnk_00) {
        case 1:
            param_3->x = param_1->mUnk_000.mUnk_04.x +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.z *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2]) >>
                                12) +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.x *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1]) >>
                                12);
            param_3->y = param_1->mUnk_000.mUnk_04.y + param_1->mUnk_0bc[param_2].mUnk_08.y;
            param_3->z = param_1->mUnk_000.mUnk_04.z +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.z *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1]) >>
                                12) -
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.x *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2]) >>
                                12);
            break;
        case 3:
            // As case 1 with mUnk_024 of the object from func_02061808 added, then halved.
            obj = func_02061808();
            param_3->x = param_1->mUnk_000.mUnk_04.x + obj->mUnk_024.x +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.z *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2]) >>
                                12) +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.x *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1]) >>
                                12);
            param_3->y = param_1->mUnk_000.mUnk_04.y + obj->mUnk_024.y + param_1->mUnk_0bc[param_2].mUnk_08.y;
            param_3->z = param_1->mUnk_000.mUnk_04.z + obj->mUnk_024.z +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.z *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1]) >>
                                12) -
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.x *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2]) >>
                                12);
            param_3->x >>= 1;
            param_3->y >>= 1;
            param_3->z >>= 1;
            break;
        case 2:
            // The entry's mUnk_08 is first multiplied per component by param_1->mUnk_01c, mUnk_020 and mUnk_024.
            t = param_1->mUnk_0bc[param_2].mUnk_08.y;
            y = (s32) (((s64) t * param_1->mUnk_000.mUnk_1c.y) >> 12);
            t = param_1->mUnk_0bc[param_2].mUnk_08.x;
            x = (s32) (((s64) t * param_1->mUnk_000.mUnk_1c.x) >> 12);
            t = param_1->mUnk_0bc[param_2].mUnk_08.z;
            z = (s32) (((s64) t * param_1->mUnk_000.mUnk_1c.z) >> 12);
            param_3->x = param_1->mUnk_000.mUnk_04.x +
                         (s32) (((s64) z * data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2]) >> 12) +
                         (s32) (((s64) x * data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1]) >> 12);
            param_3->y = param_1->mUnk_000.mUnk_04.y + y;
            param_3->z = param_1->mUnk_000.mUnk_04.z +
                         (s32) (((s64) z * data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1]) >> 12) -
                         (s32) (((s64) x * data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2]) >> 12);
            break;
        case 4:
            param_3->x = param_1->mUnk_000.mUnk_04.x +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.z *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2]) >>
                                12) +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.x *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1]) >>
                                12);
            param_3->y = param_1->mUnk_000.mUnk_9c->mUnk_00.y + param_1->mUnk_0bc[param_2].mUnk_08.y;
            param_3->z = param_1->mUnk_000.mUnk_04.z +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.z *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1]) >>
                                12) -
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.x *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2]) >>
                                12);
            break;
        case 5:
            param_3->x = param_1->mUnk_000.mUnk_04.x +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.z *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2]) >>
                                12) +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.x *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1]) >>
                                12);
            param_3->y = param_1->mUnk_0bc[param_2].mUnk_08.y - func_020d3d48(0);
            param_3->z = param_1->mUnk_000.mUnk_04.z +
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.z *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1]) >>
                                12) -
                         (s32) (((s64) param_1->mUnk_0bc[param_2].mUnk_08.x *
                                 data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2]) >>
                                12);
            break;
    }
}

void func_ov001_02187614(Unk02188950 *param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6,
                         s32 param_7) {
    Vec3 pos;

    param_1->mUnk_0bc[param_2].mUnk_04 = param_7;
    if ((param_1->mUnk_000.mUnk_02 & 0x400) != 0) {
        param_3 = -param_3;
    }
    param_1->mUnk_0bc[param_2].mUnk_08.x = param_3 << 4;
    param_1->mUnk_0bc[param_2].mUnk_08.y = param_4 << 4;
    param_1->mUnk_0bc[param_2].mUnk_08.z = param_5 << 4;
    func_ov001_02187684(param_1, param_2, &pos);
    if (param_6 != 0) {
        if (param_1->mUnk_0bc[param_2].mUnk_14 != 0) {
            func_0208b6b0(&param_1->mUnk_0bc[param_2].mUnk_14);
        }
        param_1->mUnk_0bc[param_2].mUnk_14 = func_0208b7bc(param_6, &pos);
    }
}

void func_ov001_021875c0(Unk02188950 *param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
    int i;

    for (i = 0; i < 5; i++) {
        if (param_1->mUnk_0bc[i].mUnk_14 == 0) {
            param_1->mUnk_0bc[i].mUnk_00 = 1;
            func_ov001_02187614(param_1, i, param_2, param_3, param_4, param_5, param_6);
            return;
        }
    }
}

void func_ov001_0218756c(Unk02188950 *param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
    int i;

    for (i = 0; i < 5; i++) {
        if (param_1->mUnk_0bc[i].mUnk_14 == 0) {
            param_1->mUnk_0bc[i].mUnk_00 = 2;
            func_ov001_02187614(param_1, i, param_2, param_3, param_4, param_5, param_6);
            return;
        }
    }
}

void func_ov001_02187518(Unk02188950 *param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
    int i;

    for (i = 0; i < 5; i++) {
        if (param_1->mUnk_0bc[i].mUnk_14 == 0) {
            param_1->mUnk_0bc[i].mUnk_00 = 4;
            func_ov001_02187614(param_1, i, param_2, param_3, param_4, param_5, param_6);
            return;
        }
    }
}

void func_ov001_021874c4(Unk02188950 *param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
    int i;

    for (i = 0; i < 5; i++) {
        if (param_1->mUnk_0bc[i].mUnk_14 == 0) {
            param_1->mUnk_0bc[i].mUnk_00 = 5;
            func_ov001_02187614(param_1, i, param_2, param_3, param_4, param_5, param_6);
            return;
        }
    }
}

void func_ov001_02187444(Unk02188950 *param_1, u32 param_2, int param_3) {
    int i;

    for (i = 0; i < 5; i++) {
        if (param_1->mUnk_0bc[i].mUnk_14 == 0) {
            param_1->mUnk_0bc[i].mUnk_08.x = param_1->mUnk_000.mUnk_04.x;
            param_1->mUnk_0bc[i].mUnk_08.y = -func_020d3d48(0);
            param_1->mUnk_0bc[i].mUnk_08.z = param_1->mUnk_000.mUnk_04.z;
            if (param_1->mUnk_0bc[i].mUnk_14 != 0) {
                func_0208b6b0(&param_1->mUnk_0bc[i].mUnk_14);
            }
            func_0208e490(param_2, &param_1->mUnk_0bc[i].mUnk_08, 1);
            param_1->mUnk_0bc[i].mUnk_00 = 0;
            param_1->mUnk_0bc[i].mUnk_04 = param_3;
            return;
        }
    }
}

void func_ov001_0218742c(Unk0206c1ac *param_1, const UnkVec16 *param_2) {
    param_1->mUnk_50 = *param_2;
}

void func_ov001_021872e0(Unk02188950 *param_1, int param_2, int param_3, int param_4, int param_5, int param_6,
                         int param_7, int param_8, u32 param_9) {
    int i;
    Vec3 pos;
    UnkVec16 rot;

    for (i = 0; i < 5; i++) {
        if (param_1->mUnk_0bc[i].mUnk_14 == 0) {
            param_1->mUnk_0bc[i].mUnk_00 = 1;
            param_1->mUnk_0bc[i].mUnk_04 = param_9;
            param_1->mUnk_0bc[i].mUnk_08.x = param_2 << 4;
            param_1->mUnk_0bc[i].mUnk_08.y = param_3 << 4;
            param_1->mUnk_0bc[i].mUnk_08.z = param_4 << 4;
            func_ov001_02187684(param_1, i, &pos);
            if (param_8 != 0) {
                if (param_1->mUnk_0bc[i].mUnk_14 != 0) {
                    func_0208b6b0(&param_1->mUnk_0bc[i].mUnk_14);
                }
                rot.x = ((s64) param_7 * data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2] >> 12) +
                        ((s64) param_5 * data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1] >> 12);
                rot.y = param_6;
                rot.z = ((s64) param_7 * data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1] >> 12) -
                        ((s64) param_5 * data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2] >> 12);
                func_0208b748(param_8, &pos, &rot, func_ov001_0218742c);
            }
        }
    }
}

void func_ov001_02187218(Unk02188950 *param_1, int param_2, s32 (*param_3)(Unk02188950 *)) {
    param_1->mUnk_158 = 0;
    param_1->mUnk_15c = param_3;
    param_1->mUnk_150 = param_2;
    param_1->mUnk_0b0 = 0;
    param_1->mUnk_0b4 = param_1->mUnk_0b4 > 0 ? param_1->mUnk_0b4 - 1 : 0;
    param_1->mUnk_2bc = 0;
    param_1->mUnk_2c0 = 1;
    if (param_1->mUnk_2c4 == 0) {
        param_1->mUnk_1d8 = 0;
        param_1->mUnk_1d4 = 0;
        param_1->mUnk_1dc = 0;
        param_1->mUnk_1e0 = 0;
        param_1->mUnk_1e4 = 0;
        param_1->mUnk_1e8 = 0;
        param_1->mUnk_1ec = 0;
        param_1->mUnk_1f0 = 0;
        param_1->mUnk_1f4 = 0;
        param_1->mUnk_20c = 0;
        param_1->mUnk_224 = 0;
        param_1->mUnk_228 = 0;
        param_1->mUnk_22c = 0;
        func_ov001_02187af4(param_1);
    }
}

void func_ov001_0218720c(Unk02188950 *param_1) {
    param_1->mUnk_2c0 = 0;
}

u32 func_ov001_021871f8(Unk02188950 *param_1, int param_2) {
    if (param_1->mUnk_150 < param_2) {
        return 1;
    }
    return 0;
}

int func_ov001_021871d0(Unk02188950 *param_1) {
    if ((param_1->mUnk_2c8 & 0x800) != 0 && param_1->mUnk_1c8.y <= 0) {
        return 1;
    }
    return 0;
}

void func_ov001_021870e4(void *param_1, Unk02188950 *param_2, const char *param_3, const char *param_4,
                         const char *param_5) {
    if (param_1 != 0 && param_3 != 0) {
        param_2->mUnk_304 = func_ov001_0219b478((Unk0219b478 *) (param_1), (char *) (param_3));
        if (param_4 != 0) {
            func_ov001_0219b3b4((Unk0219b250 *) (param_2->mUnk_304), (char *) (param_4));
        }
    }
    if (param_5 != 0) {
        param_2->mUnk_0a0 = func_ov001_0219b4d8((char *) (param_5));
    }
    param_2->mUnk_184 = (u16) (((s64) param_2->mUnk_000.mUnk_9c->mUnk_0c.y * 0xb60b60b60bLL + 0x80000000000LL) >> 44);
    param_2->mUnk_168 = 0x1f000;
    if (param_2->mUnk_0a0 != 0) {
        func_020d2950(&param_2->mUnk_000, param_2->mUnk_0a0->mUnk_00c << 2);
        param_2->mUnk_000.mUnk_1c.x = param_2->mUnk_0a0->mUnk_004;
        param_2->mUnk_000.mUnk_1c.y = param_2->mUnk_0a0->mUnk_004;
        param_2->mUnk_000.mUnk_1c.z = param_2->mUnk_0a0->mUnk_004;
    }
    param_2->mUnk_238 = param_2->mUnk_000.mUnk_04;
    param_2->mUnk_2bc = 0;
    param_2->mUnk_2c0 = 1;
    param_2->mUnk_148 = param_2->mUnk_000.mUnk_9c->mUnk_26;
}

void func_ov001_021870b0(void *param_1, Unk02188950 *param_2, const char *param_3) {
    if (param_1 != 0 && param_3 != 0) {
        param_2->mUnk_308 = func_ov001_0219b418((Unk0219b478 *) (param_1), (char *) (param_3));
        func_0209b940(param_2->mUnk_308, 0x3f);
        data_ov001_021a9ba0 = 0;
    }
}

void func_ov001_02187098(void) {
    if (data_ov001_021a9ba0 == 0) {
        data_ov001_021a9ba0++;
    } else {
        data_ov001_021a9ba0 = 0;
    }
}

int func_ov001_02187074(int param_1, int param_2, int param_3) {
    int v1;
    if (param_3 < param_1) {
        v1 = param_3 + param_2;
        if (param_3 + param_2 >= param_1) {
            v1 = param_1;
        }
        return v1;
    }
    if (param_3 > param_1) {
        v1 = param_3 - param_2;
        if (param_3 - param_2 <= param_1) {
            v1 = param_1;
        }
        return v1;
    }
    return param_3;
}

u16 func_ov001_02187024(Vec3 *param_1, Vec3 *param_2, s32 param_3, s32 param_4) {
    s32 diff = (u16) (func_02148714(param_1->x - param_2->x, param_1->z - param_2->z) - param_4);
    s32 res;

    if (param_3 < 0) {
        param_3 = -param_3;
    }
    if (diff > 0x8000) {
        diff -= 0x10000;
    }
    res = -param_3;
    if (diff >= res) {
        if (diff <= param_3) {
            param_3 = diff;
        }
        res = param_3;
    }
    return param_4 + res;
}

u16 func_ov001_02186fb4(Vec3 *param_1, Vec3 *param_2, s32 param_3, s32 param_4, s32 param_5) {
    s32 diff = (u16) (func_02148714(param_1->x - param_2->x, param_1->z - param_2->z) - param_5);
    s32 limit;
    s32 res;
    s32 target;

    if (param_3 < 0) {
        limit = -param_3;
    } else {
        limit = param_3;
    }
    if (diff > 0x8000) {
        diff -= 0x10000;
    }
    if (param_3 < 0) {
        diff += param_4;
        target = diff - 0x4000;
    } else {
        diff -= param_4;
        target = diff + 0x4000;
    }
    res = -limit;
    if (target >= res) {
        if (target <= limit) {
            limit = target;
        }
        res = limit;
    }
    return param_5 + res;
}

void func_ov001_021864ac(u32 param_1, Unk02188950 *param_2) {
    Vec3 pos;
    Vec3 v44;
    Vec3 v50;
    Vec3 v5c;
    Vec3 dir;
    Vec3 vel;
    s32 s;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 cur;
    s32 prev;
    s32 i;
    s32 idx;
    s64 speed;

    if (param_2->mUnk_158 == 0 && param_2->mUnk_15c != 0) {
        param_2->mUnk_158 = param_2->mUnk_15c;
        param_2->mUnk_15c = 0;
    }
    if (param_2->mUnk_158 != 0 && param_2->mUnk_158(param_2)) {
        param_2->mUnk_158 = 0;
        param_2->mUnk_154 = 0;
        param_2->mUnk_0b0 = 0;
        param_2->mUnk_150 = 0;
    }

    switch (param_2->mUnk_180) {
        case 1:
            param_2->mUnk_184 = param_2->mUnk_1a8;
            break;
        case 2:
            if (param_2->mUnk_19c > 0) {
                param_2->mUnk_194 = func_ov001_02187074(param_2->mUnk_198, param_2->mUnk_19c, param_2->mUnk_194);
            }
            if (param_2->mUnk_194 > 0) {
                param_2->mUnk_184 = func_ov001_02187024(&param_2->mUnk_188, &param_2->mUnk_000.mUnk_04,
                                                        param_2->mUnk_194, param_2->mUnk_184);
            }
            break;
        case 3:
            if (param_2->mUnk_19c > 0) {
                param_2->mUnk_194 = func_ov001_02187074(param_2->mUnk_198, param_2->mUnk_19c, param_2->mUnk_194);
            }
            if (param_2->mUnk_194 > 0) {
                param_2->mUnk_184 = func_ov001_02187024(&param_2->mUnk_000.mUnk_04, &param_2->mUnk_188,
                                                        param_2->mUnk_194, param_2->mUnk_184);
            }
            break;
        case 4:
            if (param_2->mUnk_19c > 0) {
                param_2->mUnk_194 = func_ov001_02187074(param_2->mUnk_198, param_2->mUnk_19c, param_2->mUnk_194);
            }
            if (param_2->mUnk_194 > 0) {
                param_2->mUnk_184 = func_ov001_02186fb4(&param_2->mUnk_188, &param_2->mUnk_000.mUnk_04,
                                                        param_2->mUnk_194, param_2->mUnk_1a0, param_2->mUnk_184);
            }
            break;
        case 5:
            if (param_2->mUnk_19c > 0) {
                param_2->mUnk_194 = func_ov001_02187074(param_2->mUnk_198, param_2->mUnk_19c, param_2->mUnk_194);
            }
            if (param_2->mUnk_194 > 0) {
                param_2->mUnk_184 += param_2->mUnk_194;
            }
            break;
        case 6:
        case 7:
        case 8:
            if (param_2->mUnk_19c > 0) {
                param_2->mUnk_194 = func_ov001_02187074(param_2->mUnk_198, param_2->mUnk_19c, param_2->mUnk_194);
            }
            if (param_2->mUnk_180 == 6) {
                if (func_ov001_02187024(&param_2->mUnk_188, &param_2->mUnk_000.mUnk_04, param_2->mUnk_194,
                                        param_2->mUnk_184) -
                        param_2->mUnk_184 >=
                    0) {
                    param_2->mUnk_180 = 8;
                } else {
                    param_2->mUnk_180 = 7;
                }
            }
            if (param_2->mUnk_180 == 8) {
                param_2->mUnk_184 += param_2->mUnk_194;
            } else if (param_2->mUnk_180 == 7) {
                param_2->mUnk_184 -= param_2->mUnk_194;
            }
            break;
    }

    switch (param_2->mUnk_1a4) {
        case 1:
            param_2->mUnk_1a8 = param_2->mUnk_184;
            break;
        case 2:
            if (param_2->mUnk_1c0 > 0) {
                param_2->mUnk_1b8 = func_ov001_02187074(param_2->mUnk_1bc, param_2->mUnk_1c0, param_2->mUnk_1b8);
            }
            if (param_2->mUnk_1b8 > 0) {
                param_2->mUnk_1a8 = func_ov001_02187024(&param_2->mUnk_1ac, &param_2->mUnk_000.mUnk_04,
                                                        param_2->mUnk_1b8, param_2->mUnk_1a8);
            }
            break;
        case 3:
            if (param_2->mUnk_1c0 > 0) {
                param_2->mUnk_1b8 = func_ov001_02187074(param_2->mUnk_1bc, param_2->mUnk_1c0, param_2->mUnk_1b8);
            }
            if (param_2->mUnk_1b8 > 0) {
                param_2->mUnk_1a8 = func_ov001_02187024(&param_2->mUnk_000.mUnk_04, &param_2->mUnk_1ac,
                                                        param_2->mUnk_1b8, param_2->mUnk_1a8);
            }
            break;
        case 4:
            if (param_2->mUnk_1c0 > 0) {
                param_2->mUnk_1b8 = func_ov001_02187074(param_2->mUnk_1bc, param_2->mUnk_1c0, param_2->mUnk_1b8);
            }
            if (param_2->mUnk_1b8 > 0) {
                param_2->mUnk_1a8 = func_ov001_02186fb4(&param_2->mUnk_1ac, &param_2->mUnk_000.mUnk_04,
                                                        param_2->mUnk_1b8, param_2->mUnk_1c4, param_2->mUnk_1a8);
            }
            break;
    }

    if (param_2->mUnk_17c > 0) {
        param_2->mUnk_174 = func_ov001_02187074(param_2->mUnk_178, param_2->mUnk_17c, param_2->mUnk_174);
    }
    if (param_2->mUnk_274 > 0) {
        param_2->mUnk_244 = func_ov001_02187074(param_2->mUnk_250, param_2->mUnk_274, param_2->mUnk_244);
        param_2->mUnk_248 = func_ov001_02187074(param_2->mUnk_254, param_2->mUnk_274, param_2->mUnk_248);
        param_2->mUnk_24c = func_ov001_02187074(param_2->mUnk_258, param_2->mUnk_274, param_2->mUnk_24c);
    }
    if (param_2->mUnk_278 > 0) {
        param_2->mUnk_25c = func_ov001_02187074(param_2->mUnk_268, param_2->mUnk_278, param_2->mUnk_25c);
        param_2->mUnk_260 = func_ov001_02187074(param_2->mUnk_26c, param_2->mUnk_278, param_2->mUnk_260);
        param_2->mUnk_264 = func_ov001_02187074(param_2->mUnk_270, param_2->mUnk_278, param_2->mUnk_264);
    }
    if (param_2->mUnk_2b0 > 0) {
        param_2->mUnk_280 = func_ov001_02187074(param_2->mUnk_28c, param_2->mUnk_2b0, param_2->mUnk_280);
        param_2->mUnk_284 = func_ov001_02187074(param_2->mUnk_290, param_2->mUnk_2b0, param_2->mUnk_284);
        param_2->mUnk_288 = func_ov001_02187074(param_2->mUnk_294, param_2->mUnk_2b0, param_2->mUnk_288);
    }
    if (param_2->mUnk_2b4 > 0) {
        param_2->mUnk_298 = func_ov001_02187074(param_2->mUnk_2a4, param_2->mUnk_2b4, param_2->mUnk_298);
        param_2->mUnk_29c = func_ov001_02187074(param_2->mUnk_2a8, param_2->mUnk_2b4, param_2->mUnk_29c);
        param_2->mUnk_2a0 = func_ov001_02187074(param_2->mUnk_2ac, param_2->mUnk_2b4, param_2->mUnk_2a0);
    }

    if (param_2->mUnk_2c0 != 0) {
        param_2->mUnk_1c8.y -= param_2->mUnk_0a0->mUnk_01c;
    }
    if (-param_2->mUnk_0a0->mUnk_018 < *(s32 *) &param_2->mUnk_1c8 &&
        *(s32 *) &param_2->mUnk_1c8 < param_2->mUnk_0a0->mUnk_018 &&
        -param_2->mUnk_0a0->mUnk_018 < param_2->mUnk_1c8.z && param_2->mUnk_1c8.z < param_2->mUnk_0a0->mUnk_018) {
        param_2->mUnk_1c8.x = 0;
        param_2->mUnk_1c8.z = 0;
    } else if (param_2->mUnk_2c8 & 0x1e34ef) {
        s = param_2->mUnk_0a0->mUnk_010;
        param_2->mUnk_1c8.x = (s32) (((s64) param_2->mUnk_1c8.x * s) >> 12);
        param_2->mUnk_1c8.y = (s32) (((s64) param_2->mUnk_1c8.y * s) >> 12);
        param_2->mUnk_1c8.z = (s32) (((s64) param_2->mUnk_1c8.z * s) >> 12);
    } else {
        s = param_2->mUnk_0a0->mUnk_014;
        param_2->mUnk_1c8.x = (s32) (((s64) param_2->mUnk_1c8.x * s) >> 12);
        param_2->mUnk_1c8.y = (s32) (((s64) param_2->mUnk_1c8.y * s) >> 12);
        param_2->mUnk_1c8.z = (s32) (((s64) param_2->mUnk_1c8.z * s) >> 12);
    }

    idx = ((u16) param_2->mUnk_1a8 >> 4) * 2;
    speed = param_2->mUnk_174;
    dy = param_2->mUnk_1c8.y;
    dz = param_2->mUnk_1c8.z + (s32) ((speed * data_0215d4b4[idx + 1]) >> 12);
    dx = param_2->mUnk_1c8.x + (s32) ((speed * data_0215d4b4[idx]) >> 12);
    param_2->mUnk_000.mUnk_04.x += dx;
    param_2->mUnk_000.mUnk_04.y += dy;
    param_2->mUnk_000.mUnk_04.z += dz;

    pos.x = param_2->mUnk_000.mUnk_04.x;
    pos.y = param_2->mUnk_000.mUnk_04.y + 0x14000;
    pos.z = param_2->mUnk_000.mUnk_04.z;
    param_2->mUnk_2c8 = 0;
    if (func_01ffdee4((int *) &pos, 0, 0, 0x14000, param_2->mUnk_2b8 == 1 ? 4 : 1, -2, (int *) &v44, (int *) &v50,
                      (int *) &v5c, &param_2->mUnk_2c8, 0, 0, 0, 0)) {
        if (param_2->mUnk_2b8 == 2 || param_2->mUnk_2b8 == 3) {
            param_2->mUnk_000.mUnk_04.y += v44.y;
        } else {
            param_2->mUnk_000.mUnk_04.x += v44.x;
            param_2->mUnk_000.mUnk_04.y += v44.y;
            param_2->mUnk_000.mUnk_04.z += v44.z;
        }
    }
    if (param_2->mUnk_2b8 != 2 && (param_2->mUnk_2c8 & 0x214300)) {
        if ((s64) v5c.x * v5c.x + (s64) v5c.y * v5c.y + (s64) v5c.z * v5c.z >= 0x10) {
            func_02039860(&v5c, &dir);
        }
        dir.y = 0;
        func_02147fd8(param_2->mUnk_0a0->mUnk_030, &dir, &param_2->mUnk_1c8, &param_2->mUnk_1c8);
    }

    if (param_2->mUnk_2c8 & 0x1e34ef) {
        if (param_2->mUnk_1c8.y > 0) {
            param_2->mUnk_2c8 &= ~0x1e34ef;
        } else if (param_2->mUnk_2bc != 0) {
            param_2->mUnk_1c8.y = (s32) (((s64) param_2->mUnk_1c8.y * -param_2->mUnk_0a0->mUnk_020) >> 12);
            if (param_2->mUnk_1c8.y < param_2->mUnk_0a0->mUnk_018) {
                param_2->mUnk_2bc = 0;
                param_2->mUnk_1c8.y = 0;
            }
        } else {
            param_2->mUnk_1c8.y = 0;
        }
    }
    if (param_2->mUnk_000.mUnk_04.y < 0) {
        param_2->mUnk_000.mUnk_04.y = 0;
        param_2->mUnk_2c8 |= data_ov001_021a6584;
    }
    if (param_2->mUnk_170 > 0) {
        param_2->mUnk_168 = func_ov001_02187074(param_2->mUnk_16c, param_2->mUnk_170, param_2->mUnk_168);
        if (param_2->mUnk_168 == param_2->mUnk_16c) {
            param_2->mUnk_170 = 0;
        }
    }
    if (param_2->mUnk_164 > 0) {
        param_2->mUnk_000.mUnk_1c.x = param_2->mUnk_000.mUnk_1c.y = param_2->mUnk_000.mUnk_1c.z =
            func_ov001_02187074(param_2->mUnk_160, param_2->mUnk_164, param_2->mUnk_000.mUnk_1c.x);
    }
    if (param_2->mUnk_234 == 1) {
        func_02146d44(&param_2->mUnk_000.mUnk_28.mUnk_00.x, data_0215d4b4[((u16) param_2->mUnk_184 >> 4) * 2],
                      data_0215d4b4[((u16) param_2->mUnk_184 >> 4) * 2 + 1]);
        func_02146d78((Vec3 *) &param_2->mUnk_244, &param_2->mUnk_000.mUnk_28.mUnk_00.x, &param_2->mUnk_238);
        func_02148504(&param_2->mUnk_238, &param_2->mUnk_000.mUnk_04, &param_2->mUnk_238);
    } else {
        param_2->mUnk_238.x = param_2->mUnk_000.mUnk_04.x + param_2->mUnk_244;
        param_2->mUnk_238.y = param_2->mUnk_000.mUnk_04.y + param_2->mUnk_248;
        param_2->mUnk_238.z = param_2->mUnk_000.mUnk_04.z + param_2->mUnk_24c;
    }
    param_2->mUnk_000.mUnk_7e = param_2->mUnk_184;

    if (param_2->mUnk_304 != 0) {
        prev = func_0209b620((int) param_2->mUnk_304);
        func_ov001_0219b250(param_2->mUnk_304);
        cur = func_0209b620((int) param_2->mUnk_304);
        if (param_2->mUnk_1d8 != 0) {
            if (prev < param_2->mUnk_1d8 && param_2->mUnk_1d8 <= cur) {
                func_ov001_02188e94(param_2, &param_2->mUnk_1dc);
            } else if ((u32) cur < (u32) prev && (param_2->mUnk_1d8 <= cur || prev < param_2->mUnk_1d8)) {
                func_ov001_02188e94(param_2, &param_2->mUnk_1dc);
            }
        }
        if (param_2->mUnk_1e0 != 0) {
            if (prev < param_2->mUnk_1e0 && param_2->mUnk_1e0 <= cur) {
                param_2->mUnk_1e4(param_2);
            } else if ((u32) cur < (u32) prev && (param_2->mUnk_1e0 <= cur || prev < param_2->mUnk_1e0)) {
                param_2->mUnk_1e4(param_2);
            }
        }
        if (param_2->mUnk_1e8 != 0) {
            if (prev < param_2->mUnk_1e8 && param_2->mUnk_1e8 <= cur) {
                param_2->mUnk_1ec(param_2);
            } else if ((u32) cur < (u32) prev && (param_2->mUnk_1e8 <= cur || prev < param_2->mUnk_1e8)) {
                param_2->mUnk_1ec(param_2);
            }
        }
        if (!func_ov001_0219b240((int) param_2->mUnk_304)) {
            func_ov001_02188e94(param_2, &param_2->mUnk_1d4);
        }
    }

    param_2->mUnk_0b0++;
    if (param_2->mUnk_1f0 != 0 && param_2->mUnk_0b0 == param_2->mUnk_1f0) {
        param_2->mUnk_1f0 = 0;
        param_2->mUnk_0b0 = 0;
        func_ov001_02188e94(param_2, &param_2->mUnk_1f4);
    }
    if (param_2->mUnk_20c != 0 && func_ov001_021881a8(param_2, (Vec3 *) &param_2->mUnk_200, (s32) (param_2->mUnk_1f8),
                                                      (s32) (param_2->mUnk_1fc))) {
        func_ov001_02188e94(param_2, &param_2->mUnk_20c);
    }
    if (param_2->mUnk_224 != 0 && !func_ov001_021881a8(param_2, (Vec3 *) &param_2->mUnk_218, (s32) (param_2->mUnk_210),
                                                       (s32) (param_2->mUnk_214))) {
        func_ov001_02188e94(param_2, &param_2->mUnk_224);
    }
    if (param_2->mUnk_228 != 0 && param_2->mUnk_1c8.y == 0 && -param_2->mUnk_0a0->mUnk_018 < param_2->mUnk_174 &&
        param_2->mUnk_0a0->mUnk_018 > param_2->mUnk_174 && -param_2->mUnk_0a0->mUnk_018 < param_2->mUnk_1c8.x &&
        param_2->mUnk_0a0->mUnk_018 > param_2->mUnk_1c8.x && -param_2->mUnk_0a0->mUnk_018 < param_2->mUnk_1c8.z &&
        param_2->mUnk_0a0->mUnk_018 > param_2->mUnk_1c8.z && (param_2->mUnk_2c8 & 0x1e34ef)) {
        func_ov001_02188e94(param_2, &param_2->mUnk_228);
    }
    if (param_2->mUnk_22c != 0 && param_2->mUnk_1c8.y <= 0 && (param_2->mUnk_2c8 & 0x1e34ef)) {
        func_ov001_02188e94(param_2, &param_2->mUnk_22c);
    }

    for (i = 0; i < 5; i++) {
        func_ov001_02187684(param_2, i, &vel);
        if (param_2->mUnk_0bc[i].mUnk_14 != 0) {
            if (param_2->mUnk_0bc[i].mUnk_04 > 0 && --param_2->mUnk_0bc[i].mUnk_04 == 0) {
                func_0208b6b0(&param_2->mUnk_0bc[i].mUnk_14);
            } else {
                func_0208b5b0(param_2->mUnk_0bc[i].mUnk_14, &vel);
            }
        }
    }
    if (param_2->mUnk_2d0 > 0) {
        param_2->mUnk_2d0--;
    }
}

void func_ov001_02186368(void *param_1, Unk02188950 *param_2) {
    s32 i;
    s32 depth;
    Unk0219b250_10_04 *obj;
    s32 level;
    s32 value;
    Vec3 v;
    s32 m[9];
    s32 k;

    depth = param_2->mUnk_168 >> 12;
    v.x = param_2->mUnk_000.mUnk_04.x >> 4;
    v.y = param_2->mUnk_000.mUnk_04.y >> 4;
    v.z = param_2->mUnk_000.mUnk_04.z >> 4;
    level = func_020e69bc(&v);
    if (level >= depth) {
        level = depth;
    }
    if (level > 0) {
        if (level >= 0x1f) {
            level = 0x1f;
        }
        if (level >= 0x1f) {
            func_02012ffc((Unk0201290c *) param_2->mUnk_304->mUnk_10->mUnk_04, 1);
            func_0209b940(param_2->mUnk_304, 3);
        } else if (param_2->mUnk_27c <= 1) {
            func_02012ffc((Unk0201290c *) param_2->mUnk_304->mUnk_10->mUnk_04, 1);
            func_0209b940(param_2->mUnk_304, 3);
        } else {
            obj = param_2->mUnk_304->mUnk_10->mUnk_04;
            func_02012ffc((Unk0201290c *) obj, 1);
            for (i = 0; i < obj->mUnk_18; i++) {
                func_0209b904(param_2->mUnk_304, func_020d3c44(), i);
            }
        }
        value = 0x1e;
        func_01ff9048(0x14, &value, 1);
        func_01ff9048(0x19, func_020e6b58(&param_2->mUnk_000.mUnk_04), 0xc);
        if (param_2->mUnk_000.mUnk_7e != 0) {
            k = param_2->mUnk_000.mUnk_7e >> 4;
            func_02146d44(m, data_0215d4b4[k * 2], data_0215d4b4[k * 2 + 1]);
            func_01ff9048(0x1a, m, 9);
        }
        func_01ff9048(0x1b, &param_2->mUnk_000.mUnk_1c.x, 3);
        func_0209b9a4(param_2->mUnk_304, level);
        func_0209b7a0(param_2->mUnk_304, param_2->mUnk_000.mUnk_02 & 0x400, 0);
        func_0209bb2c(param_1, param_2->mUnk_304, param_2);
    }
}

void func_ov001_021861f4(void *param_1, Unk02188950 *param_2, s32 param_3) {
    s32 depth;
    s32 value;
    Vec3 v;

    depth = param_2->mUnk_168 >> 12;
    if (param_2->mUnk_27c == 2) {
        v.x = param_2->mUnk_000.mUnk_04.x;
        v.y = param_2->mUnk_000.mUnk_04.y;
        v.z = param_2->mUnk_000.mUnk_04.z;
    } else if (param_2->mUnk_27c == 3) {
        v.x = param_2->mUnk_2e8.x;
        v.y = param_2->mUnk_000.mUnk_9c->mUnk_00.y;
        v.z = param_2->mUnk_2e8.z;
    } else {
        if (depth >= 4) {
            s32 t = depth - ((param_2->mUnk_000.mUnk_04.y - param_2->mUnk_000.mUnk_9c->mUnk_00.y) >> 15);

            if (t <= 4) {
                t = 4;
            }
            depth = (u16) t;
        }
        v.x = param_2->mUnk_000.mUnk_04.x;
        v.y = param_2->mUnk_000.mUnk_9c->mUnk_00.y;
        v.z = param_2->mUnk_000.mUnk_04.z;
    }
    if (depth > 0x10) {
        depth = 0x10;
    }
    if (param_3 != 0) {
        depth = 0x14 - depth;
    }
    if (depth > 0) {
        s32 m[9];
        Vec3 w;
        Vec3 u;
        s32 k;
        s32 a;
        s32 b;
        s32 c;

        value = 0x1e;
        func_01ff9048(0x14, &value, 1);
        func_01ff9048(0x19, func_020e6b58(&v), 0xc);
        k = (u16) param_2->mUnk_184 >> 4;
        func_02146d44(m, data_0215d4b4[k * 2], data_0215d4b4[k * 2 + 1]);
        func_01ff9048(0x1a, m, 9);
        c = param_2->mUnk_288 >> 4;
        b = param_2->mUnk_284 >> 4;
        a = param_2->mUnk_280 >> 4;
        w.x = a;
        w.y = b;
        w.z = c;
        func_01ff9048(0x1c, &w, 3);
        func_01ff9048(0x1b, &param_2->mUnk_298, 3);
        if (data_ov001_021a9ba0 == 0) {
            u.x = 0x1333;
            u.y = 0x1000;
            u.z = 0x1333;
            func_01ff9048(0x1b, &u, 3);
        }
        func_0209b940(param_2->mUnk_308, 3);
        func_0209b9a4(param_2->mUnk_308, depth);
        func_0209bb2c(param_1, param_2->mUnk_308, param_2);
    }
}

s32 func_ov001_021860cc(Unk02188950 *param_1, Vec3 *param_2, s32 param_3, Vec3 *param_4) {
    s32 d1;
    s32 d2;
    s32 d3;

    switch (param_1->mUnk_234) {
        case 0:
            param_3 += param_1->mUnk_25c;
            d1 = param_2->x - param_1->mUnk_238.x;
            d2 = param_2->y - param_1->mUnk_238.y;
            d3 = param_2->z - param_1->mUnk_238.z;
            if ((s64) d3 * d3 + ((s64) d1 * d1 + (s64) d2 * d2) < (s64) param_3 * param_3) {
                func_020eb3f0(param_2, &param_1->mUnk_238, param_3, param_4);
                return 1;
            }
            return 0;
        case 2:
            return func_020ead80(param_2, &param_1->mUnk_238, &param_1->mUnk_000.mUnk_28.mUnk_00, param_1->mUnk_25c,
                                 param_1->mUnk_260, param_1->mUnk_260, param_3, param_4);
        case 1:
            return func_020eafc4(param_2, &param_1->mUnk_238, &param_1->mUnk_000.mUnk_28.mUnk_00,
                                 (Vec3 *) &param_1->mUnk_25c, (Vec3 *) &param_1->mUnk_25c, param_3, param_4);
        default:
            return 0;
    }
}

s32 func_ov001_02185fb0(Unk02188950 *param_1, Unk02185fb0_1 *param_2, u8 *param_3, u8 *param_4) {
    Vec3 v;
    s64 k;
    u32 mode;
    UnkFunc *fn;

    mode = *param_3;
    param_1->mUnk_2d8 = *param_4;
    param_1->mUnk_000.mUnk_10.x = 0;
    param_1->mUnk_000.mUnk_10.y = 0;
    param_1->mUnk_000.mUnk_10.z = 0;
    if (mode == 1) {
        v.x = param_1->mUnk_000.mUnk_04.x - param_2->mUnk_80;
        v.y = 0;
        v.z = param_1->mUnk_000.mUnk_04.z - param_2->mUnk_88;
        if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
            func_02039860(&v, &v);
            k = -param_1->mUnk_0a0->mUnk_024;
            param_1->mUnk_000.mUnk_10.x = (s32) (((s64) v.x * k) >> 12);
            param_1->mUnk_000.mUnk_10.y = (s32) (((s64) v.y * k) >> 12);
            param_1->mUnk_000.mUnk_10.z = (s32) (((s64) v.z * k) >> 12);
            func_02147fd8(param_1->mUnk_0a0->mUnk_028, &v, &param_1->mUnk_1c8, &param_1->mUnk_1c8);
        }
        fn = param_1->mUnk_2d4;
        param_1->mUnk_2d4 = 0;
        if (fn) {
            fn(param_1, param_2);
        }
    }
    if (param_1->mUnk_2d0 == 0) {
        param_1->mUnk_2d0 = 0x1f;
    }
    return param_1->mUnk_2d8;
}

s32 func_ov001_02185f04(Unk02188950 *param_1, Unk02185f04_1 *param_2, u8 *param_3, u8 *param_4) {
    Vec3 v;
    UnkFunc *fn;

    param_1->mUnk_2e0 = *param_4;
    v.x = param_1->mUnk_000.mUnk_04.x - param_2->mUnk_50;
    v.y = 0;
    v.z = param_1->mUnk_000.mUnk_04.z - param_2->mUnk_58;
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        func_02039860(&v, &v);
        func_02147fd8(param_1->mUnk_0a0->mUnk_02c, &v, &param_1->mUnk_1c8, &param_1->mUnk_1c8);
    }
    fn = param_1->mUnk_2dc;
    param_1->mUnk_2dc = 0;
    if (fn) {
        fn(param_1, param_2);
    }
    return param_1->mUnk_2e0;
}

void *func_ov001_02185ef4(void) {
    return (void *) func_0209bf48(0, 0, 0);
}
