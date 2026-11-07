#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/code_020ae000.h"

#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020d0108.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020c70ec.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020c5db0.h"
#include "Main/Unknown/code_020c70d8.h"
#include "Main/Unknown/code_02044000.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020c7000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_021000d0.h"

void func_020d0e28(void) {
    u32 value0;
    u32 value12;
    value0 = (u32) &data_0217b4a0;
    ClearRaceHudSubScreenCells((RaceHudSubScreenCells **) value0);
}

void func_020d0cd8(void) {
    s32 i;
    s32 n;
    BOOL v;
    u32 a;
    Unk0217b498_00 *e;
    Vec3 *p;

    n = 0;
    a = func_020c0db0();
    data_0217b4a0->mUnk_0c->mUnk_04++;
    if (data_0217b4a0->mUnk_0c->mUnk_04 < 0 || data_0217b4a0->mUnk_0c->mUnk_04 >= 0x14) {
        data_0217b4a0->mUnk_0c->mUnk_04 = 0;
    }
    v = data_0217b4a0->mUnk_0c->mUnk_04 < 10;
    for (i = 0; i < data_0217b4a0->mObjectCount; i++) {
        e = data_0217b4a0->mObjects[i];
        p = &e->mPos;
        if (ComputeRaceHudSubScreenPosition(p, (UnkPair020b502c *) &data_0217b4a0->mCells[n], a, 1, 1) == FALSE) {
            continue;
        }
        data_0217b4a0->mCells[n].mUnk_08 = GetRaceSNcerEntry(v != FALSE ? 0xa5 : 0xa6);
        data_0217b4a0->mCells[n].mUnk_0c = 1;
        data_0217b4a0->mCells[n].mUnk_0e = 0;
        data_0217b4a0->mCells[n].mUnk_10 = e->mAngle;
        n++;
    }
    data_0217b4a0->mCellCount = n;
}

void func_020d0cbc(void *a) {
    DrawRaceHudSubScreenCells(a, data_0217b4a0, 1);
}

void func_020d0bd0(void) {
    u16 i;

    data_0217b49c = HeapAlloc(GetHeap(func_020364e8()), 0xb0);
    data_0217b49c->mUnk_00.mUnk_00[0] = 0;
    data_0217b49c->mUnk_00.mUnk_00[1] = 0;
    data_0217b49c->mUnk_00.mUnk_00[2] = 0;
    data_0217b49c->mUnk_00.mUnk_00[3] = 0;
    data_0217b49c->mUnk_00.mUnk_00[4] = 0;
    data_0217b49c->mUnk_00.mUnk_00[5] = 0;
    data_0217b49c->mUnk_00.mUnk_00[6] = 0;
    for (i = 0; i < 5; i++) {
        data_0217b49c->mUnk_1c[i].mUnk_00[0] = 0;
        data_0217b49c->mUnk_1c[i].mUnk_00[1] = 0;
        data_0217b49c->mUnk_1c[i].mUnk_00[2] = 0;
        data_0217b49c->mUnk_1c[i].mUnk_00[3] = 0;
        data_0217b49c->mUnk_1c[i].mUnk_00[4] = 0;
        data_0217b49c->mUnk_1c[i].mUnk_00[5] = 0;
        data_0217b49c->mUnk_1c[i].mUnk_00[6] = 0;
    }
    data_0217b49c->mUnk_a8 = 0;
    data_0217b49c->mUnk_ac = 0;
}

