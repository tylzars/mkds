#include "Main/Unknown/code_020c214c.h"

#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_020c06c4.h"
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
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020c13d0.h"
#include "Main/Unknown/code_020c13e8.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_020c3000.h"
#include "Main/Unknown/code_020c31ec.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020c0dd8.h"

// placeholder: an object of the original file that is not known yet; it only sets the order of the tables below
u8 data_020c214c_pad[12];

void func_020c3b6c(s32 a, s32 b) {
    UnkPair020b502c t[8] = {{2, 5}, {5, 8}, {8, 10}, {10, 13}, {13, 16}, {15, 18}, {18, 21}, {21, 23}};
    UnkPair020b502c u = {0, 0x1f};
    s32 m;
    s32 v;
    u32 x;
    u32 w;
    u32 y;
    u32 h;

    m = a % 2;
    v = m != 0 ? 1 : 0;
    m = m != 0 ? 2 : 1;
    switch (b) {
        case 0:
            x = t[a].mUnk_00;
            w = t[a].mUnk_04 - x + 1;
            y = u.mUnk_00;
            h = u.mUnk_04 - y + 1;
            func_020b4520(gRaceGoalS->mRaceGoalSSpaceNscrCopies[v], y, x, h, w, gRaceGoalS->mRaceGoalSNscrs[m]->mData,
                          y, x);
            func_020b44a4(gRaceGoalS->mRaceGoalSNscrs[m]->mData, y, x, h, w, 9);
            break;
        case 1:
            x = t[a].mUnk_00;
            w = t[a].mUnk_04 - x + 1;
            y = u.mUnk_00;
            h = u.mUnk_04 - y + 1;
            func_020b4520(gRaceGoalS->mRaceGoalSSpaceNscrCopies[v], y, x, h, w, gRaceGoalS->mRaceGoalSNscrs[m]->mData,
                          y, x);
            func_020b44a4(gRaceGoalS->mRaceGoalSNscrs[m]->mData, y, x, h, w, 8);
            break;
        case 2:
            x = t[a].mUnk_00;
            w = t[a].mUnk_04 - x + 1;
            h = u.mUnk_04 - u.mUnk_00 + 1;
            func_020b4428(gRaceGoalS->mRaceGoalSNscrs[m]->mData, u.mUnk_00, x, h, w, 0);
            break;
    }
}

