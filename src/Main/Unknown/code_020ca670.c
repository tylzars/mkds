#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020caba4.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_021000d0.h"

#pragma thumb on
void SetEmblemChoisesShownAndReset(u32 shown) {
    gEmblemChoises->mShown = shown;
    ResetEmblemChoisesState();
}
#pragma thumb off

s32 CreateRaceHudSubScreenShine16Cells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenShine16Cells, MAP_OBJECT_KIND_SHINE16);
}
