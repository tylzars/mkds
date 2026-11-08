#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_020ad000.h"
#include "Main/Unknown/code_0214d000.h"
#include "g2d_CharCanvas.h"
#include "code_0214cfe4.h"
#include "code_02022aa8.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_02175000.h"
#include "01/code_021804e0.h"
#include "01/code_021a5140.h"
#include "code_0214d018.h"
#include "registers.h"

#pragma thumb on

void DrawTextInRect(LabelTextCanvas *textCanvas, s32 left, s32 top, s32 width, s32 height, s32 color, s32 alignFlags,
                    s32 lineAlign, void *text, s32 fixedDigitsOnly, s8 fixedAdvance, s32 l) {
    s32 maxWidth;
    s32 textHeight;
    s32 lineWidths[20];
    u16 expandedText[500];

    func_021253f8(textCanvas, &maxWidth, lineWidths, &textHeight, text, expandedText, fixedDigitsOnly,
                  (s32) fixedAdvance);
    DrawTextLines(textCanvas, maxWidth, lineWidths, textHeight, left, top, width, height, color, alignFlags, lineAlign,
                  expandedText, fixedDigitsOnly, fixedAdvance, l);
}

void func_0212583c(void *textCanvas, u32 left, u32 top, u32 width, u32 height, u32 color, u32 alignFlags, u32 lineAlign,
                   void *text) {
    DrawTextInRect(textCanvas, left, top, width, height, color, alignFlags, lineAlign, text, 0, -1, 0);
}

void func_02125808(LabelTextCanvas *textCanvas, s32 left, s32 top, s32 width, s32 height, u32 color, u32 alignFlags,
                   u32 lineAlign, void *text, s32 fixedDigitsOnly, s8 fixedAdvance) {
    DrawTextInRect(textCanvas, left, top, width, height, color, alignFlags, lineAlign, text, fixedDigitsOnly,
                   fixedAdvance, 0);
}

void func_021257d8(void *textCanvas, u32 left, u32 top, u32 width, u32 height, u32 color, u32 alignFlags, u32 lineAlign,
                   void *text) {
    DrawTextInRect(textCanvas, left, top, width, height, color, alignFlags, lineAlign, text, 0, -1, 1);
}

