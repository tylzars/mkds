#include "03/code_021c5458.h"
#include "03/code_021d1440.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021da000.h"
#include "03/code_021bf410.h"
#include "03/code_021bf000.h"
#include "03/code_021b94b8.h"
#include "03/code_021cd4ac.h"
#include "03/code_021bf810.h"
#include "03/code_021be610.h"
#include "03/code_021c209c.h"
#include "03/code_021c50f8.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "code_0214b824.h"

void func_ov003_021c5458(void) {
    func_ov003_021bf620(data_ov003_021d71d0, MemCopyWordsToG2Bg2CntBits2To5Address);
    func_ov003_021bf620(data_ov003_021d71e8, func_0214c160);
    func_ov003_021bf620(data_ov003_021d7200, MemCopyHalfwordsToG2Bg2CntBits8To12Address);
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
