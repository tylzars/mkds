#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/code_020d1640.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b85dc.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/code_020b4000.h"

void DrawRaceMNumberPair(Unk020d029c *param_1) {
    s32 a;

    a = func_020b33f4();
    if (data_021759c0->mUnk_00c == 4 || data_021759c0->mUnk_00c == 1) {
        return;
    }
    if (a >= 0xb4) {
        return;
    }
    if (data_021759c0->mUnk_08 != 5 && (data_021759c0->mUnk_08 != 3 || data_021759c0->mUnk_1c != 2)) {
        return;
    }
    func_020d1de8(param_1, a);
    if (data_0217b4b4->mUnk_1c == 0) {
        return;
    }
    if (data_0217b4b4->mUnk_04 >= 10) {
        DrawRaceMNumberPairTwoDigit(param_1);
        return;
    }
    DrawRaceMNumberPairOneDigit(param_1);
}

void func_020d1de8(Unk020d029c *param_1, s32 param_2) {
    s32 t[20] = {0,    205,  410,  614,  819,  1638, 2253, 2867, 3891, 4506,
                 4710, 4915, 5120, 5325, 5325, 5120, 4915, 4710, 4506, 4096};
    s32 a;
    Unk020224e0_o *e;

    if (param_2 < 0) {
        data_0217b4b4->mUnk_24 = 0;
        data_0217b4b4->mUnk_18 = NULL;
        data_0217b4b4->mUnk_1c = 0;
        data_0217b4b4->mUnk_20 = 0;
        return;
    }
    if (param_2 < 0x14) {
        s32 *p;

        a = t[param_2];
        func_020b4cec(data_0217b4b4->mUnk_08, a);
        data_0217b4b4->mUnk_24 = 0;
        data_0217b4b4->mUnk_18 = data_0217b4b4->mUnk_08;
        data_0217b4b4->mUnk_1c = a;
        data_0217b4b4->mUnk_20 = func_020ae5c4(param_1);
        p = data_0217b4b4->mUnk_18;
        e = &param_1->mUnk_000[data_0217b4b4->mUnk_20 * 4];
        e[0].mUnk_00[3] = p[0] >> 4;
        e[1].mUnk_00[3] = p[1] >> 4;
        e[2].mUnk_00[3] = p[2] >> 4;
        e[3].mUnk_00[3] = p[3] >> 4;
        data_0217b4b4->mUnk_18[3] = data_0217b4b4->mUnk_1c;
        data_0217b4b4->mUnk_18[0] = data_0217b4b4->mUnk_18[3];
        data_0217b4b4->mUnk_18[2] = 0;
        data_0217b4b4->mUnk_18[1] = data_0217b4b4->mUnk_18[2];
        return;
    }
    if (param_2 < 0x78) {
        data_0217b4b4->mUnk_24 = 0;
        data_0217b4b4->mUnk_18 = NULL;
        data_0217b4b4->mUnk_1c = 0x1000;
        data_0217b4b4->mUnk_20 = 0;
        return;
    }
    data_0217b4b4->mUnk_24 = func_020ae4c0(1, 0, 0x80, param_2 - 0x78, 0x14);
    data_0217b4b4->mUnk_18 = NULL;
    data_0217b4b4->mUnk_1c = 0x1000;
    data_0217b4b4->mUnk_20 = 0;
}

void DrawRaceMNumberPairTwoDigit(Unk020d029c *param_1) {
    s32 t[5] = {175, 190, 203, 216, 231};
    Unk020224e0_c *c;
    s32 *p = NULL;
    u16 a;
    s32 q0[2];
    s32 q1[2];
    s32 q2[2];
    s32 q3[2];
    s32 q4[2];

    if (data_0217b4b4->mUnk_00 / 10 != 0) {
        a = data_0217b4b4->mUnk_20;
        p = data_0217b4b4->mUnk_18;
        c = GetRaceMNcerEntry(data_0217b4b4->mUnk_00 / 10 + 0x2d);
        q0[0] = (t[0] + data_0217b4b4->mUnk_24) << 12;
        q0[1] = 0xb1000;
        param_1->mUnk_400 +=
            func_020224e0(&param_1->mUnk_000[param_1->mUnk_400], 0x80 - param_1->mUnk_400, c, p, q0, a, 1);
    }
    a = data_0217b4b4->mUnk_20;
    p = data_0217b4b4->mUnk_18;
    c = GetRaceMNcerEntry(data_0217b4b4->mUnk_00 % 10 + 0x2d);
    q1[0] = (t[1] + data_0217b4b4->mUnk_24) << 12;
    q1[1] = 0xb1000;
    param_1->mUnk_400 += func_020224e0(&param_1->mUnk_000[param_1->mUnk_400], 0x80 - param_1->mUnk_400, c, p, q1, a, 1);
    a = data_0217b4b4->mUnk_20;
    p = data_0217b4b4->mUnk_18;
    c = GetRaceMNcerEntry(0x37);
    q2[0] = (t[2] + data_0217b4b4->mUnk_24) << 12;
    q2[1] = 0xb1000;
    param_1->mUnk_400 += func_020224e0(&param_1->mUnk_000[param_1->mUnk_400], 0x80 - param_1->mUnk_400, c, p, q2, a, 1);
    a = data_0217b4b4->mUnk_20;
    p = data_0217b4b4->mUnk_18;
    c = GetRaceMNcerEntry(data_0217b4b4->mUnk_04 / 10 + 0x2d);
    q3[0] = (t[3] + data_0217b4b4->mUnk_24) << 12;
    q3[1] = 0xb1000;
    param_1->mUnk_400 += func_020224e0(&param_1->mUnk_000[param_1->mUnk_400], 0x80 - param_1->mUnk_400, c, p, q3, a, 1);
    a = data_0217b4b4->mUnk_20;
    p = data_0217b4b4->mUnk_18;
    c = GetRaceMNcerEntry(data_0217b4b4->mUnk_04 % 10 + 0x2d);
    q4[0] = (t[4] + data_0217b4b4->mUnk_24) << 12;
    q4[1] = 0xb1000;
    param_1->mUnk_400 += func_020224e0(&param_1->mUnk_000[param_1->mUnk_400], 0x80 - param_1->mUnk_400, c, p, q4, a, 1);
}

