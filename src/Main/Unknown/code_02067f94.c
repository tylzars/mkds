#include "Main/Unknown/code_02067f94.h"
#include "Main/Unknown/code_0206a000.h"
#include "Main/Unknown/code_0206a354.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0207a6b0.h"
#include "Main/Unknown/code_02077bc0.h"

void func_020680e0(Kart *kart, const Vec3 *direction) {
    s32 c;
    BOOL d;
    s32 e;
    BOOL started;
    u32 kartBits;
    s32 state;

    kartBits = kart->mUnk_4c;
    if ((kartBits & 0x400000) != 0) {
        c = 0;
    } else if ((kart->mUnk_7c & 0x200) != 0) {
        if (kart->mState == KART_STATE_NORMAL && (kart->mUnk_48 & 0x1800) == 0 && (kartBits & 0x10000040) == 0) {
            c = 1;
        } else {
            c = 0;
        }
    } else {
        d = TRUE;
        if ((kartBits & 0x10000040) == 0 && (kart->mUnk_48 & 0x1800) == 0) {
            e = 0;
            state = kart->mState;
            if (state != KART_STATE_NORMAL && state != KART_STATE_1 && state != KART_STATE_SPIN) {
                e = d;
            }
            if (e == 0) {
                d = FALSE;
            }
        }
        c = d == FALSE ? 1 : 0;
    }
    if (c != 0) {
        StartKartState4(kart, direction, 0);
        started = TRUE;
    } else {
        started = FALSE;
    }
    if (started == FALSE) {
        return;
    }
    if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
        GetEntryKartCounters()->mUnk_14++;
    }
    kart->mUnk_48 |= 0x20000;
}

void func_02068094(Kart *kart, s32 b, Unk0206b020 *mapObject) {
    if (TryStartKartState4(kart, mapObject) == FALSE) {
        return;
    }
    if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
        GetEntryKartCounters()->mUnk_14++;
    }
    kart->mUnk_48 |= 0x20000;
}

void func_02067f94(Kart *kart, const Vec3 *direction) {
    s32 c;
    BOOL d;
    s32 e;
    BOOL started;
    u32 kartBits;
    s32 state;

    kartBits = kart->mUnk_4c;
    if ((kartBits & 0x400000) != 0) {
        c = 0;
    } else if ((kart->mUnk_7c & 0x200) != 0) {
        if (kart->mState == KART_STATE_NORMAL && (kart->mUnk_48 & 0x1800) == 0 && (kartBits & 0x10000040) == 0) {
            c = 1;
        } else {
            c = 0;
        }
    } else {
        d = TRUE;
        if ((kartBits & 0x10000040) == 0 && (kart->mUnk_48 & 0x1800) == 0) {
            e = 0;
            state = kart->mState;
            if (state != KART_STATE_NORMAL && state != KART_STATE_1 && state != KART_STATE_SPIN) {
                e = d;
            }
            if (e == 0) {
                d = FALSE;
            }
        }
        c = d == FALSE ? 1 : 0;
    }
    if (c != 0) {
        StartKartState5(kart, direction, 0);
        started = TRUE;
    } else {
        started = FALSE;
    }
    if (started == FALSE) {
        return;
    }
    if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
        GetEntryKartCounters()->mUnk_14++;
    }
    kart->mUnk_48 |= 0x20000;
}
