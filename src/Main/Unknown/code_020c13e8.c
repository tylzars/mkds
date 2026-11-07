#include "Main/Unknown/code_020c13e8.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b1d64.h"
#include "Main/Unknown/code_020c0dd8.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020c13d0.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020b1000.h"
#include "Main/Unknown/code_0203c8dc.h"

void func_020c1ef8(void) {
    s32 a[8];
    u32 w;
    s32 neg;
    BOOL x0;
    s32 x1;
    s32 v;
    s32 c;
    u16 i;

    if (gRaceProgress->mRaceDone == 0) {
        return;
    }
    gRaceGoalS->mUnk_00a4 = 1;
    if (gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mUseTeams != 0) {
        gRaceGoalS->mUnk_00ac = func_020c0f48;
        gRaceGoalS->mUnk_00b0 = 0;
        func_020b1d90();
    } else {
        gRaceGoalS->mUnk_00ac = func_020c1e70;
        gRaceGoalS->mUnk_00b0 = 0;
    }
    neg = -1;
    x0 = FALSE;
    x1 = 0;
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        gRaceGoalS->mUnk_0040[i] = i;
        if (gRaceSetup->mUnk_1c == 1 || gRaceSetup->mMode == MODE_BATTLE) {
            v = x0;
            if (gRaceSetup->mCurrentEntries[i].mPlayer.mKind <= 3 &&
                ((1 << gRaceSetup->mCurrentEntries[i].mPlayer.mKind) & 0xd)) {
                v = 1;
            }
            c = v != 0 ? 1 : x1;
            a[i] = c * 8 + 8 - GetKartRank(i);
            if (GetKartRank(i) == 1) {
                a[i] += 0x20;
            }
            a[i] = a[i] * neg;
        } else {
            a[i] = GetKartRank(i);
        }
    }
    SortIndicesByKey(gRaceGoalS->mUnk_0040, a, gRaceSetup->mKartCount);
    if (gRaceSetup->mMode == MODE_VS || gRaceSetup->mMode == 5) {
        if (TryGetRaceUpdateFramesSinceEntryEnd(&w) != 0) {
            if (w >= 0xb4) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x46);
            }
        }
    }
}

void func_020c1e70(void) {
    s32 n;

    n = gRaceGoalS->mUnk_00b0++;
    if (n < 0x14) {
        gRaceGoalS->mUnk_00a0 = InterpolateS16(1, -0x100, 0, n, 0x14);
    } else {
        gRaceGoalS->mUnk_00a0 = 0;
        gRaceGoalS->mUnk_00ac = func_020c1de4;
        gRaceGoalS->mUnk_00b0 = 0;
    }
}

void func_020c1de4(void) {
    s32 n;
    u16 f;
    Unk02175628Index i;

    n = gRaceGoalS->mUnk_00b0++;
    if (n >= 0x5a) {
        gRaceGoalS->mUnk_00ac = func_020c1bc0;
        gRaceGoalS->mUnk_00b0 = 0;
    }
    i = UNK_02175628_INDEX_8;
    f = data_02175628[i].mUnk_00 & 1;
    if (f != 0 && n >= 0x2d) {
        gRaceGoalS->mUnk_00ac = func_020c1bc0;
        gRaceGoalS->mUnk_00b0 = 0;
    }
}

void func_020c1bc0(void) {
    s32 n;
    u16 f;
    u16 i;
    BOOL t;
    s32 v;
    u32 p;
    u32 r;
    Unk0217aa1c_00 *s;
    Unk02175628Index x;

    n = gRaceGoalS->mUnk_00b0++;
    if (n % 5 == 0) {
        t = TRUE;
        for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
            if (gRaceSetup->mUnk_1c == 1 || gRaceSetup->mMode == MODE_BATTLE) {
                p = func_0205dc7c(i);
                r = GetCourseIndexInCup();
                v = data_0217aa1c->mUnk_000[r][func_0205dc7c(p)].mUnk_05;
            } else {
                p = func_0205dc7c(i);
                r = GetCourseIndexInCup();
                s = &data_0217aa1c->mUnk_000[r][func_0205dc7c(p)];
                v = s->mUnk_00;
            }
            if (gRaceGoalS->mUnk_0020[i] < v) {
                if (gRaceGoalS->mUnk_0020[i] < 0x3e8) {
                    gRaceGoalS->mUnk_0020[i]++;
                    t = FALSE;
                }
            }
        }
        if (t != FALSE) {
            gRaceGoalS->mUnk_00ac = func_020c195c;
            gRaceGoalS->mUnk_00b0 = 0;
            gRaceGoalS->mUnk_00b0 = 0;
            if (gRaceSetup->mUnk_1c == 1 || gRaceSetup->mMode == MODE_BATTLE) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x29);
            }
        } else {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x29);
        }
    }
    x = UNK_02175628_INDEX_8;
    f = data_02175628[x].mUnk_00 & 1;
    if (f != 0 && n >= 0x2d) {
        gRaceGoalS->mUnk_00ac = func_020c195c;
        gRaceGoalS->mUnk_00b0 = 0;
    }
}

