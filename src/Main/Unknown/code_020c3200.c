#include "Main/Unknown/code_020c3200.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/unk_021759c0.h"
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
            func_020b4520(data_0217b3e0->mUnk_00d8[v], y, x, h, w, data_0217b3e0->mRaceGoalSNscrs[m]->mUnk_0c, y, x);
            func_020b44a4(data_0217b3e0->mRaceGoalSNscrs[m]->mUnk_0c, y, x, h, w, 9);
            break;
        case 1:
            x = t[a].mUnk_00;
            w = t[a].mUnk_04 - x + 1;
            y = u.mUnk_00;
            h = u.mUnk_04 - y + 1;
            func_020b4520(data_0217b3e0->mUnk_00d8[v], y, x, h, w, data_0217b3e0->mRaceGoalSNscrs[m]->mUnk_0c, y, x);
            func_020b44a4(data_0217b3e0->mRaceGoalSNscrs[m]->mUnk_0c, y, x, h, w, 8);
            break;
        case 2:
            x = t[a].mUnk_00;
            w = t[a].mUnk_04 - x + 1;
            h = u.mUnk_04 - u.mUnk_00 + 1;
            func_020b4428(data_0217b3e0->mRaceGoalSNscrs[m]->mUnk_0c, u.mUnk_00, x, h, w, 0);
            break;
    }
}

void func_020c3654(void) {
    s32 n;

    n = data_0217b3e0->mUnk_20dc;
    data_0217b3e0->mUnk_20dc = n + 1;
    switch (data_0217b3e0->mUnk_20d8) {
        case 0:
            data_0217b3e0->mUnk_20e0 = -0x20;
            if (data_0217b3e0->mUnk_00ac == func_020c1e70) {
                data_0217b3e0->mUnk_20d8 = 1;
                data_0217b3e0->mUnk_20dc = 0;
            } else {
                data_0217b3e0->mUnk_20d8 = 10;
                data_0217b3e0->mUnk_20dc = 0;
            }
            break;
        case 1:
            if (n < 0x14) {
                data_0217b3e0->mUnk_20e0 = func_020ae4c0(1, -0x20, 0, n, 0x14);
            } else {
                data_0217b3e0->mUnk_20e0 = 0;
                data_0217b3e0->mUnk_20d8 = 2;
                data_0217b3e0->mUnk_20dc = 0;
            }
            break;
        case 2:
            data_0217b3e0->mUnk_20e0 = 0;
            if (data_021759c0->mUnk_08 == 5 && func_020b32ec() != 0) {
                data_0217b3e0->mUnk_20d8 = 3;
                data_0217b3e0->mUnk_20dc = 0;
                return;
            }
            if (func_020c1728 == data_0217b3e0->mUnk_00ac) {
                data_0217b3e0->mUnk_20d8 = 3;
                data_0217b3e0->mUnk_20dc = 0;
            } else if (func_020c0fd0 == data_0217b3e0->mUnk_00ac) {
                data_0217b3e0->mUnk_20d8 = 9;
                data_0217b3e0->mUnk_20dc = 0;
            }
            break;
        case 3:
            if (n < 0x14) {
                data_0217b3e0->mUnk_20e0 = func_020ae4c0(1, 0, -0x20, n, 0x14);
            } else {
                data_0217b3e0->mUnk_20e0 = -0x20;
                if (data_021759c0->mUnk_08 == 5 && func_020b32ec() != 0) {
                    data_0217b3e0->mUnk_20d8 = 7;
                    data_0217b3e0->mUnk_20dc = 0;
                } else {
                    data_0217b3e0->mUnk_20d8 = 4;
                    data_0217b3e0->mUnk_20dc = 0;
                }
            }
            break;
        case 4:
            if (n < 0x14) {
                data_0217b3e0->mUnk_20e0 = func_020ae4c0(1, -0x20, 0, n, 0x14);
            } else {
                data_0217b3e0->mUnk_20e0 = 0;
                data_0217b3e0->mUnk_20d8 = 5;
                data_0217b3e0->mUnk_20dc = 0;
            }
            break;
        case 5:
            data_0217b3e0->mUnk_20e0 = 0;
            if (data_021759c0->mUnk_08 != 5) {
                return;
            }
            if (func_020b32ec() == 0) {
                return;
            }
            data_0217b3e0->mUnk_20d8 = 6;
            data_0217b3e0->mUnk_20dc = 0;
            break;
        case 6:
            if (n < 0x14) {
                data_0217b3e0->mUnk_20e0 = func_020ae4c0(1, 0, -0x20, n, 0x14);
            } else {
                data_0217b3e0->mUnk_20e0 = -0x20;
                data_0217b3e0->mUnk_20d8 = 7;
                data_0217b3e0->mUnk_20dc = 0;
            }
            break;
        case 7:
            if (n < 0x14) {
                data_0217b3e0->mUnk_20e0 = func_020ae4c0(1, -0x20, 0, n, 0x14);
            } else {
                data_0217b3e0->mUnk_20e0 = 0;
                data_0217b3e0->mUnk_20d8 = 8;
                data_0217b3e0->mUnk_20dc = 0;
            }
            break;
        case 8:
        case 10:
            data_0217b3e0->mUnk_20e0 = 0;
            break;
        case 9:
            if (n < 0x14) {
                data_0217b3e0->mUnk_20e0 = func_020ae4c0(1, 0, -0x20, n, 0x14);
            } else {
                data_0217b3e0->mUnk_20e0 = 0;
                data_0217b3e0->mUnk_20d8 = 10;
                data_0217b3e0->mUnk_20dc = 0;
            }
            break;
    }
}

