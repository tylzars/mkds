#include "code_021445e0.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0201ec30.h"
#include "code_0214259c.h"
#include "code_02142eac.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214cfe4.h"
#include "code_0202056c.h"
#include "code_0214d018.h"

int WM_StartKeySharing(Unk021450ec *p, u32 n) {
    return WM_StartDataSharing(p, n, 0xffff, 2, 1);
}

int WM_EndKeySharing(Unk021450ec *p) {
    return WM_EndDataSharing(p);
}

// Fills in the object p (0x820 bytes) for n and stores ReceiveParentPortMessage (ReceiveChildPortMessage when mUnk_184
// is not 0) for it; returns 6 for bad arguments.
int WM_StartDataSharing(Unk021450ec *p, u32 n, u32 mask, u32 k, u32 flag) {
    u32 w;
    u32 u5;
    Unk02142988 *q;
    int r;
    int i;
    u16 v;
    u32 c;
    Unk0214461c *e;

    w = 1;
    q = GetWorkBuffer()->mStatusArea;
    r = GetErrorUnlessStateIsOneOf(2, 9, 10);
    if (r != 0) {
        return r;
    }
    DC_InvalidateRange(&q->mUnk_00c, 4);
    if (q->mUnk_00c == 0) {
        return 3;
    }
    if (p == 0) {
        return 6;
    }
    if (n >= 16) {
        return 6;
    }
    if (mask == 0) {
        return 6;
    }
    DC_InvalidateRange(&q->mOwnMemberIndex, 2);
    u5 = q->mOwnMemberIndex;
    if (u5 == 0) {
        DC_InvalidateRange(&q->mUnk_086, 2);
        w = q->mUnk_086;
    }
    MemFillWordsByBlock_inline(p, 0x820);
    p->mUnk_808 = 0;
    p->mUnk_80a = 0;
    p->mUnk_80c = 0;
    p->mMemberDataSize = k;
    p->mPort = n;
    p->mMemberMask = 0;
    p->mUnk_818 = flag != 0;
    v = mask | (1 << u5);
    p->mMemberMask = v;
    c = CountSetBits(v);
    p->mUnk_812 = c;
    p->mUnk_814 = k * c;
    if (p->mUnk_814 > 0x1fc) {
        p->mMemberMask = 0;
        return 6;
    }
    p->mUnk_814 += 4;
    p->mStatus = 1;
    if (u5 == 0) {
        for (i = 0; i < 4; i++) {
            p->mUnk_000[i].mUnk_00 = p->mMemberMask & (w | 1);
        }
        WM_SetPortCallback(n, (UnkFunc *) ReceiveParentPortMessage, p);
        e = p->mUnk_000;
        for (i = 0; i < (p->mUnk_818 == 1 ? 2 : 1); e++, i++) {
            p->mUnk_808 = (p->mUnk_808 + 1) & 3;
            r = WM_SetMPDataToPortEx((UnkFunc *) ReceiveBlockSendResult, p, e, p->mUnk_814, p->mMemberMask & w,
                                     p->mPort, 1);
            if (r == 7) {
                p->mUnk_800[i] = 0xffff;
                p->mUnk_80a = (p->mUnk_80a + 1) & 3;
            } else if (r != 0 && r != 2) {
                p->mStatus = 5;
                return 1;
            }
        }
    } else {
        p->mUnk_80a = 3;
        WM_SetPortCallback(n, (UnkFunc *) ReceiveChildPortMessage, p);
    }
    return 0;
}

// Clears the object p when ReceiveParentPortMessage or ReceiveChildPortMessage is stored for it; returns 3 otherwise.
int WM_EndDataSharing(Unk021450ec *p) {
    Unk02142aa8 *pp;
    UnkFunc *f;
    int r;

    pp = GetWorkBuffer();
    r = GetErrorUnlessStateIsOneOf(2, 9, 10);
    if (r != 0) {
        return r;
    }
    if (p == 0) {
        return 6;
    }
    if (p->mMemberMask == 0 || ((f = pp->mPortCallbacks[p->mPort]) != (UnkFunc *) ReceiveParentPortMessage &&
                                f != (UnkFunc *) ReceiveChildPortMessage)) {
        return 3;
    }
    WM_SetPortCallback(p->mPort, 0, 0);
    p->mMemberMask = 0;
    p->mStatus = 0;
    return 0;
}

