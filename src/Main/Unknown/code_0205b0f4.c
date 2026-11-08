#include "Main/Unknown/code_0205b0f4.h"

#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/code_0205afa8.h"
#include "Main/Unknown/code_0205b000.h"
#include "Main/Unknown/code_0205a000.h"
#include "Main/Unknown/code_0205c000.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_021201e4.h"
#include "Main/Unknown/code_0205a908.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_0219b580.h"
#include "00/code_021832d8.h"
#include "01/code_021956dc.h"
#include "code_0200f5ac.h"
#include "code_0202056c.h"
#include "code_021458c4.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_0203d568.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_020b2e34.h"
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
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0211ff74.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_02061654.h"
#include "code_0200eddc.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0205a548.h"
#include "Main/Unknown/code_0205a92c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/code_0203c25c.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_0203c8dc.h"

void ResetParticipantKartMap(void) {
    s32 index;

    for (index = 0; index < 4; index++) {
        gParticipantKartMap->mParticipantOfKart[index] = -1;
        gParticipantKartMap->mKartOfParticipant[index] = -1;
    }
    gParticipantKartMap->mUnk_05 = 0;
}

void SetParticipantKartMapFromMask(u32 participantMask) {
    u8 participant;
    u8 kart;

    for (participant = 0, kart = 0; participant < 4; participant++) {
        gParticipantKartMap->mKartOfParticipant[participant] = -1;
        if ((participantMask & (1 << participant)) != 0) {
            gParticipantKartMap->mParticipantOfKart[kart] = participant;
            gParticipantKartMap->mKartOfParticipant[participant] = kart;
            kart++;
        }
    }
    gParticipantKartMap->mUnk_04 = participantMask;
    while (kart < 4) {
        gParticipantKartMap->mParticipantOfKart[kart] = -1;
        kart++;
    }
}

static inline BOOL func_0205c98c_inline(void) {
    u8 participant;
    Unk0217aa14 *p;
    Unk0217aa14_754_04 *q;

    p = data_0217aa14;
    q = &p->mUnk_754->mUnk_04;
    for (participant = 0; participant < 4; participant++) {
        if (p->mUnk_014[participant].mUnk_30 != FALSE) {
            MI_CpuCopy8(&p->mUnk_014[participant], q, 0x28);
            *(u64 *) &q->mUnk_0c[2] = OS_GetTick();
            if (func_0205c340(participant, 0, 0x28) != 0) {
                data_0217aa14->mUnk_014[participant].mUnk_30 = FALSE;
            } else {
                MI_CpuFill8(q, 0, 0x28);
            }
            return TRUE;
        }
    }
    return FALSE;
}

void func_0205cd24(void *heap) {
    s32 i;
    s32 j;
    u8 k;
    s32 n;
    u8 m;
    Unk0217aa14 *p;

    if (gRaceSetup->mMode != 5) {
        return;
    }
    data_0217aa14 = HeapAlloc(heap, 0x760);
    data_0217aa14->mUnk_754 = HeapAllocAligned(heap, 0x6c, 0x20);
    for (i = 0; i < 16; i++) {
        data_0217aa14->mUnk_324[i].mData = HeapAllocAligned(heap, 20, 32);
        for (j = 0; j < 4; j++) {
            data_0217aa14->mUnk_3e4[i][j].mData = HeapAllocAligned(heap, 20, 32);
        }
    }
    data_0217aa14->mUnk_0fc = gParticipantKartMap->mUnk_04;
    MI_CpuFill8(data_0217aa14->mUnk_754, 0, 0x6c);
    for (n = 0; n < 4; n++) {
        MI_CpuFill8(&data_0217aa14->mUnk_104[n], 0, 0x68);
        data_0217aa14->mUnk_104[n].mUnk_86_0 = 0;
    }
    k = data_0217aa14->mUnk_0fc;
    data_0217aa14->mUnk_748 = 0;
    data_0217aa14->mUnk_749 = k;
    for (k = 0; k < 4; k++) {
        data_0217aa14->mUnk_74a[k] = 0;
        data_0217aa14->mUnk_740[k] = 0;
    }
    ResetItemDataSlots();
    func_0205a6b4();
    data_0217aa14->mUnk_75c |= 1;
    data_0217aa14->mUnk_75c |= 0x40;
    p = data_0217aa14;
    p->mUnk_010 = 0;
    p->mUnk_012 = 1;
    data_0217aa14->mUnk_758 = 0;
    for (m = 0; m < 4; m++) {
        j = gParticipantKartMap->mKartOfParticipant[m];
        data_0217aa14->mUnk_104[m].mUnk_80 = 0;
        if (j >= 0) {
            data_0217aa14->mUnk_104[m].mRank = GetKartStartRank((u8) j);
        } else {
            data_0217aa14->mUnk_104[m].mRank = 0;
        }
    }
    InitStateMachine(data_0217aa14, data_02165388, 6, NULL);
}

