#include "Main/Unknown/code_020c3e44.h"

#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/unk_021759c0.h"
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
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b1cf4.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020b837c.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02022030.h"
#include "Main/Unknown/code_020c476c.h"
#include "Main/Unknown/code_02036820.h"
#include "code_0200eddc.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "code_0214c778.h"
#include "Main/Unknown/code_020c4bd8.h"
#include "Main/Unknown/code_0212a724.h"
#include "code_02023374.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_020b47b4.h"
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
#include "Main/Unknown/code_020b85dc.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c53c4.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b19f8.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_020c5ccc.h"
#include "Main/Unknown/code_020c5ce0.h"
#include "Main/Unknown/code_0205f000.h"
#include "Main/Unknown/code_020c5db0.h"

u32 func_020c5dc4(void) {
    return ((u32) data_0217b3f0->mUnk_00);
}

u32 func_020c5db0(void) {
    return ((u32) data_0217b3f0->mUnk_04);
}

void func_020c5ce0(void) {
    data_0217b3f0 = HeapAlloc(GetHeap(func_020364e8()), 0x1c);
    data_0217b3f0->mUnk_00 = 1;
    data_0217b3f0->mUnk_04 = 0;
    data_0217b3f0->mUnk_08 = 0;
    data_0217b3f0->mUnk_0c = 0;
    data_0217b3f0->mUnk_10 = 0;
    if (data_021759c0->mMode == 4) {
        if (func_0205fd78(data_021759c0->mMode == 4 ? data_021759c0->mMissionTableRow : -1,
                          data_021759c0->mMode == 4 ? data_021759c0->mMissionTableColumn : -1,
                          &data_0217b3f0->mUnk_14) == 0) {
            data_0217b3f0->mUnk_14 = 9;
        }
    } else {
        data_0217b3f0->mUnk_14 = 9;
    }
    data_0217b3f0->mUnk_18 = 9;
}

u32 func_020c5ccc(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b3f0;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void func_020c5940(void) {
    u32 b;
    s32 a;
    u16 i;
    s32 n;
    u16 x;
    s32 *q;
    Unk0217aa1c_00 *p;

    n = data_0217b3f0->mUnk_04;
    x = func_020b4d9c();
    if (gRaceProgress->mUnk_000[x].mStatus == 1 || gRaceProgress->mRaceDone != 0) {
        data_0217b3f0->mUnk_00 = 0;
    }
    if (func_020b1d0c() == 0) {
        return;
    }
    if (data_021759c0->mMode == 4) {
        if ((IsKartEnded((u16) data_021759c0->mEntryIndex) != 0 ? gRaceProgress->mUnk_4e0 : 6) != 0 &&
            func_0207a218() == 0 && n == 0) {
            return;
        }
    }
    q = &data_0217b3f0->mUnk_04;
    if (*q < 0x7fffffff) {
        *q = *q + 1;
    }
    switch (data_021759c0->mMode) {
        case 0:
            data_0217b3f0->mUnk_08 = GetKartRank(func_020b4d9c()) - 1;
            b = func_0205dc7c(func_020b4d9c());
            a = func_0205db28();
            p = &data_0217aa1c->mUnk_000[a][func_0205dc7c(b)];
            a = p->mUnk_00;
            data_0217b3f0->mUnk_0c = a - func_0205d3f0(func_020b4d9c());
            if (n > 0x14) {
                data_0217b3f0->mUnk_00 = 1;
            }
            break;
        case 1:
            if (n > 0x14) {
                data_0217b3f0->mUnk_00 = 1;
            }
            break;
        case 3:
        case 5:
            data_0217b3f0->mUnk_08 = GetKartRank(func_020b4d9c()) - 1;
            for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
                if (GetKartRank(i) == 1) {
                    break;
                }
            }
            data_0217b3f0->mUnk_10 = i;
            if (n > 0x14) {
                data_0217b3f0->mUnk_00 = 1;
            }
            break;
        case 4:
            if (IsKartEnded((u16) data_021759c0->mEntryIndex) != 0 ? gRaceProgress->mUnk_4e0 : 6) {
                data_0217b3f0->mUnk_18 = 9;
            } else {
                data_0217b3f0->mUnk_18 = func_0205d140();
            }
            if ((IsKartEnded((u16) data_021759c0->mEntryIndex) != 0 ? gRaceProgress->mUnk_4e0 : 6) == 0) {
                if (n == 1) {
                    switch (data_0217b3f0->mUnk_18) {
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                            break;
                        case 5:
                            func_0212ecc0(&data_0217d068, 0, 0x1b);
                            break;
                        case 6:
                            func_0212ecc0(&data_0217d068, 0, 0x1c);
                            break;
                        case 7:
                            func_0212ecc0(&data_0217d068, 0, 0x1d);
                            break;
                    }
                } else if (n > 0x1e) {
                    data_0217b3f0->mUnk_00 = 1;
                }
            } else if (n > 0x4b) {
                data_0217b3f0->mUnk_00 = 1;
            }
            break;
        default:
            data_0217b3f0->mUnk_00 = 1;
            break;
    }
}

