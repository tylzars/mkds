#include "00/code_0219a604.h"
#include "00/code_02197e58.h"

u32 func_ov000_0219a604(const Gt2ConnectionEntry *object, u32 modulus) {
    return (object->mValue->mAddress * object->mValue->mPort) % modulus;
}
