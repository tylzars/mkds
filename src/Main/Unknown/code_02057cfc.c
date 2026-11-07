#include "Main/Unknown/code_02057cfc.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"

#pragma thumb on
void CopyBackupReadToBlock(u32 buffer, u32 length) {
    u32 source = buffer;
    u32 value1 = length;
    u32 size;
    u32 value3;
    size = (value1) + (0u);
    value1 = (u32) &data_021759d4;
    value1 = *(const u32 *) ((value1) + 0u);
    value1 = *(const u32 *) ((value1) + 104u);
    MI_CpuCopy8((const void *) source, (void *) value1, size);
}
#pragma thumb off
