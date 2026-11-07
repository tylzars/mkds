#include "Main/Unknown/code_0203b680.h"

u32 GetMissionTableValue(u32 table, u32 row, u32 column) {
    u32 value0 = table;
    u32 value1 = row;
    u32 value2 = column;
    u32 columnCount;
    columnCount = *(const u16 *) ((value0) + (6));
    value2 = (value2) - (1u);
    value1 = (value1) - (1u);
    value2 = (value1) * (columnCount) + (value2);
    value0 = (value0) + (value2);
    value0 = *(const u8 *) ((value0) + (8));
    return value0;
}
