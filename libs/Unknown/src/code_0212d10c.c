#include "code_0200eddc.h"
#include "code_0212d10c.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "00/code_02188720.h"

s32 func_0212d154(u8 *a, u32 b, u32 c, u32 d, u32 e, UnkFunc *f, void *g) {
    volatile u32 v;

    func_0212d10c();
    if (data_0217ddd0.mUnk_00 != 0) {
        return 0;
    }
    v = 0;
    func_0214d018(v, a, b);
    func_0200ee74(a, b);
    return func_0212ccd4(1, a, a + (b >> 1), b >> 1, c, 0, 0, 1, d, 0x7f, 0, 0x7f, e, f, g);
}

void func_0212d10c(void) {
    if (data_0217ddd0.mUnk_00 == 0) {
        return;
    }
    if (data_0217ddd0.mUnk_04 != 1) {
        return;
    }
    func_0212cbd8();
}
