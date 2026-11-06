#include "code_02013b20.h"

NNSG3dResDictTexPatAnmData *NNSi_G3dGetTexPatAnmDataByIdx(const NNSG3dResTexPatAnm *pPatAnm, u32 idx) {
    NNSG3dResDictEntryHeader *entry;

    entry = (NNSG3dResDictEntryHeader *) ((u8 *) &pPatAnm->mDict + pPatAnm->mDict.mOfsEntry);
    return (NNSG3dResDictTexPatAnmData *) (entry->mData + entry->mSizeUnit * idx);
}
