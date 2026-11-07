#include "Main/Unknown/code_0205afa8.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203c240.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_0219b580.h"
#include "Main/Unknown/code_0203c5f8.h"

s32 func_0205afa8(void) {
    u32 c;
    s32 b;
    u16 a;
    s32 d;
    s32 e;

    a = data_0217aa18->mUnk_06[func_ov000_0219bb50()];
    b = GetKartStartRank(a);
    c = GetKartFinishTimeMs(a) & 0x7ffff;
    if (IsKartEnded(a) != 0 && gRaceProgress->mUnk_000[a].mStatus != 1 && data_0217aa14->mUnk_72c == FALSE) {
        c = 0x7ffff;
    }
    if (c == 0) {
        c = b - 1;
    }
    if (gRaceProgress->mUnk_000[a].mStatus == 1) {
        d = 0;
    } else {
        d = 6 - GetKartHighestLap(a);
    }
    e = (d << 19) & 0x380000;
    if (IsKartEnded(a) == 0 && data_0217aa14->mUnk_72c == FALSE) {
        d = 1;
    } else {
        d = 0;
    }
    return c | (((d << 22) & 0x400000) | e);
}
