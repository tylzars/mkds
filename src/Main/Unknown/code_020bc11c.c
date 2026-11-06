#include "Main/Unknown/code_020bc11c.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020b19b4.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b1000.h"
#include "Main/Unknown/code_020b19f8.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020b85dc.h"
#include "code_020222ec.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020b1cf4.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/code_020b6e00.h"
#include "Main/Unknown/code_020b8000.h"
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_020be7fc.h"
#include "Main/Unknown/code_020be930.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"

void func_020be930(int a) {
    data_0217b3d8->mUnk_0fc[a].mUnk_00 = 0;
}

void func_020be8e4(s32 i, s32 a, s32 b) {
    data_0217b3d8->mUnk_0fc[i].mUnk_00 = 1;
    data_0217b3d8->mUnk_0fc[i].mUnk_04 = a;
    data_0217b3d8->mUnk_0fc[i].mUnk_08 = b;
}

void func_020be7fc(void) {
    u8 i;

    data_0217b3d8 = HeapAlloc(GetHeap(func_020364e8()), 0x15c);
    for (i = 0; i < (s32) data_021759c0->mKartCount; i++) {
        data_0217b3d8->mUnk_080[i] = 1;
        data_0217b3d8->mUnk_060[i] = data_0217b3d8->mUnk_080[i];
        data_0217b3d8->mUnk_0a0[i] = 0;
        data_0217b3d8->mUnk_0c0[i] = 0;
    }
    data_0217b3d8->mUnk_0e0 = 0;
    data_0217b3d8->mUnk_0e4 = 0;
    data_0217b3d8->mUnk_0e8[0] = 0xc4e;
    data_0217b3d8->mUnk_0e8[1] = 0;
    data_0217b3d8->mUnk_0e8[2] = 0;
    data_0217b3d8->mUnk_0e8[3] = 0xc4e;
    data_0217b3d8->mUnk_0f8 = 0;
}

