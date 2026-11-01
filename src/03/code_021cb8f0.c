#include "03/code_021cb8f0.h"
#include "00/code_02188694.h"
#include "00/code_02188720.h"
#include "03/code_021bf000.h"
#include "03/code_021be610.h"
#include "03/code_021c2120.h"
#include "03/code_021c7844.h"
#include "03/code_021c7cb0.h"
#include "03/code_021cb9c8.h"
#include "03/code_021cbd40.h"
#include "03/code_021cd4ac.h"
#include "03/code_021cdbd0.h"
#include "03/code_021cdc10.h"
#include "03/code_021d2168.h"
#include "03/code_021d254c.h"
#include "03/code_021d34c8.h"
#include "03/unk_021da000.h"
#include "Main/Unknown/code_0215109c.h"
#include "code_0214d018.h"

void func_ov003_021cb948(void) {
    u32 a = func_ov003_021cd4dc();
    if (func_ov000_02188720() != 0) {
        func_0214d1fc((const void *) func_0215109c(), (void *) (a + 0xf0), 0xe);
        func_0214d1fc((const void *) func_0215109c(), (void *) (a + 0x1f0), 0xe);
        func_ov003_021beecc();
        func_ov003_021d2168(0);
        func_ov003_021d272c(0, 0x15);
        if (data_ov003_021da248 == 0) {
            func_ov003_021c2120(0, 1);
            func_ov003_021c212c(func_ov003_021c7d14);
        } else {
            func_ov003_021c2120(0, 1);
            func_ov003_021c212c(func_ov003_021cbdbc);
        }
    }
}

void func_ov003_021cb8f0(u32 param_1) {
    s32 a = func_ov000_021887cc();
    if (a != 0) {
        func_ov003_021bf9b8();
        func_ov003_021cdbd0();
        if (a > 0) {
            data_ov003_021da248 = 1;
            func_ov003_021cdc10(0x11);
        } else {
            func_ov003_021c7844(func_ov000_02188758());
            func_ov003_021cdc10(0x12);
        }
        func_ov003_021c212c(func_ov003_021cb9e8);
        func_ov003_021d34c8(0, param_1);
    }
}
