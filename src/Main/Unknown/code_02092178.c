#include "Main/Unknown/code_02092178.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/code_021000d0.h"

void InitKanoke64(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value12 = (u32) &CreateParkedMapObjects;
    value2 = value0;
    value0 = MAP_OBJECT_KIND_BASABASA;
    value1 = 0xau;
    CreateParkedMapObjects(value0, value1, (void *) value2);
}