u32 func_020be7e8(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b3d8;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void func_020be3e4(void) {
    Unk0217b3d8_00 t[9] = {{0x1b, 0xf},  {0x1b, 0xf},  {0x1b, 0x26}, {0x1b, 0x3d}, {0x1b, 0x54},
                           {0x1b, 0x6b}, {0x1b, 0x82}, {0x1b, 0x99}, {0x1b, 0xb0}};
    Unk0217b3d8_00 v1;
    Unk0217b3d8_00 v2;
    Unk0217b3d8_00 v3;
    s32 b[8];
    s32 e;
    s32 k;
    u8 i;
    KartItems *o;

    e = data_0217b3d8->mUnk_0f8;
    if (GetRaceStartSequenceFrames() <= 0x188) {
        data_0217b3d8->mUnk_0e0 = (0x20 - (GetRaceStartSequenceFrames() - 0x168)) * 4;
    } else {
        data_0217b3d8->mUnk_0e0 = 0;
    }
    if (GetRaceStartSequenceFrames() < 0x168) {
        return;
    }
    if (data_021759c0->mMode == MODE_TIME_ATTACK) {
        return;
    }
    if (data_021759c0->mMode == MODE_MISSION_RUN) {
        return;
    }
    if (data_021759c0->mMode == MODE_BATTLE) {
        for (i = 0; i < (s32) data_021759c0->mKartCount; i++) {
            data_0217b3d8->mUnk_0c0[i] = GetBalloonOrShineCount(i);
        }
    }
    for (i = 0; i < (s32) data_021759c0->mKartCount; i++) {
        o = &gKartItems[i];
        data_0217b3d8->mUnk_040[i] = o->mHeldItem.mUnk_00 == 0x13 ? o->mActiveItem : o->mHeldItem.mUnk_00;
        if (data_0217b3d8->mUnk_0f8 % 0x1c == 0) {
            data_0217b3d8->mUnk_060[i] = data_0217b3d8->mUnk_080[i];
            data_0217b3d8->mUnk_080[i] = GetKartRank(i);
        }
        v1 = t[data_0217b3d8->mUnk_060[i]];
        v2 = t[data_0217b3d8->mUnk_080[i]];
        if (data_0217b3d8->mUnk_060[i] > data_0217b3d8->mUnk_080[i]) {
            if (e < 10) {
                v3.mUnk_00 = v1.mUnk_00 + (e * 16) / 10;
                v3.mUnk_04 = v1.mUnk_04;
            } else if (e < 0x12) {
                k = e - 10;
                v3.mUnk_00 = v1.mUnk_00 + (v2.mUnk_00 - v1.mUnk_00) * k / 8 + 0x10;
                v3.mUnk_04 = v1.mUnk_04 + (v2.mUnk_04 - v1.mUnk_04) * k / 8;
            } else {
                v3.mUnk_00 = v1.mUnk_00 + 0x10 - ((e - 0x12) * 16) / 10;
                v3.mUnk_04 = v2.mUnk_04;
            }
        } else {
            v3.mUnk_00 = v1.mUnk_00 + e * (v2.mUnk_00 - v1.mUnk_00) / 0x1c;
            v3.mUnk_04 = v1.mUnk_04 + e * (v2.mUnk_04 - v1.mUnk_04) / 0x1c;
        }
        data_0217b3d8->mUnk_000[i] = v3;
    }
    for (i = 0; i < (s32) data_021759c0->mKartCount; i++) {
        data_0217b3d8->mUnk_0a0[i] = i;
        b[i] = data_0217b3d8->mUnk_080[i];
    }
    SortIndicesByKey(data_0217b3d8->mUnk_0a0, b, data_021759c0->mKartCount);
    data_0217b3d8->mUnk_0f8++;
    if (data_0217b3d8->mUnk_0f8 >= 0x1c) {
        data_0217b3d8->mUnk_0f8 = 0;
    }
    for (i = 0; i < (s32) data_021759c0->mKartCount; i++) {
        if (data_0217b3d8->mUnk_0fc[i].mUnk_00 != 0) {
            data_0217b3d8->mUnk_0fc[i].mUnk_00++;
            if (data_0217b3d8->mUnk_0fc[i].mUnk_00 > 0x24) {
                data_0217b3d8->mUnk_0fc[i].mUnk_00 = 0;
            }
        }
    }
}

void func_020be2f4(Unk020d029c *a) {
    s32 *e;
    Unk020224e0_o *p;

    if (GetRaceStartSequenceFrames() < 0x168) {
        return;
    }
    data_0217b3d8->mUnk_0e4 = func_020ae5c4(a);
    switch (data_021759c0->mMode) {
        case MODE_GRAND_PRIX:
        case MODE_VS:
        case 5:
            func_020bd7f8(a);
            break;
        case MODE_BATTLE:
            switch (GetRaceHudSubScreenState()) {
                case 0:
                    func_020bd178(a);
                    break;
                case 1:
                case 2:
                case 3:
                    func_020bcbe8(a);
                    break;
            }
            break;
    }
    e = data_0217b3d8->mUnk_0e8;
    p = &a->mUnk_000[data_0217b3d8->mUnk_0e4 * 4];
    p[0].mUnk_00[3] = e[0] >> 4;
    p[1].mUnk_00[3] = e[1] >> 4;
    p[2].mUnk_00[3] = e[2] >> 4;
    p[3].mUnk_00[3] = e[3] >> 4;
}

u32 func_020be15c(u16 a) {
    u32 r;
    Unk0217b3d8 *d;
    Unk0217b3d8_fc *e;
    s32 v;

    if (func_020b1cf4(a) != 0) {
        r = 0x25;
    } else if (data_021759c0->mMode == MODE_BATTLE && IsKartOnWinningTeamAtEnd(a) != 0) {
        r = 0x24;
    } else if (data_021759c0->mMode == MODE_BATTLE && IsKartEliminated(a) != FALSE) {
        r = 0xc9;
    } else if (data_021759c0->mMode != MODE_BATTLE && IsKartEnded(a) != 0) {
        r = 0x24;
    } else if ((d = data_0217b3d8)->mUnk_0fc[a].mUnk_00 != 0) {
        v = d->mUnk_0fc[a].mUnk_00 - 1;
        if (v % 12 < 6) {
            r = 0xc9;
        } else if ((e = (Unk0217b3d8_fc *) &d->mUnk_0fc[0].mUnk_04)[a].mUnk_00 == 5) {
            switch (d->mUnk_0fc[a].mUnk_08) {
                case 1:
                    r = 0x11;
                    break;
                case 2:
                    r = 0x12;
                    break;
                case 3:
                    r = 0x13;
                    break;
            }
        } else {
            r = LookupRaceSNcerIndex(a, e[a].mUnk_00);
        }
    } else if (d->mUnk_040[a] != 0x13) {
        r = LookupRaceSNcerIndex(a, d->mUnk_040[a]);
    } else if (gKartItems[a].mSlotState == 1) {
        r = 0x16;
    } else {
        r = 0xc9;
    }
    return r;
}

void func_020bdf08(Unk020d029c *a) {
    s32 t[8][2] = {{8, 0xf}, {8, 0x26}, {8, 0x3d}, {8, 0x54}, {8, 0x6b}, {8, 0x82}, {8, 0x99}, {8, 0xb0}};
    u16 i;
    s32 e;
    s32 j;
    s32 v;
    s32 y;
    s32 q1[2];
    s32 q2[2];
    Unk020224e0_c *c;

    e = data_0217b3d8->mUnk_0e0;
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        j = data_0217b3d8->mUnk_060[i] - 1;
        c = GetRaceSNcerEntry(j + 0x35);
        q1[0] = (t[j][0] - e - 1) << 12;
        y = t[j][1];
        q1[1] = (y - 4) << 12;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q1, 0, 1);
        v = 0;
        if (data_021759c0->mMode == MODE_BATTLE && IsKartEliminated(i) != FALSE) {
            v = 1;
        } else if (data_021759c0->mMode != MODE_BATTLE && (func_020b1cf4(i) != 0 || func_0207a84c(i) != 0)) {
            v = 1;
        }
        if (v != 0) {
            v = 3;
        } else if (i == func_020b4d9c()) {
            v = 0;
        } else if (data_021759c0->mUseTeams != 0 && data_021759c0->mCurrentEntries[i].mPlayer.mTeamIndex == 1) {
            v = 2;
        } else {
            v = 1;
        }
        c = GetRaceSNcerEntry(v + 0x75);
        q2[0] = -e << 12;
        q2[1] = y << 12;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q2, 0, 1);
    }
}

