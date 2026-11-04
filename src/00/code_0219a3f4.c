#include "00/code_0218d818.h"
#include "00/code_0218dd8c.h"
#include "00/code_02197e8c.h"
#include "00/code_0219a3f4.h"
#include "00/code_0218e2dc.h"
#include "00/code_021a3668.h"

void DeleteSocket(Gt2Socket *a) {
    if (a->mRunningCallbackCount != 0) {
        a->mDeletePending = 1;
        return;
    }
    func_ov000_0218e53c(a->mDescriptor);
    HashtableDelete(a->mConnections);
    DarrayDelete(a->mConnectionsToFree);
    func_ov000_021a3668(a);
    func_ov000_0218e8b4();
    return;
}

void SetIncomingConnectionCallback(int a, u32 b) {
    *(u32 *) (a + 0x20) = b;
    return;
}
