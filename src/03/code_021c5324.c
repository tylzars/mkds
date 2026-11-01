#include "03/code_021c5324.h"
#include "03/code_021bf2d0.h"
#include "03/code_021bf334.h"
#include "03/code_021c2120.h"
#include "03/code_021c515c.h"
#include "03/code_021c52d0.h"
#include "03/code_021cdbd0.h"
#include "03/code_021cdc10.h"
#include "03/code_021ce000.h"
#include "03/code_021d34c0.h"
#include "03/code_021d3544.h"
#include "03/unk_021da000.h"

void func_ov003_021c5324(void) {
    int a;
    func_ov003_021c52f4();
    func_ov003_021c52f0();
    func_ov003_021c52d0();
    a = func_ov003_021c1f34();
    switch (a) {
        case 0:
            break;
        case 1:
            data_ov003_021da1dc = 1;
            func_ov003_021d34c0(1, data_ov003_021da1e4);
            data_ov003_021da1e4 = 0;
            func_ov003_021c212c(func_ov003_021c5120);
            break;
        case 2:
            func_ov003_021cdbd0();
            func_ov003_021cefc0(0x40, 1, 1, -1, 0);
            func_ov003_021cdc10(9);
            func_ov003_021bf2d0();
            func_ov003_021d34c0(1, data_ov003_021da1e4);
            data_ov003_021da1e4 = 0;
            func_ov003_021c212c(func_ov003_021c5178);
            break;
    }
}

void func_ov003_021c53b4(void) {
    if (func_ov003_021bf334() != -2) {
        data_ov003_021da1e4 = func_ov003_021d3544(1, func_ov003_021c51a0, 0, 0x78);
        func_ov003_021c212c(func_ov003_021c5324);
    }
}
