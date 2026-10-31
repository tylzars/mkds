#include "03/code_021cdb90.h"
#include "code_020205b0.h"
#include "03/code_021d27d8.h"

void func_ov003_021cdb90(void) {
    int v1;
    v1 = (u32) func_ov003_021d285c((u32) (((u32) 0x000006f8u)), (u32) 0x20);
    *(int *) &data_ov003_021da270 = v1;
    func_02020720((u16 *) (v1 + 0x4f8), (u32) (((u32) 0x0000a001u)));
    func_02151804((u32) data_ov003_021da270);
}