// Returns 1 when mStatus is 5 and 3 when it is neither 1 nor 4; otherwise takes the next block into b, passes a to
// SetMemberData and returns 0.
int WM_StepDataSharing(Unk021450ec *p, void *a, Unk0214461c *b) {
    int f2;
    int r;
    Unk02142988 *q;
    u32 w;
    u32 st;
    int f1;
    u32 u5;
    int t;
    int rr;
    u16 k;
    u8 *e7;

    q = GetWorkBuffer()->mStatusArea;
    r = GetErrorUnlessStateIsOneOf(2, 9, 10);
    if (r != 0) {
        return r;
    }
    DC_InvalidateRange(&q->mUnk_00c, 4);
    if (q->mUnk_00c == 0) {
        return 3;
    }
    if (p == 0) {
        return 6;
    }
    if (a == 0) {
        return 6;
    }
    if (b == 0) {
        return 6;
    }
    DC_InvalidateRange(&q->mOwnMemberIndex, 2);
    u5 = q->mOwnMemberIndex;
    if (u5 == 0) {
        DC_InvalidateRange(&q->mUnk_086, 2);
        w = q->mUnk_086;
    }
    st = p->mStatus;
    if (st == 5) {
        return 1;
    }
    if (st != 1) {
        if (st != 4) {
            return 3;
        }
    }
    r = 5;
    if (u5 == 0) {
        f1 = 0;
        f2 = 0;
        if (st == 4) {
            p->mStatus = 1;
            k = (p->mUnk_808 + 3) & 3;
            rr = WM_SetMPDataToPortEx((UnkFunc *) ReceiveBlockSendResult, p, &p->mUnk_000[k], p->mUnk_814,
                                      p->mMemberMask & w, p->mPort, 1);
            if (rr == 7) {
                p->mUnk_800[k] = 0xffff;
                p->mUnk_80a = (p->mUnk_80a + 1) & 3;
            } else if (rr != 0) {
                if (rr != 2) {
                    p->mStatus = r;
                    return 1;
                }
            }
        }
        if (p->mUnk_80c != p->mUnk_80a) {
            p->mUnk_000[p->mUnk_80c].mUnk_00 |= 1;
            MemCopyHalfwords(&p->mUnk_000[p->mUnk_80c], b, 0x200);
            p->mUnk_81a = p->mUnk_800[p->mUnk_80c];
            p->mUnk_80c = (p->mUnk_80c + 1) & 3;
            f1 = 1;
            r = 0;
            if (p->mUnk_818 == 0 && w != 0 && p->mUnk_000[p->mUnk_808].mUnk_00 == 1) {
                f2 = f1;
            } else {
                f2 = 0;
            }
        }
        SendBlockIfComplete(p, 0);
        if (f1 != 0) {
            SetMemberData(p, 0, a);
            if (p->mUnk_818 == 0) {
                SendBlockIfComplete(p, f2);
            }
        }
    } else {
        t = 0;
        if (st == 4) {
            p->mStatus = 1;
            t = 1;
        } else if (p->mUnk_80c != p->mUnk_808) {
            if ((p->mUnk_000[p->mUnk_80c].mUnk_00 & 1) == 0) {
                p->mUnk_000[p->mUnk_80c].mUnk_00 |= 1;
            } else {
                MemCopyHalfwords(&p->mUnk_000[p->mUnk_80c], b, 0x200);
                p->mUnk_81a = p->mUnk_800[p->mUnk_80c];
                p->mUnk_80c = (p->mUnk_80c + 1) & 3;
                t = 1;
                r = 0;
            }
        }
        if (t != 0) {
            e7 = &p->mUnk_000[p->mUnk_80a].mUnk_04[0x1c];
            MemCopyHalfwords(a, e7, p->mMemberDataSize);
            rr = WM_SetMPDataToPortEx((UnkFunc *) ReceiveBlockSendResult, p, e7, p->mMemberDataSize, p->mMemberMask,
                                      p->mPort, 1);
            p->mUnk_80a = (p->mUnk_80a + 1) & 3;
            if (rr != 2) {
                if (rr != 0) {
                    p->mStatus = 5;
                    r = 1;
                }
            }
        }
    }
    return r;
}

