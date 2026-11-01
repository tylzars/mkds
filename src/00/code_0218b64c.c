#include "00/code_0218b64c.h"
#include "00/code_0218b708.h"
#include "00/code_021a3690.h"

Unk0218b668 *func_ov000_0218b668(u32 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6,
                                 s32 param_7, UnkFunc *param_8, u32 param_9) {
    Unk0218b668 *p;
    if (param_7 == 0 && data_ov000_021b4d28 != 1) {
        return 0;
    }
    p = func_ov000_021a3690(0x638);
    if (p == 0) {
        return 0;
    }
    p->mUnk_630 = param_8;
    p->mUnk_634 = param_9;
    p->mUnk_624 = 0;
    func_ov000_0218cfb8(&p->mUnk_04c, (const u8 *) param_1, (const u8 *) param_2, (const u8 *) param_3, param_4,
                        param_7, func_ov000_0218b780, p);
    func_ov000_0218acf4((Unk0218a9bc *) p, param_5, param_6, param_7, func_ov000_0218b708, p);
    return p;
}

void func_ov000_0218b64c(Unk0218b668 *p) {
    func_ov000_0218c958(&p->mUnk_04c);
    func_ov000_0218acb0(p);
    func_ov000_021a3668(p);
}
