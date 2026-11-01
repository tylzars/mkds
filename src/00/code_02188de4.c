#include "00/code_02188de4.h"
#include "00/code_02188ec0.h"
#include "00/code_0218a64c.h"
#include "code_0214d018.h"

u32 func_ov000_02188de4(struct Unk02188ec0 *v1, u32 a, Unk02188de4 *v2) {
    Unk02188db0 *p;

    p = v1->mUnk_000;
    switch (a) {
        case 2:
            p++;
        case 1:
            p++;
        case 0:
            v2->mUnk_00 = p->mUnk_e6;
            func_0214d1fc(p->mUnk_80, v2->mUnk_02, 0x50);
            break;
        case 5:
            p++;
        case 4:
            p++;
        case 3:
            v2->mUnk_00 = 1;
            func_0214d1fc(p->mUnk_d1, v2->mUnk_02, 0x14);
            v2->mUnk_02[0x14] = 0;
            break;
        case 6:
            v2->mUnk_00 = 2;
            func_ov000_0218a64c(v1->mUnk_470[v1->mUnk_d13].mUnk_0c, v2->mUnk_02);
            break;
        case 7:
            v2->mUnk_00 = 2;
            func_ov000_0218a6ac(v1->mUnk_470[v1->mUnk_d13].mUnk_0c, v2->mUnk_02);
            break;
        case 8:
        case 9:
            break;
    }
    if (v2->mUnk_00 != 0) {
        return 1;
    }
    return 0;
}
