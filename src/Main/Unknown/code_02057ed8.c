#include "Main/Unknown/code_02057ed8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200db4c.h"

void (*func_02057f8c(Unk0217aa0c *a))(void) {
    void (**q)(void) = NULL;
    void (*r)(void) = NULL;
    s32 i = 0;
    s32 d;
    u8 c = a->mUnk_28;
    do {
        d = c - i;
        if (d < 0) {
            d += 10;
        }
        if (a->mUnk_00[d] == NULL) {
            break;
        }
        i++;
        q = &a->mUnk_00[d];
    } while (i < 10);
    if (q != NULL) {
        r = *q;
        *q = NULL;
    }
    return r;
}

void func_02057ed8(void *a) {
    Unk0217aa0c *p;
    s32 i;
    data_0217aa0c = HeapAlloc(a, 0xfc);
    data_0217aa0c->mUnk_f4 = HeapAllocAligned(a, 0x800, 0x20);
    ThreadInit(&data_0217aa0c->mUnk_2c, func_02057e8c, NULL, (u8 *) data_0217aa0c->mUnk_f4 + 0x800, 0x800, 0x11);
    ThreadSetRunnable(&data_0217aa0c->mUnk_2c);
    data_0217aa0c->mUnk_f8 = 0;
    p = data_0217aa0c;
    for (i = 0; i < 10; i++) {
        p->mUnk_00[i] = NULL;
    }
    p->mUnk_28 = 0;
}
