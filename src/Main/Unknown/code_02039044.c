#include "Main/Unknown/code_02039044.h"
#include "code_0200c894.h"
#include "code_02148950.h"
#include "code_021488e8.h"

void func_020390f0(Unk021755a8 *a) {
    switch (a->mUnk_00) {
        case 0:
            break;
        case 1:
            a->mUnk_04++;
            if (a->mUnk_04 >= a->mUnk_06) {
                a->mUnk_00 = 2;
                a->mUnk_08 = 0;
            } else {
                a->mUnk_08 = 0x10 - (a->mUnk_04 << 4) / a->mUnk_06;
            }
            if (a->mUnk_02 == 0) {
                a->mUnk_08 = -a->mUnk_08;
            }
            break;
        case 2:
            a->mUnk_08 = 0;
            break;
        case 3:
            a->mUnk_04++;
            if (a->mUnk_04 >= a->mUnk_06) {
                a->mUnk_00 = 0;
                a->mUnk_08 = 0x10;
            } else {
                a->mUnk_08 = (a->mUnk_04 << 4) / a->mUnk_06;
            }
            if (a->mUnk_02 == 0) {
                a->mUnk_08 = -a->mUnk_08;
            }
            break;
    }
}

void func_0203907c(void) {
    data_021755b4.mUnk_00 = 0;
    data_021755b4.mUnk_02 = 1;
    data_021755b4.mUnk_04 = 0;
    data_021755b4.mUnk_06 = 0;
    data_021755b4.mUnk_08 = 0x10;
    data_021755a8.mUnk_00 = 0;
    data_021755a8.mUnk_02 = 1;
    data_021755a8.mUnk_04 = 0;
    data_021755a8.mUnk_06 = 0;
    data_021755a8.mUnk_08 = 0x10;
    MasterBrightWrite((u16 *) 0x400006c, data_021755b4.mUnk_08);
    MasterBrightWrite((u16 *) 0x400106c, data_021755a8.mUnk_08);
}

void func_02039044(void) {
    InterruptClearAndWait(1, 1);
    func_021489c4();
    *(vu32 *) 0x4001000 = *(vu32 *) 0x4001000 | 0x10000;
}
