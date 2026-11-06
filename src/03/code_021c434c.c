#include "03/code_021c434c.h"
#include "03/code_021bf4dc.h"
#include "03/code_021c4328.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"

void func_ov003_021c437c(void) {
    func_ov003_021d1ee0(2, 0, 0x15, 8);
    func_ov003_021d2784(0, 0x15);
    func_ov003_021c212c(func_ov003_021c434c);
}

void func_ov003_021c434c(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_ov003_021bf5c8(4);
        func_ov003_021c212c(func_ov003_021c4328);
    }
}
