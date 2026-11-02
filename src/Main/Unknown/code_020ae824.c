#include "Main/Unknown/code_020ae824.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/code_020b3724.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b9994.h"
#include "Main/Unknown/code_020ba520.h"
#include "Main/Unknown/code_020bb5ec.h"
#include "Main/Unknown/code_020bc11c.h"
#include "Main/Unknown/code_020bd850.h"
#include "Main/Unknown/code_020be950.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c2118.h"
#include "Main/Unknown/code_020c3e44.h"
#include "Main/Unknown/code_020c4780.h"
#include "Main/Unknown/code_020c4bec.h"
#include "Main/Unknown/code_020c53c4.h"
#include "Main/Unknown/code_020c5e30.h"
#include "Main/Unknown/code_020d0280.h"
#include "Main/Unknown/code_020d1158.h"
#include "Main/Unknown/code_020d12e0.h"
#include "Main/Unknown/code_020d1298.h"
#include "Main/Unknown/code_020d1640.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_0214c778.h"

void func_020ae824(void) {
    u32 v;
    s32 a;

    v = data_021759c0->mUnk_00c;
    if (v == 3) {
        func_020c4ae8();
        return;
    }
    if (v == 5) {
        return;
    }
    if (v == 6) {
        func_020d12e0();
        return;
    }
    if (data_0217b350->mUnk_898 == 0) {
        return;
    }
    func_020b3410();
    func_020b3724();
    data_0217b350->mUnk_404 = 0;
    data_0217b350->mUnk_406 = 0;
    if (data_021759c0->mUnk_00c == 4) {
        func_020d1198((Unk020d029c *) data_0217b350->mUnk_004);
    }
    v = data_021759c0->mUnk_08;
    if ((v == 2   ? data_0217561c->mUnk_4cc
         : v == 4 ? func_0203c174()
                  : (func_0203c880(func_020b4d9c()) != 0 && data_0217b350->mUnk_8dc == 0)) == 0) {
        func_020ba63c((Unk020d029c *) data_0217b350->mUnk_004);
        func_020bc208((Unk020d029c *) data_0217b350->mUnk_004);
        DrawRaceMNumberPair((Unk020d029c *) data_0217b350->mUnk_004);
        func_020d06b8((Unk020d029c *) data_0217b350->mUnk_004);
        func_020c4f08((Unk020c06c4 *) data_0217b350->mUnk_004);
        func_020b9dfc((Unk020d029c *) data_0217b350->mUnk_004);
        func_020c5804((Unk020c06c4 *) data_0217b350->mUnk_004);
    } else {
        func_020d06b8((Unk020d029c *) data_0217b350->mUnk_004);
        func_020c4f08((Unk020c06c4 *) data_0217b350->mUnk_004);
        func_020c5804((Unk020c06c4 *) data_0217b350->mUnk_004);
    }
    func_0200ee74(data_0217b350->mUnk_004, 0x400);
    func_0214cc04(3, data_0217b350->mUnk_004 + data_0217b350->mUnk_404 * 8, 0xc0,
                  (0x80 - data_0217b350->mUnk_404) << 3);
    data_0217b350->mUnk_808 = 0;
    data_0217b350->mUnk_80a = 0;
    a = data_0217b350->mUnk_828;
    if (a != 4 && a != 5) {
        func_020bb5ec((Unk020d029c *) data_0217b350->mUnk_408);
    }
    func_020be2f4((Unk020d029c *) data_0217b350->mUnk_408);
    func_0200ee74(data_0217b350->mUnk_408, 0x400);
    func_0214cc04(3, data_0217b350->mUnk_408 + data_0217b350->mUnk_808 * 8, 0xc0,
                  (0x80 - data_0217b350->mUnk_808) << 3);
    switch (data_0217b350->mUnk_828) {
        case 0:
            func_020be950(data_0217b350->mUnk_408);
            break;
        case 1:
        case 2:
        case 3:
            func_020be950(data_0217b350->mUnk_408);
            func_020c3e44((Unk020c06c4 *) data_0217b350->mUnk_408);
            break;
        case 4:
        case 5:
            func_020c2118((Unk020c06c4 *) data_0217b350->mUnk_408);
            break;
        case 6:
            func_020c676c((Unk020c06c4 *) data_0217b350->mUnk_408);
            break;
    }
}
