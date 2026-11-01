#include "Main/Unknown/code_0210f868.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_0210f744.h"
#include "Main/Unknown/code_0210e33c.h"
#include "Main/Unknown/code_02086080.h"
#include "Main/Unknown/code_02108950.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_02105ec0.h"

void func_0210f9f0(void *a0, int b) {
    Unk0206bcb0 *a = a0;
    u32 v = data_0217d1f0;
    data_0217d1f0 = v + 1;
    func_021090c4(&a->mUnk_00, v + 0xea, 0x7f, 0);
}

void func_0210f9ac(Unk0206bcb0 *a) {
    func_0210ddf4(&data_0217d28c, func_02086080(a->mUnk_74), func_0210f9f0, a, 0);
}

void func_0210f8b0(void *a, s32 b, s32 c) {
    u8 i;
    s32 j;
    func_0210ef34();
    if (b == 4) {
        c = 0x23;
    }
    func_0210dccc(a, b, c, 0xff, func_02108950());
    for (i = 0; i < 2; i++) {
        data_0217d254[i].mUnk_00 = -1;
        data_0217d254[i].mUnk_02 = -1;
        data_0217d254[i].mUnk_04 = -1;
        data_0217d254[i].mUnk_08[0] = i;
    }
    data_0217d23c[0] = 1;
    for (j = 0; j < 2; j++) {
        if (data_0217d23c[j] == 1) {
            break;
        }
    }
    data_0217d23c[1] = 1;
    for (j = 0; j < 2; j++) {
        if (data_0217d23c[j] == 1) {
            data_0217d220 = 1;
            return;
        }
    }
    data_0217d220 = 0;
}

void func_0210f868(u32 a, u32 b) {
    s32 i;
    data_0217d23c[a] = b;
    for (i = 0; i < 2; i++) {
        if (data_0217d23c[i] == 1) {
            data_0217d220 = 1;
            return;
        }
    }
    data_0217d220 = 0;
}
