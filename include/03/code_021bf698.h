#pragma once

#include "types.h"

void ReleaseSelectionObjectSlots(void);
void PlaceSelectionCorners(u32 left, u32 right, u32 top, u32 bottom);
void PlaceSelectionPair(u32 pairIndex, u32 leftX, u32 rightX, u32 yPos);
void ReleaseSelectionObjects(void);
void InitSelectionObjects(void);
