#include "Main/Unknown/code_020b4e0c.h"
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
#include "Main/Unknown/code_020b4e70.h"
#include "Main/Unknown/code_02077bc0.h"

s32 func_020b4e0c(void) {
    s32 r = 1;
    Vec3 v;
    s32 a = func_020b4e5c();

    if (a == 0x11 || a == 0x13) {
        func_0207a91c(&v, GetFollowedKartOrEntryIndex());
        r = func_020b4e70(&v);
    }
    return r;
}
