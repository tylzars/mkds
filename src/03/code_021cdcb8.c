#include "03/code_021cdcb8.h"
#include "03/code_021d1000.h"
#include "03/code_021d3000.h"
#include "03/unk_021da000.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0214b824.h"

#include "03/code_021d1440.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d3488.h"

void func_ov003_021cdcf0(u32 a) {
    data_ov003_021da278 = func_ov003_021d14b8(func_ov003_021bf650(data_ov003_021d7850[a]), 0, 4);
    func_ov003_021d3544(1, func_ov003_021cdcb8, 0, 0x78);
}

void func_ov003_021cdcb8(u32 param_1) {
    func_0200ee74(data_ov003_021da278, (int) (((u32) 0x00000600u)));
    func_0214bd04(data_ov003_021da278, 0, (u32) (((u32) 0x00000600u)));
    func_ov003_021d1490(data_ov003_021da278);
    func_ov003_021d34c8(1, param_1);
    return;
}
