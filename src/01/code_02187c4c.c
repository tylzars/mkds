#include "01/code_02187c4c.h"
#include "01/code_02188950.h"

u32 IsItemBombStored(Unk02188950 *mapObject) {
    if (mapObject->mItemBomb != NULL) {
        return 1;
    }
    return 0;
}
