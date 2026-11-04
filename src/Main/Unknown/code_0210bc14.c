#include "Main/Unknown/code_0210bc14.h"

#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0210bafc.h"
#include "code_0212da38.h"
#include "code_020172d0.h"

u32 func_0210bc8c(int a, int b) {
    BOOL i;
    Unk0210bc54 *p;

    p = (Unk0210bc54 *) (b + ((LinkedList *) a)->mLinkOffset);
    if (p->mUnk_08 != 0) {
        i = FALSE;
    } else {
        i = TRUE;
        p->mUnk_08 = (u32) a;
    }
    if (i != FALSE) {
        ListAppend((LinkedList *) a, (void *) b);
    } else {
        return 0;
    }
    return 1;
}

void func_0210bc54(LinkedList *a, void *b) {
    Unk0210bc54 *p;

    ListRemove(a, b);
    p = (Unk0210bc54 *) ((u8 *) b + a->mLinkOffset);
    if (p->mUnk_08 != 0) {
        p->mUnk_08 = 0;
    }
}

void func_0210bc14(void) {
    __clear(data_0217cd30, 0x17 * sizeof(Unk0217cd30));
}
