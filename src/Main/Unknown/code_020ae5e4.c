#include "Main/Unknown/code_020ae5e4.h"
#include "code_0200eddc.h"
#include "code_0214b824.h"

#pragma thumb on

void UploadOamLists(void *mainOamList, void *subOamList) {
    if (mainOamList != NULL) {
        DC_FlushRange(mainOamList, 0x00000400u);
        GX_LoadOAM(mainOamList, 0, 0x00000400u);
    }
    if (subOamList != NULL) {
        DC_FlushRange(subOamList, 0x00000400u);
        GXS_LoadOAM(subOamList, 0, 0x00000400u);
    }
}

u16 GetOamMatrixCount(const void *oamList) {
    return ((u32) * (const u16 *) ((u8 *) oamList + 0 + (0x402u)));
}

#pragma thumb off
