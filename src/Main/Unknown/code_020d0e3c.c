#include "Main/Unknown/code_020d0e3c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020d0ee8.h"
#include "Main/Unknown/code_020d0f78.h"
#include "Main/Unknown/code_021000d0.h"

#pragma optimize_for_size on

#pragma thumb on
BOOL func_020d0ec4(void) {
    if (gCupPicture != NULL && func_020d0ee8() == 0) {
        return TRUE;
    }
    return FALSE;
}

void *GetCupPictureNclrData(void) {
    if (func_020d0ec4() != FALSE) {
        return gCupPicture->mCupPictureNclr->mData;
    }
    return NULL;
}

void *GetCupPictureNcgrData(void) {
    if (func_020d0ec4() != FALSE) {
        return gCupPicture->mCupPictureNcgr->mData;
    }
    return NULL;
}

void *GetCupPictureNscrData(void) {
    if (func_020d0ec4() != FALSE) {
        return &gCupPicture->mCupPictureNscr->mData;
    }
    return NULL;
}
#pragma thumb off

s32 CreateRaceHudSubScreenFireball2Cells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenFireball2Cells, MAP_OBJECT_KIND_FIREBALL2);
}
