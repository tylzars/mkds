#include "g2d_NAN_load.h"

void NNS_G2dUnpackNAN(Unk02021dc8 *bank) {
    int offset;
    u16 seq;
    u16 frame;
    Unk02021e1c *sequences;
    u32 frames;
    s32 contents;

    bank->mUnk_04 += (u32) bank;
    bank->mUnk_08 += (u32) bank;
    bank->mUnk_0c = OFFSET_PTR(Unk02021e40, bank->mUnk_0c, (u32) bank);
    sequences = (Unk02021e1c *) bank->mUnk_04;
    contents = (u32) bank->mUnk_0c;
    frames = bank->mUnk_08;
    for (seq = 0; seq < bank->mUnk_00; seq++) {
        offset = sequences[seq].mUnk_0c;
        sequences[seq].mUnk_0c = frames + offset;
        for (frame = 0; frame < sequences[seq].mUnk_00; frame++) {
            ((Unk02021e40 *) sequences[seq].mUnk_0c)[frame].mUnk_00 =
                contents + ((Unk02021e40 *) sequences[seq].mUnk_0c)[(u32) frame].mUnk_00;
        }
    }
}

void *NNS_G2dGetAnimSequenceByIdx(void *bank, u32 idx) {
    Unk02021dc8 *header = bank;

    if (header->mUnk_00 > idx) {
        return (Unk02021e1c *) header->mUnk_04 + idx;
    }
    return 0;
}
