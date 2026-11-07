#include "Main/Unknown/code_020b2b1c.h"

#include "Main/Unknown/code_020b2b24.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020b2b54.h"
#include "00/code_02181f98.h"

u32 func_020b2b5c(void) {
    return (data_0217b488->mUnk_10);
}

u32 func_020b2b54(void) {
    return 0x8u;
}

u16 func_020b2b40(InputSlot *p, u32 a) {
    return p->mUnk_00 & a;
}

u16 func_020b2b24(s32 a, u32 b) {
    return func_020b2b40(&data_02175628[a], b);
}

u32 func_020b2b1c(const void *p0) {
    return (*OFFSET_PTR(const u16, p0, 4));
}
