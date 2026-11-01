#include "Main/Unknown/code_021171a0.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02016468.h"

#pragma thumb on

void func_021171a0(s32 a, void *b, void *c, u32 d, u16 e, s32 f) {
    int n;

    n = 0x12;
    switch (f) {
        case 0:
            n = 0xe;
            break;
        case 1:
            n = 0x1e;
            break;
    }
    func_02124748(data_0215c60c[a].mUnk_00, data_0217d35c->mUnk_04, data_0217d35c->mUnk_00, data_0217d35c->mUnk_14, f,
                  d, b, c);
    func_02016468(n, e * 32, data_0217d35c->mUnk_08[data_0215c60c[a].mUnk_04]->mUnk_0c + data_0215c60c[a].mUnk_08 * 16,
                  0x20);
}

#pragma thumb off
