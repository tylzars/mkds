#include "Main/Unknown/code_0203b69c.h"

u32 GetMissionTableRowCount(u32 table) {
    return (*OFFSET_PTR(const u16, table, 4));
}

u32 GetMissionTableColumnCount(u32 table) {
    return (*OFFSET_PTR(const u16, table, 6));
}
