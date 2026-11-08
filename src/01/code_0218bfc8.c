#include "01/code_0218bfc8.h"
#include "01/code_02185ef4.h"
#include "01/code_02187eb0.h"
#include "01/code_02188cd8.h"
#include "Main/Unknown/code_02042044.h"
#include "01/code_0218c0a4.h"
#include "01/code_0218c584.h"
#include "01/code_0219b1c4.h"

void func_ov001_0218bfc8(Unk02188950 *mapObject) {
    CourseMapGroupEntry *currentGroupEntry;
    MissionRunPrm *prm;
    func_ov001_02187218(mapObject, 2, &func_ov001_0218c584);
    StartAnimationNoEndCallback(mapObject, mapObject->mPrm->mUnk_15c, mapObject->mPrm->mUnk_160);
    func_ov001_0219b1c4(mapObject->mNsbmd, mapObject->mPrm->mUnk_164, mapObject->mPrm->mUnk_160, 0);
    SetSpeedTargetAndPerCall(mapObject, mapObject->mPrm->mUnk_168, mapObject->mPrm->mUnk_16c);
    prm = mapObject->mPrm;
    func_ov001_021889ec(mapObject, prm->mUnk_178, prm->mUnk_17c, prm->mUnk_170, prm->mUnk_174);
    currentGroupEntry = GetCurrentGroupEntry(mapObject);
    SetAnglePoint(mapObject, &currentGroupEntry->mPos);
    currentGroupEntry = GetCurrentGroupEntry(mapObject);
    SetMoveAnglePoint(mapObject, &currentGroupEntry->mPos);
    StartStateFrameCountCallback(mapObject, mapObject->mPrm->mUnk_180, &func_ov001_0218c354);
    func_ov001_0218c5fc(mapObject);
}
