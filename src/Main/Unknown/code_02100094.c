#include "Main/Unknown/code_02100094.h"
#include "Main/Unknown/code_020e6fd4.h"

s32 func_02100094(MapObjectList *list) {
    s32 count = list->mMapObjectCount;

    while (count > 1 && *(u16 *) list->mMapObjects[count - 1] == 0x6f) {
        count--;
    }
    return count;
}
