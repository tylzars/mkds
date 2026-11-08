#include "01/code_02188e24.h"
#include "01/code_02188e88.h"

void SetAnimationFrameCallback(Unk02188950 *mapObject, s32 frameIndex, UnkFunc *callback) {
    mapObject->mAnimationFrameCallbackFrameIndex = frameIndex;
    mapObject->mAnimationFrameCallback = callback;
}

void func_ov001_02188e48(Unk02188950 *mapObject, s32 firstFrameIndex, void (*firstCallback)(Unk02188950 *),
                         s32 secondFrameIndex, void (*secondCallback)(Unk02188950 *)) {
    mapObject->mUnk_1e0 = firstFrameIndex;
    mapObject->mUnk_1e4 = firstCallback;
    mapObject->mUnk_1e8 = secondFrameIndex;
    mapObject->mUnk_1ec = secondCallback;
}

void StartStateFrameCountCallback(Unk02188950 *mapObject, s32 frameCount, void (*callback)(Unk02188950 *)) {
    mapObject->mStateFrameCount = frameCount;
    mapObject->mStateFrames = 0;
    if (callback == NULL) {
        callback = func_ov001_02188e88;
    }
    mapObject->mStateFrameCountCallback = callback;
}
