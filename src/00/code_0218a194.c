#include "00/code_0218a194.h"
#include "00/code_02188008.h"
#include "00/code_021884d8.h"

u32 func_ov000_0218a194(void) {
    int v1;
    v1 = DWC_Netcheck_Create((Unk02188114 *) func_ov000_02188584(8));
    if (v1 != 0) {
        func_ov000_02188508(3);
        return 0x11;
    }
    return 0xe;
}
