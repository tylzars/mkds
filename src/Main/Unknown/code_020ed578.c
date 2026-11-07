#include "Main/Unknown/code_020ed578.h"
#include "Main/Unknown/code_020e66e4.h"

#include "Main/Unknown/code_020ed588.h"
#include "Main/Unknown/code_020f36d8.h"

void func_020ed588(ItemObject *item, Unk020e6488 *model) {
    func_020e6a18(model);
    func_020e6854(model, &item->mPos, 1, 0x1f);
}

Unk020e6488 *GetItemModel(u32 kind) {
    return gItemModels[kind];
}
