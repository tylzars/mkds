#include "03/code_021c0fd8.h"
#include "03/code_021d197c.h"
#include "03/code_021d27d8.h"
#include "03/code_021d2ecc.h"

void func_ov003_021c0fd8(u32 a) {
    int v1;
    int v2;
    func_ov003_021d34c8(0, a);
    v1 = 0;
    v2 = 0;
    do {
        func_ov003_021d197c(*(Unk021d1770 **) ((u8 *) data_ov003_021da160 + v2 + 0x48));
        func_ov003_021d2388((*(u32 *) ((u8 *) data_ov003_021da160 + v2)));
        v2 = v2 + 4;
        v1 = v1 + 1;
    } while (v1 < 4);
    v2 = 0;
    v1 = 0;
    do {
        func_ov003_021d197c(*(Unk021d1770 **) ((u8 *) data_ov003_021da160 + v1 + 0x40));
        v1 = v1 + 4;
        v2 = v2 + 1;
    } while (v2 < 2);
    v2 = 0;
    v1 = 0;
    do {
        func_ov003_021d2f00((u32 *) (u32) (*(u32 *) ((u8 *) data_ov003_021da160 + v1 + 0x38)));
        v1 = v1 + 4;
        v2 = v2 + 1;
    } while (v2 < 2);
    v2 = 0;
    v1 = 0;
    do {
        func_ov003_021d2f00((u32 *) (u32) (*(u32 *) ((u8 *) data_ov003_021da160 + v1 + 0x10)));
        v1 = v1 + 4;
        v2 = v2 + 1;
    } while (v2 < 10);
    func_ov003_021d2808(&data_ov003_021da160);
    return;
}
