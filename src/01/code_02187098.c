#include "01/code_02187098.h"
#include "01/code_02187000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "01/callees_0219b000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d3000.h"

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
