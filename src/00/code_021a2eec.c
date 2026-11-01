#include "00/code_021a2eec.h"
#include "00/code_0219b9c4.h"
#include "00/code_021a2ccc.h"
#include "00/code_021a2f98.h"
#include "00/code_021a31e8.h"
#include "00/unk_021b5000.h"
#include "code_0200fd1c.h"

void func_ov000_021a2eec(Unk0219887c *a, void *b, s32 c) {
    u8 v1 = func_ov000_0219b9c4(a);
    switch (func_ov000_021a2fb4(v1)) {
        case 0: {
            u16 n = func_ov000_021a31e8(b);
            if (n >= 2 && n <= 4) {
                func_ov000_021a2dfc(v1, b, c);
            }
            break;
        }
        case 1:
            func_ov000_021a2dfc(v1, b, c);
            break;
        case 2:
            func_ov000_021a2d68(v1, b, c);
            break;
        case 3:
            func_ov000_021a2d38(v1, b, c);
            break;
        case 4:
            data_ov000_021b5dd0->mUnk_000[v1].mUnk_1d = 1;
            data_ov000_021b5dd0->mUnk_000[v1].mUnk_10 = 0;
            data_ov000_021b5dd0->mUnk_000[v1].mUnk_18 = 0;
            break;
        default:
            func_0200fd1c();
            break;
    }
}
