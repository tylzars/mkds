#include "00/code_02198714.h"
#include "00/code_0218e2dc.h"
#include "00/code_0219a0d0.h"

u32 SendConnectionBytes(Gt2Connection *a, u8 *b, u32 c) {
    int v1;
    u32 v2;
    v1 = func_ov000_0219a110((u32 *) a->mSocket, a->mAddress, a->mPort, (u32) b, c);
    if (v1 == 0) {
        return 0;
    }
    v2 = func_ov000_0218e8c4();
    a->mLastSendTime = v2;
    return 1;
}