void func_020bdb34(Unk020d029c *a) {
    u16 i;
    s32 k;
    Unk0217b3d8_00 p;
    s32 r;
    u16 f;
    s32 *d;
    s32 s;
    s32 q1[2];
    s32 q2[2];
    s32 q3[2];
    s32 q4[2];
    s32 v;
    Unk020224e0_c *c;

    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        k = data_0217b3d8->mUnk_0a0[i];
        p = data_0217b3d8->mUnk_000[k];
        r = func_020be15c(k);
        p.mUnk_00 -= data_0217b3d8->mUnk_0e0;
        if (r != 0xc9) {
            c = GetRaceSNcerEntry(r);
            q1[0] = (p.mUnk_00 + 0x45) << 12;
            q1[1] = p.mUnk_04 << 12;
            a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q1, 0, 1);
        }
        if (data_0217b3d8->mUnk_060[k] > data_0217b3d8->mUnk_080[k]) {
            f = data_0217b3d8->mUnk_0e4;
        } else {
            f = 0;
        }
        if (data_0217b3d8->mUnk_060[k] > data_0217b3d8->mUnk_080[k]) {
            d = data_0217b3d8->mUnk_0e8;
        } else {
            d = NULL;
        }
        c = GetRaceSNcerEntry(k + 8);
        q2[0] = p.mUnk_00 << 12;
        q2[1] = p.mUnk_04 << 12;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, d, q2, f, 1);
        s = 0;
        if (data_021759c0->mMode == MODE_BATTLE && IsKartEliminated((u16) k) != FALSE) {
            s = 1;
        } else if (data_021759c0->mMode != MODE_BATTLE &&
                   (func_020b1cf4((u16) k) != 0 || func_0207a84c((u16) k) != 0)) {
            s = 1;
        }
        s = s != 0 ? 0x6d : 0x65;
        c = GetRaceSNcerEntry(s + k);
        q3[0] = (p.mUnk_00 + 0xa) << 12;
        q3[1] = p.mUnk_04 << 12;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q3, 0, 1);
        v = 0;
        if (data_021759c0->mMode == MODE_BATTLE && IsKartEliminated((u16) k) != FALSE) {
            v = 1;
        } else if (data_021759c0->mMode != MODE_BATTLE &&
                   (func_020b1cf4((u16) k) != 0 || func_0207a84c((u16) k) != 0)) {
            v = 1;
        }
        if (v != 0) {
            v = 3;
        } else if ((u16) k == func_020b4d9c()) {
            v = 0;
        } else if (data_021759c0->mUseTeams != 0 && data_021759c0->mCurrentEntries[(u16) k].mPlayer.mTeamIndex == 1) {
            v = 2;
        } else {
            v = 1;
        }
        c = GetRaceSNcerEntry(v + 0x79);
        q4[0] = (p.mUnk_00 - 0xb) << 12;
        q4[1] = p.mUnk_04 << 12;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q4, 0, 1);
    }
}

