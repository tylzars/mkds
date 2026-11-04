#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b6e00.h"

#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_020b8624.h"
#include "Main/Unknown/code_020ad000.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/code_0212b09c.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_027e0000.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020b846c.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b85dc.h"
#include "Main/Unknown/code_020b85f0.h"
#include "Main/Unknown/code_020b8610.h"
#include "Main/Unknown/code_020b6000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_0200eddc.h"
#include "code_02021e8c.h"
#include "code_02023374.h"
#include "code_0214cfe4.h"

void func_020b8624(void) {
    Unk02021dc8 *a0;
    Unk02021dc8 *a1;
    Unk02021dc8 *a2;
    Unk02021dc8 *a3;
    Unk02021dc8 *a4;
    Unk02021dc8 *a5;
    Unk02021dc8 *a6;
    Ncgr *a7;
    Nclr *a8;
    Unk02021dc8 *a9;
    Unk02021dc8 *a10;
    Unk02021dc8 *a11;
    Unk02021dc8 *a12;
    u8 buf0[0x20];
    Unk02180728 s0;
    u8 buf1[0x20];
    Unk02180728 s1;
    u8 buf2[0x20];
    Unk02180728 s2;
    u8 buf3[0x20];
    Unk02180728 s3;
    u16 w3[0x14];
    u8 buf4[0x20];
    Unk02180728 s4;
    u8 buf5[0x20];
    Unk02180728 s5;
    u16 w5[0x14];
    u8 buf6[0x20];
    Unk02180728 s6;
    u16 w6[0xe];
    u16 i;
    u16 x3;
    u16 y3;
    u16 x2;
    u16 y2;
    s32 j;
    void *p;
    s32 n;
    s32 n2;
    s32 m;
    u16 x;
    u16 y;
    s32 b;
    s32 c;
    void *q;

    data_0217b3c4 = HeapAlloc(GetHeap(func_020364e8()), 0x88c);
    for (i = 0; i < 0x38; i++) {
        data_0217b3c4->mRaceMNcerEntries[i] = NULL;
    }
    for (i = 0; i < 0x44; i++) {
        data_0217b3c4->mRaceGoalMNcerEntries[i] = NULL;
    }
    for (i = 0; i < 0xf; i++) {
        data_0217b3c4->mRaceTaMNcerEntries[i] = NULL;
    }
    for (i = 0; i < 0xd; i++) {
        data_0217b3c4->mRaceBattleMNcerEntries[i] = NULL;
    }
    for (i = 0; i < 0x16; i++) {
        data_0217b3c4->mRaceMrMNcerEntries[i] = NULL;
    }
    for (i = 0; i < 8; i++) {
        data_0217b3c4->mRaceGoalMrMNcerEntries[i] = NULL;
    }
    for (i = 0; i < 0xc9; i++) {
        data_0217b3c4->mRaceSNcerEntries[i] = NULL;
    }
    for (i = 0; i < 0x2c; i++) {
        data_0217b3c4->mRaceGoalSNcerEntries[i] = NULL;
    }
    for (i = 0; i < 0x28; i++) {
        data_0217b3c4->mRaceGoalTeamSNcerEntries[i] = NULL;
    }
    for (i = 0; i < 0x21; i++) {
        data_0217b3c4->mRaceNewRecordTaSNcerEntries[i] = NULL;
    }
    for (i = 0; i < 3; i++) {
        data_0217b3c4->mRaceStartBattleMNcerEntries[i] = NULL;
    }

    LoadNclrData(&data_0217b3c4->mNclrNcgrPairs[0].mNclr, FindSceneFileWrapper("race_m_o.NCLR"));
    LoadNclrData(&data_0217b3c4->mNclrNcgrPairs[1].mNclr, FindSceneFileWrapper("race_goal_m_o.NCLR"));
    switch (data_021759c0->mUnk_08) {
        case 1:
            data_0217b3c4->mNclrNcgrPairs[2].mNclr = data_0217b3c4->mNclrNcgrPairs[0].mNclr;
            break;
        case 2:
            LoadNclrData(&data_0217b3c4->mNclrNcgrPairs[3].mNclr, FindSceneFileWrapper("race_battle_m_o.NCLR"));
            if (data_021759c0->mUnk_00c == 4) {
                LoadNclrData(&data_0217b3c4->mNclrNcgrPairs[10].mNclr,
                             FindSceneFileWrapper("race_start_battle_m_o.NCLR"));
            }
            break;
        case 4:
            LoadNclrData(&data_0217b3c4->mNclrNcgrPairs[4].mNclr, FindSceneFileWrapper("race_mr_m_o.NCLR"));
            LoadNclrData(&data_0217b3c4->mNclrNcgrPairs[5].mNclr, FindSceneFileWrapper("race_goal_mr_m_o.NCLR"));
            break;
        case 5:
            break;
    }

    LoadNcgrData2(&data_0217b3c4->mNclrNcgrPairs[0].mNcgr, FindSceneFileWrapper("race_m_o.NCGR"));
    LoadNcgrData2(&data_0217b3c4->mNclrNcgrPairs[1].mNcgr, FindSceneFileWrapper("race_goal_m_o.NCGR"));
    switch (data_021759c0->mUnk_08) {
        case 1:
            LoadNcgrData2(&data_0217b3c4->mNclrNcgrPairs[2].mNcgr, FindSceneFileWrapper("race_ta_m_o.NCGR"));
            break;
        case 2:
            LoadNcgrData2(&data_0217b3c4->mNclrNcgrPairs[3].mNcgr, FindSceneFileWrapper("race_battle_m_o.NCGR"));
            if (data_021759c0->mUnk_00c == 4) {
                LoadNcgrData2(&data_0217b3c4->mNclrNcgrPairs[10].mNcgr,
                              FindSceneFileWrapper("race_start_battle_m_o.NCGR"));
            }
            break;
        case 4:
            LoadNcgrData2(&data_0217b3c4->mNclrNcgrPairs[4].mNcgr, FindSceneFileWrapper("race_mr_m_o.NCGR"));
            LoadNcgrData2(&data_0217b3c4->mNclrNcgrPairs[5].mNcgr, FindSceneFileWrapper("race_goal_mr_m_o.NCGR"));
            break;
        case 5:
            break;
    }

    a0 = NULL;
    LoadNcerData(&a0, FindSceneFileWrapper("race_m.NCER"));
    for (i = 0; i < 0x38; i++) {
        data_0217b3c4->mRaceMNcerEntries[i] = func_02021f1c(a0, i);
    }
    a1 = NULL;
    LoadNcerData(&a1, FindSceneFileWrapper("race_goal_m.NCER"));
    for (i = 0; i < 0x44; i++) {
        data_0217b3c4->mRaceGoalMNcerEntries[i] = func_02021f1c(a1, i);
    }

    switch (data_021759c0->mUnk_08) {
        case 1:
            p = func_020b403c(2);
            func_02023408(buf0, data_0217b3c4->mNclrNcgrPairs[1].mNcgr->mData, 0x20, 0x10, 4);
            s0.mUnk_08 = func_020b4acc();
            s0.mUnk_00 = buf0;
            s0.mUnk_04 = p;
            s0.mUnk_0c = 0;
            func_02024340(&s0, 0x80, 0x38, 0xe, 0x412, GetBmgEntry(func_020b47cc("common.bmg"), 0x81));
            func_0200ee74(data_0217b3c4->mNclrNcgrPairs[1].mNcgr->mData,
                          data_0217b3c4->mNclrNcgrPairs[1].mNcgr->mDataSize);
            a2 = NULL;
            LoadNcerData(&a2, FindSceneFileWrapper("race_ta_m.NCER"));
            for (i = 0; i < 0xf; i++) {
                data_0217b3c4->mRaceTaMNcerEntries[i] = func_02021f1c(a2, i);
            }
            p = func_020b403c(2);
            func_02023408(buf1, data_0217b3c4->mNclrNcgrPairs[2].mNcgr->mData, 0x20, 4, 4);
            s1.mUnk_08 = func_020b4acc();
            s1.mUnk_00 = buf1;
            s1.mUnk_04 = p;
            s1.mUnk_0c = 0;
            func_02024340(&s1, 0x80, 0x18, 0xe, 0x412, GetBmgEntry(func_020b47cc("common.bmg"), 0x6d));
            func_0200ee74(data_0217b3c4->mNclrNcgrPairs[2].mNcgr->mData,
                          data_0217b3c4->mNclrNcgrPairs[2].mNcgr->mDataSize);
            func_020b46d0(data_0217b3c4->mNclrNcgrPairs[2].mNcgr->mData, 0, 0, 0x20, 4,
                          data_0217b3c4->mNclrNcgrPairs[0].mNcgr->mData, 0, 0);
            break;
        case 2:
            if (data_021759c0->mUnk_00c != 4) {
                a3 = NULL;
                LoadNcerData(&a3, FindSceneFileWrapper("race_battle_m.NCER"));
                for (i = 0; i < 0xd; i++) {
                    data_0217b3c4->mRaceBattleMNcerEntries[i] = func_02021f1c(a3, i);
                }
                MemCopyHalfwords(data_0217b3c4->mNclrNcgrPairs[3].mNclr->mData,
                                 data_0217b3c4->mNclrNcgrPairs[0].mNclr->mData, 0x40);
                func_020b46d0(data_0217b3c4->mNclrNcgrPairs[3].mNcgr->mData, 0, 0, 0x20, 4,
                              data_0217b3c4->mNclrNcgrPairs[0].mNcgr->mData, 0, 0);
            } else {
                a4 = NULL;
                LoadNcerData(&a4, FindSceneFileWrapper("race_start_battle_m.NCER"));
                for (i = 0; i < 3; i++) {
                    data_0217b3c4->mRaceStartBattleMNcerEntries[i] = func_02021f1c(a4, i);
                }
                p = func_020b403c(2);
                n = func_02025d8c(data_021759c0->mCourseId);
                func_02023408(buf2, data_0217b3c4->mNclrNcgrPairs[10].mNcgr->mData, 0x20, 4, 4);
                n2 = func_020b4b54();
                s2.mUnk_04 = p;
                s2.mUnk_00 = buf2;
                s2.mUnk_0c = 0;
                s2.mUnk_08 = n2;
                func_02024340(&s2, 0, 9, 0xc, 0x40a,
                              GetBmgEntry(func_020b47cc("common.bmg"), data_021759c0->mUnk_18 == 0 ? 0x54 : 0x55));
                func_02024340(&s2, 0, 8, 0xc, 0x40a,
                              GetBmgEntry(func_020b47cc("common.bmg"), data_021759c0->mUnk_18 == 0 ? 0x54 : 0x55));
                s2.mUnk_08 = func_020b4b54();
                func_02024340(&s2, 0, 0x19, 0xe, 0x40a, GetBmgEntry(func_020b47cc("common.bmg"), n));
                func_02024340(&s2, 0, 0x18, 0xe, 0x40a, GetBmgEntry(func_020b47cc("common.bmg"), n));
                func_0200ee74(data_0217b3c4->mNclrNcgrPairs[10].mNcgr->mData,
                              data_0217b3c4->mNclrNcgrPairs[10].mNcgr->mDataSize);
                MemCopyHalfwords(data_0217b3c4->mNclrNcgrPairs[10].mNclr->mData,
                                 data_0217b3c4->mNclrNcgrPairs[0].mNclr->mData, 0x40);
                func_020b46d0(data_0217b3c4->mNclrNcgrPairs[10].mNcgr->mData, 0, 0, 0x20, 4,
                              data_0217b3c4->mNclrNcgrPairs[0].mNcgr->mData, 0, 0);
            }
            break;
        case 4:
            a5 = NULL;
            LoadNcerData(&a5, FindSceneFileWrapper("race_mr_m.NCER"));
            for (i = 0; i < 0x16; i++) {
                data_0217b3c4->mRaceMrMNcerEntries[i] = func_02021f1c(a5, i);
            }
            MemCopyHalfwords(data_0217b3c4->mNclrNcgrPairs[4].mNclr->mData,
                             data_0217b3c4->mNclrNcgrPairs[0].mNclr->mData, 0x40);
            func_020b46d0(data_0217b3c4->mNclrNcgrPairs[4].mNcgr->mData, 0, 0, 0x20, 4,
                          data_0217b3c4->mNclrNcgrPairs[0].mNcgr->mData, 0, 0);
            a6 = NULL;
            LoadNcerData(&a6, FindSceneFileWrapper("race_goal_mr_m.NCER"));
            for (i = 0; i < 8; i++) {
                data_0217b3c4->mRaceGoalMrMNcerEntries[i] = func_02021f1c(a6, i);
            }
            MemCopyHalfwords(data_0217b3c4->mNclrNcgrPairs[5].mNclr->mData,
                             data_0217b3c4->mNclrNcgrPairs[1].mNclr->mData, 0x20);
            func_020b46d0(data_0217b3c4->mNclrNcgrPairs[5].mNcgr->mData, 0, 0, 0x20, 8,
                          data_0217b3c4->mNclrNcgrPairs[1].mNcgr->mData, 0, 0);
            break;
        case 5:
            a7 = NULL;
            LoadNcgrData2(&a7, FindSceneFileWrapper("race_icon_txt.NCGR"));
            q = a7->mData;
            func_020b46d0(q, 0, 0, 8, 2, data_0217b3c4->mNclrNcgrPairs[0].mNcgr->mData, 0x18, 0xe);
            func_020b46d0(q, 0, 0, 8, 2, data_0217b3c4->mNclrNcgrPairs[1].mNcgr->mData, 0x18, 0xe);
            break;
    }

    LoadNclrData(&data_0217b3c4->mNclrNcgrPairs[6].mNclr, FindSceneFileWrapper("race_s_o.NCLR"));
    LoadNclrData(&data_0217b3c4->mNclrNcgrPairs[7].mNclr, FindSceneFileWrapper("race_goal_s_o.NCLR"));
    LoadNclrData(&data_0217b3c4->mNclrNcgrPairs[8].mNclr, FindSceneFileWrapper("race_goal_team_s_o.NCLR"));
    if (data_021759c0->mUseTeams != 0) {
        a8 = NULL;
        m = data_021759c0->mUnk_68[func_020b4d9c()].mUnk_08.mTeamIndex == 0 ? 0x13 : 0x23;
        LoadNclrData(&a8, FindSceneFileWrapper("race_own_character_s_o.NCLR"));
        func_0200ee74(data_0217b3c4->mNclrNcgrPairs[6].mNclr->mData, 0x200);
        for (j = 0; j < 4; j++) {
            data_0217b3c4->mNclrNcgrPairs[6].mNclr->mData[j + 0xb3] = a8->mData[m + j];
        }
    }
    LoadNcgrData2(&data_0217b3c4->mNclrNcgrPairs[6].mNcgr, FindSceneFileWrapper("race_s_o.NCGR"));
    LoadNcgrData2(&data_0217b3c4->mNclrNcgrPairs[7].mNcgr, FindSceneFileWrapper("race_goal_s_o.NCGR"));
    LoadNcgrData2(&data_0217b3c4->mNclrNcgrPairs[8].mNcgr, FindSceneFileWrapper("race_goal_team_s_o.NCGR"));

    p = func_020b403c(0);
    func_02023408(buf3, data_0217b3c4->mNclrNcgrPairs[7].mNcgr->mData, 0x20, 0x10, 4);
    s3.mUnk_00 = buf3;
    s3.mUnk_04 = p;
    s3.mUnk_08 = 1;
    s3.mUnk_0c = 0;
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        x = (i % 2) * 0x68;
        y = (i / 2) * 0x10 + 0x48;
        func_020adff0(i, w3, 1);
        func_02024340(&s3, x, y + 1, i == func_020b4d9c() ? 0xd : 0xf, 0x40a, w3);
        func_02024340(&s3, x, y, i == func_020b4d9c() ? 0xc : 0xe, 0x40a, w3);
    }

    p = func_020b403c(2);
    func_02023408(buf4, data_0217b3c4->mNclrNcgrPairs[7].mNcgr->mData, 0x20, 0x10, 4);
    s4.mUnk_00 = buf4;
    s4.mUnk_04 = p;
    s4.mUnk_08 = 1;
    s4.mUnk_0c = 0;
    func_02024340(&s4, 0x20, 0x38, 0xe, 0x40a, GetBmgEntry(func_020b47cc("common.bmg"), 0x79));

    p = func_020b403c(0);
    func_02023408(buf5, data_0217b3c4->mNclrNcgrPairs[8].mNcgr->mData, 0x20, 0xa, 4);
    s5.mUnk_00 = buf5;
    s5.mUnk_04 = p;
    s5.mUnk_08 = 1;
    s5.mUnk_0c = 0;
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        x2 = (i % 4) * 0x38;
        y2 = (i / 4) * 0x10 + 0x38;
        func_020adff0(i, w5, 0);
        if (i == func_020b4d9c()) {
            if (data_021759c0->mUseTeams != 0) {
                if (data_021759c0->mUnk_68[i].mUnk_08.mTeamIndex == 0) {
                    b = 0xa;
                    c = 0xb;
                } else {
                    b = 8;
                    c = 9;
                }
            } else {
                b = 0xc;
                c = 0xd;
            }
        } else {
            b = 0xe;
            c = 0xf;
        }
        func_02024340(&s5, x2, y2 + 1, c, 0x40a, w5);
        func_02024340(&s5, x2, y2, b, 0x40a, w5);
    }

    a9 = NULL;
    LoadNcerData(&a9, FindSceneFileWrapper("race_s.NCER"));
    for (i = 0; i < 0xc9; i++) {
        data_0217b3c4->mRaceSNcerEntries[i] = func_02021f1c(a9, i);
    }
    a10 = NULL;
    LoadNcerData(&a10, FindSceneFileWrapper("race_goal_s.NCER"));
    for (i = 0; i < 0x2c; i++) {
        data_0217b3c4->mRaceGoalSNcerEntries[i] = func_02021f1c(a10, i);
    }
    a11 = NULL;
    LoadNcerData(&a11, FindSceneFileWrapper("race_goal_team_s.NCER"));
    for (i = 0; i < 0x28; i++) {
        data_0217b3c4->mRaceGoalTeamSNcerEntries[i] = func_02021f1c(a11, i);
    }

    if (data_021759c0->mUnk_08 != 1) {
        return;
    }
    LoadNclrData(&data_0217b3c4->mNclrNcgrPairs[9].mNclr, FindSceneFileWrapper("race_new_record_ta_s_o.NCLR"));
    LoadNcgrData2(&data_0217b3c4->mNclrNcgrPairs[9].mNcgr, FindSceneFileWrapper("race_new_record_ta_s_o.NCGR"));
    p = func_020b403c(0);
    func_02023408(buf6, data_0217b3c4->mNclrNcgrPairs[9].mNcgr->mData, 0x20, 0x10, 4);
    s6.mUnk_00 = buf6;
    s6.mUnk_04 = p;
    s6.mUnk_08 = 1;
    s6.mUnk_0c = 0;
    for (i = 0; i < 7; i++) {
        y3 = (i / 2) * 0x10 + 0x49;
        func_020b6c74(i, w6, 1);
        x3 = (i % 2) * 0x68;
        func_02024340(&s6, x3, y3 + 1, 0xf, 0x40a, w6);
        func_02024340(&s6, x3, y3, 0xe, 0x40a, w6);
    }
    a12 = NULL;
    LoadNcerData(&a12, FindSceneFileWrapper("race_new_record_ta_s.NCER"));
    for (i = 0; i < 0x21; i++) {
        data_0217b3c4->mRaceNewRecordTaSNcerEntries[i] = func_02021f1c(a12, i);
    }
}

