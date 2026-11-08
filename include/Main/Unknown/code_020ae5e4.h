#pragma once

#include "types.h"

u16 GetOamMatrixCount(const void *oamList);
void UploadOamLists(void *mainOamList, void *subOamList);
