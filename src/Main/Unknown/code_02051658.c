#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0200eddc.h"
#include "code_020204c0.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_02051640.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_02053000.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02054000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_021445e0.h"
#include "wm_etc.h"
#include "code_02142eac.h"
#include "code_0214d018.h"

static inline u32 func_02051658_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

void StartScan(s32 a, s32 (*b)(), s32 (*c)()) {
    ConnectionWork *connection;
    Unk0217aa00_ac *s;
    Unk02143a78 *scanParams;
    u16 channel;
    s32 i;
    u16 allowedChannels;

    connection = data_0217aa00;
    s = &connection->mUnk_00ac_view;
    channel = s->mUnk_38d;
    scanParams = connection->mUnk_001c;
    connection->mUnk_0000 = 2;
    data_0217aa00->mUnk_000c = 7;
    data_0217aa00->mRequestPending = 1;
    allowedChannels = WM_GetAllowedChannel();
    if (allowedChannels == 0) {
        data_0217aa00->mRequestPending = 0;
        data_0217aa00->mUnk_0008 = 3;
        data_0217aa00->mRequestPending = 0;
        return;
    }
    if (allowedChannels == 0x8000) {
        data_0217aa00->mRequestPending = 0;
        data_0217aa00->mUnk_0008 = 8;
        data_0217aa00->mRequestPending = 0;
        return;
    }
    if (s->mUnk_38c == 0) {
        if (((1 << (channel - 1)) & allowedChannels) == 0) {
            do {
                channel = channel + 1;
                if (channel > 0xe) {
                    channel = 1;
                }
            } while (((1 << (channel - 1)) & allowedChannels) == 0);
        }
        scanParams->mUnk_04 = channel;
        s->mUnk_38d = channel;
        for (i = 0; i < 6; i++) {
            scanParams->mUnk_08[i] = 0xff;
        }
    } else {
        scanParams->mUnk_08[0] = s->mUnk_380[0];
        scanParams->mUnk_08[1] = s->mUnk_380[1];
        scanParams->mUnk_08[2] = s->mUnk_380[2];
        scanParams->mUnk_08[3] = s->mUnk_380[3];
        scanParams->mUnk_08[4] = s->mUnk_380[4];
        scanParams->mUnk_08[5] = s->mUnk_380[5];
        s->mUnk_38c = s->mUnk_38c - 1;
    }
    scanParams->mUnk_06 = WM_GetDispersionScanPeriod();
    if (WM_StartScan(StartScanCallback, scanParams) != 2) {
        data_0217aa00->mUnk_0436 &= ~1;
        func_020533a0();
        return;
    }
    data_0217aa00->mUnk_0436 |= 1;
    data_0217aa00->mUnk_0440 = b;
    data_0217aa00->mUnk_0444 = c;
    if (a != 0) {
        s->mUnk_38f = 1;
    } else {
        s->mUnk_38f = 0;
    }
}

void func_020525a8(ScanSlot *slot, ScanBlockView *scanBuffer, Unk0217aa00_42c *key, Unk0217aa00_24_50 *d, u8 e) {
    s32 n0;
    u8 n1;
    s32 k;

    if (e >= 4) {
        return;
    }
    k = d->mUnk_0e.mUnk_07_0;
    if (k != 0) {
        if (data_0217aa00->mUnk_1d00 != 2) {
            return;
        }
        n1 = d->mUnk_0e.mUnk_06_4;
        n0 = d->mUnk_0e.mUnk_06_0;
        MI_CpuCopy8(scanBuffer, slot, 0xc0);
        slot->mUnk_c0_42c = *key;
        slot->mUnk_dc_0 = 1;
        slot->mUnk_db = 0;
        if (n0 >= 0) {
            slot->mUnk_da = n0;
        }
        slot->mUnk_dc_1 = n1;
        slot->mUnk_dc_5 = 0;
        slot->mUnk_dc_6 = k;
        MI_CpuCopy8(d, slot->mUnk_c6, 0x14);
        SetScanGhostInfo(e, d);
    } else {
        s32 m0;
        u8 m1;

        if (data_0217aa00->mUnk_1d00 == 2) {
            return;
        }
        m1 = d->mUnk_0e.mUnk_06_4;
        m0 = d->mUnk_0e.mUnk_06_0;
        MI_CpuCopy8(scanBuffer, slot, 0xc0);
        slot->mUnk_c0_42c = *key;
        slot->mUnk_dc_0 = 1;
        slot->mUnk_db = 0;
        if (m0 >= 0) {
            slot->mUnk_da = m0;
        }
        slot->mUnk_dc_1 = m1;
        slot->mUnk_dc_5 = 0;
        slot->mUnk_dc_6 = k;
        MI_CpuCopy8(d, slot->mUnk_c6, 0x14);
    }
}