u32 func_020b8610(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b3c4;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

Unk0217b3c4_7dc *GetRaceNclrNcgr(u32 a) {
    return &data_0217b3c4->mNclrNcgrPairs[a];
}

Unk020224e0_c *GetRaceMNcerEntry(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) &data_0217b3c4;
    value1 = (u32) * (const u32 *) ((value1) + (0));
    value0 = (u32) * (const u32 *) ((value1) + ((value0 << 2)));
    return (Unk020224e0_c *) value0;
}

u32 LookupRaceMNcerIndex(u32 a) {
    u32 r;
    Unk020ee684 *p;
    enum { K0 } j;

    r = 0xb;
    switch (a) {
        case 0:
            r = 0x12;
            break;
        case 1:
            r = 0x10;
            break;
        case 2:
            r = 0x17;
            break;
        case 3:
            r = 0x14;
            break;
        case 4:
            r = 0xd;
            break;
        case 5:
            p = &data_027e00c8[func_020b4d9c()];
            j = p->mUnk_030.mUnk_00;
            switch (data_0217bc48[j].mUnk_08 == 3 ? (u16) p->mUnk_030.mUnk_08 : 0) {
                case 1:
                    r = 0xd;
                    break;
                case 2:
                    r = 0xe;
                    break;
                case 0:
                case 3:
                    r = 0xf;
                    break;
            }
            break;
        case 6:
            r = 0x16;
            break;
        case 7:
            r = 0x1b;
            break;
        case 8:
            r = 0x19;
            break;
        case 9:
            r = 0x13;
            break;
        case 10:
            r = 0x18;
            break;
        case 11:
            r = 0x11;
            break;
        case 12:
            r = 0x1a;
            break;
        case 13:
            r = 0x1e;
            break;
        case 14:
            r = 0x1c;
            break;
        case 15:
            r = 0x1d;
            break;
        case 16:
            r = 0x15;
            break;
        case 17:
            r = 0x1f;
            break;
        case 18:
        case 19:
            break;
    }
    return r;
}

