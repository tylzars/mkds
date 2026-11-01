#include "Main/Unknown/code_020b8624.h"
#include "Main/Unknown/code_020ad000.h"
#include "Main/Unknown/code_020b6000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02025d8c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02021e8c.h"
#include "code_0214cfe4.h"

void func_020b8624(void) {
    Unk02021dc8 *a0;
    Unk02021dc8 *a1;
    Unk02021dc8 *a2;
    Unk02021dc8 *a3;
    Unk02021dc8 *a4;
    Unk02021dc8 *a5;
    Unk02021dc8 *a6;
    Unk020b4934 *a7;
    Unk020b4a44 *a8;
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

    data_0217b3c4 = func_02036bec(func_020364e0(func_020364e8()), 0x88c);
    for (i = 0; i < 0x38; i++) {
        data_0217b3c4->mUnk_000[i] = 0;
    }
    for (i = 0; i < 0x44; i++) {
        data_0217b3c4->mUnk_0e0[i] = 0;
    }
    for (i = 0; i < 0xf; i++) {
        data_0217b3c4->mUnk_1f0[i] = 0;
    }
    for (i = 0; i < 0xd; i++) {
        data_0217b3c4->mUnk_22c[i] = 0;
    }
    for (i = 0; i < 0x16; i++) {
        data_0217b3c4->mUnk_260[i] = 0;
    }
    for (i = 0; i < 8; i++) {
        data_0217b3c4->mUnk_2b8[i] = 0;
    }
    for (i = 0; i < 0xc9; i++) {
        data_0217b3c4->mUnk_2d8[i] = 0;
    }
    for (i = 0; i < 0x2c; i++) {
        data_0217b3c4->mUnk_5fc[i] = 0;
    }
    for (i = 0; i < 0x28; i++) {
        data_0217b3c4->mUnk_6ac[i] = 0;
    }
    for (i = 0; i < 0x21; i++) {
        data_0217b3c4->mUnk_74c[i] = 0;
    }
    for (i = 0; i < 3; i++) {
        data_0217b3c4->mUnk_7d0[i] = 0;
    }

    func_020b4a7c(&data_0217b3c4->mUnk_7dc[0].mUnk_00, func_020b47c0("race_m_o.NCLR"));
    func_020b4a7c(&data_0217b3c4->mUnk_7dc[1].mUnk_00, func_020b47c0("race_goal_m_o.NCLR"));
    switch (data_021759c0->mUnk_08) {
        case 1:
            data_0217b3c4->mUnk_7dc[2].mUnk_00 = data_0217b3c4->mUnk_7dc[0].mUnk_00;
            break;
        case 2:
            func_020b4a7c(&data_0217b3c4->mUnk_7dc[3].mUnk_00, func_020b47c0("race_battle_m_o.NCLR"));
            if (data_021759c0->mUnk_00c == 4) {
                func_020b4a7c(&data_0217b3c4->mUnk_7dc[10].mUnk_00, func_020b47c0("race_start_battle_m_o.NCLR"));
            }
            break;
        case 4:
            func_020b4a7c(&data_0217b3c4->mUnk_7dc[4].mUnk_00, func_020b47c0("race_mr_m_o.NCLR"));
            func_020b4a7c(&data_0217b3c4->mUnk_7dc[5].mUnk_00, func_020b47c0("race_goal_mr_m_o.NCLR"));
            break;
        case 5:
            break;
    }

    func_020b49f4(&data_0217b3c4->mUnk_7dc[0].mUnk_04, func_020b47c0("race_m_o.NCGR"));
    func_020b49f4(&data_0217b3c4->mUnk_7dc[1].mUnk_04, func_020b47c0("race_goal_m_o.NCGR"));
    switch (data_021759c0->mUnk_08) {
        case 1:
            func_020b49f4(&data_0217b3c4->mUnk_7dc[2].mUnk_04, func_020b47c0("race_ta_m_o.NCGR"));
            break;
        case 2:
            func_020b49f4(&data_0217b3c4->mUnk_7dc[3].mUnk_04, func_020b47c0("race_battle_m_o.NCGR"));
            if (data_021759c0->mUnk_00c == 4) {
                func_020b49f4(&data_0217b3c4->mUnk_7dc[10].mUnk_04, func_020b47c0("race_start_battle_m_o.NCGR"));
            }
            break;
        case 4:
            func_020b49f4(&data_0217b3c4->mUnk_7dc[4].mUnk_04, func_020b47c0("race_mr_m_o.NCGR"));
            func_020b49f4(&data_0217b3c4->mUnk_7dc[5].mUnk_04, func_020b47c0("race_goal_mr_m_o.NCGR"));
            break;
        case 5:
            break;
    }

    a0 = 0;
    func_020b48ec(&a0, func_020b47c0("race_m.NCER"));
    for (i = 0; i < 0x38; i++) {
        data_0217b3c4->mUnk_000[i] = func_02021f1c(a0, i);
    }
    a1 = 0;
    func_020b48ec(&a1, func_020b47c0("race_goal_m.NCER"));
    for (i = 0; i < 0x44; i++) {
        data_0217b3c4->mUnk_0e0[i] = func_02021f1c(a1, i);
    }

    switch (data_021759c0->mUnk_08) {
        case 1:
            p = func_020b403c(2);
            func_02023408(buf0, data_0217b3c4->mUnk_7dc[1].mUnk_04->mUnk_14, 0x20, 0x10, 4);
            s0.mUnk_08 = func_020b4acc();
            s0.mUnk_00 = buf0;
            s0.mUnk_04 = p;
            s0.mUnk_0c = 0;
            func_02024340(&s0, 0x80, 0x38, 0xe, 0x412, func_020b3f7c(func_020b47cc("common.bmg"), 0x81));
            func_0200ee74(data_0217b3c4->mUnk_7dc[1].mUnk_04->mUnk_14, data_0217b3c4->mUnk_7dc[1].mUnk_04->mUnk_10);
            a2 = 0;
            func_020b48ec(&a2, func_020b47c0("race_ta_m.NCER"));
            for (i = 0; i < 0xf; i++) {
                data_0217b3c4->mUnk_1f0[i] = func_02021f1c(a2, i);
            }
            p = func_020b403c(2);
            func_02023408(buf1, data_0217b3c4->mUnk_7dc[2].mUnk_04->mUnk_14, 0x20, 4, 4);
            s1.mUnk_08 = func_020b4acc();
            s1.mUnk_00 = buf1;
            s1.mUnk_04 = p;
            s1.mUnk_0c = 0;
            func_02024340(&s1, 0x80, 0x18, 0xe, 0x412, func_020b3f7c(func_020b47cc("common.bmg"), 0x6d));
            func_0200ee74(data_0217b3c4->mUnk_7dc[2].mUnk_04->mUnk_14, data_0217b3c4->mUnk_7dc[2].mUnk_04->mUnk_10);
            func_020b46d0(data_0217b3c4->mUnk_7dc[2].mUnk_04->mUnk_14, 0, 0, 0x20, 4,
                          data_0217b3c4->mUnk_7dc[0].mUnk_04->mUnk_14, 0, 0);
            break;
        case 2:
            if (data_021759c0->mUnk_00c != 4) {
                a3 = 0;
                func_020b48ec(&a3, func_020b47c0("race_battle_m.NCER"));
                for (i = 0; i < 0xd; i++) {
                    data_0217b3c4->mUnk_22c[i] = func_02021f1c(a3, i);
                }
                func_0214cffc(data_0217b3c4->mUnk_7dc[3].mUnk_00->mUnk_0c, data_0217b3c4->mUnk_7dc[0].mUnk_00->mUnk_0c,
                              0x40);
                func_020b46d0(data_0217b3c4->mUnk_7dc[3].mUnk_04->mUnk_14, 0, 0, 0x20, 4,
                              data_0217b3c4->mUnk_7dc[0].mUnk_04->mUnk_14, 0, 0);
            } else {
                a4 = 0;
                func_020b48ec(&a4, func_020b47c0("race_start_battle_m.NCER"));
                for (i = 0; i < 3; i++) {
                    data_0217b3c4->mUnk_7d0[i] = func_02021f1c(a4, i);
                }
                p = func_020b403c(2);
                n = func_02025d8c(data_021759c0->mUnk_00);
                func_02023408(buf2, data_0217b3c4->mUnk_7dc[10].mUnk_04->mUnk_14, 0x20, 4, 4);
                n2 = func_020b4b54();
                s2.mUnk_04 = p;
                s2.mUnk_00 = buf2;
                s2.mUnk_0c = 0;
                s2.mUnk_08 = n2;
                func_02024340(&s2, 0, 9, 0xc, 0x40a,
                              func_020b3f7c(func_020b47cc("common.bmg"), data_021759c0->mUnk_18 == 0 ? 0x54 : 0x55));
                func_02024340(&s2, 0, 8, 0xc, 0x40a,
                              func_020b3f7c(func_020b47cc("common.bmg"), data_021759c0->mUnk_18 == 0 ? 0x54 : 0x55));
                s2.mUnk_08 = func_020b4b54();
                func_02024340(&s2, 0, 0x19, 0xe, 0x40a, func_020b3f7c(func_020b47cc("common.bmg"), n));
                func_02024340(&s2, 0, 0x18, 0xe, 0x40a, func_020b3f7c(func_020b47cc("common.bmg"), n));
                func_0200ee74(data_0217b3c4->mUnk_7dc[10].mUnk_04->mUnk_14,
                              data_0217b3c4->mUnk_7dc[10].mUnk_04->mUnk_10);
                func_0214cffc(data_0217b3c4->mUnk_7dc[10].mUnk_00->mUnk_0c, data_0217b3c4->mUnk_7dc[0].mUnk_00->mUnk_0c,
                              0x40);
                func_020b46d0(data_0217b3c4->mUnk_7dc[10].mUnk_04->mUnk_14, 0, 0, 0x20, 4,
                              data_0217b3c4->mUnk_7dc[0].mUnk_04->mUnk_14, 0, 0);
            }
            break;
        case 4:
            a5 = 0;
            func_020b48ec(&a5, func_020b47c0("race_mr_m.NCER"));
            for (i = 0; i < 0x16; i++) {
                data_0217b3c4->mUnk_260[i] = func_02021f1c(a5, i);
            }
            func_0214cffc(data_0217b3c4->mUnk_7dc[4].mUnk_00->mUnk_0c, data_0217b3c4->mUnk_7dc[0].mUnk_00->mUnk_0c,
                          0x40);
            func_020b46d0(data_0217b3c4->mUnk_7dc[4].mUnk_04->mUnk_14, 0, 0, 0x20, 4,
                          data_0217b3c4->mUnk_7dc[0].mUnk_04->mUnk_14, 0, 0);
            a6 = 0;
            func_020b48ec(&a6, func_020b47c0("race_goal_mr_m.NCER"));
            for (i = 0; i < 8; i++) {
                data_0217b3c4->mUnk_2b8[i] = func_02021f1c(a6, i);
            }
            func_0214cffc(data_0217b3c4->mUnk_7dc[5].mUnk_00->mUnk_0c, data_0217b3c4->mUnk_7dc[1].mUnk_00->mUnk_0c,
                          0x20);
            func_020b46d0(data_0217b3c4->mUnk_7dc[5].mUnk_04->mUnk_14, 0, 0, 0x20, 8,
                          data_0217b3c4->mUnk_7dc[1].mUnk_04->mUnk_14, 0, 0);
            break;
        case 5:
            a7 = 0;
            func_020b49f4(&a7, func_020b47c0("race_icon_txt.NCGR"));
            q = a7->mUnk_14;
            func_020b46d0(q, 0, 0, 8, 2, data_0217b3c4->mUnk_7dc[0].mUnk_04->mUnk_14, 0x18, 0xe);
            func_020b46d0(q, 0, 0, 8, 2, data_0217b3c4->mUnk_7dc[1].mUnk_04->mUnk_14, 0x18, 0xe);
            break;
    }

    func_020b4a7c(&data_0217b3c4->mUnk_7dc[6].mUnk_00, func_020b47c0("race_s_o.NCLR"));
    func_020b4a7c(&data_0217b3c4->mUnk_7dc[7].mUnk_00, func_020b47c0("race_goal_s_o.NCLR"));
    func_020b4a7c(&data_0217b3c4->mUnk_7dc[8].mUnk_00, func_020b47c0("race_goal_team_s_o.NCLR"));
    if (data_021759c0->mUnk_58 != 0) {
        a8 = 0;
        m = data_021759c0->mUnk_68[func_020b4d9c()].mUnk_08.mUnk_04 == 0 ? 0x13 : 0x23;
        func_020b4a7c(&a8, func_020b47c0("race_own_character_s_o.NCLR"));
        func_0200ee74(data_0217b3c4->mUnk_7dc[6].mUnk_00->mUnk_0c, 0x200);
        for (j = 0; j < 4; j++) {
            data_0217b3c4->mUnk_7dc[6].mUnk_00->mUnk_0c[j + 0xb3] = a8->mUnk_0c[m + j];
        }
    }
    func_020b49f4(&data_0217b3c4->mUnk_7dc[6].mUnk_04, func_020b47c0("race_s_o.NCGR"));
    func_020b49f4(&data_0217b3c4->mUnk_7dc[7].mUnk_04, func_020b47c0("race_goal_s_o.NCGR"));
    func_020b49f4(&data_0217b3c4->mUnk_7dc[8].mUnk_04, func_020b47c0("race_goal_team_s_o.NCGR"));

    p = func_020b403c(0);
    func_02023408(buf3, data_0217b3c4->mUnk_7dc[7].mUnk_04->mUnk_14, 0x20, 0x10, 4);
    s3.mUnk_00 = buf3;
    s3.mUnk_04 = p;
    s3.mUnk_08 = 1;
    s3.mUnk_0c = 0;
    for (i = 0; i < (u32) data_021759c0->mUnk_3d0; i++) {
        x = (i % 2) * 0x68;
        y = (i / 2) * 0x10 + 0x48;
        func_020adff0(i, w3, 1);
        func_02024340(&s3, x, y + 1, i == func_020b4d9c() ? 0xd : 0xf, 0x40a, w3);
        func_02024340(&s3, x, y, i == func_020b4d9c() ? 0xc : 0xe, 0x40a, w3);
    }

    p = func_020b403c(2);
    func_02023408(buf4, data_0217b3c4->mUnk_7dc[7].mUnk_04->mUnk_14, 0x20, 0x10, 4);
    s4.mUnk_00 = buf4;
    s4.mUnk_04 = p;
    s4.mUnk_08 = 1;
    s4.mUnk_0c = 0;
    func_02024340(&s4, 0x20, 0x38, 0xe, 0x40a, func_020b3f7c(func_020b47cc("common.bmg"), 0x79));

    p = func_020b403c(0);
    func_02023408(buf5, data_0217b3c4->mUnk_7dc[8].mUnk_04->mUnk_14, 0x20, 0xa, 4);
    s5.mUnk_00 = buf5;
    s5.mUnk_04 = p;
    s5.mUnk_08 = 1;
    s5.mUnk_0c = 0;
    for (i = 0; i < (u32) data_021759c0->mUnk_3d0; i++) {
        x2 = (i % 4) * 0x38;
        y2 = (i / 4) * 0x10 + 0x38;
        func_020adff0(i, w5, 0);
        if (i == func_020b4d9c()) {
            if (data_021759c0->mUnk_58 != 0) {
                if (data_021759c0->mUnk_68[i].mUnk_08.mUnk_04 == 0) {
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

    a9 = 0;
    func_020b48ec(&a9, func_020b47c0("race_s.NCER"));
    for (i = 0; i < 0xc9; i++) {
        data_0217b3c4->mUnk_2d8[i] = func_02021f1c(a9, i);
    }
    a10 = 0;
    func_020b48ec(&a10, func_020b47c0("race_goal_s.NCER"));
    for (i = 0; i < 0x2c; i++) {
        data_0217b3c4->mUnk_5fc[i] = func_02021f1c(a10, i);
    }
    a11 = 0;
    func_020b48ec(&a11, func_020b47c0("race_goal_team_s.NCER"));
    for (i = 0; i < 0x28; i++) {
        data_0217b3c4->mUnk_6ac[i] = func_02021f1c(a11, i);
    }

    if (data_021759c0->mUnk_08 != 1) {
        return;
    }
    func_020b4a7c(&data_0217b3c4->mUnk_7dc[9].mUnk_00, func_020b47c0("race_new_record_ta_s_o.NCLR"));
    func_020b49f4(&data_0217b3c4->mUnk_7dc[9].mUnk_04, func_020b47c0("race_new_record_ta_s_o.NCGR"));
    p = func_020b403c(0);
    func_02023408(buf6, data_0217b3c4->mUnk_7dc[9].mUnk_04->mUnk_14, 0x20, 0x10, 4);
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
    a12 = 0;
    func_020b48ec(&a12, func_020b47c0("race_new_record_ta_s.NCER"));
    for (i = 0; i < 0x21; i++) {
        data_0217b3c4->mUnk_74c[i] = func_02021f1c(a12, i);
    }
}