void func_020c5804(Unk020c06c4 *a) {
    s32 y;
    s32 k;
    s32 e[2];
    void *c;

    if (data_021759c0->mUnk_00c != 0) {
        return;
    }
    if (func_020b1d0c() == 0) {
        return;
    }
    switch (data_021759c0->mMode) {
        case 0:
            func_020c55b0(a);
            break;
        case 3:
        case 5:
            y = func_020ae4c0(1, 0x40, 0, data_0217b3f0->mUnk_04, 0x14);
            c = GetRaceGoalMNcerEntry(data_0217b3f0->mUnk_08);
            e[0] = 0x18000;
            e[1] = (y + 0xa8) << 12;
            k = a->mUnk_400;
            a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, c, NULL, e, 0, 1);
            break;
        case 4:
            func_020c541c(a);
            break;
    }
}

void func_020c55b0(Unk020c06c4 *a) {
    s32 y;
    s32 k;
    s32 e0[2];
    s32 e1[2];
    s32 e2[2];
    s32 e3[2];
    s32 e4[2];
    s32 z;
    void *c;

    y = func_020ae4c0(1, 0x40, 0, data_0217b3f0->mUnk_04, 0x14);
    c = GetRaceGoalMNcerEntry(data_0217b3f0->mUnk_08);
    e0[0] = 0x18000;
    e0[1] = (y + 0xa8) << 12;
    k = a->mUnk_400;
    a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, c, NULL, e0, 0, 1);

    c = GetRaceGoalMNcerEntry(data_0217b3f0->mUnk_0c + 8);
    e1[0] = 0x48000;
    e1[1] = (y + 0xb0) << 12;
    k = a->mUnk_400;
    a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, c, NULL, e1, 0, 1);

    c = GetRaceGoalMNcerEntry(func_020b4b98(data_0217b3f0->mUnk_0c) != FALSE ? 0x13 : 0x14);
    e2[0] = 0x48000;
    e2[1] = (y + 0xb0) << 12;
    k = a->mUnk_400;
    a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, c, NULL, e2, 0, 1);

    c = GetRaceGoalMNcerEntry(0x40);
    e3[0] = 0xda000;
    e3[1] = (y + 0xa6) << 12;
    k = a->mUnk_400;
    a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, c, NULL, e3, 0, 1);

    c = GetRaceGoalMNcerEntry(0x41);
    e4[0] = 0xda000;
    e4[1] = (y + 0xa6) << 12;
    k = a->mUnk_400;
    a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, c, NULL, e4, 0, 1);
}

