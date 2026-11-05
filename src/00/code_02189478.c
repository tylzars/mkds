#include "00/code_021884d8.h"
#include "00/code_021892f4.h"
#include "00/code_02189350.h"
#include "00/code_02189420.h"
#include "00/code_02189440.h"
#include "00/code_02189478.h"

u8 func_ov000_021894c0(void) {
    int v1;
    v1 = func_ov000_02188584(1);
    v1 = func_ov000_021892f4((u8 *) (v1 + 10));
    if (v1 == 1) {
        return 0x12;
    }
    return 0x11;
}

u32 func_ov000_02189478(void) {
    u32 v1;
    int v2;
    v1 = func_ov000_02188584(1);
    v2 = func_ov000_021884fc();
    if (v2 < 4) {
        return func_ov000_02189440(v2);
    }
    if (v2 < 5) {
        return func_ov000_02189438();
    }
    if (v2 == 5) {
        return func_ov000_02189420(v1);
    }
    return func_ov000_02189350((Unk02189350 *) v1);
}
