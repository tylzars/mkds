#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020e6fd4.h"

#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_0210c000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
void func_020e730c(void) {
    Unk020e730c *e;
    s32 n;
    s32 i;

    n = ((Unk020e6fd4 *) data_0217b864)->mUnk_04;
    *(void **) data_0217b86c = func_02036bec(func_020364e0(func_020364e8()), n * 4);
    data_0217b868 = func_02036bec(func_020364e0(func_020364e8()), n * 2);
    for (i = 0; i < ((Unk020e6fd4 *) data_0217b864)->mUnk_04; i++) {
        s32 k;

        e = (Unk020e730c *) ((Unk020e6fd4 *) data_0217b864)->mUnk_00[i];
        k = e->mUnk_a0;
        (*(Vec3 ***) data_0217b86c)[k] = &e->mUnk_00.mPos;
        data_0217b868[k] = e->mUnk_a2;
    }
}

void func_020e72cc(Unk020e730c *p, struct Unk020fa294 *q) {
    p->mUnk_a0 = q->mUnk_28;
    switch (data_021759c0->mUnk_010) {
        case 0:
            p->mUnk_a2 = q->mUnk_2a;
            break;
        case 1:
            p->mUnk_a2 = q->mUnk_2c;
            break;
        case 2:
            p->mUnk_a2 = q->mUnk_2e;
            break;
    }
}
#pragma thumb off

void func_020e71a0(MapObject *p) {
    Unk020e71a0_94 *q;
    BOOL a;
    BOOL b;

    q = p->mUnk_94;
    if ((p->mFlags & 2) == 0) {
        q->mUnk_00.mUnk_40 = p->mUnk_78 & ~0xc000001f;
        a = (func_020d4ddc(p) == 0);
        b = (q->mUnk_00.mUnk_34 & 1) != 0;
        if (a != FALSE) {
            if (b != FALSE) {
                goto ret;
            }
            goto call;
        }
    ret:
        if (a != FALSE) {
            return;
        }
        if (b == FALSE) {
            return;
        }
    call:
        func_0210cfbc(&q->mUnk_00, 2, 1);
    } else {
        s32 v;

        v = func_020d4ef4(&p->mPos);
        q->mUnk_00.mUnk_40 = v;
        if (func_020d4d60(p, v) != 0) {
            p->mUnk_78 |= data_02159310;
            if ((q->mUnk_00.mUnk_34 & 1) != 0) {
                func_0210cfbc(&q->mUnk_00, 2, 1);
            }
        } else if ((q->mUnk_00.mUnk_34 & 1) == 0) {
            func_0210cfbc(&q->mUnk_00, 2, 1);
        }
    }
}

void func_020e705c(Unk020e6fd4 *p) {
    MapObject *e;
    Vec3 t;
    void (*cb)(void *p, MapObject *e);
    s32 n;
    void **arr;

    cb = p->mUnk_10;
    n = p->mUnk_04;
    arr = p->mUnk_00;
    if (cb == NULL) {
        s32 i;

        for (i = 0; i < n; i++) {
            e = arr[i];
            if (e->mUnk_94 != NULL) {
                func_020e71a0(e);
            }
        };
        return;
    }
    if (p->mUnk_18 == 2) {
        s32 i;

        for (i = 0; i < n; i++) {
            e = arr[i];
            if ((e->mFlags & 4) == 0) {
                t = e->mPos;
                cb(p, e);
                func_021484d0(&e->mPos, &t, &e->mUnk_10);
                if (e->mUnk_94 != NULL) {
                    func_020e71a0(e);
                }
            }
        };
        return;
    }
    {
        s32 i;

        for (i = 0; i < n; i++) {
            e = arr[i];
            if ((e->mFlags & 4) == 0) {
                cb(p, e);
                if (e->mUnk_94 != NULL) {
                    func_020e71a0(e);
                }
            }
        }
    }
}

void func_020e6fd4(Unk020e6fd4 *p) {
    MapObject *e;
    u8 buf[2];
    s32 i;
    s32 n;
    void **arr;
    s32 (*cb)(MapObject *, void *, void *, void *);

    n = p->mUnk_04;
    cb = p->mUnk_1c;
    arr = p->mUnk_00;
    buf[0] = p->mUnk_20;
    buf[1] = 0;
    if (cb == NULL) {
        return;
    }
    for (i = 0; i < n; i++) {
        e = arr[i];
        if ((e->mFlags & 0x88) == 0) {
            cb(e, NULL, &buf[0], &buf[1]);
        }
    }
}
