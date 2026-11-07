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

void func_020b4f64(Vec3 *result, const Vec3 *startPoint, const Vec3 *endPoint) {
    Vec3 point;
    s32 factor;

    if (startPoint->x == endPoint->x && startPoint->z == endPoint->z) {
        *result = *startPoint;
        return;
    }
    factor = MulFixed12NoRound(func_020c0d9c(), 0x3000);
    point.x = startPoint->x + MulFixed12NoRound(factor, endPoint->x - startPoint->x);
    point.y = startPoint->y + MulFixed12NoRound(factor, endPoint->y - startPoint->y);
    point.z = startPoint->z + MulFixed12NoRound(factor, endPoint->z - startPoint->z);
    *result = point;
}

s32 func_020b4e70(const Vec3 *position) {
    BOOL r = TRUE;

    switch (func_020b4e5c()) {
        case COURSE_ID_CLOCK:
            if (position->x >= -0x377000 && position->x <= 0x377000 && position->z >= -0x377000 &&
                position->z <= 0x377000 && position->y < 0x2be800) {
                r = FALSE;
            } else {
                r = TRUE;
            }
            break;
        case COURSE_ID_AIRSHIP:
            if (position->x >= -0x640000 && position->x <= 0x992000 && position->z >= -0x1ce8000 &&
                position->z <= -0x17a2000 && position->y < 0x2e2000) {
                r = FALSE;
            } else {
                r = TRUE;
            }
            break;
    }
    return r;
}
