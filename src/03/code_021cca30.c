#include "03/code_021cca30.h"
#include "03/code_021cc97c.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3544.h"
#include "03/unk_021da000.h"
#include "code_0214d018.h"

void func_ov003_021cca30(const void *param_1) {
    Unk021da25c *a = func_ov003_021d283c(0x608, 4);
    data_ov003_021da25c = a;
    func_0214d0a8(param_1, a->mUnk_004, 0x600);
    data_ov003_021da25c->mUnk_000 = func_ov003_021d3544(1, (u32) func_ov003_021cc97c, 0, 0x78);
}
