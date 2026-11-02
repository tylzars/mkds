#include "Main/Unknown/code_020b4e70.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020c0d9c.h"

void func_020b4f64(Vec3 *v1, const Vec3 *a, const Vec3 *b) {
    Vec3 t;
    s32 s;

    if (a->x == b->x && a->z == b->z) {
        *v1 = *a;
        return;
    }
    s = func_020b502c(func_020c0d9c(), 0x3000);
    t.x = a->x + func_020b502c(s, b->x - a->x);
    t.y = a->y + func_020b502c(s, b->y - a->y);
    t.z = a->z + func_020b502c(s, b->z - a->z);
    *v1 = t;
}

s32 func_020b4e70(const Vec3 *a) {
    BOOL r = TRUE;

    switch (func_020b4e5c()) {
        case 0x11:
            if (a->x >= -0x377000 && a->x <= 0x377000 && a->z >= -0x377000 && a->z <= 0x377000 && a->y < 0x2be800) {
                r = FALSE;
            } else {
                r = TRUE;
            }
            break;
        case 0x13:
            if (a->x >= -0x640000 && a->x <= 0x992000 && a->z >= -0x1ce8000 && a->z <= -0x17a2000 && a->y < 0x2e2000) {
                r = FALSE;
            } else {
                r = TRUE;
            }
            break;
    }
    return r;
}
