#include "00/code_02197ddc.h"
#include "00/code_02197e58.h"
#include "00/code_021a3690.h"
#include "00/unk_021b3000.h"
#include "code_02134398.h"

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

void AppendBufferByte(Gt2Buffer *buffer, u8 b) {
    int v1;
    if (buffer->mLength >= buffer->mSize) {
        AssertionFailed(data_ov000_021b3f34, data_ov000_021b3ebc, NULL, 0x23);
    }
    v1 = buffer->mLength;
    buffer->mLength = v1 + 1;
    buffer->mData[v1] = b;
}

void AppendBufferU16(Gt2Buffer *buffer, s32 b) {
    int v1;
    if (buffer->mLength + 2 > buffer->mSize) {
        AssertionFailed(data_ov000_021b3f10, data_ov000_021b3ebc, NULL, 0x2e);
    }
    v1 = buffer->mLength;
    buffer->mLength = v1 + 1;
    buffer->mData[v1] = b >> 8;
    v1 = buffer->mLength;
    buffer->mLength = v1 + 1;
    buffer->mData[v1] = (s8) b;
}
