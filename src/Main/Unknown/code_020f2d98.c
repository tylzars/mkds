#include "Main/Unknown/code_020f2d98.h"
#include "Main/Unknown/code_020f2dac.h"

void func_020f2d98(u32 p0, u32 p1) {
    *(u32 *) ((u8 *) p0 + 300) = p1;
    *(u32 *) ((u8 *) p0 + 292) = (u32) (((u32) (&func_020f2dac)));
}
