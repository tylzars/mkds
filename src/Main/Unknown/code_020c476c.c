#include "Main/Unknown/code_020c476c.h"
#include "code_02022030.h"

#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0200eddc.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "code_0214c778.h"
#include "Main/Unknown/code_020c4bd8.h"
#include "Main/Unknown/code_0212a724.h"
#include "code_02023374.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_020b4000.h"
#include "code_02021e8c.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_0212030c.h"
#include "code_02142eac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020b1cf4.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020b85dc.h"
#include "Main/Unknown/code_0212a000.h"

u32 func_020c53b0(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b3ec;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void func_020c525c(void) {
    if (data_0217b3ec == NULL) {
        return;
    }
    if (data_021759d0->mUnk_20 == 0) {
        return;
    }
    if (data_021759c0->mUnk_08 == 5) {
        data_0217b3ec->mUnk_04 = func_021205e8();
        data_0217b3ec->mUnk_0c = data_0217b3ec->mUnk_10;
        data_0217b3ec->mUnk_10 = func_0212a8d0();
        if (data_0217b3ec->mUnk_10 != 0 && data_0217b3ec->mUnk_0c == 0) {
            func_0212ecc0(&data_0217d068, 0, 0x26);
        }
        if (data_0217b3ec->mUnk_10 != 0) {
            data_0217b3ec->mUnk_08++;
            if (data_0217b3ec->mUnk_08 >= 0x78) {
                data_0217b3ec->mUnk_08 = 0;
            }
        } else {
            data_0217b3ec->mUnk_08 = 0;
            data_0217b3ec->mUnk_0c = 0;
            data_0217b3ec->mUnk_10 = 0;
        }
    } else {
        data_0217b3ec->mUnk_00 = data_0217aa00->mUnk_0004 == 0 ? 0 : func_021431d8();
    }
}

void func_020c4f08(Unk020c06c4 *a) {
    void *p = NULL;
    void *q = NULL;

    if (data_0217b3ec == NULL) {
        return;
    }
    if (data_021759d0->mUnk_20 != 0) {
        if (func_020b1d20() == 0) {
            if (data_021759c0->mUnk_08 == 5) {
                p = GetRaceMNcerEntry(data_0217b3ec->mUnk_04 + 0x28);
            } else {
                p = GetRaceMNcerEntry(data_0217b3ec->mUnk_00 + 0x28);
            }
        } else {
            if (data_021759c0->mUnk_08 == 5) {
                p = GetRaceGoalMNcerEntry(data_0217b3ec->mUnk_04 + 0x3c);
            } else {
                p = GetRaceGoalMNcerEntry(data_0217b3ec->mUnk_00 + 0x3c);
            }
        }
        if (data_021759c0->mUnk_08 == 5 && data_0217b3ec->mUnk_10 != 0 && data_0217b3ec->mUnk_08 < 0x69) {
            if (func_020b1d20() != 0) {
                q = GetRaceGoalMNcerEntry(0x42);
            } else {
                q = GetRaceMNcerEntry(0x2c);
            }
        }
    }
    if (p != NULL) {
        s32 v[2];
        s32 w[2];
        s32 n;
        Unk020c06c4_08 *e;

        n = a->mUnk_400;
        v[0] = 0xf8000;
        v[1] = 0xb8000;
        e = &a->mUnk_000.mUnk_00[n];
        a->mUnk_400 += func_020224e0((Unk020224e0_o *) e, 0x80 - n, p, NULL, v, 0, 1);
        for (; n < a->mUnk_400; n++, e++) {
            e->mUnk_0a = 2;
            e->mUnk_0e = 1;
        }
        w[0] = 0xf8000;
        w[1] = 0xb8000;
        n = a->mUnk_400;
        a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[n], 0x80 - n, p, NULL, w, 0, 1);
    }
    if (q != NULL) {
        s32 v[2];
        s32 w[2];
        s32 n;
        Unk020c06c4_08 *e;

        n = a->mUnk_400;
        v[0] = 0xf8000;
        v[1] = 0xa7000;
        e = &a->mUnk_000.mUnk_00[n];
        a->mUnk_400 += func_020224e0((Unk020224e0_o *) e, 0x80 - n, q, NULL, v, 0, 1);
        for (; n < a->mUnk_400; n++, e++) {
            e->mUnk_0a = 2;
            e->mUnk_0e = 1;
        }
        w[0] = 0xf8000;
        w[1] = 0xa7000;
        n = a->mUnk_400;
        a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[n], 0x80 - n, q, NULL, w, 0, 1);
    }
}

