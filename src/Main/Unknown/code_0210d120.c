#include "Main/Unknown/code_0210d120.h"
#include "Main/Unknown/code_0210bc14.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210c1b0.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0212c6ac.h"
#include "code_0212c478.h"
#include "code_020172d0.h"

void func_0210d2cc(void) {
    Unk02017328 *l;
    u32 t;
    Unk0210bf24 *q;
    Unk02017328 *m;
    Unk0210bfbc *p;

    if (data_0217d084.mUnk_10 == 0) {
        return;
    }
    if (data_0217d020 != 0) {
        for (p = data_0217d028.mUnk_00; p != 0; p = func_0201733c(&data_0217d028, p)) {
            func_0210cc3c(p);
        }
        data_0217d020 = 0;
    }
    func_0210e280((Unk0217c7c4 *) data_0217d034);
    l = data_0217d048;
    for (p = l->mUnk_00; p != 0; p = l->mUnk_00) {
        func_0210ca4c(p);
        if (p->mUnk_18 != 3) {
            func_0210bc54(&l[p->mUnk_18], p);
            p->mUnk_18 = 3;
        }
    }
    m = (Unk02017328 *) data_0217d054;
    p = m->mUnk_00;
    t = data_0217d024[0];
    if (p != 0) {
        l = data_0217d048;
        do {
            if ((t++ & 3) == data_0217d010[0]) {
                func_0210ca4c(p);
            } else if ((t & 1) == (data_0217d010[0] & 1)) {
                for (q = p->mUnk_0c.mUnk_00; q != 0; q = func_0201733c(&p->mUnk_0c, q)) {
                    if (q->mUnk_00 != 0) {
                        p->mUnk_30(p, q, 0);
                    }
                }
            }
            if (p->mUnk_18 != 3) {
                func_0210bc54(&l[p->mUnk_18], p);
                p->mUnk_18 = 3;
            }
            p = m->mUnk_00;
        } while (p != 0);
    }
    data_0217d010[0]++;
    if (data_0217d010[0] == 4) {
        data_0217d010[0] = 0;
    }
    data_0217d024[0] = 0;
}

void func_0210d200(u32 a) {
    Unk0210bfbc *p;
    Unk0210bf24 *q;

    p = data_0217d028.mUnk_00;
    if (p == 0) {
        return;
    }
    do {
        q = p->mUnk_0c.mUnk_00;
        if (q != 0) {
            do {
                func_0212c6f0(&q->mUnk_00, a);
                q->mUnk_19 &= ~4;
                q->mUnk_19 &= ~8;
                q->mUnk_19 &= ~2;
                func_0210bc54(&p->mUnk_0c, q);
                q = p->mUnk_0c.mUnk_00;
            } while (q != 0);
        }
        if (p->mUnk_18 != 3) {
            func_0210bc54(&data_0217d048[p->mUnk_18], p);
            p->mUnk_18 = 3;
        }
        p = func_0201733c(&data_0217d028, p);
    } while (p != 0);
}

void func_0210d1a4(s32 a, s32 b) {
    u8 *p;
    s32 i;

    p = ((Unk0217c7c4 *) data_0217d034)->mUnk_0c;
    for (i = 0; i < ((Unk0217c7c4 *) data_0217d034)->mUnk_00; i++) {
        func_0212c620(&((Unk0210bf24 *) p)->mUnk_00, a, b);
        p += ((Unk0217c7c4 *) data_0217d034)->mUnk_10;
    }
}

void func_0210d120(u32 a) {
    u8 *p;
    s32 i;

    p = ((Unk0217c7c4 *) data_0217d034)->mUnk_0c;
    for (i = 0; i < ((Unk0217c7c4 *) data_0217d034)->mUnk_00; i++) {
        func_0212c6f0(&((Unk0210bf24 *) p)->mUnk_00, a);
        ((Unk0210bf24 *) p)->mUnk_19 &= ~4;
        ((Unk0210bf24 *) p)->mUnk_19 &= ~8;
        ((Unk0210bf24 *) p)->mUnk_19 &= ~2;
        p += ((Unk0217c7c4 *) data_0217d034)->mUnk_10;
    }
}
