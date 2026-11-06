#include "Main/Unknown/code_020add18.h"
#include "Main/Unknown/code_020add50.h"
#include "code_02022aa8.h"

void func_020add18(u32 *a, Unk02022aa8 *b, u32 c) {
    u32 v1;
    v1 = (u32) NNS_G2dFontGetCharWidthsFromIndex(b, c);
    *a = v1;
    v1 = func_020add50(b, c);
    a[1] = v1;
}
