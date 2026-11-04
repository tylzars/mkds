#include "Main/Unknown/code_020808d4.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/unk_02155000.h"
#include "code_02147cd8.h"

void func_02080ac0(Unk0208001c *p) {
    if (p->mUnk_14 == NULL) {
        p->mUnk_14 = p->mUnk_04;
        p->mUnk_18 = 0;
    }
}

void func_02080908(Unk0208001c *p, Vec3 *a, Vec3 *b, u16 c) {
    Unk02175620_bc *r = NULL;
    u16 i;
    u16 j;
    s32 k;
    s32 m;
    s32 d;
    Unk02175620_bc *v1 = gCourseMap->mUnk_bc;
    Unk02175620_bc *v2[3] = {0, 0, 0};
    s32 v3[3];
    Vec3 v;
    Vec3 w;

    v3[0] = v3[1] = v3[2] = 0xc8000;
    m = -0x1000;
    for (i = 0; i < gCourseMap->mUnk_88; i++) {
        Vec3Sub(&gCourseMap->mUnk_84[i].mUnk_00, a, &v);
        d = Vec3Length(&v);
        if (d < 0xc8000) {
            for (k = 0; k < 3; k++) {
                if (d < v3[k]) {
                    v3[k] = d;
                    v2[k] = &v1[i];
                    break;
                }
            }
        }
    }
    for (j = 0; j < 3; j++) {
        if (v2[j] != NULL) {
            Vec3Sub(v2[j]->mUnk_20, a, &w);
            if ((s64) w.x * w.x + (s64) w.y * w.y + (s64) w.z * w.z >= 0x10) {
                func_02039860(&w, &w);
            }
            d = func_02039828(&w, b);
            if (d >= m) {
                r = v2[j];
                m = d;
            }
        }
    }
    p->mUnk_00 = r;
    p->mUnk_04 = r;
    p->mUnk_08 = data_021557ec;
    p->mUnk_14 = NULL;
    p->mUnk_18 = 0;
}

void func_020808d4(Unk0208001c *p, Unk02175620_bc *a) {
    p->mUnk_04 = a;
    p->mUnk_00 = p->mUnk_04;
    p->mUnk_08 = data_021557ec;
    p->mUnk_14 = NULL;
    p->mUnk_18 = 0;
}
