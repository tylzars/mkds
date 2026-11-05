#include "00/code_0218a658.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"

u32 func_ov000_0218a658(const u8 *a) {
    int v1;
    v1 = memcmp(a, data_ov000_021b2168, 8);
    if (v1 == 0) {
        return 1;
    }
    return 0;
}