void func_020c541c(Unk020c06c4 *a) {
    s32 n;
    s32 y;
    s32 k;
    s32 v;
    s32 t;
    s32 e[2];
    void *c;

    n = data_0217b3f0->mUnk_04;
    y = func_020ae4c0(1, -0x80, 0, n, 0x14);
    if (data_0217b3f0->mUnk_14 != 9 && data_0217b3f0->mUnk_18 > data_0217b3f0->mUnk_14 && n >= 0x1e) {
        t = n - 10;
        if (t < 0x54) {
            n = t % 12;
            if (n >= 8) {
                return;
            }
        }
    }
    switch (data_0217b3f0->mUnk_18) {
        case 0:
            v = 7;
            break;
        case 1:
            v = 6;
            break;
        case 2:
            v = 5;
            break;
        case 3:
            v = 4;
            break;
        case 4:
            v = 3;
            break;
        case 5:
            v = 2;
            break;
        case 6:
            v = 1;
            break;
        case 7:
            v = 0;
            break;
    }
    if (data_0217b3f0->mUnk_18 >= 8) {
        return;
    }
    c = GetRaceGoalMrMNcerEntry(v);
    e[0] = (y + 0x80) << 12;
    e[1] = 0x60000;
    k = a->mUnk_400;
    a->mUnk_400 += func_020224e0((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, c, NULL, e, 0, 1);
}

void func_020c53c4(void) {
    data_0217b3ec = HeapAlloc(GetHeap(func_020364e8()), 0x14);
    data_0217b3ec->mUnk_00 = 0;
    data_0217b3ec->mUnk_04 = 0;
    data_0217b3ec->mUnk_08 = 0;
    data_0217b3ec->mUnk_0c = 0;
    data_0217b3ec->mUnk_10 = 0;
}

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
    if (data_021759c0->mMode == 5) {
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
            if (data_021759c0->mMode == 5) {
                p = GetRaceMNcerEntry(data_0217b3ec->mUnk_04 + 0x28);
            } else {
                p = GetRaceMNcerEntry(data_0217b3ec->mUnk_00 + 0x28);
            }
        } else {
            if (data_021759c0->mMode == 5) {
                p = GetRaceGoalMNcerEntry(data_0217b3ec->mUnk_04 + 0x3c);
            } else {
                p = GetRaceGoalMNcerEntry(data_0217b3ec->mUnk_00 + 0x3c);
            }
        }
        if (data_021759c0->mMode == 5 && data_0217b3ec->mUnk_10 != 0 && data_0217b3ec->mUnk_08 < 0x69) {
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
    if (data_021759c0->mMode == 0) {
        s = func_02025d8c(data_021759c0->mCourseId);
        w.mUnk_08 = func_020b4b10();
    } else if (data_021759c0->mMode == 4) {
        s = (data_021759c0->mMode == 4 ? data_021759c0->mMissionTableRow : s) + 0x55;
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
    if (data_021759c0->mMode == 1) {
        data_0217b3e4->mUnk_004[a] = 0;
    }
}

void func_020c4a04(s32 a) {
    s32 i;
    s32 j;

    if (data_021759c0->mMode != 1) {
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

    if (data_021759c0->mMode != 1) {
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
        s32 s = gPairsByAngle[((u16) (a * 0x10000 / 16) >> 4) * 2];
        s32 c = gPairsByAngle[((u16) (a * 0x10000 / 16) >> 4) * 2 + 1];
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

void func_020c43c4(void) {
    Kart *p;
    Unk0217b3e4 *d;
    u16 j;
    s32 n;
    u32 i;

    if (data_021759c0->mMode != 1) {
        return;
    }
    if (IsRaceStartSequenceDone() == 0) {
        return;
    }
    if ((u16) (data_02175628[func_020435bc()].mUnk_00 & 4) != 0) {
        data_0217b3e4->mUnk_000 = data_0217b3e4->mUnk_000 == 0 ? 1 : 0;
    }
    for (i = 0; i < data_021759c0->mKartCount; i = (u16) (i + 1)) {
        if ((data_027e00c8)[i].mUnk_204 != FALSE) {
            n = data_0217b3e4->mUnk_790[i].mUnk_00;
            data_0217b3e4->mUnk_790[i].mUnk_00 = n + 1;
            ((void (*)(Vec3 *, s32)) func_0207a91c)(&data_0217b3e4->mUnk_790[i].mUnk_04[n], i);
            data_0217b3e4->mUnk_790[i].mUnk_28[n] = func_020b4e70(&data_0217b3e4->mUnk_790[i].mUnk_04[n]) != 0 ? 2 : 3;
        }
    }
    data_0217b3e4->mUnk_00c++;
    if (data_0217b3e4->mUnk_00c > 0xf) {
        data_0217b3e4->mUnk_00c = 0;
        for (i = 0; i < data_021759c0->mKartCount; i = (u16) (i + 1)) {
            for (j = 0; j < data_0217b3e4->mUnk_790[i].mUnk_00; j = (u16) (j + 1)) {
                if (data_0217b3e4->mUnk_790[i].mUnk_34[j] < 0x28) {
                    data_0217b3e4->mUnk_790[i].mUnk_34[j]++;
                }
            }
        }
        func_020b1d50();
        func_020b1d50();
        for (i = 0; i < data_021759c0->mKartCount; i = (u16) (i + 1)) {
            p = GetKart(i);
            d = data_0217b3e4;
            for (j = 0x27; j != 0; j--) {
                d->mUnk_010[i][j] = d->mUnk_010[i][j - 1];
            }
            func_0207a91c(&data_0217b3e4->mUnk_010[i][0].mUnk_00, i);
            data_0217b3e4->mUnk_010[i][0].mUnk_14 = func_020b4e70(&data_0217b3e4->mUnk_010[i][0].mUnk_00) != 0 ? 2 : 3;
            data_0217b3e4->mUnk_010[i][0].mUnk_0c = func_020b6338(i);
            if ((p->mUnk_44 & 0xa) != 0) {
                data_0217b3e4->mUnk_010[i][0].mUnk_10 = 2;
            } else if ((p->mUnk_48 & 0x80020) != 0) {
                data_0217b3e4->mUnk_010[i][0].mUnk_10 = 3;
            } else {
                data_0217b3e4->mUnk_010[i][0].mUnk_10 = 1;
            }
            if (gRaceProgress->mRaceDone != 0) {
                data_0217b3e4->mUnk_010[i][0].mUnk_10 = 0;
                data_0217b3e4->mUnk_004[i] = 0;
            }
        }
    }
}

void func_020c3e44(Unk020c06c4 *a) {
    UnkPair020b502c o1;
    UnkPair020b502c o2;
    s32 w1[2];
    s32 w2[2];
    u16 c;
    void *r;
    float f;
    s32 v;
    s32 s;
    s32 i;
    s32 j;
    u32 m;
    s32 n;
    Unk020c06c4_08 *e;
    void *q;
    u32 h;
    s32 d;
    Unk020c06c4_08 *p;

    if (data_021759c0->mMode != 1) {
        return;
    }
    if (data_0217b3e4->mUnk_000 == 0) {
        return;
    }
    c = func_020ae5c4(a);
    for (i = 1; i < 16; i++) {
        func_020ae5c4(a);
    }
    if ((s32) (func_020b1d50() * 3) > 0) {
        f = (float) (s32) (func_020b1d50() * 0x3000) + 0.5f;
    } else {
        f = (float) (s32) (func_020b1d50() * 0x3000) - 0.5f;
    }
    v = f;
    s = ((s64) v * 20) >> 12;
    for (i = 0; i < data_021759c0->mKartCount; i++) {
        if (data_0217b3e4->mUnk_004[i] != 0) {
            if (gRaceProgress->mRaceDone == 0) {
                for (j = 0; j < data_0217b3e4->mUnk_790[i].mUnk_00; j++) {
                    if (data_0217b3e4->mUnk_790[i].mUnk_34[j] < 0x28) {
                        if (func_020b5ae8(&data_0217b3e4->mUnk_790[i].mUnk_04[j], &o1, s, 1, 1) != FALSE) {
                            m = data_0217b3e4->mUnk_790[i].mUnk_28[j];
                            q = GetRaceSNcerEntry(0x4f);
                            n = a->mUnk_400;
                            w1[0] = o1.mUnk_00 << 12;
                            w1[1] = o1.mUnk_04 << 12;
                            e = &a->mUnk_000.mUnk_00[n];
                            a->mUnk_400 += func_020224e0((Unk020224e0_o *) e, 0x80 - n, q, NULL, w1, 0, 1);
                            for (; n < a->mUnk_400; n++, e++) {
                                if (m != -1) {
                                    e->mUnk_0e = m;
                                }
                            }
                        }
                    }
                }
            }
            for (j = 0; j < 0x28; j++) {
                u16 x = (u16) (data_0217b3e4->mUnk_010[i][j].mUnk_0c + func_020b6368()) + 0x800;
                u16 y = ((x << 4) / 0x10000) % 16;
                if (func_020b5ae8(&data_0217b3e4->mUnk_010[i][j].mUnk_00, &o2, s, 1, 1) != FALSE) {
                    switch (data_0217b3e4->mUnk_010[i][j].mUnk_10) {
                        case 0:
                            r = NULL;
                            break;
                        case 1:
                            r = GetRaceSNcerEntry(0x51);
                            break;
                        case 2:
                            r = GetRaceSNcerEntry(0x52);
                            break;
                        case 3:
                            r = GetRaceSNcerEntry(0x53);
                            break;
                    }
                    if (r != NULL) {
                        h = data_0217b3e4->mUnk_010[i][j].mUnk_14;
                        d = a->mUnk_400;
                        w2[0] = o2.mUnk_00 << 12;
                        w2[1] = o2.mUnk_04 << 12;
                        p = &a->mUnk_000.mUnk_00[d];
                        a->mUnk_400 += func_020224e0((Unk020224e0_o *) p, 0x80 - d, r,
                                                     &data_0217b3e4->mUnk_810[y].mUnk_00, w2, (u16) (y + c), 1);
                        for (; d < a->mUnk_400; d++, p++) {
                            if ((i != 0 ? 1 : -1) != -1) {
                                p->mUnk_0a = i != 0 ? 1 : -1;
                            }
                            if (h != -1) {
                                p->mUnk_0e = h;
                            }
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < 16; i++) {
        Unk0217b3e4_810 *t = &data_0217b3e4->mUnk_810[i];
        (a->mUnk_000.mUnk_20 + c)[i].mUnk_06 = t->mUnk_00 >> 4;
        (a->mUnk_000.mUnk_20 + c)[i].mUnk_0e = t->mUnk_04 >> 4;
        (a->mUnk_000.mUnk_20 + c)[i].mUnk_16 = t->mUnk_08 >> 4;
        (a->mUnk_000.mUnk_20 + c)[i].mUnk_1e = t->mUnk_0c >> 4;
    }
}
