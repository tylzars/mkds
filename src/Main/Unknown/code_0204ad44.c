#include "Main/Unknown/code_0204ad44.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020487fc.h"
#include "code_02012b20.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0202f14c.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200eddc.h"
#include "code_0200f5ac.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "code_0214f4a4.h"
#include "code_02017f24.h"
#include "Main/Unknown/code_0204aa60.h"

void func_0204b030(void) {
    u32 value12;
    func_0202f1dc();
}

void func_0204b024(void) {
    u32 value12;
    func_0202f160();
}

void func_0204b018(void *a) {
    func_0202f20c(a);
}

s32 RunWLMenuScene(SceneNumbers *a) {
    SceneCallbacks b = data_usa_021651b0;

    RunScene(a, &b);
    return 0;
}

void func_0204af70(void *a) {
    u8 *b;
    u8 *c;

    b = OS_GetArenaLo(4);
    c = OS_GetArenaHi(4);
    data_021759d0 = HeapAlloc(a, 0x7c);
    data_021759d0->mHeap = FrmHeapCreate(b, c - b, 1);
    func_0204ad44();
}

void func_0204ad44(void) {
    Unk0200fddc v;
    u64 t;
    u64 u;
    Unk021759d0 *p;
    Unk020f41c4_B *q;

    OS_GetOwnerInfo(&v);
    MI_CpuFill8(data_021759d0->mUnk_2a, 0, 0x14);
    data_021759d0->mUnk_3e = v.mUnk_18;
    MI_CpuCopy8(v.mUnk_04, data_021759d0->mUnk_2a, data_021759d0->mUnk_3e << 1);
    data_021759d0->mUnk_40 = v.mUnk_01;
    data_021759d0->mUnk_00 = 1;
    switch (v.mUnk_00) {
        case 1:
            data_021759d0->mUnk_04 = 1;
            break;
        case 2:
            data_021759d0->mUnk_04 = 2;
            break;
        case 3:
            data_021759d0->mUnk_04 = 3;
            break;
        case 4:
            data_021759d0->mUnk_04 = 4;
            break;
        case 5:
            data_021759d0->mUnk_04 = 5;
            break;
        default:
            data_021759d0->mUnk_04 = 1;
            break;
    }
    data_021759d0->mUnk_20 = 0;
    data_021759d0->mUnk_28 = -1;
    data_021759d0->mUnk_44 = -1;
    data_021759d0->mUnk_1c_0 = 0;
    data_021759d0->mUnk_1c_1 = 0;
    data_021759d0->mUnk_58 = 0;
    data_021759d0->mUnk_5c = 0;
    func_02012b20(0);
    data_021759d0->mUnk_1c_3 = 0;
    data_021759d0->mUnk_54 = FALSE;
    data_021759d0->mUnk_50 = 0;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        data_021759d0->mUnk_1c_2 = 1;
    } else {
        data_021759d0->mUnk_1c_2 = 0;
    }
    t = OS_GetTick();
    u = OS_GetTick();
    p = data_021759d0;
    q = &p->mUnk_60;
    q->mUnk_00 = (u32) ((t << 16) + u);
    q->mUnk_08 = 0x5d588b656c078965;
    q->mUnk_10 = 0x269ec3;
    if (PM_GetBackLight(&p->mUnk_48, &p->mUnk_4c) == 0) {
        return;
    }
    func_0204aab4(1, 1);
}
