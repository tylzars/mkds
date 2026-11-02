#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02133000.h"

#pragma thumb on
#pragma optimize_for_size on
void LocateBmgSections(Unk020b3fb0 *bmg) {
    u32 i;
    u32 p;
    u32 section;
    u32 tag;

    p = (u32) &bmg->mUnk_20;
    for (i = 0; i < bmg->mUnk_0c; i++) {
        section = p;
        p = p + ((Unk020b3fb0_20 *) p)->mUnk_04;
        tag = func_020ae1d0(((Unk020b3fb0_20 *) section)->mUnk_00);
        switch (tag) {
            case 0x494e4631:
                data_0217b360 = (Unk0217b340 *) section;
                break;
            case 0x44415431:
                data_0217b364 = (Unk0217b344 *) section;
                break;
        }
    }
}

void *GetBmgEntry(Unk020b3fb0 *bmg, s32 index) {
    LocateBmgSections(bmg);
    return &data_0217b364->mUnk_08[data_0217b360->mUnk_10[index % 0x10000]];
}
#pragma thumb off
