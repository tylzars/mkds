#include "00/code_0219de5c.h"

#include "00/code_0219e4e8.h"
#include "00/code_0219eac8.h"
#include "00/code_021a4784.h"

void func_ov000_0219dedc(void) {}

void func_ov000_0219ded8(void) {}

void func_ov000_0219de68(s32 a, Unk021a3fc8 *b, void *c) {
    s32 i;
    u8 *d;
    switch (a) {
        case 0:
            func_ov000_021a4784((u32) b, 8);
            func_ov000_021a4784((u32) b, 0xa);
            func_ov000_021a4784((u32) b, 0x32);
            func_ov000_021a4784((u32) b, 0x33);
            func_ov000_021a4784((u32) b, 0x34);
            func_ov000_021a4784((u32) b, 0x35);
            func_ov000_021a4784((u32) b, 0x36);
            i = 0;
            d = data_ov000_021b5698[0];
            for (; i < 0x9a; i++) {
                if (d[0] != 0) {
                    func_ov000_021a4784((u32) b, d[0]);
                }
                d += 12;
            }
            break;
        case 1:
            break;
        case 2:
            break;
    }
}

s32 func_ov000_0219de64(void) {
    return 0;
}

u32 func_ov000_0219de5c(u32 kind) {
    return func_ov000_0219e4e8(kind);
}
