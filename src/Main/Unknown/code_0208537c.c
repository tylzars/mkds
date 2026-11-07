#include "Main/Unknown/code_0208537c.h"

#include "Main/Unknown/code_0203c5ac.h"
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
#include "Main/Unknown/code_0203c000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0207d814.h"
#include "Main/Unknown/code_0207e654.h"
#include "Main/Unknown/code_02090354.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_020172d0.h"
#include "code_0201750c.h"
#include "Main/Unknown/code_0203c8dc.h"

#pragma thumb on

// Picks the row of 'kartAIparam.bin' for the course and the mode; no row in battle and when mUnk_00c is 5 or 6.
void SetKartAiParamRow(void) {
    Unk021759c0 *p;
    KartAiParamRow *r;
    gKartAiParamRow = NULL;
    p = data_021759c0;
    if (p->mUnk_00c != 5 && p->mMode != MODE_BATTLE && p->mUnk_00c != 6) {
        r = func_02047950(data_usa_02165990);
        p = data_021759c0;
        if (p->mMode == MODE_GRAND_PRIX) {
            r = &r[(p->mCourseId - 1) * 12 + p->mUnk_010];
        } else {
            r = &r[(p->mCourseId - 1) * 12 + (p->mUnk_010 + 1) * 3];
            switch (p->mUnk_014) {
                case 2:
                    r++;
                    break;
                case 3:
                    r += 2;
                    break;
            }
        }
        gKartAiParamRow = r;
    }
}

void InitKartAiShared(void) {
    u16 i;
    BOOL z;
    s32 m;
    gKartAiShared = HeapAlloc(GetHeap(func_020364e8()), 0x144);
    z = FALSE;
    m = -1;
    for (i = 0; i < 8; i++) {
        gKartAiShared->mUnk_000[i] = z;
        gKartAiShared->mKartAtRank[i] = m;
        gKartAiShared->mUnk_040[i] = m;
        gKartAiShared->mUnk_060[i] = m;
        gKartAiShared->mUnk_090[i] = z;
    }
    gKartAiShared->mUnk_080 = m;
    gKartAiShared->mUnk_084 = m;
    gKartAiShared->mUnk_088 = m;
    gKartAiShared->mUnk_08c = z;
    if (data_021759c0->mMode == MODE_TIME_ATTACK) {
        gKartAiShared->mRandom = &gRaceProgress->mLocalRandom;
    } else {
        gKartAiShared->mRandom = &gRaceProgress->mRandom;
    }
    if (data_021759c0->mKartCount > 1 && data_021759c0->mKartCount - data_021759c0->mUnk_3d1 == 1) {
        gKartAiShared->mUnk_120 = 1;
        gKartAiShared->mUnk_124 = ((u32) data_021759c0->mUnk_3d1 >> 1) + 1;
    } else {
        gKartAiShared->mUnk_120 = 0;
        gKartAiShared->mUnk_124 = -1;
    }
    if (gKartAiParamRow != NULL) {
        func_02085bec();
        func_02085ad8();
        if (data_021759c0->mMode == MODE_GRAND_PRIX) {
            switch (data_021759c0->mUnk_010) {
                case 0:
                    gKartAiShared->mUnk_138 = 0;
                    break;
                case 1:
                    gKartAiShared->mUnk_138 = 1;
                    break;
                case 2:
                    gKartAiShared->mUnk_138 = 2;
                    break;
                default:
                    gKartAiShared->mUnk_138 = 1;
                    break;
            }
        } else {
            switch (data_021759c0->mUnk_014) {
                case 1:
                    gKartAiShared->mUnk_138 = 0;
                    break;
                case 2:
                    gKartAiShared->mUnk_138 = 1;
                    break;
                case 3:
                    gKartAiShared->mUnk_138 = 2;
                    break;
                default:
                    gKartAiShared->mUnk_138 = 1;
                    break;
            }
        }
        gKartAiParamRow->mUnk_04 = FX_Div(gKartAiParamRow->mUnk_04, 0x3000);
    }
    func_02085d1c();
    func_0207fba0();
    func_0207e268();
    func_0207c78c();
    if (data_021759c0->mMode == MODE_BATTLE) {
        func_02089974();
        SetupBattleItemEntries();
    }
}

