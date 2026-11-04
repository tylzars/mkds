#include "00/code_0218e0e0.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_0218dd8c.h"

void *func_ov000_0218e0e0(u32 a, u32 b, void *c, void *d, void *e) {
    return HashtableCreate((s32) (a), (s32) (b), 4, (s32(*)(void *, s32))(c), (s32(*)(void *, void *))(d),
                           (void (*)(void *))(e));
}
