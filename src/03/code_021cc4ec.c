#include "03/code_021cc4ec.h"
#include "03/code_021bf2d0.h"
#include "03/code_021bf410.h"
#include "03/code_021c2120.h"
#include "03/code_021ca000.h"
#include "03/code_021cb11c.h"
#include "03/code_021cc3d0.h"
#include "03/code_021cc084.h"
#include "03/code_021cc464.h"
#include "03/code_021cc4a8.h"
#include "03/code_021cc6a4.h"
#include "03/code_021cdbd0.h"
#include "03/code_021cdc10.h"
#include "03/code_021ce000.h"
#include "03/code_021ce834.h"
#include "03/code_021d1f70.h"
#include "03/code_021d2168.h"
#include "03/code_021d254c.h"
#include "03/code_021be610.h"
#include "03/code_021ce848.h"

void func_ov003_021cc4ec(u32 param_1) {
    if (data_ov003_021da258 == 0) {
        switch (param_1) {
            case 0:
                data_ov003_021da258 = 3;
                func_ov003_021cdbd0();
                func_ov003_021cdc10(0x12);
                func_ov003_021cefc0(0x45, 1, 1, -1, 0);
                func_ov003_021bf2d0();
                func_ov003_021c212c(func_ov003_021cc4c4);
                break;
            case 1:
                data_ov003_021da258 = 1;
                func_ov003_021cdbd0();
                func_ov003_021c212c(func_ov003_021cc6a4);
                break;
            case 2:
                func_ov003_021cdbd0();
                func_ov003_021ce834(0);
                func_ov003_021cefc0(0x47, 0, 1, -1, 0);
                func_ov003_021bf2d0();
                func_ov003_021c212c(func_ov003_021cc464);
                break;
            case 3:
                data_ov003_021da258 = 2;
                func_ov003_021cdbd0();
                func_ov003_021cdc10(9);
                func_ov003_021c212c(func_ov003_021cc6a4);
                break;
        }
    }
}

void func_ov003_021cc5a8(void) {
    if (func_ov003_021d1f70(0) == 0 && (data_ov003_021da258 != 2 || func_ov003_021d1f70(1) == 0) &&
        func_ov003_021bf2f0() != 0) {
        func_ov003_021ce848();
        func_ov003_021beecc();
        func_ov003_021d2168(0);
        if (data_ov003_021da258 == 2 || data_ov003_021da258 == 3) {
            func_ov003_021bf410();
            func_ov003_021d272c(1, 1);
        }
        func_ov003_021d272c(0, 0x15);
        if (data_ov003_021da258 == 2) {
            func_ov003_021c2120(2, 1);
            func_ov003_021c212c(func_ov003_021cb294);
        } else if (data_ov003_021da258 == 3) {
            func_ov003_021c2120(2, 1);
            func_ov003_021c212c(func_ov003_021cc3d0);
        } else {
            func_ov003_021c2120(0, 0);
            func_ov003_021c212c(func_ov003_021cc110);
        }
    }
}
