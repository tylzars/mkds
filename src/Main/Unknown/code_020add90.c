#include "Main/Unknown/code_020add90.h"
#include "code_02022aa8.h"
#include "code_0214cfe4.h"

void FillHalfwords(void *destination, u16 value, s32 size) {
    volatile u16 valueCopy = value;

    MIi_CpuClear16(valueCopy, destination, size);
}

u32 GetFontGlyphIndex(Unk02022aa8 *font, u32 code) {
    u32 glyphIndex;

    glyphIndex = NNS_G2dFontFindGlyphIndex(font, code);
    if (glyphIndex == 0xffff) {
        glyphIndex = font->mUnk_00->mUnk_02;
    }
    return glyphIndex;
}
