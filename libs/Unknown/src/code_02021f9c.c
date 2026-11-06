#include "code_02021f9c.h"

Unk02021fd0 *FindPartByTag(Unk02021f9c *file, u32 tag) {
    u16 i;
    u16 count;
    Unk02021fd0 *part;

    part = (Unk02021fd0 *) ((u8 *) file + file->mUnk_0c);
    count = file->mUnk_0e;
    for (i = 0; i < count; i++) {
        if (part->mUnk_00 == tag) {
            return part;
        }
        part = (Unk02021fd0 *) ((u8 *) part + part->mUnk_04);
    }
    return 0;
}

u32 NNS_G2dGetUnpackedScreenData(Unk02021f9c *pNscrFile, Unk02021fd0 **ppScrData) {
    Unk02021fd0 *part;

    part = FindPartByTag(pNscrFile, 0x5343524e);
    if (part != 0) {
        *ppScrData = part + 1;
        return 1;
    }
    *ppScrData = 0;
    return 0;
}
