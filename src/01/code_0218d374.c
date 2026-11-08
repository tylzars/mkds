#include "01/code_0218d374.h"
#include "01/code_02187eb0.h"
#include "01/code_02188cd8.h"

#include "01/code_02185ef4.h"
#include "01/code_02188000.h"
#include "01/code_02188da4.h"
#include "01/code_02187000.h"
#include "01/code_0218d520.h"
#include "01/code_0218dce4.h"
#include "01/code_0218ddb4.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_0210b708.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_0218d000.h"
#include "01/code_0218e000.h"
#include "01/unk_021a7000.h"

void func_ov001_0218d3ec(Unk02188950 *a) {
    s32 x;
    s32 y;
    s32 t;

    if (GetBalloonOrShineCount(gRaceSetup->mEntryIndex) <= 1) {
        y = 0x1000 - a->mPrm->mUnk_0ac;
        t = func_ov001_02187f38(a);
        x = (((s64) t * y) >> 12);
    } else if (GetBalloonOrShineCount(gRaceSetup->mEntryIndex) <= 2) {
        y = 0x1000 - a->mPrm->mUnk_0a8;
        t = func_ov001_02187f38(a);
        x = (((s64) t * y) >> 12);
    } else {
        x = func_ov001_02187f38(a);
    }
    func_ov001_02187218(a, 1, func_ov001_0218d520);
    SetStoppedCallback(a, NULL);
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_088, a->mPrm->mUnk_08c);
    func_ov001_0218d824(a, x);
    func_ov001_0218d87c(a, x);
    func_ov001_0218d8f4(a, x);
    func_ov001_0218dce4(a);
}

void func_ov001_0218d374(Unk02188950 *a) {
    int i;
    Unk0218d87c *list;
    Unk02188950 *p;

    func_ov001_02187218(a, 8, NULL);
    StartAnimationNoEndCallback(a, a->mPrm->mUnk_078, a->mPrm->mUnk_07c);
    func_ov001_02188c90(a);
    SetSpeedAndClearTarget(a, 0);
    list = FindMapObjectKindUpdateList(0x1fe);
    if (list != NULL) {
        for (i = 0; i < list->mUnk_04 && (p = list->mUnk_00[i]) != NULL; i++) {
            func_ov001_02187218(p, 1, NULL);
            StartAnimationNoEndCallback(p, p->mPrm->mUnk_078, p->mPrm->mUnk_07c);
        }
    }
}
