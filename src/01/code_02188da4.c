#include "01/code_02188da4.h"
#include "01/code_02188e88.h"

void SetStoppedCallback(Unk02188950 *mapObject, UnkFunc *callback) {
    if (callback == NULL) {
        callback = (UnkFunc *) func_ov001_02188e88;
    }
    mapObject->mStoppedCallback = callback;
}

void SetCourseCollisionCallback(Unk02188950 *mapObject, void (*callback)(Unk02188950 *)) {
    if (callback == NULL) {
        callback = (UnkFunc *) func_ov001_02188e88;
    }
    mapObject->mCourseCollisionCallback = callback;
}

void func_ov001_02188da4(Unk02188950 *mapObject, UnkFunc *callback) {
    if (callback == NULL) {
        callback = (UnkFunc *) func_ov001_02188e88;
    }
    mapObject->mUnk_230 = callback;
}