Unk020224e0_c *GetRaceGoalMNcerEntry(u32 p0) {
    return ((Unk020224e0_c *) data_0217b3c4->mRaceGoalMNcerEntries[p0]);
}

Unk020224e0_c *GetRaceTaMNcerEntry(u32 p0) {
    return ((Unk020224e0_c *) data_0217b3c4->mRaceTaMNcerEntries[p0]);
}

Unk020224e0_c *GetRaceBattleMNcerEntry(u32 p0) {
    return ((Unk020224e0_c *) data_0217b3c4->mRaceBattleMNcerEntries[p0]);
}

Unk020224e0_c *GetRaceMrMNcerEntry(u32 p0) {
    return ((Unk020224e0_c *) data_0217b3c4->mRaceMrMNcerEntries[p0]);
}

Unk020224e0_c *GetRaceGoalMrMNcerEntry(u32 p0) {
    return ((Unk020224e0_c *) data_0217b3c4->mRaceGoalMrMNcerEntries[p0]);
}

Unk020224e0_c *GetRaceSNcerEntry(u32 p0) {
    return ((Unk020224e0_c *) data_0217b3c4->mRaceSNcerEntries[p0]);
}

Unk020224e0_c *GetRaceGoalSNcerEntry(u32 p0) {
    return ((Unk020224e0_c *) data_0217b3c4->mRaceGoalSNcerEntries[p0]);
}

