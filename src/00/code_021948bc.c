#include "00/code_021948bc.h"
#include "code_02139f70.h"

u32 func_ov000_021948bc(u32 a, int b, Unk0219488cArg *c) {
    int v1;
    u32 *v2;
    v2 = *(u32 **) (b + 0xc);
    if (((v2 != NULL) && (v1 = strcmp(c->mUnk_00, (const char *) (*v2)), v1 == 0)) &&
        (v1 = strcmp(c->mUnk_04, (const char *) (v2[2])), v1 == 0)) {
        *c->mUnk_08 = (void *) b;
        c->mUnk_0c = TRUE;
        return 0;
    }
    return 1;
}
