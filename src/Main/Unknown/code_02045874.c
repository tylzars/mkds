#include "Main/Unknown/code_02045874.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02029aa0.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0204a000.h"
#include "Main/Unknown/code_0204aa60.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02090354.h"

static inline u32 func_02046524_inline(Unk020f41c4_B *a, u32 b) {
    u64 r;
    if (b == 0) {
        r = 0;
    } else {
        a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
        if (b == 0) {
            r = a->mUnk_00 >> 32;
        } else {
            r = ((a->mUnk_00 >> 32) * b) >> 32;
        }
    }
    return (u16) r;
}

BOOL func_02046648(s32 a) {
    u32 n;
    n = (u8) gRaceSetup->mNextHeader.mEngineIndex;
    if (gRaceSetup->mNextHeader.mMirrorMode != 0) {
        n = 3;
    }
    switch (a) {
        case 0:
        case 1:
        case 4:
        case 5:
            return TRUE;
        case 2:
            if (func_0205fbb8(n)) {
                return TRUE;
            }
            break;
        case 3:
            if (func_0205fbb8(n + 4)) {
                return TRUE;
            }
            break;
        case 6:
            if (func_0205fbb8(n + 8)) {
                return TRUE;
            }
            break;
        case 7:
            if (func_0205fbb8(n + 12)) {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

void func_02046594(void) {
    u8 k;
    BOOL f;
    u8 i;
    k = 1;
    f = FALSE;
    switch (gRaceSetup->mNextHeader.mMode) {
        case MODE_GRAND_PRIX:
        case MODE_TIME_ATTACK:
        case MODE_MISSION_RUN:
        case 5:
            f = TRUE;
            break;
    }
    for (i = 0; i < 8; i++) {
        if (f == FALSE && gRaceSetup->mNextEntries[i].mPlayer.mKind == 1) {
            gRaceSetup->mNextEntries[i].mPlayer.mUnk_16 = k;
            k = k + 1;
        } else {
            gRaceSetup->mNextEntries[i].mPlayer.mUnk_16 = -1;
        }
    }
    gRaceSetup->mUnk_3e1 = k;
}

u32 func_02046524(Unk020f41c4_B *a, u32 b) {
    u64 r;
    if (b == 0) {
        r = 0;
    } else {
        a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
        if (b == 0) {
            r = a->mUnk_00 >> 32;
        } else {
            r = ((a->mUnk_00 >> 32) * b) >> 32;
        }
    }
    return (u16) r;
}

void func_02046024(s32 a) {
    s32 f;
    u32 m;
    const u32 *t;
    u32 i;
    u32 n;
    f = 0;
    func_0205db50();
    gRaceSetup->mCourseListIndex = 0;
    gRaceSetup->mNextHeader.mCourseNumber = 1;
    if (a != 0) {
        gRaceSetup->mNextHeader.mUnk_0c = 0;
    } else if (data_021759d0->mUnk_1c_2) {
        gRaceSetup->mNextHeader.mUnk_0c = 0;
    } else {
        gRaceSetup->mNextHeader.mUnk_0c = 4;
    }
    for (i = 0; i < 0x21; i++) {
        gRaceSetup->mCourseList[i] = 0;
    }
    switch (data_021759d0->mUnk_20) {
        case 1:
        case 2:
            f = (data_0217aa00->mUnk_0454 & 0x40) != 0;
            break;
    }
    switch (gRaceSetup->mNextHeader.mCourseListMode) {
        case 1:
            if (a != 0) {
                u8 p;
                u8 q;
                u32 n;
                s32 e;
                s32 c;
                m = f != 0 ? 2 : 8;
                t = f != 0 ? data_usa_021540c0 : data_usa_02154108;
                e = gRaceSetup->mNextHeader.mCourseId;
                n = m * 4;
                for (f = 0; f < n; f++) {
                    p = f / 4;
                    q = f % 4;
                    if (e == data_02154128[t[p]][q]) {
                        break;
                    }
                }
                c = 0;
                for (f = 0; f < n; f++) {
                    if (func_02046648(t[p]) != FALSE) {
                        gRaceSetup->mCourseList[c] = data_02154128[t[p]][q];
                        c = (u8) (c + 1);
                    }
                    q = q + 1;
                    if (q >= 4) {
                        q = 0;
                        p = p + 1;
                        if (p >= m) {
                            p = 0;
                        }
                    }
                }
                return;
            } else {
                s32 e;
                u32 s;
                n = f != 0 ? 3 : 6;
                s = 0;
                t = f != 0 ? data_usa_021540c8 : data_usa_021540d4;
                e = gRaceSetup->mNextHeader.mCourseId;
                for (i = 0; i < n; i++) {
                    s = i;
                    if (e == t[i]) {
                        break;
                    }
                }
                for (i = 0; i < n; i++) {
                    gRaceSetup->mCourseList[i] = t[s];
                    s++;
                    if (s >= n) {
                        s = 0;
                    }
                }
                return;
            }
        case 2:
            if (a != 0) {
                Unk020f41c4_B *g;
                u32 n;
                s32 k;
                s32 c;
                u8 q;
                u8 p;
                u8 w;
                u8 x;
                u8 y;
                s32 h;
                s32 z;
                g = func_0204aa60();
                m = f != 0 ? 2 : 8;
                t = f != 0 ? data_usa_021540c0 : data_usa_02154108;
                n = m * 4;
                c = 0;
                for (k = 0; k < n; k++) {
                    p = k / 4;
                    q = k % 4;
                    if (func_02046648(t[p]) != FALSE) {
                        gRaceSetup->mCourseList[c] = data_02154128[t[p]][q];
                        c = (u8) (c + 1);
                    }
                }
                h = c * 2;
                for (z = 0; z < h; z++) {
                    w = func_02046524(g, (vu16) (c - 1));
                    x = z % c;
                    y = gRaceSetup->mCourseList[x];
                    if (w >= x) {
                        w = w + 1;
                    }
                    gRaceSetup->mCourseList[x] = gRaceSetup->mCourseList[w];
                    gRaceSetup->mCourseList[w] = y;
                }
            } else {
                s32 k;
                Unk020f41c4_B *g;
                g = func_0204aa60();
                n = f != 0 ? 3 : 6;
                t = f != 0 ? data_usa_021540c8 : data_usa_021540d4;
                for (k = 0; k < n; k++) {
                    gRaceSetup->mCourseList[k] = t[k];
                }
                k = 0;
                if (k < n) {
                    m = (u16) (n - 1);
                    for (; k < n; k++) {
                        u8 w;
                        u8 y;
                        w = func_02046524_inline(g, m);
                        y = gRaceSetup->mCourseList[k];
                        if (w >= k) {
                            w = w + 1;
                        }
                        gRaceSetup->mCourseList[k] = gRaceSetup->mCourseList[w];
                        gRaceSetup->mCourseList[w] = y;
                    }
                }
            }
            gRaceSetup->mNextHeader.mCourseId = gRaceSetup->mCourseList[0];
            break;
    }
}

void func_02045ed0(void) {
    u8 i;
    u8 r;
    func_02046594();
    switch (gRaceSetup->mNextHeader.mMode) {
        case MODE_GRAND_PRIX:
            func_0205db50();
            gRaceSetup->mNextHeader.mCourseNumber = 1;
            gRaceSetup->mNextHeader.mUnk_0c = 3;
            gRaceSetup->mNextHeader.mCourseId =
                data_02154128[gRaceSetup->mNextHeader.mCupIndex][gRaceSetup->mNextHeader.mCourseNumber - 1];
            break;
        case MODE_VS:
            func_02046024(1);
            break;
        case MODE_BATTLE:
            func_02046024(0);
            break;
        case 5:
            r = 0xff;
            func_0205db50();
            gRaceSetup->mNextHeader.mCourseNumber = 1;
            gRaceSetup->mNextHeader.mUnk_0c = 0;
            for (i = 0; i < 4; i++) {
                if (gRaceSetup->mNextEntries[i].mPlayer.mKind == 0) {
                    r = i;
                    break;
                }
            }
            gRaceSetup->mNextHeader.mFollowedKartIndex = r;
            break;
        case MODE_MISSION_RUN:
            func_0205db50();
            if (gRaceSetup->mNextHeader.mMissionTableColumn == 9) {
                gRaceSetup->mNextHeader.mUnk_0c = 3;
            } else {
                gRaceSetup->mNextHeader.mUnk_0c = 0;
            }
            gRaceSetup->mNextHeader.mCourseNumber = 1;
            break;
    }
}

BOOL func_02045bd4(void) {
    s8 t;
    u8 i;
    s8 j;
    u8 b;
    u32 c;
    s32 n;
    Unk0217aa1c_00 *e;
    t = gRaceSetup->mEntryIndex;
    data_0217b488->mUnk_7c = func_0205d4e8((u16) t) - 1;
    data_0217b488->mUnk_80 = func_0205d190();
    data_0217b488->mUnk_90 = gRaceSetup->mCurrentEntries[(u8) t].mCharacterIndex;
    data_0217b488->mUnk_84 = gRaceSetup->mCupIndex;
    data_0217b488->mUnk_88 = gRaceSetup->mEngineIndex;
    data_0217b488->mUnk_8c = gRaceSetup->mMirrorMode;
    c = func_0205dc7c((u8) t);
    b = func_0205db28();
    e = &data_0217aa1c->mUnk_000[b][func_0205dc7c(c)];
    data_0217b488->mUnk_a8 = e->mUnk_00;
    data_0217b488->mUnk_94 = gRaceSetup->mCurrentEntries[(u8) t].mKartIndex;
    for (i = 0; i < 4; i++) {
        Unk0217aa1c_144_00 d;
        func_0205d7c8(&d, (u16) gRaceSetup->mEntryIndex, i);
        data_0217b488->mUnk_98[i] = d;
    }
    if ((u32) func_0205d4e8((u16) gRaceSetup->mEntryIndex) > 3) {
        return FALSE;
    }
    gRaceSetup->mNextHeader.mCourseId = COURSE_ID_AWARD;
    gRaceSetup->mNextHeader.mUnk_0c = 5;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < gRaceSetup->mKartCount; j++) {
            if (func_0205d4e8((u16) j) == i + 1) {
                break;
            }
        }
        func_020468b0(i, gRaceSetup->mCurrentEntries[(u16) j].mCharacterIndex,
                      gRaceSetup->mCurrentEntries[(u16) j].mKartIndex, 1, -1, 3);
    }
    for (; i < 8; i++) {
        func_020468b0(i, i, i * 3, 4, -1, 3);
    }
    for (i = 0; i < 8; i++) {
        n = func_0205d4e8(i) - 1;
        data_0217b488->mUnk_cc[n] = gRaceSetup->mCurrentEntries[i].mKartIndex;
        data_0217b488->mUnk_ac[n] = gRaceSetup->mCurrentEntries[i].mCharacterIndex;
    }
    gRaceSetup->mNextHeader.mFollowedKartIndex = func_0205d4e8((u16) gRaceSetup->mEntryIndex) - 1;
    return TRUE;
}

void func_02045a2c(s32 a) {
    u8 i;
    s8 j;
    s32 x;
    s32 y;
    if (a != 0) {
        gRaceSetup->mNextHeader.mCourseId = COURSE_ID_STAFFROLLTRUE;
    } else {
        gRaceSetup->mNextHeader.mCourseId = COURSE_ID_STAFFROLL;
    }
    gRaceSetup->mNextHeader.mUnk_0c = 6;
    gRaceSetup->mNextHeader.mEngineIndex = 1;
    gRaceSetup->mNextHeader.mFollowedKartIndex = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < gRaceSetup->mKartCount; j++) {
            if (func_0205d4e8((u16) j) == i + 1) {
                break;
            }
        }
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            if ((gRaceSetup->mMode == MODE_MISSION_RUN ? gRaceSetup->mMissionTableRow : -1) == 6 &&
                (gRaceSetup->mMode == MODE_MISSION_RUN ? gRaceSetup->mMissionTableColumn : -1) == 9) {
                if (i == 0) {
                    x = 7;
                    y = 0x15;
                } else if (i == 7) {
                    x = 0;
                    y = x;
                } else {
                    x = i;
                    y = i * 3;
                }
            } else {
                x = i;
                y = i * 3;
            }
        } else if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
            if (func_020909cc() != 2) {
                x = i;
                y = i * 3;
            } else {
                x = data_0217b488->mUnk_ac[i];
                y = data_0217b488->mUnk_cc[i];
            }
        } else {
            x = i;
            y = i * 3;
        }
        func_020468b0(i, x, y, 1, -1, 3);
    }
}

