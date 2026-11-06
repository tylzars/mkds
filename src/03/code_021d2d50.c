#include "03/code_021d2d50.h"
#include "03/code_021d27d8.h"
#include "03/code_021d2940.h"
#include "03/code_021d3000.h"
#include "03/unk_021da000.h"
#include "code_0200c914.h"
#include "code_0200fc8c.h"
#include "code_0214e308.h"

void func_ov003_021d2dfc(void) {
    u16 a;

    data_ov003_021da2ec = *(vu32 *) 0x4000210;
    OS_SetIrqMask(0x40018);
    OS_EnableIrqMask(1);
    data_ov003_021da2e8 = OS_GetIrqFunction(1);
    OS_SetIrqFunction(1, func_ov003_021d2da4);
    a = *(vu16 *) 0x4000208;
    *(vu16 *) 0x4000208 = 1;
    IrqEnable();
}

void func_ov003_021d2dcc(void) {
    u16 a;

    a = *(vu16 *) 0x4000208;
    *(vu16 *) 0x4000208 = 0;
    OS_SetIrqMask(data_ov003_021da2ec);
    OS_SetIrqFunction(1, data_ov003_021da2e8);
}

void func_ov003_021d2da4(void) {
    func_ov003_021d3558(1);
    *(u32 *) ((u8 *) &data_027e0000 + 0x3ff8) |= 1;
}

void func_ov003_021d2d50(void) {
    Unk0214e334 a;

    data_ov003_021da2d4 = func_ov003_021d283c(0x3a, 4);
    if (TP_GetUserInfo(&a) == 0) {
        IrqDisableLoopForever();
    }
    TP_SetCalibrateParam(&a);
    TP_RequestAutoSamplingStartAsync(0, 4, data_ov003_021da2d4->mUnk_00, 5);
    TP_WaitBusy(2);
    if (TP_CheckError(2) != 0) {
        IrqDisableLoopForever();
    }
    func_ov003_021d2d14();
}
