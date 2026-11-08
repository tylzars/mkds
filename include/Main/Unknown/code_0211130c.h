#pragma once

#include "types.h"

// Object whose member at 0x4 UpdateRecordScene writes.
typedef struct Unk02111324 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
} Unk02111324;

void UpdateRecordScene(Unk02111324 *sceneNumbers);
void *GetRecordMainOam(void);
void *GetRecordSubOam(void);
