#include "00/code_0218f960.h"
#include "00/code_021965a0.h"
#include "00/code_02196594.h"

void GpiSetError(GpConnection *a, u32 b, const char *c) {
    GpiConnection *v1;
    v1 = a->mGpiConnection;
    GpiCopyString(v1->mErrorMessage, c, 0x100);
    v1->mErrorNumber = b;
    return;
}
