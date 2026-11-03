#include "00/code_021a9200.h"
#include "00/code_021a998c.h"
#include "Main/Unknown/code_02000b44.h"
#include "Main/Unknown/unk_02000000.h"
#include "Main/Unknown/unk_0216f000.h"

#pragma opt_unpromotetypes on

void func_ov000_021a9200(u8 param_1) {
    Unk021a998c *v1;
    func_02000b44((u32) ((u8 *) &BuildInfo + 0x98));
    v1 = *(Unk021a998c **) data_0216ff5c.mUnk_04->mUnk_a4;
    if (v1 != NULL) {
        v1->mUnk_09 = param_1;
    }
}
