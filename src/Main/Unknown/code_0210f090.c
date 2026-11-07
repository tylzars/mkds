#include "Main/Unknown/code_0210f090.h"

#include "code_0201ec30.h"

u32 func_0210f090(MicBuffer *micBuffer) {
    if (micBuffer->mUnk_41c == 0) {
        return func_0201ec30();
    }
    if (micBuffer->mUnk_41c < 0x1e) {
        micBuffer->mUnk_41c = micBuffer->mUnk_41c + 1;
    } else {
        micBuffer->mUnk_41c = 0;
    }
    return 0;
}
