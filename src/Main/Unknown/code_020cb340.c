#include "Main/Unknown/code_020cb340.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void func_020cb340(void) {
    Unk02124b1c *subCells;
    s32 selectedIndex;
    s32 i;

    subCells = data_0217b43c->mUnk_948;
    selectedIndex = data_0217b43c->mUnk_930;
    for (i = 0; i <= 9; i++) {
        subCells[i].mUnk_00 = 1;
    }
    for (i = 10; i <= 14; i++) {
        subCells[i].mUnk_00 = 0;
    }
    if (GetMenuScreenNumber() != 3 || data_0217b43c->mUnk_934 == FALSE || GetFramesSinceMenuScreenSwitch() >= 5) {
        subCells[selectedIndex + 5].mUnk_00 = 0;
        subCells[selectedIndex + 10].mUnk_00 = 1;
    }
    if (data_0217b43c->mScreenNumber == 3) {
        subCells[selectedIndex].mUnk_04 = data_0217b43c->mUnk_938;
        subCells[selectedIndex + 5].mUnk_04 = data_0217b43c->mUnk_938;
        subCells[selectedIndex + 10].mUnk_04 = data_0217b43c->mUnk_938;
    }
}
