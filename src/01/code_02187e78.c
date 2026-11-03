#include "01/code_02187e78.h"
#include "01/code_02188950.h"
#include "Main/Unknown/code_020b502c.h"

void func_ov001_02187e78(Unk02188950 *a) {
    int v1;

    if (a->mUnk_148 < gCourseMap->mUnk_0c) {
        v1 = a->mUnk_14c + 1;
        if (v1 >= gCourseMap->mUnk_08[(u16) a->mUnk_148].mUnk_02) {
            v1 = 0;
        }
        a->mUnk_14c = v1;
    }
}