Unk020224e0_c *GetRaceGoalTeamSNcerEntry(u32 p0) {
    return ((Unk020224e0_c *) data_0217b3c4->mRaceGoalTeamSNcerEntries[p0]);
}

Unk020224e0_c *GetRaceNewRecordTaSNcerEntry(u32 p0) {
    return ((Unk020224e0_c *) data_0217b3c4->mRaceNewRecordTaSNcerEntries[p0]);
}

Unk020224e0_c *GetRaceStartBattleMNcerEntry(u32 p0) {
    return ((Unk020224e0_c *) data_0217b3c4->mRaceStartBattleMNcerEntries[p0]);
}

s32 LookupRaceSNcerIndex(s32 a, s32 b) {
    Unk020ee684 *p;
    u32 k;
    enum { K0 } j;

    switch (b) {
        case 0:
            return 0x1b;
        case 1:
            return 0x14;
        case 2:
            return 0x22;
        case 3:
            return 0x17;
        case 4:
            return 0x11;
        case 5:
            p = &data_027e00c8[(u16) a];
            j = p->mUnk_030.mUnk_00;
            if (data_0217bc48[j].mUnk_08 == 3) {
                k = (u16) p->mUnk_030.mUnk_08;
            } else {
                k = 0;
            }
            switch (k) {
                case 1:
                    return 0x11;
                case 2:
                    return 0x12;
                case 0:
                case 3:
                    return 0x13;
            }
            break;
        case 6:
            return 0x1f;
        case 7:
            return 0x20;
        case 8:
            return 0x21;
        case 9:
            return 0x1c;
        case 10:
            return 0x23;
        case 11:
            return 0x15;
        case 12:
            return 0x19;
        case 13:
            return 0x18;
        case 14:
            return 0x1d;
        case 16:
            return 0x1e;
        case 15:
            return 0x1a;
        case 17:
            return 0x16;
    }
    return a;
}

