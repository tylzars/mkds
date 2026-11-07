#include "Main/Unknown/code_020add18.h"
#include "Main/Unknown/code_020add50.h"
#include "code_02022aa8.h"

void GetFontGlyph(u32 *glyph, Unk02022aa8 *font, u32 glyphIndex) {
    u32 v1;
    v1 = (u32) NNS_G2dFontGetCharWidthsFromIndex(font, glyphIndex);
    *glyph = v1;
    v1 = GetFontGlyphImage(font, glyphIndex);
    glyph[1] = v1;
}