s32 func_02045920(void) {
    BOOL r;
    s32 i;
    s32 v;
    s32 x;
    r = TRUE;
    gRaceSetup->mNextHeader.mCourseNumber++;
    if (gRaceSetup->mUnk_3d4 > 1) {
        for (i = 0; i < gRaceSetup->mKartCount; i++) {
            x = gRaceSetup->mCurrentEntries[i].mPlayer.mUnk_08;
            v = 3;
            if (x != 0) {
                if (x == 1) {
                    v = 0;
                }
            } else {
                v = 1;
            }
            gRaceSetup->mNextEntries[i].mPlayer.mUnk_08 = v;
        }
    }
    switch (gRaceSetup->mCourseListMode) {
        case 0:
            r = FALSE;
            break;
        case 1:
        case 2:
            gRaceSetup->mCourseListIndex++;
            if (gRaceSetup->mCourseList[gRaceSetup->mCourseListIndex] == 0) {
                gRaceSetup->mCourseListIndex = 0;
            }
            gRaceSetup->mNextHeader.mCourseId = gRaceSetup->mCourseList[gRaceSetup->mCourseListIndex];
            break;
    }
    return r;
}

s32 func_02045914(void) {
    return func_02045920();
}

s32 func_020458cc(void) {
    if (data_021759d0->mUnk_1c_2) {
        gRaceSetup->mNextHeader.mUnk_0c = 0;
    } else {
        gRaceSetup->mNextHeader.mUnk_0c = 4;
    }
    return func_02045920();
}

BOOL func_02045874(void) {
    data_0217b488->mUnk_5c[gRaceSetup->mCourseNumber] = gRaceSetup->mCourseId;
    gRaceSetup->mNextHeader.mCourseNumber++;
    return gRaceSetup->mNextHeader.mCourseNumber <= 4;
}