void func_0205ccec(void) {
    Unk0217aa14 *p;

    p = data_0217aa14;
    if (p == NULL) {
        return;
    }
    switch (p->mUnk_00e) {
        case 4:
        case 5:
            p->mUnk_728++;
            break;
    }
}

void func_0205cbe4(void) {
    u8 participant;
    s32 *e;
    Unk0217aa14 *b;

    for (participant = 0; participant < 4; participant++) {
        e = &data_0217aa14->mUnk_014[participant].mUnk_04;
        e[0] = 0;
        e[1] = 0;
        e[2] = 0;
        e[3] = 0;
        e[4] = 0;
        e[5] = 0;
        e[6] = 0;
        e[7] = 0;
        e[8] = 0;
        b = data_0217aa14;
        b->mUnk_014[participant].mUnk_28 = 0;
        b->mUnk_014[participant].mUnk_2c = 0;
        b->mUnk_014[participant].mUnk_34 = 0;
        data_0217aa14->mUnk_014[participant].mUnk_35 = 0;
        data_0217aa14->mUnk_014[participant].mUnk_36 = 0;
    }
    data_0217aa14->mUnk_0f8 = 0;
    data_0217aa14->mUnk_0fb = 0;
    data_0217aa14->mUnk_0fd = 0;
    data_0217aa14->mUnk_0f4 = 0;
    data_0217aa14->mUnk_736 = 0x7f;
    data_0217aa14->mUnk_758 = 1;
    data_0217aa14->mUnk_75c &= ~2;
    data_0217aa14->mUnk_75c |= 0x80;
    data_0217aa14->mUnk_75c &= ~0x10;
}

void func_0205c98c(void) {
    u16 participant;
    u8 mask;
    u16 k;
    u8 b;
    Unk0217aa14 *p;
    Unk0217aa14_754_04 *q;
    Unk0217aa14_754 *r;

    mask = 0;
    for (participant = 0; participant < 4; participant++) {
        if (participant == func_ov000_0219bb50() || data_0217aa14->mUnk_014[participant].mUnk_34 >= 12) {
            mask = mask | (1 << participant);
        }
    }
    p = data_0217aa14;
    if (p->mUnk_749 == (p->mUnk_749 & mask)) {
        p->mUnk_0fb = mask;
        p = data_0217aa14;
        p->mUnk_010 = 2;
        p->mUnk_012 = 1;
    }
    if (func_0205c98c_inline() != FALSE) {
        return;
    }
    p = data_0217aa14;
    k = p->mUnk_0f8;
    if (k < 4) {
        b = k;
        if ((p->mUnk_749 & (1 << b)) != 0 && b != func_ov000_0219bb50()) {
            p = data_0217aa14;
            if (p->mUnk_014[b].mUnk_34 < 12) {
                r = p->mUnk_754;
                q = &r->mUnk_04;
                r->mUnk_04.mUnk_00_h = func_ov000_0219bb50();
                *(u64 *) &q->mUnk_04 = OS_GetTick();
                q->mUnk_0c[0] = 0;
                q->mUnk_0c[1] = 0;
                q->mUnk_0c[2] = 0;
                q->mUnk_0c[3] = 0;
                q->mUnk_0c[4] = 0;
                *(u32 *) &q->mUnk_20[0] = 0;
                func_0205c340(b, 0, 0x28);
            } else {
                if (p->mUnk_014[b].mUnk_36 == 0) {
                    func_0205c340(b, 5, 0);
                }
                data_0217aa14->mUnk_014[b].mUnk_36++;
                if (data_0217aa14->mUnk_014[b].mUnk_36 > 4) {
                    data_0217aa14->mUnk_014[b].mUnk_36 = 0;
                }
            }
        }
        data_0217aa14->mUnk_0f8++;
    } else {
        p->mUnk_0f8 = 0;
    }
}

