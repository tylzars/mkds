#include "03/code_021be4ec.h"
#include "code_0200fc8c.h"

void func_ov003_021be568(void) {
    u32 a = func_0200fca0();
    s32 i;

    data_ov003_021d8c38 = 0;
    data_ov003_021d8c3c = 0;
    for (i = 0; i < 4; i++) {
        data_ov003_021d8c6c[i] = 0;
    }
    func_0200fcb4(a);
}

u32 func_ov003_021be528(void) {
    u32 a = func_0200fca0();
    s32 b = data_ov003_021d8c3c;
    u32 c;

    if (data_ov003_021d8c38 == b) {
        c = 0;
    } else {
        c = data_ov003_021d8c6c[b];
        b++;
        data_ov003_021d8c3c = b;
        if (b >= 4) {
            data_ov003_021d8c3c = 0;
        }
    }
    func_0200fcb4(a);
    return c;
}

void func_ov003_021be4ec(u32 v1, u32 v2) {
    s32 a = data_ov003_021d8c3c;
    s32 b = data_ov003_021d8c38;
    s32 c = b + 1;

    if (c == a) {
        return;
    }
    if (b == a + 3) {
        return;
    }
    data_ov003_021d8c6c[b] = v1;
    data_ov003_021d8c38 = c;
    if (c >= 4) {
        data_ov003_021d8c38 = 0;
    }
}
