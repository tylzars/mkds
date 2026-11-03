#include "00/code_0218f960.h"
#include "00/code_021965a0.h"
#include "00/code_02196914.h"

void func_ov000_021965a0(GpConnection *a, u32 b, const void *c) {
    GpiConnection *v1;
    v1 = a->mGpiConnection;
    func_ov000_02196914(v1->mErrorMessage, c, 0x100);
    v1->mErrorNumber = b;
    return;
}
