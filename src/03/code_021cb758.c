#include "03/code_021cb758.h"
#include "03/code_021d1440.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"
#include "03/code_021bf098.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf410.h"
#include "03/code_021bf698.h"
#include "03/code_021bf000.h"
#include "03/code_021b94b8.h"
#include "03/code_021cd4ac.h"
#include "03/code_021bf810.h"
#include "03/code_021c209c.h"
#include "03/code_021c2000.h"
#include "03/code_021ce000.h"
#include "03/code_021cb000.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/code_021cb4d0.h"
#include "code_0214b824.h"

void func_ov003_021cb758(void) {
    Unk021d7654 a = data_ov003_021d7654;
    func_ov003_021bf620(data_ov003_021d766c, MemCopyWordsToG2Bg2CntBits2To5Address);
    func_ov003_021bf620(data_ov003_021d7684, func_0214c160);
    func_ov003_021bf620(data_ov003_021d769c, MemCopyHalfwordsToG2Bg2CntBits8To12Address);
    data_ov003_021da244 = func_ov003_021d14b8(func_ov003_021bf650((u8 *) &a), NULL, 4);
    *(u16 *) 0x4001008 = (*(u16 *) 0x4001008 & ~3) | 3;
    *(u16 *) 0x400100a = (*(u16 *) 0x400100a & ~3) | 3;
    *(u16 *) 0x400000a = (*(u16 *) 0x400000a & ~3) | 3;
    *(u16 *) 0x400000c = (*(u16 *) 0x400000c & ~3) | 3;
}

void func_ov003_021cb7fc(void) {
    int a = func_ov003_021cdb6c();
    data_ov003_021da240[0] = 0;
    if (data_ov003_021da238 == 0) {
        data_ov003_021da238 = 1;
    }
    if (func_ov003_021c20d0() != 0) {
        if (data_ov003_021da23c == 2) {
            data_ov003_021da23c = 0;
        }
        if (data_ov003_021da238 == 2) {
            data_ov003_021da238 = 1;
        }
    }
    func_ov003_021cb758();
    func_ov003_021bf854();
    func_ov003_021bf43c(0x7e, data_ov003_021d6578[func_ov003_021c20d0()], *(u8 *) (a + 0xf4) + 1);
    func_ov003_021bf5ec(1);
    func_ov003_021bf6c8(data_ov003_021d65e0[func_ov003_021c20a8(1)][data_ov003_021da23c].mUnk_00,
                        data_ov003_021d65e0[func_ov003_021c20a8(1)][data_ov003_021da23c].mUnk_04,
                        data_ov003_021d65e0[func_ov003_021c20a8(1)][data_ov003_021da23c].mUnk_02,
                        data_ov003_021d65e0[func_ov003_021c20a8(1)][data_ov003_021da23c].mUnk_06);
    func_ov003_021c212c(func_ov003_021cb71c);
}
