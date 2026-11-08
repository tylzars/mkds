#include "Main/Unknown/code_0202f4ac.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"

void func_0202f530(void *dest, u32 fillValue, u32 size) {
    volatile u32 value = fillValue;

    MIi_CpuClearFast(value, dest, size);
}

void func_0202f51c(void *dest, u32 size) {
    func_0202f530(dest, 0, size);
}

void func_0202f4e0(Unk02180774 *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    SetBg1Record(displaySettings->mMainBgRecords, b, c, d, e, f, g, h);
}

void func_0202f4ac(Unk02180774 *displaySettings, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    SetBg3RecordParams(displaySettings->mSubBgRecords, b, c, d, e, f, g);
}
