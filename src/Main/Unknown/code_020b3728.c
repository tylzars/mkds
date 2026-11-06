#include "Main/Unknown/code_020b3728.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_02089ef4.h"

#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/code_02089000.h"
#include "Main/Unknown/code_020b3b08.h"
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
#include "Main/Unknown/code_020c7000.h"
#include "Main/Unknown/code_020c70ec.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/unk_0217b35c.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020b3adc.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_020b3f64.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"

u32 func_020b3f64(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b35c;
    value1 = 1u;
    value0 = *(const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (4)) = value1;
    return value0;
}

void func_020b3cd8(void) {
    Unk021759c0 *d = data_021759c0;
    s32 a[8];
    s32 b[8];
    u16 i;
    u16 j;
    s32 n = -1;
    s32 g;
    s32 k;
    s32 m;
    s32 v;
    BOOL f;
    Unk0217aa1c_00 *q;

    if (d->mMode == MODE_TIME_ATTACK) {
        return;
    }
    if (d->mMode == MODE_MISSION_RUN) {
        return;
    }
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        if (data_021759c0->mUnk_1c == 1 || data_021759c0->mMode == MODE_BATTLE) {
            f = FALSE;
            if (data_021759c0->mCurrentEntries[i].mPlayer.mKind <= 3) {
                if ((1 << data_021759c0->mCurrentEntries[i].mPlayer.mKind) & 0xd) {
                    f = TRUE;
                }
            }
            g = f != FALSE ? 1 : 0;
            k = func_0205dc7c(i);
            m = func_0205db28();
            v = data_0217aa1c->mUnk_000[m][func_0205dc7c(k)].mUnk_05;
            a[i] = (v << 4) + (g << 3) + 8 - GetKartRank(i);
        } else {
            f = FALSE;
            if (data_021759c0->mCurrentEntries[i].mPlayer.mKind <= 3) {
                if ((1 << data_021759c0->mCurrentEntries[i].mPlayer.mKind) & 0xd) {
                    f = TRUE;
                }
            }
            g = f != FALSE ? 1 : 0;
            k = func_0205dc7c(i);
            m = func_0205db28();
            q = &data_0217aa1c->mUnk_000[m][func_0205dc7c(k)];
            v = q->mUnk_00;
            a[i] = (v << 4) + (g << 3) + 8 - GetKartRank(i);
        }
    }
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        b[i] = i;
        a[i] = a[i] * n;
    }
    SortIndicesByKey(b, a, data_021759c0->mKartCount);
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        for (j = 0; j < (u32) data_021759c0->mKartCount; j++) {
            if (i == b[j]) {
                func_0205d76c(i, j + 1);
                break;
            }
        }
    }
}

static inline Unk0217aa1c_144_00 *func_020b3b58_inline(s32 j) {
    return &data_0217aa1c->mUnk_144[func_0205db28()].mUnk_00[j];
}

static inline Unk0217aa1c_144 *func_020b3b58_inline2(void) {
    return &data_0217aa1c->mUnk_144[func_0205db28()];
}

void func_020b3b58(void) {
    Unk021759c0 *d = data_021759c0;
    s32 a;
    s32 b;
    BOOL c;
    u16 i;
    Unk0217aa1c_144_00 *q;

    if (d->mUseTeams == 0) {
        return;
    }
    if (d->mUnk_1c == 1 || d->mMode == MODE_BATTLE) {
        a = func_020b3b58_inline(0)->mUnk_02;
    } else {
        q = &data_0217aa1c->mUnk_144[func_0205db28()].mUnk_00[0];
        a = q->mUnk_00;
    }
    d = data_021759c0;
    c = TRUE;
    if (d->mUnk_1c != 1 && d->mMode != MODE_BATTLE) {
        c = FALSE;
    }
    if (c) {
        b = func_020b3b58_inline(1)->mUnk_02;
    } else {
        b = func_020b3b58_inline2()->mUnk_00[1].mUnk_00;
    }
    if (a > b) {
        func_0205d6d0(0);
        return;
    }
    if (b > a) {
        func_0205d6d0(1);
        return;
    }
    for (i = 0; i < (u32) data_021759c0->mKartCount; i++) {
        if (GetKartRank(i) == 1) {
            break;
        }
    }
    func_0205d6d0(data_021759c0->mCurrentEntries[i].mPlayer.mTeamIndex);
}

