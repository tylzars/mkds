#include "03/code_021d1c18.h"
#include "03/code_021d1000.h"
#include "03/unk_021da000.h"
#include "Main/Unknown/code_0214d000.h"
#include "03/code_021d2ecc.h"

#include "03/code_021d1440.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"

void LoadNceFile(u32 slot, const u8 *path) {
    u32 size;

    gNceFiles[slot] = LoadFile(path, &size, 4);
}

void FreeNceFile(u32 slot) {
    DeleteLoadedFile(gNceFiles[slot]);
    gNceFiles[slot] = NULL;
}

void CopyNceImageToOamEntries(u32 slot, u32 imageIndex, OamEntry *destination) {
    NceImage *file = gNceFiles[slot];
    u8 *source = (u8 *) file + file[imageIndex].mEntriesOffset;
    u16 entryCount = file[imageIndex].mEntryCount;
    s32 i;
    u8 buffer[8];
    // placeholder: the value is sent through the stack
    volatile u32 d = 0;

    MIi_CpuClear32(d, buffer, 8);
    for (i = 0; i < entryCount; i++, source += 6, destination++) {
        MIi_CpuCopy16(source, buffer, 6);
        MIi_CpuCopy32(buffer, destination, 8);
    }
}

void *CreateOamEntryFromNceImage(u32 screen, u32 imageIndex) {
    OamEntry *entry;
    u8 v2[8];
    entry = CreateOamEntry(screen, v2);
    CopyNceImageToOamEntries(screen, imageIndex, entry);
    return entry;
}
