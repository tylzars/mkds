#include "03/code_021bf698.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/unk_021d5000.h"

#include "03/code_021d1000.h"
#include "03/code_021d27d8.h"
#include "03/unk_021da000.h"

void func_ov003_021bf7f4(void) {
    data_ov003_021da150 = func_ov003_021d283c(0x10, 4);
}

void func_ov003_021bf7dc(void) {
    func_ov003_021bf698();
    func_ov003_021d2808(&data_ov003_021da150);
}

void func_ov003_021bf760(u32 c, u32 d, u32 e, u32 f) {
    s32 i;
    u8 *a;

    func_ov003_021bf698();
    i = 0;
    a = data_ov003_021d5f4c + c * 2;
    for (; i < 2; i++) {
        data_ov003_021da150[i] = func_ov003_021d1be4(0, *a, 1);
        func_ov003_021d1790(data_ov003_021da150[i], -1, 1);
        a++;
    }
    func_ov003_021d17d4(data_ov003_021da150[0], -1, d, f);
    func_ov003_021d17d4(data_ov003_021da150[1], -1, e, f);
}

void func_ov003_021bf6c8(u32 a, u32 b, u32 c, u32 d) {
    int v1;
    int v2;
    int v3;
    Unk021d1770 *v4;
    v1 = 6;
    func_ov003_021bf698();
    v2 = 0;
    v3 = 0;
    do {
        v4 = func_ov003_021d1be4(0, v1, 1);
        data_ov003_021da150[v3] = v4;
        func_ov003_021d1790(data_ov003_021da150[v3], 0xffffffff, 1);
        v3 = v3 + 1;
        v2 = v2 + 1;
        v1 = v1 + 1;
    } while (v2 < 4);
    func_ov003_021d17d4(data_ov003_021da150[0], 0xffffffff, a, c);
    func_ov003_021d17d4(data_ov003_021da150[1], 0xffffffff, b, c);
    func_ov003_021d17d4(data_ov003_021da150[2], 0xffffffff, a, d);
    func_ov003_021d17d4(data_ov003_021da150[3], 0xffffffff, b, d);
    return;
}

void func_ov003_021bf698(void) {
    int v1;
    int v2;
    Unk021d1770 *p;
    v1 = 0;
    v2 = 0;
    do {
        p = data_ov003_021da150[v2];
        if (NULL != p) {
            func_ov003_021d197c(p);
            data_ov003_021da150[v2] = NULL;
        }
        v2 = v2 + 1;
        v1 = v1 + 1;
    } while (v1 < 4);
    return;
}