// Passed to WM_SetMPDataToPortEx; accepts only objects that ReceiveParentPortMessage or ReceiveChildPortMessage are
// stored for and records the result in the object at mUnk_20.
void ReceiveBlockSendResult(Unk02144920 *a) {
    Unk02142aa8 *pp;
    Unk02142988 *q;
    Unk021450ec *p;
    UnkFunc *f;
    u32 x;
    u32 y;

    pp = GetWorkBuffer();
    q = pp->mStatusArea;
    f = pp->mPortCallbacks[a->mUnk_0a];
    p = pp->mPortCallbackArgs[a->mUnk_0a];
    if (f != (UnkFunc *) ReceiveParentPortMessage && f != (UnkFunc *) ReceiveChildPortMessage) {
        return;
    }
    if (p == 0) {
        return;
    }
    if (p != a->mUnk_20) {
        return;
    }
    DC_InvalidateRange(&q->mOwnMemberIndex, 2);
    x = a->mResultCode;
    y = q->mOwnMemberIndex;
    if (x == 0) {
        if (y != 0) {
            return;
        }
        p->mUnk_800[p->mUnk_80a] = a->mUnk_1a >> 1;
        p->mUnk_80a = (p->mUnk_80a + 1) & 3;
        return;
    }
    if (x == 10) {
        if (y != 0) {
            p->mUnk_80a = (p->mUnk_80a + 3) & 3;
        }
        p->mStatus = 4;
        return;
    }
    p->mStatus = 5;
}

// Function stored in mUnk_0c4 by WM_StartDataSharing; messages 7, 9 and 0x15 pass the object to SendBlockIfComplete (9
// clears bit mUnk_12 first, 0x15 calls SetMemberData).
void ReceiveParentPortMessage(Unk02144920 *a) {
    Unk021450ec *p;
    u32 s;
    enum { K0 } d;
    u32 t;
    u32 n;
    u32 m;
    u16 k;

    p = a->mUnk_1c;
    if (p == 0) {
        return;
    }
    if (a->mResultCode == 0) {
        switch (a->mUnk_04) {
            case 0x15:
                SetMemberData(p, a->mUnk_12, a->mUnk_0c);
                SendBlockIfComplete(p, 0);
                return;
            case 7:
                SendBlockIfComplete(p, 0);
                return;
            case 9:
                t = a->mUnk_12;
                d = 1;
                s = OS_DisableInterrupts();
                n = p->mUnk_808;
                m = ~(d << t);
                p->mUnk_000[n].mUnk_00 &= m;
                if (p->mUnk_818 == 1) {
                    k = (n + 1) & 3;
                    p->mUnk_000[k].mUnk_00 &= m;
                }
                OS_RestoreInterrupts(s);
                SendBlockIfComplete(p, 0);
                if (p->mUnk_818 == 1) {
                    SendBlockIfComplete(p, 0);
                }
                return;
        }
    } else {
        p->mStatus = 5;
    }
}

// Function stored in mUnk_0c4 by WM_StartDataSharing; when a->mUnk_04 is 0x15, copies mUnk_10 bytes from mUnk_0c into
// the block at mUnk_808 and advances mUnk_808.
void ReceiveChildPortMessage(Unk02144920 *a) {
    Unk02142988 *q;
    Unk021450ec *p;
    u32 n;
    u32 v;
    u32 g;
    u16 *d;

    q = GetWorkBuffer()->mStatusArea;
    p = a->mUnk_1c;
    if (p == 0) {
        return;
    }
    if (a->mResultCode == 0) {
        if (a->mUnk_04 == 7) {
            return;
        }
        if (a->mUnk_04 == 9) {
            return;
        }
        if (a->mUnk_04 != 0x15) {
            return;
        }
        d = a->mUnk_0c;
        v = *d;
        n = a->mUnk_10;
        DC_InvalidateRange(&q->mOwnMemberIndex, 2);
        g = q->mOwnMemberIndex;
        if (n != p->mUnk_814) {
            if (n > 0x200) {
                n = 0x200;
            }
        }
        if (n < 4) {
            return;
        }
        if ((v & (1 << g)) == 0) {
            return;
        }
        MemCopyHalfwords(d, &p->mUnk_000[p->mUnk_808], n);
        p->mUnk_800[p->mUnk_808] = a->mUnk_1a >> 1;
        p->mUnk_808 = (p->mUnk_808 + 1) & 3;
    } else {
        p->mStatus = 5;
    }
}

