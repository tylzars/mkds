#include "03/code_021cbb98.h"
#include "03/code_021be610.h"
#include "03/code_021bf000.h"
#include "03/code_021bf43c.h"
#include "03/code_021bf4f4.h"
#include "03/code_021bf5c8.h"
#include "03/code_021bf83c.h"
#include "03/code_021c20c0.h"
#include "03/code_021c20dc.h"
#include "03/code_021c2120.h"
#include "03/code_021c2a74.h"
#include "03/code_021cba54.h"
#include "03/code_021cbaa0.h"
#include "03/code_021cbb14.h"
#include "03/code_021cbc50.h"
#include "03/code_021cdc10.h"

void func_ov003_021cbb98(void) {
    s32 a;
    data_ov003_021da248 = 0;
    func_ov003_021cbb14();
    func_ov003_021c20dc(0, &a);
    if (a == 0) {
        func_ov003_021bf43c(0x7d, -1, 0);
    }
    func_ov003_021bf5ec(2);
    if (a == 0) {
        func_ov003_021bf854();
    }
    func_ov003_021bf578(0x76);
    func_ov003_021beef8(0);
    func_ov003_021cbaa0();
    func_ov003_021bf9e8(0);
    func_ov003_021cdc10(0xc);
    func_ov003_021c212c(func_ov003_021cba54);
}

void func_ov003_021cbc00(void) {
    s32 a;
    data_ov003_021da24c[0]++;
    if (data_ov003_021da24c[0] >= 0xb4) {
        func_ov003_021c20dc(0, &a);
        switch (func_ov003_021c20c0()) {
            case 0:
                break;
            case 1:
                if (a != 0) {
                    func_ov003_021c212c(func_ov003_021c2a74);
                    return;
                }
                break;
        }
        func_ov003_021c212c(func_ov003_021cbcc8);
    }
}
