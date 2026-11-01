#include "00/code_0218b4f8.h"
#include "00/code_0218b708.h"
#include "00/code_0218e368.h"

s32 func_ov000_0218b530(Unk0218b668 *a, u32 b, s32 c, u8 *d, s32 e) {
    u32 f = func_ov000_0218e374(b);
    return func_ov000_0218ba88(&a->mUnk_04c, f, (u16) (((c >> 8) & 0xff) | ((c << 8) & 0xff00)), d, e);
}

s32 func_ov000_0218b4f8(Unk0218b668 *a, u32 b, s32 c, u32 d) {
    u32 e = func_ov000_0218e374(b);
    return func_ov000_0218ba10(&a->mUnk_04c, e, (u16) (((c >> 8) & 0xff) | ((c << 8) & 0xff00)), d);
}
