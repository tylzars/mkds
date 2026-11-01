#include "03/code_021c2fd4.h"
#include "03/code_021bf43c.h"
#include "03/code_021bf620.h"
#include "03/code_021bf698.h"
#include "03/code_021bf86c.h"
#include "03/code_021c2120.h"
#include "03/code_021c2b28.h"
#include "03/code_021c2f68.h"
#include "03/code_021d1000.h"
#include "code_0214b824.h"

void func_ov003_021c3078(void) {
    func_ov003_021c2fd4();
    func_ov003_021bf86c(0);
    func_ov003_021bf43c(0x7a, -1, 0);
    func_ov003_021cdcf0(4);
    func_ov003_021bf6c8(data_ov003_021d6328[data_ov003_021da1a0 * 4], data_ov003_021d632c[data_ov003_021da1a0 * 4],
                        data_ov003_021d632a[data_ov003_021da1a0 * 4], data_ov003_021d632e[data_ov003_021da1a0 * 4]);
    func_ov003_021c212c(func_ov003_021c2f98);
}

void func_ov003_021c2fd4(void) {
    Unk021d6fd4 a;
    a = data_ov003_021d6fd4;
    func_ov003_021bf620(data_ov003_021d6fec, func_0214b95c);
    func_ov003_021bf620(data_ov003_021d7004, func_0214c160);
    func_ov003_021bf620(data_ov003_021d701c, func_0214bc9c);
    data_ov003_021da1a4 = func_ov003_021d14b8(func_ov003_021bf650(a.mUnk_00), 0, 4);
    *(u16 *) 0x4001008 = (*(u16 *) 0x4001008 & ~3) | 3;
    *(u16 *) 0x400100a = (*(u16 *) 0x400100a & ~3) | 3;
    *(u16 *) 0x400000a = (*(u16 *) 0x400000a & ~3) | 3;
    *(u16 *) 0x400000c = (*(u16 *) 0x400000c & ~3) | 3;
}
