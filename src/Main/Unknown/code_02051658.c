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
    Unk0217aa00 *p;
    Unk0217aa00_ac *s;
    Unk02143a78 *q;
    u16 v1;
    s32 i;
    u16 m;

    p = data_0217aa00;
    s = &p->mUnk_00ac_view;
    v1 = s->mUnk_38d;
    q = p->mUnk_001c;
    p->mUnk_0000 = 2;
    data_0217aa00->mUnk_000c = 7;
    data_0217aa00->mRequestPending = 1;
    m = WM_GetAllowedChannel();
    if (m == 0) {
        data_0217aa00->mRequestPending = 0;
        data_0217aa00->mUnk_0008 = 3;
        data_0217aa00->mRequestPending = 0;
        return;
    }
    if (m == 0x8000) {
        data_0217aa00->mRequestPending = 0;
        data_0217aa00->mUnk_0008 = 8;
        data_0217aa00->mRequestPending = 0;
        return;
    }
    if (s->mUnk_38c == 0) {
        if (((1 << (v1 - 1)) & m) == 0) {
            do {
                v1 = v1 + 1;
                if (v1 > 0xe) {
                    v1 = 1;
                }
            } while (((1 << (v1 - 1)) & m) == 0);
        }
        q->mUnk_04 = v1;
        s->mUnk_38d = v1;
        for (i = 0; i < 6; i++) {
            q->mUnk_08[i] = 0xff;
        }
    } else {
        q->mUnk_08[0] = s->mUnk_380[0];
        q->mUnk_08[1] = s->mUnk_380[1];
        q->mUnk_08[2] = s->mUnk_380[2];
        q->mUnk_08[3] = s->mUnk_380[3];
        q->mUnk_08[4] = s->mUnk_380[4];
        q->mUnk_08[5] = s->mUnk_380[5];
        s->mUnk_38c = s->mUnk_38c - 1;
    }
    q->mUnk_06 = WM_GetDispersionScanPeriod();
    if (WM_StartScan(StartScanCallback, q) != 2) {
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

void func_020525a8(Unk0217aa00_0ac *a, Unk0217aa00_24 *b, Unk0217aa00_42c *c, Unk0217aa00_24_50 *d, u8 e) {
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
        MI_CpuCopy8(b, a, 0xc0);
        a->mUnk_c0_42c = *c;
        a->mUnk_dc_0 = 1;
        a->mUnk_db = 0;
        if (n0 >= 0) {
            a->mUnk_da = n0;
        }
        a->mUnk_dc_1 = n1;
        a->mUnk_dc_5 = 0;
        a->mUnk_dc_6 = k;
        MI_CpuCopy8(d, a->mUnk_c6, 0x14);
        func_0204ec28(e, d);
    } else {
        s32 m0;
        u8 m1;

        if (data_0217aa00->mUnk_1d00 == 2) {
            return;
        }
        m1 = d->mUnk_0e.mUnk_06_4;
        m0 = d->mUnk_0e.mUnk_06_0;
        MI_CpuCopy8(b, a, 0xc0);
        a->mUnk_c0_42c = *c;
        a->mUnk_dc_0 = 1;
        a->mUnk_db = 0;
        if (m0 >= 0) {
            a->mUnk_da = m0;
        }
        a->mUnk_dc_1 = m1;
        a->mUnk_dc_5 = 0;
        a->mUnk_dc_6 = k;
        MI_CpuCopy8(d, a->mUnk_c6, 0x14);
    }
}

