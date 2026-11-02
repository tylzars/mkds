#include "00/code_0218acb0.h"
#include "00/code_0218a000.h"
#include "00/code_0218b000.h"
#include "00/code_0218c000.h"
#include "00/code_021a3000.h"
#include "00/code_0218b434.h"
#include "00/code_0218e49c.h"

void func_ov000_0218acf0(int a, u32 b) {
    *(u32 *) (a + 0x28) = b;
    return;
}

void func_ov000_0218acd8(int a) {
    func_ov000_0218ae5c((u32 *) ((u32 *) (u32) (a + 0x14)));
    func_ov000_0218ae5c((u32 *) ((u32 *) (u32) (a + 8)));
    return;
}

void func_ov000_0218acb0(struct Unk0218b668 *p) {
    func_ov000_0218e53c(p->mUnk_020);
    p->mUnk_020 = 0xffffffff;
    func_ov000_0218ae5c(&p->mUnk_014);
    func_ov000_0218ae5c(&p->mUnk_008);
}