void FindOrAddScanSlot(ScanBlockView *scanBuffer, Unk0217aa00_42c *key, Unk0217aa00_24_50 *c) {
    Unk0217aa00_24_50_0e_36 *x;
    s32 i;
    s32 n;
    Unk0217aa00_ac *s;
    ScanSlot *chosenSlot;
    ScanSlot *g;
    ConnectionWork *connection;
    BOOL found;
    ScanSlot *slot;
    Unk0217aa00_24_50_0e *u;
    Unk0217aa00_24_50 *t;
    s8 v;

    connection = data_0217aa00;
    chosenSlot = NULL;
    g = connection->mUnk_00ac;
    n = 0;
    found = FALSE;
    for (i = 0, slot = g; i < 4; i++, slot++) {
        if (slot->mUnk_dc_0 != 0 && key->mUnk_00[0] == slot->mUnk_c0[0] && key->mUnk_00[1] == slot->mUnk_c0[1] &&
            key->mUnk_00[2] == slot->mUnk_c0[2] && key->mUnk_00[3] == slot->mUnk_c0[3] &&
            key->mUnk_00[4] == slot->mUnk_c0[4] && key->mUnk_00[5] == slot->mUnk_c0[5]) {
            chosenSlot = slot;
            found = TRUE;
            break;
        }
    }
    if (chosenSlot == NULL) {
        for (i = 0, slot = g; i < 4; i++, slot++) {
            if (slot->mUnk_dc_0 == 0) {
                chosenSlot = slot;
                break;
            }
        }
    }
    if (chosenSlot == NULL) {
        for (i = 0; i < 4; i++) {
            if (g->mUnk_db < 5) {
                if (g->mUnk_db > n) {
                    n = g->mUnk_db;
                    chosenSlot = g;
                }
            }
            g++;
        }
    }
    if (chosenSlot == NULL) {
        return;
    }
    if ((scanBuffer->mUnk_4b & 2) != 0) {
        if (connection->mUnk_1d00 != 2) {
            t = &scanBuffer->mUnk_50;
            if (t->mUnk_07 == 5) {
                u = (void *) &t->mUnk_0e;
                x = &u->mUnk_36;
                v = -(found != FALSE);
                MI_CpuCopy8(scanBuffer, chosenSlot, 0xc0);
                chosenSlot->mUnk_c0_42c = *key;
                chosenSlot->mUnk_dc_0 = 1;
                chosenSlot->mUnk_db = 0;
                if (v >= 0) {
                    chosenSlot->mUnk_da = v;
                }
                chosenSlot->mUnk_dc_1 = 0;
                chosenSlot->mUnk_dc_5 = 1;
                chosenSlot->mUnk_dc_6 = 0;
                MI_CpuCopy8(x->mUnk_02, chosenSlot->mUnk_c6, 0x14);
                data_0217aa00->mUnk_0438 = 0;
            } else if (t->mUnk_07 == 9) {
                if (chosenSlot->mUnk_dc_0 != 0) {
                    chosenSlot->mUnk_da = t->mUnk_0a - 1;
                }
            } else if (chosenSlot->mUnk_dc_0 != 0) {
                chosenSlot->mUnk_db = 0;
            } else {
                connection = data_0217aa00;
                *(Unk0217aa00_42c *) &connection->mUnk_042c = *key;
                connection->mUnk_0438 = 0xf;
            }
        }
    } else if (scanBuffer->mUnk_4a == 0x1c) {
        func_020525a8(chosenSlot, scanBuffer, key, c, i);
    }
    s = &data_0217aa00->mUnk_00ac_view;
    s->mUnk_388 = 0;
    for (i = 0, slot = s->mUnk_000; i < 4; i++, slot++) {
        if (slot->mUnk_dc_0 != 0) {
            s->mUnk_388 += 1;
        }
    }
}

