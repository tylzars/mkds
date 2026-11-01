#include "types.h"
#include "01/code_021a0e34.h"
#include "01/unk_021ca000.h"
#include "Main/Unknown/code_02029520.h"
#include "Main/Unknown/code_0205f000.h"
#include "01/code_021a1000.h"
#include "01/unk_021a6000.h"

void func_ov001_021a0e34(void) {
    s32 out;
    s32 i;

    data_ov001_021ca414->mUnk_a0 = 1;
    for (i = 0; i < 8; i++) {
        data_ov001_021ca414->mUnk_a0 &= func_0205fd78((u8) func_02029608(), (u8) (i + 1), &out);
    }
}
