#include "00/code_02198584.h"
#include "00/code_02197e58.h"
#include "00/code_021985ec.h"

u32 func_ov000_02198584(Gt2Connection *a, u32 b) {
    int v1;
    v1 = func_ov000_021986ac(a, b);
    if (v1 == 0) {
        return 0;
    }
    v1 = func_ov000_021985ec(a, b);
    if (v1 == 0) {
        return 0;
    }
    v1 = func_ov000_02198658(a, b);
    if (v1 == 0) {
        return 0;
    }
    v1 = func_ov000_0219861c(a, b);
    if (v1 != 0) {
        return 1;
    }
    return 0;
}