void StartScanCallback(Unk021425e8 *event) {
    ScanBlockView scanBuffer;
    Unk0217aa00_42c key;
    s32 i;
    ConnectionWork *connection;
    s32 j;
    ScanSlot *q;
    Unk0217aa00_ac *s;
    u16 v;
    BOOL accepted;
    ScanSlot *e;

    if (data_0217aa00->mUnk_000c != 7) {
        return;
    }
    if (event->mResultCode == 0) {
        switch (event->mUnk_08_0) {
            case 5:
                DC_InvalidateRange(data_0217aa00->mUnk_0028, 0xc0);
                MI_CpuCopy8(data_0217aa00->mUnk_0028, &scanBuffer, 0xc0);
                DC_StoreRange(&scanBuffer, 0xc0);
                if (data_0217aa00->mUnk_0004 == 0xd) {
                    v = event->mUnk_12;
                    if (func_020204c0(&scanBuffer) != 0) {
                        data_0217aa00->mUnk_1ed0 = 1;
                        data_0217aa00->mUnk_1ed4 = v;
                        data_0217aa00->mUnk_1ed6 = 0;
                    } else if (scanBuffer.mUnk_3c >= 8 && scanBuffer.mUnk_44 == 0x25 && (scanBuffer.mUnk_4b & 1) != 0) {
                        if ((scanBuffer.mUnk_4b & 2) != 0) {
                            data_0217aa00->mUnk_1ed8 = 2;
                        } else {
                            data_0217aa00->mUnk_1ed8 = 3;
                        }
                        data_0217aa00->mUnk_1edc = v;
                        data_0217aa00->mUnk_1ede = 0;
                    }
                } else {
                    accepted = TRUE;
                    if (scanBuffer.mUnk_3c < 8 || scanBuffer.mUnk_44 != 0x25 || (scanBuffer.mUnk_4b & 1) == 0) {
                        accepted = FALSE;
                    } else if (data_0217aa00->mUnk_0444 != 0) {
                        if (data_0217aa00->mUnk_0444(&scanBuffer) == 0) {
                            accepted = FALSE;
                        }
                    }
                    if (accepted != FALSE) {
                        if (data_0217aa00->mUnk_0440 != 0) {
                            data_0217aa00->mUnk_0440(event, &scanBuffer);
                        } else if ((data_0217aa00->mUnk_0436 & 1) != 0) {
                            if ((scanBuffer.mUnk_48 & 0x8000) != 0) {
                                key.mUnk_00[0] = event->mUnk_0a[0];
                                key.mUnk_00[1] = event->mUnk_0a[1];
                                key.mUnk_00[2] = event->mUnk_0a[2];
                                key.mUnk_00[3] = event->mUnk_0a[3];
                                key.mUnk_00[4] = event->mUnk_0a[4];
                                key.mUnk_00[5] = event->mUnk_0a[5];
                                FindOrAddScanSlot(&scanBuffer, &key, &scanBuffer.mUnk_50);
                                *data_0217aa00->mUnk_0024 = scanBuffer;
                            }
                        }
                    } else if (data_0217aa00->mUnk_0438 == 0) {
                        data_0217aa00->mUnk_0439 += 1;
                    }
                }
                break;
            case 4:
                if (data_0217aa00->mUnk_0438 == 0) {
                    data_0217aa00->mUnk_0439 += 1;
                }
                break;
        }
        connection = data_0217aa00;
        if ((connection->mUnk_0436 & 1) != 0 && connection->mUnk_0004 != 0xd) {
            for (i = 0, e = connection->mUnk_00ac; i < 4; i++, e++) {
                if (e->mUnk_dc_0 != 0) {
                    e->mUnk_db += 1;
                    if (e->mUnk_db > 0xc8) {
                        e->mUnk_dc_0 = 0;
                        s = &data_0217aa00->mUnk_00ac_view;
                        s->mUnk_388 = 0;
                        for (j = 0, q = s->mUnk_000; j < 4; j++, q++) {
                            if (q->mUnk_dc_0 != 0) {
                                s->mUnk_388 += 1;
                            }
                        }
                    }
                }
            }
        }
        if (data_0217aa00->mUnk_043b == 0) {
            data_0217aa00->mRequestPending = 0;
            return;
        }
        StartScan(1, data_0217aa00->mUnk_0440, data_0217aa00->mUnk_0444);
    } else {
        func_020533a0();
    }
}

