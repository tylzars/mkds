#include "03/code_021c0000.h"
#include "03/code_021c04ec.h"
#include "03/unk_021da000.h"

void func_ov003_021c04ec(int a) {
    if (a != data_ov003_021da15c->mUnk_11f) {
        func_ov003_021c0050(a, 1);
        func_ov003_021c0050(data_ov003_021da15c->mUnk_11f, 0);
        data_ov003_021da15c->mUnk_11f = (s8) a;
    }
}
