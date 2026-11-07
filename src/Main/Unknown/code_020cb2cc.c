#include "Main/Unknown/code_020cb2cc.h"

#include "Main/Unknown/code_020cb2d4.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020cb340.h"
#include "Main/Unknown/code_020cb3e4.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on

void DrawSinglePlaySelectCells(void) {
    Unk0217b43c *menu;
    func_020cb340();
    menu = data_0217b43c;
    DrawLayoutTable(menu->mSinglePlaySelectModeMBncl, menu->mSinglePlaySelectModeMNcer, NULL, menu->mMainOam,
                    menu->mUnk_93c);
    menu = data_0217b43c;
    DrawLayoutTable(menu->mSinglePlaySelectModeSBncl, menu->mSinglePlaySelectModeSNcer, NULL, menu->mSubOam,
                    menu->mUnk_948);
}

#pragma thumb off

#pragma thumb on
void func_020cb2cc(void) {
    u32 value3;
    SetupSinglePlaySelectGraphics();
}
#pragma thumb off
