#include "00/code_0218f960.h"
#include "00/code_02194840.h"
#include "00/code_02194874.h"
#include "00/code_0218d000.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/code_0218dd8c.h"

BOOL GpiForEachProfileWhileNonZero(GpConnection *a, void *b, void *c) {
    GpiConnection *r;
    Unk02194840Arg d;

    r = a->mGpiConnection;
    d.mUnk_00 = a;
    d.mUnk_04 = b;
    d.mUnk_08 = c;
    if (HashtableFindByFn(r->mProfileList.mTable, (s32) func_ov000_02194874, (u32) &d) == NULL) {
        return TRUE;
    }
    return FALSE;
}
