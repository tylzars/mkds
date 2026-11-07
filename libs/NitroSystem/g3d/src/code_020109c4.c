#include "code_020109c4.h"

// Keeps the chain ordered by priority.
void addLink_(NNSG3dAnmObj **l, NNSG3dAnmObj *item) {
    NNSG3dAnmObj *prev;
    NNSG3dAnmObj *next;
    NNSG3dAnmObj *tail;

    prev = *l;
    if (prev == 0) {
        *l = item;
        return;
    }
    next = prev->mNext;
    if (next == 0) {
        if (prev->mPriority > item->mPriority) {
            tail = item;
            if (item->mNext != 0) {
                do {
                    tail = tail->mNext;
                } while (tail->mNext != 0);
            }
            tail->mNext = prev;
            *l = item;
            return;
        }
        prev->mNext = item;
        return;
    }
    while (next != 0) {
        if (next->mPriority >= item->mPriority) {
            tail = item;
            if (item->mNext != 0) {
                do {
                    tail = tail->mNext;
                } while (tail->mNext != 0);
            }
            prev->mNext = item;
            tail->mNext = next;
            return;
        }
        prev = next;
        next = next->mNext;
    }
    prev->mNext = item;
}

// Marks the entries the chain maps.
void updateHintVec_(u32 *pVec, const NNSG3dAnmObj *pAnmObj) {
    int i;

    while (pAnmObj != 0) {
        for (i = 0; i < pAnmObj->mNumMapData; i++) {
            if ((pAnmObj->mMapData[i] & 0x100) != 0) {
                pVec[i >> 5] |= 1 << (i & 31);
            }
        }
        pAnmObj = pAnmObj->mNext;
    }
}

void NNS_G3dRenderObjAddAnmObj(NNSG3dRenderObj *pRenderObj, NNSG3dAnmObj *pAnmObj) {
    NNSG3dResAnmHeader *header;

    header = pAnmObj->mResAnm;
    switch (header->mCategory0) {
        case 'M':
            updateHintVec_(pRenderObj->mHintMatAnmExist, pAnmObj);
            addLink_(&pRenderObj->mAnmMat, pAnmObj);
            break;
        case 'J':
            updateHintVec_(pRenderObj->mHintJntAnmExist, pAnmObj);
            addLink_(&pRenderObj->mAnmJnt, pAnmObj);
            break;
        case 'V':
            updateHintVec_(pRenderObj->mHintVisAnmExist, pAnmObj);
            addLink_(&pRenderObj->mAnmVis, pAnmObj);
            break;
    }
}

int removeLink_(NNSG3dAnmObj **l, NNSG3dAnmObj *item) {
    NNSG3dAnmObj *next;
    NNSG3dAnmObj *cur;

    cur = *l;
    if (cur == 0) {
        return 0;
    }
    if (cur == item) {
        *l = cur->mNext;
        item->mNext = 0;
        return 1;
    }
    next = cur->mNext;
    while (next != 0) {
        if (next == item) {
            cur->mNext = next->mNext;
            next->mNext = 0;
            return 1;
        }
        cur = next;
        next = next->mNext;
    }
    return 0;
}

void NNS_G3dRenderObjRemoveAnmObj(NNSG3dRenderObj *pRenderObj, NNSG3dAnmObj *pAnmObj) {
    if (removeLink_(&pRenderObj->mAnmMat, pAnmObj) != 0 || removeLink_(&pRenderObj->mAnmJnt, pAnmObj) != 0 ||
        removeLink_(&pRenderObj->mAnmVis, pAnmObj) != 0) {
        pRenderObj->mFlag |= 0x10;
    }
}

void NNS_G3dRenderObjSetCallBack(NNSG3dRenderObj *pRenderObj, NNSG3dSbcCallBackFunc func, u8 *unused, u8 cmd,
                                 u32 timing) {
    pRenderObj->mCbFunc = func;
    pRenderObj->mCbCmd = cmd;
    pRenderObj->mCbTiming = timing;
}
