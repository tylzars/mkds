#include "03/code_021d35f4.h"
#include "03/code_021d1000.h"
#include "03/code_021d27d8.h"
#include "03/code_021d2e50.h"
#include "03/code_021d2ecc.h"
#include "03/code_021d34c8.h"
#include "03/unk_021d6000.h"
#include "03/unk_021da000.h"

void func_ov003_021d35f4(void) {
    s32 i;
    u8 *b;

    data_ov003_021da32c = func_ov003_021d285c(0x78, 4);
    i = 0;
    b = data_ov003_021d67f0;
    do {
        data_ov003_021da32c[i].mUnk_34 = *b;
        data_ov003_021da32c[i].mUnk_38 = func_ov003_021d285c(*b * 0x14, 4);
        data_ov003_021da32c[i].mUnk_00 = func_ov003_021d1d60(*b, data_ov003_021da32c[i].mUnk_38, 0x14);
        data_ov003_021da32c[i].mResource = func_ov003_021d1d88(*b);
        data_ov003_021da32c[i].mUnk_08 = func_ov003_021d2ecc();
        data_ov003_021da32c[i].mUnk_0c.mUnk_10 = 0;
        data_ov003_021da32c[i].mUnk_20.mUnk_10 = 0xff;
        func_ov003_021d2e50((u32) data_ov003_021da32c[i].mUnk_08, (u32) &data_ov003_021da32c[i].mUnk_0c);
        func_ov003_021d2e5c((u32) data_ov003_021da32c[i].mUnk_08, (u32) &data_ov003_021da32c[i].mUnk_20);
        b++;
        i++;
    } while (i < 2);
}
