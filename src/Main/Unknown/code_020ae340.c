#include "Main/Unknown/code_020ae340.h"
#include "Main/Unknown/code_0203b680.h"
#include "Main/Unknown/code_0203b69c.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/unk_02168000.h"

#pragma optimize_for_size on
#pragma thumb on

u32 func_020ae3a4(s32 a, s32 b) {
    return data_02168024[a * 4 + b];
}

void FindMissionTableCell(u32 value, u8 *outRow, u8 *outColumn) {
    u32 table;
    s32 rowCount;
    s32 columnCount;
    u8 row;
    u8 column;

    table = (u32) func_02047a28("/missionTable.mtbl");
    rowCount = func_0203b6a4(table);
    columnCount = func_0203b69c(table);
    for (row = 1; row <= rowCount; row++) {
        for (column = 1; column <= columnCount; column++) {
            if (value == func_0203b680(table, row, column)) {
                *outRow = row;
                *outColumn = column;
            }
        }
    }
}

#pragma thumb off
