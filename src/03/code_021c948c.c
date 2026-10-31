#include "03/code_021c948c.h"
#include "03/code_021c9464.h"
#include "03/code_021d254c.h"

void func_ov003_021c94c8(void) {
    int v1[1];
    func_ov003_021cdb6c();
    func_ov003_021c20dc(0, v1);
    if (v1[0] == 0) {
        *(u16 *) &data_ov003_021da210 = 0;
        *(u8 *) &data_ov003_021da204 = 0;
        *(u8 *) &data_ov003_021da20c = 0;
    }
    return;
}

void func_ov003_021c948c(void) {
    func_ov003_021d1ee0(2, 1, 1, (u16) (8));
    func_ov003_021d1ee0(2, 0, 0x1d, (u16) (8));
    func_ov003_021d2784(1, 1);
    func_ov003_021d2784(0, 0x1d);
    func_ov003_021c212c(func_ov003_021c9464);
    return;
}
