#include "Main/Unknown/code_0210d4a4.h"
#include "Main/Unknown/code_0210e328.h"
#include "Main/Unknown/code_0210bce0.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_0201750c.h"

void func_0210d4a4(Unk0210bf24 *a, s32 b) {
    s32 i;

    func_0210e2c4((Unk0217c7c4 *) data_0217d034, a, b, 0x1c);
    for (i = 0; i < b; i++) {
        func_0210e328(a);
        func_0210bce0(&a->mUnk_08);
        a->mUnk_18 = 0;
        a->mUnk_16 = 0;
        a->mUnk_19 = 0;
        a->mUnk_14 = 0;
        a->mUnk_1a = 0x7f;
        a++;
    }
    func_02017538(&data_0217d028, 0);
    for (i = 0; i < 2; i++) {
        func_02017538(&data_0217d048[i], 0x1c);
    }
    data_0217d010[0] = 0;
    data_0217d024[0] = 0;
}
