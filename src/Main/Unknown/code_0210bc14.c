#include "Main/Unknown/code_0210bc14.h"

#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0210bafc.h"
#include "code_0212da38.h"
#include "code_020172d0.h"

u32 func_0210bc8c(int a, int b) {
    BOOL i;
    Unk0210bc54 *p;

    p = (Unk0210bc54 *) (b + ((Unk02017328 *) a)->mUnk_0a);
    if (p->mUnk_08 != 0) {
        i = FALSE;
    } else {
        i = TRUE;
        p->mUnk_08 = (u32) a;
    }
    if (i != FALSE) {
        func_020174a4((Unk02017328 *) a, (void *) b);
    } else {
        return 0;
    }
    return 1;
}

void func_0210bc54(Unk02017328 *a, void *b) {
    Unk0210bc54 *p;

    func_02017354(a, b);
    p = (Unk0210bc54 *) ((u8 *) b + a->mUnk_0a);
    if (p->mUnk_08 != 0) {
        p->mUnk_08 = 0;
    }
}

void func_0210bc14(void) {
    __clear(data_0217cd30, 0x17 * sizeof(Unk0217cd30));
}
