#include "Main/Unknown/code_020ca9e4.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020caae8.h"
#include "Main/Unknown/code_020caaac.h"
#include "Main/Unknown/code_020cab58.h"
#include "Main/Unknown/code_020cab74.h"
#include "Main/Unknown/code_020b4000.h"
#include "code_0214b824.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void DrawEmblemChoises(void) {
    if (gEmblemChoises->mUnk_08 != FALSE) {
        GXS_LoadBGPltt(gEmblemChoises->mChoisesSBNclr->mData + 0xe0, 0x1c0, 0x40);
        GXS_LoadBG0Char(gEmblemChoises->mChoisesSBNcgr->mData, 0, 0x3000);
        gEmblemChoises->mUnk_08 = FALSE;
    }
    if (gEmblemChoises->mUnk_00 != 0) {
        GXS_LoadBG0Scr(gEmblemChoises->mChoisesS3Nscr->mData, 0, 0x600);
    }
    if (gEmblemChoises->mUnk_00 != gEmblemChoises->mUnk_04) {
        if (gEmblemChoises->mUnk_00 != 0) {
            func_020cab58(func_020cab74() | 1);
            func_020cab2c(0, 0);
            func_020caae8(0x3e, 0x3f, 8, 8, -7);
        } else {
            func_020cab58(func_020cab74() & ~1);
            if (gEmblemChoises->mUnk_0c != NULL) {
                gEmblemChoises->mUnk_0c();
            } else {
                func_020caaac(0, 0, 6, 10);
            }
        }
    }
    gEmblemChoises->mUnk_04 = gEmblemChoises->mUnk_00;
}
#pragma thumb off
