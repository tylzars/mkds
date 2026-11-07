#include "res_struct_accessor.h"

NNSG3dResMdlSet *NNS_G3dGetMdlSet(const NNSG3dResFileHeader *header) {
    u32 *blockOffsets;

    blockOffsets = OFFSET_PTR(u32, header, header->mHeaderSize);
    return OFFSET_PTR(NNSG3dResMdlSet, header, blockOffsets[0]);
}
