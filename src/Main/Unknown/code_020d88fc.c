#include "Main/Unknown/code_020d88fc.h"

Vec3 *GetGroupFollowerSegmentUp(GroupFollower *follower) {
    u32 value0 = (u32) follower;
    u32 segmentIndex;
    u32 value2;
    value2 = *(const u32 *) ((value0) + (0));
    segmentIndex = *(const u32 *) ((value0) + (12));
    value2 = *(const u32 *) ((value2) + (0));
    value0 = 0x54u;
    value0 = (segmentIndex) * (value0) + (value2);
    value0 = (value0) + (0x48u);
    return (Vec3 *) value0;
}
