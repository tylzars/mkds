#include "00/code_021a9200.h"

// non-matching: 4 instructions differ; first at +0x6: original nothing, ours `add r0, #0x98`
void func_ov000_021a9200(u8 param_1) {
    int v1;
    func_02000b44((u32) (((u32) ((u32) ((u8 *) &BuildInfo + 0x98)))));
    v1 = *(int *) (*(int *) (((int) (u32) ((u8 *) &data_0216ff5c)) + 4) + 0xa4);
    if (v1 != 0) {
        *(u8 *) (v1 + 9) = param_1;
    }
}
