#include "00/code_021adb80.h"
#include "00/code_021a9228.h"
#include "00/code_021adbac.h"
#include "Main/Unknown/unk_0216f000.h"

void func_ov000_021adb80(void) {
    Unk021a998c *v1;
    v1 = *(Unk021a998c **) data_0216ff5c.mUnk_04->mUnk_a4;
    if ((v1 != NULL) && (v1->mUnk_60 != 0)) {
        func_ov000_021adc64((v1->mUnk_5c), v1->mUnk_60, NULL, 0);
        v1->mUnk_60 = 0;
    }
}