void func_02085d1c(void) {
    u16 j;
    u16 k;
    BOOL f;
    BOOL g;
    Unk021759c0_70 *e;
    j = 0;
    gKartAiShared->mUnk_13c = j;
    for (k = 0; k < 2; k++) {
        gKartAiShared->mUnk_13e[k] = j;
    }
    for (j = 0; (u32) j < data_021759c0->mKartCount; j++) {
        if (data_021759c0->mUseTeams != 0) {
            for (k = 0; k < 2; k++) {
                f = FALSE;
                if (data_021759c0->mCurrentEntries[j].mPlayer.mKind > 3) {
                } else if ((1 << data_021759c0->mCurrentEntries[j].mPlayer.mKind) & 0xd) {
                    f = TRUE;
                }
                if (f != FALSE && k == data_021759c0->mCurrentEntries[j].mPlayer.mTeamIndex) {
                    gKartAiShared->mUnk_13e[k]++;
                    break;
                }
            }
        } else {
            g = FALSE;
            e = &data_021759c0->mCurrentEntries[j].mPlayer;
            if (e->mKind <= 3 && ((1 << e->mKind) & 0xd)) {
                g = TRUE;
            }
            if (g != FALSE) {
                gKartAiShared->mUnk_13c++;
            }
        }
    }
}

void func_02085bec(void) {
    u16 i0;
    s32 m0;
    s32 m1;
    s16 i;
    u16 k;
    s32 v;
    BOOL f;
    s32 v1;

    i0 = 0;
    m0 = 0;
    m1 = 0;
    for (; i0 < 2; i0++) {
        gKartAiShared->mUnk_114[i0] = 0;
    }
    gKartAiShared->mUnk_110 = 1;
    gKartAiShared->mUnk_11c = 0;
    if (data_021759c0->mMode == MODE_GRAND_PRIX) {
        for (i = 0; i < data_021759c0->mKartCount; i++) {
            k = i;
            v = func_0205d3f0(k);
            f = FALSE;
            if (data_021759c0->mCurrentEntries[k].mPlayer.mKind <= 3 &&
                ((1 << data_021759c0->mCurrentEntries[k].mPlayer.mKind) & 0xd)) {
                f = TRUE;
            }
            if (f != FALSE) {
                if (v > m0) {
                    m0 = v;
                }
            } else {
                if (v > m1) {
                    m1 = v;
                }
                if (i == data_021759c0->mUnk_3d5[0]) {
                    gKartAiShared->mUnk_114[0] = v;
                } else if (i == data_021759c0->mUnk_3d5[1]) {
                    gKartAiShared->mUnk_114[1] = v;
                }
            }
        }
        v1 = m0 - m1;
        if (v1 <= -5) {
            if (data_021759c0->mUnk_3d4 > 1) {
                gKartAiShared->mUnk_110 = 0;
                if (gKartAiShared->mUnk_114[0] > gKartAiShared->mUnk_114[1]) {
                    gKartAiShared->mUnk_11c = 1;
                }
            }
        } else if (data_021759c0->mUnk_014 != 1 && v1 >= 4) {
            gKartAiShared->mUnk_110 = 2;
        }
    }
}

void func_02085ad8(void) {
    u16 a;
    u16 b;
    u16 i;
    u16 k;
    u16 n;
    u16 q;
    u16 j;
    Unk021759c0 *p;
    s32 v;
    BOOL f;
    u32 g;
    a = 0;
    b = 0;
    g = data_021759c0->mKartCount;
    NNS_FndInitList(&gKartAiShared->mUnk_12c, 4);
    for (i = 0; i < 2; i++) {
        if (data_021759c0->mUnk_3d5[i] >= 0) {
            a++;
        }
    }
    n = data_021759c0->mKartCount;
    for (k = 0; (u32) k < n; k++) {
        f = FALSE;
        if (data_021759c0->mCurrentEntries[k].mPlayer.mKind <= 3 &&
            ((1 << data_021759c0->mCurrentEntries[k].mPlayer.mKind) & 0xd)) {
            f = TRUE;
        }
        if (f != FALSE) {
            b++;
        }
    }
    q = n - b - a;
    j = 0;
    for (; j < q; j++) {
        gKartAiShared->mUnk_0b0[j].mUnk_00 = (u16) (j + a + 1);
        NNS_FndAppendListObject(&gKartAiShared->mUnk_12c, &gKartAiShared->mUnk_0b0[j]);
    }
    a = 0;
    p = data_021759c0;
    for (; (u32) a < p->mKartCount; a++) {
        if (p->mMode == MODE_TIME_ATTACK) {
            v = a;
        } else {
            v = func_02085984(a, &g);
        }
        gKartAiShared->mUnk_090[a] = v;
        p = data_021759c0;
    }
}