void func_020b80a8(void) {
    void *p;
    void *a;
    u16 i;
    s32 y;
    s32 x;
    s32 b;
    s32 c;
    BOOL k;
    u8 v1[0x20];
    Unk02180728 o;
    u16 t[22];

    p = func_020b403c(0);
    a = func_0212b090();
    func_0212b09c();
    func_02023408(v1, a, 0x20, 4, 4);
    o.mUnk_00 = v1;
    o.mUnk_08 = 1;
    o.mUnk_04 = p;
    o.mUnk_0c = 0;
    i = 0;
    k = FALSE;
    for (; i < 8; i++) {
        y = (i % 4) << 6;
        x = (((u32) i >> 2) << 4) + 8;
        func_020adff0(i, t, k);
        if (i == func_020b4d9c()) {
            if (data_021759c0->mUseTeams != 0) {
                if (data_021759c0->mUnk_68[i].mUnk_08.mTeamIndex == 0) {
                    b = 10;
                    c = 11;
                } else {
                    b = 8;
                    c = 9;
                }
            } else {
                b = 12;
                c = 13;
            }
        } else {
            b = 14;
            c = 15;
        }
        func_02024340(&o, y, x + 1, c, 0x40a, t);
        func_02024340(&o, y, x, b, 0x40a, t);
    }
}

