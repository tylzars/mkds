#include "00/code_02198584.h"
#include "00/code_02197e8c.h"
#include "00/code_021985ec.h"

u32 func_ov000_02198584(u32 a, u32 b) {
    int v1;
    v1 = func_ov000_021986ac((Unk02197fe8 *) a, b);
    if (v1 == 0) {
        return 0;
    }
    v1 = func_ov000_021985ec((Unk02197fe8 *) a, b);
    if (v1 == 0) {
        return 0;
    }
    v1 = func_ov000_02198658((Unk02197fe8 *) a, b);
    if (v1 == 0) {
        return 0;
    }
    v1 = func_ov000_0219861c((Unk02197fe8 *) a, b);
    if (v1 != 0) {
        return 1;
    }
    return 0;
}
