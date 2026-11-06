#include "code_02021e8c.h"

Unk02021e40 *GetPtrOamArrayHead_(Unk02021dc8 *bank) {
    if (bank->mUnk_02 & 1) {
        return (Unk02021e40 *) (bank->mUnk_04 + bank->mUnk_00 * 16);
    }
    return (Unk02021e40 *) (bank->mUnk_04 + bank->mUnk_00 * 8);
}

Unk020224e0_c *NNS_G2dGetCellDataByIdx(Unk02021dc8 *bank, u32 idx) {
    if (idx >= bank->mUnk_00) {
        return 0;
    }
    if (bank->mUnk_02 & 1) {
        return (Unk020224e0_c *) (bank->mUnk_04 + idx * 16);
    }
    return (Unk020224e0_c *) (bank->mUnk_04 + idx * 8);
}

void NNS_G2dUnpackNCE(Unk02021dc8 *bank) {
    Unk02021e40 *oamHead;
    Unk02021e40 *entry;
    u16 i;

    bank->mUnk_04 += (u32) bank;
    oamHead = GetPtrOamArrayHead_(bank);
    for (i = 0; i < bank->mUnk_00; i++) {
        entry = (Unk02021e40 *) NNS_G2dGetCellDataByIdx(bank, i);
        entry->mUnk_04 += (u32) oamHead;
    }
    if (bank->mUnk_0c != 0) {
        bank->mUnk_0c = (Unk02021e40 *) ((u32) bank->mUnk_0c + (u32) bank);
        entry = bank->mUnk_0c;
        entry->mUnk_04 += (u32) entry;
        bank->mUnk_0c = entry;
    }
}
