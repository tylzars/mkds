#include "Main/Unknown/code_0203e74c.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203f2b4.h"
#include "Main/Unknown/code_0203f280.h"
#include "Main/Unknown/code_0203f320.h"
#include "Main/Unknown/code_0203f334.h"
#include "Main/Unknown/code_0204a904.h"
#include "Main/Unknown/code_0204a928.h"
#include "Main/Unknown/code_020401ac.h"
#include "Main/Unknown/code_0205a92c.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020c70ec.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_0219b580.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_02077bc0.h"

s32 func_0203ef58(void) {
    BOOL r;
    u16 i;
    s32 s;
    BOOL f;
    s32 v;
    s32 n;
    s32 m;
    Unk021759c0 *o;
    RaceProgress *q;
    o = data_021759c0;
    switch (o->mMode) {
        case MODE_GRAND_PRIX:
            r = TRUE;
            for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
                f = FALSE;
                s = o->mCurrentEntries[i].mPlayer.mKind;
                if ((u32) s <= 3 && ((1 << s) & 0xd) != 0) {
                    f = TRUE;
                }
                if (f != FALSE) {
                    s = gRaceProgress->mUnk_000[i].mStatus;
                    f = FALSE;
                    switch (s) {
                        case 1:
                        case 2:
                        case 3:
                            f = TRUE;
                            break;
                    }
                    if (f == FALSE) {
                        r = FALSE;
                        break;
                    }
                }
            }
            break;
        case MODE_VS:
            r = TRUE;
            q = gRaceProgress;
            if (q->mUnk_000[0].mFinishedCount < (s32) func_0203f320() - (q->mUnk_000[0].mRemovedCount + 1)) {
                for (i = 0; i < func_0203f320(); i++) {
                    if (func_0203f2dc(i) != FALSE && IsKartEnded(i) == 0) {
                        if (func_0203f2b4(i) == FALSE) {
                            r = FALSE;
                            break;
                        }
                    }
                }
            }
            if (r == FALSE && func_0203f2a0() == 1) {
                if (IsKartEnded(GetLeadingKart()) != 0) {
                    r = TRUE;
                }
            }
            break;
        case 5:
            v = data_0217aa18->mUnk_06[func_ov000_0219bb50()];
            if (v < 0) {
                r = FALSE;
            } else {
                n = data_021759c0->mKartCount;
                q = gRaceProgress;
                m = q->mUnk_000[0].mRemovedCount;
                if (n - m <= 1) {
                    r = FALSE;
                } else {
                    s = q->mUnk_000[(u16) v].mStatus;
                    f = FALSE;
                    switch (s) {
                        case 1:
                        case 2:
                        case 3:
                            f = TRUE;
                            break;
                    }
                    if (f == FALSE) {
                        r = q->mUnk_000[0].mFinishedCount + m >= n - 1;
                    } else {
                        r = q->mUnk_000[0].mFinishedCount + m >= n;
                    }
                }
            }
            break;
        case MODE_TIME_ATTACK:
            r = FALSE;
            switch (gRaceProgress->mUnk_000[0].mStatus) {
                case 1:
                case 2:
                case 3:
                    r = TRUE;
                    break;
            }
            break;
        case MODE_BATTLE:
            r = TRUE;
            for (i = 0; i < (u32) o->mKartCount; i++) {
                f = FALSE;
                s = o->mCurrentEntries[i].mPlayer.mKind;
                if ((u32) s <= 3 && ((1 << s) & 0xd) != 0) {
                    f = TRUE;
                }
                if (f != FALSE) {
                    if (IsKartEliminated(i) == FALSE) {
                        r = FALSE;
                        break;
                    }
                }
                o = data_021759c0;
            }
            break;
        case MODE_MISSION_RUN:
            r = FALSE;
            if (o->mUnk_2f == 6 && gRaceProgress->mUnk_000[0].mFinishedCount != 0) {
                r = TRUE;
            }
            break;
        default:
            r = FALSE;
            break;
    }
    return r;
}

