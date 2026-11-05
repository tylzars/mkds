#include "00/code_0219a430.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "00/code_0218d818.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_0218dd8c.h"
#include "00/unk_021b4000.h"
#include "00/code_0218e2dc.h"
#include "00/code_02197e58.h"
#include "00/code_021985ec.h"
#include "00/code_021988e8.h"
#include "00/code_02198a8c.h"
#include "00/code_021919ac.h"
#include "00/code_0219a000.h"
#include "00/code_0219a5e8.h"
#include "00/code_0219a604.h"
#include "00/code_021a3668.h"

typedef struct Unk0219a430Addr {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk0219a430Addr;

void func_ov000_0219a5dc(Gt2Connection **a) {
    func_ov000_021984b4(*a);
}

Gt2Connection *FindConnection(Gt2Socket *a, u32 b, u32 c) {
    Gt2Connection d;
    Gt2Connection *e;
    void *f;
    d.mAddress = b;
    d.mPort = c;
    e = &d;
    f = HashtableFind(a->mConnections, &e);
    if (f != NULL) {
        return *(Gt2Connection **) f;
    }
    return NULL;
}

u32 CreateSocket(Gt2Socket **a, const char *b, u32 c, u32 d, u32 e) {
    Gt2Socket *f;
    u16 i;
    Unk0219a430Addr g;
    u32 h;
    s32 j;
    u32 *p;
    func_ov000_0218e8b8();
    if (d == 0) {
        d = 0x10000;
    }
    if (c == 0) {
        c = 0x10000;
    }
    if (Gt2ParseAddress(b, &h, &i) == FALSE) {
        return 4;
    }
    f = func_ov000_021a3690(0x44);
    if (f == NULL) {
        return 1;
    }
    memset(f, 0, 0x44);
    f->mDescriptor = -1;
    f->mUnk_3c = d;
    f->mSendBufferSize = c;
    f->mUnk_24 = (void (*)(Gt2Socket *)) e;
    f->mConnections = HashtableCreate(4, 0x20, 2, (s32(*)(void *, s32)) & func_ov000_0219a604,
                                      (s32(*)(void *, void *)) & func_ov000_0219a5e8, NULL);
    if (f->mConnections == NULL) {
        func_ov000_021a3668(f);
        return 1;
    }
    f->mConnectionsToFree = (void *) DarrayCreate(4, 4, (void (*)(void *)) & func_ov000_0219a5dc);
    if (f->mConnectionsToFree == NULL) {
        HashtableDelete(f->mConnections);
        func_ov000_021a3668(f);
        return 1;
    }
    f->mDescriptor = func_ov000_0218e554(2, 2, 0);
    if (f->mDescriptor == -1) {
        HashtableDelete(f->mConnections);
        DarrayDelete(f->mConnectionsToFree);
        func_ov000_021a3668(f);
        return 3;
    }
    p = (u32 *) &g;
    p[0] = 0;
    p[1] = 0;
    g.mUnk_01 = 2;
    g.mUnk_04 = h;
    g.mUnk_02 = ((i >> 8) & 0xff) | ((i << 8) & 0xff00);
    if (func_ov000_0218e4e4(f->mDescriptor, &g, 8) == -1) {
        func_ov000_0218e53c(f->mDescriptor);
        HashtableDelete(f->mConnections);
        DarrayDelete(f->mConnectionsToFree);
        func_ov000_021a3668(f);
        return 3;
    }
    j = 8;
    func_ov000_0218e394(f->mDescriptor, &g, (u32 *) &j);
    f->mAddress = g.mUnk_04;
    f->mPort = ((g.mUnk_02 >> 8) & 0xff) | ((g.mUnk_02 << 8) & 0xff00);
    *a = f;
    return 0;
}
