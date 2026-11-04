#include "00/code_0219887c.h"
#include "00/code_02197e8c.h"
#include "00/unk_021b3000.h"
#include "code_02134398.h"

u16 GetSocketPort(void *a) {
    return *(u16 *) ((u8 *) a + 8);
}

int func_ov000_021988dc(Gt2Connection *a) {
    return a->mSendBuffer.mSize - a->mSendBuffer.mLength;
}

u32 GetSocketDescriptor(u32 *a) {
    return *a;
}

void SetUnmatchedDataCallback(int a, u32 b) {
    *(u32 *) (a + 0x30) = b;
    return;
}

void func_ov000_021988a4(Unk0219887c *connection, void *b) {
    if (connection == NULL) {
        AssertionFailed(data_ov000_021b3f8c, data_ov000_021b3f98, NULL, 0x19c);
    }
    connection->mUnk_40 = b;
    return;
}

u8 *func_ov000_0219887c(Unk0219887c *object) {
    if (object == NULL) {
        AssertionFailed(data_ov000_021b3f8c, data_ov000_021b3f98, NULL, 0x1a3);
    }
    return object->mUnk_40;
}
