#include "Main/Unknown/code_020165b8.h"

Unk02016638 *func_020165c8(Unk02016468 *p) {
    return p->mUnk_00 + p->mUnk_08;
}

Unk02016638 *func_020165b8(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) * (const u16 *) ((value0) + (10));
    value0 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (value0) + ((value1 << 4));
    return (Unk02016638 *) value0;
}