void func_020b3b08(void) {
    data_0217b35c = HeapAlloc(GetHeap(func_020364e8()), 0x10);
    data_0217b35c->mUnk_00 = 0;
    data_0217b35c->mUnk_04 = FALSE;
    data_0217b35c->mUnk_08 = 0;
    data_0217b35c->mUnk_0c = FALSE;
}

u32 func_020b3af4(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b35c;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

u32 func_020b3adc(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b35c;
    value1 = 0u;
    value0 = *(const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void func_020b3728(void) {
    Unk021759c0 *d;
    s32 a;
    s32 b;
    BOOL f;
    u16 i;

    if (gRaceProgress->mRaceDone != 0 && data_0217b35c->mUnk_0c == FALSE) {
        func_020b3cd8();
        func_020b3b58();
        func_0205eeb0();
        data_0217b35c->mUnk_0c = TRUE;
    }
    i = func_020b4d9c();
    if (gRaceProgress->mUnk_000[i].mStatus != 1 && gRaceProgress->mRaceDone == 0) {
        return;
    }
    a = data_0217b35c->mUnk_00;
    if (a < 11) {
        data_0217b35c->mUnk_00 = a + 1;
        if (a == 0) {
            d = data_021759c0;
            switch (d->mMode) {
                case MODE_GRAND_PRIX:
                case MODE_TIME_ATTACK:
                    func_02089ef4(3);
                    break;
                case MODE_VS:
                case 5:
                    if (d->mUnk_1c != 1) {
                        if (gRaceProgress->mUnk_000[func_020b4d9c()].mStatus == 1) {
                            func_02089ef4(3);
                        }
                    }
                    break;
            }
            if ((data_0217d084.mUnk_04 - 2) <= 1 && data_021759c0->mMode != MODE_BATTLE) {
                d = data_021759c0;
                f = TRUE;
                if (d->mUnk_00c == 1) {
                    f = FALSE;
                } else if (d->mMode == MODE_MISSION_RUN) {
                    switch (d->mUnk_2f) {
                        case 2:
                        case 4:
                        case 6:
                        case 10:
                            if ((IsKartEnded((u16) d->mEntryIndex) ? gRaceProgress->mEntryEndKind : 6) != 0) {
                                f = FALSE;
                            }
                            break;
                        default:
                            f = FALSE;
                            break;
                    }
                }
                if (f != FALSE) {
                    if (func_020c7148() != 0 || func_020c70ec() != 0) {
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x44);
                    } else {
                        b = gRaceProgress->mUnk_000[func_020b4d9c()].mStatus;
                        if (b == 3) {
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x43);
                        } else {
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x42);
                        }
                    }
                }
            }
        } else if (a == 10) {
            d = data_021759c0;
            switch (d->mMode) {
                case MODE_VS:
                    if (d->mUnk_1c == 1) {
                        func_02089ef4((GetKart(d->mEntryIndex)->mUnk_7c & 0x2000000) ? 4 : 5);
                    }
                    break;
                case MODE_BATTLE:
                    func_02089ef4((GetKart(d->mEntryIndex)->mUnk_7c & 0x2000000) ? 4 : 5);
                    break;
                case MODE_MISSION_RUN:
                    if ((IsKartEnded((u16) d->mEntryIndex) ? gRaceProgress->mEntryEndKind : 6) != 0) {
                        func_02089ef4(7);
                    }
                    break;
                case MODE_GRAND_PRIX:
                case MODE_TIME_ATTACK:
                case 5:
                    break;
            }
        }
    }
    if (data_0217b35c->mUnk_04 == FALSE) {
        return;
    }
    a = data_0217b35c->mUnk_08;
    data_0217b35c->mUnk_08 = a + 1;
    if (a != 10) {
        return;
    }
    d = data_021759c0;
    switch (d->mMode) {
        case MODE_MISSION_RUN:
            if ((IsKartEnded((u16) d->mEntryIndex) ? gRaceProgress->mEntryEndKind : 6) == 0) {
                func_02089ef4(6);
            }
            break;
        case MODE_GRAND_PRIX:
        case MODE_TIME_ATTACK:
        case MODE_BATTLE:
        case MODE_VS:
        case 5:
            break;
    }
    data_0217b35c->mUnk_04 = FALSE;
}
