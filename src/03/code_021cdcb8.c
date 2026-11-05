#include "03/code_021cdcb8.h"
#include "03/code_021d1000.h"
#include "03/code_021d3000.h"
#include "03/unk_021da000.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0200eddc.h"
#include "code_0214b824.h"

#include "03/code_021d1440.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d3488.h"

void func_ov003_021cdcf0(u32 a) {
    data_ov003_021da278 = func_ov003_021d14b8(func_ov003_021bf650(data_ov003_021d7850[a]), NULL, 4);
    func_ov003_021d3544(1, func_ov003_021cdcb8, NULL, 0x78);
}

void func_ov003_021cdcb8(u32 a) {
    DC_FlushRange(data_ov003_021da278, (0x00000600u));
    MemCopyHalfwordsToG2sBg1CntBits8To12Address(data_ov003_021da278, 0, (u32) (((u32) 0x00000600u)));
    func_ov003_021d1490(data_ov003_021da278);
    func_ov003_021d34c8(1, a);
    return;
}