void func_020bd850(Unk020d029c *a) {
    u16 i;
    s32 k;
    Unk0217b3d8_00 p;
    s32 r;
    s32 *d;
    u16 f;
    s32 q1[2];
    s32 q2[2];
    s32 q3[2];
    s32 v;
    Unk020224e0_c *c;

    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        k = data_0217b3d8->mUnk_0a0[i];
        p = data_0217b3d8->mUnk_000[k];
        r = func_020be15c(k);
        p.mUnk_00 -= data_0217b3d8->mUnk_0e0;
        if (r != 0xc9) {
            c = GetRaceSNcerEntry(r);
            q1[0] = (p.mUnk_00 + 0x12) << 12;
            q1[1] = p.mUnk_04 << 12;
            a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q1, 0, 1);
        }
        if (data_0217b3d8->mUnk_060[k] > data_0217b3d8->mUnk_080[k]) {
            f = data_0217b3d8->mUnk_0e4;
        } else {
            f = 0;
        }
        if (data_0217b3d8->mUnk_060[k] > data_0217b3d8->mUnk_080[k]) {
            d = data_0217b3d8->mUnk_0e8;
        } else {
            d = NULL;
        }
        c = GetRaceSNcerEntry(k + 8);
        q2[0] = p.mUnk_00 << 12;
        q2[1] = p.mUnk_04 << 12;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, d, q2, f, 1);
        v = 0;
        if (data_021759c0->mMode == MODE_BATTLE && IsKartEliminated((u16) k) != FALSE) {
            v = 1;
        } else if (data_021759c0->mMode != MODE_BATTLE &&
                   (func_020b1cf4((u16) k) != 0 || func_0207a84c((u16) k) != 0)) {
            v = 1;
        }
        if (v != 0) {
            v = 3;
        } else if ((u16) k == func_020b4d9c()) {
            v = 0;
        } else if (data_021759c0->mUseTeams != 0 && data_021759c0->mCurrentEntries[(u16) k].mPlayer.mTeamIndex == 1) {
            v = 2;
        } else {
            v = 1;
        }
        c = GetRaceSNcerEntry(v + 0x7d);
        q3[0] = (p.mUnk_00 - 0xb) << 12;
        q3[1] = p.mUnk_04 << 12;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q3, 0, 1);
    }
}

void func_020bd7f8(Unk020d029c *a) {
    switch (GetRaceHudSubScreenState()) {
        case 0:
            func_020bdf08(a);
            func_020bdb34(a);
            break;
        case 1:
        case 2:
        case 3:
            func_020bdf08(a);
            func_020bd850(a);
            break;
    }
}

