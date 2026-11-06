#include "Main/Unknown/code_0203be88.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_0203ba84.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02056444.h"
#include "Main/Unknown/code_020ada2c.h"
#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"
#include "code_0214d93c.h"
#include "Main/Unknown/code_0203d568.h"
#include "Main/Unknown/code_020ad32c.h"
#include "Main/Unknown/code_020ada94.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_02039000.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_02039774.h"
#include "Main/Unknown/code_0204a550.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020ad344.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_0218155c.h"
#include "Main/Unknown/code_0203e74c.h"

void func_0203c1a8(Vec3 *a, u32 b) {
    s32 v;
    if (func_0204176c(a, &v) == 0) {
        return;
    }
    if (v != 0) {
        if (data_021759c0->mMode == MODE_MISSION_RUN) {
            func_ov001_021816fc();
        }
        if (data_021759c0->mMode != MODE_MISSION_RUN) {
            return;
        }
        FinishRaceProgressKartWithEndKind(b, 0);
    } else {
        FinishRaceProgressKartWithEndKind(b, 6);
    }
}

BOOL func_0203c174(void) {
    return gRaceProgress->mFramesSinceFinish > data_021759c0->mUnk_038;
}

u32 func_0203c0bc(void) {
    u32 v;
    s32 i = data_021759c0->mEntryIndex;
    if (i == -1) {
        return 0;
    }
    if (gRaceProgress->mUnk_000[0].mUnk_0a >= 7) {
        return 1;
    }
    if (func_0204a620((Unk02175650 *) &data_02175628[i].mUnk_28) != FALSE) {
        return 1;
    }
    if (TryGetRaceUpdateFramesSinceEntryEnd(&v) != 0) {
        if (v > 0x384) {
            return 1;
        }
    }
    return 0;
}

void func_0203c094(void) {
    GetHeap(func_020364e8());
    func_02039a1c();
    func_020ad344();
    func_02043c14();
}

void func_0203c088(void) {
    u32 value12;
    func_020ad32c();
}

void func_0203c07c(void) {
    u32 value12;
    func_020ada94();
}

void func_0203c060(s32 a) {
    func_02037a40();
    func_020ada2c(a);
}

u32 RunTitleScene(SceneNumbers *a) {
    SceneCallbacks b = data_usa_02164798;
    RunScene(a, &b);
    return 0;
}

void func_0203bfec(s32 *a) {
    if (RTC_GetDate((u32 *) a) != 0) {
        a[0] = 5;
        a[1] = 1;
        a[2] = 1;
    }
}

void func_0203bfc4(Unk0203bfc4 *a) {
    if (RTC_GetTime((u32 *) a) != 0) {
        a->mUnk_00 = 0;
        a->mUnk_04 = 0;
        a->mUnk_08 = 0;
    }
}

void func_0203bf04(Unk0203bf04_a *a, Unk0203bf04_b *b) {
    MI_CpuCopy8(a, b, 0x30);
    MI_CpuCopy8(a->mUnk_030, b->mUnk_230, 0xdcc);
    if (data_0217aa08->mUnk_04->mUnk_004 != 0 && data_0217aa08->mUnk_00->mUnk_31_3 == 0) {
        MI_CpuCopy8(data_0217aa08->mUnk_04->mUnk_008, b->mUnk_030, 0x200);
        b->mUnk_008 |= 2;
    } else {
        MI_CpuFill8(b->mUnk_030, 0, 0x200);
        b->mUnk_008 &= ~2;
    }
    b->mUnk_02f_0 = func_02056208();
}

#pragma thumb on

u8 *func_0203bedc(void *a) {
    Unk0203ba84 *p;
    void *t;
    p = HeapAlloc(a, 0x48);
    t = func_02056444(a);
    p->mUnk_44 = t;
    func_0203bec0((u8 *) p);
    return (u8 *) p;
}

void func_0203bec0(u8 *a) {
    Unk0203ba84 *p = (Unk0203ba84 *) a;
    u8 i;
    p->mUnk_00 = 0;
    p->mUnk_01 = 0;
    for (i = 0; i < 8; i++) {
        p->mUnk_04[i] = -1;
        p->mUnk_24[i] = -1;
    }
}

void func_0203bea4(u8 *a, u32 b, u32 c) {
    Unk0203ba84 *p = (Unk0203ba84 *) a;
    p->mUnk_01 |= 1 << b;
    p->mUnk_04[b] = c;
}

void func_0203be88(u8 *a, u32 b, u32 c) {
    Unk0203ba84 *p = (Unk0203ba84 *) a;
    p->mUnk_00 |= 1 << b;
    p->mUnk_24[b] = c;
}
