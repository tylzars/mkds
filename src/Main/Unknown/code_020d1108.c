#include "Main/Unknown/code_020d1108.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d0efc.h"
#include "Main/Unknown/code_020d0f78.h"
#include "Main/Unknown/code_020d113c.h"
#include "Main/Unknown/code_020d1158.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on

void InitCupPicture(void) {
    int result;
    CupPicture *cupPicture;
    u32 heap;
    result = func_020d1158();
    if (result == 0) {
        heap = func_020d113c();
        cupPicture = HeapAlloc((void *) heap, (0x0000185cu));
        gCupPicture = cupPicture;
        cupPicture->mCupPictureIndex = 0;
        TrySetCupPictureIndexAndQueueLoads(0x14);
    }
}

#pragma thumb off
