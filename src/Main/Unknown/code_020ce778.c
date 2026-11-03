#include "Main/Unknown/code_020ce778.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_021189f4.h"
#include "Main/Unknown/code_0211d4a8.h"

#pragma optimize_for_size on
#pragma thumb on
void func_020ce7b8(void) {
    switch (func_02118e64()) {
        case 1:
            func_020ccc74(0x1d, 0x1f);
            break;
        case 2:
            func_020ccc74(0xc, 0x1f);
            break;
    }
}
#pragma thumb off

Unk027ffc40 *func_020ce7ac(void) {
    return (Unk027ffc40 *) 0x027ffc40;
}

u32 func_020ce784(void) {
    return func_020ce7ac()->mUnk_00 == 2 ? 1 : 0;
}

u32 func_020ce778(void) {
    return func_020ce784();
}
