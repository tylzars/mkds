#include "00/code_0219887c.h"
#include "00/code_02197e58.h"
#include "00/unk_021b3000.h"
#include "code_02134398.h"

u16 GetSocketPort(Gt2Socket *a) {
    return a->mPort;
}

int func_ov000_021988dc(Gt2Connection *a) {
    return a->mSendBuffer.mSize - a->mSendBuffer.mLength;
}

u32 GetSocketDescriptor(u32 *a) {
    return *a;
}

void SetUnmatchedDataCallback(Gt2Socket *a, UnkWordFunc *b) {
    a->mUnmatchedDataCallback = b;
}

void func_ov000_021988a4(Unk0219887c *connection, void *b) {
    if (connection == NULL) {
        AssertionFailed(data_ov000_021b3f8c, data_ov000_021b3f98, NULL, 0x19c);
    }
    connection->mUnk_40 = b;
}

u8 *func_ov000_0219887c(Unk0219887c *object) {
    if (object == NULL) {
        AssertionFailed(data_ov000_021b3f8c, data_ov000_021b3f98, NULL, 0x1a3);
    }
    return object->mUnk_40;
}