void func_020b7fd8(s32 a, s32 *b, s32 *c) {
    s32 t;

    *b = data_021759c0->mUnk_68[a].mCharacterIndex;
    switch (*b) {
        case 0:
        case 2:
        case 8:
        case 10:
        case 11:
            *c = 7;
            break;
        case 1:
        case 3:
        case 9:
            *c = 8;
            break;
        case 4:
        case 5:
            *c = 9;
            break;
        case 6:
        case 7:
            *c = 10;
            break;
        case 12:
            t = data_0217b488->mUnk_10c[a];
            *b = t % 4 + 12;
            if (t < 4) {
                *c = 5;
            } else {
                *c = 6;
            }
            break;
    }
}

void func_020b7ee8(s32 a, s32 *b, s32 *c) {
    Unk02056bc0 t;

    func_02056bc0(data_021759c0->mCourseId, a, &t);
    if (t.mUnk_18 != 0) {
        *b = t.mUnk_19;
    } else {
        *b = 0;
        *c = 0;
        return;
    }
    switch (*b) {
        case 0:
        case 2:
        case 8:
        case 10:
        case 11:
            *c = 7;
            break;
        case 1:
        case 3:
        case 9:
            *c = 8;
            break;
        case 4:
        case 5:
            *c = 9;
            break;
        case 6:
        case 7:
            *c = 10;
            break;
        case 12:
            break;
    }
}

