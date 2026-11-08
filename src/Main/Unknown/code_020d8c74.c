#include "Main/Unknown/code_020d8c74.h"
#include "Main/Unknown/code_020d9480.h"

void GetGroupFollowerCurvePosition(GroupFollower *follower, Vec3 *output) {
    u32 value0 = (u32) follower;
    u32 value1 = (u32) output;
    u32 outputAddress;
    u32 segments;
    u32 followerAddress;
    followerAddress = value0;
    value0 = *(const u32 *) ((followerAddress) + (0));
    outputAddress = value1;
    segments = *(const u32 *) ((value0) + (0));
    value1 = *(const u32 *) ((followerAddress) + (12));
    value0 = 0x54u;
    value0 = (value1) * (value0) + (segments);
    value1 = *(const u32 *) ((followerAddress) + (20));
    GetCurvePoint(value0, value1, outputAddress);
}
