#include "03/code_021c36ec.h"
#include "03/code_021bf4dc.h"
#include "03/code_021c36c8.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"

void func_ov003_021c371c(void) {
    func_ov003_021d1ee0(2, 1, 1, 8);
    func_ov003_021d1ee0(2, 0, 0x15, 8);
    CombineDispcntBits(1, 1);
    CombineDispcntBits(0, 0x15);
    SetUpdateFunction(func_ov003_021c36ec);
}

void func_ov003_021c36ec(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_ov003_021bf5c8(2);
        SetUpdateFunction(func_ov003_021c36c8);
    }
}
