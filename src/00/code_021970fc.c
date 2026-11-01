#include "00/code_021970fc.h"

void func_ov000_02197190(u32 a, s8 *b) {
    s8 *c = b;
    func_02135014((u8 *) b, data_ov000_021b3e04, a);
    while (*c != 0) {
        *c = *c + 0x11 + (c - b);
        c++;
    }
}

const s8 *func_ov000_021970fc(const s8 *v1, const u8 *v2) {
    Unk021b3c88 a = data_ov000_021b3c88;
    const s8 *b;
    s8 *c;
    s8 *e;
    data_ov000_021b4e70 ^= 1;
    func_0213a1c0((char *) a.mUnk_00, v2);
    func_0213a1c0((char *) a.mUnk_00, data_ov000_021b3e00);
    b = (const s8 *) func_02139f70((const u8 *) v1, (const u8 *) a.mUnk_00);
    if (b == 0) {
        return 0;
    }
    b += func_0213a434((const u8 *) a.mUnk_00);
    e = data_ov000_021b5084 + (data_ov000_021b4e70 << 8);
    c = e;
    while (*b != 0 && *b != '\\') {
        *c++ = *b++;
    }
    *c = 0;
    return e;
}
