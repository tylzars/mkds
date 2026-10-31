#include "00/code_021a86bc.h"
#include "00/code_021a8000.h"
#include "00/code_021a8a5c.h"

u32 func_ov000_021a86bc(int param_1) {
    int v1;
    if (((0 <= param_1) && (v1 = func_ov000_021a8a80(), v1 != 0)) &&
        (v1 = func_ov000_021a8a5c((Unk021a8ab8 *) param_1), v1 == 0)) {
        return 1;
    }
    return 0;
}
