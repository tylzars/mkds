#include "01/code_02184874.h"
#include "01/code_02184000.h"
#include "01/code_02184cc8.h"
#include "01/code_02185ef4.h"
#include "01/code_02188158.h"
#include "01/code_02188cd8.h"
#include "01/code_02188da4.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_02109054.h"
#include "code_02147cd8.h"

void func_ov001_02184874(Unk02188950 *d, Unk0206bcb0 *e) {
    s32 scale;

    if ((GetKart(e->mIndex)->mUnk_48 & 0x20) && e->mUnk_238 > 0) {
        if (func_ov001_021871f8(d, 8)) {
            if (d->mPrm->mUnk_1dc > 0 || d->mPrm->mUnk_1e0 > 0) {
                Vec3 a = {0, 0, 0};
                a.x = e->mUnk_a4.x;
                a.z = e->mUnk_a4.z;
                if ((s64) a.z * a.z + ((s64) a.x * a.x + (s64) a.y * a.y) >= 0x10) {
                    func_02039860(&a, &a);
                }
                scale = d->mPrm->mUnk_1e0;
                a.x = (s32) (((s64) a.x * scale) >> 12);
                a.y = (s32) (((s64) a.y * scale) >> 12);
                a.z = (s32) (((s64) a.z * scale) >> 12);
                a.y = d->mPrm->mUnk_1dc;
                func_ov001_02187218(d, 7, NULL);
                func_ov001_02188d64(d, (s32) (d->mPrm->mUnk_1d4), (s32) (d->mPrm->mUnk_1d8));
                func_ov001_02188a8c(d, d->mPrm->mUnk_1e4, 0x270f000);
                SetVelocity(d, &a);
                func_ov001_02188dcc(d, func_ov001_02184d70);
                func_ov001_02188cec(d, 0);
            }
            {
                Vec3 b;

                Vec3Sub(&d->mUnk_000.mPos, &e->mUnk_1b8, &b);
                if ((s64) b.z * b.z + ((s64) b.x * b.x + (s64) b.y * b.y) >= 0x10) {
                    func_02039860(&b, &b);
                }
                Vec3AddScaled(e->mUnk_1d0, &b, &e->mUnk_1b8, &b);
                if (d->mUnk_000.mKind == 0x1f5) {
                    d->mUnk_000.mUnk_78 |= data_ov001_021a657c;
                    func_02109060(&d->mUnk_000.mUnk_94->mUnk_00, 0x214);
                    func_020d2774(&d->mUnk_000, (u32) (0x211));
                    func_0208b7bc(0x3e9, &b);
                    func_0208b7bc(0x3e8, &b);
                    func_0208b7bc(0x3ea, &b);
                    func_ov001_02187518(d, 0x99a, 0, 0x75c, 0x3f3, 0);
                    func_ov001_02187518(d, -0x99a, 0, 0x75c, 0x3f3, 0);
                } else if (d->mUnk_000.mKind == 0x1f6) {
                    d->mUnk_000.mUnk_78 |= data_ov001_021a657c;
                    func_02109060(&d->mUnk_000.mUnk_94->mUnk_00, 0x245);
                    func_020d2774(&d->mUnk_000, (u32) (0x23f));
                    func_0208b7bc(0x3fa, &b);
                    func_0208b7bc(0x3fb, &b);
                    func_0208b7bc(0x3fc, &b);
                    func_ov001_02187518(d, -0x11ec, 0, 0x1800, 0x445, 0);
                    func_ov001_02187518(d, 0x11ec, 0, 0x1800, 0x445, 0);
                }
            }
        }
    } else if (func_ov001_021871f8(d, 7)) {
        if (d->mPrm->mUnk_1c4 > 0 || d->mPrm->mUnk_1c8 > 0) {
            Vec3 c = {0, 0, 0};
            c.x = e->mUnk_a4.x;
            c.z = e->mUnk_a4.z;
            if ((s64) c.z * c.z + ((s64) c.x * c.x + (s64) c.y * c.y) >= 0x10) {
                func_02039860(&c, &c);
            }
            scale = d->mPrm->mUnk_1c8;
            c.x = (s32) (((s64) c.x * scale) >> 12);
            c.y = (s32) (((s64) c.y * scale) >> 12);
            c.z = (s32) (((s64) c.z * scale) >> 12);
            c.y = d->mPrm->mUnk_1c4;
            func_ov001_02187218(d, 7, NULL);
            func_ov001_02188d64(d, (s32) (d->mPrm->mUnk_1bc), (s32) (d->mPrm->mUnk_1c0));
            func_ov001_02188a8c(d, d->mPrm->mUnk_1cc, 0x270f000);
            SetVelocity(d, &c);
            func_ov001_02188dcc(d, NULL);
            func_ov001_02188cec(d, 0);
        }
    }
    func_ov001_02188200(d, func_ov001_02184874);
    d->mUnk_2d8 = 13;
}
