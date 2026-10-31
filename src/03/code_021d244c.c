#include "03/code_021d244c.h"
#include "03/code_021d1d4c.h"
#include "03/code_021d27d8.h"

void func_ov003_021d244c(void) {
    int v1;
    int v2;
    int v3;
    v3 = ((u32) 0x0000078cu);
    v1 = 0;
    v2 = 0;
    do {
        func_ov003_021d1490(*(void **) (*(u8 **) data_ov003_021da2c4 + v2 + v3));
        v2 = v2 + 4;
        v1 = v1 + 1;
    } while (v1 < 2);
    func_ov003_021d1d4c(*(void **) (*(u8 **) data_ov003_021da2c4 + 0x788));
    func_ov003_021d2808((int *) &data_ov003_021da2c4);
    return;
}