void func_0205c898(void) {
    s32 participant;
    Unk0217aa14 *p;
    u8 n;
    u64 x;

    data_0217aa14->mUnk_0fa = 1 << func_ov000_0219bb50();
    data_0217aa14->mUnk_736 = 0x7f;
    data_0217aa14->mUnk_0f8 = 0;
    for (participant = 0; participant < 4; participant++) {
        p = data_0217aa14;
        n = p->mUnk_014[participant].mUnk_34;
        x = *(u64 *) &p->mUnk_014[participant].mUnk_28;
        if (n == 0) {
            p->mUnk_104[participant].mUnk_84 = 0;
        } else {
            p->mUnk_104[participant].mUnk_84 = (x / n * 64 / 0x82ea + 32) / 33;
        }
    }
}

void func_0205c800(u16 a, void (*callback)(u32)) {
    u16 i;
    s32 nextParticipant;
    u16 participant;

    nextParticipant = -1;
    for (i = 1; i <= 4; i++) {
        participant = a + i;
        if (participant >= 4) {
            participant = participant - 4;
        }
        if (participant != func_ov000_0219bb50() && (data_0217aa14->mUnk_749 & (1 << (u8) participant)) != 0) {
            nextParticipant = participant;
            break;
        }
    }
    if (nextParticipant == -1) {
        return;
    }
    callback(nextParticipant);
}

void func_0205c7a0(u32 participant) {
    u8 index;
    if (participant == 0xffffffff) {
        return;
    }
    index = participant;
    if (data_0217aa14->mUnk_749 & (1 << index)) {
        if (func_0205c340(index, 1, 8) != 0) {
            data_0217aa14->mUnk_0f8 = index;
        }
    }
}

void func_0205c6b0(void) {
    Unk0217aa14 *p;
    u8 participant;
    Unk0217aa14_754_04 *q;

    p = data_0217aa14;
    q = &p->mUnk_754->mUnk_04;
    for (participant = 0; participant < 4; participant++) {
        if (p->mUnk_014[participant].mUnk_30 != FALSE) {
            MI_CpuCopy8(&p->mUnk_014[participant], q, 0x28);
            *(u64 *) &q->mUnk_0c[2] = OS_GetTick();
            if (func_0205c340(participant, 0, 0x28) != 0) {
                data_0217aa14->mUnk_014[participant].mUnk_30 = FALSE;
            } else {
                MI_CpuFill8(q, 0, 0x28);
            }
            break;
        }
    }
    p = data_0217aa14;
    if (p->mUnk_749 == (p->mUnk_749 & p->mUnk_0fa)) {
        p->mUnk_010 = 3;
        p->mUnk_012 = 1;
        return;
    }
    func_0205c800(p->mUnk_0f8, func_0205c7a0);
}

void func_0205c684(void) {
    data_0217aa14->mUnk_736 = 0xf0;
    data_0217aa14->mUnk_734 = 0;
}

void func_0205c610(u32 participant) {
    Unk0217aa14_754 *q;
    Unk0217aa14_754_04 *r;

    q = data_0217aa14->mUnk_754;
    r = &q->mUnk_04;
    r->mUnk_00_h = data_0217aa14->mUnk_736 - data_0217aa14->mUnk_104[participant].mUnk_84;
    r->mUnk_04_b[0] = data_0217aa14->mUnk_0fb;
    if (func_0205c340(participant, 2, 8) != 0) {
        data_0217aa14->mUnk_734 = participant;
    }
}

void func_0205c594(void) {
    Unk0217aa14 *p;

    data_0217aa14->mUnk_736 = data_0217aa14->mUnk_736 - 1;
    if (data_0217aa14->mUnk_736 <= 0) {
        data_0217aa14->mUnk_736 = -1;
        p = data_0217aa14;
        p->mUnk_010 = 4;
        p->mUnk_012 = 1;
        return;
    }
    func_0205c800(data_0217aa14->mUnk_734, func_0205c610);
}

