#include "01/code_02188950.h"
#include "01/code_02187074.h"
#include "01/code_02188158.h"
#include "01/code_02188e88.h"
#include "01/code_0219b240.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "01/code_021864ac.h"
#include "01/code_02186000.h"
#include "01/code_02187000.h"
#include "01/code_0219b250.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_0208b000.h"

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
