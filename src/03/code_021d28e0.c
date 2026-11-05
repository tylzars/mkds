#include "03/code_021d28e0.h"
#include "03/unk_021da000.h"
#include "code_0214f4a4.h"

void func_ov003_021d28e0(void) {
    if (data_ov003_021da2cc != 0) {
        if (((*(u16 *) 0x27fffa8 & 0x8000) >> 15) == 0) {
            if (PM_SetLCDPower(1) != 0) {
                data_ov003_021da2cc = 0;
            }
        }
    } else if (((*(u16 *) 0x27fffa8 & 0x8000) >> 15) != 0) {
        if (PM_SetLCDPower(0) != 0) {
            data_ov003_021da2cc = 1;
        }
    }
}
