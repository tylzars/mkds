#include "00/code_02198714.h"
#include "00/code_0218e8c4.h"

u32 func_ov000_02198714(u32 *a, u32 b, u32 c) {
    int v1;
    u32 v2;
    v1 =
        func_ov000_0219a110((u32 *) ((u32 *) (u32) (a[2])), (u32) (*a), (int) (*(u16 *) (a + 1)), (u32) (b), (u32) (c));
    if (v1 == 0) {
        return 0;
    }
    v2 = func_ov000_0218e8c4();
    a[0x22] = v2;
    return 1;
}
