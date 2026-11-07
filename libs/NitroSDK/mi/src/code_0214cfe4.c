#include "code_0214cfe4.h"

// Copies size bytes from srcp to destp, a halfword at a time.
void MIi_CpuCopy16(const void *srcp, void *destp, s32 size) {
    s32 offset;

    offset = 0;
    do {
        if (offset >= size) {
            break;
        }
        *(u16 *) ((u32) destp + offset) = *(const u16 *) ((u32) srcp + offset);
        offset += 2;
    } while (1);
}

// Stores data at destp, a halfword at a time, for size bytes.
void MIi_CpuClear16(u16 data, void *destp, s32 size) {
    s32 offset;

    offset = 0;
    do {
        if (offset >= size) {
            break;
        }
        *(u16 *) ((u32) destp + offset) = data;
        offset += 2;
    } while (1);
}