void UpdateRaceGoalSOffset(void) {
    s32 n;

    n = gRaceGoalS->mOffsetStateFrames;
    gRaceGoalS->mOffsetStateFrames = n + 1;
    switch (gRaceGoalS->mOffsetState) {
        case 0:
            gRaceGoalS->mOffset = -0x20;
            if (gRaceGoalS->mUnk_00ac == func_020c1e70) {
                gRaceGoalS->mOffsetState = 1;
                gRaceGoalS->mOffsetStateFrames = 0;
            } else {
                gRaceGoalS->mOffsetState = 10;
                gRaceGoalS->mOffsetStateFrames = 0;
            }
            break;
        case 1:
            if (n < 0x14) {
                gRaceGoalS->mOffset = func_020ae4c0(1, -0x20, 0, n, 0x14);
            } else {
                gRaceGoalS->mOffset = 0;
                gRaceGoalS->mOffsetState = 2;
                gRaceGoalS->mOffsetStateFrames = 0;
            }
            break;
        case 2:
            gRaceGoalS->mOffset = 0;
            if (data_021759c0->mMode == 5 && func_020b32ec() != 0) {
                gRaceGoalS->mOffsetState = 3;
                gRaceGoalS->mOffsetStateFrames = 0;
                return;
            }
            if (func_020c1728 == gRaceGoalS->mUnk_00ac) {
                gRaceGoalS->mOffsetState = 3;
                gRaceGoalS->mOffsetStateFrames = 0;
            } else if (func_020c0fd0 == gRaceGoalS->mUnk_00ac) {
                gRaceGoalS->mOffsetState = 9;
                gRaceGoalS->mOffsetStateFrames = 0;
            }
            break;
        case 3:
            if (n < 0x14) {
                gRaceGoalS->mOffset = func_020ae4c0(1, 0, -0x20, n, 0x14);
            } else {
                gRaceGoalS->mOffset = -0x20;
                if (data_021759c0->mMode == 5 && func_020b32ec() != 0) {
                    gRaceGoalS->mOffsetState = 7;
                    gRaceGoalS->mOffsetStateFrames = 0;
                } else {
                    gRaceGoalS->mOffsetState = 4;
                    gRaceGoalS->mOffsetStateFrames = 0;
                }
            }
            break;
        case 4:
            if (n < 0x14) {
                gRaceGoalS->mOffset = func_020ae4c0(1, -0x20, 0, n, 0x14);
            } else {
                gRaceGoalS->mOffset = 0;
                gRaceGoalS->mOffsetState = 5;
                gRaceGoalS->mOffsetStateFrames = 0;
            }
            break;
        case 5:
            gRaceGoalS->mOffset = 0;
            if (data_021759c0->mMode != 5) {
                return;
            }
            if (func_020b32ec() == 0) {
                return;
            }
            gRaceGoalS->mOffsetState = 6;
            gRaceGoalS->mOffsetStateFrames = 0;
            break;
        case 6:
            if (n < 0x14) {
                gRaceGoalS->mOffset = func_020ae4c0(1, 0, -0x20, n, 0x14);
            } else {
                gRaceGoalS->mOffset = -0x20;
                gRaceGoalS->mOffsetState = 7;
                gRaceGoalS->mOffsetStateFrames = 0;
            }
            break;
        case 7:
            if (n < 0x14) {
                gRaceGoalS->mOffset = func_020ae4c0(1, -0x20, 0, n, 0x14);
            } else {
                gRaceGoalS->mOffset = 0;
                gRaceGoalS->mOffsetState = 8;
                gRaceGoalS->mOffsetStateFrames = 0;
            }
            break;
        case 8:
        case 10:
            gRaceGoalS->mOffset = 0;
            break;
        case 9:
            if (n < 0x14) {
                gRaceGoalS->mOffset = func_020ae4c0(1, 0, -0x20, n, 0x14);
            } else {
                gRaceGoalS->mOffset = 0;
                gRaceGoalS->mOffsetState = 10;
                gRaceGoalS->mOffsetStateFrames = 0;
            }
            break;
    }
}

