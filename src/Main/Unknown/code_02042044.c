#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_02042064.h"

CourseMapGroupEntry *GetCourseMapGroupEntry(u16 groupIndex, u16 entryIndex) {
    return GetCourseMapEntryGroupTableRow(groupIndex)->mEntries + entryIndex;
}
