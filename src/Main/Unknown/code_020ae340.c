#include "Main/Unknown/code_020ae340.h"
#include "Main/Unknown/code_0203b680.h"
#include "Main/Unknown/code_0203b69c.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/unk_02168000.h"

#pragma optimize_for_size on
#pragma thumb on

u32 func_020ae3a4(s32 a, s32 b) {
    return data_02168024[a * 4 + b];
}

void func_020ae340(u32 a, u8 *b, u8 *c) {
    u32 f;
    s32 n;
    s32 m;
    u8 i;
    u8 j;

    f = (u32) func_02047a28("/missionTable.mtbl");
    n = func_0203b6a4(f);
    m = func_0203b69c(f);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (a == func_0203b680(f, i, j)) {
                *b = i;
                *c = j;
            }
        }
    }
}

#pragma thumb off
