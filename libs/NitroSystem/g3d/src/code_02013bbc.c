#include "code_02013bbc.h"

const u32 *NNSi_G3dGetTexPatAnmTexNameByIdx(const NNSG3dResTexPatAnm *pPatAnm, u8 texIdx) {
    return (const u32 *) ((const u8 *) pPatAnm + pPatAnm->mOfsTexName + (texIdx << 4));
}

const u32 *NNSi_G3dGetTexPatAnmPlttNameByIdx(const NNSG3dResTexPatAnm *pPatAnm, u8 plttIdx) {
    return (const u32 *) ((const u8 *) pPatAnm + pPatAnm->mOfsPlttName + (plttIdx << 4));
}
