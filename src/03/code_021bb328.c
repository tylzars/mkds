#include "03/code_021bb328.h"
#include "03/code_021bbc94.h"
#include "03/code_021bbd70.h"
#include "code_0200f5ac.h"
#include "code_021329f8.h"
#include "code_02134d30.h"

void func_ov003_021bb378(u8 *a, const u8 *b, u32 c) {
    Unk021bbd70 d;
    func_ov003_021bbd70(&d);
    func_ov003_021bbcf0(&d, b, c);
    func_ov003_021bbc94(a, &d);
}

u32 func_ov003_021bb354(void) {
    return _ll_udiv(func_0200f5ac() << 6, 0x82ea);
}

void *func_ov003_021bb328(s32 a, s32 b) {
    s32 c = a * b;
    void *d = (void *) data_ov003_021d8bd4(c);
    if (d != 0) {
        func_02134de0(d, 0, c);
    }
    return d;
}
