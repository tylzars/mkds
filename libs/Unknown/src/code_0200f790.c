#include "code_0200f790.h"

#include "code_0200c914.h"
#include "code_0200f5ac.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/unk_02170000.h"
#include "code_0200f580.h"

void OS_InitVAlarm(void) {
    if (data_02170268 != 0) {
        return;
    }
    data_02170268 = 1;
    data_02170274[0] = 0;
    data_02170274[1] = 0;
    InterruptEnableClearBits(4);
    data_02170270 = 0;
    data_0217026c = 0;
}

u16 gAlarmInitialized;
Unk02170260 gAlarmList;

void StartAlarmTimer(Unk0200fb08 *n) {
    u64 t;
    s64 d;
    u16 v;

    t = OS_GetTick();
    *(vu16 *) 0x4000106 = 0;
    d = n->mUnk_0c - t;
    func_0200cb50(1, AlarmTimerCallback, 0);
    if (d < 0) {
        v = 0xfffe;
    } else if (d < 0x10000) {
        v = ~d;
    } else {
        v = 0;
    }
    *(vu16 *) 0x4000104 = v;
    *(vu16 *) 0x4000106 = 0xc1;
    InterruptEnableSetBits(0x10);
}

void OS_InitAlarm(void) {
    if (gAlarmInitialized != 0) {
        return;
    }
    gAlarmInitialized = 1;
    func_0200f580(1);
    gAlarmList.mUnk_00 = 0;
    gAlarmList.mUnk_04 = 0;
    InterruptEnableClearBits(0x10);
}

u32 OS_IsAlarmAvailable(void) {
    u32 value0;
    value0 = (u32) &gAlarmInitialized;
    value0 = (u32) * (const u16 *) ((value0) + (0));
    return value0;
}

void OS_CreateAlarm(Unk0200fb08 *n) {
    n->mUnk_00 = 0;
    n->mUnk_08 = 0;
}

void AddAlarmToList(Unk0200fb08 *n, u64 t) {
    Unk0200fb08 *p;
    u64 c;

    if (n->mUnk_1c != 0) {
        c = OS_GetTick();
        t = n->mUnk_24;
        if (t < c) {
            t = t + n->mUnk_1c * ((c - t) / n->mUnk_1c + 1);
        }
    }
    n->mUnk_0c = t;
    for (p = gAlarmList.mUnk_00; p != 0; p = p->mUnk_18) {
        if ((s64) (t - p->mUnk_0c) < 0) {
            n->mUnk_14 = p->mUnk_14;
            p->mUnk_14 = n;
            n->mUnk_18 = p;
            if (n->mUnk_14 != 0) {
                n->mUnk_14->mUnk_18 = n;
                return;
            }
            gAlarmList.mUnk_00 = n;
            StartAlarmTimer(n);
            return;
        }
    }
    n->mUnk_18 = 0;
    p = gAlarmList.mUnk_04;
    gAlarmList.mUnk_04 = n;
    n->mUnk_14 = p;
    if (p != 0) {
        p->mUnk_18 = n;
        return;
    }
    gAlarmList.mUnk_04 = n;
    gAlarmList.mUnk_00 = n;
    StartAlarmTimer(n);
}

void OS_SetAlarm(Unk0200fb08 *n, u64 a, void (*f)(void *), void *p) {
    u32 s;

    if (n == 0 || n->mUnk_00 != 0) {
        IrqDisableLoopForever();
    }
    s = IrqDisable();
    n->mUnk_1c = 0;
    n->mUnk_00 = f;
    n->mUnk_04 = p;
    AddAlarmToList(n, a + OS_GetTick());
    IrqRestore(s);
}

void OS_CancelAlarm(Unk0200fb08 *n) {
    u32 s;
    Unk0200fb08 *next;

    s = IrqDisable();
    if (n->mUnk_00 == 0) {
        IrqRestore(s);
        return;
    }
    next = n->mUnk_18;
    if (next == 0) {
        gAlarmList.mUnk_04 = n->mUnk_14;
    } else {
        next->mUnk_14 = n->mUnk_14;
    }
    if (n->mUnk_14 != 0) {
        n->mUnk_14->mUnk_18 = next;
    } else {
        gAlarmList.mUnk_00 = next;
        if (next != 0) {
            StartAlarmTimer(next);
        }
    }
    n->mUnk_00 = 0;
    n->mUnk_1c = 0;
    IrqRestore(s);
}

void AdvanceAlarmList(void) {
    Unk0200fb08 *n;
    Unk0200fb08 *next;
    void (*f)(void *);
    u64 c;

    *(vu16 *) 0x4000106 = 0;
    InterruptEnableClearBits(0x10);
    *(u32 *) ((u8 *) &data_027e0000 + 0x3ff8) |= 0x10;
    c = OS_GetTick();
    n = gAlarmList.mUnk_00;
    if (n == 0) {
        return;
    }
    if (c < n->mUnk_0c) {
        StartAlarmTimer(n);
        return;
    }
    next = n->mUnk_18;
    gAlarmList.mUnk_00 = next;
    if (next == 0) {
        gAlarmList.mUnk_04 = 0;
    } else {
        next->mUnk_14 = 0;
    }
    f = n->mUnk_00;
    if (n->mUnk_1c == 0) {
        n->mUnk_00 = 0;
    }
    if (f != 0) {
        f(n->mUnk_04);
    }
    if (n->mUnk_1c != 0) {
        n->mUnk_00 = f;
        AddAlarmToList(n, 0);
    }
    if (gAlarmList.mUnk_00 != 0) {
        StartAlarmTimer(gAlarmList.mUnk_00);
    }
}

// clang-format off
// Calls AdvanceAlarmList and returns.
// Not compiled code: its only call is in tail position, which 1.2 builds as `ldr ip, =callee; bx ip`
// (docs/compiler.md), not as a `bl` inside a frame.
asm void AlarmTimerCallback(void) {
    stmdb sp!, {lr}
    bl AdvanceAlarmList
    ldmia sp!, {lr}
    bx lr
}
// clang-format on
