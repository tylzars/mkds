#include "00/code_0218acb0.h"
#include "00/code_0218a000.h"
#include "00/code_0218b000.h"
#include "00/code_0218c000.h"
#include "00/code_021a3000.h"
#include "00/code_0218b434.h"
#include "00/code_0218e49c.h"

void func_ov000_0218acf0(int param_1, u32 param_2) {
    *(u32 *) (param_1 + 0x28) = param_2;
    return;
}

void func_ov000_0218acd8(int param_1) {
    func_ov000_0218ae5c((u32 *) ((u32 *) (u32) (param_1 + 0x14)));
    func_ov000_0218ae5c((u32 *) ((u32 *) (u32) (param_1 + 8)));
    return;
}

void func_ov000_0218acb0(struct Unk0218b668 *p) {
    func_ov000_0218e53c(p->mUnk_020);
    p->mUnk_020 = 0xffffffff;
    func_ov000_0218ae5c(&p->mUnk_014);
    func_ov000_0218ae5c(&p->mUnk_008);
}
