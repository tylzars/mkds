#include "Main/Unknown/code_02057ca4.h"
#include "Main/Unknown/code_0204b418.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"

#pragma thumb on

void func_02057ca4(void *a) {
    u32 *v = data_021759d4->mBuffer;
    if (data_021759d4->mBackupEnabled != 0) {
        enum { K0 = 0x53444b4d } b;
        enum { K1 = 0x30315653 } c;
        MI_CpuCopy8(a, v, 0x100);
        b = K0;
        c = K1;
        v[0] = b;
        v[1] = c;
        v[2] = 0x59534b4e;
        func_0204b430(0, 0x30f00, v, 0x100, NULL, 1);
    }
}

#pragma thumb off
