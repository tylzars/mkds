#include "00/code_0218dc44.h"
#include "00/code_0218dd8c.h"
#include "00/code_02197e8c.h"
#include "00/code_0219a3f4.h"
#include "00/code_0218e49c.h"
#include "00/code_021a3668.h"

void func_ov000_0219a3f8(Unk02197e8c *a) {
    if (a->mUnk_1c != 0) {
        a->mUnk_14 = 1;
        return;
    }
    func_ov000_0218e53c(a->mUnk_00);
    func_ov000_0218dfb4(a->mUnk_0c);
    func_ov000_0218dc48(a->mUnk_10);
    func_ov000_021a3668(a);
    func_ov000_0218e8b4();
    return;
}

void func_ov000_0219a3f4(int a, u32 b) {
    *(u32 *) (a + 0x20) = b;
    return;
}
