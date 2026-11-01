#include "03/code_021cf284.h"
#include "03/code_021cf260.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"

u16 func_ov003_021cf32c(u32 a) {
    Unk021cf260 *s;

    s = data_ov003_021da288;
    data_ov003_021da28c[0] = &s->mMask;
    data_ov003_021da28c[1] = &s->mUnk_04;
    data_ov003_021da28c[2] = &s->mUnk_06;
    data_ov003_021da28c[3] = &s->mUnk_08;
    data_ov003_021da28c[4] = &s->mUnk_0a;
    data_ov003_021da28c[5] = &s->mUnk_0c;
    return *data_ov003_021da28c[a];
}

u32 func_ov003_021cf284(u32 a) {
    u32 t;
    u16 b;
    u16 s[7];

    t = func_0200fca0();
    b = 1 << a;
    if ((data_ov003_021da288->mMask & b) == 0) {
        func_0200fcb4(t);
        return 0;
    }
    func_0214d1fc(data_ov003_021da288, s, 0xe);
    func_0200fcb4(t);
    if ((s[2] & b) != 0) {
        return 2;
    }
    if ((s[3] & b) != 0) {
        return 3;
    }
    if ((s[4] & b) != 0) {
        return 4;
    }
    if ((s[5] & b) != 0) {
        return 5;
    }
    if ((s[6] & b) != 0) {
        return 6;
    }
    return 1;
}
