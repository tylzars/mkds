#include "00/code_0218d340.h"
#include "00/code_0218b000.h"
#include "00/code_0218d430.h"
#include "00/code_0218d488.h"
#include "00/code_0218d000.h"
#include "00/code_0218da04.h"
#include "00/code_02193818.h"
#include "00/unk_021b2000.h"
#include "code_0214177c.h"

s32 func_ov000_0218d3d8(u32 *a, u32 *b) {
    u8 *x;
    u8 *y;
    s32 r;
    x = func_ov000_0218b30c((Unk0218af28 *) *a, (const u8 *) data_ov000_021b4d24->mUnk_498, data_ov000_021b2260);
    y = func_ov000_0218b30c((Unk0218af28 *) *b, (const u8 *) data_ov000_021b4d24->mUnk_498, data_ov000_021b2260);
    r = func_02142368(x, y);
    if (data_ov000_021b4d24->mUnk_49c == 0) {
        r = -r;
    }
    return r;
}

void func_ov000_0218d374(Unk021b4d24 *p, s32 a, u32 b, u32 c) {
    s32 (*f)(u32 *, u32 *);
    switch (c) {
        case 0:
            f = func_ov000_0218d528;
            break;
        case 1:
            f = func_ov000_0218d488;
            break;
        case 2:
            f = func_ov000_0218d430;
            break;
        case 3:
            f = func_ov000_0218d3d8;
            break;
        default:
            f = func_ov000_0218d3d8;
            break;
    }
    p->mUnk_498 = b;
    p->mUnk_49c = a;
    data_ov000_021b4d24 = p;
    func_ov000_0218da04((u32) p->mUnk_004, (u32) f);
}

void func_ov000_0218d340(Unk021b4d24 *p, u32 a) {
    func_ov000_0218dbc0(p->mUnk_004, &a);
    p->mUnk_488(p, 0, a, p->mUnk_494);
}
