#include "00/code_02197ddc.h"
#include "00/code_02197e8c.h"
#include "00/code_021a3690.h"
#include "00/unk_021b3000.h"
#include "code_0213442c.h"

u32 func_ov000_02197e60(Unk02197fe8Buf *a, int b) {
    u8 *v1;
    v1 = func_ov000_021a3690(b);
    a->mUnk_00 = v1;
    if (a->mUnk_00 == 0) {
        return 0;
    }
    a->mUnk_04 = b;
    return 1;
}

int func_ov000_02197e58(Unk02197fe8Buf *a) {
    return a->mUnk_04 - a->mUnk_08;
}

void func_ov000_02197e20(Unk02197fe8Buf *a, u8 b) {
    int v1;
    if (a->mUnk_08 >= a->mUnk_04) {
        func_0213442c(data_ov000_021b3f34, data_ov000_021b3ebc, NULL, 0x23);
    }
    v1 = a->mUnk_08;
    a->mUnk_08 = v1 + 1;
    a->mUnk_00[v1] = b;
    return;
}

void func_ov000_02197ddc(Unk02197fe8Buf *a, s32 b) {
    int v1;
    if (a->mUnk_08 + 2 > a->mUnk_04) {
        func_0213442c(data_ov000_021b3f10, data_ov000_021b3ebc, NULL, 0x2e);
    }
    v1 = a->mUnk_08;
    a->mUnk_08 = v1 + 1;
    a->mUnk_00[v1] = b >> 8;
    v1 = a->mUnk_08;
    a->mUnk_08 = v1 + 1;
    a->mUnk_00[v1] = (s8) b;
    return;
}
