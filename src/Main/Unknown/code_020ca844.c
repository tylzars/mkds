#include "Main/Unknown/code_020ca844.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020caba4.h"
#include "Main/Unknown/code_020ca984.h"
#include "Main/Unknown/code_020ca9ac.h"
#include "Main/Unknown/code_020ca9dc.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void UpdateEmblemChoises(void) {
    gEmblemChoises->mUnk_24++;
    if (gEmblemChoises->mUnk_24 >= 0x32) {
        gEmblemChoises->mUnk_24 = 0;
    }
    if (gEmblemChoises->mUnk_14 == 0 && gEmblemChoises->mUnk_18 == 0 && gEmblemChoises->mShown != 0 &&
        gEmblemChoises->mUnk_04 != 0) {
        if (func_020cacc0()) {
            gEmblemChoises->mUnk_14 = 1;
        } else if (func_020ca9ac(GetEmblemChoisesInputSlot(), PAD_KEY_A)) {
            gEmblemChoises->mUnk_14 = 1;
            gEmblemChoises->mUnk_10 = TRUE;
            switch (gEmblemChoises->mChoisesIndex) {
                case 0:
                    StartEmblemChoisesSound(0x10);
                    break;
                case 1:
                    StartEmblemChoisesSound(0xb);
                    break;
                case 2:
                    StartEmblemChoisesSound(5);
                    break;
            }
        } else if (func_020ca9ac(GetEmblemChoisesInputSlot(), PAD_KEY_B | PAD_KEY_START)) {
            gEmblemChoises->mUnk_18 = 1;
            StartEmblemChoisesSound(0x10);
        }
        if (func_020ca9ac(GetEmblemChoisesInputSlot(), PAD_KEY_UP)) {
            MoveEmblemChoisesIndex(-1);
        } else if (func_020ca9ac(GetEmblemChoisesInputSlot(), PAD_KEY_DOWN)) {
            MoveEmblemChoisesIndex(1);
        }
    }
    if (gEmblemChoises->mUnk_14 != 0) {
        gEmblemChoises->mUnk_14++;
        if (gEmblemChoises->mUnk_14 > 0xf) {
            if (gEmblemChoises->mShown != 0) {
                gEmblemChoises->mResult = gEmblemChoises->mChoisesIndex;
                gEmblemChoises->mUnk_14 = 0;
            }
            gEmblemChoises->mUnk_14 = 0;
            gEmblemChoises->mUnk_10 = FALSE;
        }
    }
    if (gEmblemChoises->mUnk_18 != 0) {
        gEmblemChoises->mUnk_18++;
        if (gEmblemChoises->mUnk_18 > 4) {
            if (gEmblemChoises->mShown != 0) {
                gEmblemChoises->mResult = -2;
                gEmblemChoises->mUnk_14 = 0;
            }
            gEmblemChoises->mUnk_18 = 0;
        }
    }
}
#pragma thumb off
