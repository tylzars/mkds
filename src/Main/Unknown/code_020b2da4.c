#include "Main/Unknown/code_020b2da4.h"
#include "Main/Unknown/code_020b2c80.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_020b41e8.h"
#include "Main/Unknown/code_020b1de4.h"

#pragma thumb on
#pragma optimize_for_size on
void func_020b2e00(u16 *a, s32 b, s32 c) {
    func_020b4428(a, b, c, 1, 1, 4);
    func_020b4428(a, b, c + 1, 1, 1, 0x24);
}

void func_020b2da4(void) {
    s32 n;
    s32 i;
    s32 b;
    u16 *p;

    n = gChoisesS->mLists[func_020b2d04()].mValueCount;
    p = (u16 *) func_020b32f8();
    if (p != NULL) {
        for (i = 0, b = 0xd - n * 2; i < n; i++) {
            func_020b2e00(p, 2, b + i * 4);
        }
        func_020b44a4(p, 0, 0, 0x20, 0x18, 0xf);
    }
}
#pragma thumb off
