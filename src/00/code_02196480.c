#include "00/code_02196480.h"

#include "00/code_02193634.h"
#include "00/code_021906e4.h"
#include "00/code_021947e4.h"
#include "00/code_02196914.h"
#include "00/code_021a3690.h"
#include "00/code_02196590.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "code_02135014.h"
#include "code_02139f70.h"
#include "code_02134d30.h"
#include "code_0213a460.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/code_02190ff8.h"
#include "00/code_02192d64.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/code_0218d818.h"
#include "00/code_02196000.h"
#include "00/code_02190000.h"
#include "00/code_0218f960.h"
#include "00/code_02194bb8.h"
#include "00/code_02193b88.h"
#include "00/code_021965a0.h"
#include "00/code_021967b4.h"
#include "code_021384cc.h"
#include "00/code_0218e2dc.h"
#include "00/unk_021b4000.h"
#include "00/code_02190cd4.h"

s32 func_ov000_021964e4(GpConnection *a, GpiOperation *b, const char *c) {
    GpiCallback p;
    u32 *m;
    s32 t;

    if (GpiReadError(a, c, 1) != 0) {
        return 4;
    }
    if (strncmp(c, data_ov000_021b39c4, 4) != 0) {
        GpiSetError(a, 1, data_ov000_021b39cc);
        GpiQueueErrorCallback(a, 3, 1);
        return 3;
    }
    p = b->mUnk_0c;
    if (p.mCallback != NULL) {
        m = func_ov000_021a3690(4);
        if (m == NULL) {
            GpiSetErrorMessage(a, data_ov000_021b39fc);
            return 1;
        }
        m[0] = 0;
        t = GpiQueueCallback(a, p, m, b, 0);
        if (t != 0) {
            return t;
        }
    }
    GpiRemoveOperation(a, b);
    return 0;
}

s32 func_ov000_02196480(GpConnection *a, s32 *b, GpiPeer *c, s32 d, const char *e) {
    char f[0x24];
    s32 t;

    if (e == NULL) {
        e = data_ov000_021b39a8;
    }
    t = GpiPeerSendXfer(a, c, 0xc9, (GpiTransferId *) b);
    if (t != 0) {
        return t;
    }
    sprintf(f, data_ov000_021b39ac, 1, d);
    t = GpiPeerSendString(a, (Unk02190988 *) c, f);
    if (t != 0) {
        return t;
    }
    t = GpiPeerSendLenMsg(a, c, e, -1);
    if (t != 0) {
        return t;
    }
    return 0;
}
