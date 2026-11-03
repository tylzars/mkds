#include "00/code_02197ddc.h"
#include "00/code_02197e8c.h"
#include "00/code_021a3690.h"
#include "00/unk_021b3000.h"
#include "code_0213442c.h"

u32 InitBuffer(Gt2Buffer *a, int b) {
    u8 *v1;
    v1 = func_ov000_021a3690(b);
    a->mData = v1;
    if (a->mData == 0) {
        return 0;
    }
    a->mSize = b;
    return 1;
}

int GetBufferUnusedSize(Gt2Buffer *a) {
    return a->mSize - a->mLength;
}

void AppendBufferByte(Gt2Buffer *a, u8 b) {
    int v1;
    if (a->mLength >= a->mSize) {
        func_0213442c(data_ov000_021b3f34, data_ov000_021b3ebc, NULL, 0x23);
    }
    v1 = a->mLength;
    a->mLength = v1 + 1;
    a->mData[v1] = b;
    return;
}

void AppendBufferU16(Gt2Buffer *a, s32 b) {
    int v1;
    if (a->mLength + 2 > a->mSize) {
        func_0213442c(data_ov000_021b3f10, data_ov000_021b3ebc, NULL, 0x2e);
    }
    v1 = a->mLength;
    a->mLength = v1 + 1;
    a->mData[v1] = b >> 8;
    v1 = a->mLength;
    a->mLength = v1 + 1;
    a->mData[v1] = (s8) b;
    return;
}
