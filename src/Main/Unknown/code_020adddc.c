#include "Main/Unknown/code_020adddc.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_0212a910.h"

#pragma thumb on

void func_020adddc(u32 a, void *b, u32 c, u32 d) {
    u16 *v1;
    RenderKartEntryName(a);
    v1 = GetMessageScreenCharBuffer();
    PlotNibblePixels(v1, b, c, d, SetPixel2Bit);
}

#pragma thumb off
