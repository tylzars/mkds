#include "03/code_021ca8e8.h"
#include "03/code_021bf43c.h"
#include "03/code_021bf4f4.h"
#include "03/code_021bf5c8.h"
#include "03/code_021bf83c.h"
#include "03/code_021be610.h"
#include "03/code_021c2120.h"
#include "03/code_021ca7f8.h"
#include "03/code_021cd2a4.h"
#include "03/code_021cd844.h"
#include "03/code_021cdbd0.h"
#include "03/unk_021d7000.h"
#include "03/code_021cdc10.h"

void func_ov003_021ca940(void) {
    Unk021d6974 a;
    Unk021d6974 b;
    int c;
    a = data_ov003_021d75c0;
    b = data_ov003_021d75c4;
    if (*(u8 *) &data_ov003_021da230 <= 3) {
        func_ov003_021cc948(data_ov003_021da234->mUnk_00, a.mUnk_00[*(u8 *) &data_ov003_021da230],
                            a.mUnk_00[*(u8 *) &data_ov003_021da230]);
        if (*(u8 *) &data_ov003_021da230 != 3) {
            c = func_ov003_021cd844(*(u8 *) &data_ov003_021da230);
            if (c > 2) {
                c = 3;
            }
            func_ov003_021d1890(data_ov003_021da234->mUnk_04[*(u8 *) &data_ov003_021da230], -1, 0, b.mUnk_00[c]);
        }
    }
}

void func_ov003_021ca8e8(void) {
    data_ov003_021da22c = 0;
    *(u8 *) &data_ov003_021da228 = 0;
    func_ov003_021ca864();
    func_ov003_021bf43c(0x7f, -1, 0);
    func_ov003_021bf854();
    func_ov003_021bf5ec(2);
    func_ov003_021bf578(0x7f);
    func_ov003_021beef8(0);
    func_ov003_021cd2a4();
    func_ov003_021cd1c4();
    func_ov003_021cdc10(0xa);
    func_ov003_021c212c(func_ov003_021ca828);
}