void func_0203ee28(void) {
    u16 i;
    RaceProgressKart *p;
    s32 s;
    BOOL f;
    BOOL u;
    BOOL v;
    Unk0217aa1c_144_00 *t;
    u32 h;
    u = FALSE;
    v = FALSE;
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        s = ((Unk0217561c_000 *) ((u8 *) gRaceProgress + i * 0x8c))->mStatus;
        f = FALSE;
        switch (s) {
            case 1:
            case 2:
            case 3:
                f = TRUE;
                break;
        }
        if (f == FALSE && s != 4) {
            p = (RaceProgressKart *) ((u8 *) &gRaceProgress->mKarts[0] + i * 0x8c);
            t = &p->mLapTimes[5];
            h = gRaceProgress->mUnk_000[0].mElapsedFrames;
            if (data_021759c0->mMode == MODE_GRAND_PRIX) {
                if (p->mRaceProgress > 0) {
                    h = (u32) (h * ReciprocalFixed12(p->mRaceProgress)) >> 12;
                    if (h > 0x57e40) {
                        h = 0x57e40;
                    }
                } else {
                    h = 0x57e40;
                }
            }
            ComputeRaceTime(&t->mUnk_02, &t->mUnk_03, &t->mUnk_00, u, h);
            FinishRaceProgressKart(p, v);
        }
    }
    gRaceProgress->mUnk_000[0].mFinishedCount = data_021759c0->mKartCount;
}

void func_0203ecf0(void) {
    u16 i;
    RaceProgressKart *p;
    s32 s;
    BOOL f;
    BOOL u;
    BOOL v;
    Unk0217aa1c_144_00 *t;
    u32 h;
    u = FALSE;
    v = FALSE;
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        s = ((Unk0217561c_000 *) ((u8 *) gRaceProgress + i * 0x8c))->mStatus;
        f = FALSE;
        switch (s) {
            case 1:
            case 2:
            case 3:
                f = TRUE;
                break;
        }
        if (f == FALSE && s != 4) {
            p = (RaceProgressKart *) ((u8 *) &gRaceProgress->mKarts[0] + i * 0x8c);
            t = &p->mLapTimes[5];
            h = gRaceProgress->mUnk_000[0].mElapsedFrames;
            if (data_021759c0->mMode == MODE_GRAND_PRIX) {
                if (p->mRaceProgress > 0) {
                    h = (u32) (h * ReciprocalFixed12(p->mRaceProgress)) >> 12;
                    if (h > 0x57e40) {
                        h = 0x57e40;
                    }
                } else {
                    h = 0x57e40;
                }
            }
            ComputeRaceTime(&t->mUnk_02, &t->mUnk_03, &t->mUnk_00, u, h);
            func_0205ae8c(i);
            FinishRaceProgressKart(p, v);
        }
    }
    gRaceProgress->mUnk_000[0].mFinishedCount = data_021759c0->mKartCount;
}

void func_0203eb38(void) {
    u16 i;
    RaceProgressKart *p;
    Unk0206cdd4_B *q;
    s32 s;
    BOOL f;
    u32 g;
    u8 *r;
    Unk0217aa1c_144_00 *t;
    u32 h;
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        s = ((Unk0217561c_000 *) ((u8 *) gRaceProgress + i * 0x8c))->mStatus;
        f = FALSE;
        switch (s) {
            case 1:
            case 2:
            case 3:
                f = TRUE;
                break;
        }
        if (f == FALSE) {
            p = (RaceProgressKart *) ((u8 *) &gRaceProgress->mKarts[0] + i * 0x8c);
            t = &p->mLapTimes[5];
            h = gRaceProgress->mUnk_000[0].mElapsedFrames;
            if (data_021759c0->mMode == MODE_GRAND_PRIX) {
                if (p->mRaceProgress > 0) {
                    h = (u32) (h * ReciprocalFixed12(p->mRaceProgress)) >> 12;
                    if (h > 0x57e40) {
                        h = 0x57e40;
                    }
                } else {
                    h = 0x57e40;
                }
            }
            ComputeRaceTime(&t->mUnk_02, &t->mUnk_03, &t->mUnk_00, 0, h);
            g = 1;
            r = (u8 *) &data_021759c0->mUnk_028;
            q = func_0207a6b0();
            switch (r[7]) {
                case 4:
                    if (r[0xf] > (u32) q->mUnk_04) {
                        g = 0;
                    }
                    break;
                case 6:
                    if (((u32) (p->mUnk_3c << 28) >> 28) != 1) {
                        g = 0;
                    }
                    break;
            }
            if (g != 0) {
                u32 k = (u32) (p->mUnk_3c << 24) >> 28;
                if (data_021759c0->mMode == MODE_MISSION_RUN) {
                    func_0203e788(k, 0);
                }
            } else {
                func_0203e788((u32) (p->mUnk_3c << 24) >> 28, 4);
            }
        }
    }
    gRaceProgress->mUnk_000[0].mFinishedCount = data_021759c0->mKartCount;
}