void InitRaceGoalS(void) {
    s32 s[8];
    u16 i;
    u32 j;
    u32 g;
    s32 k;
    s32 l;
    s32 e;

    gRaceGoalS = HeapAlloc(GetHeap(func_020364e8()), 0x20e4);
    for (i = 0; i < 8; i++) {
        gRaceGoalS->mUnk_0000[i] = 1;
        gRaceGoalS->mUnk_0020[i] = 0;
        gRaceGoalS->mUnk_0040[i] = 0;
        gRaceGoalS->mUnk_0080[i] = 1;
    }
    gRaceGoalS->mUnk_00a4 = 0;
    gRaceGoalS->mUnk_00a8 = 0;
    gRaceGoalS->mUnk_00ac = func_020c1ef8;
    gRaceGoalS->mUnk_00b0 = 0;
    gRaceGoalS->mUnk_00b4 = 0;
    gRaceGoalS->mUnk_00a0 = -0x100;
    for (j = 0; j < data_021759c0->mKartCount; j = (u16) (j + 1)) {
        if (data_021759c0->mUnk_1c == 1 || data_021759c0->mMode == MODE_BATTLE) {
            e = data_021759c0->mCurrentEntries[j].mPlayer.mKind;
            k = e == 0 || e == 2 || e == 3 ? 1 : 0;
            l = func_0205d360(j);
            s[j] = l * 16 + k * 8;
            if (data_021759c0->mMode == MODE_VS || data_021759c0->mMode == 5) {
                s[j] = s[j] + (8 - func_0205d27c(j));
            } else {
                s[j] += 8 - j;
            }
            gRaceGoalS->mUnk_0020[j] = func_0205d360(j);
        } else {
            e = data_021759c0->mCurrentEntries[j].mPlayer.mKind;
            l = e == 0 || e == 2 || e == 3 ? 1 : 0;
            k = func_0205d3f0(j);
            s[j] = k * 16 + l * 8 + 8 - func_0205d27c(j);
            gRaceGoalS->mUnk_0020[j] = func_0205d3f0(j);
        }
    }
    for (g = 0; g < data_021759c0->mKartCount; g = (u16) (g + 1)) {
        gRaceGoalS->mUnk_0040[g] = g;
        s[g] *= -1;
    }
    SortIndicesByKey(gRaceGoalS->mUnk_0040, s, data_021759c0->mKartCount);
    for (j = 0; j < data_021759c0->mKartCount; j = (u16) (j + 1)) {
        gRaceGoalS->mUnk_0060[j] = gRaceGoalS->mUnk_0040[j];
    }
    gRaceGoalS->mOffsetState = 0;
    gRaceGoalS->mOffsetStateFrames = 0;
    gRaceGoalS->mOffset = -0x20;
    LoadNclrData(&gRaceGoalS->mRaceGoalSBNclr, FindSceneFileWrapper("race_goal_s_b.NCLR"));
    LoadNcgrData(&gRaceGoalS->mRaceGoalSBNcgr, FindSceneFileWrapper("race_goal_s_b.NCGR"));
    LoadNscrData(&gRaceGoalS->mRaceGoalSNscrs[0], FindSceneFileWrapper("race_goal_s_bg.NSCR"));
    LoadNscrData(&gRaceGoalS->mRaceGoalSNscrs[1], FindSceneFileWrapper("race_goal_s_space1.NSCR"));
    LoadNscrData(&gRaceGoalS->mRaceGoalSNscrs[2], FindSceneFileWrapper("race_goal_s_space2.NSCR"));
    LoadNscrData(&gRaceGoalS->mRaceGoalSNscrs[3], FindSceneFileWrapper("race_goal_s_team_bg.NSCR"));
    LoadNscrData(&gRaceGoalS->mRaceGoalSNscrs[4], FindSceneFileWrapper("race_goal_s_teamB.NSCR"));
    LoadNscrData(&gRaceGoalS->mRaceGoalSNscrs[5], FindSceneFileWrapper("race_goal_s_teamR.NSCR"));
    for (i = 0; i < 0x800; i++) {
        gRaceGoalS->mRaceGoalSSpaceNscrCopies[0][i] = gRaceGoalS->mRaceGoalSNscrs[1]->mData[i];
        gRaceGoalS->mRaceGoalSSpaceNscrCopies[1][i] = gRaceGoalS->mRaceGoalSNscrs[2]->mData[i];
    }
}

