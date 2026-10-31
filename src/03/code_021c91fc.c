#include "03/code_021c91fc.h"

u32 func_ov003_021c91fc(void) {
    int v1;
    int v2;
    func_ov003_021cdb6c();
    v1 = func_ov003_021c8400();
    if (v1 == 0xe) {
        return 0;
    }
    v2 = func_ov003_021c8904(v1);
    if (v2 == 0) {
        func_ov003_021cdc10(9);
        return 1;
    }
    func_ov003_021c8100(v1);
    switch (v1) {
        case 2:
        case 3:
        case 7:
        case 8:
            func_ov003_021c7e20();
    }
    func_ov003_021c90dc(v1);
    return 1;
}
