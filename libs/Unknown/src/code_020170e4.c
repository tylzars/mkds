#include "code_020170e4.h"

#include "code_020169a4.h"
#include "code_02016d28.h"
#include "code_02015f98.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02173000.h"

void func_02017274(u32 a, u32 b, u32 c, int d) {
    data_02173250.mUnk_08 = a;
    data_02173250.mUnk_0c = (Unk020169a4 *) b;
    data_02173250.mUnk_10 = c;
    func_020170e4();
    if (d != 0) {
        data_021619f4 = (u32(*)(s32, s32, s32)) func_02017190;
        data_021619f8 = (void (*)(void *)) func_02017138;
    }
}

u32 func_02017190(u32 a, s32 b) {
    u32 n;
    u32 p;
    s32 r;

    if (a == 0) {
        n = 8;
    } else {
        n = (a + 7) & ~7;
    }
    if (n >= 0x7fff8) {
        return 0;
    }
    if (b != 0) {
        r = func_02016b00(&data_02173250.mUnk_00, &data_02173254, &p, n, 8);
        if (p + n > 0x10000) {
            func_020169a4(&data_02173250.mUnk_00, &data_02173254, p, n);
            return 0;
        }
    } else {
        r = func_02016b00(&data_02173250.mUnk_00, &data_02173254, &p, n, 0x10);
    }
    if (r != 0) {
        return ((n >> 3) << 16) | ((p >> 3) & 0xffff);
    }
    return 0;
}

s32 func_02017138(u32 v) {
    return func_020169a4(&data_02173250.mUnk_00, &data_02173254, (v & 0xffff) << 3, ((v & -0x10000) >> 0x10) << 3) == 0;
}

void func_020170e4(void) {
    data_02173250.mUnk_04 = func_02016cd8(data_02173250.mUnk_0c, data_02173250.mUnk_10 >> 4);
    func_02016d28(&data_02173250.mUnk_00);
    func_02016c64(&data_02173250.mUnk_00, &data_02173254, 0, data_02173250.mUnk_08);
}
