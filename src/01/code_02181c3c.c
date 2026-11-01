#include "01/code_02181c3c.h"
#include "01/code_02182000.h"
#include "Main/Unknown/code_020d8000.h"
#include "code_02147cd8.h"

void func_ov001_02181c3c(void *param_1, Unk02181c3c *param_2) {
    s32 n;
    switch (param_2->mUnk_0f8) {
        case 2:
            n = param_2->mUnk_0a0 + 1;
            if (n >= 31) {
                n = 31;
            }
            param_2->mUnk_0a0 = n;
            func_ov001_02182eb8(param_2, 1);
            param_2->mUnk_000.mUnk_10.y -= 0x333;
            func_02148504(&param_2->mUnk_000.mUnk_04, &param_2->mUnk_000.mUnk_10, &param_2->mUnk_000.mUnk_04);
            if (param_2->mUnk_000.mUnk_04.y <= param_2->mUnk_0e4) {
                param_2->mUnk_000.mUnk_04.y = param_2->mUnk_0e4;
                if (param_2->mUnk_000.mUnk_10.y <= 0) {
                    param_2->mUnk_000.mUnk_10.y = ((s64) param_2->mUnk_000.mUnk_10.y * -0x800) >> 12;
                    if (param_2->mUnk_000.mUnk_10.y < 0x1000) {
                        param_2->mUnk_000.mUnk_10.x = 0;
                        param_2->mUnk_000.mUnk_10.y = 0;
                        param_2->mUnk_000.mUnk_10.z = 0;
                        param_2->mUnk_0f8 = 0;
                    }
                    func_020d2600(0x1d8, &param_2->mUnk_000.mUnk_04, 2);
                }
            }
            break;
        case 0: {
            u16 radius;
            s32 i;
            s32 found;
            Vec3 *v;
            s32 dx;
            s32 dz;
            func_ov001_02182eb8(param_2, 1);
            if (param_2->mUnk_0b4.mUnk_08 != 0xffff) {
                func_020d8cc8(&param_2->mUnk_0b4);
                func_020d8bf8(&param_2->mUnk_0b4, &param_2->mUnk_000.mUnk_04, &param_2->mUnk_000.mUnk_10);
                param_2->mUnk_000.mUnk_04.y += 0xe000;
                param_2->mUnk_0d8 = param_2->mUnk_000.mUnk_04;
            } else {
                param_2->mUnk_000.mUnk_10.x = 0;
                param_2->mUnk_000.mUnk_10.y = 0;
                param_2->mUnk_000.mUnk_10.z = 0;
            }
            if (param_2->mUnk_000.mUnk_9c->mUnk_2a != 0) {
                radius = param_2->mUnk_000.mUnk_9c->mUnk_2a;
                for (i = 0; i < data_021759c0->mUnk_3d0; i++) {
                    v = &func_0207a974((u16) i)->mUnk_80;
                    dx = v->x - param_2->mUnk_000.mUnk_04.x;
                    dz = v->z - param_2->mUnk_000.mUnk_04.z;
                    if ((s64) dx * dx + (s64) dz * dz < (s64) (radius << 12) * (radius << 12)) {
                        found = 1;
                        goto checked;
                    }
                }
                found = 0;
            checked:
                if (!found) {
                    goto skip;
                }
            }
            n = param_2->mUnk_0a0 + 1;
            if (n >= 31) {
                n = 31;
            }
            param_2->mUnk_0a0 = n;
            break;
        skip:
            param_2->mUnk_0a0 = 0;
            break;
        }
        case 8:
            n = param_2->mUnk_0a0 - 1;
            if (n <= 0) {
                n = 0;
            }
            param_2->mUnk_0a0 = n;
            func_ov001_02182eb8(param_2, 4);
            param_2->mUnk_000.mUnk_04.y += param_2->mUnk_000.mUnk_10.y;
            param_2->mUnk_000.mUnk_10.y -= 0x333;
            if (param_2->mUnk_0a0 == 0) {
                param_2->mUnk_0f8 = 9;
            }
            break;
        case 1: {
            Unk0206bcb0 *e;
            n = param_2->mUnk_0a0 - 1;
            if (n <= 0) {
                n = 0;
            }
            param_2->mUnk_0a0 = n;
            func_ov001_02182eb8(param_2, 4);
            e = func_0207a974((u16) data_021759c0->mUnk_62);
            param_2->mUnk_000.mUnk_04.x = e->mUnk_80.x;
            param_2->mUnk_000.mUnk_04.y += param_2->mUnk_000.mUnk_10.y;
            param_2->mUnk_000.mUnk_04.z = e->mUnk_80.z;
            param_2->mUnk_000.mUnk_10.y -= 0x333;
            if (param_2->mUnk_0ac-- <= 0) {
                func_020d2398((void *) ((u32) param_2));
            } else if (param_2->mUnk_0ac == 3) {
                func_02081f10(func_0208b7bc(0x3f4, &e->mUnk_80), e->mUnk_74, 0x18);
            }
            if (param_2->mUnk_0fc != 0) {
                func_0208b5b0(param_2->mUnk_0fc, &param_2->mUnk_000.mUnk_04);
                if (param_2->mUnk_100-- < 0) {
                    func_0208b6b0(&param_2->mUnk_0fc);
                }
            }
            break;
        }
        case 3: {
            u32 flags;
            Vec3 pos;
            Vec3 delta;
            Vec3 out1;
            Vec3 out2;
            n = param_2->mUnk_0a0 + 1;
            if (n >= 31) {
                n = 31;
            }
            param_2->mUnk_0a0 = n;
            if (param_2->mUnk_0b0 < 0x1000) {
                param_2->mUnk_0b0 += 0x29;
                if (param_2->mUnk_0b0 > 0x1000) {
                    param_2->mUnk_0b0 = 0x1000;
                }
            }
            func_ov001_02182eb8(param_2, 1);
            param_2->mUnk_000.mUnk_10.y -= 0x333;
            func_02148504(&param_2->mUnk_000.mUnk_04, &param_2->mUnk_000.mUnk_10, &param_2->mUnk_000.mUnk_04);
            pos.x = param_2->mUnk_000.mUnk_04.x;
            pos.y = param_2->mUnk_000.mUnk_58.x + (param_2->mUnk_000.mUnk_04.y - 0xe000);
            pos.z = param_2->mUnk_000.mUnk_04.z;
            if (func_020d2c2c(&pos, &param_2->mUnk_000.mUnk_10, param_2->mUnk_000.mUnk_58.x, param_2->mUnk_000.mUnk_64,
                              2, &delta) != 0) {
                func_02148504(&param_2->mUnk_000.mUnk_04, &delta, &param_2->mUnk_000.mUnk_04);
                if ((s64) delta.x * delta.x + (s64) delta.y * delta.y + (s64) delta.z * delta.z >= 0x10) {
                    func_02039860(&delta, &param_2->mUnk_000.mUnk_10);
                }
                param_2->mUnk_000.mUnk_10.x = ((s64) param_2->mUnk_000.mUnk_10.x * 0x1400) >> 12;
                param_2->mUnk_000.mUnk_10.y = ((s64) param_2->mUnk_000.mUnk_10.y * 0x1400) >> 12;
                param_2->mUnk_000.mUnk_10.z = ((s64) param_2->mUnk_000.mUnk_10.z * 0x1400) >> 12;
            }
            if (func_01ffdee4((int *) &pos, 0, 0, param_2->mUnk_000.mUnk_58.x, 1, param_2->mUnk_000.mUnk_64,
                              (int *) &delta, (int *) &out1, (int *) &out2, &flags, 0, 0, 0, 0) != 0) {
                func_02148504(&param_2->mUnk_000.mUnk_04, &delta, &param_2->mUnk_000.mUnk_04);
                if (flags & 0x214300) {
                    func_020eaa14(&param_2->mUnk_000.mUnk_10, &out2, 0x1000, 0x1000, 0xc00, &param_2->mUnk_000.mUnk_10);
                    if ((s64) param_2->mUnk_000.mUnk_10.x * param_2->mUnk_000.mUnk_10.x +
                            (s64) param_2->mUnk_000.mUnk_10.y * param_2->mUnk_000.mUnk_10.y +
                            (s64) param_2->mUnk_000.mUnk_10.z * param_2->mUnk_000.mUnk_10.z >=
                        0x10) {
                        func_02039860(&param_2->mUnk_000.mUnk_10, &param_2->mUnk_000.mUnk_10);
                    }
                    param_2->mUnk_000.mUnk_10.x = ((s64) param_2->mUnk_000.mUnk_10.x * 0x1400) >> 12;
                    param_2->mUnk_000.mUnk_10.y = ((s64) param_2->mUnk_000.mUnk_10.y * 0x1400) >> 12;
                    param_2->mUnk_000.mUnk_10.z = ((s64) param_2->mUnk_000.mUnk_10.z * 0x1400) >> 12;
                }
                if ((flags & 0x1e34ef) && param_2->mUnk_000.mUnk_10.y <= 0) {
                    param_2->mUnk_000.mUnk_10.y = ((s64) param_2->mUnk_000.mUnk_10.y * -0x800) >> 12;
                    if (param_2->mUnk_000.mUnk_10.y < 0x1000) {
                        param_2->mUnk_000.mUnk_10.x = 0;
                        param_2->mUnk_000.mUnk_10.y = 0;
                        param_2->mUnk_000.mUnk_10.z = 0;
                        param_2->mUnk_0f8 = 0;
                    }
                    func_020d2600(0x1d8, &param_2->mUnk_000.mUnk_04, 2);
                }
                if ((flags & 0x800) || param_2->mUnk_000.mUnk_04.y < 0) {
                    param_2->mUnk_0f8 = 4;
                }
            }
            param_2->mUnk_0d8.x = param_2->mUnk_000.mUnk_04.x;
            param_2->mUnk_0d8.z = param_2->mUnk_000.mUnk_04.z;
            break;
        }
        case 4:
            func_ov001_02182eb8(param_2, 1);
            param_2->mUnk_000.mUnk_10.y -= 0x333;
            func_02148504(&param_2->mUnk_000.mUnk_04, &param_2->mUnk_000.mUnk_10, &param_2->mUnk_000.mUnk_04);
            n = param_2->mUnk_0a0 - 1;
            if (n > 0) {
                param_2->mUnk_0a0 = n;
                break;
            }
            if (param_2->mUnk_000.mUnk_9c->mUnk_2c != 0) {
                param_2->mUnk_0f8 = 7;
                param_2->mUnk_0b0 = 0x1000;
                param_2->mUnk_0a0 = 0;
                param_2->mUnk_000.mUnk_02 |= data_ov001_021a6574;
                if (data_021759c0->mUnk_08 == 4) {
                    func_ov001_02181630(1);
                }
            } else {
                param_2->mUnk_000.mUnk_04.x = param_2->mUnk_000.mUnk_9c->mUnk_00.x;
                param_2->mUnk_000.mUnk_04.y = param_2->mUnk_000.mUnk_9c->mUnk_00.y + 0x64000;
                param_2->mUnk_000.mUnk_04.z = param_2->mUnk_000.mUnk_9c->mUnk_00.z;
                param_2->mUnk_000.mUnk_10.x = 0;
                param_2->mUnk_000.mUnk_10.y = 0;
                param_2->mUnk_000.mUnk_10.z = 0;
                param_2->mUnk_0e4 = param_2->mUnk_000.mUnk_9c->mUnk_00.y + 0xe000;
                param_2->mUnk_0f8 = 2;
                param_2->mUnk_0b0 = 0x1000;
                param_2->mUnk_0a0 = 0;
                param_2->mUnk_000.mUnk_02 &= ~1;
            }
            break;
        case 5:
            n = param_2->mUnk_0a0 + 1;
            if (n >= 31) {
                n = 31;
            }
            param_2->mUnk_0a0 = n;
            if (param_2->mUnk_0b0 < 0x1000) {
                param_2->mUnk_0b0 += 0x29;
                if (param_2->mUnk_0b0 > 0x1000) {
                    param_2->mUnk_0b0 = 0x1000;
                }
            }
            func_ov001_02182eb8(param_2, 1);
            param_2->mUnk_000.mUnk_10.y -= 0x333;
            func_02148504(&param_2->mUnk_000.mUnk_04, &param_2->mUnk_000.mUnk_10, &param_2->mUnk_000.mUnk_04);
            if (param_2->mUnk_000.mUnk_10.y <= 0) {
                param_2->mUnk_0f8 = 6;
            }
            break;
        case 6:
            if (param_2->mUnk_0b0 < 0x1000) {
                param_2->mUnk_0b0 += 0x29;
                if (param_2->mUnk_0b0 > 0x1000) {
                    param_2->mUnk_0b0 = 0x1000;
                }
            }
            func_ov001_02182eb8(param_2, 1);
            if (param_2->mUnk_000.mUnk_04.x < param_2->mUnk_0e8->x) {
                param_2->mUnk_000.mUnk_10.x += 0x400;
            } else if (param_2->mUnk_000.mUnk_04.x > param_2->mUnk_0e8->x) {
                param_2->mUnk_000.mUnk_10.x -= 0x400;
            }
            if (param_2->mUnk_000.mUnk_04.y < param_2->mUnk_0e8->y) {
                param_2->mUnk_000.mUnk_10.y += 0x400;
            } else if (param_2->mUnk_000.mUnk_04.y > param_2->mUnk_0e8->y) {
                param_2->mUnk_000.mUnk_10.y -= 0x400;
            }
            if (param_2->mUnk_000.mUnk_04.z < param_2->mUnk_0e8->z) {
                param_2->mUnk_000.mUnk_10.z += 0x400;
            } else if (param_2->mUnk_000.mUnk_04.z > param_2->mUnk_0e8->z) {
                param_2->mUnk_000.mUnk_10.z -= 0x400;
            }
            func_02148504(&param_2->mUnk_000.mUnk_04, &param_2->mUnk_000.mUnk_10, &param_2->mUnk_000.mUnk_04);
            if (param_2->mUnk_0ac-- <= 0) {
                param_2->mUnk_0ac = 0;
                n = param_2->mUnk_0a0 - 1;
                if (n <= 0) {
                    n = 0;
                }
                param_2->mUnk_0a0 = n;
                if (param_2->mUnk_0a0 < 1) {
                    param_2->mUnk_0f8 = 7;
                    param_2->mUnk_0b0 = 0x1000;
                    param_2->mUnk_0a0 = 0;
                    param_2->mUnk_0e8 = 0;
                    param_2->mUnk_000.mUnk_02 |= data_ov001_021a6574;
                }
            }
            break;
        case 7:
            if (param_2->mUnk_0e8 != 0) {
                n = param_2->mUnk_0a0 + 2;
                if (n >= 31) {
                    n = 31;
                }
                param_2->mUnk_0a0 = n;
            } else {
                n = param_2->mUnk_0a0 - 2;
                if (n <= 0) {
                    n = 0;
                }
                param_2->mUnk_0a0 = n;
            }
            if (param_2->mUnk_0a0 != 0 && param_2->mUnk_0e8 != 0) {
                func_ov001_02182eb8(param_2, 1);
                param_2->mUnk_000.mUnk_10.y -= 0x14;
                func_02148504(&param_2->mUnk_0ec, &param_2->mUnk_000.mUnk_10, &param_2->mUnk_0ec);
                func_02148504(&param_2->mUnk_0ec, param_2->mUnk_0e8, &param_2->mUnk_000.mUnk_04);
                if ((s64) ((const Vec3 *) &param_2->mUnk_0ec)->x * ((const Vec3 *) &param_2->mUnk_0ec)->x +
                        (s64) ((const Vec3 *) &param_2->mUnk_0ec)->z * ((const Vec3 *) &param_2->mUnk_0ec)->z >=
                    0x190000000LL) {
                    param_2->mUnk_000.mUnk_10.x = ((s64) param_2->mUnk_0ec.x * -0x14) >> 12;
                    param_2->mUnk_000.mUnk_10.z = ((s64) param_2->mUnk_0ec.z * -0x14) >> 12;
                }
                if (param_2->mUnk_0ec.y < -0xa000) {
                    param_2->mUnk_000.mUnk_10.y = 0x4cd;
                }
            }
            break;
        case 9:
            break;
    }
}
