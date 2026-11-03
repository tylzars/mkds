#include "01/code_02187cd4.h"
#include "01/code_02187d14.h"
#include "01/code_02188950.h"
#include "01/code_0219b250.h"
#include "code_020109c4.h"

void func_ov001_02187cd4(Unk02188950 *a, u32 b) {
    Unk0219b250 **v1;
    a->mUnk_2e4 = b;
    a->mUnk_27c = 3;
    v1 = &a->mNsbmd;
    (*v1)->mUnk_10->mUnk_2c = a;
    func_020109c4((void *) (*v1)->mUnk_10, (void (*)(void *))((u32) &func_ov001_02187d14), (u32) 0, (u8) 6, (u8) 3);
}
