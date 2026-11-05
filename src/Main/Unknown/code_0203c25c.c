#include "Main/Unknown/code_0203c25c.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020b1cdc.h"
#include "Main/Unknown/code_0203e74c.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_02077bc0.h"

u16 LookupRankPoints(u8 a) {
    u16 r = 0;
    RankPointRow *t = gRaceProgress->mRankPointFile;
    if (t != NULL) {
        switch (data_021759c0->mMode) {
            case MODE_GRAND_PRIX:
                break;
            case MODE_VS: {
                u16 k = 1;
                if (data_021759c0->mUseTeams != 0) {
                    if (data_021759c0->mKartCount > 3) {
                        if (data_021759c0->mTeamKartCounts[0] <= 1 || data_021759c0->mTeamKartCounts[1] <= 1) {
                            k = 8;
                        } else {
                            k = 0xf;
                        }
                    } else {
                        k = 8;
                    }
                }
                r = k + 8 - data_021759c0->mKartCount;
                break;
            }
            case 5:
                r = 9 - data_021759c0->mKartCount;
                break;
        }
        r = (t + r + 1)->mPoints[a - 1];
    }
    return r;
}

void func_0203c2e4(u16 a) {
    u32 o;
    RaceProgressKart *p = (RaceProgressKart *) ((u8 *) &gRaceProgress->mKarts[0] + a * 0x8c);
    BOOL f = FALSE;
    switch (p->mStatus) {
        case 1:
        case 2:
        case 3:
            f = TRUE;
            break;
    }
    if (f == FALSE) {
        u32 v;
        s32 i;
        o = p->mUnk_3c_0;
        v = (u16) (data_021759c0->mKartCount - gRaceProgress->mUnk_000[0].mRemovedCount);
        p->mUnk_3c_0 = data_021759c0->mKartCount - gRaceProgress->mUnk_000[0].mRemovedCount;
        for (i = 0; i < data_021759c0->mKartCount; i++) {
            RaceProgressKart *q = (RaceProgressKart *) ((u8 *) &gRaceProgress->mKarts[0] + i * 0x8c);
            if (i != a) {
                u32 m = q->mUnk_3c_0;
                if (m > o && m <= v) {
                    q->mUnk_3c_0--;
                }
            }
        }
        gRaceProgress->mUnk_000[0].mRemovedCount++;
    }
    if (data_021759c0->mMode == MODE_BATTLE) {
        func_020a16d0(a);
    }
    p->mStatus = 4;
    func_02069044(GetKart(a));
    func_020b1cdc(a, 1);
    if (func_0203ef58() != 0) {
        switch (data_021759c0->mMode) {
            case MODE_TIME_ATTACK:
                break;
            case MODE_BATTLE:
                func_020a12b8();
                break;
            case MODE_MISSION_RUN:
                func_0203eb38();
                break;
            case 5:
                func_0203ecf0();
                break;
            default:
                func_0203ee28();
                break;
        }
    }
}

BOOL IsKartOnLastLap(u16 a) {
    BOOL f = FALSE;
    BOOL r;
    switch (gRaceProgress->mUnk_000[a].mStatus) {
        case 1:
        case 2:
        case 3:
            f = TRUE;
            break;
    }
    r = f == FALSE;
    if (r != FALSE) {
        r = func_02044618() == gRaceProgress->mUnk_000[a].mLap;
    }
    return r != FALSE;
}
