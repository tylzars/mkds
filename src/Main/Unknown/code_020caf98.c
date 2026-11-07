#include "Main/Unknown/code_020caf98.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020291c4.h"
#include "Main/Unknown/code_020cb0cc.h"
#include "Main/Unknown/code_020cb0f4.h"
#include "Main/Unknown/code_020cb11c.h"
#include "Main/Unknown/code_020cb1cc.h"
#include "Main/Unknown/code_020cb1f4.h"
#include "Main/Unknown/code_020cb224.h"
#include "Main/Unknown/code_020cb2d4.h"
#include "Main/Unknown/code_020cc000.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void UpdateSinglePlaySelectInput(s32 a) {
    u32 v;
    u32 pairX;
    s32 touchedIndex;
    s32 previousSelected;
    Unk0217b43c *menu;

    if (a != 0) {
        v = func_020cb224();
        if (func_020cb1f4(v, PAD_KEY_A)) {
            func_020ccc74(3, 0x1f);
            func_020cb1cc(5);
            data_0217b43c->mUnk_934 = TRUE;
        } else if (func_020cb1f4(v, PAD_KEY_B)) {
            func_020ccc74(2, 0x1b);
            RequestSelectReturnState3WithSound(1);
        } else if (GetNewOrRepeatBits(v, PAD_KEY_UP)) {
            menu = data_0217b43c;
            menu->mUnk_930 = (menu->mUnk_930 + 4) % 5;
            StartSoundOncePerFrame(0);
        } else if (GetNewOrRepeatBits(v, PAD_KEY_DOWN)) {
            menu = data_0217b43c;
            menu->mUnk_930 = (menu->mUnk_930 + 6) % 5;
            StartSoundOncePerFrame(0);
        } else if (func_020cb11c(v)) {
            pairX = func_020cb0f4(v);
            v = func_020cb0cc(v);
            touchedIndex = FindRectContainingPoint(pairX, v, data_0217b43c->mSinglePlaySelectModeSBnbl);
            menu = data_0217b43c;
            previousSelected = menu->mUnk_930;
            if (touchedIndex != -1) {
                if (previousSelected == touchedIndex) {
                    menu->mUnk_934 = TRUE;
                }
                data_0217b43c->mUnk_930 = touchedIndex;
                func_020ccc74(3, 0x1f);
                func_020cb1cc(5);
            } else if (IsSelectReturnState2NoState3Or4RequestAndInRect(pairX, v)) {
                func_020ccc74(2, 0x1b);
                RequestSelectReturnState3WithSound(1);
            }
        }
    }
    DrawSinglePlaySelectCells();
}
