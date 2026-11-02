#include "Main/Unknown/code_020364e0.h"

#include "Main/Unknown/code_020365ac.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/unk_02174000.h"

u32 func_020364f8(Unk02036590 *a, u32 b) {
    u32 c;
    void *d;
    a->mUnk_10 = data_02174e70;
    if (a->mUnk_10 != NULL) {
        d = a->mUnk_10->mUnk_0c;
    } else {
        d = func_020365ac();
    }
    a->mUnk_0c = func_020369fc(d);
    data_02174e70 = a;
    c = ((u32(*)(u32)) a->mUnk_04)(b);
    if (a->mUnk_08 != 0) {
        ((void (*)(void)) a->mUnk_08)();
    }
    data_02174e70 = a->mUnk_10;
    func_02036ab0(a->mUnk_0c);
    a->mUnk_0c = NULL;
    return c;
}

void *func_020364e8(void) {
    return data_02174e70;
}

void *func_020364e0(void *a) {
    return *(void **) ((u8 *) a + 12);
}
