#include "Main/Unknown/code_02108e6c.h"

#include "Main/Unknown/code_02108e94.h"
#include "Main/Unknown/code_0210d000.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_02108eb4.h"
#include "Main/Unknown/code_02108ec4.h"
#include "Main/Unknown/code_02108ed8.h"
#include "Main/Unknown/code_02108edc.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210d740.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"

void func_02108edc(s32 a, s32 b) {
    u32 c;
    PlayingSound *playingSound;

    if (a == b) {
        if (data_0217c76c[0] != 0xff) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, data_0217c76c[0]);
        }
        if (data_0217c76c[0] == 0x1d7) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1de);
            return;
        }
        c = gRaceSetup->mUnk_3c;
        if (c == 0x65 || c == 0xc9) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0xd4);
        }
    } else {
        c = data_0217c770[0];
        if (c == 0xff) {
            return;
        }
        if (!(data_0217c780 & 1)) {
            return;
        }
        playingSound = func_0210e128(&data_0217c7c4);
        if (data_0217d084.mUnk_0c == 0) {
            return;
        }
        if (playingSound->mUnk_00 != NULL) {
            NNS_SndPlayerStopSeq(&playingSound->mUnk_00, 0);
        }
        if (playingSound->mUnk_00 != NULL) {
            NNS_SndPlayerStopSeq(&playingSound->mUnk_00, 0);
        }
        NNS_SndArcPlayerStartSeqArc(&playingSound->mUnk_00, 0, c);
    }
}

void func_02108ed8(void) {}

u32 SetCurrentSndArc(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &NNS_SndArcSetCurrent;
    value0 = (u32) &data_0217d0a0;
    value0 = (u32) NNS_SndArcSetCurrent((NNSSndArc *) value0);
    return value0;
}

void func_02108eb4(u32 index, u32 value) {
    u32 indexCopy = index;
    u32 valueCopy = value;
    u32 table;
    table = (u32) &data_0217c7fc;
    *(u32 *) ((table) + ((indexCopy << 2))) = valueCopy;
}

Unk0217c7c4 *func_02108ea0(u32 index) {
    u32 value0 = index;
    u32 elementSize;
    u32 base;
    base = (u32) &data_0217c7c4;
    elementSize = 0x14u;
    value0 = (elementSize) * (value0) + (base);
    return (Unk0217c7c4 *) value0;
}

void SetSoundOutputEffect(s32 type) {
    ChangeSoundOutputEffect(type);
}

NNSSndSeqPlayer **GetSndHandles(void) {
    return data_0217c838;
}

NNSSndSeqPlayer **func_02108e7c(void) {
    return &data_0217c83c;
}

NNSSndSeqPlayer **GetSndHandleSlot(u32 index) {
    return data_0217c838 + index;
}
