#include "Main/Unknown/code_021519a8.h"
#include "Main/Unknown/unk_02180000.h"
#include "code_021510a4.h"

#pragma thumb on

u32 func_021519a8(void *a) {
    int v1;
    v1 = readNvram((u32) ((*(u32 *) &data_0218049c)), (u32) (((u32) 0x00000300u)), a);
    if (v1 != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off
