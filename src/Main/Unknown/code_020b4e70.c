#include "Main/Unknown/code_020b4e70.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020c0d9c.h"

void func_020b4f64(Vec3 *v1, const Vec3 *a, const Vec3 *b) {
    Vec3 t;
    s32 s;

    if (a->x == b->x && a->z == b->z) {
        *v1 = *a;
        return;
    }
    s = MulFixed12NoRound(func_020c0d9c(), 0x3000);
    t.x = a->x + MulFixed12NoRound(s, b->x - a->x);
    t.y = a->y + MulFixed12NoRound(s, b->y - a->y);
    t.z = a->z + MulFixed12NoRound(s, b->z - a->z);
    *v1 = t;
}

s32 func_020b4e70(const Vec3 *a) {
    BOOL r = TRUE;

    switch (func_020b4e5c()) {
        case COURSE_ID_CLOCK:
            if (a->x >= -0x377000 && a->x <= 0x377000 && a->z >= -0x377000 && a->z <= 0x377000 && a->y < 0x2be800) {
                r = FALSE;
            } else {
                r = TRUE;
            }
            break;
        case COURSE_ID_AIRSHIP:
            if (a->x >= -0x640000 && a->x <= 0x992000 && a->z >= -0x1ce8000 && a->z <= -0x17a2000 && a->y < 0x2e2000) {
                r = FALSE;
            } else {
                r = TRUE;
            }
            break;
    }
    return r;
}
