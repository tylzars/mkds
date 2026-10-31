#include "Main/Unknown/code_02111a98.h"

#include "Main/Unknown/code_02111450.h"
#include "Main/Unknown/code_02111494.h"
#include "Main/Unknown/code_02111b40.h"
#include "Main/Unknown/code_02111b94.h"
#include "Main/Unknown/code_02112b48.h"
#include "Main/Unknown/code_021114cc.h"
#include "Main/Unknown/unk_0217d000.h"
#include "registers.h"

#pragma thumb on

void func_02111adc(void) {
    u32 v;
    if (func_0211146c() == 12) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1b00;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | 0x1600;
    } else {
        v = (reg_GX_DISPCNT & 0x1f00) >> 8;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | ((v | 0x13) << 8);
    }
}

void func_02111ab4(void) {
    Unk0217d344_18 v = {func_02112bb4, func_02112b48, func_02111b94, func_02111b40, func_02111adc};
    func_02111494(&v);
}

void func_02111a98(void) {
    data_0217d344->mUnk_18.mUnk_00 = 0;
    data_0217d344->mUnk_18.mUnk_04 = 0;
    data_0217d344->mUnk_18.mUnk_08 = 0;
    data_0217d344->mUnk_18.mUnk_0c = 0;
}

#pragma thumb off