s32 func_02085984(u16 a, u32 *b) {
    s32 r;
    BOOL v1;
    BOOL g;
    BOOL f;
    s32 s;
    s32 m;
    s32 v;
    u16 k;
    NNSFndList *l;
    u16 n;
    u32 h;
    u16 x;
    u16 y;
    KartAiShared *d;
    Unk021759c0 *p;
    Unk0217aebc_128 *c;
    Unk0217aebc_0b0 *e;
    v1 = FALSE;
    r = -1;
    d = gKartAiShared;
    m = d->mUnk_110;
    if (m == 2) {
        g = TRUE;
    } else {
        g = FALSE;
    }
    f = FALSE;
    p = data_021759c0;
    s = p->mCurrentEntries[a].mPlayer.mKind;
    if ((u32) s <= 3 && ((1 << s) & 0xd)) {
        f = TRUE;
    }
    if (f != FALSE) {
        r = *b;
        *b = r - 1;
    } else {
        if (m == 0) {
            s = d->mUnk_11c;
            if (s != 0) {
                s = 1;
            } else {
                s = 0;
            }
            if (s == 0) {
                v = 1;
            } else {
                v = 0;
            }
            if (a == p->mUnk_3d5[s]) {
                r = 1;
                v1 = TRUE;
            } else if (a == (u16) p->mUnk_3d5[v]) {
                r = 2;
                v1 = TRUE;
            }
        } else {
            for (k = 0; k < 2; k++) {
                s = p->mUnk_3d5[k];
                if (s == a) {
                    if (k == 0) {
                        r = 1;
                    } else {
                        r = 2;
                        if (g != FALSE) {
                            r = 1;
                        }
                    }
                    v1 = TRUE;
                    break;
                }
            }
        }
        if (v1 == FALSE) {
            l = &gKartAiShared->mUnk_12c;
            n = l->mCount;
            c = gKartAiShared->mRandom;
            x = n - 1;
            if (x == 0) {
                h = 0;
            } else {
                c->mUnk_00 = (s64) c->mUnk_08 * (s64) c->mUnk_00 + c->mUnk_10;
                y = (u16) n - 1;
                if (y == 0) {
                    h = c->mUnk_00 >> 32;
                } else {
                    h = (s64) (u32) (c->mUnk_00 >> 32) * (s64) (u32) y >> 32;
                }
            }
            e = NNS_FndGetNthListObject(l, h);
            r = e->mUnk_00;
            NNS_FndRemoveListObject(l, e);
        }
    }
    return r;
}

#pragma thumb off

void func_020858ac(u32 a) {
    Unk021759c0 *p;
    BOOL f;
    s16 j;
    p = data_021759c0;
    f = FALSE;
    if (p->mCurrentEntries[a].mPlayer.mKind <= 3 && ((1 << p->mCurrentEntries[a].mPlayer.mKind) & 0xd)) {
        f = TRUE;
    }
    if (f == FALSE) {
        return;
    }
    if (p->mUseTeams != 0) {
        for (j = 0; j < 2; j++) {
            if (j == p->mCurrentEntries[a].mPlayer.mTeamIndex) {
                if (gKartAiShared->mUnk_13e[j] > 0) {
                    gKartAiShared->mUnk_13e[j]--;
                }
                break;
            }
        }
    } else {
        if (gKartAiShared->mUnk_13c > 0) {
            gKartAiShared->mUnk_13c--;
        }
    }
}

s16 func_02085824(u32 a) {
    s16 r;
    u16 j;
    r = 0;
    if (data_021759c0->mUseTeams != 0) {
        for (j = 0; j < 2; j++) {
            if (j != data_021759c0->mCurrentEntries[a].mPlayer.mTeamIndex) {
                r = r + gKartAiShared->mUnk_13e[j];
            }
        }
    } else {
        r = gKartAiShared->mUnk_13c;
    }
    return r;
}

void UpdateKartAiShared(void) {
    u32 m;
    u16 i;
    u32 v;
    if (gKartAiParamRow == NULL) {
        return;
    }
    func_0208552c();
    m = 1;
    for (i = 0; (u32) i < data_021759c0->mKartCount; i++) {
        v = GetKartRank(i);
        if (data_021759c0->mCurrentEntries[i].mPlayer.mKind != 1) {
            if (v == 1) {
                gKartAiShared->mUnk_088 = i;
            }
            if (v >= m) {
                m = v;
                gKartAiShared->mUnk_084 = i;
            }
        }
    }
}

