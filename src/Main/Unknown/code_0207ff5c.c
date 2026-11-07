#include "Main/Unknown/code_0207ff5c.h"
#include "Main/Unknown/code_02039774.h"
#include "code_02147cd8.h"

// Steps the cursor to the first next link without a choice; returns the length of the new direction.
u32 AdvancePointLinkCursorToFirstNext(u32 cursor) {
    u32 value0 = cursor;
    u32 value1;
    u32 directionAddress;
    u32 cursorAddress;
    cursorAddress = value0;
    value0 = *(const u32 *) ((cursorAddress) + (0));
    directionAddress = (cursorAddress) + (8u);
    *(u32 *) ((cursorAddress) + (4)) = value0;
    value0 = *(const u32 *) ((cursorAddress) + (0));
    value0 = *(const u32 *) ((value0) + (0));
    *(u32 *) ((cursorAddress) + (0)) = value0;
    value0 = *(const u32 *) ((cursorAddress) + (0));
    value1 = *(const u32 *) ((cursorAddress) + (4));
    value0 = *(const u32 *) ((value0) + (24));
    value1 = *(const u32 *) ((value1) + (24));
    VEC_Subtract((const Vec3 *) value0, (const Vec3 *) value1, (Vec3 *) directionAddress);
    value0 = (cursorAddress) + (8u);
    value1 = value0;
    value0 = Vec3NormalizeAndGetLengthUnchecked((const Vec3 *) value0, (Vec3 *) value1);
    return value0;
}
