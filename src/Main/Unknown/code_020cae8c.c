#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020cb2d4.h"
#include "Main/Unknown/code_020cc000.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_02029000.h"
#include "Main/Unknown/code_02029890.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_0202993c.h"

#pragma thumb on
#pragma optimize_for_size on
void func_020cae8c(void) {
    s32 t[5][2] = {{4, 0}, {0x14, 1}, {8, 3}, {0xe, 2}, {0x12, 4}};
    s32 n;

    n = func_020ccccc();
    data_0217b43c->mUnk_938 = func_020ae488(n);
    if (n >= 10) {
        func_020ccc74(2, t[data_0217b43c->mUnk_930][0]);
        ResetRaceSetupCopy();
        GetRaceSetupCopy()->mMode = t[data_0217b43c->mUnk_930][1];
    }
    func_020cb2d4();
}
#pragma thumb off
