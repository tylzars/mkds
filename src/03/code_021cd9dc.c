#include "03/code_021cd9dc.h"
#include "03/code_021cd2cc.h"
#include "03/code_021d3254.h"
#include "code_0214d018.h"

void func_ov003_021cd9dc(const u8 *a) {
    s32 i;
    s32 n;
    u8 *p;
    func_0214d168(data_ov003_021da270->mUnk_400.mUnk_00.mUnk_80[0], 0, 0x10);
    n = func_ov003_021d3254(a, 0x20);
    switch (n) {
        case 0:
        case 10:
        case 26:
        case 32:
            data_ov003_021da270->mUnk_400.mUnk_00.mUnk_e6_2 = 0;
            p = data_ov003_021da270->mUnk_400.mUnk_00.mUnk_80[0];
            i = 0;
            for (; i < n;) {
                *p = (func_ov003_021cd2cc(a[i]) << 4) + func_ov003_021cd2cc(a[i + 1]);
                i += 2;
                p++;
            }
            break;
        default:
            data_ov003_021da270->mUnk_400.mUnk_00.mUnk_e6_2 = 1;
            func_0214d1fc(a, data_ov003_021da270->mUnk_400.mUnk_00.mUnk_80[0], 0x10);
            break;
    }
    switch (n) {
        case 0:
            data_ov003_021da270->mUnk_400.mUnk_00.mUnk_e6_0 = 0;
            break;
        case 5:
        case 10:
            data_ov003_021da270->mUnk_400.mUnk_00.mUnk_e6_0 = 1;
            break;
        case 13:
        case 26:
            data_ov003_021da270->mUnk_400.mUnk_00.mUnk_e6_0 = 2;
            break;
        default:
            data_ov003_021da270->mUnk_400.mUnk_00.mUnk_e6_0 = 3;
            break;
    }
}
