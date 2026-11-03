#include "Main/Unknown/code_020307b8.h"
#include "Main/Unknown/code_0203003c.h"
#include "Main/Unknown/code_02030a10.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_021281b4.h"
#include "code_02148ca0.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02163000.h"
#include "Main/Unknown/unk_02174000.h"
#include "code_02016468.h"
#include "code_0214d018.h"

#pragma optimize_for_size on

#pragma thumb on

void func_020307b8(void *a, void *b, void *c) {
    void *h;
    Unk02174e54 *o;
    Unk02153d2c *q;
    s32 i;
    u32 n;
    s32 x;

    h = func_02036948(a);
    data_02174e54 = func_02036bec(h, 0x40);
    func_0203091c(data_02174e54, 0x40);
    data_02174e54->mUnk_3c = h;
    data_02174e54->mUnk_1c = b;
    data_02174e54->mUnk_20 = c;
    data_02174e54->mUnk_24 = FindSceneFile(data_0216362c);
    data_02174e54->mUnk_38 = -0xc0;
    n = func_02148ca0();
    o = data_02174e54;
    LocateNcgr2(&o->mUnk_00, FindSceneFile(data_02163638));
    LocateNcer(&o->mUnk_08, FindSceneFile(data_02163654));
    LocateNclr(&o->mUnk_04, FindSceneFile(data_02163670));
    o->mUnk_0c = FindSceneFile(data_0216368c);
    o->mUnk_10 = FindSceneFile(data_021636a4);
    o->mUnk_14 = FindSceneFile(data_021636bc);
    func_02124ed0(data_02174e54->mUnk_3c, o->mUnk_0c, o->mUnk_14, &o->mUnk_18);
    for (i = 0; i < 2; i++) {
        q = &data_02153d2c[i];
        x = q->mUnk_00;
        n -= func_021243ac(data_02174e54->mUnk_3c, x, o->mUnk_14, q->mUnk_02, q->mUnk_04, q->mUnk_06, o->mUnk_08,
                           o->mUnk_0c, o->mUnk_18, n);
        func_0212426c(1, x, o->mUnk_14, GetBmgEntry(data_02174e54->mUnk_24, q->mUnk_08), o->mUnk_0c, o->mUnk_18);
    }
    func_02016468(0x23, 0, o->mUnk_00->mUnk_14, o->mUnk_00->mUnk_10);
    func_02016468(0x1e, 0, o->mUnk_04->mUnk_0c, o->mUnk_04->mUnk_08);
    func_02030954(1);
    func_021281c8(0xe);
    func_0204f804();
    func_02036820(data_02174e54->mUnk_3c);
}

#pragma thumb off

void func_0203091c(void *a, u32 b) {
    func_02030930(a, 0, b);
}

void func_02030930(void *a, u32 b, u32 c) {
    volatile u32 v = b;
    func_0214d05c(v, a, c);
}

#pragma thumb on

void func_02030954(s32 a) {
    u32 t[2];
    s32 i;
    Unk02174e54 *o;
    s32 v;
    s32 w;
    BOOL z1;
    BOOL z2;
    u16 *q;
    u32 c;
    u32 d;

    o = data_02174e54;
    c = *(volatile u32 *) &data_02163614[0];
    d = *(volatile u32 *) &data_02163614[1];
    t[0] = c;
    t[1] = d;
    z1 = FALSE;
    z2 = FALSE;
    for (i = 0; i < 2; i++) {
        if (data_02174e54->mUnk_28 == i && a != 0) {
            v = 1;
        } else {
            v = z1;
        }
        q = data_02153d20[i];
        o->mUnk_18[q[0]].mUnk_00 = v;
        if (v == 0) {
            w = 1;
        } else {
            w = z2;
        }
        o->mUnk_18[q[1]].mUnk_00 = w;
        func_02124100(q[2], (u8) t[v], o->mUnk_14, o->mUnk_18, o->mUnk_0c);
    }
}

void func_020309d8(void) {
    Unk02174e54 *o;
    s32 i;
    s32 n;

    o = data_02174e54;
    n = func_02030a18((u32) o->mUnk_0c) + func_02030a10((u32) o->mUnk_14);
    for (i = 0; i < n; i++) {
        o->mUnk_18[i].mUnk_06 = data_02174e54->mUnk_38;
    }
}

#pragma thumb off
