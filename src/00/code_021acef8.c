#include "00/code_021acef8.h"
#include "00/code_021a8878.h"
#include "00/code_021acfd8.h"
#include "00/code_021ad018.h"
#include "00/unk_021b6380.h"

u32 func_ov000_021acef8(const char *a) {
    u32 r;
    u8 f[2];
    u16 s[2];
    s32 i;
    s32 j;

    data_ov000_021b63e0[0] = (s64) data_ov000_021b63e0[1] * (s64) data_ov000_021b63e0[0] + data_ov000_021b63e0[2];
    s[0] = ((data_ov000_021b63e0[0] >> 32) * 0x10000) >> 32;
    data_ov000_021b63e0[0] = (s64) data_ov000_021b63e0[1] * (s64) data_ov000_021b63e0[0] + data_ov000_021b63e0[2];
    s[1] = ((data_ov000_021b63e0[0] >> 32) * 0x10000) >> 32;
    if (func_ov000_021ad018(a, &r) != 0) {
        return r;
    }
    f[0] = 1;
    f[1] = 1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            if (f[j] != 0) {
                r = func_ov000_021acfd8(a, data_ov000_021b63d8[j], s[j]);
                if (r != 0 && r != 0xffffffff) {
                    goto done;
                }
                if (r == 0xffffffff) {
                    f[j] = 0;
                }
            }
        }
    }
done:
    if (r == 0xffffffff) {
        r = 0;
    }
    return r;
}