u32 func_020c31ec(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRaceGoalS;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void func_020c31c0(void) {
    u32 v2 = ((u32) (&gRaceGoalS));
    u32 v3 = ((u32) * (u32 *) ((v2) + (0)));
    u32 v4 = ((u32) * (u32 *) ((v3) + (172)));
    u32 v5 = ((u32(*)(void))(v4))();
    UpdateRaceGoalSOffset();
}

void func_020c28dc(Unk020c06c4 *a) {
    s32 r;
    u16 i;
    s32 k;
    s32 v;
    s32 p;
    s32 q;
    RaceGoalS *g = gRaceGoalS;
    s32 d = g->mUnk_00a0;
    s32 w;
    s32 x;
    s32 n;
    s32 z;
    Unk020c06c4_08 *u;
    void *m;
    s32 e10[2];
    s32 e11[2];
    s32 e12[2];
    s32 e1[2];
    s32 e2[2];
    s32 e3[2];
    s32 e4[2];
    s32 e5[2];
    s32 e6[2];
    s32 e7[2];
    s32 e8[2];
    s32 e9[2];
    s32 t[8] = {0x22, 0x37, 0x4c, 0x61, 0x76, 0x8b, 0xa0, 0xb5};

    switch (g->mOffsetState) {
        case 1:
        case 2:
        case 3:
        case 9:
            m = GetRaceGoalSNcerEntry(0x21);
            n = a->mUnk_400;
            e10[1] = (gRaceGoalS->mOffset + 0xb) << 12;
            e10[0] = 0;
            u = &a->mUnk_000.mUnk_00[n];
            a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) u, 0x80 - n, m, NULL, e10, 0, 1);
            for (; n < a->mUnk_400; n++, u++) {
                u->mUnk_0e = 1;
            }
            break;
        case 4:
        case 5:
        case 6:
            m = GetRaceGoalSNcerEntry(0x22);
            n = a->mUnk_400;
            e11[1] = (gRaceGoalS->mOffset + 0xb) << 12;
            e11[0] = 0;
            u = &a->mUnk_000.mUnk_00[n];
            a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) u, 0x80 - n, m, NULL, e11, 0, 1);
            for (; n < a->mUnk_400; n++, u++) {
                u->mUnk_0e = 1;
            }
            break;
        case 7:
        case 8:
            w = gRaceGoalS->mOffsetStateFrames % 40;
            if (w < 0x20) {
                m = GetRaceGoalSNcerEntry(0x2b);
                n = a->mUnk_400;
                z = gRaceGoalS->mOffset;
                e12[0] = 0x80000;
                e12[1] = (z + 0x60) << 12;
                u = &a->mUnk_000.mUnk_00[n];
                a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) u, 0x80 - n, m, NULL, e12, 0, 1);
                for (; n < a->mUnk_400; n++, u++) {
                    u->mUnk_0e = 1;
                }
            }
            break;
    }
    for (i = 0; (u32) i < (u32) data_021759c0->mKartCount; i++) {
        k = gRaceGoalS->mUnk_0040[i];
        v = gRaceGoalS->mUnk_0020[k];
        p = v / 100;
        q = (v - p * 100) / 10;
        r = v % 10;
        if (p >= 10) {
            r = 9;
            q = r;
            p = r;
        }
        if (gRaceGoalS->mUnk_0000[i] == 0) {
            func_020c3b6c(i, 2);
        } else if (k == func_020b4d9c()) {
            func_020c3b6c(i, 0);
        } else {
            func_020c3b6c(i, 1);
        }
        if (gRaceGoalS->mUnk_0000[i] != 0) {
            if (p != 0) {
                m = GetRaceGoalSNcerEntry(p + 0x10);
                e1[0] = (d + 0xba) << 12;
                e1[1] = t[i] << 12;
                a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[a->mUnk_400],
                                                     0x80 - a->mUnk_400, m, NULL, e1, 0, 1);
            }
            if (p != 0 || q != 0) {
                m = GetRaceGoalSNcerEntry(q + 0x10);
                e2[0] = (d + 0xc3) << 12;
                e2[1] = t[i] << 12;
                a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[a->mUnk_400],
                                                     0x80 - a->mUnk_400, m, NULL, e2, 0, 1);
            }
            m = GetRaceGoalSNcerEntry(r + 0x10);
            e3[0] = (d + 0xcc) << 12;
            e3[1] = t[i] << 12;
            a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[a->mUnk_400],
                                                 0x80 - a->mUnk_400, m, NULL, e3, 0, 1);
            if (!(data_021759c0->mUnk_1c == 1 || data_021759c0->mMode == MODE_BATTLE)) {
                x = func_020b4b98(v) != FALSE ? 0x1a : 0x1b;
                m = GetRaceGoalSNcerEntry(x);
                e4[0] = (d + 0xd1) << 12;
                e4[1] = t[i] << 12;
                a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[a->mUnk_400],
                                                     0x80 - a->mUnk_400, m, NULL, e4, 0, 1);
            }
            if (data_021759c0->mUseTeams != 0) {
                x = data_021759c0->mCurrentEntries[(u16) k].mPlayer.mTeamIndex == 0 ? 0x1f : 0x20;
                m = GetRaceGoalSNcerEntry(x);
                e5[0] = (d + 0xec) << 12;
                e5[1] = t[i] << 12;
                a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[a->mUnk_400],
                                                     0x80 - a->mUnk_400, m, NULL, e5, 0, 1);
            }
            if (!(data_021759c0->mUnk_1c == 1 || data_021759c0->mMode == MODE_BATTLE ||
                  data_021759c0->mCourseNumber == 1)) {
                if (gRaceGoalS->mUnk_00ac == func_020c155c || gRaceGoalS->mUnk_00ac == func_020c13e8 ||
                    gRaceGoalS->mUnk_00ac == func_020c13d0) {
                    m = GetRaceGoalSNcerEntry(gRaceGoalS->mUnk_0080[k] + 0x1c);
                    e6[0] = (d + 0xc) << 12;
                    e6[1] = t[i] << 12;
                    a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[a->mUnk_400],
                                                         0x80 - a->mUnk_400, m, NULL, e6, 0, 1);
                }
            }
            m = GetRaceGoalSNcerEntry(i + 8);
            e7[0] = (d + 0x1d) << 12;
            e7[1] = t[i] << 12;
            a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[a->mUnk_400],
                                                 0x80 - a->mUnk_400, m, NULL, e7, 0, 1);
            m = GetRaceGoalSNcerEntry(k);
            e8[0] = (d + 0x2e) << 12;
            e8[1] = t[i] << 12;
            a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[a->mUnk_400],
                                                 0x80 - a->mUnk_400, m, NULL, e8, 0, 1);
            m = GetRaceGoalSNcerEntry(k + 0x23);
            e9[0] = (d + 0x3b) << 12;
            e9[1] = t[i] << 12;
            a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[a->mUnk_400],
                                                 0x80 - a->mUnk_400, m, NULL, e9, 0, 1);
        }
    }
}

