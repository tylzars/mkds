#include "Main/Unknown/code_020bb5ec.h"
#include "Main/Unknown/code_02089ef4.h"

#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020b837c.h"
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
#include "Main/Unknown/code_020b19f8.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02089000.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020bc108.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_0203c5f8.h"

u32 func_020bc108(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRaceTimeDigits;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void func_020bbbb4(void) {
    u8 a;
    u8 b;
    u16 c;
    s32 i;
    s32 x;
    NNSSndSeqPlayer **r;

    if (GetRaceHudSubScreenState() == 6) {
        return;
    }
    if (func_020b1a20() != 0) {
        x = GetFollowedKartOrEntryIndex();
        GetKartLapTime(x, func_020b4d2c(), &a, &b, &c);
    } else {
        if (gRaceSetup->mMode != MODE_BATTLE && IsKartEnded(GetFollowedKartOrEntryIndex()) != 0) {
            GetKartFinishTime(GetFollowedKartOrEntryIndex(), &a, &b, &c);
        } else {
            GetRaceClockTime(&a, &b, &c);
        }
    }
    SplitTimeDigits(a, b, c, &gRaceTimeDigits->mUnk_00);
    if (gRaceTimeDigits->mUnk_1c == FALSE) {
        return;
    }
    if (a == 0 && b > 6) {
        for (i = 0; i < 6; i++) {
            gRaceTimeDigits->mUnk_20[i] = 0;
        }
        return;
    }
    if (a == 0 && ((b == 5 && c == 0) || b < 5) && gRaceTimeDigits->mUnk_20[0] == 0) {
        if (gRaceProgress->mUnk_000[GetFollowedKartOrEntryIndex()].mStatus != 2) {
            func_02089ef4(2);
        }
        if ((data_0217c780 & 1) != 0) {
            r = func_0210e128(func_02108ea0(0));
            if (data_0217d084.mUnk_0c != 0) {
                if (*r != NULL) {
                    NNS_SndPlayerStopSeq(r, 0);
                }
                if (*r != NULL) {
                    NNS_SndPlayerStopSeq(r, 0);
                }
                NNS_SndArcPlayerStartSeqArc(r, 0, 0x49);
            }
        }

        gRaceTimeDigits->mUnk_20[0] = 1;
        return;
    }
    if (a == 0 && ((b == 4 && c == 0) || b < 4) && gRaceTimeDigits->mUnk_20[1] == 0) {
        if ((data_0217c780 & 1) != 0) {
            r = func_0210e128(func_02108ea0(0));
            if (data_0217d084.mUnk_0c != 0) {
                if (*r != NULL) {
                    NNS_SndPlayerStopSeq(r, 0);
                }
                if (*r != NULL) {
                    NNS_SndPlayerStopSeq(r, 0);
                }
                NNS_SndArcPlayerStartSeqArc(r, 0, 0x49);
            }
        }

        gRaceTimeDigits->mUnk_20[1] = 1;
        return;
    }
    if (a == 0 && ((b == 3 && c == 0) || b < 3) && gRaceTimeDigits->mUnk_20[2] == 0) {
        if ((data_0217c780 & 1) != 0) {
            r = func_0210e128(func_02108ea0(0));
            if (data_0217d084.mUnk_0c != 0) {
                if (*r != NULL) {
                    NNS_SndPlayerStopSeq(r, 0);
                }
                if (*r != NULL) {
                    NNS_SndPlayerStopSeq(r, 0);
                }
                NNS_SndArcPlayerStartSeqArc(r, 0, 0x49);
            }
        }

        gRaceTimeDigits->mUnk_20[2] = 1;
        return;
    }
    if (a == 0 && ((b == 2 && c == 0) || b < 2) && gRaceTimeDigits->mUnk_20[3] == 0) {
        if ((data_0217c780 & 1) != 0) {
            r = func_0210e128(func_02108ea0(0));
            if (data_0217d084.mUnk_0c != 0) {
                if (*r != NULL) {
                    NNS_SndPlayerStopSeq(r, 0);
                }
                if (*r != NULL) {
                    NNS_SndPlayerStopSeq(r, 0);
                }
                NNS_SndArcPlayerStartSeqArc(r, 0, 0x49);
            }
        }

        gRaceTimeDigits->mUnk_20[3] = 1;
        return;
    }
    if (a == 0 && ((b == 1 && c == 0) || b < 1) && gRaceTimeDigits->mUnk_20[4] == 0) {
        if ((data_0217c780 & 1) != 0) {
            r = func_0210e128(func_02108ea0(0));
            if (data_0217d084.mUnk_0c != 0) {
                if (*r != NULL) {
                    NNS_SndPlayerStopSeq(r, 0);
                }
                if (*r != NULL) {
                    NNS_SndPlayerStopSeq(r, 0);
                }
                NNS_SndArcPlayerStartSeqArc(r, 0, 0x49);
            }
        }

        gRaceTimeDigits->mUnk_20[4] = 1;
        return;
    }
    if (a == 0 && b == 0 && c == 0) {
        if (gRaceTimeDigits->mUnk_20[5] == 0) {
            gRaceTimeDigits->mUnk_20[5] = 1;
        }
    }
}

void func_020bb5ec(Unk020d029c *p) {
    s32 a[2];
    s32 b[2];
    s32 c[2];
    s32 d[2];
    s32 e[2];
    s32 f[2];
    s32 g[2];
    s32 h[2];
    s32 j[2];
    s32 k[2];
    s32 l[2];
    s32 t[10] = {0xa6, 0xad, 0xb6, 0xbf, 0xc8, 0xd1, 0xda, 0xe3, 0xec, 0xf5};
    u32 u;
    s32 m;
    s32 n;
    s32 q;

    u = func_020b1a20();
    m = 0;
    if (GetRaceHudSubScreenState() == 6) {
        return;
    }
    if (gRaceSetup->mRaceKind == 4) {
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_DEMO) {
        return;
    }
    if (gRaceProgress->mUnk_000[GetFollowedKartOrEntryIndex()].mStatus == 3) {
        return;
    }
    if (u != 0) {
        n = (s32) func_020b1a0c() % 16;
        if (n >= 4) {
            if (n < 8) {
                m = 0xc;
            } else if (n < 12) {
                m = 0x18;
            } else {
                m = 0xc;
            }
        }
    }
    if (u != 0) {
        Unk020224e0_c *w = GetRaceSNcerEntry(m + 0x27);
        a[0] = t[0] << 12;
        a[1] = 0xc000;
        p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, w, NULL, a, 0, 1);
    } else {
        Unk020224e0_c *w = GetRaceSNcerEntry(0x26);
        b[0] = t[0] << 12;
        b[1] = 0xc000;
        p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, w, NULL, b, 0, 1);
    }
    if (gRaceTimeDigits->mUnk_00.mUnk_00[0] != 0) {
        Unk020224e0_c *w = GetRaceSNcerEntry(m + 0x28 + gRaceTimeDigits->mUnk_00.mUnk_00[0]);
        c[0] = t[1] << 12;
        c[1] = 0xc000;
        p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, w, NULL, c, 0, 1);
    }
    {
        Unk020224e0_c *w = GetRaceSNcerEntry(m + 0x28 + gRaceTimeDigits->mUnk_00.mUnk_00[1]);
        d[0] = t[2] << 12;
        d[1] = 0xc000;
        p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, w, NULL, d, 0, 1);
    }
    q = m + 0x32;
    {
        Unk020224e0_c *w = GetRaceSNcerEntry(q);
        e[0] = t[3] << 12;
        e[1] = 0xc000;
        p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, w, NULL, e, 0, 1);
    }
    {
        Unk020224e0_c *w = GetRaceSNcerEntry(m + 0x28 + gRaceTimeDigits->mUnk_00.mUnk_00[2]);
        f[0] = t[4] << 12;
        f[1] = 0xc000;
        p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, w, NULL, f, 0, 1);
    }
    {
        Unk020224e0_c *w = GetRaceSNcerEntry(m + 0x28 + gRaceTimeDigits->mUnk_00.mUnk_00[3]);
        g[0] = t[5] << 12;
        g[1] = 0xc000;
        p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, w, NULL, g, 0, 1);
    }
    {
        Unk020224e0_c *w = GetRaceSNcerEntry(q);
        h[0] = t[6] << 12;
        h[1] = 0xc000;
        p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, w, NULL, h, 0, 1);
    }
    {
        Unk020224e0_c *w = GetRaceSNcerEntry(m + 0x28 + gRaceTimeDigits->mUnk_00.mUnk_00[4]);
        j[0] = t[7] << 12;
        j[1] = 0xc000;
        p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, w, NULL, j, 0, 1);
    }
    {
        Unk020224e0_c *w = GetRaceSNcerEntry(m + 0x28 + gRaceTimeDigits->mUnk_00.mUnk_00[5]);
        k[0] = t[8] << 12;
        k[1] = 0xc000;
        p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, w, NULL, k, 0, 1);
    }
    {
        Unk020224e0_c *w = GetRaceSNcerEntry(m + 0x28 + gRaceTimeDigits->mUnk_00.mUnk_00[6]);
        l[0] = t[9] << 12;
        l[1] = 0xc000;
        p->mUnk_400 += NNS_G2dMakeCellToOams(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, w, NULL, l, 0, 1);
    }
}
