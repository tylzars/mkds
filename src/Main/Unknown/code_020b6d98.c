#include "Main/Unknown/code_020b6d98.h"
#include "Main/Unknown/code_020b41e8.h"
#include "Main/Unknown/code_020b6e00.h"
#include "Main/Unknown/code_0212a910.h"

void CopyPlayerCharacterToRaceGoalMO(void *palette, void *chars) {
    (GetMessageScreenCharBuffer());
    CopyPlayerCharacterPaletteAndChars(palette, 0xc, chars, 0x1b, 8);
}

void FillRaceSOPaletteAndChars(void *palette, void *chars) {
    RenderKartEntryNames();
    CopyRaceTransferSOAndMapSO(palette, chars);
}
