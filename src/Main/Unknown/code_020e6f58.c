#include "Main/Unknown/code_020e6f58.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020d6538.h"

#include "Main/Unknown/code_020d6000.h"

#pragma thumb on
// While still unset, also fills the list's words 0x18 to 0x20.
void AddMapObjectToUpdateList(MapObjectList *p, MapObject *q) {
    u16 n;
    MapObjectKindData *t;

    n = p->mMapObjectCount;
    p->mMapObjectCount = n + 1;
    p->mMapObjects[n] = q;
    if (p->mUnk_18 == 3) {
        t = q->mKindData;
        p->mUnk_18 = t->mUnk_20;
    }
    if (p->mUnk_1c == NULL) {
        t = q->mKindData;
        p->mUnk_1c = t->mUnk_04;
    }
    if (p->mUnk_20 == 3) {
        p->mUnk_20 = func_020d6910(6, q);
    }
}
#pragma thumb off
