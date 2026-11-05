#include "00/code_0219a0d0.h"
#include "00/code_0218d818.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_0218d000.h"
#include "00/code_0219a61c.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_0218dd8c.h"
#include "00/code_0218e2dc.h"
#include "00/unk_021b4000.h"
#include "00/code_02197000.h"
#include "00/code_02199000.h"
#include "00/code_0219a000.h"
#include "00/code_0219903c.h"
#include "00/code_02197ddc.h"
#include "00/code_02198584.h"
#include "00/code_0219a044.h"
#include "00/code_0219a3e8.h"
#include "00/code_0219a430.h"
#include "00/code_021a3668.h"
#include "code_021382a8.h"

typedef struct Unk0219a110Addr {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk0219a110Addr;

u32 CreateConnection(Gt2Socket *a, Gt2Connection **b, u32 c, u32 d) {
    Gt2Connection *e = NULL;
    if (FindConnection(a, c, d) != NULL) {
        return 5;
    }
    e = func_ov000_0219a3e8();
    if (e != NULL) {
        memset(e, 0, 0xa0);
        e->mAddress = c;
        e->mPort = d;
        e->mSocket = a;
        e->mCreateTime = func_ov000_0218e8c4();
        e->mLastSendTime = e->mCreateTime;
        e->mUnk_64 = 0;
        e->mUnk_66 = 0;
        if (InitBuffer(&e->mUnk_44, a->mUnk_3c) != 0 && InitBuffer(&e->mSendBuffer, a->mSendBufferSize) != 0) {
            e->mUnk_5c = (void *) DarrayCreate(0x10, 0x40, NULL);
            if (e->mUnk_5c != NULL) {
                e->mUnk_60 = (void *) DarrayCreate(0x10, 0x40, NULL);
                if (e->mUnk_60 != NULL) {
                    e->mUnk_98 = (void *) DarrayCreate(4, 2, NULL);
                    if (e->mUnk_98 != NULL) {
                        e->mUnk_9c = (void *) DarrayCreate(4, 2, NULL);
                        if (e->mUnk_9c != NULL) {
                            HashtableSet(a->mConnections, &e);
                            *b = FindConnection(a, c, d);
                            if (*b != NULL) {
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    if (e != NULL) {
        func_ov000_021a3668(e->mUnk_44.mData);
        func_ov000_021a3668(e->mSendBuffer.mData);
        if (e->mUnk_5c != NULL) {
            DarrayDelete(e->mUnk_5c);
        }
        if (e->mUnk_60 != NULL) {
            DarrayDelete(e->mUnk_60);
        }
        if (e->mUnk_98 != NULL) {
            DarrayDelete(e->mUnk_98);
        }
        if (e->mUnk_9c != NULL) {
            DarrayDelete(e->mUnk_9c);
        }
        func_ov000_021a3668(e);
    }
    return 1;
}

void func_ov000_0219a220(Gt2Connection *a) {
    s32 b;
    s32 c;
    if (a->mUnk_14 == FALSE && a->mUnk_24 == 0) {
        if (a->mUnk_0c == 7) {
            b = DarrayGetCount(a->mSocket->mConnectionsToFree);
            for (c = 0; c < b; c++) {
                if (a == *(Gt2Connection **) DarrayGetElement(a->mSocket->mConnectionsToFree, c)) {
                    DarrayRemove(a->mSocket->mConnectionsToFree, c);
                    return;
                }
            }
        } else {
            HashtableRemove(a->mSocket->mConnections, &a);
        }
    }
}

u32 func_ov000_0219a110(u32 *c, u32 d, int f, u32 g, u32 h) {
    Gt2Socket *a = (Gt2Socket *) c;
    s32 e;
    func_ov000_0219a61c((const char **) &g, (s32 *) &h);
    if (func_ov000_0218e644(a->mDescriptor) == 0) {
        return 1;
    }
    {
        Unk0219a110Addr b = {0, 0, 0, 0};
        Unk0219a110Addr *p = &b;
        p->mUnk_01 = 2;
        p->mUnk_04 = d;
        p->mUnk_02 = ((f >> 8) & 0xff) | ((f << 8) & 0xff00);
        if (func_ov000_0218e3e4(a->mDescriptor, (void *) g, h, 0, &b, 8) == -1) {
            e = func_ov000_0218e368(a->mDescriptor);
            if (e == -15) {
                if (func_ov000_0219922c(a, d, f) == 0) {
                    return 0;
                }
            } else if (e == -42 || e == -6) {
                return 1;
            } else if (e != -35) {
                func_ov000_0219a044(a);
                return 0;
            }
        } else if (a->mSentCallback != NULL) {
            if (func_ov000_02197f28(a, FindConnection(a, d, f), d, f, 0, g, h, 1) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

u32 func_ov000_0219a0d0(Gt2Connection **a, u32 *b) {
    Gt2Connection *c = *a;
    u32 d = *b;
    if (c->mUnk_0c != 7 && func_ov000_02198584(c, d) == 0) {
        return 0;
    }
    if (c->mUnk_0c == 7 && c->mUnk_14 == FALSE && c->mUnk_24 == 0) {
        func_ov000_0219a220(c);
    }
    return 1;
}
