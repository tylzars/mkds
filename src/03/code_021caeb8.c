#include "03/code_021caeb8.h"
#include "03/code_021bf2d0.h"
#include "03/code_021c20c0.h"
#include "03/code_021c20d0.h"
#include "03/code_021c2120.h"
#include "03/code_021c2a74.h"
#include "03/code_021bf334.h"
#include "03/code_021ca000.h"
#include "03/code_021ca9e8.h"
#include "03/code_021cae88.h"
#include "03/code_021cd000.h"
#include "03/code_021cd844.h"
#include "03/code_021cdc10.h"
#include "03/code_021ce000.h"
#include "03/unk_021d6000.h"
#include "03/code_021ca8e8.h"

void func_ov003_021caeb8(void) {
    s32 a;
    u8 s;
    switch (func_ov003_021bf334()) {
        case 0:
            switch (func_ov003_021c20c0()) {
                case 0:
                    func_ov003_021cdc10(7);
                    data_ov003_021da234->mUnk_1d = 2;
                    break;
                case 1:
                    func_ov003_021bf2d0();
                    func_ov003_021c212c(func_ov003_021c2a74);
                    return;
            }
            break;
        case 1:
            data_ov003_021da234->mUnk_1d = 1;
            s = data_ov003_021da230[0];
            if (s >= 4) {
                a = s - 4;
                if (func_ov003_021cd844(a) == 0xff) {
                    func_ov003_021cdc10(9);
                    func_ov003_021bf310(-1);
                    return;
                }
                func_ov003_021cdc10(6);
                func_ov003_021cefc0(0x98, 0, 1, data_ov003_021d64e8[func_ov003_021c20d0()], a + 1);
                func_ov003_021caae0();
                func_ov003_021bf2d0();
                func_ov003_021c212c(func_ov003_021ca9e8);
                return;
            }
            if (s <= 2) {
                func_ov003_021cd790(s);
            }
            func_ov003_021cdc10(6);
            func_ov003_021ca940();
            break;
        default:
            return;
    }
    func_ov003_021c212c(func_ov003_021cae88);
}