void EndScan(void) {
    data_0217aa00->mUnk_0436 &= ~1;
    data_0217aa00->mUnk_000c = 9;
    data_0217aa00->mRequestPending = 1;
    if (WM_EndScan(EndScanCallback) == 2) {
        return;
    }
    func_020533a0();
}

void EndScanCallback(Unk021425e8 *event) {
    data_0217aa00->mRequestPending = 0;
    if (event->mResultCode == 0) {
        return;
    }
    func_020533a0();
}

void StartConnect(ScanBlockView *a, void *b, s32 (*c)(), s32 (*d)(), s32 (*e)()) {
    u8 v1[0x18];

    MI_CpuFill8(v1, 0, 0x18);
    MI_CpuCopy8(&data_0217aa08->mUnk_00->mPlayerName, v1, 0x14);
    if (a != NULL) {
        *data_0217aa00->mUnk_0024 = *a;
    }
    if (b == NULL) {
        v1[0x14] = 0;
        if (*(u16 *) 0x027ffc40 == 2) {
            v1[0x14] = v1[0x14] | 1;
        }
    } else {
        MI_CpuCopy8(b, v1, 0x18);
    }
    data_0217aa00->mUnk_000c = 10;
    data_0217aa00->mRequestPending = 1;
    if (WM_StartConnectEx(StartConnectCallback, (u16 *) data_0217aa00->mUnk_0024, v1, 1, 0) != 2) {
        func_020533a0();
        return;
    }
    data_0217aa00->mUnk_0448 = c;
    data_0217aa00->mUnk_044c = d;
    data_0217aa00->mUnk_0450 = e;
}

void StartConnectCallback(Unk021425e8 *event) {
    BOOL shouldReset;
    u16 v;
    RandomState64 *randomState;

    shouldReset = FALSE;
    switch (event->mResultCode) {
        case 0:
            switch (event->mUnk_08_0) {
                case 7:
                    data_0217aa00->mOwnIndex = event->mUnk_08_2;
                    data_0217aa00->mUnk_043a = shouldReset;
                    v = shouldReset;
                    switch (func_02051658_inline()) {
                        case 1:
                            v = data_0217aa00->mParentParameter->mUnk_0c;
                            break;
                        case 2:
                            v = data_0217aa00->mUnk_0024->mUnk_48;
                            break;
                    }
                    randomState = &data_0217aa00->mUnk_1ee8;
                    randomState->mValue = (u32) (v * 3 | v << 16);
                    randomState->mMultiplier = 0x5d588b656c078965;
                    randomState->mIncrement = 0x269ec3;
                    if (data_0217aa00->mUnk_0448 != 0) {
                        data_0217aa00->mUnk_0448();
                    }
                    data_0217aa00->mRequestPending = 0;
                    break;
                case 9:
                    if (*(u16 *) 0x027ffc40 == 2) {
                        shouldReset = TRUE;
                    } else if (data_0217aa00->mUnk_0450 != 0) {
                        data_0217aa00->mUnk_0450();
                    } else {
                        switch (data_0217aa00->mUnk_0004) {
                            case 2:
                            case 3:
                            case 4:
                            case 5:
                            case 6:
                                func_020533a0();
                                break;
                            case 0xa:
                                shouldReset = TRUE;
                                break;
                            case 0xb:
                            case 0xc:
                                break;
                            default:
                                shouldReset = TRUE;
                                break;
                        }
                    }
                    break;
                case 6:
                case 8:
                    break;
                default:
                    shouldReset = TRUE;
                    break;
            }
            break;
        case 1:
        case 0xb:
        case 0xc:
            if (data_0217aa00->mUnk_044c == 0) {
                shouldReset = TRUE;
            } else {
                data_0217aa00->mUnk_044c();
                data_0217aa00->mRequestPending = 0;
            }
            break;
        default:
            shouldReset = TRUE;
            break;
    }
    if (shouldReset == FALSE) {
        return;
    }
    ResetConnectionData();
    data_0217aa00->mUnk_0008 = 0;
    data_0217aa00->mRequestPending = 0;
}

