#include "Main/Unknown/code_0209f5cc.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/unk_0217b000.h"
#include "ITCM/code_01ff8000.h"

void DrawChandelier(void *a, Unk0209f1c8 *b) {
    MtxFx43 *v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048(0x14, &v2, 1);
    v1 = func_020e6cbc(&b->mUnk_00.mPos);
    func_01ff9048(0x19, v1, 0xc);
    func_01ff9048(0x1b, &b->mUnk_00.mScale, 3);
    SetMapObjectModelNsbcaFrameIndex(gChandelier, b->mUnk_a0);
    DrawMapObjectModel(a, gChandelier, b);
}