void DrawRaceMNumberPairOneDigit(Unk020d029c *param_1) {
    s32 t[3] = {205, 218, 231};
    Unk020224e0_c *c;
    s32 *p;
    u16 a;
    s32 q0[2];
    s32 q1[2];
    s32 q2[2];

    a = data_0217b4b4->mUnk_20;
    p = data_0217b4b4->mUnk_18;
    c = GetRaceMNcerEntry(data_0217b4b4->mUnk_00 + 0x2d);
    q0[0] = (t[0] + data_0217b4b4->mUnk_24) << 12;
    q0[1] = 0xb1000;
    param_1->mUnk_400 += func_020224e0(&param_1->mUnk_000[param_1->mUnk_400], 0x80 - param_1->mUnk_400, c, p, q0, a, 1);
    a = data_0217b4b4->mUnk_20;
    p = data_0217b4b4->mUnk_18;
    c = GetRaceMNcerEntry(0x37);
    q1[0] = (t[1] + data_0217b4b4->mUnk_24) << 12;
    q1[1] = 0xb1000;
    param_1->mUnk_400 += func_020224e0(&param_1->mUnk_000[param_1->mUnk_400], 0x80 - param_1->mUnk_400, c, p, q1, a, 1);
    a = data_0217b4b4->mUnk_20;
    p = data_0217b4b4->mUnk_18;
    c = GetRaceMNcerEntry(data_0217b4b4->mUnk_04 + 0x2d);
    q2[0] = (t[2] + data_0217b4b4->mUnk_24) << 12;
    q2[1] = 0xb1000;
    param_1->mUnk_400 += func_020224e0(&param_1->mUnk_000[param_1->mUnk_400], 0x80 - param_1->mUnk_400, c, p, q2, a, 1);
}

void CreateSearchIconMBChildAndMultiDownload(void *param_1) {
    data_0217b4b0 = HeapAlloc(param_1, 0x2c);
    data_0217b4b0->mUnk_00 = func_02047a28("search_icon_00.bncl");
    data_0217b4b0->mUnk_04 = func_02047a28("search_icon_layout_00.bncl");
    LoadNcgrData2(&data_0217b4b0->mUnk_08, func_02047a28("search_icon_00.nce.ncgr"));
    LoadNcerData(&data_0217b4b0->mUnk_0c, func_02047a28("search_icon_00.nce.ncer"));
    LoadNclrData(&data_0217b4b0->mUnk_10, func_02047a28("search_icon_00_o.nclr"));
    switch (data_021759d0->mUnk_04) {
        default:
            func_020b478c(&data_0217b4b0->mUnk_14, func_02047a28("MBChild_us.NFTR"));
            break;
        case 2:
            func_020b478c(&data_0217b4b0->mUnk_14, func_02047a28("MBChild_fr.NFTR"));
            break;
        case 3:
            func_020b478c(&data_0217b4b0->mUnk_14, func_02047a28("MBChild_ge.NFTR"));
            break;
        case 4:
            func_020b478c(&data_0217b4b0->mUnk_14, func_02047a28("MBChild_it.NFTR"));
            break;
        case 5:
            func_020b478c(&data_0217b4b0->mUnk_14, func_02047a28("MBChild_es.NFTR"));
            break;
    }
    switch (data_021759d0->mUnk_04) {
        default:
            data_0217b4b0->mUnk_20 = func_02047a28("MBChild_us.bmg");
            break;
        case 2:
            data_0217b4b0->mUnk_20 = func_02047a28("MBChild_fr.bmg");
            break;
        case 3:
            data_0217b4b0->mUnk_20 = func_02047a28("MBChild_ge.bmg");
            break;
        case 4:
            data_0217b4b0->mUnk_20 = func_02047a28("MBChild_it.bmg");
            break;
        case 5:
            data_0217b4b0->mUnk_20 = func_02047a28("MBChild_es.bmg");
            break;
    }
    LoadNcgrData(&data_0217b4b0->mUnk_24, func_02047a28("multi_download_00_b.NCGR"));
    LoadNclrData(&data_0217b4b0->mUnk_28, func_02047a28("multi_download_00_b.NCLR"));
}
