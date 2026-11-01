#include "00/code_0218a67c.h"
#include "00/code_0218a350.h"
#include "00/unk_021b2000.h"
#include "code_02134d30.h"
#include "code_0214d018.h"

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
