#include "code_02013730.h"

NNSG3dResMdlSet *NNS_G3dGetMdlSet(const NNSG3dResFileHeader *header) {
    u32 *blockOffsets;

    blockOffsets = (u32 *) ((u8 *) header + header->mHeaderSize);
    return (NNSG3dResMdlSet *) ((u8 *) header + blockOffsets[0]);
}