void func_0205c470(void) {
    u8 participant;

    data_0217aa14->mUnk_75c = data_0217aa14->mUnk_75c | 2;
    data_0217aa14->mUnk_75c = data_0217aa14->mUnk_75c & ~0x20;
    data_0217aa14->mUnk_75c = data_0217aa14->mUnk_75c & ~0x200;
    data_0217aa14->mUnk_728 = 0;
    data_0217aa14->mUnk_73a = 0;
    data_0217aa14->mUnk_73d = 0;
    data_0217aa14->mUnk_73b = 0;
    data_0217aa14->mUnk_73e = 0;
    data_0217aa14->mUnk_72c = FALSE;
    data_0217aa14->mUnk_738 = 0;
    data_0217aa14->mUnk_758 = 2;
    MI_CpuFill8(data_0217aa14->mUnk_754, 0, 0x6c);
    for (participant = 0; participant < 4; participant++) {
        if ((data_0217aa14->mUnk_0fc & (1 << participant)) != 0 &&
            (data_0217aa14->mUnk_749 & (1 << participant)) == 0) {
            if (gParticipantKartMap->mKartOfParticipant[participant] >= 0) {
                data_0217aa14->mUnk_104[participant].mUnk_80 =
                    (GetKartStartRank((u8) gParticipantKartMap->mKartOfParticipant[participant]) - 1) | 0x700000;
            }
        }
    }
}

int func_0205c340(u8 participant, u32 b, int dataSize) {
    Unk0205b504 *packet;
    int r;

    r = 1;
    if ((data_0217aa14->mUnk_75c & 4) != 0) {
        return 0;
    }
    if (participant != func_ov000_0219bb50()) {
        r = dataSize + 4;
        packet = (Unk0205b504 *) data_0217aa14->mUnk_754;
        data_0217aa14->mUnk_75c = data_0217aa14->mUnk_75c | 4;
        packet->mUnk_00_0 = func_ov000_0219bb50();
        packet->mUnk_00_2 = participant;
        packet->mUnk_00_4 = b;
        packet->mUnk_01 = data_0217aa14->mUnk_758;
        packet->mUnk_02_0 = data_0217aa14->mUnk_748;
        DC_StoreRange(packet, r);
        r = func_02120340(participant, packet, r, func_0211ff74);
        if (r == 0) {
            data_0217aa14->mUnk_75c = data_0217aa14->mUnk_75c & ~4;
        }
    }
    return r;
}

void func_0205c234(s32 dataSize) {
    u8 participant;
    s8 j;
    s32 sentCount;
    u8 t;

    sentCount = 0;
    t = data_0217aa14->mUnk_73a;
    if ((t & 1) == 0) {
        data_0217aa14->mUnk_73a = t + 1;
        return;
    }
    participant = t >> 1;
    j = participant - 1;
    if (j < 0) {
        j = j + 4;
    }
    while (sentCount < 1 && participant != j) {
        if (participant != func_ov000_0219bb50() && (data_0217aa14->mUnk_749 & (1 << participant)) != 0) {
            if (func_0205c340(participant, 3, dataSize) != 0) {
                participant = participant + 1;
                if (participant >= 4) {
                    participant = 0;
                }
                sentCount = sentCount + 1;
            } else {
                participant = participant + 1;
                if (participant >= 4) {
                    participant = 0;
                }
            }
        } else {
            participant = participant + 1;
            if (participant >= 4) {
                participant = 0;
            }
        }
    }
    data_0217aa14->mUnk_73a = participant << 1;
}

