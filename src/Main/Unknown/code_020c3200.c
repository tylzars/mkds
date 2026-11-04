#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_020c3200.h"
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
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020c0dd8.h"
#include "Main/Unknown/code_020c13e8.h"

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
        if (data_021759c0->mUnk_1c == 1 || data_021759c0->mMode == 2) {
            e = data_021759c0->mCurrentEntries[j].mUnk_08.mKind;
            k = e == 0 || e == 2 || e == 3 ? 1 : 0;
            l = func_0205d360(j);
            s[j] = l * 16 + k * 8;
            if (data_021759c0->mMode == 3 || data_021759c0->mMode == 5) {
                s[j] = s[j] + (8 - func_0205d27c(j));
            } else {
                s[j] += 8 - j;
            }
            gRaceGoalS->mUnk_0020[j] = func_0205d360(j);
        } else {
            e = data_021759c0->mCurrentEntries[j].mUnk_08.mKind;
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
    func_020ae770(gRaceGoalS->mUnk_0040, s, data_021759c0->mKartCount);
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