void func_02052288(Unk0217aa00_24 *a, Unk0217aa00_42c *b, Unk0217aa00_24_50 *c) {
    Unk0217aa00_24_50_0e_36 *x;
    s32 i;
    s32 n;
    Unk0217aa00_ac *s;
    Unk0217aa00_0ac *f;
    Unk0217aa00_0ac *g;
    Unk0217aa00 *p;
    BOOL k;
    Unk0217aa00_0ac *e;
    Unk0217aa00_24_50_0e *u;
    Unk0217aa00_24_50 *t;
    s8 v;

    p = data_0217aa00;
    f = NULL;
    g = p->mUnk_00ac;
    n = 0;
    k = FALSE;
    for (i = 0, e = g; i < 4; i++, e++) {
        if (e->mUnk_dc_0 != 0 && b->mUnk_00[0] == e->mUnk_c0[0] && b->mUnk_00[1] == e->mUnk_c0[1] &&
            b->mUnk_00[2] == e->mUnk_c0[2] && b->mUnk_00[3] == e->mUnk_c0[3] && b->mUnk_00[4] == e->mUnk_c0[4] &&
            b->mUnk_00[5] == e->mUnk_c0[5]) {
            f = e;
            k = TRUE;
            break;
        }
    }
    if (f == NULL) {
        for (i = 0, e = g; i < 4; i++, e++) {
            if (e->mUnk_dc_0 == 0) {
                f = e;
                break;
            }
        }
    }
    if (f == NULL) {
        for (i = 0; i < 4; i++) {
            if (g->mUnk_db < 5) {
                if (g->mUnk_db > n) {
                    n = g->mUnk_db;
                    f = g;
                }
            }
            g++;
        }
    }
    if (f == NULL) {
        return;
    }
    if ((a->mUnk_4b & 2) != 0) {
        if (p->mUnk_1d00 != 2) {
            t = &a->mUnk_50;
            if (t->mUnk_07 == 5) {
                u = (void *) &t->mUnk_0e;
                x = &u->mUnk_36;
                v = -(k != FALSE);
                MI_CpuCopy8(a, f, 0xc0);
                f->mUnk_c0_42c = *b;
                f->mUnk_dc_0 = 1;
                f->mUnk_db = 0;
                if (v >= 0) {
                    f->mUnk_da = v;
                }
                f->mUnk_dc_1 = 0;
                f->mUnk_dc_5 = 1;
                f->mUnk_dc_6 = 0;
                MI_CpuCopy8(x->mUnk_02, f->mUnk_c6, 0x14);
                data_0217aa00->mUnk_0438 = 0;
            } else if (t->mUnk_07 == 9) {
                if (f->mUnk_dc_0 != 0) {
                    f->mUnk_da = t->mUnk_0a - 1;
                }
            } else if (f->mUnk_dc_0 != 0) {
                f->mUnk_db = 0;
            } else {
                p = data_0217aa00;
                *(Unk0217aa00_42c *) &p->mUnk_042c = *b;
                p->mUnk_0438 = 0xf;
            }
        }
    } else if (a->mUnk_4a == 0x1c) {
        func_020525a8(f, a, b, c, i);
    }
    s = &data_0217aa00->mUnk_00ac_view;
    s->mUnk_388 = 0;
    for (i = 0, e = s->mUnk_000; i < 4; i++, e++) {
        if (e->mUnk_dc_0 != 0) {
            s->mUnk_388 += 1;
        }
    }
}

