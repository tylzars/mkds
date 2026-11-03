#include "code_0200f790.h"
#include "code_0200fb28.h"
#include "code_0200c914.h"
#include "code_0200f580.h"
#include "code_0200f5ac.h"
#include "code_0200f7a0.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/unk_02170000.h"

void func_0200fc1c(void) {
    if (data_02170268 != 0) {
        return;
    }
    data_02170268 = 1;
    data_02170274[0] = 0;
    data_02170274[1] = 0;
    func_0200ca9c(4);
    data_02170270 = 0;
    data_0217026c = 0;
}

void func_0200fb80(Unk0200fb08 *n) {
    u64 t;
    s64 d;
    u16 v;

    t = func_0200f5ac();
    *(vu16 *) 0x4000106 = 0;
    d = n->mUnk_0c - t;
    func_0200cb50(1, func_0200f790, 0);
    if (d < 0) {
        v = 0xfffe;
    } else if (d < 0x10000) {
        v = ~d;
    } else {
        v = 0;
    }
    *(vu16 *) 0x4000104 = v;
    *(vu16 *) 0x4000106 = 0xc1;
    func_0200cae4(0x10);
}

void func_0200fb28(void) {
    if (data_0217025c != 0) {
        return;
    }
    data_0217025c = 1;
    func_0200f580(1);
    data_02170260.mUnk_00 = 0;
    data_02170260.mUnk_04 = 0;
    func_0200ca9c(0x10);
}