void CopyRaceTransferMapMrSO(u16 *a, void *b) {
    Ncgr *o = NULL;
    void *p;
    Nclr *v1;
    Nclr *v2;
    Nclr *v3;
    Nclr *v4;
    Nclr *v5;
    Nclr *v6;
    Nclr *v7;
    s32 i;

    LoadNcgrData2(&o, FindSceneFileWrapper("race_transfer_map_mr_s_o.NCGR"));
    p = o->mData;
    switch (data_021759c0->mUnk_2e) {
        case 0x9:
            func_020b46d0(p, 0x0, 0, 4, 4, b, 0, 12);
            v1 = NULL;
            LoadNclrData(&v1, FindSceneFileWrapper("race_transfer_map_mr_s_o.NCLR"));
            for (i = 0; i < 16; i++) {
                a[0x50 + i] = v1->mData[0x0 + i];
            }
            break;
        case 0x32:
            func_020b46d0(p, 0x4, 0, 8, 4, b, 0, 12);
            v2 = NULL;
            LoadNclrData(&v2, FindSceneFileWrapper("race_transfer_map_mr_s_o.NCLR"));
            for (i = 0; i < 16; i++) {
                a[0x50 + i] = v2->mData[0x10 + i];
            }
            break;
        case 0x15:
            func_020b46d0(p, 0xc, 0, 4, 4, b, 0, 12);
            v3 = NULL;
            LoadNclrData(&v3, FindSceneFileWrapper("race_transfer_map_mr_s_o.NCLR"));
            for (i = 0; i < 16; i++) {
                a[0x50 + i] = v3->mData[0x20 + i];
            }
            break;
        case 0x33:
            func_020b46d0(p, 0x10, 0, 4, 4, b, 0, 12);
            v4 = NULL;
            LoadNclrData(&v4, FindSceneFileWrapper("race_transfer_map_mr_s_o.NCLR"));
            for (i = 0; i < 16; i++) {
                a[0x50 + i] = v4->mData[0x50 + i];
            }
            break;
        case 0x11:
            func_020b46d0(p, 0x14, 0, 4, 4, b, 0, 12);
            v5 = NULL;
            LoadNclrData(&v5, FindSceneFileWrapper("race_transfer_map_mr_s_o.NCLR"));
            for (i = 0; i < 16; i++) {
                a[0x50 + i] = v5->mData[0x60 + i];
            }
            break;
        case 0xa:
            func_020b46d0(p, 0x18, 0, 4, 4, b, 0, 12);
            v6 = NULL;
            LoadNclrData(&v6, FindSceneFileWrapper("race_transfer_map_mr_s_o.NCLR"));
            for (i = 0; i < 16; i++) {
                a[0x50 + i] = v6->mData[0x70 + i];
            }
            break;
        case 0x31:
            func_020b46d0(p, 0x0, 4, 8, 4, b, 0, 12);
            v7 = NULL;
            LoadNclrData(&v7, FindSceneFileWrapper("race_transfer_map_mr_s_o.NCLR"));
            for (i = 0; i < 16; i++) {
                a[0x50 + i] = v7->mData[0x80 + i];
            }
            break;
    }
}

