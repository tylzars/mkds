#include "Main/Unknown/code_02057294.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on
void ClearEmblemRecord(void) {
    u32 value0;
    u32 fillValue;
    u32 size;
    u32 value3;
    value0 = (u32) &data_0217aa08;
    value0 = *(const u32 *) ((value0) + 0u);
    value0 = *(const u32 *) ((value0) + 4u);
    fillValue = 0u;
    size = 0x300u;
    MI_CpuFill8((void *) value0, fillValue, size);
}
#pragma thumb off

#pragma thumb on
void ClearGrandPrixRecordBlock(void) {
    u32 value0;
    u32 fillValue;
    u32 size;
    u32 value3;
    value0 = (u32) &data_0217aa08;
    value0 = *(const u32 *) ((value0) + 0u);
    value0 = *(const u32 *) ((value0) + 8u);
    fillValue = 0u;
    size = 0x400u;
    MI_CpuFill8((void *) value0, fillValue, size);
}
#pragma thumb off

#pragma thumb on
void ClearCourseTimeRecordBlock(void) {
    u32 value0;
    u32 fillValue;
    u32 size;
    u32 value3;
    value0 = (u32) &data_0217aa08;
    value0 = *(const u32 *) ((value0) + 0u);
    value0 = *(const u32 *) ((value0) + 12u);
    fillValue = 0u;
    size = 0x1600u;
    MI_CpuFill8((void *) value0, fillValue, size);
}
#pragma thumb off

#pragma thumb on
void ClearMissionRecordBlock(void) {
    u32 value0;
    u32 fillValue;
    u32 size;
    u32 value3;
    value0 = (u32) &data_0217aa08;
    value0 = *(const u32 *) ((value0) + 0u);
    value0 = *(const u32 *) ((value0) + 16u);
    fillValue = 0u;
    size = 0x100u;
    MI_CpuFill8((void *) value0, fillValue, size);
}
#pragma thumb off
