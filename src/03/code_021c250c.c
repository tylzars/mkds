#include "03/code_021c250c.h"

// Returns the message entry; a non-negative column first gets the character value + '0' (a digit for 0 to 9).
void *GetMessageEntryAndWriteDigit(MessageFile *table, u32 index, s32 column, s32 value) {
    u16 *cell = (u16 *) (table->mData + table->mOffsets[index & 0xffff]);
    if (column >= 0) {
        cell[column] = value + 0x30;
    }
    return cell;
}
