#include "Main/Unknown/code_020646f0.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "code_02147cd8.h"

void func_020646f0(Kart *a, s32 b) {
    Unk02012f58 *m;
    CourseMap *c;
    Vec3 d;
    Vec3 e;
    Vec3 f;
    Vec3 g;
    Vec3 h;
    Unk0206bcb0_590_08 *i;
    s16 j;
    s16 k;
    s16 l;
    Vec3 *n;

    if (b == 0) {
        GetCourseMapKartStartPlacement(&a->mPos, &d, a->mIndex);
        if (data_021759c0->mUnk_00c == 5) {
            a->mPos = data_0216549c[a->mIndex];
        }
    } else {
        c = gCourseMap;
        if (c->mUnk_3c != NULL) {
            n = &a->mPos;
            if (n != NULL) {
                *n = c->mUnk_3c->mUnk_00;
            }
            d = c->mUnk_3c->mUnk_0c;
        }
    }
    if ((a->mUnk_7c & 0x600) != 0) {
        j = a->mPos.x >> 10;
        k = a->mPos.y >> 10;
        l = a->mPos.z >> 10;
        a->mPos.x = j << 10;
        a->mPos.y = k << 10;
        a->mPos.z = l << 10;
    }
    g = a->mPos;
    g.y = g.y + 0x1000;
    a->mPos.y = a->mPos.y - 0x1400;
    if (func_01ffdee4(&a->mPos, (u32 *) &g, (u32) &a->mUnk_50, 0x5000, 1, -2, &e, &f, NULL, NULL, NULL, NULL, NULL,
                      NULL) != 0) {
        h.x = (s64) f.x * 0x5000 >> 12;
        h.y = (s64) f.y * 0x5000 >> 12;
        h.z = (s64) f.z * 0x5000 >> 12;
        Vec3Sub(&e, &h, &e);
        Vec3Add(&a->mPos, &e, &a->mPos);
    }
    a->mPos.y = a->mPos.y - 0x1000;
    a->mHeadingAngle = (u32) (d.y * 0xb6) >> 12;
    QuaternionFromAxisAngle(&data_02154a3c, a->mHeadingAngle, &a->mUnk_e0_m);
    a->mUnk_110_q = a->mUnk_e0_m;
    func_01ffcd84(&a->mUnk_120, &a->mUnk_110_q);
    a->mUnk_150_m = a->mUnk_120_m;
    a->mPrevPos = a->mPos;
    a->mUnk_98 = a->mPrevPos;
    a->mUnk_174.x = a->mUnk_98.x;
    a->mUnk_174.y = a->mUnk_98.y;
    a->mUnk_174.z = a->mUnk_98.z;
    m = &a->mUnk_120_m;
    a->mUnk_278.x = m->mUnk_00[2].x;
    a->mUnk_278.y = m->mUnk_00[2].y;
    a->mUnk_278.z = m->mUnk_00[2].z;
    a->mUnk_50 = a->mUnk_278;
    a->mUnk_1b4 = &a->mUnk_150_m;
    i = a->mKartModelsEntry->mUnk_008;
    if (i == NULL) {
        return;
    }
    if (i->mUnk_18 != 0) {
        i->mUnk_0c = a->mKartModelsEntry->mUnk_02c;
    }
}
