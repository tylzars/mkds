#pragma once

#include "types.h"

typedef struct TimeRecord TimeRecord;
typedef struct PackedGrandPrixRecord PackedGrandPrixRecord;

void UnpackGrandPrixRecord(PackedGrandPrixRecord *packedGrandPrixRecord, TimeRecord *timeRecord);
