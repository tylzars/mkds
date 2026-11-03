#include "code_0212ee54.h"

#include "code_0200fc8c.h"
#include "code_020172d0.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02003be0.h"
#include "code_0200e77c.h"
#include "code_0212f788.h"
#include "code_0212c7f0.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_02017000.h"
#include "Main/Unknown/unk_0217e000.h"
#include "Main/Unknown/unk_02152000.h"

// Walks the four objects of data_0217e404.
void func_0212f094(void) {
    s32 i;
    s32 a;
    s32 b;
    Unk0212c7f0 *p;

    p = data_0217e404;
    for (i = 0; i < 4; i++, p++) {
        if (!p->mUnk_110_0) {
            continue;
        }
        if (p->mUnk_114 == 0) {
            func_0212efb8(p);
            continue;
        }
        if (p->mUnk_110_2 && p->mUnk_118 != 0) {
            func_0212c948(p);
            p->mUnk_110_1 = 1;
            p->mUnk_110_2 = 0;
        }
        if (p->mUnk_110_1) {
            func_0212f7e0(&p->mUnk_e8);
            a = data_02152ce4[p->mUnk_154];
            b = data_02152ce4[func_0212f7f8(&p->mUnk_e8) >> 8];
            b += a;
            if (b != p->mUnk_158) {
                func_0212c8a4(p, b);
                p->mUnk_158 = b;
            }
            if (p->mUnk_110_3) {
                if (func_0212f7c8(&p->mUnk_e8) != 0) {
                    func_0212efb8(p);
                }
            }
        }
    }
}

// Clears mUnk_14c (and the word it points to) and bits 0, 2 and 1 of mUnk_110.
void func_0212f058(Unk0212c7f0 *a) {
    if (a->mUnk_14c != 0) {
        *a->mUnk_14c = 0;
        a->mUnk_14c = 0;
    }
    a->mUnk_110_0 = 0;
    a->mUnk_110_2 = 0;
    a->mUnk_110_1 = 0;
}

// Brackets func_0212ef48 with func_0200ed34 and func_0200ecc4 on data_0217e3e0 and on mUnk_4cc of data_0217df04.
void func_0212efb8(Unk0212c7f0 *a) {
    func_0200ed34(data_0217e3e0);
    if (data_0217df04 != 0) {
        func_0200ed34(data_0217df04->mUnk_4cc);
    }
    if (a->mUnk_110_1) {
        func_0212c918(a);
    }
    if (a->mUnk_110_0) {
        FS_CancelFile(&a->mUnk_5c);
    }
    func_0212ef48(a);
    func_0200ecc4(data_0217e3e0);
    if (data_0217df04 != 0) {
        func_0200ecc4(data_0217df04->mUnk_4cc);
    }
}

// If bit 0 of mUnk_110 is set: runs func_0212ef00, FS_CloseFile, and func_0212ee8c on data_0217e3f8 and
// mUnk_4e4 of data_0217df04, then func_0212f058.
void func_0212ef48(Unk0212c7f0 *a) {
    if (!a->mUnk_110_0) {
        return;
    }
    func_0212ef00(a);
    FS_CloseFile(&a->mUnk_5c);
    func_0212ee8c(&data_0217e3f8, a);
    if (data_0217df04 != 0) {
        func_0212ee8c(&data_0217df04->mUnk_4e4, a);
    }
    func_0212f058(a);
}

// Lowers mUnk_120 when it is not 0 and calls func_0212c9a4 when it reaches 0.
void func_0212ef00(Unk0212c7f0 *a) {
    if (a->mUnk_120 == 0) {
        return;
    }
    a->mUnk_120 = a->mUnk_120 - 1;
    if (a->mUnk_120 != 0) {
        return;
    }
    func_0212c9a4(a);
}

// Unlinks every element of the list whose mUnk_08 is b and passes it to func_0212ee54.
void func_0212ee8c(Unk02017328 *a, void *b) {
    u32 v;
    Unk0212ee8c *p;
    Unk0212ee8c *next;

    v = func_0200fca0();
    p = func_0201733c(a, 0);
    if (p != 0) {
        do {
            next = func_0201733c(a, p);
            if (p->mUnk_08 == b) {
                func_02017354(a, p);
                func_0212ee54(p);
            }
            p = next;
        } while (p != 0);
    }
    func_0200fcb4(v);
}

u32 func_0212ee54(void *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value4;
    u32 value5;
    value5 = value0;
    value0 = (u32) func_0200fca0();
    value4 = value0;
    value0 = (u32) &data_0217df08;
    value1 = value5;
    func_020174a4((Unk02017328 *) value0, (void *) value1);
    value0 = value4;
    value0 = (u32) func_0200fcb4(value0);
    return value0;
}
