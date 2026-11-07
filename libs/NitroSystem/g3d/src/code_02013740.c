#include "code_02013740.h"
#include "code_02013bdc.h"

NNSG3dResTexPatAnm *NNS_G3dGetTexPatAnmByIdx(NNSG3dResTexPatAnmSet *pAnmSet, u8 idx) {
    NNSG3dResDictEntryHeader *dictEntries;
    NNSG3dResDictAnmSetData *setEntry;

    dictEntries = OFFSET_PTR(NNSG3dResDictEntryHeader, &pAnmSet->mDict, pAnmSet->mDict.mOfsEntry);
    setEntry = (NNSG3dResDictAnmSetData *) (dictEntries->mData + dictEntries->mSizeUnit * idx);
    return OFFSET_PTR(NNSG3dResTexPatAnm, pAnmSet, setEntry->mOffset);
}

NNSG3dResTexPatAnmSet *NNS_G3dGetTexPatAnmSet(const u8 *pFileHead) {
    return NNSi_G3dGetBinaryBlockFromFile(pFileHead, 0x30505442, 0x30544150);
}

NNSG3dResTexSRTAnm *NNS_G3dGetTexSRTAnmByIdx(NNSG3dResTexSRTAnmSet *pTexSRTSet, u8 idx) {
    NNSG3dResDictEntryHeader *dictEntries;
    NNSG3dResDictAnmSetData *setEntry;

    dictEntries = OFFSET_PTR(NNSG3dResDictEntryHeader, &pTexSRTSet->mDict, pTexSRTSet->mDict.mOfsEntry);
    setEntry = (NNSG3dResDictAnmSetData *) (dictEntries->mData + dictEntries->mSizeUnit * idx);
    return OFFSET_PTR(NNSG3dResTexSRTAnm, pTexSRTSet, setEntry->mOffset);
}

NNSG3dResTexSRTAnmSet *NNS_G3dGetTexSRTAnmSet(const u8 *pFileHead) {
    return NNSi_G3dGetBinaryBlockFromFile(pFileHead, 0x30415442, 0x30545253);
}

NNSG3dResMatCAnm *NNS_G3dGetMatCAnmByIdx(NNSG3dResMatCAnmSet *pAnmSet, u8 idx) {
    NNSG3dResDictEntryHeader *dictEntries;
    NNSG3dResDictAnmSetData *setEntry;

    dictEntries = OFFSET_PTR(NNSG3dResDictEntryHeader, &pAnmSet->mDict, pAnmSet->mDict.mOfsEntry);
    setEntry = (NNSG3dResDictAnmSetData *) (dictEntries->mData + dictEntries->mSizeUnit * idx);
    return OFFSET_PTR(NNSG3dResMatCAnm, pAnmSet, setEntry->mOffset);
}

NNSG3dResMatCAnmSet *NNS_G3dGetMatCAnmSet(const u8 *pFileHead) {
    return NNSi_G3dGetBinaryBlockFromFile(pFileHead, 0x30414d42, 0x3054414d);
}

NNSG3dResJntAnm *NNS_G3dGetJntAnmByIdx(NNSG3dResJntAnmSet *pJntAnmSet, int idx) {
    NNSG3dResDictEntryHeader *dictEntries;
    NNSG3dResDictAnmSetData *setEntry;

    dictEntries = OFFSET_PTR(NNSG3dResDictEntryHeader, &pJntAnmSet->mDict, pJntAnmSet->mDict.mOfsEntry);
    setEntry = (NNSG3dResDictAnmSetData *) (dictEntries->mData + dictEntries->mSizeUnit * idx);
    return OFFSET_PTR(NNSG3dResJntAnm, pJntAnmSet, setEntry->mOffset);
}

NNSG3dResJntAnmSet *NNS_G3dGetJntAnmSet(const u8 *pFileHead) {
    return NNSi_G3dGetBinaryBlockFromFile(pFileHead, 0x30414342, 0x30544e4a);
}

