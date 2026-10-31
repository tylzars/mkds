#include "03/code_021bf698.h"

void func_ov003_021bf6c8(u32 param_1, u32 param_2, u32 param_3, u32 param_4) {
    int v1;
    int v2;
    int v3;
    u32 v4;
    v1 = 6;
    func_ov003_021bf698();
    v2 = 0;
    v3 = 0;
    do {
        v4 = (u32) func_ov003_021d1be4(0, v1, 1);
        *(u32 *) ((*(int *) &data_ov003_021da150) + v3) = v4;
        func_ov003_021d1790(*(Unk021d1770 **) ((*(int *) &data_ov003_021da150) + v3), 0xffffffff, 1);
        v3 = v3 + 4;
        v2 = v2 + 1;
        v1 = v1 + 1;
    } while (v2 < 4);
    func_ov003_021d17d4(*(Unk021d1770 **) (*(int *) &data_ov003_021da150), 0xffffffff, param_1, param_3);
    func_ov003_021d17d4(*(Unk021d1770 **) ((*(int *) &data_ov003_021da150) + 4), 0xffffffff, param_2, param_3);
    func_ov003_021d17d4(*(Unk021d1770 **) ((*(int *) &data_ov003_021da150) + 8), 0xffffffff, param_1, param_4);
    func_ov003_021d17d4(*(Unk021d1770 **) ((*(int *) &data_ov003_021da150) + 0xc), 0xffffffff, param_2, param_4);
    return;
}

void func_ov003_021bf698(void) {
    int v1;
    int v2;
    Unk021d1770 *p;
    v1 = 0;
    v2 = 0;
    do {
        p = *(Unk021d1770 **) (*(int *) data_ov003_021da150 + v2);
        if (0 != p) {
            func_ov003_021d197c(p);
            *(u32 *) (*(int *) data_ov003_021da150 + v2) = 0;
        }
        v2 = v2 + 4;
        v1 = v1 + 1;
    } while (v1 < 4);
    return;
}
