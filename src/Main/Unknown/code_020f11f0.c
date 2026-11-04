#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020f11f0.h"
#include "Main/Unknown/code_020f1258.h"
#include "Main/Unknown/unk_021759c0.h"

u32 func_020f11f0(u32 a, u32 b) {
    u16 v1;
    int v2;
    v1 = func_02061f90();
    if (((u32) v1 < data_021759c0->mKartCount) && (v2 = func_020f1258(a, v1, 0, b), v2 != 0)) {
        return 1;
    }
    return 0;
}
