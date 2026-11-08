#include "01/code_02188158.h"
#include "01/code_02188e88.h"
#include "Main/Unknown/code_020fd264.h"
#include "Main/Unknown/code_020fd83c.h"
#include "Main/Unknown/code_020fd7f0.h"

void SetKartCollisionCallback(Unk02188950 *mapObject, UnkFunc *kartCollisionCallback) {
    mapObject->mKartCollisionCallback = kartCollisionCallback;
}

void SetItemCollisionCallback(Unk02188950 *mapObject, UnkFunc *itemCollisionCallback) {
    mapObject->mItemCollisionCallback = itemCollisionCallback;
}

BOOL IsPointInRange(Unk02188950 *mapObject, Vec3 *point, s32 radius, s32 halfAngle) {
    if ((radius != 0 || halfAngle != 0) && (radius == 0 || func_ov001_02188f04(mapObject, point, radius) != 0) &&
        (halfAngle == 0 || func_ov001_02188eac(mapObject, mapObject->mMoveAngle, point, halfAngle) != 0)) {
        return TRUE;
    }
    return FALSE;
}

ItemBomb *FindItemBombInRange(Unk02188950 *mapObject, u32 radius, u32 halfAngle) {
    int bombCount;
    ItemBomb *bomb;
    int inRange;
    int index;
    bombCount = GetItemBombActiveCount();
    index = 0;
    if (0 < bombCount) {
        do {
            bomb = func_020fd7a4(index);
            if ((bomb != NULL) &&
                (inRange = IsPointInRange(mapObject, &bomb->mUnk_000.mItemObject.mPos, radius, halfAngle),
                 inRange != 0)) {
                return bomb;
            }
            index = index + 1;
        } while (index < bombCount);
    }
    return NULL;
}