void func_020bd178(Unk020d029c *a) {
    s32 s;
    u16 i;
    u16 f;
    Unk0217b3d8_00 p;
    s32 *d;
    s32 k;
    s32 q1[2];
    s32 q2[2];
    s32 q3[2];
    s32 q4[2];
    s32 r;
    s32 q5[2];
    s32 q6[2];
    s32 q7[2];
    s32 q8[2];
    s32 q9[2];
    s32 v;
    Unk020224e0_c *c;

    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        k = data_0217b3d8->mUnk_0a0[i];
        p = data_0217b3d8->mUnk_000[k];
        r = func_020be15c(k);
        p.mUnk_00 -= data_0217b3d8->mUnk_0e0 + 0x13;
        if (r != 0xc9) {
            c = GetRaceSNcerEntry(r);
            q1[0] = (p.mUnk_00 + 0x45) << 12;
            q1[1] = p.mUnk_04 << 12;
            a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q1, 0, 1);
        }
        if (data_0217b3d8->mUnk_060[k] > data_0217b3d8->mUnk_080[k]) {
            f = data_0217b3d8->mUnk_0e4;
        } else {
            f = 0;
        }
        if (data_0217b3d8->mUnk_060[k] > data_0217b3d8->mUnk_080[k]) {
            d = data_0217b3d8->mUnk_0e8;
        } else {
            d = NULL;
        }
        c = GetRaceSNcerEntry(k + 8);
        q2[0] = (p.mUnk_00 + 1) << 12;
        q2[1] = p.mUnk_04 << 12;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, d, q2, f, 1);
        s = 0;
        if (data_021759c0->mMode == MODE_BATTLE && IsKartEliminated((u16) k) != FALSE) {
            s = 1;
        } else if (data_021759c0->mMode != MODE_BATTLE &&
                   (func_020b1cf4((u16) k) != 0 || func_0207a84c((u16) k) != 0)) {
            s = 1;
        }
        s = s != 0 ? 0x6d : 0x65;
        c = GetRaceSNcerEntry(s + k);
        q3[0] = (p.mUnk_00 + 0xb) << 12;
        q3[1] = p.mUnk_04 << 12;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q3, 0, 1);
        if (data_021759c0->mUnk_18 == 0) {
            s32 t = data_0217b3d8->mUnk_0c0[k];

            c = GetRaceSNcerEntry(0xc3);
            q4[0] = (p.mUnk_00 + 0x57) << 12;
            q4[1] = (p.mUnk_04 - 2) << 12;
            a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q4, 0, 1);
            c = GetRaceSNcerEntry(t + 0xb9);
            q5[0] = (p.mUnk_00 + 0x5c) << 12;
            q5[1] = p.mUnk_04 << 12;
            a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q5, 0, 1);
        } else {
            s32 t = data_0217b3d8->mUnk_0c0[k] / 10;
            s32 u = data_0217b3d8->mUnk_0c0[k] % 10;

            c = GetRaceSNcerEntry(0xc4);
            q6[0] = (p.mUnk_00 + 0x57) << 12;
            q6[1] = (p.mUnk_04 - 2) << 12;
            a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q6, 0, 1);
            c = GetRaceSNcerEntry(t + 0xb9);
            q7[0] = (p.mUnk_00 + 0x54) << 12;
            q7[1] = p.mUnk_04 << 12;
            a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q7, 0, 1);
            c = GetRaceSNcerEntry(u + 0xb9);
            q8[0] = (p.mUnk_00 + 0x5c) << 12;
            q8[1] = p.mUnk_04 << 12;
            a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q8, 0, 1);
        }
        v = 0;
        if (data_021759c0->mMode == MODE_BATTLE && IsKartEliminated((u16) k) != FALSE) {
            v = 1;
        } else if (data_021759c0->mMode != MODE_BATTLE &&
                   (func_020b1cf4((u16) k) != 0 || func_0207a84c((u16) k) != 0)) {
            v = 1;
        }
        if (v != 0) {
            v = 3;
        } else if ((u16) k == func_020b4d9c()) {
            v = 0;
        } else if (data_021759c0->mUseTeams != 0 && data_021759c0->mCurrentEntries[(u16) k].mPlayer.mTeamIndex == 1) {
            v = 2;
        } else {
            v = 1;
        }
        c = GetRaceSNcerEntry(v + 0x81);
        q9[0] = (p.mUnk_00 - 0xb) << 12;
        q9[1] = p.mUnk_04 << 12;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q9, 0, 1);
    }
}

