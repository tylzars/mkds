#include "00/code_0218583c.h"
#include "00/code_021857e0.h"
#include "00/code_02182fdc.h"
#include "01/code_02195a6c.h"
#include "code_0200e904.h"
#include "code_02148950.h"
#include "code_021458c4.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/unk_0217a000.h"
#include "registers.h"

void func_ov000_0218583c(void) {
    u32 a;
    Unk0217aa08_00 *p;
    s8 b;

    if (func_02036d08() != 0) {
        data_ov000_021b4c8c->mUnk_04 = 1;
        func_02037288(0x1e);
        reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | 0x1208;
        reg_G2_BG1CNT = reg_G2_BG1CNT & ~3;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1f00;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | 0x1700;
        reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
        func_02148950(1, 0, 1);
        if (data_0217b488->mUnk_6c != 0) {
            p = data_0217aa08->mUnk_00;
            a = p->mUnk_48;
            b = data_0217d384->mUnk_1f54 - 1;
            if (b > 0) {
                if (a < b) {
                    a = 0;
                } else {
                    a -= b;
                }
            }
            p->mUnk_48 = a;
            func_02056d40();
            func_02057d9c();
            if (data_021759d4->mUnk_0c != 0) {
                func_02145d38();
            }
        }
    }
}
