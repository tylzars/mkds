#include "Main/Unknown/code_02061428.h"

void func_02061470(void) {
    u8 i;
    u8 *a;
    Unk0217aa08_14 *b;

    a = data_0217aa08->mUnk_40;
    for (i = 0; i < 10; i++) {
        b = (Unk0217aa08_14 *) (a + i * 0x230);
        if (func_020573c8(i) != 0) {
            func_02057800(0, i, b);
            if (data_021759d4->mUnk_0c != 0) {
                func_02145d38();
            }
            if (data_021759d4->mUnk_04 != NULL) {
                b->mUnk_08_0 = 0;
            }
        } else {
            b->mUnk_08_0 = 0;
        }
    }
    func_02057504();
    data_0217aa08->mUnk_40 = NULL;
}

void func_02061428(void *a) {
    data_0217aa08->mUnk_40 = a;
    func_02057514();
    func_02057df0((void (*)(void)) func_02061470);
    data_0217aa0c->mUnk_f8 = 1;
}
