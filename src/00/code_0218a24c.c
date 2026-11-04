#include "00/code_021884d8.h"
#include "00/code_0218a064.h"
#include "00/code_0218a24c.h"
#include "00/unk_021b6000.h"
#include "00/code_021a8aa8.h"

u32 func_ov000_0218a24c(Unk02188ec0 *a) {
    u32 v1;
    u32 v2;
    int v3;
    v1 = func_ov000_02188584(1);
    v2 = func_ov000_02188584(4);
    func_ov000_0218a064((const u32 *) v1, a, (Unk0218a064 *) v2);
    *(u32 *) &data_ov000_021b5f98 = 4;
    v3 = func_ov000_021a8c94((void *) (v2));
    if (v3 != 0) {
        func_ov000_02188508(2);
        return 0x11;
    }
    return 0xc;
}
