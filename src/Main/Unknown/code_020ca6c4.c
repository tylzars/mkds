#include "Main/Unknown/code_020ca6c4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020caba4.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ca820.h"
#include "Main/Unknown/unk_0217b000.h"
#include "g2d_CharCanvas.h"

void func_020ca808(Unk02180728 *textCanvas, void *charCanvas, void *c, s32 d, s32 e) {
    textCanvas->mUnk_00 = charCanvas;
    textCanvas->mUnk_04 = c;
    textCanvas->mUnk_08 = d;
    textCanvas->mUnk_0c = e;
}

u32 func_020ca7e0(Unk02180728 *textCanvas, s32 x, s32 y, u32 d, u32 e, void *text) {
    return NNSi_G2dTextCanvasDrawText(textCanvas, x, y, d, e, text);
}

#pragma thumb on
#pragma optimize_for_size on
void InitEmblemChoises(void) {
    EmblemChoises *emblemChoises;

    gEmblemChoises = HeapAlloc(func_020ca820(), 0x6c);
    gEmblemChoises->mShown = 0;
    gEmblemChoises->mUnk_04 = 1;
    gEmblemChoises->mGraphicsUploadRequested = FALSE;
    gEmblemChoises->mUnk_0c = NULL;
    ResetEmblemChoisesState();
    gEmblemChoises->mUnk_24 = 0;
    gEmblemChoises->mUnk_10 = FALSE;
    gEmblemChoises->mUnk_14 = 0;
    gEmblemChoises->mUnk_18 = 0;
    gEmblemChoises->mChoisesCount = 3;
    LoadNclrData(&gEmblemChoises->mChoisesSBNclr, FindSceneFileWrapper("choises_s_b.NCLR"));
    LoadNcgrData(&gEmblemChoises->mChoisesSBNcgr, FindSceneFileWrapper("choises_s_b.NCGR"));
    LoadNscrData(&gEmblemChoises->mChoisesS3Nscr, FindSceneFileWrapper("choises_s_3.NSCR"));
    gEmblemChoises->mUnk_2c = func_020b403c(2);
    NNS_G2dCharCanvasInitForBG(&gEmblemChoises->mUnk_30, gEmblemChoises->mChoisesSBNcgr->mData, 0x20, 0xc, 4);
    emblemChoises = gEmblemChoises;
    func_020ca808(&emblemChoises->mUnk_50, &emblemChoises->mUnk_30, emblemChoises->mUnk_2c, func_020b4acc(), 0);
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