// Copies mUnk_810 bytes from src (zeros when src is 0) to the data of the block that holds bit, then moves bit from
// the first mask of that block to its second mask.
void SetMemberData(Unk021450ec *p, u32 bit, const void *src) {
    u32 m;
    u16 n;
    u32 s;
    u8 *dst;
    volatile u16 z;

    m = (u16) (1 << bit);
    if ((p->mMemberMask & m) == 0) {
        return;
    }
    n = p->mUnk_808;
    if ((m & p->mUnk_000[n].mUnk_00) == 0) {
        if (p->mUnk_818 != 1) {
            return;
        }
        n = (n + 1) & 3;
        if ((m & p->mUnk_000[n].mUnk_00) == 0) {
            return;
        }
    }
    dst = GetMemberDataInBlock(p, p->mMemberMask, p->mUnk_000[n].mUnk_04, bit);
    if (src != 0) {
        MemCopyHalfwords(src, dst, p->mMemberDataSize);
    } else {
        z = 0;
        MemFillHalfwords(z, dst, p->mMemberDataSize);
    }
    s = OS_DisableInterrupts();
    p->mUnk_000[n].mUnk_00 &= ~m;
    p->mUnk_000[n].mArrivedMembers |= m;
    OS_RestoreInterrupts(s);
}

// When the block at mUnk_808 starts with 0: advances mUnk_808, clears the block two ahead (one ahead when mUnk_818
// is not 1), then passes the block to WM_SetMPDataToPortEx.
void SendBlockIfComplete(Unk021450ec *p, u32 f) {
    u32 s;
    u16 i;
    u32 w;
    Unk02142988 *q;
    u16 n1;
    u16 n2;
    int r;
    volatile u16 z;

    q = GetWorkBuffer()->mStatusArea;
    s = OS_DisableInterrupts();
    if (p->mUnk_000[p->mUnk_808].mUnk_00 == 0) {
        DC_InvalidateRange(&q->mUnk_086, 2);
        i = p->mUnk_808;
        w = q->mUnk_086;
        n1 = (i + 1) & 3;
        if (p->mUnk_818 == 1) {
            n2 = (n1 + 1) & 3;
        } else {
            n2 = n1;
        }
        z = 0;
        MemFillHalfwords(z, &p->mUnk_000[n2], 0x200);
        p->mUnk_000[n2].mUnk_00 = p->mMemberMask & (w | 1);
        p->mUnk_808 = n1;
        p->mUnk_000[i].mUnk_00 = p->mMemberMask;
        if (f == 1) {
            p->mUnk_000[i].mUnk_00 &= ~1;
        }
        OS_RestoreInterrupts(s);
        r = WM_SetMPDataToPortEx((UnkFunc *) ReceiveBlockSendResult, p, &p->mUnk_000[i], p->mUnk_814,
                                 p->mMemberMask & w, p->mPort, 1);
        if (r == 7) {
            p->mUnk_800[i] = 0xffff;
            p->mUnk_80a = (p->mUnk_80a + 1) & 3;
        } else if (r != 0) {
            if (r != 2) {
                p->mStatus = 5;
            }
        }
    } else {
        OS_RestoreInterrupts(s);
    }
}

// Returns GetMemberDataInBlock for the data of q, or 0 when p or q is 0 or bit is not set in both masks of q.
u8 *WM_GetSharedDataAddress(Unk021450ec *p, Unk0214461c *q, u32 bit) {
    u32 m;
    u32 a;
    u32 b;

    b = q->mArrivedMembers;
    m = 1 << bit;
    a = q->mUnk_00;
    if (p == 0) {
        return 0;
    }
    if (q == 0) {
        return 0;
    }
    if ((a & m) == 0) {
        return 0;
    }
    if ((b & m) == 0) {
        return 0;
    }
    return GetMemberDataInBlock(p, a, q->mUnk_04, bit);
}

// Returns base plus mUnk_810 times the number of set bits of mask below bit.
u8 *GetMemberDataInBlock(Unk021450ec *p, u32 mask, u8 *base, u32 bit) {
    return base + p->mMemberDataSize * CountSetBits(mask & ((1 << bit) - 1));
}
