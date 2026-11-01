#include "00/code_021adb80.h"
#include "00/code_021a998c.h"

void func_ov000_021adb80(void) {
    Unk021a998c *v1;
    v1 = *(Unk021a998c **) data_0216ff5c.mUnk_04->mUnk_a4;
    if ((v1 != 0) && (v1->mUnk_60 != 0)) {
        func_ov000_021adc64((const u8 *) (v1->mUnk_5c), (int) (v1->mUnk_60), (const u8 *) 0, 0);
        v1->mUnk_60 = 0;
    }
}
