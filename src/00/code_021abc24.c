#include "00/code_021abc24.h"
#include "00/code_021abca0.h"
#include "00/code_021ac37c.h"
#include "00/unk_021b4000.h"

void func_ov000_021abc4c(int a, u32 b) {
    int v1;
    int v2;
    func_ov000_021ac37c((u8 *) b, (u32 *) (a + 0x14), 8);
    v1 = *(u32 *) (a + 0x18) >> 3 & 0x3f;
    if (v1 < 0x38) {
        v2 = 0x38 - v1;
    } else {
        v2 = 0x78 - v1;
    }
    func_ov000_021abca0((void *) a, data_ov000_021b4be4, v2);
    func_ov000_021abca0((void *) a, (const u8 *) b, 8);
    func_ov000_021ac37c((u8 *) b, (u32 *) a, 0x14);
    return;
}

void func_ov000_021abc24(u32 a, u32 b) {
    func_ov000_021abca0((void *) a, data_ov000_021b4be5, 0x2c);
    func_ov000_021ac37c((u8 *) b, (u32 *) a, 0x14);
    return;
}
