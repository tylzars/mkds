#include "Main/Unknown/code_021189cc.h"
#include "Main/Unknown/code_021189f4.h"
#include "Main/Unknown/unk_0217d000.h"

#pragma thumb on

void func_021189cc(void) {
    int v1;
    u32 v3;
    v1 = 0;
    do {
        v3 = func_021189f4(v1);
        data_0217d360->mUnk_48[v1] = v3;
        v1 = v1 + 1;
    } while (v1 < 8);
}

#pragma thumb off
