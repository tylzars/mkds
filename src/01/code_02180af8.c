#include "01/code_02180af8.h"

#pragma thumb off

void ClearCharCanvas(u8 *charCanvas, u32 color) {
    u32 clearFunction = (*(u32 *) (((u32) charCanvas) + (24)));
    u32 v3 = ((u32(*)(u32, u32))(clearFunction))((u32) charCanvas, color);
}

#pragma thumb on