void func_020c2570(Unk020c06c4 *a, u32 b, s32 c, s32 d) {
    s32 e0[2];
    s32 e1[2];
    s32 e2[2];
    s32 e3[2];
    s32 e4[2];
    s32 e5[2];
    s32 v;
    s32 p;
    s32 q;
    s32 r;
    s32 s;
    void *m;

    v = gRaceGoalS->mUnk_0020[b];
    p = v / 100;
    q = v / 10 % 10;
    r = v % 10;
    m = GetRaceGoalTeamSNcerEntry(b);
    e0[0] = (c + 0xc) << 12;
    e0[1] = d << 12;
    a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[a->mUnk_400], 0x80 - a->mUnk_400, m,
                                         NULL, e0, 0, 1);
    m = GetRaceGoalTeamSNcerEntry(b + 0x20);
    e1[0] = (c + 0x16) << 12;
    e1[1] = d << 12;
    a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[a->mUnk_400], 0x80 - a->mUnk_400, m,
                                         NULL, e1, 0, 1);
    if (b == func_020b4d9c()) {
        s = data_021759c0->mCurrentEntries[b].mPlayer.mTeamIndex == 0 ? 0x1e : 0x1f;
    } else {
        s = data_021759c0->mCurrentEntries[b].mPlayer.mTeamIndex == 0 ? 0x1c : 0x1d;
    }
    m = GetRaceGoalTeamSNcerEntry(s);
    e2[0] = c << 12;
    e2[1] = d << 12;
    a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[a->mUnk_400], 0x80 - a->mUnk_400, m,
                                         NULL, e2, 0, 1);
    if (data_021759c0->mMode == MODE_BATTLE) {
        return;
    }
    if (p >= 10) {
        r = 9;
        p = r;
        q = r;
    }
    if (p != 0) {
        m = GetRaceGoalTeamSNcerEntry(p + 8);
        e3[0] = (c + 0x57) << 12;
        e3[1] = d << 12;
        a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[a->mUnk_400], 0x80 - a->mUnk_400, m,
                                             NULL, e3, 0, 1);
    }
    if (p != 0 || q != 0) {
        m = GetRaceGoalTeamSNcerEntry(q + 8);
        e4[0] = (c + 0x60) << 12;
        e4[1] = d << 12;
        a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[a->mUnk_400], 0x80 - a->mUnk_400, m,
                                             NULL, e4, 0, 1);
    }
    m = GetRaceGoalTeamSNcerEntry(r + 8);
    e5[0] = (c + 0x69) << 12;
    e5[1] = d << 12;
    a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[a->mUnk_400], 0x80 - a->mUnk_400, m,
                                         NULL, e5, 0, 1);
}