void func_0205be0c(void) {
    u32 a[4];
    u8 participantOrder[4];
    u8 participant;
    u8 j;
    u8 l;
    u8 n;
    s16 m;
    u32 x;
    u32 y;
    u8 k;
    u8 z;
    u32 t;
    u32 f;
    u32 g;
    u32 kart;
    u32 u;
    u32 q;
    Unk0217aa14 *d;
    u32 participantBit;
    u8 p;
    u32 c;
    u32 r;

    x = 0xf;
    for (participant = 0; participant < 4; participant++) {
        a[participant] = -1;
        participantOrder[participant] = participant;
        d = data_0217aa14;
        participantBit = 1 << participant;
        t = d->mUnk_749 & participantBit;
        if (t != 0) {
            q = 0;
            if ((d->mUnk_0fc & participantBit) != 0) {
                q = t == 0;
            }
            if (q != 0) {
                a[participant] = d->mUnk_104[participant].mUnk_80 & 0x3fffff;
            } else {
                if (participant == func_ov000_0219bb50()) {
                    f = func_0205afa8();
                    g = data_0217aa14->mUnk_73e;
                } else {
                    f = data_0217aa14->mUnk_104[participant].mUnk_04;
                    g = (u8) ((f & 0x7800000) >> 23);
                }
                x = x & g;
                if (f == 0 && IsRaceStarted() == 0) {
                    if (gParticipantKartMap->mKartOfParticipant[participant] != -1) {
                        f = (GetKartStartRank((u16) gParticipantKartMap->mKartOfParticipant[participant]) - 1) |
                            0x700000;
                    }
                }
                if (f != 0) {
                    if ((u8) ((f & 0x400000) >> 22) == 0) {
                        data_0217aa14->mUnk_73e = data_0217aa14->mUnk_73e | participantBit;
                    }
                    data_0217aa14->mUnk_104[participant].mUnk_80 = f;
                    a[participant] = data_0217aa14->mUnk_104[participant].mUnk_80 & 0x3fffff;
                }
            }
        }
    }
    for (participant = 0; participant < 4; participant++) {
        d = data_0217aa14;
        participantBit = 1 << participant;
        kart = *(u8 *) &gParticipantKartMap->mKartOfParticipant[participant];
        u = d->mUnk_104[participant].mUnk_80;
        t = d->mUnk_749 & participantBit;
        if (t != 0) {
            q = 0;
            if ((d->mUnk_0fc & participantBit) != 0) {
                q = t == 0;
            }
            if (q == 0 && (x & participantBit) != 0 && IsKartEnded(kart) == 0) {
                func_0203e4c4(kart, (u & 0x7ffff) != 0x7ffff);
            }
        }
    }
    for (l = 1; l < 4; l++) {
        n = l;
        y = a[l];
        k = participantOrder[l];
        while (n != 0 && a[n - 1] > y) {
            a[n] = a[n - 1];
            participantOrder[n] = participantOrder[n - 1];
            n--;
        }
        a[n] = y;
        participantOrder[n] = k;
    }
    for (j = 0; j < 4; j++) {
        participant = participantOrder[j];
        z = 0;
        d = data_0217aa14;
        r = d->mUnk_0fc;
        if ((r & (1 << participant)) != 0) {
            if ((u8) (((u32) d->mUnk_104[participant].mUnk_80 & 0x400000) >> 22) == 0) {
                z = j + 1;
                for (m = j; m >= 0; m--) {
                    if ((u8) (((u32) d->mUnk_104[participantOrder[m]].mUnk_80 & 0x400000) >> 22) != 0) {
                        z = z - 1;
                    }
                }
            } else {
                u16 w;

                w = gParticipantKartMap->mKartOfParticipant[participant];
                c = gRaceProgress->mUnk_000[w].mUnk_50_0;
                z = c;
                for (p = 0; p < 4; p++) {
                    u32 e;

                    if ((u8) (((u32) d->mUnk_104[p].mUnk_80 & 0x400000) >> 22) == 0) {
                        e = 1;
                    } else {
                        e = 0;
                    }
                    if ((r & (1 << p)) != 0) {
                        u16 o;
                        u32 v;

                        o = gParticipantKartMap->mKartOfParticipant[p];
                        o = (u16) o;
                        v = gRaceProgress->mUnk_000[o].mUnk_50_0;
                        if (gRaceProgress->mUnk_000[o].mStatus != 4 && e != 0 && v > c) {
                            z = z + 1;
                        }
                    }
                }
            }
        }
        d->mUnk_104[participant].mRank = z;
    }
}

void func_0205bc08(void) {
    u16 recordSize;
    u32 w;
    Unk0217aa14 *p;
    Unk0217aa14_754 *q;
    Unk0217aa14_754_04 *r;

    func_0205a908();
    func_0205a350();
    p = data_0217aa14;
    q = p->mUnk_754;
    r = &q->mUnk_04;
    recordSize = 0x68 - p->mUnk_724;
    q->mUnk_04.mUnk_00_0 = p->mUnk_728;
    r->mUnk_00_b[3] = recordSize;
    if (gParticipantKartMap->mKartOfParticipant[func_ov000_0219bb50()] < 0) {
        r->mUnk_04 = 0;
    } else {
        w = func_0205afa8();
        r->mUnk_04 = w | ((data_0217aa14->mUnk_73e << 23) & 0x7800000);
    }
    func_0205c234(recordSize);
    func_0205be0c();
    if (IsKartEnded(*(u8 *) &gParticipantKartMap->mKartOfParticipant[func_ov000_0219bb50()]) == 0 &&
        (data_0217aa14->mUnk_75c & 0x200) == 0) {
        if (data_0217562a[func_020435bc()].mBits == 0) {
            data_0217aa14->mUnk_738 = data_0217aa14->mUnk_738 + 1;
            if (data_0217aa14->mUnk_738 > 0x708) {
                data_0217aa14->mUnk_75c = data_0217aa14->mUnk_75c | 0x200;
                func_021208e8(1);
            }
        } else {
            data_0217aa14->mUnk_738 = 0;
        }
    }
    if (data_0217aa14->mUnk_758 == 2) {
        switch (func_020b2e34()) {
            case 2:
            case 7:
                data_0217aa14->mUnk_758 = 4;
                p = data_0217aa14;
                p->mUnk_010 = 5;
                p->mUnk_012 = 1;
                break;
            case 9:
                data_0217aa14->mUnk_758 = 3;
                p = data_0217aa14;
                p->mUnk_010 = 5;
                p->mUnk_012 = 1;
                break;
        }
    }
}

