#include "00/code_0218f848.h"
#include "00/code_0218e49c.h"
#include "00/code_0218e8c4.h"
#include "00/code_0218f15c.h"
#include "00/code_0218f808.h"
#include "00/code_021948f8.h"
#include "00/code_021967b4.h"
#include "00/code_021a3668.h"
#include "00/code_021a3690.h"
#include "00/unk_021b23b0.h"
#include "code_021384cc.h"
#include "code_02134d30.h"

u32 func_ov000_0218f848(Unk0218f960 *a, s32 b, s32 c) {
    Unk0218f960 p;
    u32 r;
    s32 i;
    a->mUnk_00 = 0;
    p.mUnk_00 = func_ov000_021a3690(0x490);
    if (p.mUnk_00 == 0) {
        return 1;
    }
    memset(p.mUnk_00, 0, 0x490);
    p.mUnk_00->mUnk_000[0] = 0;
    p.mUnk_00->mUnk_418 = 0;
    p.mUnk_00->mUnk_100 = 1;
    p.mUnk_00->mUnk_104 = 0;
    p.mUnk_00->mUnk_108 = 0;
    p.mUnk_00->mUnk_10c = 0;
    p.mUnk_00->mUnk_46c = b;
    p.mUnk_00->mUnk_470 = c;
    if (func_ov000_02194af4(&p) == 0) {
        func_ov000_021a3668(p.mUnk_00);
        p.mUnk_00 = 0;
        return 1;
    }
    p.mUnk_00->mUnk_420 = 0;
    for (i = 0; i < 6; i++) {
        p.mUnk_00->mUnk_1a4[i].mUnk_00 = 0;
        p.mUnk_00->mUnk_1a4[i].mUnk_04 = 0;
    }
    p.mUnk_00->mUnk_460 = 0;
    func_ov000_0219690c(&p, data_ov000_021b2718);
    r = func_ov000_0218f654(&p);
    if (r != 0) {
        func_ov000_0218f808(&p);
        return r;
    }
    func_ov000_0218e8b8();
    func_021384cc(func_ov000_0218e8c4());
    a->mUnk_00 = p.mUnk_00;
    return 0;
}