void func_0208552c(void) {
    s32 m;
    u16 i;
    s32 v;
    s32 w;
    s32 n;
    s32 k;
    s32 x;
    s32 y;
    u16 q;
    BOOL f;
    m = 1;
    for (i = 0; (u32) i < data_021759c0->mKartCount; i++) {
        w = gCourseMap->mUnk_108;
        x = GetKartRaceProgress(i);
        w = ((s64) x * w + 0x800) >> 12;
        v = GetKartRank(i);
        gKartAiShared->mUnk_000[i] = w;
        if (v > 0) {
            q = v - 1;
            if (data_021759c0->mCurrentEntries[i].mPlayer.mKind == 1) {
                if (v > m) {
                    m = v;
                    gKartAiShared->mUnk_080 = i;
                }
            }
            gKartAiShared->mKartAtRank[q] = i;
        }
        if (v == 1) {
            if (w >= 0) {
                gKartAiShared->mUnk_08c = FX_Div(gKartAiShared->mUnk_000[i], 0x4ce);
                if (gKartAiShared->mUnk_08c < 0x19a) {
                    gKartAiShared->mUnk_08c = 0x19a;
                } else if (gKartAiShared->mUnk_08c > 0x1000) {
                    gKartAiShared->mUnk_08c = 0x1000;
                }
            } else {
                gKartAiShared->mUnk_08c = 0;
            }
        }
    }
    n = 0;
    for (k = 0; k < data_021759c0->mKartCount; k++) {
        x = gKartAiShared->mKartAtRank[k];
        if (x >= 0) {
            q = x;
            if (data_021759c0->mCurrentEntries[q].mPlayer.mKind == 1) {
                gKartAiShared->mUnk_040[n] = x;
                n++;
            }
        }
    }
    if (gKartAiShared->mUnk_120 == 0) {
        return;
    }
    n = 0;
    for (k = 0; k < data_021759c0->mKartCount; k++) {
        y = gKartAiShared->mKartAtRank[k];
        if (y >= 0) {
            q = y;
            f = FALSE;
            if (data_021759c0->mCurrentEntries[q].mPlayer.mKind <= 3 &&
                ((1 << data_021759c0->mCurrentEntries[q].mPlayer.mKind) & 0xd)) {
                f = TRUE;
            }
            if (f != FALSE) {
                gKartAiShared->mUnk_060[n] = y;
                n++;
            }
        }
    }
}

s32 func_020854c0(u16 a) {
    s32 r;
    u16 i;
    r = -1;
    for (i = 0; (u32) i < data_021759c0->mKartCount; i++) {
        if (a == (u16) gKartAiShared->mUnk_040[i]) {
            r = i + 1;
            break;
        }
    }
    return r;
}

s32 func_020854a0(u32 p0, u32 p1) {
    return gKartAiShared->mUnk_040[(((p1) + (p0))) - (0x1u)];
}

s32 func_0208548c(void) {
    return gKartAiShared->mUnk_08c;
}

s32 func_02085478(void) {
    return gKartAiShared->mUnk_040[0];
}

s32 func_02085458(s32 a) {
    s32 i = a - 2;
    s32 r = -1;

    if (i >= 0) {
        r = gKartAiShared->mUnk_040[i];
    }
    return r;
}

s32 func_02085434(void) {
    return gKartAiShared->mUnk_060[((gKartAiShared->mUnk_124)) - (0x1u)];
}

KartAiParamRow *GetKartAiParamRow(void) {
    return gKartAiParamRow;
}

s32 GetKartIndexAtRank(u32 rank) {
    return gKartAiShared->mKartAtRank[(rank) - (0x1u)];
}

u32 func_020853f0(u32 p0) {
    return (gKartAiShared->mUnk_090[p0]);
}

u32 func_020853dc(void) {
    return (gKartAiShared->mUnk_138);
}

// Race progress times CourseMap.mUnk_108 as a 1.12 fixed-point product, rounded.
s32 GetKartRaceProgressScaled(u32 a) {
    s32 m;
    s32 v;
    m = gCourseMap->mUnk_108;
    v = GetKartRaceProgress(a);
    return ((s64) v * m + 0x800) >> 12;
}

u32 func_02085390(void) {
    return (gKartAiShared->mUnk_120);
}

Unk0217aebc_128 *GetKartAiRandom(void) {
    return gKartAiShared->mRandom;
}
