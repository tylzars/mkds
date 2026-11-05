#include "00/code_021988e8.h"
#include "00/code_0219a0d0.h"
#include "00/code_0219a61c.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_0218dd8c.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/code_0218d818.h"
#include "03/code_021b94b8.h"
#include "00/code_0218e2dc.h"
#include "00/code_02198748.h"
#include "00/code_02198a8c.h"
#include "00/code_0219a654.h"

int func_ov000_02198a7c(Gt2Connection *a, Gt2ConnectionCallbacks *b) {
    return func_ov000_02198778(a, b);
}

void func_ov000_02198a74(Gt2Connection *a, void *b, u32 c) {
    func_ov000_02198748(a, b, c);
}

int func_ov000_02198968(void *a, Gt2Connection **b, u32 c, void *d, int e, u32 f, Gt2ConnectionCallbacks *g, int h) {
    Gt2Connection *m;
    u32 i;
    u16 j;
    u32 k;
    int l;
    int n;
    if (Gt2ParseAddress((const char *) c, &i, &j) == FALSE || i == 0 || (k = j) == 0) {
        return 4;
    }
    if (((((i << 24) & 0xff000000) | (((i << 8) & 0xff0000) | (((i >> 24) & 0xff) | ((i >> 8) & 0xff00)))) &
         0xe0000000) == 0xe0000000) {
        return 4;
    }
    l = func_ov000_0219885c(a, &m, i, k);
    if (l != 0) {
        return l;
    }
    m->mTimeSinceCreateLimit = f;
    n = func_ov000_021987c8(m, d, e, g);
    if (n != 0) {
        func_ov000_0219a220(m);
        return n;
    }
    if (h == 0) {
        if (b != NULL) {
            *b = m;
        }
        return 0;
    }
    m->mUnk_24++;
    do {
        func_ov000_02198a8c(a);
        l = m->mUnk_0c >= 5 ? 1 : 0;
        if (l == 0) {
            func_ov000_0218e8bc(1);
        }
    } while (l == 0);
    m->mUnk_24--;
    if (m->mUnk_0c == 5) {
        *b = m;
    }
    return m->mResult;
}

void func_ov000_02198914(Gt2Connection *a, u8 *b, int c, int d) {
    if (a->mUnk_0c == 5) {
        func_ov000_0219a61c((const char **) &b, &c);
        if (DarrayGetCount((u32 *) a->mUnk_98) != 0) {
            func_ov000_02198098(a, 0, (s32) b, (void *) c, d);
            return;
        }
        func_ov000_02198ad8(a, b, c, d);
    }
}

void func_ov000_02198908(Gt2Connection *a) {
    func_ov000_02198548(a, 1);
}

void func_ov000_021988fc(Gt2Connection **a) {
    func_ov000_02198908(*a);
}

void func_ov000_021988e8(Gt2Socket *a) {
    HashtableForEach(a->mConnections, (void (*)(void *, void *)) func_ov000_021988fc, NULL);
}