void StartMP(void) {
    data_0217aa00->mUnk_000c = 0xb;
    data_0217aa00->mRequestPending = 1;
    if (WM_StartMPEx(StartMPCallback, data_0217aa00->mUnk_003c, data_0217aa00->mUnk_0038, data_0217aa00->mUnk_0034,
                     data_0217aa00->mUnk_0030, 1, 0, 0, 0, 0, 0) == 2) {
        return;
    }
    data_0217aa00->mUnk_0008 = 2;
    data_0217aa00->mRequestPending = 0;
}

void StartMPCallback(Unk021425e8 *event) {
    switch (event->mResultCode) {
        case 0:
            switch (event->mUnk_04) {
                case 0xa:
                    data_0217aa00->mUnk_0454 |= 1;
                    data_0217aa00->mUnk_1d54 = 0;
                    data_0217aa00->mRequestPending = 0;
                    break;
                case 0xb:
                case 0xc:
                    break;
            }
            break;
        case 9:
        case 0xd:
        case 0xf:
            break;
        default:
            data_0217aa00->mUnk_0454 |= 1;
            data_0217aa00->mUnk_0008 = 2;
            data_0217aa00->mRequestPending = 0;
            break;
    }
}

void SetMPFrequency(u32 mpFreq) {
    s32 result;

    data_0217aa00->mUnk_000c = 0xc;
    data_0217aa00->mRequestPending = 1;
    result = WM_SetMPFrequency(SetMPFrequencyCallback, mpFreq);
    if (result == 0) {
        data_0217aa00->mRequestPending = 0;
        return;
    }
    if (result == 2) {
        return;
    }
    data_0217aa00->mUnk_0008 = 2;
    data_0217aa00->mRequestPending = 0;
}

void SetMPFrequencyCallback(Unk021425e8 *event) {
    data_0217aa00->mRequestPending = 0;
    if (event->mResultCode != 0) {
        data_0217aa00->mUnk_0008 = 2;
        data_0217aa00->mRequestPending = 0;
    }
}

void SetEntry(s32 enabled) {
    s32 result;

    if ((data_0217aa00->mParentParameter->mUnk_0e != 0) == enabled) {
        return;
    }
    data_0217aa00->mUnk_000c = 0xd;
    data_0217aa00->mRequestPending = 1;
    result = WM_SetEntry(SetEntryCallback, enabled);
    if (result == 2) {
        return;
    }
    func_020533a0();
}

void SetEntryCallback(Unk021425e8 *event) {
    data_0217aa00->mRequestPending = 0;
    if (event->mResultCode == 0) {
        return;
    }
    func_020533a0();
}

void StartDataSharing(void) {
    s32 result;

    data_0217aa00->mUnk_000c = 0xe;
    data_0217aa00->mRequestPending = 1;
    result = WM_StartDataSharing(data_0217aa00->mUnk_15bc, 0xc, 0xff, 8, 1);
    data_0217aa00->mRequestPending = 0;
    if (result != 0) {
        data_0217aa00->mUnk_0008 = 2;
        data_0217aa00->mRequestPending = 0;
        return;
    }
    ResetDataSharing(&data_0217aa00->mUnk_15bc_view);
}

void SetGameInfo(void) {
    ChildList *children;
    BOOL r;
    u8 f;

    if (func_02051658_inline() != 1) {
        return;
    }
    data_0217aa00->mUnk_000c = 0xf;
    data_0217aa00->mRequestPending = 1;
    children = &data_0217aa00->mUnk_0044;
    children->mUnk_38->mUnk_0e.mUnk_06_0 = children->mChildCount;
    r = TRUE;
    if (data_0217aa00->mUnk_0004 != 8 && data_0217aa00->mUnk_0004 != 9) {
        r = FALSE;
    }
    if (WM_SetGameInfo((Unk021425e8Func) ClearRequestPending, children->mUnk_38, 0x1c, 0x25,
                       data_0217aa00->mParentParameter->mUnk_0c, r == FALSE) != 2) {
        data_0217aa00->mRequestPending = 0;
    }
}
