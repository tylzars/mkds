#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_020a0028.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_0209b000.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02146cbc.h"

void CreateAirship(void *a) {
    gAirship = func_0209be84(a, gAirshipNsbmdName);
    func_0209b940(gAirship, 0x3f);
}

void func_020a018c(void *a, Unk020a018c *p) {
    s32 v;
    s32 q[9];
    Vec3 w;

    v = 0x1e;
    func_01ff9048(0x14, &v, 1);
    w.y = (p->mUnk_a0 + p->mUnk_ac) >> 4;
    w.x = 0;
    w.z = 0;
    func_01ff9048(0x1c, &w, 3);
    p->mUnk_00.mMatrix.mUnk_00[3].x = p->mUnk_00.mPos.x >> 4;
    p->mUnk_00.mMatrix.mUnk_00[3].y = p->mUnk_00.mPos.y >> 4;
    p->mUnk_00.mMatrix.mUnk_00[3].z = p->mUnk_00.mPos.z >> 4;
    func_01ff9048(0x19, &p->mUnk_00.mMatrix, 0xc);
    if (p->mUnk_00.mUnk_7e != 0) {
        func_02146d44(q, data_0215d4b4[((p->mUnk_00.mUnk_7e >> 4) << 1)],
                      data_0215d4b4[((p->mUnk_00.mUnk_7e >> 4) << 1) + 1]);
        func_01ff9048(0x1a, q, 9);
    }
    func_01ff9048(0x1b, &p->mUnk_00.mUnk_1c, 3);
    func_0209bb2c(a, gAirship, p);
}

void func_020a0064(Unk020a0064 *p) {
    s32 i;
    Unk020a018c *o;
    BOOL z;
    s32 v;

    if (p == NULL) {
        return;
    }
    z = FALSE;
    for (i = 0; i < p->mUnk_04 && (o = p->mUnk_00[i]) != NULL; i++) {
        func_020d7da8(&o->mUnk_c8, o->mUnk_00.mCourseMapRow, z);
        o->mUnk_a4 = (o->mUnk_00.mCourseMapRow->mUnk_28 * 0x5000L) / 100;
        v = o->mUnk_a4;
        o->mUnk_c8.mUnk_04 = v;
        o->mUnk_c8.mUnk_10 = ((s64) v * o->mUnk_c8.mUnk_00->mUnk_00[o->mUnk_c8.mUnk_0c].mUnk_34) >> 12;
        o->mUnk_a0 = o->mUnk_00.mPos.y;
        func_020d8bf8(&o->mUnk_c8, &o->mUnk_00.mPos, &o->mUnk_00.mUnk_10);
        o->mUnk_a0 = o->mUnk_a0 - o->mUnk_00.mPos.y;
        o->mUnk_a8 = 0;
        o->mUnk_b4 = 0;
        o->mUnk_b8 = 0x50000;
        o->mUnk_bc = 0;
        o->mUnk_c0 = 0xb6;
        o->mUnk_c4 = 0;
        if (o->mUnk_00.mCourseMapRow->mUnk_2a != 0) {
            o->mUnk_ec = 0;
        } else {
            o->mUnk_ec = 2;
        }
    }
}

s32 func_020a0044(s32 a) {
    return data_0215d4b4[((a >> 4) << 1) + 1];
}

s32 func_020a0028(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}
