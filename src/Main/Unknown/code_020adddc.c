#include "Main/Unknown/code_020adddc.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_0212a910.h"

#pragma thumb on

void RenderKartEntryNameToTexture(u32 kartIndex, void *texBuffer, u32 textValue, u32 outlineValue) {
    u16 *messageScreenCharBuffer;
    RenderKartEntryName(kartIndex);
    messageScreenCharBuffer = GetMessageScreenCharBuffer();
    PlotNibblePixels(messageScreenCharBuffer, texBuffer, textValue, outlineValue, SetPixel2Bit);
}

#pragma thumb off