void func_021253f8(LabelTextCanvas *textCanvas, s32 *maxWidth, s32 *lineWidths, s32 *textHeight, void *text,
                   u16 *expandedText, s32 fixedDigitsOnly, s32 fixedAdvance) {
    s32 lineHeight;
    s32 charSpacing;
    s32 lineIndex;
    s32 tagSize;
    s32 n1;
    s32 n2;
    s32 fixedAdvanceWithSpacing;
    s32 i2;
    s32 i1;
    u8 *readPointer;
    u16 buf1[10];
    u16 buf2[10];
    Unk02022aa8 *font;
    u16 charCode;
    s32 variant;
    s32 r7;
    u32 glyphIndex;
    u16 ch;
    NNSG2dCharWidths *charWidths;
    s32 *lineWidthPointer;
    u16 *writePointer;

    lineIndex = 0;
    charSpacing = textCanvas->mCharSpacing;
    font = textCanvas->mFont;
    lineHeight = textCanvas->mLineSpacing + font->mUnk_00->mUnk_01;
    readPointer = text;
    writePointer = expandedText;
    *maxWidth = ~lineIndex;
    *lineWidths = lineIndex;
    *textHeight = font->mUnk_00->mUnk_01;
    charCode = font->mUnk_04(&readPointer);
    if (charCode != 0) {
        lineWidthPointer = lineWidths;
        fixedAdvanceWithSpacing = fixedAdvance + charSpacing;
        do {
            if (charCode == 0x1a) {
                tagSize = ((TextTag *) readPointer)->mSize;
                variant = ((TextTag *) readPointer)->mVariant;
                switch (((TextTag *) readPointer)->mKind) {
                    case 0:
                        break;
                    case 1:
                        switch (variant) {
                            case 0:
                                for (r7 = 0; r7 < 10; r7++) {
                                    ch = ((u16 *) data_0217aa08->mFirstBlock->mPlayerName)[r7];
                                    if (ch == 0) {
                                        r7 = 10;
                                    } else {
                                        *writePointer++ = ch;
                                        if (fixedAdvance == -1 || (fixedDigitsOnly != 0 && !func_021253f8_inline(ch))) {
                                            glyphIndex = NNS_G2dFontFindGlyphIndex(font, ch);
                                            if (glyphIndex == 0xffff) {
                                                glyphIndex = font->mUnk_00->mUnk_02;
                                            }
                                            charWidths = NNS_G2dFontGetCharWidthsFromIndex(font, glyphIndex);
                                            *lineWidthPointer += charWidths->mCharWidth + charSpacing;
                                        } else {
                                            *lineWidthPointer += fixedAdvanceWithSpacing;
                                        }
                                    }
                                }
                                break;
                            case 1:
                                n1 = CopyTextWithinWidth((u16 *) data_0217aa08->mFirstBlock->mPlayerName, buf1);
                                for (i1 = 0; i1 < n1; i1++) {
                                    *writePointer++ = buf1[i1];
                                    if (fixedAdvance == -1 ||
                                        (fixedDigitsOnly != 0 && !func_021253f8_inline(buf1[i1]))) {
                                        glyphIndex = NNS_G2dFontFindGlyphIndex(font, buf1[i1]);
                                        if (glyphIndex == 0xffff) {
                                            glyphIndex = font->mUnk_00->mUnk_02;
                                        }
                                        charWidths = NNS_G2dFontGetCharWidthsFromIndex(font, glyphIndex);
                                        *lineWidthPointer += charWidths->mCharWidth + charSpacing;
                                    } else {
                                        *lineWidthPointer += fixedAdvanceWithSpacing;
                                    }
                                }
                            case 10:
                                for (r7 = 0; r7 < 10; r7++) {
                                    ch = ((u16 *) data_021759d0->mOwnerText)[r7];
                                    if (ch == 0) {
                                        r7 = 10;
                                    } else {
                                        *writePointer++ = ch;
                                        if (fixedAdvance == -1 || (fixedDigitsOnly != 0 && !func_021253f8_inline(ch))) {
                                            glyphIndex = NNS_G2dFontFindGlyphIndex(font, ch);
                                            if (glyphIndex == 0xffff) {
                                                glyphIndex = font->mUnk_00->mUnk_02;
                                            }
                                            charWidths = NNS_G2dFontGetCharWidthsFromIndex(font, glyphIndex);
                                            *lineWidthPointer += charWidths->mCharWidth + charSpacing;
                                        } else {
                                            *lineWidthPointer += fixedAdvanceWithSpacing;
                                        }
                                    }
                                }
                                break;
                            case 11:
                                n2 = CopyTextWithinWidth((u16 *) data_021759d0->mOwnerText, buf2);
                                for (i2 = 0; i2 < n2; i2++) {
                                    *writePointer++ = buf2[i2];
                                    if (fixedAdvance == -1 ||
                                        (fixedDigitsOnly != 0 && !func_021253f8_inline(buf2[i2]))) {
                                        glyphIndex = NNS_G2dFontFindGlyphIndex(font, buf2[i2]);
                                        if (glyphIndex == 0xffff) {
                                            glyphIndex = font->mUnk_00->mUnk_02;
                                        }
                                        charWidths = NNS_G2dFontGetCharWidthsFromIndex(font, glyphIndex);
                                        *lineWidthPointer += charWidths->mCharWidth + charSpacing;
                                    } else {
                                        *lineWidthPointer += fixedAdvanceWithSpacing;
                                    }
                                }
                                break;
                        }
                        break;
                    case 0xff:
                        if (variant == 0) {
                            MI_CpuCopy8(readPointer - 2, writePointer, tagSize);
                            writePointer += tagSize >> 1;
                        }
                        break;
                }
                readPointer = readPointer + tagSize - 2;
            } else {
                *writePointer++ = charCode;
                if (charCode == 0xa) {
                    *textHeight += lineHeight;
                    if (*maxWidth < *lineWidthPointer) {
                        *maxWidth = *lineWidthPointer;
                    }
                    lineWidthPointer++;
                    lineIndex++;
                    *lineWidthPointer = 0;
                } else {
                    r7 = charSpacing;
                    if (*(u16 *) readPointer == 0 || *(u16 *) readPointer == 0xa) {
                        r7 = 0;
                    }
                    if (fixedAdvance == -1 || (fixedDigitsOnly != 0 && !func_021253f8_inline(charCode))) {
                        glyphIndex = NNS_G2dFontFindGlyphIndex(font, charCode);
                        if (glyphIndex == 0xffff) {
                            glyphIndex = font->mUnk_00->mUnk_02;
                        }
                        charWidths = NNS_G2dFontGetCharWidthsFromIndex(font, glyphIndex);
                        *lineWidthPointer += charWidths->mCharWidth + r7;
                    } else {
                        *lineWidthPointer += fixedAdvance + r7;
                    }
                }
            }
        } while ((charCode = font->mUnk_04(&readPointer)) != 0);
    }
    *writePointer = 0;
    if (*maxWidth < lineWidths[lineIndex]) {
        *maxWidth = lineWidths[lineIndex];
    }
}

