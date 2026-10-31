#include "03/code_021ccb1c.h"
#include "03/code_021d29e8.h"
#include "03/code_021d2a34.h"
#include "03/code_021d2a80.h"

int func_ov003_021ccb50(void) {
    int v1;
    int v2;
    u8 v3[8];
    func_ov003_021cca9c(1, (u16 *) (void *) (v3));
    v1 = func_ov003_021d29e8((const Unk021d299c *) (u16 *) (void *) (v3));
    if (v1 != 0) {
        return 1;
    }
    v1 = 2;
    do {
        func_ov003_021cca9c(v1, (u16 *) (void *) (v3));
        v2 = func_ov003_021d29e8((const Unk021d299c *) (u16 *) (void *) (v3));
        if (v2 != 0) {
            return v1;
        }
        v1 = v1 + 1;
    } while (v1 <= 3);
    func_ov003_021cca9c(4, (u16 *) (void *) (v3));
    v1 = func_ov003_021d2a34((const Unk021d299c *) (u16 *) ((u16 *) (void *) (v3)));
    if (v1 != 0) {
        return 4;
    }
    return 0;
}

int func_ov003_021ccb1c(int param_1) {
    int v1;
    int v2;
    u8 v3[8];
    v2 = 2;
    do {
        func_ov003_021cca9c(v2, (u16 *) (void *) (v3));
        v1 = func_ov003_021d2a80((const Unk021d299c *) (u16 *) (void *) (v3));
        if (v1 != 0) {
            return v2;
        }
        v2 = v2 + 1;
    } while (v2 <= 3);
    return 0;
}
