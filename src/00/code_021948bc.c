#include "00/code_021948bc.h"
#include "code_02139f70.h"

u32 func_ov000_021948bc(u32 a, int b, u32 *c) {
    int v1;
    u32 *v2;
    v2 = *(u32 **) (b + 0xc);
    if (((v2 != NULL) && (v1 = strcmp((const u8 *) (*c), (const u8 *) (*v2)), v1 == 0)) &&
        (v1 = strcmp((const u8 *) (c[1]), (const u8 *) (v2[2])), v1 == 0)) {
        *(s32 *) c[2] = b;
        c[3] = 1;
        return 0;
    }
    return 1;
}
