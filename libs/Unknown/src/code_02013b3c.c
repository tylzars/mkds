#include "code_02013b3c.h"
#include "code_02013b20.h"

// Starts at the entry the ratio estimates, then steps to the frame.
NNSG3dResTexPatAnmFV *NNSi_G3dGetTexPatAnmFV(const NNSG3dResTexPatAnm *pPatAnm, u32 idx, u32 frame) {
    NNSG3dResDictTexPatAnmData *patData;
    NNSG3dResTexPatAnmFV *frames;
    u32 cur;

    patData = NNSi_G3dGetTexPatAnmDataByIdx(pPatAnm, idx);
    cur = patData->mRatioDataFrame;
    frames = OFFSET_PTR(NNSG3dResTexPatAnmFV, pPatAnm, patData->mOffset);
    cur = (cur * frame) >> 12;
    while (cur != 0 && frames[cur].mIdxFrame >= frame) {
        cur--;
    }
    while (cur + 1 < patData->mNumFV && (&frames[cur])[1].mIdxFrame <= frame) {
        cur++;
    }
    return &frames[cur];
}