u32 func_0205bbe8(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217aa14;
    value0 = *(const u32 *) ((value0) + (0));
    value0 = (value0) + (0x700u);
    value1 = *(const u16 *) ((value0) + (92));
    value1 = (value1) & ~(0x100u);
    *(u16 *) ((value0) + (92)) = value1;
    return value0;
}

u32 func_0205bba8(void) {
    u32 result;
    Unk0217aa14 *p;

    p = data_0217aa14;
    result = 0;
    if (p->mUnk_758 != 3) {
        if (p->mUnk_758 != 5) {
            return result;
        }
        if ((p->mUnk_75c & 0x100) != 0) {
            result = 2;
        }
        return result;
    }
    return 9;
}

void func_0205ba60(void) {
    Unk0217aa14 *p;
    u8 a;
    u8 b;
    u8 participant;
    enum { K0 } v1;

    a = 0;
    b = 0;
    p = data_0217aa14;
    switch (p->mUnk_758) {
        case 3:
        case 4:
            for (participant = 0; participant < 4; participant++) {
                v1 = 1 << participant;
                if ((data_0217aa14->mUnk_749 & v1) != 0 && participant != func_ov000_0219bb50()) {
                    if (data_0217aa14->mUnk_74e[participant] != 4 && data_0217aa14->mUnk_74e[participant] != 5) {
                        a = a | v1;
                    }
                }
            }
            if (a == 0) {
                data_0217aa14->mUnk_758 = 5;
            }
            break;
        case 5:
            for (a = 0; a < 4; a++) {
                v1 = 1 << a;
                if ((p->mUnk_749 & v1) != 0 && p->mUnk_74e[a] == 5) {
                    b = b | v1;
                }
            }
            if ((p->mUnk_749 & ~b) == 0) {
                p->mUnk_75c = p->mUnk_75c | 0x100;
            }
            if ((data_0217aa14->mUnk_749 | ~b) != 0) {
                data_0217aa14->mUnk_75c = data_0217aa14->mUnk_75c | 0x100;
            }
            break;
    }
    if ((data_0217aa14->mUnk_749 & ~b) == 0) {
        data_0217aa14->mUnk_758 = 5;
    }
}

void func_0205b9a8(void) {
    u16 recordSize;
    Unk0217aa14 *p;
    Unk0217aa14_754 *q;
    Unk0217aa14_754_04 *r;
    s32 t;

    func_0205a908();
    func_0205a350();
    p = data_0217aa14;
    q = p->mUnk_754;
    r = &q->mUnk_04;
    recordSize = 0x68 - p->mUnk_724;
    q->mUnk_04.mUnk_00_0 = p->mUnk_728;
    r->mUnk_00_b[3] = recordSize;
    if (gParticipantKartMap->mKartOfParticipant[func_ov000_0219bb50()] < 0) {
        r->mUnk_04 = 0;
    } else {
        t = func_0205afa8();
        r->mUnk_04 = t | ((data_0217aa14->mUnk_73e << 23) & 0x7800000);
    }
    func_0205c234(recordSize);
    func_0205be0c();
    func_0205ba60();
}

Unk0217aa14_104 *func_0205b978(s32 participant, u32 b) {
    Unk0217aa14_104 *entry;

    entry = &data_0217aa14->mUnk_104[participant];
    if (b != entry->mUnk_00_0) {
        return NULL;
    }
    return entry;
}

s32 func_0205b954(s32 participant) {
    return data_0217aa14->mUnk_104[participant].mUnk_00_0;
}

