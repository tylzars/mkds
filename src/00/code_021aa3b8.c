#include "00/code_021aa3b8.h"
#include "00/code_021aa468.h"
#include "00/types_021a998c.h"
#include "code_02134d30.h"
#include "code_0214d018.h"

void func_ov000_021aa3b8(Unk021a998c_0c *a, u8 *b) {
    int v1;
    u8 v2[20];
    func_0214d1fc(a->mUnk_378, a->mUnk_3d0, 0x58);
    func_ov000_021aa50c(a, v2, 1);
    func_0214d1fc(a->mUnk_3d0, a->mUnk_378, 0x58);
    v1 = memcmp(b, v2, 0x10);
    if (v1 != 0) {
        a->mUnk_429 = 9;
        return;
    }
    func_0214d1fc(a->mUnk_2c0, a->mUnk_31c, 0x5c);
    func_ov000_021aa468(a, v2, 1);
    func_0214d1fc(a->mUnk_31c, a->mUnk_2c0, 0x5c);
    v1 = memcmp(b + 0x10, v2, 0x14);
    if (v1 != 0) {
        a->mUnk_429 = 9;
        return;
    }
    a->mUnk_429 = 6;
}
