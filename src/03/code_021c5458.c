#include "03/code_021c5458.h"
#include "03/code_021bf620.h"
#include "03/code_021bf43c.h"
#include "03/code_021bf4f4.h"
#include "03/code_021bf5c8.h"
#include "03/code_021bf83c.h"
#include "03/code_021be610.h"
#include "03/code_021c2120.h"
#include "03/code_021c541c.h"
#include "03/code_021cdc10.h"
#include "code_0214b824.h"

void func_ov003_021c5458(void) {
    func_ov003_021bf620(data_ov003_021d71d0, func_0214b95c);
    func_ov003_021bf620(data_ov003_021d71e8, func_0214c160);
    func_ov003_021bf620(data_ov003_021d7200, func_0214bc9c);
    *(vu16 *) 0x4001008 = (*(vu16 *) 0x4001008 & ~3) | 3;
    *(vu16 *) 0x400100a = (*(vu16 *) 0x400100a & ~3) | 3;
    *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & ~3) | 3;
    *(vu16 *) 0x400000a = (*(vu16 *) 0x400000a & ~3) | 3;
    *(vu16 *) 0x400000c = (*(vu16 *) 0x400000c & ~3) | 3;
}

void func_ov003_021c54dc(void) {
    data_ov003_021da1e0 = 0;
    func_ov003_021c5458();
    func_ov003_021bf854();
    func_ov003_021bf43c(0x82, -1, 0);
    func_ov003_021bf5ec(2);
    func_ov003_021bf578(0x67);
    func_ov003_021beef8(0);
    func_ov003_021c1fc8();
    func_ov003_021cdc10(0xb);
    func_ov003_021c212c(func_ov003_021c541c);
}
