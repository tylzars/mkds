#include "code_02013b20.h"

NNSG3dResDictTexPatAnmData *NNSi_G3dGetTexPatAnmDataByIdx(const NNSG3dResTexPatAnm *pPatAnm, u32 idx) {
    NNSG3dResDictEntryHeader *entry;

    entry = OFFSET_PTR(NNSG3dResDictEntryHeader, &pPatAnm->mDict, pPatAnm->mDict.mOfsEntry);
    return (NNSG3dResDictTexPatAnmData *) (entry->mData + entry->mSizeUnit * idx);
}
