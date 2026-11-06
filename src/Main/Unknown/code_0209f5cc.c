#include "Main/Unknown/code_0209f5cc.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/unk_0217b000.h"
#include "ITCM/code_01ff8000.h"

void DrawChandelier(void *a, int b) {
    MtxFx43 *v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048(0x19, v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    SetMapObjectModelNsbcaFrameIndex((void *) (*(u32 *) &gChandelier), (u16) (*(u16 *) (b + 0xa0)));
    DrawMapObjectModel(a, ((*&gChandelier)), (void *) b);
}
