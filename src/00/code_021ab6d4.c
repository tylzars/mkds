#include "00/code_021ab6d4.h"
#include "00/code_021ab728.h"
#include "00/code_021abc04.h"
#include "00/unk_021b4000.h"

void func_ov000_021ab6d4(int a, u32 b) {
    int v1;
    int v2;
    func_ov000_021abc14(b, a + 0x10, 8);
    v1 = *(u32 *) (a + 0x10) >> 3 & 0x3f;
    if (v1 < 0x38) {
        v2 = 0x38 - v1;
    } else {
        v2 = 0x78 - v1;
    }
    func_ov000_021ab728((void *) a, data_ov000_021b4aa4, v2);
    func_ov000_021ab728((void *) a, (const u8 *) b, 8);
    func_ov000_021abc14(b, a, 0x10);
    return;
}