s32 GetTextLineOffset(u32 alignFlags, s32 lineAlign, s32 rectWidth, s32 textWidth, s32 lineWidth) {
    s32 offset;

    offset = 0;
    if (alignFlags & 0x400) {
        offset += (rectWidth - textWidth) >> 1;
    } else if (alignFlags & 0x800) {
        offset += rectWidth - textWidth;
    }
    if (lineAlign == 1) {
        offset += (textWidth - lineWidth) >> 1;
    } else if (lineAlign == 2) {
        offset += textWidth - lineWidth;
    }
    return offset;
}

void DrawTextLines(LabelTextCanvas *textCanvas, s32 textWidth, s32 *lineWidths, s32 textHeight, s32 left, s32 top,
                   s32 width, s32 height, s32 color, u32 alignFlags, s32 lineAlign, void *text, s32 fixedDigitsOnly,
                   s32 fixedAdvance, s32 o) {
    s32 x;
    s32 y;
    s32 lineAdvance;
    s32 charSpacing;
    Unk02022aa8 *font;
    s32 bottom;
    s32 right;
    NNSG2dCharWidths *charWidths;
    u16 charCode;
    u8 tagSize;
    u16 variant;
    u8 kind;
    u8 colorValue;
    u32 glyphIndex;
    u8 *readPointer;

    x = left;
    y = top;
    charSpacing = textCanvas->mCharSpacing;
    font = textCanvas->mFont;
    lineAdvance = textCanvas->mLineSpacing + font->mUnk_00->mUnk_01;
    readPointer = text;
    x += GetTextLineOffset(alignFlags, lineAlign, width, textWidth, *lineWidths);
    if (x < 0) {
        return;
    }
    if (alignFlags & 0x80) {
        y += (height - textHeight) >> 1;
    } else if (alignFlags & 0x100) {
        y += height - textHeight;
    }
    if (y < 0) {
        return;
    }
    charCode = font->mUnk_04(&readPointer);
    if (charCode == 0) {
        return;
    }
    bottom = top + height;
    right = left + width;
    do {
        if (charCode == 0x1a) {
            tagSize = ((TextTag *) readPointer)->mSize;
            variant = ((TextTag *) readPointer)->mVariant;
            kind = ((TextTag *) readPointer)->mKind;
            if (kind == 0xff && variant == 0) {
                colorValue = ((TextTag *) readPointer)->mUnk_04;
                if (o != 0) {
                    if (colorValue == 0) {
                        color = 2;
                    } else {
                        color = colorValue * 2 + 1;
                    }
                } else {
                    color = colorValue * 2 + 1;
                }
            }
            readPointer = readPointer + tagSize - 2;
        } else if (charCode == 0xa) {
            y += lineAdvance;
            lineWidths++;
            if (y >= bottom) {
                return;
            }
            x = left + GetTextLineOffset(alignFlags, lineAlign, width, textWidth, *lineWidths);
            if (x < 0) {
                return;
            }
        } else {
            if (fixedAdvance == -1 || (fixedDigitsOnly != 0 && !func_021253f8_inline(charCode))) {
                x += NNS_G2dCharCanvasDrawChar((Unk02023374 *) textCanvas->mCharCanvas, textCanvas->mFont, x, y, color,
                                               charCode);
            } else {
                glyphIndex = NNS_G2dFontFindGlyphIndex(font, charCode);
                if (glyphIndex == 0xffff) {
                    glyphIndex = font->mUnk_00->mUnk_02;
                }
                charWidths = NNS_G2dFontGetCharWidthsFromIndex(font, glyphIndex);
                x += (fixedAdvance - charWidths->mCharWidth) >> 1;
                NNS_G2dCharCanvasDrawChar((Unk02023374 *) textCanvas->mCharCanvas, textCanvas->mFont, x, y, color,
                                          charCode);
                x += fixedAdvance - ((fixedAdvance - charWidths->mCharWidth) >> 1);
            }
            if (x > right) {
                return;
            }
            x += charSpacing;
        }
    } while ((charCode = font->mUnk_04(&readPointer)) != 0);
}

