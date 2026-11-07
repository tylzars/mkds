#include "Main/Unknown/code_020add50.h"
#include "Main/Unknown/code_020add80.h"
#include "code_02022aa8.h"

int GetFontGlyphImage(Unk02022aa8 *font, int glyphIndex) {
    u32 value0 = (u32) font;
    u32 value1 = glyphIndex;
    u32 indexCopy;
    u32 fontCopy;
    fontCopy = value0;
    indexCopy = value1;
    value0 = GetFontGlyphImageStride(font);
    value1 = *(const u32 *) ((fontCopy) + (0));
    value1 = *(const u32 *) ((value1) + (8));
    value1 = (value1) + (8u);
    value0 = (indexCopy) * (value0) + (value1);
    return value0;
}