void func_0205b824(const u64 *ticks, s32 participant) {
    u8 n;
    u64 d;
    Unk0217aa14 *p;
    BOOL f;

    p = data_0217aa14;
    n = p->mUnk_014[participant].mUnk_34;
    if (n >= 12) {
        return;
    }
    if (n != 0) {
        d = (ticks[3] - ticks[0]) - (ticks[2] - ticks[1]);
        if (d * 64 / 0x82ea < 1000) {
            *(u64 *) &p->mUnk_014[participant].mUnk_28 += d;
            f = TRUE;
        } else {
            f = FALSE;
            data_0217aa14->mUnk_014[participant].mUnk_35++;
            if (data_0217aa14->mUnk_014[participant].mUnk_35 > 0x40) {
                data_0217aa14->mUnk_748 |= 1 << participant;
            }
        }
    } else {
        f = TRUE;
    }
    if (f != FALSE) {
        n = n + 1;
    }
    data_0217aa14->mUnk_014[participant].mUnk_34 = n;
}

void func_0205b778(u32 a, Unk0205b504 *packet, u32 c) {
    Unk0217aa14 *p;
    Unk0217aa14_104 *entry;
    u8 *s;
    u32 y;
    u32 participant;
    u8 n;
    u32 x;

    participant = packet->mUnk_00_0;
    p = data_0217aa14;
    s = packet->mUnk_04.mUnk_00_b;
    y = packet->mUnk_04.mUnk_00_0;
    x = p->mUnk_104[participant].mUnk_00_0;
    entry = &p->mUnk_104[participant];
    n = s[3];
    if (p->mUnk_00e != 4 && p->mUnk_00e != 5) {
        return;
    }
    if (x != 0 && x >= y) {
        return;
    }
    if (p->mUnk_104[participant].mUnk_86_0 == 0) {
        p->mUnk_104[participant].mUnk_86_0 = 1;
    }
    MI_CpuCopy8(s, entry, n);
}

void func_0205b6bc(u32 a, Unk0205b504 *packet, u32 c) {
    s32 t;
    Unk0217aa14 *p;
    s16 x;
    s16 v;
    s16 d;
    u32 participantBit;

    x = packet->mUnk_04.mUnk_00_s;
    p = data_0217aa14;
    v = p->mUnk_736;
    if (p->mUnk_00e == 2) {
        participantBit = 1 << packet->mUnk_00_0;
        if ((p->mUnk_0fa & participantBit) == 0) {
            p->mUnk_0fa |= participantBit;
        }
        return;
    }
    if (v < 0) {
        return;
    }
    d = x - v;
    if (d > 0) {
        d = (d + 1) >> 1;
    } else if (d < 0) {
        d = (d - 1) >> 1;
    }
    t = (d << 11) + (data_0217aa14->mUnk_0f4 >> 1);
    data_0217aa14->mUnk_0f4 = t;
    data_0217aa14->mUnk_736 += (s16) ((t + 0x800) >> 12);
}

void func_0205b504(u32 a, Unk0205b504 *packet, u32 c, u32 d) {
    u32 participant;
    Unk0217aa14 *p;
    Unk0205b504_04 *m;
    Unk0217aa14_014 *e;
    u32 i;
    u64 t;
    u8 ownParticipant;

    p = data_0217aa14;
    if (p == NULL) {
        return;
    }
    participant = packet->mUnk_00_0;
    if ((p->mUnk_749 & (1 << participant)) == 0) {
        return;
    }
    p->mUnk_740[participant] = 0;
    data_0217aa14->mUnk_74a[packet->mUnk_00_0] = packet->mUnk_02_0;
    data_0217aa14->mUnk_74e[packet->mUnk_00_0] = packet->mUnk_01;
    switch (((volatile Unk0205b504 *) packet)->mUnk_00_4) {
        case 0:
            m = &packet->mUnk_04;
            i = packet->mUnk_00_0;
            ownParticipant = func_ov000_0219bb50();
            if (m->mUnk_00 == ownParticipant) {
                m->mUnk_04[3] = OS_GetTick();
                func_0205b824(m->mUnk_04, i);
                return;
            }
            if (m->mUnk_00 >= 4) {
                return;
            }
            e = &data_0217aa14->mUnk_014[i];
            MI_CpuCopy8(m, e, 0x28);
            t = OS_GetTick();
            e->mUnk_0c = t;
            e->mUnk_10 = t >> 32;
            data_0217aa14->mUnk_014[i].mUnk_30 = TRUE;
            break;
        case 1:
            data_0217aa14->mUnk_0fa = data_0217aa14->mUnk_0fa | (1 << packet->mUnk_00_0);
            break;
        case 2:
            func_0205b6bc(a, packet, c);
            break;
        case 3:
            func_0205b778(a, packet, c);
            break;
        case 4:
        case 5:
            break;
    }
}