void func_020bcbe8(Unk020d029c *a) {
    u16 i;
    u16 f;
    Unk0217b3d8_00 p;
    s32 *d;
    s32 k;
    s32 q1[2];
    s32 q2[2];
    s32 q3[2];
    s32 q4[2];
    s32 r;
    s32 q5[2];
    s32 q6[2];
    s32 q7[2];
    s32 q8[2];
    s32 v;
    Unk020224e0_c *c;

    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        k = data_0217b3d8->mUnk_0a0[i];
        p = data_0217b3d8->mUnk_000[k];
        r = func_020be15c(k);
        p.mUnk_00 -= data_0217b3d8->mUnk_0e0 + 0x13;
        if (r != 0xc9) {
            c = GetRaceSNcerEntry(r);
            q1[0] = (p.mUnk_00 + 0x12) << 12;
            q1[1] = p.mUnk_04 << 12;
            a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q1, 0, 1);
        }
        if (data_0217b3d8->mUnk_060[k] > data_0217b3d8->mUnk_080[k]) {
            f = data_0217b3d8->mUnk_0e4;
        } else {
            f = 0;
        }
        if (data_0217b3d8->mUnk_060[k] > data_0217b3d8->mUnk_080[k]) {
            d = data_0217b3d8->mUnk_0e8;
        } else {
            d = NULL;
        }
        c = GetRaceSNcerEntry(k + 8);
        q2[0] = (p.mUnk_00 + 1) << 12;
        q2[1] = p.mUnk_04 << 12;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, d, q2, f, 1);
        if (data_021759c0->mUnk_18 == 0) {
            s32 t = data_0217b3d8->mUnk_0c0[k];

            c = GetRaceSNcerEntry(0xc3);
            q3[0] = (p.mUnk_00 + 0x25) << 12;
            q3[1] = (p.mUnk_04 - 2) << 12;
            a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q3, 0, 1);
            c = GetRaceSNcerEntry(t + 0xb9);
            q4[0] = (p.mUnk_00 + 0x2a) << 12;
            q4[1] = p.mUnk_04 << 12;
            a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q4, 0, 1);
        } else {
            s32 t = data_0217b3d8->mUnk_0c0[k] / 10;
            s32 u = data_0217b3d8->mUnk_0c0[k] % 10;

            c = GetRaceSNcerEntry(0xc4);
            q5[0] = (p.mUnk_00 + 0x25) << 12;
            q5[1] = (p.mUnk_04 - 2) << 12;
            a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q5, 0, 1);
            c = GetRaceSNcerEntry(t + 0xb9);
            q6[0] = (p.mUnk_00 + 0x22) << 12;
            q6[1] = p.mUnk_04 << 12;
            a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q6, 0, 1);
            c = GetRaceSNcerEntry(u + 0xb9);
            q7[0] = (p.mUnk_00 + 0x2a) << 12;
            q7[1] = p.mUnk_04 << 12;
            a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q7, 0, 1);
        }
        v = 0;
        if (data_021759c0->mMode == MODE_BATTLE && IsKartEliminated((u16) k) != FALSE) {
            v = 1;
        } else if (data_021759c0->mMode != MODE_BATTLE &&
                   (func_020b1cf4((u16) k) != 0 || func_0207a84c((u16) k) != 0)) {
            v = 1;
        }
        if (v != 0) {
            v = 3;
        } else if ((u16) k == func_020b4d9c()) {
            v = 0;
        } else if (data_021759c0->mUseTeams != 0 && data_021759c0->mCurrentEntries[(u16) k].mPlayer.mTeamIndex == 1) {
            v = 2;
        } else {
            v = 1;
        }
        c = GetRaceSNcerEntry(v + 0x85);
        q8[0] = (p.mUnk_00 - 0xb) << 12;
        q8[1] = p.mUnk_04 << 12;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q8, 0, 1);
    }
}

void func_020bcb74(void) {
    data_0217b3d4 = HeapAlloc(GetHeap(func_020364e8()), 0x14);
    data_0217b3d4->mUnk_00 = 0;
    data_0217b3d4->mUnk_04 = 0;
    data_0217b3d4->mUnk_08 = (u16) (func_02044618() - 1);
    data_0217b3d4->mUnk_0c = 0;
    data_0217b3d4->mUnk_10 = 1;
}

