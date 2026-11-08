#include "01/code_02188de0.h"
#include "01/code_0218c000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020a3000.h"

void SetPointInRangeCallback(Unk02188950 *mapObject, s32 pointRadius, s32 pointHalfAngle, Vec3 *point,
                             UnkFunc *callback) {
    UnkFunc *storedCallback;

    mapObject->mPointRadius = pointRadius;
    mapObject->mPointHalfAngle = pointHalfAngle;
    if (point != NULL) {
        mapObject->mPoint = *point;
    }
    storedCallback = callback;
    if (storedCallback == NULL) {
        storedCallback = func_ov001_02188e88;
    }
    mapObject->mPointInRangeCallback = storedCallback;
}
