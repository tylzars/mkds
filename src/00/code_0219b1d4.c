#include "00/code_0219b1d4.h"
#include "00/code_0218e49c.h"

void func_ov000_0219b1d4(Unk0219b1d4 *object) {
    if (object->mDescriptor != -1) {
        func_ov000_0218e53c(object->mDescriptor);
    }
    object->mDescriptor = -1;
    object->mUnk_10 = 4;
}
