#include "00/code_021892f4.h"
#include "00/code_02187484.h"
#include "00/code_02188008.h"
#include "00/code_02188ee0.h"

u32 func_ov000_021892f4(u8 *a) {
    u8 v1;
    int v2;
    v1 = *a;
    if (v1 <= 10) {
        v2 = func_ov000_02189280();
        if (v2 == 1) {
            *a = 0;
            return 1;
        }
        if (v2 == -1) {
            *a = 0x12;
            return 1;
        }
    } else if (v1 == 0xe) {
        DWC_Netcheck_Abort();
        DWC_Netcheck_Destroy();
        *a = 0xc;
    } else if ((v1 < 0x12) && (v2 = func_ov000_0218925c(), v2 == 1)) {
        *a = 10;
    }
    return 0;
}