void func_020c3200(void) {
    s32 s[8];
    u16 i;
    u32 j;
    u32 g;
    s32 k;
    s32 l;
    s32 e;

    data_0217b3e0 = func_02036bec(func_020364e0(func_020364e8()), 0x20e4);
    for (i = 0; i < 8; i++) {
        data_0217b3e0->mUnk_0000[i] = 1;
        data_0217b3e0->mUnk_0020[i] = 0;
        data_0217b3e0->mUnk_0040[i] = 0;
        data_0217b3e0->mUnk_0080[i] = 1;
    }
    data_0217b3e0->mUnk_00a4 = 0;
    data_0217b3e0->mUnk_00a8 = 0;
    data_0217b3e0->mUnk_00ac = func_020c1ef8;
    data_0217b3e0->mUnk_00b0 = 0;
    data_0217b3e0->mUnk_00b4 = 0;
    data_0217b3e0->mUnk_00a0 = -0x100;
    for (j = 0; j < data_021759c0->mUnk_3d0; j = (u16) (j + 1)) {
        if (data_021759c0->mUnk_1c == 1 || data_021759c0->mUnk_08 == 2) {
            e = data_021759c0->mUnk_68[j].mUnk_08.mUnk_00;
            k = e == 0 || e == 2 || e == 3 ? 1 : 0;
            l = func_0205d360(j);
            s[j] = l * 16 + k * 8;
            if (data_021759c0->mUnk_08 == 3 || data_021759c0->mUnk_08 == 5) {
                s[j] = s[j] + (8 - func_0205d27c(j));
            } else {
                s[j] += 8 - j;
            }
            data_0217b3e0->mUnk_0020[j] = func_0205d360(j);
        } else {
            e = data_021759c0->mUnk_68[j].mUnk_08.mUnk_00;
            l = e == 0 || e == 2 || e == 3 ? 1 : 0;
            k = func_0205d3f0(j);
            s[j] = k * 16 + l * 8 + 8 - func_0205d27c(j);
            data_0217b3e0->mUnk_0020[j] = func_0205d3f0(j);
        }
    }
    for (g = 0; g < data_021759c0->mUnk_3d0; g = (u16) (g + 1)) {
        data_0217b3e0->mUnk_0040[g] = g;
        s[g] *= -1;
    }
    func_020ae770(data_0217b3e0->mUnk_0040, s, data_021759c0->mUnk_3d0);
    for (j = 0; j < data_021759c0->mUnk_3d0; j = (u16) (j + 1)) {
        data_0217b3e0->mUnk_0060[j] = data_0217b3e0->mUnk_0040[j];
    }
    data_0217b3e0->mUnk_20d8 = 0;
    data_0217b3e0->mUnk_20dc = 0;
    data_0217b3e0->mUnk_20e0 = -0x20;
    LoadNclrData(&data_0217b3e0->mRaceGoalSBNclr, FindSceneFileWrapper("race_goal_s_b.NCLR"));
    LoadNcgrData(&data_0217b3e0->mRaceGoalSBNcgr, FindSceneFileWrapper("race_goal_s_b.NCGR"));
    LoadNscrData(&data_0217b3e0->mRaceGoalSNscrs[0], FindSceneFileWrapper("race_goal_s_bg.NSCR"));
    LoadNscrData(&data_0217b3e0->mRaceGoalSNscrs[1], FindSceneFileWrapper("race_goal_s_space1.NSCR"));
    LoadNscrData(&data_0217b3e0->mRaceGoalSNscrs[2], FindSceneFileWrapper("race_goal_s_space2.NSCR"));
    LoadNscrData(&data_0217b3e0->mRaceGoalSNscrs[3], FindSceneFileWrapper("race_goal_s_team_bg.NSCR"));
    LoadNscrData(&data_0217b3e0->mRaceGoalSNscrs[4], FindSceneFileWrapper("race_goal_s_teamB.NSCR"));
    LoadNscrData(&data_0217b3e0->mRaceGoalSNscrs[5], FindSceneFileWrapper("race_goal_s_teamR.NSCR"));
    for (i = 0; i < 0x800; i++) {
        data_0217b3e0->mUnk_00d8[0][i] = data_0217b3e0->mRaceGoalSNscrs[1]->mUnk_0c[i];
        data_0217b3e0->mUnk_00d8[1][i] = data_0217b3e0->mRaceGoalSNscrs[2]->mUnk_0c[i];
    }
}