u32 func_020bcb60(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b3d4;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

// Values of the first argument func_020bc208 passes to GetRaceTaMNcerEntry.
typedef enum { UNK_020B843C_ARG_0, UNK_020B843C_ARG_1 } Unk020b843c_Arg;

void func_020bc958(void) {
    Unk0217b3ec *d;
    NNSSndSeqPlayer **a;
    u32 v;

    if (data_021759c0->mMode == MODE_BATTLE) {
        return;
    }
    if (data_021759c0->mMode == MODE_MISSION_RUN) {
        switch (data_021759c0->mUnk_2f) {
            case 2:
            case 4:
            case 6:
            case 10:
                break;
            default:
                return;
        }
    }
    data_0217b3d4->mUnk_04 = data_0217b3d4->mUnk_00;
    data_0217b3d4->mUnk_00 = func_0203c8c0(func_020b4d9c()) - 1;
    if (data_0217b3d4->mUnk_00 != data_0217b3d4->mUnk_04 && data_0217b3d4->mUnk_08 > 0) {
        if (data_0217b3d4->mUnk_00 < data_0217b3d4->mUnk_08) {
            v = 0x41;
            if (data_021759c0->mCourseId == COURSE_ID_PINBALL) {
                v = 0x1c7;
            }
            if (data_0217c780 & 1) {
                a = func_0210e128(func_02108ea0(0));
                if (data_0217d084.mUnk_0c != 0) {
                    if (*a != NULL) {
                        NNS_SndPlayerStopSeq(a, 0);
                    }
                    if (*a != NULL) {
                        NNS_SndPlayerStopSeq(a, 0);
                    }
                    NNS_SndArcPlayerStartSeqArc(a, 0, v);
                }
            }
        }
        data_0217b3d4->mUnk_0c = 1;
    }
    d = data_0217b3d4;
    if (d->mUnk_0c != 0) {
        if ((d->mUnk_0c - 1) % 12 < 8) {
            d->mUnk_10 = 1;
        } else {
            d->mUnk_10 = 0;
        }
        data_0217b3d4->mUnk_0c++;
        if (data_0217b3d4->mUnk_0c > 0x78) {
            data_0217b3d4->mUnk_0c = 0;
        }
    } else {
        d->mUnk_10 = 1;
    }
}

void func_020bc208(Unk020d029c *a) {
    s32 t[2] = {0xf8, 0x10};
    s32 *p;
    TimeDigits *r;
    s32 q1[2];
    s32 q2[2];
    s32 q3[2];
    s32 q4[2];
    s32 v;
    Unk020224e0_c *c;

    if (data_021759c0->mUnk_00c == 4) {
        return;
    }
    if (data_021759c0->mUnk_00c == 1) {
        return;
    }
    if (data_021759c0->mMode == MODE_MISSION_RUN) {
        switch (data_021759c0->mUnk_2f) {
            case 2:
            case 4:
            case 6:
            case 10:
                if (data_0217b3d4->mUnk_08 < 2) {
                    return;
                }
                break;
            default:
                return;
        }
    }
    if (data_021759c0->mMode == MODE_BATTLE) {
        return;
    }
    c = GetRaceMNcerEntry(0x20);
    q1[0] = t[0] << 12;
    q1[1] = t[1] << 12;
    a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q1, 0, 1);
    if (data_0217b3d4->mUnk_10 != 0) {
        c = GetRaceMNcerEntry(data_0217b3d4->mUnk_00 + 0x21);
        q2[0] = t[0] << 12;
        q2[1] = t[1] << 12;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q2, 0, 1);
    }
    switch (data_0217b3d4->mUnk_08) {
        case 2:
            c = GetRaceMNcerEntry(0x26);
            q3[0] = t[0] << 12;
            q3[1] = t[1] << 12;
            a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q3, 0, 1);
            break;
        case 4:
            c = GetRaceMNcerEntry(0x27);
            q4[0] = t[0] << 12;
            q4[1] = t[1] << 12;
            a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q4, 0, 1);
            break;
    }
    if (GetUseTimeDifference() == 0) {
        return;
    }
    if (func_020b1a20() == 0) {
        return;
    }
    v = func_020b1a0c();
    if (v % 0x24 >= 0x18) {
        return;
    }
    {
        s32 q5[2];
        s32 q6[2];
        s32 q7[2];
        s32 q8[2];
        s32 q9[2];
        s32 q10[2];
        s32 q11[2];
        s32 q12[2];
        s32 q13[2];
        s32 q14[2];
        s32 b[10] = {0x57, 0x61, 0x6a, 0x72, 0x7c, 0x85, 0x8e, 0x98, 0xa1, 0xaa};

        GetRaceHudTimeDifference(&p, &r);
        c = GetRaceTaMNcerEntry(*p != 0 ? UNK_020B843C_ARG_0 : UNK_020B843C_ARG_1);
        q5[0] = b[0] << 12;
        q5[1] = 0x58000;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q5, 0, 1);
        if (r->mUnk_00[0] != 0) {
            c = GetRaceTaMNcerEntry(r->mUnk_00[0] + 2);
            q6[0] = b[1] << 12;
            q6[1] = 0x58000;
            a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q6, 0, 1);
        }
        c = GetRaceTaMNcerEntry(r->mUnk_00[1] + 2);
        q7[0] = b[2] << 12;
        q7[1] = 0x58000;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q7, 0, 1);
        c = GetRaceTaMNcerEntry(0xc);
        q8[0] = b[3] << 12;
        q8[1] = 0x58000;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q8, 0, 1);
        c = GetRaceTaMNcerEntry(r->mUnk_00[2] + 2);
        q9[0] = b[4] << 12;
        q9[1] = 0x58000;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q9, 0, 1);
        c = GetRaceTaMNcerEntry(r->mUnk_00[3] + 2);
        q10[0] = b[5] << 12;
        q10[1] = 0x58000;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q10, 0, 1);
        c = GetRaceTaMNcerEntry(0xc);
        q11[0] = b[6] << 12;
        q11[1] = 0x58000;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q11, 0, 1);
        c = GetRaceTaMNcerEntry(r->mUnk_00[4] + 2);
        q12[0] = b[7] << 12;
        q12[1] = 0x58000;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q12, 0, 1);
        c = GetRaceTaMNcerEntry(r->mUnk_00[5] + 2);
        q13[0] = b[8] << 12;
        q13[1] = 0x58000;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q13, 0, 1);
        c = GetRaceTaMNcerEntry(r->mUnk_00[6] + 2);
        q14[0] = b[9] << 12;
        q14[1] = 0x58000;
        a->mUnk_400 += NNS_G2dMakeCellToOams(&a->mUnk_000[a->mUnk_400], 0x80 - a->mUnk_400, c, NULL, q14, 0, 1);
    }
}

void func_020bc11c(void) {
    s32 i;

    data_0217b3d0 = HeapAlloc(GetHeap(func_020364e8()), 0x38);
    data_0217b3d0->mUnk_00.mUnk_00[0] = 0;
    data_0217b3d0->mUnk_00.mUnk_00[1] = 0;
    data_0217b3d0->mUnk_00.mUnk_00[2] = 0;
    data_0217b3d0->mUnk_00.mUnk_00[3] = 0;
    data_0217b3d0->mUnk_00.mUnk_00[4] = 0;
    data_0217b3d0->mUnk_00.mUnk_00[5] = 0;
    data_0217b3d0->mUnk_00.mUnk_00[6] = 0;
    data_0217b3d0->mUnk_1c = FALSE;
    if (data_021759c0->mMode == MODE_BATTLE) {
        if (data_021759c0->mUnk_18 == 1) {
            data_0217b3d0->mUnk_1c = TRUE;
        }
    }
    if (data_021759c0->mMode == MODE_MISSION_RUN) {
        if (data_021759c0->mUnk_2f != 6) {
            data_0217b3d0->mUnk_1c = TRUE;
        }
    }
    for (i = 0; i < 6; i++) {
        data_0217b3d0->mUnk_20[i] = 0;
    }
}
