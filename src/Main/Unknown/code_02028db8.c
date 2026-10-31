#include "Main/Unknown/code_02028db8.h"

u16 func_02028dd4(void) {
    int v1;
    u32 v2;
    v2 = *(u32 *) &data_0217aa00;
    if ((*(u32 *) v2) == 2) {
        v1 = *(u16 *) (v2 + 0x432);
    } else {
        v1 = 0;
    }
    return v1;
}

u32 func_02028db8(u32 p0) {
    return ((u32) *(
        const u16
            *) ((u8 *) (u32) ((
                    (((((u32) *(
                          const u32 *) ((u8 *) (u32) (((u32) (&data_0217aa00))) + 0))) +
                      (((p0) << 3)))) +
                    (0x1e00u))) +
                82));
}