void func_020c195c(void) {
    s32 n;
    u16 f;
    u16 i;
    u32 p;
    u32 r;
    Unk0217aa1c_00 *s;
    Unk02175628Index x;

    n = gRaceGoalS->mUnk_00b0++;
    if (n < 0x5a) {
        for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
            if (gRaceSetup->mUnk_1c == 1 || gRaceSetup->mMode == MODE_BATTLE) {
                p = func_0205dc7c(i);
                r = GetCourseIndexInCup();
                gRaceGoalS->mUnk_0020[i] = data_0217aa1c->mUnk_000[r][func_0205dc7c(p)].mUnk_05;
            } else {
                p = func_0205dc7c(i);
                r = GetCourseIndexInCup();
                s = &data_0217aa1c->mUnk_000[r][func_0205dc7c(p)];
                gRaceGoalS->mUnk_0020[i] = s->mUnk_00;
            }
        }
    } else {
        if (gRaceSetup->mUseTeams != 0) {
            gRaceGoalS->mUnk_00ac = func_020c0fd0;
            gRaceGoalS->mUnk_00b0 = 0;
        } else if (gRaceSetup->mCourseNumber == 1) {
            gRaceGoalS->mUnk_00ac = func_020c13e8;
            gRaceGoalS->mUnk_00b0 = 0;
        } else {
            gRaceGoalS->mUnk_00ac = func_020c1728;
            gRaceGoalS->mUnk_00b0 = 0;
        }
    }
    x = UNK_02175628_INDEX_8;
    f = data_02175628[x].mUnk_00 & 1;
    if (f != 0 && n >= 0x2d) {
        if (gRaceSetup->mUseTeams != 0) {
            gRaceGoalS->mUnk_00ac = func_020c0fd0;
            gRaceGoalS->mUnk_00b0 = 0;
        } else if (gRaceSetup->mCourseNumber == 1) {
            gRaceGoalS->mUnk_00ac = func_020c13e8;
            gRaceGoalS->mUnk_00b0 = 0;
        } else {
            gRaceGoalS->mUnk_00ac = func_020c1728;
            gRaceGoalS->mUnk_00b0 = 0;
        }
    }
}

void func_020c1728(void) {
    s32 n;
    s32 m;
    u16 f;
    u16 j;
    Unk02175628Index i;

    n = gRaceGoalS->mUnk_00b0++;
    if (n < 0x2d) {
        m = gRaceGoalS->mUnk_00a8;
        if (m < gRaceSetup->mKartCount) {
            if (n % 5 == 0) {
                switch (m) {
                    case 0:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x32);
                        break;
                    case 1:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x33);
                        break;
                    case 2:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x34);
                        break;
                    case 3:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x35);
                        break;
                    case 4:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x36);
                        break;
                    case 5:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x37);
                        break;
                    case 6:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x38);
                        break;
                    case 7:
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x39);
                        break;
                }
                gRaceGoalS->mUnk_0000[gRaceGoalS->mUnk_00a8++] = 0;
            }
        }
    } else {
        func_020c1060();
        gRaceGoalS->mUnk_00ac = func_020c155c;
        gRaceGoalS->mUnk_00b0 = 0;
    }
    i = UNK_02175628_INDEX_8;
    f = data_02175628[i].mUnk_00 & 1;
    if (f != 0 && n >= 0x2d) {
        for (j = 0; j < (u32) gRaceSetup->mKartCount; j++) {
            gRaceGoalS->mUnk_0000[j] = 0;
        }
        gRaceGoalS->mUnk_00a8 = gRaceSetup->mKartCount;
        func_020c1060();
        gRaceGoalS->mUnk_00ac = func_020c155c;
        gRaceGoalS->mUnk_00b0 = 0;
    }
}

void func_020c155c(void) {
    s32 n;
    s32 m;
    u16 f;
    Unk02175628Index i;

    n = gRaceGoalS->mUnk_00b0++;
    m = gRaceGoalS->mUnk_00a8;
    if (m > 0) {
        if (n % 5 == 0) {
            gRaceGoalS->mUnk_00a8 = m - 1;
            gRaceGoalS->mUnk_0000[gRaceGoalS->mUnk_00a8] = 1;
            switch (gRaceGoalS->mUnk_00a8) {
                case 0:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x2a);
                    break;
                case 1:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x2b);
                    break;
                case 2:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x2c);
                    break;
                case 3:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x2d);
                    break;
                case 4:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x2e);
                    break;
                case 5:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x2f);
                    break;
                case 6:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x30);
                    break;
                case 7:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x31);
                    break;
            }
        }
    } else {
        gRaceGoalS->mUnk_00ac = func_020c13e8;
        gRaceGoalS->mUnk_00b0 = 0;
    }
    i = UNK_02175628_INDEX_8;
    f = data_02175628[i].mUnk_00 & 1;
    if (f != 0 && n >= 0x2d) {
        gRaceGoalS->mUnk_00ac = func_020c13e8;
        gRaceGoalS->mUnk_00b0 = 0;
    }
}

static inline Unk0217aa1c_144_00 *func_020c13e8_inline(s32 j) {
    return &data_0217aa1c->mUnk_144[GetCourseIndexInCup()].mUnk_00[j];
}

void func_020c13e8(void) {
    s32 n;
    s32 i;
    s32 a;
    s32 b;

    n = gRaceGoalS->mUnk_00b0++;
    if (n < 0x3c) {
        func_020c1060();
        for (i = 0; i < gRaceSetup->mKartCount; i++) {
            gRaceGoalS->mUnk_0000[i] = 1;
        }
    } else {
        if (gRaceSetup->mUnk_1c == 1 || gRaceSetup->mMode == MODE_BATTLE) {
            if (gRaceSetup->mUseTeams != 0) {
                a = func_020c13e8_inline(0)->mUnk_02;
                b = func_020c13e8_inline(1)->mUnk_02;
                if (a <= b) {
                    a = b;
                }
            } else {
                a = gRaceGoalS->mUnk_0020[gRaceGoalS->mUnk_0040[0]];
            }
            gRaceGoalS->mUnk_00b4 = a >= gRaceSetup->mCourseCount;
        } else {
            gRaceGoalS->mUnk_00b4 = gRaceSetup->mCourseNumber >= gRaceSetup->mCourseCount;
        }
        gRaceGoalS->mUnk_00ac = func_020c13d0;
        gRaceGoalS->mUnk_00b0 = 0;
    }
}
