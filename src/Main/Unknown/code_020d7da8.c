#include "Main/Unknown/code_020d7da8.h"
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
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020d9000.h"
#include "Main/Unknown/code_020d7db4.h"

#pragma thumb on
void InitGroupFollower(GroupFollower *follower, CourseMapRow *row, s32 speed) {
    GroupFollower *followerCopy = follower;
    u32 value1 = (u32) row;
    u32 speedCopy = speed;
    u32 unused;
    value1 = *(const u16 *) ((value1) + 38u);
    InitGroupFollowerForGroup(followerCopy, value1, speedCopy);
}
#pragma thumb off