void StartScanCallback(Unk021425e8 *a) {
    Unk0217aa00_24 v1;
    Unk0217aa00_42c m;
    s32 i;
    Unk0217aa00 *p;
    s32 j;
    Unk0217aa00_0ac *q;
    Unk0217aa00_ac *s;
    u16 v;
    BOOL k;
    Unk0217aa00_0ac *e;

    if (data_0217aa00->mUnk_000c != 7) {
        return;
    }
    if (a->mResultCode == 0) {
        switch (a->mUnk_08_0) {
            case 5:
                DC_InvalidateRange(data_0217aa00->mUnk_0028, 0xc0);
                MI_CpuCopy8(data_0217aa00->mUnk_0028, &v1, 0xc0);
                DC_StoreRange(&v1, 0xc0);
                if (data_0217aa00->mUnk_0004 == 0xd) {
                    v = a->mUnk_12;
                    if (func_020204c0(&v1) != 0) {
                        data_0217aa00->mUnk_1ed0 = 1;
                        data_0217aa00->mUnk_1ed4 = v;
                        data_0217aa00->mUnk_1ed6 = 0;
                    } else if (v1.mUnk_3c >= 8 && v1.mUnk_44 == 0x25 && (v1.mUnk_4b & 1) != 0) {
                        if ((v1.mUnk_4b & 2) != 0) {
                            data_0217aa00->mUnk_1ed8 = 2;
                        } else {
                            data_0217aa00->mUnk_1ed8 = 3;
                        }
                        data_0217aa00->mUnk_1edc = v;
                        data_0217aa00->mUnk_1ede = 0;
                    }
                } else {
                    k = TRUE;
                    if (v1.mUnk_3c < 8 || v1.mUnk_44 != 0x25 || (v1.mUnk_4b & 1) == 0) {
                        k = FALSE;
                    } else if (data_0217aa00->mUnk_0444 != 0) {
                        if (data_0217aa00->mUnk_0444(&v1) == 0) {
                            k = FALSE;
                        }
                    }
                    if (k != FALSE) {
                        if (data_0217aa00->mUnk_0440 != 0) {
                            data_0217aa00->mUnk_0440(a, &v1);
                        } else if ((data_0217aa00->mUnk_0436 & 1) != 0) {
                            if ((v1.mUnk_48 & 0x8000) != 0) {
                                m.mUnk_00[0] = a->mUnk_0a[0];
                                m.mUnk_00[1] = a->mUnk_0a[1];
                                m.mUnk_00[2] = a->mUnk_0a[2];
                                m.mUnk_00[3] = a->mUnk_0a[3];
                                m.mUnk_00[4] = a->mUnk_0a[4];
                                m.mUnk_00[5] = a->mUnk_0a[5];
                                func_02052288(&v1, &m, &v1.mUnk_50);
                                *data_0217aa00->mUnk_0024 = v1;
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
        p = data_0217aa00;
        if ((p->mUnk_0436 & 1) != 0 && p->mUnk_0004 != 0xd) {
            for (i = 0, e = p->mUnk_00ac; i < 4; i++, e++) {
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

void EndScanCallback(Unk021425e8 *a) {
    data_0217aa00->mRequestPending = 0;
    if (a->mResultCode == 0) {
        return;
    }
    func_020533a0();
}

void StartConnect(Unk0217aa00_24 *a, void *b, s32 (*c)(), s32 (*d)(), s32 (*e)()) {
    u8 v1[0x18];

    MI_CpuFill8(v1, 0, 0x18);
    MI_CpuCopy8(&data_0217aa08->mUnk_00->mUnk_0c, v1, 0x14);
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

void StartConnectCallback(Unk021425e8 *a) {
    BOOL r;
    u16 v;
    RandomState64 *p;

    r = FALSE;
    switch (a->mResultCode) {
        case 0:
            switch (a->mUnk_08_0) {
                case 7:
                    data_0217aa00->mOwnIndex = a->mUnk_08_2;
                    data_0217aa00->mUnk_043a = r;
                    v = r;
                    switch (func_02051658_inline()) {
                        case 1:
                            v = data_0217aa00->mParentParameter->mUnk_0c;
                            break;
                        case 2:
                            v = data_0217aa00->mUnk_0024->mUnk_48;
                            break;
                    }
                    p = &data_0217aa00->mUnk_1ee8;
                    p->mValue = (u32) (v * 3 | v << 16);
                    p->mMultiplier = 0x5d588b656c078965;
                    p->mIncrement = 0x269ec3;
                    if (data_0217aa00->mUnk_0448 != 0) {
                        data_0217aa00->mUnk_0448();
                    }
                    data_0217aa00->mRequestPending = 0;
                    break;
                case 9:
                    if (*(u16 *) 0x027ffc40 == 2) {
                        r = TRUE;
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
                                r = TRUE;
                                break;
                            case 0xb:
                            case 0xc:
                                break;
                            default:
                                r = TRUE;
                                break;
                        }
                    }
                    break;
                case 6:
                case 8:
                    break;
                default:
                    r = TRUE;
                    break;
            }
            break;
        case 1:
        case 0xb:
        case 0xc:
            if (data_0217aa00->mUnk_044c == 0) {
                r = TRUE;
            } else {
                data_0217aa00->mUnk_044c();
                data_0217aa00->mRequestPending = 0;
            }
            break;
        default:
            r = TRUE;
            break;
    }
    if (r == FALSE) {
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

void StartMPCallback(Unk021425e8 *a) {
    switch (a->mResultCode) {
        case 0:
            switch (a->mUnk_04) {
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

void SetMPFrequency(u32 a) {
    s32 r;

    data_0217aa00->mUnk_000c = 0xc;
    data_0217aa00->mRequestPending = 1;
    r = WM_SetMPFrequency(SetMPFrequencyCallback, a);
    if (r == 0) {
        data_0217aa00->mRequestPending = 0;
        return;
    }
    if (r == 2) {
        return;
    }
    data_0217aa00->mUnk_0008 = 2;
    data_0217aa00->mRequestPending = 0;
}

void SetMPFrequencyCallback(Unk021425e8 *a) {
    data_0217aa00->mRequestPending = 0;
    if (a->mResultCode != 0) {
        data_0217aa00->mUnk_0008 = 2;
        data_0217aa00->mRequestPending = 0;
    }
}

void SetEntry(s32 a) {
    s32 r;

    if ((data_0217aa00->mParentParameter->mUnk_0e != 0) == a) {
        return;
    }
    data_0217aa00->mUnk_000c = 0xd;
    data_0217aa00->mRequestPending = 1;
    r = WM_SetEntry(SetEntryCallback, a);
    if (r == 2) {
        return;
    }
    func_020533a0();
}

void SetEntryCallback(Unk021425e8 *a) {
    data_0217aa00->mRequestPending = 0;
    if (a->mResultCode == 0) {
        return;
    }
    func_020533a0();
}

void StartDataSharing(void) {
    s32 r;

    data_0217aa00->mUnk_000c = 0xe;
    data_0217aa00->mRequestPending = 1;
    r = WM_StartDataSharing(data_0217aa00->mUnk_15bc, 0xc, 0xff, 8, 1);
    data_0217aa00->mRequestPending = 0;
    if (r != 0) {
        data_0217aa00->mUnk_0008 = 2;
        data_0217aa00->mRequestPending = 0;
        return;
    }
    ResetDataSharing(&data_0217aa00->mUnk_15bc_view);
}

void SetGameInfo(void) {
    Unk0217aa00_44 *p;
    BOOL r;
    u8 f;

    if (func_02051658_inline() != 1) {
        return;
    }
    data_0217aa00->mUnk_000c = 0xf;
    data_0217aa00->mRequestPending = 1;
    p = &data_0217aa00->mUnk_0044;
    p->mUnk_38->mUnk_0e.mUnk_06_0 = p->mChildCount;
    r = TRUE;
    if (data_0217aa00->mUnk_0004 != 8 && data_0217aa00->mUnk_0004 != 9) {
        r = FALSE;
    }
    if (WM_SetGameInfo((Unk021425e8Func) ClearRequestPending, p->mUnk_38, 0x1c, 0x25,
                       data_0217aa00->mParentParameter->mUnk_0c, r == FALSE) != 2) {
        data_0217aa00->mRequestPending = 0;
    }
}
