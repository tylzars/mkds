#include "Main/Unknown/code_0203c5f8.h"
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
#include "Main/Unknown/code_020f36d8.h"
#include "code_0214d018.h"

s32 IsKartEnded(u32 param_1) {
    BOOL f = FALSE;
    switch (gRaceProgress->mUnk_000[param_1].mStatus) {
        case 1:
        case 2:
        case 3:
            f = TRUE;
            break;
    }
    return f;
}

void GetKartFinishTime(s32 a, u8 *b, u8 *c, u16 *d) {
    RaceProgressKart *p = OFFSET_PTR(RaceProgressKart, &gRaceProgress->mKarts[0], a * 0x8c);
    BOOL g = TRUE;
    if (data_021759c0->mMode == MODE_BATTLE) {
        if (data_021759c0->mUnk_18 == 1) {
            g = FALSE;
        }
    }
    if (g != FALSE) {
        BOOL h = FALSE;
        switch (p->mStatus) {
            case 1:
            case 2:
            case 3:
                h = TRUE;
                break;
        }
        if (h != FALSE) {
            Unk0217aa1c_144_00 *t = &p->mLapTimes[5];
            *b = t->mUnk_02;
            *c = t->mUnk_03;
            *d = t->mUnk_00;
            return;
        }
    }
    *b = 0;
    *c = 0;
    *d = 0;
}

void GetKartLapTime(s32 a, u16 b, u8 *c, u8 *d, u16 *e) {
    s32 k = b - 1;
    Unk0217aa1c_144_00 *p = OFFSET_PTR(Unk0217aa1c_144_00, &gRaceProgress->mKarts[0].mLapTimes[0], a * 0x8c);
    Unk0217aa1c_144_00 *q = &p[k];
    *c = q->mUnk_02;
    *d = q->mUnk_03;
    *e = q->mUnk_00;
}

u16 GetKartBestLapTime(u16 a, u8 *b, u8 *c, u16 *d) {
    u16 r = 1;
    u16 i;
    BOOL f = TRUE;
    u32 v1;
    Unk0217aa1c_144_00 v2;
    Unk0217aa1c_144_00 *q;
    BOOL k;
    Unk0217aa1c_144_00 *p;
    i = 1;
    if (gCourseMap->mSettings->mLapCountOrBattleSeconds >= 1) {
        v1 = a * 0x8c;
        do {
            q = OFFSET_PTR(Unk0217aa1c_144_00, &gRaceProgress->mKarts[0].mLapTimes[0], v1) + (i - 1);
            if (f != FALSE) {
                f = FALSE;
                r = i;
                v2 = *q;
            } else {
                p = &v2;
                k = FALSE;
                if (((q->mUnk_02 * 60 + q->mUnk_03) * 1000 + q->mUnk_00) <=
                    (u32) ((v2.mUnk_02 * 60 + v2.mUnk_03) * 1000 + v2.mUnk_00)) {
                    k = TRUE;
                    if (q != p) {
                        MI_CpuCopy8(q, p, 4);
                    }
                } else {
                    if (p != &v2) {
                        MI_CpuCopy8(q, p, 4);
                    }
                }
                if (k != FALSE) {
                    r = i;
                    v2 = *q;
                }
            }
            i++;
        } while (i <= gCourseMap->mSettings->mLapCountOrBattleSeconds);
    }
    *b = v2.mUnk_02;
    *c = v2.mUnk_03;
    *d = v2.mUnk_00;
    return r;
}
