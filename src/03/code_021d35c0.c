#include "03/code_021d35c0.h"
#include "03/code_021d1d4c.h"
#include "03/code_021d2eb8.h"
#include "03/code_021d27d8.h"

void func_ov003_021d35c0(void) {
    int v1;
    int v2;
    v1 = 0;
    v2 = 0;
    do {
        func_ov003_021d2eb8(*(void **) ((u8 *) data_ov003_021da32c + v2 + 8));
        func_ov003_021d1d4c(*(void **) ((u8 *) data_ov003_021da32c + v2));
        v2 = v2 + 0x3c;
        v1 = v1 + 1;
    } while (2 > v1);
    func_ov003_021d2808((int *) &data_ov003_021da32c);
    return;
}
