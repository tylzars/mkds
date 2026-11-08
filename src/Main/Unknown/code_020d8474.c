#include "Main/Unknown/code_020d8474.h"
#include "Main/Unknown/code_020d9340.h"
#include "Main/Unknown/code_020d9480.h"

void func_020d8488(SegmentPoints *arg0, Vec3 *output) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) output;
    u32 value2;
    u32 value12;
    value2 = value1;
    value1 = arg0->mUnk_00.mUnk_5c;
    func_020d9480(value0, value1, value2);
}

void func_020d8474(SegmentProgress *segmentProgress, Vec3 *output) {
    u32 value0 = (u32) segmentProgress;
    u32 value1 = (u32) output;
    u32 value2;
    u32 value12;
    value2 = value1;
    value1 = segmentProgress->mUnk_5c;
    func_020d9340(value0, value1, value2);
}
