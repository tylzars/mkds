#include "01/code_021843b0.h"
#include "01/code_02188950.h"
#include "01/code_02187098.h"
#include "01/code_02188000.h"
#include "01/code_02188da4.h"
#include "01/code_02188158.h"
#include "01/code_021874c4.h"
#include "01/code_02184000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020b502c.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02073000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02109000.h"

void func_ov001_021843b0(Unk02188950 *param_1, Unk0206bcb0 *param_2) {
    Vec3 vec1;
    Vec3 vec2;
    Vec3 vec3;

    if ((func_0207a974(param_2->mUnk_74)->mUnk_48 & 0x20) && param_2->mUnk_238 > 0) {
        if (func_ov001_021871f8(param_1, 8)) {
            if (param_1->mUnk_0a0->mUnk_1a8 > 0 || param_1->mUnk_0a0->mUnk_1ac > 0) {
                vec1.x =
                    (s32) (((s64) -param_1->mUnk_0a0->mUnk_1ac * data_0215d4b4[((u16) param_1->mUnk_1a8 >> 4) * 2]) >>
                           12);
                vec1.y = param_1->mUnk_0a0->mUnk_1a8;
                vec1.z = (s32) (((s64) -param_1->mUnk_0a0->mUnk_1ac *
                                 data_0215d4b4[((u16) param_1->mUnk_1a8 >> 4) * 2 + 1]) >>
                                12);
                func_ov001_02187218(param_1, 7, 0);
                func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_1a0), (s32) (param_1->mUnk_0a0->mUnk_1a4));
                func_ov001_02188a8c(param_1, param_1->mUnk_0a0->mUnk_1b0, 0x270f000);
                func_ov001_02188950(param_1, &vec1);
                func_ov001_02188dcc(param_1, func_ov001_02184d70);
                func_ov001_02188cec(param_1, 0);
            }
            func_021484d0(&param_1->mUnk_000.mUnk_04, &param_2->mUnk_1b8, &vec2);
            if ((s64) vec2.x * vec2.x + (s64) vec2.y * vec2.y + (s64) vec2.z * vec2.z >= 0x10) {
                func_02039860(&vec2, &vec2);
            }
            func_02147fd8(param_2->mUnk_1d0, &vec2, &param_2->mUnk_1b8, &vec2);
            if (param_1->mUnk_000.mUnk_00 == 0x1f5) {
                param_1->mUnk_000.mUnk_78 |= data_ov001_021a657c;
                func_02109060(&param_1->mUnk_000.mUnk_94->mUnk_00, 0x214);
                func_020d2774(&param_1->mUnk_000, (u32) (0x211));
                func_0208b7bc(0x3e9, &vec2);
                func_0208b7bc(0x3e8, &vec2);
                func_0208b7bc(0x3ea, &vec2);
                func_ov001_02187518(param_1, 0x99a, 0, 0x75c, 0x3f3, 0);
                func_ov001_02187518(param_1, -0x99a, 0, 0x75c, 0x3f3, 0);
            } else if (param_1->mUnk_000.mUnk_00 == 0x1f6) {
                param_1->mUnk_000.mUnk_78 |= data_ov001_021a657c;
                func_02109060(&param_1->mUnk_000.mUnk_94->mUnk_00, 0x245);
                func_020d2774(&param_1->mUnk_000, (u32) (0x23f));
                func_0208b7bc(0x3fa, &vec2);
                func_0208b7bc(0x3fb, &vec2);
                func_0208b7bc(0x3fc, &vec2);
                func_ov001_02187518(param_1, -0x11ec, 0, 0x1800, 0x445, 0);
                func_ov001_02187518(param_1, 0x11ec, 0, 0x1800, 0x445, 0);
            }
            param_1->mUnk_000.mUnk_10.x =
                (s32) (((s64) param_1->mUnk_0a0->mUnk_1b8 * data_0215d4b4[((u16) param_1->mUnk_1a8 >> 4) * 2]) >> 12);
            param_1->mUnk_000.mUnk_10.y = 0;
            param_1->mUnk_000.mUnk_10.z =
                (s32) (((s64) param_1->mUnk_0a0->mUnk_1b8 * data_0215d4b4[((u16) param_1->mUnk_1a8 >> 4) * 2 + 1]) >>
                       12);
            param_1->mUnk_000.mUnk_04.x -= param_1->mUnk_000.mUnk_10.x;
            param_1->mUnk_000.mUnk_04.y -= param_1->mUnk_000.mUnk_10.y;
            param_1->mUnk_000.mUnk_04.z -= param_1->mUnk_000.mUnk_10.z;
        }
    } else if (func_ov001_021871f8(param_1, 7)) {
        if (param_1->mUnk_0a0->mUnk_18c > 0 || param_1->mUnk_0a0->mUnk_190 > 0) {
            vec3.x =
                (s32) (((s64) -param_1->mUnk_0a0->mUnk_190 * data_0215d4b4[((u16) param_1->mUnk_1a8 >> 4) * 2]) >> 12);
            vec3.y = param_1->mUnk_0a0->mUnk_18c;
            vec3.z =
                (s32) (((s64) -param_1->mUnk_0a0->mUnk_190 * data_0215d4b4[((u16) param_1->mUnk_1a8 >> 4) * 2 + 1]) >>
                       12);
            func_ov001_02187218(param_1, 7, 0);
            func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_184), (s32) (param_1->mUnk_0a0->mUnk_188));
            func_ov001_02188a8c(param_1, param_1->mUnk_0a0->mUnk_194, 0x270f000);
            func_ov001_02188950(param_1, &vec3);
            func_ov001_02188dcc(param_1, func_ov001_02184cc8);
            func_ov001_02188cec(param_1, 0);
        }
        param_1->mUnk_000.mUnk_10.x =
            (s32) (((s64) param_1->mUnk_0a0->mUnk_19c * data_0215d4b4[((u16) param_1->mUnk_1a8 >> 4) * 2]) >> 12);
        param_1->mUnk_000.mUnk_10.y = 0;
        param_1->mUnk_000.mUnk_10.z =
            (s32) (((s64) param_1->mUnk_0a0->mUnk_19c * data_0215d4b4[((u16) param_1->mUnk_1a8 >> 4) * 2 + 1]) >> 12);
        param_1->mUnk_000.mUnk_04.x -= param_1->mUnk_000.mUnk_10.x;
        param_1->mUnk_000.mUnk_04.y -= param_1->mUnk_000.mUnk_10.y;
        param_1->mUnk_000.mUnk_04.z -= param_1->mUnk_000.mUnk_10.z;
        param_1->mUnk_000.mUnk_78 |= data_ov001_021a657c;
        func_020d2774(&param_1->mUnk_000, (u32) (0x213));
    }
    func_ov001_02188200(param_1, func_ov001_02184874);
    param_1->mUnk_2d8 = 0xd;
    func_02073fb0(param_1->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
}
