#include "00/code_0218b3f4.h"
#include "00/code_0218b434.h"
#include "00/code_0218b440.h"
#include "00/code_0218b44c.h"
#include "00/code_0218dddc.h"

struct Unk0218e004 *func_ov000_0218b3f4(struct Unk021b4d24 *p) {
    if (data_ov000_021b4d18 == 0) {
        data_ov000_021b4d18 =
            func_ov000_0218e004(8, 100, 2, (s32(*)(void *, s32)) func_ov000_0218b44c,
                                (s32(*)(void *, void *)) func_ov000_0218b440, (void (*)(void *)) func_ov000_0218b434);
    }
    return data_ov000_021b4d18;
}