u32 func_020d0bbc(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b49c;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void func_020d0a18(void) {
    u8 a;
    u8 b;
    u16 c;
    u16 i;
    s32 v;

    if (data_021759c0->mMode != MODE_GRAND_PRIX && data_021759c0->mMode != MODE_TIME_ATTACK) {
        return;
    }
    GetKartFinishTime(func_020b4d9c(), &a, &b, &c);
    SplitTimeDigits(a, b, c, &data_0217b49c->mUnk_00);
    for (i = 0; i < func_02044618(); i++) {
        GetKartLapTime(func_020b4d9c(), i + 1, &a, &b, &c);
        SplitTimeDigits(a, b, c, &data_0217b49c->mUnk_1c[i]);
    }
    if (data_021759c0->mMode != MODE_TIME_ATTACK) {
        return;
    }
    if (func_020c7148() == 0 && func_020c70ec() == 0) {
        return;
    }
    data_0217b49c->mUnk_a8++;
    if (data_0217b49c->mUnk_a8 >= 0x10) {
        data_0217b49c->mUnk_a8 = 0;
    }
    v = data_0217b49c->mUnk_a8 % 16;
    if (v < 4) {
        data_0217b49c->mUnk_ac = 0;
        return;
    }
    if (v < 8) {
        data_0217b49c->mUnk_ac = 0xd;
        return;
    }
    if (v < 12) {
        data_0217b49c->mUnk_ac = 0x1a;
    } else {
        data_0217b49c->mUnk_ac = 0xd;
    }
}

void func_020d06b8(Unk020d029c *a) {
    Unk020224e0_c *c;
    s32 q[4][2];
    s32 t[6];
    u16 i;
    s32 n;
    s32 j;
    s32 k;

    n = func_020c5db0();
    if (data_021759c0->mMode != MODE_GRAND_PRIX && data_021759c0->mMode != MODE_TIME_ATTACK) {
        return;
    }
    if (data_021759c0->mUnk_00c == 4 || data_021759c0->mUnk_00c == 1) {
        return;
    }
    if (func_020c70bc() != 0) {
        c = GetRaceGoalMNcerEntry(0x43);
        q[0][0] = 0x80000;
        q[0][1] = 0x60000;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q[0], 0, 1);
    }
    if (n <= 0) {
        return;
    }
    for (i = 0; i < 6; i++) {
        t[i] = InterpolateS16(1, 0x80, 0, n - i * 4, 0x14);
    }
    c = GetRaceGoalMNcerEntry((func_020c7148() != 0 ? data_0217b49c->mUnk_ac : 0) + 0x15);
    q[1][0] = (t[0] + 0xa2) << 12;
    q[1][1] = 0x10000;
    a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q[1], 0, 1);
    func_020d029c(a, t[0], 0x10, &data_0217b49c->mUnk_00, func_020c7148() != 0 ? data_0217b49c->mUnk_ac : 0);
    c = GetRaceGoalMNcerEntry((func_020c70ec() != 0 ? data_0217b49c->mUnk_ac : 0) + 0x16);
    q[2][0] = (t[1] + 0x99) << 12;
    q[2][1] = 0x28000;
    a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q[2], 0, 1);
    for (i = 0; i < func_02044618(); i++) {
        j = 0;
        if (func_020c70ec() != 0 && i + 1 == func_020c70d8()) {
            j = data_0217b49c->mUnk_ac;
        }
        c = GetRaceGoalMNcerEntry(i + 0x18 + j);
        k = i * 16 + 0x28;
        q[3][0] = (t[i + 1] + 0x9e) << 12;
        q[3][1] = k << 12;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q[3], 0, 1);
        func_020d029c(a, t[i + 1], k, &data_0217b49c->mUnk_1c[i], j);
    }
}

