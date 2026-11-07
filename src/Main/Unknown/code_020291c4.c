#include "Main/Unknown/code_020291c4.h"
#include "code_0201ea58.h"

s32 FindRectContainingPoint(u32 x, u32 y, Unk0201ea30 *rects) {
    return RectTableFindContaining(rects, x, y);
}
