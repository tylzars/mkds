#include "03/code_021bf698.h"
#include "03/unk_021d5000.h"

#include "03/code_021d1000.h"
#include "03/code_021d27d8.h"
#include "03/unk_021da000.h"

void func_ov003_021bf7f4(void) {
    *(void **) &data_ov003_021da150 = func_ov003_021d283c(0x10, 4);
}

void func_ov003_021bf7dc(void) {
    func_ov003_021bf698();
    func_ov003_021d2808(&data_ov003_021da150);
}

void func_ov003_021bf760(u32 param_0, u32 param_1, u32 param_2, u32 param_3) {
    s32 i;
    u8 *a;
    s32 b;

    func_ov003_021bf698();
    i = 0;
    a = data_ov003_021d5f4c + param_0 * 2;
    b = i;
    for (; i < 2; i++) {
        *(u32 *) (*(int *) &data_ov003_021da150 + b) = (u32) func_ov003_021d1be4(0, *a, 1);
        func_ov003_021d1790(*(Unk021d1770 **) (*(int *) &data_ov003_021da150 + b), -1, 1);
        a++;
        b += 4;
    }
    func_ov003_021d17d4(*(Unk021d1770 **) *(int *) &data_ov003_021da150, -1, param_1, param_3);
    func_ov003_021d17d4(*(Unk021d1770 **) (*(int *) &data_ov003_021da150 + 4), -1, param_2, param_3);
}

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
