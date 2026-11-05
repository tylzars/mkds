#include "00/code_021abc24.h"
#include "00/code_021abca0.h"
#include "00/code_021ac37c.h"
#include "00/unk_021b4000.h"

void func_ov000_021abc4c(Unk021abca0 *a, u8 *b) {
    int v1;
    int v2;
    func_ov000_021ac37c(b, &a->mUnk_14, 8);
    v1 = a->mUnk_18 >> 3 & 0x3f;
    if (v1 < 0x38) {
        v2 = 0x38 - v1;
    } else {
        v2 = 0x78 - v1;
    }
    func_ov000_021abca0(a, data_ov000_021b4be4, v2);
    func_ov000_021abca0(a, b, 8);
    func_ov000_021ac37c(b, &a->mUnk_00, 0x14);
    return;
}

void func_ov000_021abc24(Unk021abca0 *a, u8 *b) {
    func_ov000_021abca0(a, data_ov000_021b4be5, 0x2c);
    func_ov000_021ac37c(b, &a->mUnk_00, 0x14);
    return;
}