// Dictionaries of 16 or more entries are searched through their tree.
void *NNS_G3dGetResDataByName(const void *dict, const u32 *name) {
    const NNSG3dResDict *p;
    const NNSG3dResDictEntryHeader *dictEntries;
    const NNSG3dResDictTreeNode *base;
    const NNSG3dResDictTreeNode *prev;
    const NNSG3dResDictTreeNode *node;
    const u32 *entryName;
    u32 i;
    u32 k0;
    u32 k1;
    u32 k2;
    u32 k3;

    p = dict;
    if (p->mNumEntry < 0x10) {
        k0 = name[0];
        k1 = name[1];
        k2 = name[2];
        k3 = name[3];
        for (i = 0; i < p->mNumEntry; i++) {
            dictEntries = OFFSET_PTR(const NNSG3dResDictEntryHeader, p, p->mOfsEntry);
            entryName = (const u32 *) ((const u8 *) dictEntries + dictEntries->mOfsName + i * 16);
            if (entryName[0] == k0 && entryName[1] == k1 && entryName[2] == k2 && entryName[3] == k3) {
                dictEntries = OFFSET_PTR(const NNSG3dResDictEntryHeader, p, p->mOfsEntry);
                return (dictEntries->mData + dictEntries->mSizeUnit * i);
            }
        }
    } else {
        base = p->mNode;
        prev = base;
        if (prev->mIdxLeft != 0) {
            node = base + prev->mIdxLeft;
            while (prev->mRefBit > node->mRefBit) {
                prev = node;
                node = base + (&node->mIdxLeft)[(name[node->mRefBit >> 5] >> (node->mRefBit & 0x1f)) & 1];
            }
            dictEntries = OFFSET_PTR(const NNSG3dResDictEntryHeader, p, p->mOfsEntry);
            entryName = (const u32 *) ((const u8 *) dictEntries + dictEntries->mOfsName + node->mIdxEntry * 16);
            if (entryName[0] == name[0] && entryName[1] == name[1] && entryName[2] == name[2] &&
                entryName[3] == name[3]) {
                dictEntries = OFFSET_PTR(const NNSG3dResDictEntryHeader, p, p->mOfsEntry);
                return (dictEntries->mData + dictEntries->mSizeUnit * node->mIdxEntry);
            }
        }
    }
    return 0;
}

// Dictionaries of 16 or more entries are searched through their tree.
int NNS_G3dGetResDictIdxByName(const void *dict, const u32 *name) {
    const NNSG3dResDict *p;
    const NNSG3dResDictEntryHeader *dictEntries;
    const NNSG3dResDictTreeNode *base;
    const NNSG3dResDictTreeNode *prev;
    const NNSG3dResDictTreeNode *node;
    const u32 *entryName;
    u32 i;
    u32 k0;
    u32 k1;
    u32 k2;
    u32 k3;

    p = dict;
    if (p->mNumEntry < 0x10) {
        k0 = name[0];
        k1 = name[1];
        k2 = name[2];
        k3 = name[3];
        for (i = 0; i < p->mNumEntry; i++) {
            dictEntries = OFFSET_PTR(const NNSG3dResDictEntryHeader, p, p->mOfsEntry);
            entryName = (const u32 *) ((const u8 *) dictEntries + dictEntries->mOfsName + i * 16);
            if (entryName[0] == k0 && entryName[1] == k1 && entryName[2] == k2 && entryName[3] == k3) {
                return i;
            }
        }
    } else {
        base = p->mNode;
        prev = base;
        if (prev->mIdxLeft != 0) {
            node = base + prev->mIdxLeft;
            while (prev->mRefBit > node->mRefBit) {
                prev = node;
                node = base + (&node->mIdxLeft)[(name[node->mRefBit >> 5] >> (node->mRefBit & 0x1f)) & 1];
            }
            dictEntries = OFFSET_PTR(const NNSG3dResDictEntryHeader, p, p->mOfsEntry);
            entryName = (const u32 *) ((const u8 *) dictEntries + dictEntries->mOfsName + node->mIdxEntry * 16);
            if (entryName[0] == name[0] && entryName[1] == name[1] && entryName[2] == name[2] &&
                entryName[3] == name[3]) {
                return node->mIdxEntry;
            }
        }
    }
    return -1;
}

NNSG3dResDataBlockHeader *NNS_G3dGetDataBlockHeaderByIdx(const NNSG3dResFileHeader *header, u32 idx) {
    u32 *blockOffsets;

    blockOffsets = OFFSET_PTR(u32, header, header->mHeaderSize);
    return OFFSET_PTR(NNSG3dResDataBlockHeader, header, blockOffsets[idx]);
}