void func_0205b32c(void) {
    s16 elos[4];
    s16 newElos[4];
    s32 eloChange;
    u8 participant;
    u8 otherParticipant;
    u8 k;
    u8 v3;
    s32 kart;
    s8 otherKart;
    u32 kartRank;
    u32 otherKartRank;
    s16 eloDifference;

    for (participant = 0; participant < 4; participant++) {
        if (gParticipantKartMap->mKartOfParticipant[participant] == -1) {
            elos[participant] = 5000;
        } else {
            elos[participant] = GetPlayerRecordElo(participant);
        }
    }
    for (participant = 0; participant < 4; participant++) {
        kart = gParticipantKartMap->mKartOfParticipant[participant];
        if (kart == -1) {
            continue;
        }
        newElos[participant] = elos[participant];
        for (otherParticipant = 0; otherParticipant < 4; otherParticipant++) {
            k = 1;
            otherKart = gParticipantKartMap->mKartOfParticipant[otherParticipant];
            if (otherKart == -1 || kart == otherKart) {
                continue;
            }
            kartRank = GetKartRank((u16) kart);
            otherKartRank = GetKartRank((u16) otherKart);
            if (kartRank > otherKartRank) {
                k = 0;
            }
            eloDifference = elos[otherParticipant] - elos[participant];
            for (v3 = 0; v3 < 9; v3++) {
                if (eloDifference > data_021548e0[v3].mUnk_00) {
                    if (k != 0) {
                        eloChange = data_021548e0[v3].mUnk_02;
                    } else {
                        eloChange = data_021548e0[v3].mUnk_03;
                    }
                    break;
                }
            }
            newElos[participant] += eloChange;
            if (newElos[participant] < 0) {
                newElos[participant] = 0;
                continue;
            }
            if (newElos[participant] > 10000) {
                newElos[participant] = 10000;
            }
        }
        SetPlayerRecordElo(participant, newElos[participant]);
    }
}

void func_0205b0f4(void) {
    u8 participant;
    u32 a;
    u32 participantBit;
    u32 v2;
    u8 t;
    u16 v;
    u32 n;
    BackupFirstBlock *q;

    for (participant = 0; participant < 4; participant++) {
        participantBit = 1 << participant;
        if ((data_0217aa14->mUnk_749 & participantBit) != 0 && participant != func_ov000_0219bb50() &&
            (data_0217aa14->mUnk_748 & participantBit) == 0) {
            v2 = 300;
            if (data_0217aa14->mUnk_014[participant].mUnk_34 == 0) {
                v2 = 600;
            }
            data_0217aa14->mUnk_740[participant]++;
            if (data_0217aa14->mUnk_740[participant] > v2) {
                data_0217aa14->mUnk_748 |= participantBit;
            }
        }
    }
    a = data_0217aa14->mUnk_748;
    for (participant = 0; participant < 4; participant++) {
        if ((data_0217aa14->mUnk_749 & (1 << participant)) != 0) {
            if (participant != func_ov000_0219bb50()) {
                if ((data_0217aa14->mUnk_748 & (1 << participant)) == 0) {
                    t = data_0217aa14->mUnk_74a[participant] | (1u << participant);
                    a = a & t;
                }
            }
        }
    }
    if (a == 0) {
        return;
    }
    for (participant = 0; participant < 4; participant++) {
        participantBit = 1 << participant;
        if ((a & participantBit) != 0 && (data_0217aa14->mUnk_749 & participantBit) != 0 &&
            gParticipantKartMap->mKartOfParticipant[participant] != -1) {
            RemoveRaceProgressKart(gParticipantKartMap->mKartOfParticipant[participant]);
            data_0217aa14->mUnk_749 = data_0217aa14->mUnk_749 & ~participantBit;
        }
    }
    if (CountSetBits(data_0217aa14->mUnk_749) > 1) {
        return;
    }
    v = gWiFiSession->mUnk_0008.mState;
    q = data_0217aa08->mFirstBlock;
    n = q->mUnk_34[5];
    if (v != 0) {
        s8 c = gWiFiSession->mKartCountCopy - 1;
        if (c > 0) {
            if (n < c) {
                n = 0;
            } else {
                n = n - c;
            }
        }
        q->mUnk_34[5] = n;
        func_02056d40();
        WaitThreadFunctionsDone();
        if (gBackupAccess->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
    }
    func_021208e8(2);
}