void func_020b6e00(u16 *a, void *b) {
    s32 x;
    s32 y;
    Ncgr *o = NULL;
    Nclr *q1;
    Nclr *q2;
    Nclr *q3;
    Nclr *q4;
    Nclr *q5;
    Nclr *q6;
    Nclr *q7;
    Nclr *q8;
    Nclr *q9;
    Nclr *q10;
    Nclr *q11;
    Nclr *q12;
    Nclr *q13;
    Nclr *q14;
    Nclr *q15;
    void *p;
    u8 i;
    u8 j;
    u8 k;
    s32 n;
    Unk020b6e00 *r;

    LoadNcgrData2(&o, FindSceneFileWrapper("race_transfer_s_o.NCGR"));
    p = o->mData;
    for (i = 0; i < (s32) data_021759c0->mKartCount; i++) {
        func_020b7fd8(i, &x, &y);
        func_020b46d0(p, x << 1, 0, 2, 2, b, i << 1, 0);
        r = (Unk020b6e00 *) data_0217b3c4->mRaceSNcerEntries[i]->mUnk_04;
        r->mUnk_04 = (r->mUnk_04 & 0xfff) + (y << 12);
    }
    for (j = 0; j < (s32) data_021759c0->mKartCount; j++) {
        func_020b7fd8(j, &x, &y);
        func_020b46d0(p, x << 1, 2, 2, 2, b, (j << 1) + 0x10, 0);
        r = (Unk020b6e00 *) data_0217b3c4->mRaceSNcerEntries[j + 8]->mUnk_04;
        r->mUnk_04 = (r->mUnk_04 & 0xfff) + (y << 12);
        r = (Unk020b6e00 *) data_0217b3c4->mRaceGoalSNcerEntries[j]->mUnk_04;
        r->mUnk_04 = (r->mUnk_04 & 0xfff) + (y << 12);
        r = (Unk020b6e00 *) data_0217b3c4->mRaceGoalTeamSNcerEntries[j]->mUnk_04;
        r->mUnk_04 = (r->mUnk_04 & 0xfff) + (y << 12);
        if (data_021759c0->mUnk_08 == 1) {
            r = (Unk020b6e00 *) data_0217b3c4->mRaceNewRecordTaSNcerEntries[j + 7]->mUnk_04;
            r->mUnk_04 = (r->mUnk_04 & 0xfff) + (y << 12);
        }
    }
    if (data_021759c0->mUnk_08 == 1) {
        for (j = 0; j < 6; j++) {
            func_020b7ee8(j, &x, &y);
            func_020b46d0(p, x << 1, 2, 2, 2, b, ((j + 2) << 1) + 0x10, 0);
            r = (Unk020b6e00 *) data_0217b3c4->mRaceNewRecordTaSNcerEntries[j + 8]->mUnk_04;
            r->mUnk_04 = (r->mUnk_04 & 0xfff) + (y << 12);
        }
    }
    for (k = 0; k < (s32) data_021759c0->mKartCount; k++) {
        s32 t[8][2] = {{16, 8}, {16, 10}, {11, 12}, {18, 12}, {25, 12}, {11, 14}, {18, 14}, {25, 14}};

        func_020b46d0(func_0212b090(), (k % 4) << 3, ((u32) k >> 2) << 1, 7, 2, b, t[k][0], t[k][1]);
    }
    func_0212b09c();
    LoadNcgrData2(&o, FindSceneFileWrapper("race_transfer_map_s_o.NCGR"));
    p = o->mData;
    if (data_021759c0->mUnk_08 == 2) {
        func_020b46d0(p, 0x14, 6, 0xc, 4, b, 0, 8);
        func_020b46d0(p, 0x14, 0xa, 0xb, 4, b, 0, 0xc);
        q1 = NULL;
        LoadNclrData(&q1, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
        for (n = 0; n < 16; n++) {
            a[0x40 + n] = q1->mData[0xd0 + n];
        }
    } else {
        switch (data_021759c0->mCourseId) {
            case 15:
            case 31:
            case 46:
                func_020b46d0(p, 0x0, 0, 4, 2, b, 0, 8);
                q2 = NULL;
                LoadNclrData(&q2, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q2->mData[n];
                }
                break;
            case 10:
            case 18:
            case 35:
                func_020b46d0(p, 0x4, 0, 5, 2, b, 0, 8);
                q3 = NULL;
                LoadNclrData(&q3, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q3->mData[0x10 + n];
                }
                break;
            case 27:
                func_020b46d0(p, 0x9, 0, 6, 2, b, 0, 8);
                q4 = NULL;
                LoadNclrData(&q4, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q4->mData[0x20 + n];
                }
                break;
            case 36:
                func_020b46d0(p, 0xf, 0, 3, 2, b, 0, 8);
                q5 = NULL;
                LoadNclrData(&q5, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q5->mData[0x30 + n];
                }
                break;
            case 33:
                func_020b46d0(p, 0, 2, 0xc, 4, b, 0, 8);
                func_020b46d0(p, 0, 6, 0xb, 4, b, 0, 0xc);
                if (data_021759c0->mUnk_57 != 0) {
                    func_020b45b0(p, 0, 2, 8, 8, b, 0, 8);
                }
                q6 = NULL;
                LoadNclrData(&q6, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q6->mData[0x40 + n];
                }
                break;
            case 24:
            case 38:
                func_020b46d0(p, 0x14, 0, 8, 4, b, 0, 8);
                q7 = NULL;
                LoadNclrData(&q7, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q7->mData[0x50 + n];
                }
                break;
            case 16:
            case 30:
                func_020b46d0(p, 0x1d, 0, 3, 2, b, 0, 8);
                q8 = NULL;
                LoadNclrData(&q8, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q8->mData[0x60 + n];
                }
                break;
            case 17:
                func_020b46d0(p, 0xc, 4, 8, 4, b, 0, 8);
                q9 = NULL;
                LoadNclrData(&q9, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q9->mData[0x70 + n];
                }
                break;
            case 1:
            case 9:
            case 25:
            case 39:
                func_020b46d0(p, 0xc, 2, 8, 2, b, 0, 8);
                q10 = NULL;
                LoadNclrData(&q10, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q10->mData[0x80 + n];
                }
                break;
            case 11:
            case 14:
            case 19:
            case 26:
                func_020b46d0(p, 0x13, 4, 12, 4, b, 0, 8);
                q11 = NULL;
                LoadNclrData(&q11, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q11->mData[0x90 + n];
                }
                break;
            case 34:
                func_020b46d0(p, 0x8, 10, 8, 4, b, 0, 8);
                q12 = NULL;
                LoadNclrData(&q12, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q12->mData[0x80 + n];
                }
                break;
            case 12:
            case 32:
                func_020b46d0(p, 0xc, 8, 8, 2, b, 0, 8);
                q13 = NULL;
                LoadNclrData(&q13, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q13->mData[0xa0 + n];
                }
                break;
            case 29:
                func_020b46d0(p, 0x12, 10, 2, 2, b, 0, 8);
                q14 = NULL;
                LoadNclrData(&q14, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q14->mData[0xb0 + n];
                }
                break;
            case 23:
                func_020b46d0(p, 0x0, 10, 8, 6, b, 0, 8);
                q15 = NULL;
                LoadNclrData(&q15, FindSceneFileWrapper("race_transfer_map_s_o.NCLR"));
                for (n = 0; n < 16; n++) {
                    a[0x40 + n] = q15->mData[0xe0 + n];
                }
                break;
        }
    }
    if (data_021759c0->mUnk_08 == 4) {
        CopyRaceTransferMapMrSO(a, b);
    }
}