void func_020c4e48(void) {
    u32 v;
    u32 p;

    func_0200ee74(&gRaceStartGp->mUnk_18, 0x400);
    func_0214bfcc(&gRaceStartGp->mUnk_18, 0, 0x400);
    v = (*(vu16 *) 0x4000304 & 0x8000) >> 15;
    if (v != 0) {
        if (v == 1) {
            p = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
            *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & ~0x1f00) | ((p | 0x10) << 8);
        }
    } else {
        p = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
        *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & ~0x1f00) | ((p & ~0x10) << 8);
    }
}

void InitRaceStartGp(void) {
    Unk02021dc8 *ncer;
    u8 buf[0x20];
    Unk02180728 w;
    void *r;
    s32 s;
    s32 i;

    gRaceStartGp = HeapAlloc(GetHeap(func_020364e8()), 0x41c);
    for (i = 0; i < 0x80; i++) {
        Unk020c06c4_08 *e = &gRaceStartGp->mUnk_18.mUnk_000.mUnk_00[i];
        e->mUnk_0a = 3;
    }
    gRaceStartGp->mUnk_00 = 0;
    LoadNclrData(&gRaceStartGp->mRaceStartGpMONclr, FindSceneFileWrapper("race_start_gp_m_o.NCLR"));
    LoadNcgrData2(&gRaceStartGp->mRaceStartGpMONcgr, FindSceneFileWrapper("race_start_gp_m_o.NCGR"));
    ncer = NULL;
    LoadNcerData(&ncer, FindSceneFileWrapper("race_start_gp_m.NCER"));
    for (i = 0; i < 3; i++) {
        gRaceStartGp->mRaceStartGpMNcerEntries[i] = func_02021f1c(ncer, (u16) i);
    }
    r = func_020b403c(2);
    s = -1;
    func_02023408(buf, gRaceStartGp->mRaceStartGpMONcgr->mData, 0x20, 4, 4);
    w.mUnk_00 = buf;
    w.mUnk_04 = r;
    w.mUnk_08 = 1;
    w.mUnk_0c = 0;
    if (data_021759c0->mUnk_08 == 0) {
        s = func_02025d8c(data_021759c0->mCourseId);
        w.mUnk_08 = func_020b4b10();
    } else if (data_021759c0->mUnk_08 == 4) {
        s = (data_021759c0->mUnk_08 == 4 ? data_021759c0->mMissionTableRow : s) + 0x55;
        w.mUnk_08 = func_020b4b54();
    }
    func_02024340(&w, 0, 9, 0xe, 0x40a, GetBmgEntry(func_020b47cc("common.bmg"), s));
    func_02024340(&w, 0, 8, 0xe, 0x40a, GetBmgEntry(func_020b47cc("common.bmg"), s));
    func_0200ee74(gRaceStartGp->mRaceStartGpMONcgr->mData, gRaceStartGp->mRaceStartGpMONcgr->mDataSize);
    func_0214c090(gRaceStartGp->mRaceStartGpMONclr->mData, 0, gRaceStartGp->mRaceStartGpMONclr->mDataSize);
    func_0214bf04(gRaceStartGp->mRaceStartGpMONcgr->mData, 0, gRaceStartGp->mRaceStartGpMONcgr->mDataSize);
}

