#include "01/code_02188230.h"
#include "01/code_0218c000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020a3000.h"

BOOL func_ov001_02188230(Unk02188950 *a) {
    s32 limit;

    a->mUnk_0ac--;
    limit = -a->mUnk_0a0->mUnk_000;
    if (a->mUnk_0ac <= limit) {
        a->mUnk_0ac = limit;
        return TRUE;
    }
    return FALSE;
}
