#include "00/code_021a37dc.h"

void func_ov000_021a37dc(void) {
    int v1;
    if ((int) data_ov000_021b5df4 != 0) {
        v1 = func_ov000_02188720();
        while (v1 == 0) {
            func_0200dc3c(10);
            v1 = func_ov000_02188720();
        }
        *(int *) &data_ov000_021b5df4 = 0;
    }
    return;
}
