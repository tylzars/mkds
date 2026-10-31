#include "01/code_02193448.h"
#include "Main/Unknown/code_02125f54.h"

void func_ov001_02193448(void) {
    int v1;
    v1 = func_ov001_02192e84();
    if ((v1 == -1) && (data_ov001_021a9bd4->mUnk_10 == 4)) {
        func_ov001_02192e78((u16) 0);
    }
    v1 = func_02125f54();
    if (v1 != 0) {
        func_02125ebc((u32) 0x23);
        func_02125fc0();
        *(u32 *) ((int) data_ov001_021a9bd4 + 0x10) = 4;
    }
}