void FinishRaceProgressKart(RaceProgressKart *a, s32 b) {
    Unk0217aa1c_144_00 *t;
    s32 c;
    s32 m;
    s16 d;
    c = data_021759c0->mCurrentEntries[(u32) (a->mUnk_3c << 24) >> 28].mPlayer.mIndex;
    if (b != 0) {
        a->mStatus = 1;
    } else {
        a->mStatus = 3;
    }
    switch (data_02175628[c].mSourceKind) {
        case 2:
            func_0204a928(&data_02175628[c].mUnk_28);
            break;
        case 1:
            func_0204a904((Unk02175650 *) &data_02175628[c].mUnk_28);
            break;
    }
    a->mFlags |= 8;
    if ((a->mFlags & 1) != 0 && (a->mFlags & 0x10) == 0) {
        func_020c7164();
    }
    t = &a->mLapTimes[5];
    if (b != 0) {
        a->mFinishTimeMs = (t->mUnk_02 * 0x3c + t->mUnk_03) * 1000 + t->mUnk_00;
    } else if (data_021759c0->mMode != 5) {
        a->mFinishTimeMs = 0x5b8d80;
    }
    m = data_021759c0->mMode;
    if (m == MODE_GRAND_PRIX || m == MODE_MISSION_RUN) {
        if ((a->mFlags & 1) != 0) {
            a->mScore = func_020408f0((u32) (a->mUnk_3c << 24) >> 28);
            d = a->mScore;
            if (data_021759c0->mMode == MODE_MISSION_RUN) {
                data_0217aa1c->mUnk_140 = d;
            } else {
                data_0217aa1c->mUnk_140 += d;
            }
        }
    }
    gRaceProgress->mUnk_000[0].mFinishedCount++;
}

void func_0203e788(s32 a, s32 b) {
    Kart *q;
    Unk0217aa1c_144_00 t;
    s32 s;
    BOOL f;
    RaceProgressKart *e;
    e = (RaceProgressKart *) ((u8 *) &gRaceProgress->mKarts[0] + a * 0x8c);
    s = e->mStatus;
    f = FALSE;
    switch (s) {
        case 1:
        case 2:
        case 3:
            f = TRUE;
            break;
    }
    if (f != FALSE) {
        return;
    }
    if ((e->mFlags & 0x10) != 0) {
        return;
    }
    if ((e->mFlags & 0x20) != 0) {
        return;
    }
    q = GetKart(a);
    e = (RaceProgressKart *) ((u8 *) &gRaceProgress->mKarts[0] + a * 0x8c);
    gRaceProgress->mUnk_000[0].mClockEnabled = 0;
    ComputeRaceTime(&t.mUnk_02, &t.mUnk_03, &t.mUnk_00, 0, gRaceProgress->mUnk_000[0].mElapsedFrames);
    e->mLapTimes[5] = t;
    if ((e->mFlags & 1) != 0) {
        gRaceProgress->mUnk_4e0 = b;
        q->mUnk_7c |= 0x20000000;
        q->mUnk_48 &= ~0x2000000;
        if (b == 0) {
            e->mFlags |= 0x10;
            gRaceProgress->mFramesSinceFinish = 0;
            if (data_021759c0->mMode == MODE_MISSION_RUN) {
                func_020a12b8();
            }
        } else {
            e->mFlags |= 0x20;
            gRaceProgress->mUnk_4fc = 0;
            if (data_021759c0->mMode == MODE_MISSION_RUN) {
                ((void (*)(s32)) func_020a16d0)(a);
            }
        }
    }
    FinishRaceProgressKart(e, b == 0);
    if (func_0203ef58() == 0) {
        return;
    }
    switch (data_021759c0->mMode) {
        case MODE_BATTLE:
            func_020a12b8();
            return;
        case MODE_MISSION_RUN:
            func_0203eb38();
            return;
        case 5:
            func_0203ecf0();
            return;
        default:
            func_0203ee28();
            return;
        case MODE_TIME_ATTACK:
            return;
    }
}

void func_0203e74c(u16 param_1) {
    if (data_021759c0->mMode != MODE_MISSION_RUN) {
        return;
    }
    func_0203e788(param_1, 0);
}