void func_020c2304(Unk020c06c4 *a, s32 b, s32 c, s32 d) {
    s32 e0[2];
    s32 e1[2];
    s32 e2[2];
    s32 e3[2];
    s32 p;
    s32 q;
    s32 r;
    s32 s;
    void *m;

    p = b / 1000;
    q = b / 100 % 10;
    r = b / 10 % 10;
    s = b % 10;
    if (p != 0) {
        m = GetRaceGoalTeamSNcerEntry(p + 0x12);
        e0[0] = c << 12;
        e0[1] = d << 12;
        a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[a->mUnk_400], 0x80 - a->mUnk_400, m,
                                             NULL, e0, 0, 1);
    }
    if (p != 0 || q != 0) {
        m = GetRaceGoalTeamSNcerEntry(q + 0x12);
        e1[0] = (c + 0xf) << 12;
        e1[1] = d << 12;
        a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[a->mUnk_400], 0x80 - a->mUnk_400, m,
                                             NULL, e1, 0, 1);
    }
    if (p != 0 || q != 0 || r != 0) {
        m = GetRaceGoalTeamSNcerEntry(r + 0x12);
        e2[0] = (c + 0x1e) << 12;
        e2[1] = d << 12;
        a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[a->mUnk_400], 0x80 - a->mUnk_400, m,
                                             NULL, e2, 0, 1);
    }
    m = GetRaceGoalTeamSNcerEntry(s + 0x12);
    e3[0] = (c + 0x2d) << 12;
    e3[1] = d << 12;
    a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[a->mUnk_400], 0x80 - a->mUnk_400, m,
                                         NULL, e3, 0, 1);
}

void func_020c214c(Unk020c06c4 *a) {
    s32 c[2];
    s32 t1[2] = {0xa, 0x89};
    s32 t2[2] = {0x43, 0xc2};
    s32 d;
    s32 k;
    u16 i;
    BOOL f;
    s32 v;
    Unk0217aa1c_144 *s;

    d = gRaceGoalS->mUnk_00a0;
    for (i = 0; i < 2; i++) {
        c[i] = 0;
    }
    for (i = 0; (u32) i < (u32) data_021759c0->mKartCount; i++) {
        k = data_021759c0->mCurrentEntries[i].mPlayer.mTeamIndex;
        func_020c2570(a, i, t1[k] + (k == 0 ? -d : d), c[k] * 0x17 + 0x11);
        c[k]++;
    }
    for (i = 0; i < 2; i++) {
        f = TRUE;
        if (!(data_021759c0->mUnk_1c == 1 || data_021759c0->mMode == MODE_BATTLE)) {
            f = FALSE;
        }
        if (f != FALSE) {
            s = &data_0217aa1c->mUnk_144[func_0205db28()];
            v = s->mUnk_00[i].mUnk_02;
        } else {
            s = &data_0217aa1c->mUnk_144[func_0205db28()];
            v = s->mUnk_00[i].mUnk_00;
        }
        func_020c2304(a, v, t2[i] + (i == 0 ? -d : d), 0xb6);
    }
}
