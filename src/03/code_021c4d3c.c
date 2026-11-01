#include "03/code_021c4d3c.h"
#include "03/code_021c2120.h"
#include "03/code_021c27b4.h"
#include "03/code_021c27d0.h"
#include "03/code_021c4ad4.h"
#include "03/code_021c4c64.h"
#include "03/code_021bf43c.h"
#include "03/code_021d1fd0.h"
#include "code_0214cfe4.h"

void func_ov003_021c4d3c(void) {
    u8 *a;
    void *b;
    u16 c[12];
    a = func_ov003_021c27b4();
    b = func_ov003_021d2288(0, 0);
    data_ov003_021da1d4 = 0;
    data_ov003_021da1d0 = 0;
    func_ov003_021c4cd8();
    c[0] = 0;
    func_0214cfe4(c[0], &c[1], 0x16);
    func_0214cffc(a + 2, &c[1], a[1] * 2);
    func_ov003_021d2070(b, data_ov003_021d6380.mUnk_00, data_ov003_021d6380.mUnk_02,
                        data_ov003_021d6380.mUnk_04 - data_ov003_021d6380.mUnk_00,
                        data_ov003_021d6380.mUnk_06 - data_ov003_021d6380.mUnk_02, 2, 0x480, &c[1]);
    func_ov003_021d1fd0(b);
    func_ov003_021c27d0(func_ov003_021c4ad4);
    func_ov003_021c212c(func_ov003_021c4cb0);
}