void func_020d029c(Unk020d029c *a, s32 b, s32 d, TimeDigits *e, s32 f) {
    Unk020224e0_c *c;
    s32 p0[2];
    s32 p1[2];
    s32 p2[2];
    s32 p3[2];
    s32 p4[2];
    s32 p5[2];
    s32 p6[2];
    s32 p7[2];
    s32 p8[2];
    s32 t[9] = {170, 179, 188, 198, 207, 216, 226, 235, 244};

    if (e->mUnk_00[0] != 0) {
        c = GetRaceGoalMNcerEntry(e->mUnk_00[0] + 0x17 + f);
        p0[0] = (b + t[0]) << 12;
        p0[1] = d << 12;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, p0, 0, 1);
    }
    c = GetRaceGoalMNcerEntry(e->mUnk_00[1] + 0x17 + f);
    p1[0] = (b + t[1]) << 12;
    p1[1] = d << 12;
    a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, p1, 0, 1);
    c = GetRaceGoalMNcerEntry(f + 0x21);
    p2[0] = (b + t[2]) << 12;
    p2[1] = d << 12;
    a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, p2, 0, 1);
    c = GetRaceGoalMNcerEntry(e->mUnk_00[2] + 0x17 + f);
    p3[0] = (b + t[3]) << 12;
    p3[1] = d << 12;
    a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, p3, 0, 1);
    c = GetRaceGoalMNcerEntry(e->mUnk_00[3] + 0x17 + f);
    p4[0] = (b + t[4]) << 12;
    p4[1] = d << 12;
    a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, p4, 0, 1);
    c = GetRaceGoalMNcerEntry(f + 0x21);
    p5[0] = (b + t[5]) << 12;
    p5[1] = d << 12;
    a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, p5, 0, 1);
    c = GetRaceGoalMNcerEntry(e->mUnk_00[4] + 0x17 + f);
    p6[0] = (b + t[6]) << 12;
    p6[1] = d << 12;
    a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, p6, 0, 1);
    c = GetRaceGoalMNcerEntry(e->mUnk_00[5] + 0x17 + f);
    p7[0] = (b + t[7]) << 12;
    p7[1] = d << 12;
    a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, p7, 0, 1);
    c = GetRaceGoalMNcerEntry(e->mUnk_00[6] + 0x17 + f);
    p8[0] = (b + t[8]) << 12;
    p8[1] = d << 12;
    a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, p8, 0, 1);
}

s32 func_020d0280(void) {
    return CreateRaceHudSubScreenCells(&data_0217b498, MAP_OBJECT_KIND_BERRY);
}

void func_020d026c(void) {
    u32 value0;
    u32 value12;
    value0 = (u32) &data_0217b498;
    ClearRaceHudSubScreenCells((RaceHudSubScreenCells **) value0);
}

void func_020d0150(void) {
    s32 i;
    s32 n;
    u32 a;
    Unk0217b498_00 *e;
    Vec3 *p;

    n = 0;
    a = func_020c0db0();
    for (i = 0; i < data_0217b498->mObjectCount; i++) {
        e = data_0217b498->mObjects[i];
        p = &e->mPos;
        if (ComputeRaceHudSubScreenPosition(p, (UnkPair020b502c *) &data_0217b498->mCells[n], a, 1, 1) == FALSE) {
            continue;
        }
        data_0217b498->mCells[n].mUnk_08 = GetRaceSNcerEntry(0xb8);
        data_0217b498->mCells[n].mUnk_0c = func_020b4e70(p) != 0 ? 2 : 3;
        data_0217b498->mCells[n].mUnk_10 = e->mAngle;
        data_0217b498->mUnk_0c[n].mUnk_00 = e->mUnk_1c / 6;
        n++;
    }
    data_0217b498->mCellCount = n;
}

void func_020d0134(void *a) {
    DrawRaceHudSubScreenCellsScaled(a, data_0217b498, 1);
}

s32 func_020d011c(void) {
    return CreateRaceHudSubScreenCells(&data_0217b494, MAP_OBJECT_KIND_CREAM);
}

void func_020d0108(void) {
    u32 value0;
    u32 value12;
    value0 = (u32) &data_0217b494;
    ClearRaceHudSubScreenCells((RaceHudSubScreenCells **) value0);
}

void func_020cffec(void) {
    s32 i;
    s32 n;
    s32 v;
    Unk0217b498_00 *e;
    Vec3 *p;

    n = 0;
    v = func_020c0db0();
    for (i = 0; i < data_0217b494->mObjectCount; i++) {
        e = data_0217b494->mObjects[i];
        p = &e->mPos;
        if (ComputeRaceHudSubScreenPosition(p, &data_0217b494->mCells[n].mUnk_00, v, 1, 1) != FALSE) {
            data_0217b494->mCells[n].mUnk_08 = GetRaceSNcerEntry(0xb7);
            data_0217b494->mCells[n].mUnk_0c = func_020b4e70(p) != 0 ? 2 : 3;
            data_0217b494->mCells[n].mUnk_10 = e->mAngle;
            data_0217b494->mUnk_0c[n].mUnk_00 = e->mUnk_1c / 6;
            n++;
        }
    }
    data_0217b494->mCellCount = n;
}

void func_020cffd0(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCellsScaled(a, data_0217b494, 1);
}
