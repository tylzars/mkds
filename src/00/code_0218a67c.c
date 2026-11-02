#include "00/code_0218a67c.h"
#include "00/code_0218a000.h"

#include "00/code_0218a350.h"
#include "00/unk_021b2000.h"
#include "code_02134d30.h"
#include "code_0214d018.h"

void func_ov000_0218a6f4(u32 param_1, int param_2, int param_3) {
    u8 v1;
    int v2;
    v2 = 0;
    if (0 < param_3) {
        do {
            v1 = func_ov000_0218a71c((Unk0218a71c *) (param_1), (u8) (*(u8 *) (param_2 + v2)));
            *(u8 *) (param_2 + v2) = v1;
            v2 = v2 + 1;
        } while (v2 < param_3);
    }
    return;
}

u32 func_ov000_0218a6c8(u32 param_1) {
    int v1;
    u8 v2[24];
    func_ov000_0218a5b0((const u8 *) (param_1), v2);
    v1 = func_02134d30((const u8 *) ((u32) (v2)), (const u8 *) &data_ov000_021b2174, 8);
    if (v1 == 0) {
        return 1;
    }
    return 0;
}

void func_ov000_0218a6ac(const u8 *a, u8 *b) {
    u8 t[24];
    func_ov000_0218a5b0(a, t);
    func_ov000_0218a57c(t, b);
}

void func_ov000_0218a67c(const u8 *a, char *b) {
    u8 t[24];
    func_ov000_0218a5b0(a, t);
    if (func_02134d30(t, data_ov000_021b2174, 8) == 0) {
        func_0214d1fc(t + 8, b, 10);
    }
}