u32 func_020c4bd8(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRaceStartGp;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

u16 func_020c4bb0(void) {
    u16 *v1;
    int *v2;
    v1 = ((u16 *) 0x04000304u);
    v2 = (s32 *) gRaceStartGp;
    *v2 = (*(u32 *) v2) + 1;
    return *v1;
}

const Vec3 data_02156880 = {0, 0, 0};

void func_020c4ae8(void) {
    Unk020c06c4 *p;
    Unk02021e40 *c;
    s32 v[2];

    gRaceStartGp->mUnk_18.mUnk_400 = 0;
    c = gRaceStartGp->mRaceStartGpMNcerEntries[0];
    p = &gRaceStartGp->mUnk_18;
    v[0] = 0x80000;
    v[1] = 0x60000;
    p->mUnk_400 += func_020224e0((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400], 0x80 - p->mUnk_400,
                                 (Unk020224e0_c *) c, NULL, v, 0, 1);
    func_0200ee74(&gRaceStartGp->mUnk_18, 0x400);
    func_0214cc04(3, &gRaceStartGp->mUnk_18.mUnk_000.mUnk_00[gRaceStartGp->mUnk_18.mUnk_400], 0xc0,
                  (0x80 - gRaceStartGp->mUnk_18.mUnk_400) * 8);
}

void func_020c4ab8(s32 a) {
    if (data_021759c0->mUnk_08 == 1) {
        data_0217b3e4->mUnk_004[a] = 0;
    }
}

void func_020c4a04(s32 a) {
    s32 i;
    s32 j;

    if (data_021759c0->mUnk_08 != 1) {
        return;
    }
    for (i = 0; i < 0x28; i++) {
        data_0217b3e4->mUnk_010[a][i].mUnk_10 = 0;
    }
    for (j = 0; j < data_0217b3e4->mUnk_790[a].mUnk_00; j++) {
        data_0217b3e4->mUnk_790[a].mUnk_34[j] = 0x28;
    }
    data_0217b3e4->mUnk_004[a] = 1;
}

void func_020c4780(void) {
    s32 a;
    s32 j;
    Vec3 v;

    if (data_021759c0->mUnk_08 != 1) {
        return;
    }
    data_0217b3e4 = HeapAlloc(GetHeap(func_020364e8()), 0x910);
    data_0217b3e4->mUnk_000 = 1;
    for (a = 0; a < data_021759c0->mKartCount; a++) {
        data_0217b3e4->mUnk_004[a] = 1;
    }
    data_0217b3e4->mUnk_00c = 0;
    for (a = 0; a < data_021759c0->mKartCount; a++) {
        u16 w = (u32) func_020b6338(a);
        func_0207a91c(&v, a);
        for (j = 0; j < 0x28; j++) {
            data_0217b3e4->mUnk_010[a][j].mUnk_00 = v;
            data_0217b3e4->mUnk_010[a][j].mUnk_0c = w;
            data_0217b3e4->mUnk_010[a][j].mUnk_10 = 0;
            data_0217b3e4->mUnk_010[a][j].mUnk_14 = 3;
        }
    }
    a = 0;
    if (a < data_021759c0->mKartCount) {
        Vec3 z = data_02156880;
        do {
            data_0217b3e4->mUnk_790[a].mUnk_00 = 0;
            for (j = 0; j < 3; j++) {
                data_0217b3e4->mUnk_790[a].mUnk_04[j] = z;
                data_0217b3e4->mUnk_790[a].mUnk_34[j] = -1;
                data_0217b3e4->mUnk_790[a].mUnk_28[j] = 3;
            }
            a++;
        } while (a < data_021759c0->mKartCount);
    }
    for (a = 0; a < 16; a++) {
        s32 s = data_0215d4b4[((u16) (a * 0x10000 / 16) >> 4) * 2];
        s32 c = data_0215d4b4[((u16) (a * 0x10000 / 16) >> 4) * 2 + 1];
        data_0217b3e4->mUnk_810[a].mUnk_00 = c;
        data_0217b3e4->mUnk_810[a].mUnk_04 = s;
        data_0217b3e4->mUnk_810[a].mUnk_08 = -s;
        data_0217b3e4->mUnk_810[a].mUnk_0c = c;
    }
}

u32 func_020c476c(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b3e4;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}
