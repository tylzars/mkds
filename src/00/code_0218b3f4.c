#include "00/code_0218b3f4.h"
#include "00/code_021a3000.h"
#include "00/code_0218b434.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_0218dd8c.h"

struct Unk0218e004 *func_ov000_0218b3f4(struct Unk021b4d24 *p) {
    if (data_ov000_021b4d18 == NULL) {
        data_ov000_021b4d18 =
            func_ov000_0218e004(8, 100, 2, (s32(*)(void *, s32)) func_ov000_0218b44c,
                                (s32(*)(void *, void *)) func_ov000_0218b440, (void (*)(void *)) func_ov000_0218b434);
    }
    return data_ov000_021b4d18;
}
