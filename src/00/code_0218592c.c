#include "00/code_0218592c.h"
#include "00/code_02182fdc.h"
#include "code_0200e77c.h"
#include "00/code_021857b8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"

void func_ov000_02185954(s32 a) {
    func_0200ed34(((Unk021b4c90 *) data_ov000_021b4c90)->mUnk_3bc);
    ((Unk021b4c90 *) data_ov000_021b4c90)->mUnk_004 = a;
    func_0200ecc4(((Unk021b4c90 *) data_ov000_021b4c90)->mUnk_3bc);
}

void func_ov000_0218592c(void *a) {
    data_ov000_021b4c8c = func_02036bec(a, 8);
    data_ov000_021b4c8c->mUnk_00 = 0;
    data_ov000_021b4c8c->mUnk_04 = 0;
    func_02036f10(0x1e);
}
