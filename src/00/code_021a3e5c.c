#include "00/code_021a3e5c.h"

u32 func_ov000_021a3e5c(int a, int b) {
    int v1;
    int v2;
    int v3;
    int *v4;
    v1 = 0;
    v3 = a;
    do {
        if (b == *(int *) (v3 + 0xd8)) {
            return 1;
        }
        v3 = v3 + 4;
        v1 = v1 + 1;
    } while (v1 < 10);
    v2 = (*(int *) (a + 0x100) + 1) % (10);
    v4 = (int *) (a + 0x100);
    *v4 = v2;
    *(int *) (a + *v4 * 4 + 0xd8) = b;
    return 0;
}
