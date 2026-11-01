#include "00/code_02187274.h"
#include "00/code_02186d7c.h"
#include "00/unk_021b1000.h"
#include "code_0200d118.h"
#include "code_0200dc3c.h"
#include "code_0200e904.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "code_0214d018.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/code_0200edc0.h"

s32 func_ov000_021873d4(Unk02186d7c *p, const Unk021873d4 *q) {
    func_0214d168(p, 0, 0x1a60);
    p->mUnk_960 = -1;
    p->mUnk_04 = *q;
    p->mUnk_91c = p->mUnk_04.mUnk_10(data_ov000_021b1320, 0xb68);
    if (p->mUnk_91c == 0) {
        p->mUnk_24 = 1;
        return 1;
    }
    p->mUnk_920 = p->mUnk_04.mUnk_10(data_ov000_021b1334, 0x5ea);
    if (p->mUnk_920 == 0) {
        p->mUnk_24 = 1;
        return 1;
    }
    func_ov000_021868d0((Unk021868d0 *) p, (const u8 *) q->mUnk_00);
    p->mUnk_24 = func_ov000_02186c74((Unk021868d0 *) p);
    if (p->mUnk_24 == 0) {
        p->mUnk_00 = 0xff;
    }
    return p->mUnk_24;
}

u32 func_ov000_0218735c(Unk02186d7c *p) {
    char v1[8];
    u32 n;
    if (func_ov000_02186bd4((Unk021868d0 *) p, data_ov000_021b135c, data_ov000_021b1368) != 0) {
        return 1;
    }
    n = func_0213a434(func_02139f70(p->mUnk_928.mUnk_00, data_ov000_021b1230) + 4);
    if (n != 0) {
        func_0200d9e0(v1, 7, (const char *) data_ov000_021b1370, n);
        if (func_ov000_02186bd4((Unk021868d0 *) p, data_ov000_021b1374, (const u8 *) v1) != 0) {
            return 1;
        }
    }
    return 0;
}

void func_ov000_021872bc(Unk02186d7c *p) {
    u32 n;
    n = func_0200dcd8(data_0216ff5c.mUnk_04);
    p->mUnk_a40 = 0;
    func_0200edc0(&p->mUnk_a28);
    func_0200edc0(&p->mUnk_948);
    if (p->mUnk_04.mUnk_18 == 1) {
        data_ov000_021b4ca8 = 1;
    } else {
        data_ov000_021b4ca8 = 0;
    }
    if (p->mUnk_968.mUnk_6c == 0 || func_0200e070(&p->mUnk_968) != 0) {
        func_0200e28c(&p->mUnk_968, func_ov000_02186d7c, p, p->mUnk_1a60, 0x1000, n - 1);
        func_0200df68(&p->mUnk_968);
    }
}

void func_ov000_02187274(Unk02186d7c *p) {
    if (p->mUnk_00 == 0xff) {
        func_0200ed34(&p->mUnk_a28);
        p->mUnk_a40 = 1;
        func_0200ecc4(&p->mUnk_a28);
        if (p->mUnk_968.mUnk_6c != 0) {
            func_0200e084(&p->mUnk_968);
        }
    }
}
