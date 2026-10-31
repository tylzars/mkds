#include "01/code_02184874.h"
#include "01/code_02184000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02109000.h"
#include "code_02147cd8.h"

void func_ov001_02184874(Unk02188950 *param_1, Unk0206bcb0 *param_2) {
    s32 scale;

    if ((func_0207a974(param_2->mUnk_74)->mUnk_48 & 0x20) && param_2->mUnk_238 > 0) {
        if (func_ov001_021871f8(param_1, 8)) {
            if (param_1->mUnk_0a0->mUnk_1dc > 0 || param_1->mUnk_0a0->mUnk_1e0 > 0) {
                Vec3 a = {0, 0, 0};
                a.x = param_2->mUnk_a4.x;
                a.z = param_2->mUnk_a4.z;
                if ((s64)a.z * a.z + ((s64)a.x * a.x + (s64)a.y * a.y) >= 0x10) {
                    func_02039860(&a, &a);
                }
                scale = param_1->mUnk_0a0->mUnk_1e0;
                a.x = (s32)(((s64)a.x * scale) >> 12);
                a.y = (s32)(((s64)a.y * scale) >> 12);
                a.z = (s32)(((s64)a.z * scale) >> 12);
                a.y = param_1->mUnk_0a0->mUnk_1dc;
                func_ov001_02187218(param_1, 7, 0);
                func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_1d4), (s32) (param_1->mUnk_0a0->mUnk_1d8));
                func_ov001_02188a8c(param_1, param_1->mUnk_0a0->mUnk_1e4, 0x270f000);
                func_ov001_02188950(param_1, &a);
                func_ov001_02188dcc(param_1, func_ov001_02184d70);
                func_ov001_02188cec(param_1, 0);
            }
            {
                Vec3 b;

                func_021484d0(&param_1->mUnk_000.mUnk_04, &param_2->mUnk_1b8, &b);
                if ((s64)b.z * b.z + ((s64)b.x * b.x + (s64)b.y * b.y) >= 0x10) {
                    func_02039860(&b, &b);
                }
                func_02147fd8(param_2->mUnk_1d0, &b, &param_2->mUnk_1b8, &b);
                if (param_1->mUnk_000.mUnk_00 == 0x1f5) {
                    param_1->mUnk_000.mUnk_78 |= data_ov001_021a657c;
                    func_02109060(&param_1->mUnk_000.mUnk_94->mUnk_00, 0x214);
                    func_020d2774(&param_1->mUnk_000, (u32) (0x211));
                    func_0208b7bc(0x3e9, &b);
                    func_0208b7bc(0x3e8, &b);
                    func_0208b7bc(0x3ea, &b);
                    func_ov001_02187518(param_1, 0x99a, 0, 0x75c, 0x3f3, 0);
                    func_ov001_02187518(param_1, -0x99a, 0, 0x75c, 0x3f3, 0);
                } else if (param_1->mUnk_000.mUnk_00 == 0x1f6) {
                    param_1->mUnk_000.mUnk_78 |= data_ov001_021a657c;
                    func_02109060(&param_1->mUnk_000.mUnk_94->mUnk_00, 0x245);
                    func_020d2774(&param_1->mUnk_000, (u32) (0x23f));
                    func_0208b7bc(0x3fa, &b);
                    func_0208b7bc(0x3fb, &b);
                    func_0208b7bc(0x3fc, &b);
                    func_ov001_02187518(param_1, -0x11ec, 0, 0x1800, 0x445, 0);
                    func_ov001_02187518(param_1, 0x11ec, 0, 0x1800, 0x445, 0);
                }
            }
        }
    } else if (func_ov001_021871f8(param_1, 7)) {
        if (param_1->mUnk_0a0->mUnk_1c4 > 0 || param_1->mUnk_0a0->mUnk_1c8 > 0) {
            Vec3 c = {0, 0, 0};
            c.x = param_2->mUnk_a4.x;
            c.z = param_2->mUnk_a4.z;
            if ((s64)c.z * c.z + ((s64)c.x * c.x + (s64)c.y * c.y) >= 0x10) {
                func_02039860(&c, &c);
            }
            scale = param_1->mUnk_0a0->mUnk_1c8;
            c.x = (s32)(((s64)c.x * scale) >> 12);
            c.y = (s32)(((s64)c.y * scale) >> 12);
            c.z = (s32)(((s64)c.z * scale) >> 12);
            c.y = param_1->mUnk_0a0->mUnk_1c4;
            func_ov001_02187218(param_1, 7, 0);
            func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_1bc), (s32) (param_1->mUnk_0a0->mUnk_1c0));
            func_ov001_02188a8c(param_1, param_1->mUnk_0a0->mUnk_1cc, 0x270f000);
            func_ov001_02188950(param_1, &c);
            func_ov001_02188dcc(param_1, 0);
            func_ov001_02188cec(param_1, 0);
        }
    }
    func_ov001_02188200(param_1, func_ov001_02184874);
    param_1->mUnk_2d8 = 13;
}
