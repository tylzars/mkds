#include "03/code_021c3cc4.h"
#include "03/code_021bf43c.h"
#include "03/code_021bf620.h"
#include "03/code_021bf698.h"
#include "03/code_021bf86c.h"
#include "03/code_021c2120.h"
#include "03/code_021c2fd4.h"
#include "03/code_021c3a7c.h"
#include "03/code_021c3c58.h"
#include "03/code_021d1000.h"
#include "03/code_021d1c18.h"
#include "Main/Unknown/code_0200eddc.h"
#include "code_0214b824.h"
#include "code_0214d018.h"
#include "code_02151868.h"

void func_ov003_021c3dd4(void) {
    Unk021da104_04 *a;
    data_ov003_021da1b0[0] = 0;
    func_ov003_021c3cc4();
    func_ov003_021bf86c(0x10);
    func_ov003_021cdcf0(3);
    func_ov003_021bf43c(0x88, -1, 0);
    data_ov003_021da1b8 = (Unk021da104_04 *) func_ov003_021d1c18(0, 0x5b);
    a = data_ov003_021da1b8;
    a->mUnk_00 =
        ((data_ov003_021d634c[0] & 0x1ff) << 16) | ((a->mUnk_00 & 0xfe00ff00) | (data_ov003_021d634c[1] & 0xff));
    a = data_ov003_021da1b8;
    a->mUnk_04 = (a->mUnk_04 & 0xfffff3ff) | 0xc00;
    func_ov003_021bf6c8(data_ov003_021d6368[data_ov003_021da1ac * 4], data_ov003_021d636c[data_ov003_021da1ac * 4],
                        data_ov003_021d636a[data_ov003_021da1ac * 4], data_ov003_021d636e[data_ov003_021da1ac * 4]);
    func_ov003_021c212c(func_ov003_021c3c88);
}

// non-matching: the loop increments come out as p += 0x20, q += 0x20, i++ (original: i++, p += 0x20, q += 0x20)
void func_ov003_021c3cc4(void) {
    u8 *a;
    Unk021d70f8 b;
    Unk021d7110 c;
    Unk021510a4 d;
    s32 i;
    u8 *e;
    u8 *f;
    b = data_ov003_021d70f8;
    c = data_ov003_021d7110;
    func_ov003_021bf620(data_ov003_021d7128, func_0214b95c);
    func_ov003_021bf620(data_ov003_021d7140, func_0214bc9c);
    data_ov003_021da1b4 = func_ov003_021d14b8(func_ov003_021bf650(c.mUnk_00), 0, 4);
    a = func_ov003_021d14b8(func_ov003_021bf650(b.mUnk_00), 0, 4);
    func_02151910(&d);
    if (d.mUnk_00 == 0) {
        e = a + 0xc0;
        f = a + 0x40;
        for (i = 0; i < 2; i++) {
            func_0214d1fc(e, f, 0x20);
            e += 0x20;
            f += 0x20;
        }
    }
    func_0200ee74(a, 0x200);
    func_0214c160(a, 0, 0x200);
    func_ov003_021d1490(a);
    *(u16 *) 0x4001008 = (*(u16 *) 0x4001008 & ~3) | 3;
    *(u16 *) 0x400100a = (*(u16 *) 0x400100a & ~3) | 3;
    *(u16 *) 0x400000a = (*(u16 *) 0x400000a & ~3) | 3;
    *(u16 *) 0x400000c = (*(u16 *) 0x400000c & ~3) | 3;
}
