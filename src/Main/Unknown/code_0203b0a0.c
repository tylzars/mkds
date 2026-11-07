#include "Main/Unknown/code_0203b0a0.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0202db04.h"
#include "Main/Unknown/code_02045000.h"
#include "Main/Unknown/code_020445f8.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_020563d8.h"
#include "Main/Unknown/code_02056408.h"
#include "Main/Unknown/code_02056700.h"
#include "Main/Unknown/code_02056a7c.h"
#include "Main/Unknown/code_02056b08.h"
#include "Main/Unknown/code_0205928c.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_0204f240.h"
#include "Main/Unknown/code_0203c5f8.h"

void func_0203b598(TimeRecord *a, Unk0217aa1c_144_00 *b, TimeRecord *c) {
    u16 v1 = a->mMillisecond + b->mUnk_00;
    u16 v2 = a->mMinute + b->mUnk_02;
    u16 v3 = a->mSecond + b->mUnk_03;
    u16 d = v1 / 1000;
    if (d != 0) {
        v3 += d;
        v1 -= d * 1000;
    }
    d = v3 / 60;
    if (d != 0) {
        v2 += d;
        v3 -= d * 60;
    }
    if (v2 > 99) {
        v2 = 99;
    }
    c->mMinute = v2;
    c->mSecond = v3;
    c->mMillisecond = v1;
}

void func_0203b4c8(TimeRecord *a) {
    u8 i;
    a->mMinute = 0;
    a->mSecond = 0;
    a->mMillisecond = 0;
    MI_CpuCopy8(data_0217aa08->mUnk_00->mUnk_0c, a->mName, 0x14);
    for (i = 0; i < 4; i++) {
        func_0203b598(a, &data_0217b488->mUnk_98[i], a);
    }
    a->mCharacterIndex = data_0217b488->mUnk_90;
    a->mKartIndex = data_0217b488->mUnk_94;
    a->mUnk_1b = 0;
    a->mCupRank = data_usa_02154064[data_0217b488->mUnk_7c];
    a->mUnk_1d = data_0217b488->mUnk_a8;
    a->mUnk_1e = data_0217b488->mUnk_80;
    a->mFilled = 1;
}

BOOL func_0203b3d8(TimeRecord *a, TimeRecord *b) {
    s32 x;
    s32 y;
    if (b->mCupRank == 3) {
        return FALSE;
    }
    if (a->mFilled == 0) {
        return TRUE;
    }
    if (a->mCupRank > b->mCupRank) {
        return TRUE;
    }
    if (a->mCupRank < b->mCupRank) {
        return FALSE;
    }
    if (a->mUnk_1e < b->mUnk_1e) {
        return TRUE;
    }
    if (a->mUnk_1e > b->mUnk_1e) {
        return FALSE;
    }
    if (a->mUnk_1d < b->mUnk_1d) {
        return TRUE;
    }
    if (a->mUnk_1d > b->mUnk_1d) {
        return FALSE;
    }
    x = a->mSecond * 1000 + a->mMinute * 60000 + a->mMillisecond;
    y = b->mSecond * 1000 + b->mMinute * 60000 + b->mMillisecond;
    return x > y;
}

s32 func_0203b324(void) {
    TimeRecord a;
    TimeRecord b;
    BOOL r = FALSE;
    s32 v;
    Unk0217b488 *p = data_0217b488;
    switch (p->mUnk_88) {
        case 0:
            v = r;
            break;
        case 1:
            v = 1;
            break;
        case 2:
            v = (p->mUnk_8c != 0) ? 3 : 2;
            break;
    }
    func_02056a7c(p->mUnk_84, v, &a);
    func_0203b4c8(&b);
    if (func_0203b3d8(&a, &b) != FALSE) {
        func_02056b08(data_0217b488->mUnk_84, v, &b);
        func_0205641c();
        r = TRUE;
    }
    return r;
}

u32 func_0203b230(void) {
    Unk02056a2c c;
    Unk02056a2c d;
    u32 r = 0;
    s32 a;
    s32 b;
    s32 t;
    BOOL v1;
    a = (gRaceSetup->mMode == MODE_MISSION_RUN) ? gRaceSetup->mMissionTableRow : -1;
    b = (gRaceSetup->mMode == MODE_MISSION_RUN) ? gRaceSetup->mMissionTableColumn : -1;
    t = IsKartEnded((u16) gRaceSetup->mEntryIndex);
    t = (t != 0) ? gRaceProgress->mEntryEndKind : 6;
    if (t != 0) {
        return 0;
    }
    func_020569dc((u16) a, (u16) b, &c);
    d.mUnk_00 = 1;
    d.mUnk_01 = func_0205d140();
    if (c.mUnk_00 == 0) {
        v1 = TRUE;
    } else {
        v1 = c.mUnk_01 < d.mUnk_01;
    }
    if (v1 != FALSE) {
        func_02056a04((u16) a, (u16) b, &d);
        func_020563d8();
        r = 1;
    }
    return r;
}

void func_0203b1fc(void *a) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        func_0204f240(a, 1);
    }
    func_020445f8();
}

void func_0203b1c8(void *a) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        func_0204f240(a, 1);
    }
    func_020594d4();
}

void func_0203b194(void *a) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        func_0204f240(a, 1);
    }
    func_0205949c();
}

void func_0203b0f8(void *a) {
    void *r = NULL;
    s32 t;
    u32 f;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        func_0204f240(a, 1);
    } else {
        r = FindSceneFile(data_usa_0216478c);
    }
    t = data_021759d0->mUnk_20;
    f = 1;
    if (t != 1 && t != 2) {
        f = 0;
    }
    if (f != 0) {
        func_0204e928(a, t == 1, r);
        func_0205982c(a);
    }
    ResetRaceSetup();
}

BOOL func_0203b0a0(const Unk0203b0a0 *a, const Unk0203b0a0 *b) {
    if (a->mUnk_00 < b->mUnk_00) {
        return TRUE;
    }
    if (a->mUnk_00 > b->mUnk_00) {
        return FALSE;
    }
    if (a->mUnk_01 < b->mUnk_01) {
        return TRUE;
    }
    if (a->mUnk_01 > b->mUnk_01) {
        return FALSE;
    }
    return a->mUnk_02 < b->mUnk_02;
}
