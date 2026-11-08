#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_020b2c80.h"
#include "Main/Unknown/code_020b1de4.h"

#pragma thumb on

Nclr *GetChoisesSBNclr(void) {
    return (gChoisesS->mChoisesSBNclr);
}

Ncgr *func_020b3374(void) {
    int v1;
    v1 = GetChoisesSListIndex();
    if (v1 == 1) {
        gChoisesS->mChoisesSBNcgr->mData = gChoisesS->mList1Chars;
    } else {
        v1 = GetChoisesSListIndex();
        if (v1 == 2) {
            gChoisesS->mChoisesSBNcgr->mData = gChoisesS->mList2Chars;
        }
    }
    return gChoisesS->mChoisesSBNcgr;
}

void *func_020b32f8(void) {
    int v1;
    u16 *v2;
    v2 = 0;
    v1 = GetChoisesSListIndex();
    if (v1 == 0) {
        if (gChoisesS->mList0Nscr != NULL) {
            v2 = gChoisesS->mList0Nscr->mData;
        }
    } else if (v1 == 1) {
        if (gChoisesS->mList1Nscr != NULL) {
            v2 = gChoisesS->mList1Nscr->mData;
        }
    } else if (v1 == 2) {
        if (gChoisesS->mList2Nscr != NULL) {
            v2 = gChoisesS->mList2Nscr->mData;
        }
    } else if ((v1 == 3) && (gChoisesS->mList3Nscr != NULL)) {
        v2 = gChoisesS->mList3Nscr->mData;
    }
    return v2;
}

u32 func_020b32ec(void) {
    return (gChoisesS->mPickLocked);
}

#pragma thumb off
