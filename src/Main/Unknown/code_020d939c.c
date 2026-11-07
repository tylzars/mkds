#include "Main/Unknown/code_020d939c.h"
#include "Main/Unknown/code_020d94dc.h"

void func_020d939c(Unk020e0144_00_0 *segment, s32 fraction, s32 scale, Vec3 *firstResult, Vec3 *secondResult) {
    s32 firstWeight0;
    s32 firstWeight1;
    s32 firstWeight2;
    s32 firstWeight3;
    s32 secondWeight0;
    s32 secondWeight1;
    s32 secondWeight2;
    s32 secondWeight3;
    func_020d970c(fraction, &firstWeight0, &firstWeight1, &firstWeight2, &firstWeight3, &secondWeight0, &secondWeight1,
                  &secondWeight2, &secondWeight3);
    func_020d95c0(segment->mUnk_00, firstResult, firstWeight0, firstWeight1, firstWeight2, firstWeight3);
    func_020d95c0(segment->mUnk_00, secondResult, secondWeight0, secondWeight1, secondWeight2, secondWeight3);
    secondResult->x = ((s64) secondResult->x * scale) >> 24;
    secondResult->y = ((s64) secondResult->y * scale) >> 24;
    secondResult->z = ((s64) secondResult->z * scale) >> 24;
}
