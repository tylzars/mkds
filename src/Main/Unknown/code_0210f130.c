#include "Main/Unknown/code_0210f130.h"

#include "Main/Unknown/unk_0217d000.h"
#include "code_0201ec30.h"
#include "code_0214eef0.h"
#include "code_0214f4a4.h"
#include "Main/Unknown/code_0210f090.h"

u32 data_0217d1bc;

void func_0210f1d4(void) {
    func_0214f418();
    func_021500a0();
    func_0214fb3c(1);
    data_0217d1bc = 1;
}

void func_0210f130(Unk0210f090 *p) {
    Unk0210f130 *q;
    s32 i;

    if (data_0217d1bc == 0) {
        func_0214f418();
        func_021500a0();
        func_0214fb3c(1);
        data_0217d1bc = 1;
    }
    p->mUnk_41c = 0;
    for (i = 0; i < 0x400; i++) {
        p->mUnk_000[i] = 0;
    }
    p->mUnk_400.mUnk_00 = 2;
    q = &p->mUnk_400;
    q->mUnk_04 = (u32) p;
    q->mUnk_08 = 0x400;
    q->mUnk_0c = 0x105d;
    q->mUnk_10 = 1;
    q->mUnk_14 = 0;
    q->mUnk_18 = 0;
    func_02020430((Unk02173290 *) q);
    func_020203d4(0);
    func_0214fb24(3);
}