void FormatMessageWithText(u16 *insertText, u16 *message, u16 *formattedText, u32 d) {
    s32 length;
    s32 tagSize;
    u16 *writePointer;
    u16 halfword;

    length = 0;
    while (*message != 0x1a || ((Unk0212513c *) message)->mUnk_03 != 1 || ((Unk0212513c *) message)->mUnk_04 != 0xff) {
        formattedText[length] = *message;
        length++;
        message++;
    }
    message += ((Unk0212513c *) message)->mUnk_02 >> 1;
    if (*insertText != 0) {
        writePointer = formattedText + length;
        do {
            *writePointer++ = ((Unk0212513c *) insertText)->mUnk_00;
            length++;
            insertText++;
        } while (*insertText != 0);
    }
    while ((halfword = *message) != 0) {
        if (halfword == 0x1a) {
            tagSize = ((Unk0212513c *) message)->mUnk_02;
            MIi_CpuCopy16(message, formattedText + length, tagSize);
            message += tagSize >> 1;
            length += tagSize >> 1;
        } else {
            formattedText[length] = halfword;
            length++;
            message++;
        }
    }
    formattedText[length] = 0;
}

void *func_021250b0(void *heap) {
    DisplaySettingsDesc desc = {1, 0x12, 0x18, 1, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 4, 0x100, 0, 0, 8, 0};
    Unk02180774 *displaySettings;

    displaySettings = CreateDisplaySettings(heap, &desc);
    SetBg1Record(displaySettings->mMainBgRecords, 0, 0, 0, 0, 0x12, 2, 0);
    SetBg3RecordParams(displaySettings->mSubBgRecords, 1, 0, 0, 0, 0x10, 4);
    InitDisplayFromSettings(displaySettings);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | 0x10;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | 0x10;
    return displaySettings;
}

void *func_02125028(void *heap) {
    DisplaySettingsDesc desc = {1, 0x13, 0x18, 1, 0, 1, 0, 4, 0x60, 0, 0, 3, 0x10, 0, 0x80, 0x100, 0, 0, 8, 0};
    Unk02180774 *displaySettings;

    displaySettings = CreateDisplaySettings(heap, &desc);
    SetBg1Record(displaySettings->mMainBgRecords, 0, 0, 0, 0, 0x12, 2, 0);
    SetBg3RecordParams(displaySettings->mSubBgRecords, 1, 0, 0, 0, 0xf, 0);
    InitDisplayFromSettings(displaySettings);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | 0x10;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | 0x10;
    return displaySettings;
}

s32 CountDecimalDigits(u32 a) {
    s32 i;
    s32 digitCount;

    digitCount = 1;
    for (i = 0; i < 10; i++) {
        a = a / 10;
        if (a == 0) {
            break;
        }
        digitCount++;
    }
    return digitCount;
}

s32 FormatAsciiNumber(u32 a, u16 *buffer) {
    s32 digitCount;
    s32 i;
    digitCount = CountDecimalDigits(a);
    for (i = 0; i < digitCount; i++) {
        *(buffer + digitCount - i - 1) = (u16) (a % 10) + 0x30;
        a = a / 10;
    }
    buffer[digitCount] = 0;
    return digitCount;
}

s32 func_02124f4c(u32 a, u16 *buffer) {
    s32 digitCount;
    s32 i;
    digitCount = CountDecimalDigits(a);
    for (i = 0; i < digitCount; i++) {
        *(buffer + digitCount - i - 1) = (u16) (a % 10) + 0xff10;
        a = a / 10;
    }
    buffer[digitCount] = 0;
    return digitCount;
}

#pragma thumb off
