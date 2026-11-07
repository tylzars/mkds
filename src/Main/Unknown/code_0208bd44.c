#include "Main/Unknown/code_0208bd44.h"
#include "Main/Unknown/code_0207d814.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_02089ce4.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_0207d000.h"
#include "Main/Unknown/code_020901a0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0207d7e4.h"
#include "Main/Unknown/code_0207e000.h"
#include "Main/Unknown/code_02090000.h"
#include "Main/Unknown/code_02077bc0.h"

void func_0208bf40(KartAi *p) {
    AdvanceBattleKartAi(p);
    AdvanceBattleKartAiSpeedLimit(&p->mAiSpeedLimit, p);
    func_0209033c(&p->mItemUse, p);
}

void func_0208bef4(KartAi *p) {
    if (p->mBattleLinkCursor.mRequestedLink != NULL) {
        if (p->mBattleLinkCursor.mUnk_18 != FALSE) {
            return;
        }
    }
    p->mBattleLinkCursor.mRequestedLink = FindCourseMapKind4ShapeBattlePointLink(&p->mKart->mPos);
    if (p->mBattleLinkCursor.mRequestedLink != NULL) {
        p->mBattleLinkCursor.mUnk_18 = TRUE;
    }
}

BOOL func_0208bee0(KartAi *p) {
    return p->mBattleLinkCursor.mRequestedLink != NULL;
}

void func_0208bea4(Vec3 *a, Vec3 *b, KartAi *p) {
    LinkCursor *s = &p->mBattleLinkCursor;

    *a = *s->mLink->mUnk_20;
    *b = s->mDirection;
}

void func_0208be90(KartAi *p) {
    SetupBattleHeldItemEntry(&p->mItemUse, p);
}

void func_0208be7c(KartAi *p) {
    SetupBattleItemInUseEntry(&p->mItemUse, p);
}

void func_0208be00(KartAi *p, s32 a) {
    Kart *q = GetKart(a);

    p->mUnk_154 = 0;
    func_0207e594(p, q, p->mUnk_154);
    func_0207d814(&p->mUnk_e8, p);
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        p->mUnk_e8.mUnk_2c = 1;
        p->mUnk_e8.mUnk_30 = 4;
    } else {
        p->mUnk_e8.mUnk_2c = 0;
        p->mUnk_e8.mUnk_30 = 0;
    }
}

void func_0208bde0(KartAi *p, Unk02175620_bc *a) {
    func_0207e564(p, a);
    func_0207d7e4(&p->mUnk_e8, p);
}

void func_0208bdc0(KartAi *p) {
    func_0207e4a4(p);
    func_0207d6a4(&p->mUnk_e8, p);
}

void func_0208bd44(KartAi *p, s32 a) {
    Kart *q = GetKart(a);

    p->mUnk_154 = 0;
    func_0207e400(p, q, p->mUnk_154);
    func_0207d814(&p->mUnk_e8, p);
    p->mUnk_e8.mUnk_2c = 0;
    p->mUnk_e8.mUnk_30 = 0;
    if (q->mIndex != gRaceSetup->mEntryIndex) {
        q->mUnk_7c |= 0x40;
    }
}
