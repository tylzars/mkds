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

void IncrementEntryIndex(Unk02188950 *mapObject) {
    int nextEntryIndex;

    if (mapObject->mEntryGroupIndex < gCourseMap->mEntryGroupCount) {
        nextEntryIndex = mapObject->mEntryIndex + 1;
        if (nextEntryIndex >= gCourseMap->mEntryGroups[(u16) mapObject->mEntryGroupIndex].mEntryCount) {
            nextEntryIndex = 0;
        }
        mapObject->mEntryIndex = nextEntryIndex;
    }
}
