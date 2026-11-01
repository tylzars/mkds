#include "Main/Unknown/code_0204a550.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/unk_02165000.h"
#include "01/code_021a2398.h"

void func_0204a5e8(void) {
    func_ov001_021a23c0();
}

void func_0204a598(Unk0204a598 *a) {
    s32 r;

    r = func_ov001_021a23c8();
    if (a != 0 && r != 0) {
        switch (a->mUnk_00) {
            case 7:
                a->mUnk_04 = 7;
                break;
            default:
                a->mUnk_04 = 0;
                break;
        }
    }
}

s32 func_0204a550(void *a) {
    Unk021a9034 b = data_02165190;

    func_020487fc(a, &b);
    return 0;
}
