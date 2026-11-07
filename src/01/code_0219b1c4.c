#include "01/code_0219b1c4.h"
#include "Main/Unknown/code_02087000.h"
#include "01/code_0219b540.h"
#include "01/code_0219c000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_0212b000.h"
#include "Main/Unknown/code_02087cfc.h"

void func_ov001_0219b208(Unk0219b250 *a, s32 b, s32 c, s32 d) {
    StartModelAnimationBlend(a->mNsbcaAnimation, b);
    a->mNsbcaAnimation->mUnk_08 = c;
    func_02087cfc(a->mNsbcaAnimation, ((u16) b), (d != 0 ? UNK_02087CFC_KIND_0 : UNK_02087CFC_KIND_1));
}

void func_ov001_0219b1fc(Unk0219b250 *a) {
    AdvanceModelAnimation(a->mNsbtaAnimation);
}

void func_ov001_0219b1c4(Unk0219b250 *a, s32 b, s32 c, s32 d) {
    StartModelAnimationBlend(a->mNsbtaAnimation, b);
    a->mNsbtpAnimation->mUnk_08 = c;
    func_02087cfc(a->mNsbtaAnimation, ((u16) b), (d != 0 ? UNK_02087CFC_KIND_0 : UNK_02087CFC_KIND_1));
}
