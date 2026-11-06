#include "Main/Unknown/code_020e6fc4.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

#pragma thumb on
void ClearMapObjectListCount(MapObjectList *p) {
    p->mMapObjectCount = 0;
}

void AddToMapObjectListCount(MapObjectList *p, s32 n) {
    p->mMapObjectCount = p->mMapObjectCount + n;
}
#pragma thumb off
