#include "Main/Unknown/code_020ed578.h"
#include "Main/Unknown/code_020e66e4.h"

#include "Main/Unknown/code_020ed588.h"
#include "Main/Unknown/code_020f36d8.h"

void func_020ed588(ItemObject *a, Unk020e6488 *b) {
    func_020e6a18(b);
    func_020e6854(b, &a->mPos, 1, 0x1f);
}

Unk020e6488 *func_020ed578(u32 arg0) {
    return gItemModels[arg0];
}
