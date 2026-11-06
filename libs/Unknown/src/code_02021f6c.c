#include "code_02021f6c.h"

void NNS_G2dUnpackNCL(NNSG2dPaletteData *pPlttData) {
    pPlttData->mRawData = OFFSET_PTR(void, pPlttData->mRawData, (u32) pPlttData);
}

void NNS_G2dUnpackBGNCG(NNSG2dCharacterData *pCharData) {
    pCharData->mRawData = OFFSET_PTR(void, pCharData->mRawData, (u32) pCharData);
}

void NNS_G2dUnpackNCG(NNSG2dCharacterData *pCharData) {
    pCharData->mRawData = OFFSET_PTR(void, pCharData->mRawData, (u32) pCharData);
}
