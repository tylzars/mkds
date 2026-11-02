#include "Main/Unknown/code_020ca6c4.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020caba4.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ca820.h"
#include "Main/Unknown/unk_0217b000.h"

void func_020ca808(Unk02180728 *a, void *b, void *c, s32 d, s32 e) {
    a->mUnk_00 = b;
    a->mUnk_04 = c;
    a->mUnk_08 = d;
    a->mUnk_0c = e;
}

u32 func_020ca7e0(Unk02180728 *a, s32 b, s32 c, u32 d, u32 e, void *f) {
    return func_02024340(a, b, c, d, e, f);
}

#pragma thumb on
#pragma optimize_for_size on
void InitEmblemChoises(void) {
    Unk0217b438 *p;

    gEmblemChoises = func_02036bec(func_020ca820(), 0x6c);
    gEmblemChoises->mUnk_00 = 0;
    gEmblemChoises->mUnk_04 = 1;
    gEmblemChoises->mUnk_08 = 0;
    gEmblemChoises->mUnk_0c = 0;
    func_020cac9c();
    gEmblemChoises->mUnk_24 = 0;
    gEmblemChoises->mUnk_10 = 0;
    gEmblemChoises->mUnk_14 = 0;
    gEmblemChoises->mUnk_18 = 0;
    gEmblemChoises->mChoisesCount = 3;
    LoadNclrData(&gEmblemChoises->mChoisesSBNclr, FindSceneFileWrapper("choises_s_b.NCLR"));
    LoadNcgrData(&gEmblemChoises->mChoisesSBNcgr, FindSceneFileWrapper("choises_s_b.NCGR"));
    LoadNscrData(&gEmblemChoises->mChoisesS3Nscr, FindSceneFileWrapper("choises_s_3.NSCR"));
    gEmblemChoises->mUnk_2c = func_020b403c(2);
    func_02023408(&gEmblemChoises->mUnk_30, gEmblemChoises->mChoisesSBNcgr->mUnk_14, 0x20, 0xc, 4);
    p = gEmblemChoises;
    func_020ca808(&p->mUnk_50, &p->mUnk_30, p->mUnk_2c, func_020b4acc(), 0);
    {
        s32 bmgIndices[3] = {2, 0, 1};
        s32 i;

        for (i = 0; i < gEmblemChoises->mChoisesCount; i++) {
            func_020ca7e0(&gEmblemChoises->mUnk_50, 0x90, i * 16 + 9, 12, 0x412,
                          GetBmgEntry(FindSceneFileWrapper("emblem.bmg"), bmgIndices[i]));
        }
    }
}
#pragma thumb off
