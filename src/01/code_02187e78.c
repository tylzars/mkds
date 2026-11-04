#include "01/code_02187e78.h"
#include "01/code_02188950.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"

void func_ov001_02187e78(Unk02188950 *a) {
    int v1;

    if (a->mUnk_148 < gCourseMap->mEntryGroupCount) {
        v1 = a->mUnk_14c + 1;
        if (v1 >= gCourseMap->mEntryGroups[(u16) a->mUnk_148].mEntryCount) {
            v1 = 0;
        }
        a->mUnk_14c = v1;
    }
}
