#include "03/code_021c391c.h"
#include "03/code_021bf2d0.h"
#include "03/code_021bf410.h"
#include "03/code_021bf698.h"
#include "03/code_021c2120.h"
#include "03/code_021c2b28.h"
#include "03/code_021c2fd4.h"
#include "03/code_021c33ac.h"
#include "03/code_021c38f0.h"
#include "03/code_021c4670.h"
#include "03/code_021cdc10.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"
#include "03/code_021d2f00.h"
#include "03/unk_021da000.h"
#include "code_02147cd8.h"

void func_ov003_021c39a4(void) {
    if (func_ov003_021d1f70(1) == 0 && func_ov003_021d1f70(0) == 0 && func_ov003_021bf2f0() != 0) {
        func_ov003_021d2f00((u32 *) data_ov003_021da1b8);
        func_ov003_021bf698();
        func_ov003_021bf410();
        func_ov003_021d1490(data_ov003_021da1b4);
        func_ov003_021d272c(1, 1);
        func_ov003_021d272c(0, 0x14);
        if (data_ov003_021da1b0[0] == 0) {
            func_ov003_021c2120(0, 0);
            func_ov003_021c212c(func_ov003_021c3078);
        } else {
            switch (data_ov003_021da1ac) {
                case 0:
                    func_ov003_021c2120(0, 1);
                    func_ov003_021c212c(func_ov003_021c38f0);
                    break;
                case 1:
                    func_ov003_021c2120(0, 1);
                    func_ov003_021c212c(func_ov003_021c33ac);
                    break;
                case 2:
                    func_ov003_021c2120(0, 1);
                    func_ov003_021c212c(func_ov003_021c4670);
                    break;
            }
        }
    }
}

void func_ov003_021c3940(s32 a) {
    if (a == 1) {
        data_ov003_021da1ac = func_02147cd8(data_ov003_021da1ac + 2, 3);
    } else {
        data_ov003_021da1ac = func_02147cd8(data_ov003_021da1ac + 1, 3);
    }
    func_ov003_021cdc10(8);
    func_ov003_021bf6c8(data_ov003_021d6368[data_ov003_021da1ac * 4], data_ov003_021d636c[data_ov003_021da1ac * 4],
                        data_ov003_021d636a[data_ov003_021da1ac * 4], data_ov003_021d636e[data_ov003_021da1ac * 4]);
}

void func_ov003_021c391c(void) {
    u8 a = data_ov003_021d6348[data_ov003_021da1ac];
    func_ov003_021cc948(data_ov003_021da1b4, a, a);
}
