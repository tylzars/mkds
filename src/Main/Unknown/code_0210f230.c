#include "Main/Unknown/code_0210f230.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02108e38.h"

#include "Main/Unknown/code_02108000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_0210f208.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"

u32 data_0216cb4c = 0xffff;
Unk0216cb50 data_0216cb50[5] = {
    {{0x01b1, 0x01b2, 0x01b3, 0x01b4, 0x01b5, 0xffff, 0xffff, 0xffff}},
    {{0x1000, 0x1001, 0x1002, 0x1003, 0x0198, 0x0197, 0xffff, 0xffff}},
    {{0x1000, 0x1001, 0x1002, 0x1003, 0x01ab, 0xffff, 0xffff, 0xffff}},
    {{0x01cc, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff}},
    {{0x01c2, 0x01c3, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff, 0xffff}},
};

void func_0210f5d4(u32 a) {
    u32 v;
    s32 j;
    s32 i;
    u32 t;
    u32 w;

    v = 0xffff;
    switch (a) {
        case 0x1d:
            v = 0;
            break;
        case 0x1c:
            v = 1;
            break;
        case 0x20:
            v = 2;
            break;
        case 0x21:
            v = 3;
            break;
        case 0x22:
            v = 4;
            break;
    }
    data_0216cb4c = v;
    if (v != 0xffff) {
        j = 0;
        func_0210f208(data_0217d1c0, 3, j);
        func_0210f208(data_0217d1d0, 3, j);
        for (; j < 2; j++) {
            w = (j == 0 ? 0x1000 : 0x2000);
            for (i = 0; i < 8; i++) {
                if (data_0216cb50[v].mUnk_00[i] == w) {
                    func_0210f208(&data_0217d1c0[j], 0, i);
                    break;
                }
            }
        }
    }
    t = 0;
    if (v == 1 && gRaceSetup->mMode != MODE_MISSION_RUN) {
        t = 3;
    }
    data_0217d1c0[0].mUnk_04 = t;
    data_0217d1c0[0].mUnk_00 = t;
}

void func_0210f458(s32 a) {
    u16 tableValue;
    u16 lowBits;
    u16 entryIndex;
    NNSSndSeqPlayer **handle;

    tableValue = data_0216cb50[data_0216cb4c].mUnk_00[a];
    lowBits = tableValue & 0xfff;
    switch (data_0216cb4c) {
        case 3:
            if (tableValue == 0x1cc) {
                handle = GetSndHandles();
                if (*handle != NULL) {
                    NNS_SndPlayerStopSeq(handle, 0);
                }
                handle = GetSndHandleSlot(7);
                if (*handle != NULL) {
                    NNS_SndPlayerStopSeq(handle, 0);
                }
            };
            break;
        case 4:
            func_02108e38();
            break;
    }
    if (tableValue < 0xfff) {
        handle = GetSndHandleSlot(a < 5 ? a + 7 : a + 2);
        if ((data_0217c780 & 1) == 0) {
            return;
        }
        if (data_0217d084.mUnk_0c == 0) {
            return;
        }
        if (*handle != NULL) {
            NNS_SndPlayerStopSeq(handle, 0);
        }
        if (*handle != NULL) {
            NNS_SndPlayerStopSeq(handle, 0);
        }
        NNS_SndArcPlayerStartSeqArc(handle, 0, tableValue);
        return;
    }
    if (lowBits >= 4) {
        return;
    }
    entryIndex = ((tableValue & 0xf000) >> 12) - 1;
    a = a - data_0217d1c8[entryIndex].mUnk_00;
    data_0217d1c4[entryIndex].mUnk_00 = data_0217d1c0[entryIndex].mUnk_00;
    data_0217d1c0[entryIndex].mUnk_00 = a;
}

u32 func_0210f35c(s32 a, u32 soundId) {
    NNSSndSeqPlayer **handle;
    u32 v;
    u8 trackVolume;
    u32 ok;

    if (a == 0) {
        handle = GetSndHandleSlot(0xa);
    } else {
        handle = GetSndHandleSlot(0xb);
    }
    v = data_0217d1c0[a].mUnk_00;
    if (v == 0) {
        trackVolume = 0;
        ok = 0;
    } else {
        trackVolume = data_0217d1cc[a].mUnk_00[v - 1];
        ok = 1;
    }
    if (ok != 0) {
        if ((data_0217c780 & 1) != 0) {
            if (data_0217d084.mUnk_0c != 0) {
                if (*handle != NULL) {
                    NNS_SndPlayerStopSeq(handle, 0);
                }
                if (*handle != NULL) {
                    NNS_SndPlayerStopSeq(handle, 0);
                }
                NNS_SndArcPlayerStartSeqArc(handle, 0, soundId);
            }
        }
        if (*handle != NULL) {
            SetSndHandleTrackVolume(handle, trackVolume);
        }
    }
    return ok;
}

u32 func_0210f230(u32 a, u32 soundId) {
    NNSSndSeqPlayer **handle;
    u32 v;
    u8 trackVolume;
    u32 ok;

    if (a == 0) {
        handle = GetSndHandleSlot(0xa);
    } else {
        handle = GetSndHandleSlot(0xb);
    }
    v = data_0217d1c0[a].mUnk_00;
    if (v == 0) {
        trackVolume = 0;
        ok = 0;
    } else {
        trackVolume = data_0217d1cc[a].mUnk_00[v - 1];
        ok = 1;
    }
    if (ok != 0) {
        if (*handle == NULL) {
            if ((data_0217c780 & 1) != 0) {
                if (data_0217d084.mUnk_0c != 0) {
                    if (*handle != NULL) {
                        NNS_SndPlayerStopSeq(handle, 0);
                    }
                    if (*handle != NULL) {
                        NNS_SndPlayerStopSeq(handle, 0);
                    }
                    NNS_SndArcPlayerStartSeqArc(handle, 0, soundId);
                }
            }
            SetSndHandleTrackVolume(handle, trackVolume);
        } else if (*handle != NULL && data_0217d1c4[a].mUnk_00 != v) {
            SetSndHandleTrackVolume(handle, trackVolume);
        }
    } else {
        NNS_SndPlayerStopSeq(handle, 0xa);
    }
    return ok;
}
