#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_020b2c80.h"
#include "Main/Unknown/code_020b1de4.h"

#pragma thumb on

Nclr *GetChoisesSBNclr(void) {
    return (gChoisesS->mChoisesSBNclr);
}

Ncgr *GetChoisesSBNcgrWithListChars(void) {
    int choisesSListIndex;
    choisesSListIndex = GetChoisesSListIndex();
    if (choisesSListIndex == 1) {
        gChoisesS->mChoisesSBNcgr->mData = gChoisesS->mList1Chars;
    } else {
        choisesSListIndex = GetChoisesSListIndex();
        if (choisesSListIndex == 2) {
            gChoisesS->mChoisesSBNcgr->mData = gChoisesS->mList2Chars;
        }
    }
    return gChoisesS->mChoisesSBNcgr;
}

void *GetChoisesSListScreenMapData(void) {
    int choisesSListIndex;
    u16 *screenMapData;
    screenMapData = 0;
    choisesSListIndex = GetChoisesSListIndex();
    if (choisesSListIndex == 0) {
        if (gChoisesS->mList0Nscr != NULL) {
            screenMapData = gChoisesS->mList0Nscr->mData;
        }
    } else if (choisesSListIndex == 1) {
        if (gChoisesS->mList1Nscr != NULL) {
            screenMapData = gChoisesS->mList1Nscr->mData;
        }
    } else if (choisesSListIndex == 2) {
        if (gChoisesS->mList2Nscr != NULL) {
            screenMapData = gChoisesS->mList2Nscr->mData;
        }
    } else if ((choisesSListIndex == 3) && (gChoisesS->mList3Nscr != NULL)) {
        screenMapData = gChoisesS->mList3Nscr->mData;
    }
    return screenMapData;
}

u32 IsChoisesSPickLocked(void) {
    return (gChoisesS->mPickLocked);
}

#pragma thumb off
