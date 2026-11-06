#include "03/code_021d1c18.h"
#include "03/code_021d1000.h"
#include "03/unk_021da000.h"
#include "Main/Unknown/code_0214d000.h"
#include "03/code_021d2ecc.h"

#include "03/code_021d1440.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"

void func_ov003_021d1cb0(u32 b, const u8 *c) {
    u32 a;

    data_ov003_021da2b8[b] = func_ov003_021d14b8(c, &a, 4);
}

void func_ov003_021d1c90(u32 a) {
    func_ov003_021d1490(data_ov003_021da2b8[a]);
    data_ov003_021da2b8[a] = NULL;
}

void func_ov003_021d1c3c(u32 f, u32 g, u8 *h) {
    Unk021da2b8 *a = data_ov003_021da2b8[f];
    u8 *b = (u8 *) a + a[g].mUnk_04;
    u16 c = a[g].mUnk_00;
    s32 i;
    u8 e[8];
    // placeholder: the value is sent through the stack
    volatile u32 d = 0;

    MIi_CpuClear32(d, e, 8);
    for (i = 0; i < c; i++, b += 6, h += 8) {
        MIi_CpuCopy16(b, e, 6);
        MIi_CpuCopy32(e, h, 8);
    }
}

void *func_ov003_021d1c18(u32 a, u32 b) {
    u8 *v1;
    u8 v2[8];
    v1 = func_ov003_021d2f44(a, v2);
    func_ov003_021d1c3c(a, b, v1);
    return v1;
}
